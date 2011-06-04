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
QCell *QConsCar(QCons *qcc) {
	return qcc ? qcc->left : 0;
}

/*****************************************************************************
 */
QCell *QConsCdr(QCons *qcc) {
	return qcc ? qcc->right : 0;
}

/*****************************************************************************
 */
QCons *QConsFree(QCons *qcc) {
	if (qcc) {
		free(qcc);
	}

	return 0;
}

/*****************************************************************************
 */
QCons *QConsNew(QCell *left, QCell *right) {
	QCons *qcc = (QCons *)malloc(sizeof(QCons));
	if (qcc) {
		qcc->left  = left;
		qcc->right = right;
	}

	return qcc;
}
