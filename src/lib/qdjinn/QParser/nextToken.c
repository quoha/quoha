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

#include <string.h>
#include <stdlib.h>

/*****************************************************************************
 */
QToken *QParserNextToken(QParser *qp) {
	if (qp == 0 || qp->data.next == 0 || qp->data.next == qp->data.end) {
		return 0;
	}

	static QToken qt;
	memset(&qt, 0, sizeof(qt));

	unsigned char *s = qp->data.next;

	qt.data = s;

	if (*s == '(') {
		qp->data.next++;
		return &qt;
	}
	if (*s == ')') {
		qp->data.next++;
		return &qt;
	}

	while (s && s < qp->data.end) {
		if (*s == '(' || *s == ')') {
			break;
		}
		++s;
	}

	qp->data.next = s;
	return &qt;
}
