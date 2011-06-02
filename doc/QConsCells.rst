QConsCells
==========

For this first go-around, I am not worrying about memory usage or efficiency. I am just trying to get the parser to work.

A cons-cell has two boxes. The first, which we call "car,"  points to either an atom or a cons-cell. The second, known as "cdr," points to either a cons-cell or nil. That means that we four possible combinations of car and cdr for any give cons-cell.

  1. car points to atom and cdr points to NIL.
  2. car points to cons-cell and cdr points to NIL.
  3. car points to atom and cdr points to cons-cell.
  4. car points to cons-cell and cdr points to cons-cell.

The first type is a list containing a single atom.  The second is a list containing a single list.  The third is a list with the first element being an atom and the second being a list.  The fourth is a list with the both element being lists.

  1. ( A )
  2. ( ( A ) )
  3. ( A ( B ) )
  4. ( ( A ) ( B ) )

Lets call the boxes QCell. This structure would have a type flag because the box can hold a pointer to an atom, a cons-cell or nil. Along with that type flag, we need a union that holds the three pointers.::

  struct QCell {
    int type;
    union {
      pointer to atom;
      pointer to cons-cell;
      pointer to nil;
    }
  };

I don't know what goes in a QAtom yet, just that it needs a union holding every possible type of atom. For that, we need the type flag.::

  struct QAtom {
    int type;
    union {
      ...
    } data;
  };

Same for nil (we won't really implement it this way, it's just for discussion).::

  struct QNil {
    ...
  };

The updated QCell looks like:::

  struct QCell {
    int type;
    union {
      struct QAtom *atom;
      pointer to cons-cell;
      struct QNil  *nil;
    } data;
  };

Using QConsCell for cons-cell, the structure doesn't need a type flag because that's in the QCell. The structure is simply:

  struct QConsCell {
    struct QCell *car;
    struct QCell *cdr;
  };


The updated QCell looks like::

  struct QAtom {
    int type;
    union {
      ...
    } data;
  };

  struct QNil {
    ...
  };

  struct QCell {
    int type;
    union {
      struct QAtom     *atom;
      struct QConsCell *consCell;
      struct QNil      *nil;
    } data;
  };

  struct QConsCell {
    struct QCell *car;
    struct QCell *cdr;
  };

Parsing logic should be easy.

  a. If we find a single atom, return a QAtom.
  b. If we find an open parentheses, return a QConsCell.
  c. If we find a close parentheses, return a QNil to end the current list.
  d. If we are given a QAtom, do something with it. Probably something like add it to the active QConsCell.
  e. If we are given a QConsCell, do something with it. Probably something like add it to the active QConsCell.
  f. If we are given a QNil, do something with it. Probably something like close out the active QConsCell and pop it from the stack.

