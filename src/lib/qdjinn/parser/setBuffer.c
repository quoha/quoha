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
int QParserSetBuffer(QParser *qp, unsigned char *buffer, int bufferLength) {
#if 0
	if (qp == 0) {
		return -1;
	} else if (buffer == 0) {
		return -2;
	} else if (bufferLength < 1) {
		return -3;
	} else if (bufferLength > QUOHAPARSER_MAX_BUFSZ) {
		return -4;
	}

	qp->data.start = buffer;
	qp->data.end   = buffer + bufferLength;
	qp->data.next  = buffer;
#endif
	return 0;
}
