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
#include <sys/stat.h>
#include <fcntl.h>

/*****************************************************************************
 */
static ssize_t ReadFile(int fd, size_t bytesToRead, unsigned char *buf);

/*****************************************************************************
 * QBufferFromFile(fileName, length, forceNewLine)
 *   creates a new QBuffer from the contents of the file
 * fileName      name of file to read data from
 * forceNewLine  if non-zero, ensure that the QBuffer ends on a new-line
 *
 * returns pointer to new QBuffer
 */
QBuffer *QBufferFromFile(const char *fileName, int forceNewLine) {
	int         fd = -1;
	QBuffer    *qb =  0;
	struct stat statBuf;

	if (stat(fileName, &statBuf) == 0) {
		if (statBuf.st_size > 0) {
			fd = open(fileName, O_RDONLY);
			if (fd == -1)  // permissions issue, maybe?
				return 0;
		}

		qb = (QBuffer *)malloc(sizeof(QBuffer) + statBuf.st_size + 5);
		if (qb) {
			qb->length      = statBuf.st_size;
			qb->startOfData = qb->data;
			qb->currData    = qb->data;

			if (qb->length == 0) {
				// maybe force the buffer to end with a new-line
				if (forceNewLine)
					qb->data[qb->length++] = '\n';
			} else {
				// not empty, so read it into memory
				int rc = QBufferReadFile(fd, qb->length, qb->data);
				close(fd);
				if (rc != 0) {
					free(qb);
					return 0;
				}

				// maybe force the buffer to end with a new-line
				if (forceNewLine && qb->data[qb->length - 1] != '\n')
					qb->data[qb->length++] = '\n';
			}

			// no matter what, ensure the buffer is terminated
			qb->endOfData        = qb->data + qb->length;
			qb->data[qb->length] = 0;
		}
	}

	return qb;
}
