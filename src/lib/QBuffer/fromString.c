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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*****************************************************************************
 */
QBuffer *QBufferFromString(const char *src, int length, int forceNewLine) {
	if (src == 0 || length < 0) {
		length = 0;
		src    = "";
	}

	QBuffer *qb = (QBuffer *)malloc(sizeof(QBuffer) + length + 5);

	if (qb) {
		qb->length      = length;
		qb->startOfData = qb->data;
		qb->endOfData   = qb->data + qb->length;
		qb->currData    = qb->data;

		if (qb->length == 0) {
			// empty file
			if (forceNewLine) {
				qb->startOfData[0] = '\n';
				qb->length++;
				qb->endOfData++;
			}

			qb->startOfData[qb->length] = 0;
		} else {
			// not empty, so read it into memory
			memcpy(qb->data, src, length);

			char *lastChar = qb->endOfData - 1;

			// maybe force the buffer to end with a new-line
			if (forceNewLine && *lastChar != '\n') {
				qb->length++;
				qb->endOfData++;
				*(lastChar++) = '\n';
			}

			// no matter what, ensure the buffer is terminated
			*lastChar = 0;
		}
	}

	return qb;
}
