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
QParser *QParserNew(void) {
	QParser *qp = (QParser *)malloc(sizeof(QParser));
	if (qp) {
		qp->version.major = QUOHAPARSER_VER_MAJOR;
		qp->version.minor = QUOHAPARSER_VER_MINOR;
		qp->version.patch = QUOHAPARSER_VER_PATCH;
		qp->version.name  = QUOHAPARSER_VER_NAME;
		qp->version.tag   = QUOHAPARSER_VER_TAG;
	}

	return qp;
}
