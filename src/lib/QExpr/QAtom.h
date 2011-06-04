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

#ifndef Quoha_src_lib_QExpr_QAtom_H
#define Quoha_src_lib_QExpr_QAtom_H

/*****************************************************************************
 */
struct QAtom {
	int type;
	union {
		int                  integer;
		double               number;
		const char          *string;
		const unsigned char *ustring;
		void                *vob;
	} data;
};
typedef struct QAtom QAtom;

/*****************************************************************************
 */
QAtom *QAtomNew(void);
QAtom *QAtomFree(QAtom *atom);

/*****************************************************************************
 */
int QAtomIsInteger(QAtom *atom);
int QAtomIsNil(QAtom *atom);
int QAtomIsString(QAtom *atom);

/*****************************************************************************
 */
QAtom *QAtomSetInteger(QAtom *atom, int integer);
QAtom *QAtomSetNil(QAtom *atom);
QAtom *QAtomSetString(QAtom *atom, const char *string);
QAtom *QAtomSetUString(QAtom *atom, const unsigned char *ustring);

/*****************************************************************************
 */
int                  QAtomAsInteger(QAtom *atom);
const          char *QAtomAsString(QAtom *atom);
const unsigned char *QAtomAsUString(QAtom *atom);

#endif
