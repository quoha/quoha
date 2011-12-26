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
QToken *QParserLookahead(QParser *qp) {
	QToken *qt = 0;
	if (qp) {
		// get a token out of the active buffer. if that buffer is empty, roll
		// over to the next. continue to do that until we are out of buffers or
		// we get a token.
		QBuffer *qb = QBStackTopBuffer(qp->qs);
		for (; qt == 0; qb = QBStackTopBuffer(qp->qs)) {
			if (qb->currData >= qb->endOfData) {
				// exhausted buffer so get the next off the stack
				QBStackPopBuffer(qp->qs);
			} else {
				qt = QTokenNext(qb);
				if (!qt) {
					// no token? why?
					if (qb->currData < qb->endOfData) {
						// out of memory?
						break;
					}
					// otherwise, check the next buffer
				}
			}
		}
	}

	return qt;
}
