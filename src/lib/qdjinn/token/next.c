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
 * QTokenNext(qb)
 *   returns next token from the buffer
 * qb         buffer to create token from
 *
 * returns pointer to new QToken
 *
 * at this level, tokens are separated by whitespace or end of buffer.
 */
QToken *QTokenNext(QBuffer *qb) {
	QToken *qt = 0;

	// skip leading white space
	if (qb)
		while (qb->currData < qb->endOfData && isspace(*(qb->currData)))
			++qb->currData;

	if (qb && qb->currData < qb->endOfData) {
		char *endOfToken;
		char *startOfToken;

		if (*(qb->currData) == '"') {
			startOfToken = ++qb->currData;
			while (qb->currData < qb->endOfData && *(qb->currData) != '"')
				++qb->currData;
			endOfToken   = qb->currData;

			// skip over the closing quote (if present)
			if (qb->currData < qb->endOfData)
				*(qb->currData++) = 0;
		} else {
			startOfToken = qb->currData;
			while (qb->currData < qb->endOfData && !isspace(*(qb->currData)))
				++qb->currData;
			endOfToken   = qb->currData;

			// nul terminate the token
			if (qb->currData < qb->endOfData)
				*(qb->currData++) = 0;
		}

		qt = (QToken *)malloc(sizeof(QToken));
		if (!qt) {
			perror("QToken.New");
			exit(2);
		}
		qt->column = 0;
		qt->line   = 0;
		qt->source = 0;
		qt->data   = startOfToken;
	}

	return qt;
}
