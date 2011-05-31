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
int QCellAsInteger(QCell *qc) {
	return (qc && qc->type == QCELL_TYPE_INTEGER) ? qc->data.integer : 0;
}

/*****************************************************************************
 */
const char *QCellAsString(QCell *qc) {
	return (qc && qc->type == QCELL_TYPE_STRING) ? qc->data.string : 0;
}

/*****************************************************************************
 */
QCell *QCellFree(QCell *qc) {
	if (qc) {
		free(qc);
	}

	return 0;
}

/*****************************************************************************
 */
int QCellIsInteger(QCell *qc) {
	return (qc && qc->type == QCELL_TYPE_INTEGER) ? 1 : 0;
}

/*****************************************************************************
 */
int QCellIsString(QCell *qc) {
	return (qc && qc->type == QCELL_TYPE_STRING) ? 1 : 0;
}

/*****************************************************************************
 */
int QCellIsNil(QCell *qc) {
	return (qc && qc->type == QCELL_TYPE_NIL) ? 1 : 0;
}

/*****************************************************************************
 */
QCell *QCellNew(void) {
	QCell *qc = (QCell *)malloc(sizeof(QCell));
	if (qc) {
		qc->type = QCELL_TYPE_NIL;
		qc->data.integer = 0;
	}

	return qc;
}

/*****************************************************************************
 */
QCell *QCellNewInteger(int i) {
	QCell *qc = (QCell *)malloc(sizeof(QCell));
	if (qc) {
		qc->type = QCELL_TYPE_INTEGER;
		qc->data.integer = i;
	}

	return qc;
}

/*****************************************************************************
 */
QCell *QCellNewString(const char *s) {
	QCell *qc = (QCell *)malloc(sizeof(QCell));
	if (qc) {
		qc->type = QCELL_TYPE_STRING;
		qc->data.string = s;
	}

	return qc;
}
