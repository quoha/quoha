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
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*****************************************************************************
 * QBufferFromFile(fileName, length, forceNewLine)
 *   creates a new QBuffer from the contents of the file
 * fileName      name of file to read data from
 * forceNewLine  if non-zero, ensure that the QBuffer ends on a new-line
 *
 * returns pointer to new QBuffer
 */
QBuffer *QBufferFromFile(const char *fileName, int forceNewLine) {
	QBuffer    *qb = 0;
	struct stat statBuf;

	if (stat(fileName, &statBuf) == 0) {
		qb = (QBuffer *)malloc(sizeof(QBuffer) + statBuf.st_size + 5);
		if (qb) {
			qb->length      = statBuf.st_size;
			qb->startOfData = qb->data;
			qb->endOfData   = qb->data + qb->length;
			qb->currData    = qb->data;

			if (qb->length == 0) {
				// empty file

				// maybe force the buffer to end with a new-line
				if (!forceNewLine) {
					qb->startOfData[0] = 0;
				} else {
					qb->startOfData[0] = '\n';
					qb->startOfData[1] = 0;
					qb->length++;
					qb->endOfData++;
				}
			} else {
				// not empty, so read it into memory
				FILE *fp = fopen(fileName, "r");
				if (!fp || fread(qb->data, qb->length, 1, fp) != 1) {
					free(qb);
					return 0;
				}
				fclose(fp);

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
	}

	return qb;
}
