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

/*****************************************************************************
 */
#include "local.h"

/*****************************************************************************
 */
int QStateLoadFromFile(QState *qs, const char *fileName) {
	int doForceNewLine = 0;

	if (qs) {
		QBuffer *qb = QBufferFromFile(fileName, doForceNewLine);
		if (qb == 0) {
			qs->lastStatus = QDJINN_ERROR;
			qs->lastError  = QDJINN_NONEXIST;
		} else {
			qs->lastStatus = QDJINN_OK;
		}
	}

	return qs ? qs->lastStatus : QDJINN_ERROR;
}
