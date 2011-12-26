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
#include <ctype.h>

/*****************************************************************************
 */
static char *StrNDup(const char *src, int len) {
	if (!src) {
		src = "";
		len = 0;
	} else if (len < 0) {
		len = 0;
	}
	char *dst = malloc(len + 1);
	if (dst) {
		char *p = dst;
		while (len-- && *src) {
			if (*src != '\\') {
				*(p++) = *(src++);
			} else {
				switch (*(++src)) {
					case 0:
						break;
					case 'n':
						*(p++) = '\n';
						++src;
						break;
					case 't':
						*(p++) = '\t';
						++src;
						break;
					default:
						*(p++) = *(src++);
						break;
				}
			}
		}
		*p = 0;
	}
	return dst;
}

/*****************************************************************************
 * QTokenNext(qb)
 *   returns next token from the buffer
 * qb         buffer to create token from
 *
 * returns pointer to new QToken
 *
 */
QToken *QTokenNext(QBuffer *qb) {
	QToken *qt = 0;

	if (qb) {
		// skip leading white space
		while (qb->currData < qb->endOfData && isspace(*(qb->currData))) {
			qb->currData++;
		}
	}

	if (qb && qb->currData < qb->endOfData) {
		char *startOfToken = qb->currData;

		if (*(qb->currData) == '"') {
			// double quoted string
			qb->currData++;
			while (qb->currData < qb->endOfData && *(qb->currData) != '"') {
				if (*(qb->currData) == '\\') {
					qb->currData++;
				}
				qb->currData++;
			}
			if (qb->currData < qb->endOfData && *(qb->currData) == '"') {
				qb->currData++;
			}
		} else {
			while (qb->currData < qb->endOfData) {
				if (*(qb->currData) == '\\') {
					qb->currData++;
				} else if (isspace(*(qb->currData))) {
					break;
				} else if (*(qb->currData) == '(' || *(qb->currData) == ')') {
					break;
				} else if (*(qb->currData) == '<' || *(qb->currData) == '>') {
					break;
				} else if (*(qb->currData) == '"' || *(qb->currData) == '\'') {
					break;
				}
				qb->currData++;
			}
		}

		if (qb->currData > qb->endOfData) {
			qb->currData = qb->endOfData;
		}

		char *endOfToken = qb->currData; // should be just beyond the token

		// just to be mean, skip trailing white space
		while (qb->currData < qb->endOfData && isspace(*(qb->currData))) {
			qb->currData++;
		}

		qt = (QToken *)malloc(sizeof(QToken));
		if (qt) {
			qt->column = 0;
			qt->line   = 0;
			qt->source = 0;
			qt->data   = StrNDup(startOfToken, endOfToken - startOfToken);
			if (!qt->data) {
				// TODO: leak memory since we don't call free(qt);
				qt = 0;
			}
		}
	}

	return qt;
}
