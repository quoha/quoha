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

Parsing logic should be easy.

  a. If we find a single atom, return a QAtom.
  b. If we find an open parentheses, return a start-list token.
  c. If we find a close parentheses, return a end-list token to end the current list.
  d. If we are given a QAtom, do something with it. Probably something like add it to the active QConsCell.
  e. If we are given a start-list token, do something with it. Probably something like add it to the active QConsCell.
  f. If we are given a end-list token, do something with it. Probably something like close out the active QConsCell and pop it from the stack.

Did we mention that it would be easy to use stacks to process this? Assume that we have this input:::

  ( A ( B C ) )
  
  Input: '('
  Action: Push QConsCell on stack with car and cdr set to null.
  Action: Set current cons-cell to QConsCell on top of stack.
  
  Input: 'A'
  Action: Create QAtom.
  Action: Set car of current cons-cell to this QAtom.
  
  Input: '('
  Action: Push QConsCell on stack with car and cdr set to null.
  Action: Set current cons-cell to this QConsCell.
  
  Input: 'B'
  Action: Create QAtom.
  Action: Set car of current cons-cell to this QAtom.
  
  Input: 'C'
  Action: Create QAtom.
  Action: Create QConsCell and set car to this QAtom.
  Action: Set  car of current cons-cell to this QConsCell.
  Action: Set current cons-cell to this QConsCell.
  
  Input: ')'
  Action: Create QAtom. Set to QNil.
  Action: Set cdr of current cons-cell to this QAtom.
  Action: Pop stack.
  Action: Set current cons-cell to QConsCell on top of stack.
  
  Input: ')'
  Action: Create QAtom. Set to QNil.
  Action: Set cdr of current cons-cell to this QAtom.
  Action: Pop stack.
  Action: Set current cons-cell to QConsCell on top of stack.

How do we represent NIL versus ()?

Maybe some pseudo-code would make this clearer.::

  root = NULL
  if input is ATOM then
    root = ATOM
  else if input is '(' then
    initialize stack
      entry has { first , last } of type node
    while not end of input
      if input is '(' then
        stack.push(first, curr)
      if input is ')' then
        first, last = stack.pop
        last.left = new node
        last.left.right = first
        curr = last
      if input is ATOM then
        // append to list
        curr.left = new node(ATOM, NULL)
        curr      = curr.left


