Intro
=====

For this first go-around, I am not worrying about memory usage or efficiency. I am just trying to get the parser to work.

L-tree
======

Based on reading Anatomy of Lisp, I am rethinking this in terms of the L-tree. A list is a not-well balanced L-tree. Every node must have two children, but there is not a requirement for the tree itself to be balanced. The left child in the last node must be nil.

For every node in the L-tree with children, one of the following must be true.

  1. right node points to atom and left node points to NIL.
  2. right node points to node and left node points to NIL.
  3. right node points to atom and left node points to node.
  4. right node points to node and left node points to node.

Each of these options is a list like the following.

  1. ( A )
  2. ( ( A ) )
  3. ( A ( B ) )
  4. ( ( A ) ( B ) )

The structures for this look like:::

  struct QAtom {
    int type;
    union {
      ...
    } data;
  };

  struct QNode {
    int            typeRight;
    union {
      struct QAtom *atom;
      struct QNode *node;
    } right, left;
  };


QConsCells
==========

A cons-cell has two boxes. The first, which we call "car,"  points to either an atom or a cons-cell. The second, known as "cdr," points to either a cons-cell or nil. That means that we have only four possible combinations of car and cdr for any give cons-cell.

  1. car points to atom      and cdr points to NIL.
  2. car points to cons-cell and cdr points to NIL.
  3. car points to atom      and cdr points to cons-cell.
  4. car points to cons-cell and cdr points to cons-cell.

The first type is a list containing a single atom.  The second is a list containing a single list.  The third is a list with the first element being an atom and the second being a list.  The fourth is a list with the both element being lists.

  1. ( A )
  2. ( ( A ) )
  3. ( A ( B ) )
  4. ( ( A ) ( B ) )

I don't know what goes in a QAtom yet, just that it needs a union holding every possible type of atom. For that, we need the type flag:::

  struct QAtom {
    int type;
    union {
      ...
    } data;
  };

Nil is a special atom, or maybe a special cons-cell type. Don't know yet.

Lets call the boxes QCell. This structure would have a type flag because the box can hold a pointer to an atom, a cons-cell or nil. Along with that type flag, we need a union that holds the three pointers:::

  struct QCell {
    int type;
    union {
      pointer to atom;
      pointer to cons-cell;
      pointer to nil;
    }
  };


The updated QCell looks like::

  struct QCell {
    int type;
    union {
      struct QAtom *atom;
      pointer to cons-cell;
    } data;
  };

Using QConsCell for cons-cell, the structure doesn't need a type flag because that's in the QCell. The structure is simply::

  struct QConsCell {
    struct QCell *car;
    struct QCell *cdr;
  };


Simplifying and reducing, we come up with a structure that looks very similar to the L-tree above:::

  struct QAtom {
    int type;
    union {
      ...
    } data;
  };
  
  struct QConsCell {
    int                 carType;
    int                 cdrType;
    union {
      struct QAtom     *atom;
      struct QConsCell *consCell;
    } car, cdr;
  };

Parsing
=======

Parsing logic should be straight-forward.

Here is the pseudo-code for how to parse the expression:::

  -- List { node first; node last }
  --
  if token is not ATOM then
    do
      if token is '(' then
        stack.push(List(NULL, NULL))
      else if input is ')' then
        list = stack.pop
        if list is empty
          stack.top.append(new node(NIL, NULL))
        else
          stack.top.append(new node(list.first, NULL))
        end if
      else
        stack.top.append(new node(token, NULL))
      end if
      get next token
    while not end of input
  end if

Note that there is logic to detect empty lists. We want to keep empty lists separate from NIL. Feels like the right thing to do.

Also, there will be error checking in there to confirm that we have balanced the open and close parentheses.

Go ahead and follow the pseudo-code for this input:::

  ( A ( B C ) )

We should end up with a structure that looks like:::

  +===+===+   +===+===+
  [ A | *-+-->[ * | *-+--> NIL
  +===+===+   +=+=+===+
                |
                v
              +===+===+   +===+===+
              [ B | *-+-->[ C | *-+--> NIL
              +===+===+   +===+===+

Tell me, though, what the structure for the empty list looks like.

Nil versus ()
=============

Nil should be different than the empty list. Nil should be an atom that does not exist. The empty list is a list with no elements in it.

Boolean values
==============

We have true, false and nil. Not true is false and not false is true. Nil indicates that the value is neither true nor false. Not nil is not the same as true or false.
