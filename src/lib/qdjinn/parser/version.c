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

/*****************************************************************************
 */
const char *QParserVersionDttm(QParser *qp) {
	return __DATE__ " " __TIME__;
}

/*****************************************************************************
 */
int QParserVersionMajor(QParser *qp) {
	return qp ? qp->version.major : QUOHAPARSER_VER_MAJOR;
}

/*****************************************************************************
 */
int QParserVersionMinor(QParser *qp) {
	return qp ? qp->version.minor : QUOHAPARSER_VER_MINOR;
}

/*****************************************************************************
 */
int QParserVersionPatch(QParser *qp) {
	return qp ? qp->version.patch : QUOHAPARSER_VER_PATCH;
}

/*****************************************************************************
 */
const char *QParserVersionName(QParser *qp) {
	return qp ? qp->version.name : QUOHAPARSER_VER_NAME;
}

/*****************************************************************************
 */
const char *QParserVersionTag(QParser *qp) {
	return qp ? qp->version.tag : QUOHAPARSER_VER_TAG;
}
