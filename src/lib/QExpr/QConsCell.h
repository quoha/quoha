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

#ifndef Quoha_src_lib_QExpr_QConsCell_H
#define Quoha_src_lib_QExpr_QConsCell_H

//#include "QCell.h"

/*****************************************************************************
 */
struct QAtom {
	int type;
	union {
		int                  integer;
		double               number;
		const char          *string;
		const unsigned char *ustring;
	} data;
};
typedef struct QAtom QAtom;

/*****************************************************************************
 */
struct QCell {
	int                   type;
	union {
		struct QAtom *atom;
		struct QCons *cons;
	} data;
};
typedef struct QCell QCell;

/*****************************************************************************
 */
struct QCons {
	QCell left;
	QCell right;
};
typedef struct QConsCell QConsCell;

/*****************************************************************************
 */
QConsCell *QConsCellNew(QCell *left, QCell *right);
QConsCell *QConsCellFree(QConsCell *qcc);
QCell     *QConsCellLeft(QConsCell *qcc);
QCell     *QConsCellRight(QConsCell *qcc);

#endif
