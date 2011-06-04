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

#ifndef Quoha_src_lib_QExpr_QCell_H
#define Quoha_src_lib_QExpr_QCell_H

/*****************************************************************************
 */
struct QCell {
	int                 type;
	union {
		int         integer;
		const char *string;
	} data;
};
typedef struct QCell QCell;

/*****************************************************************************
 */
QCell      *QCellNew(void);
QCell      *QCellNewInteger(int i);
QCell      *QCellNewString(const char *s);
QCell      *QCellFree(QCell *qc);
int         QCellAsInteger(QCell *qc);
const char *QCellAsString(QCell *qc);
int         QCellIsInteger(QCell *qc);
int         QCellIsNil(QCell *qc);
int         QCellIsString(QCell *qc);

#endif
