/*****************************************************************************
 *  Quoha - a quaint framework for static websites
 *
 *  Copyright (C) 2011 Michael D Henderson
 *
 *  This file is part of Quoha (http://quoha.org).
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#include "local.h"

#include <stdlib.h>

/*****************************************************************************
 */
QAtom *QAtomNew(void) {
	return QAtomSetNil((QAtom *)malloc(sizeof(QAtom)));
}

/*****************************************************************************
 */
QAtom *QAtomFree(QAtom *atom) {
	if (atom) {
		free(atom);
	}
	return 0;
}

/*****************************************************************************
 */
int QAtomAsInteger(QAtom *atom) {
	return QAtomIsInteger(atom) ? atom->data.integer : 0;
}

/*****************************************************************************
 */
const char *QAtomAsString(QAtom *atom) {
	return QAtomIsString(atom) ? atom->data.string : 0;
}

/*****************************************************************************
 */
const unsigned char *QAtomAsUString(QAtom *atom) {
	return QAtomIsUString(atom) ? atom->data.ustring : 0;
}

/*****************************************************************************
 */
int QAtomIsInteger(QAtom *atom) {
	return atom && atom->type == QE_TYPE_ATOM_INTEGER;
}

/*****************************************************************************
 */
int QAtomIsNil(QAtom *atom) {
	return atom && atom->type == QE_TYPE_ATOM_NIL;
}

/*****************************************************************************
 */
int QAtomIsString(QAtom *atom) {
	return atom && atom->type == QE_TYPE_ATOM_STRING;
}

/*****************************************************************************
 */
int QAtomIsUString(QAtom *atom) {
	return atom && atom->type == QE_TYPE_ATOM_USTRING;
}

/*****************************************************************************
 */
QAtom *QAtomSetInteger(QAtom *atom, int integer) {
	if (atom) {
		atom->type         = QE_TYPE_ATOM_INTEGER;
		atom->data.integer = integer;
	}
	return atom;
}

/*****************************************************************************
 */
QAtom *QAtomSetNil(QAtom *atom) {
	if (atom) {
		atom->type     = QE_TYPE_ATOM_NIL;
		atom->data.vob = 0;
	}
	return atom;
}

/*****************************************************************************
 */
QAtom *QAtomSetString(QAtom *atom, const char *string) {
	if (atom) {
		atom->type        = QE_TYPE_ATOM_STRING;
		atom->data.string = string;
	}
	return atom;
}

/*****************************************************************************
 */
QAtom *QAtomSetUString(QAtom *atom, const unsigned char *ustring) {
	if (atom) {
		atom->type         = QE_TYPE_ATOM_USTRING;
		atom->data.ustring = ustring;
	}
	return atom;
}
