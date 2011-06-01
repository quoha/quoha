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
QExpr *QExprNew(void) {
	QExpr *qe = (QExpr *)malloc(sizeof(QExpr));
	if (qe) {
		qe->type = QE_TYPE_ATOM_NIL;
	}

	return qe;
}

/*****************************************************************************
 */
QExpr *QExprFree(QExpr *qe) {
	if (qe) {
		free(qe);
	}

	return 0;
}

/*****************************************************************************
 */
int QExprAsInteger(QExpr *qe) {
	return (qe && qe->type == QE_TYPE_ATOM_INTEGER) ? qe->data.integer : 0;
}

/*****************************************************************************
 */
const char *QExprAsString(QExpr *qe) {
	return (qe && qe->type == QE_TYPE_ATOM_STRING) ? qe->data.string : 0;
}

/*****************************************************************************
 */
int QExprIsAtom(QExpr *qe) {
	return (qe && ((qe->type & QE_TYPE_ATOM) == QE_TYPE_ATOM)) ? 1 : 0;
}

/*****************************************************************************
 */
int QExprIsAtomNil(QExpr *qe) {
	return (qe && (qe->type == QE_TYPE_ATOM_NIL)) ? 1 : 0;
}

/*****************************************************************************
 */
int QExprIsInteger(QExpr *qe) {
	return (qe && (qe->type == QE_TYPE_ATOM_INTEGER)) ? 1 : 0;
}

/*****************************************************************************
 */
int QExprIsNil(QExpr *qe) {
	return (qe && (qe->type == QE_TYPE_ATOM_NIL || qe->type == QE_TYPE_LIST_NIL)) ? 1 : 0;
}

/*****************************************************************************
 */
int QExprIsString(QExpr *qe) {
	return (qe && (qe->type == QE_TYPE_ATOM_STRING)) ? 1 : 0;
}

/*****************************************************************************
 */
void QExprSetAtomInteger(QExpr *qe, int i) {
	if (qe) {
		qe->type = QE_TYPE_ATOM_INTEGER;
		qe->data.integer = i;
	}
}

/*****************************************************************************
 */
void QExprSetAtomString(QExpr *qe, const char *s) {
	if (qe) {
		qe->type = QE_TYPE_ATOM_STRING;
		qe->data.string = s;
	}
}
