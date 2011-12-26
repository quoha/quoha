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

#include "../local.h"

/*****************************************************************************
 * GI000001 - http://github.com/quoha/quoha/issues/1
 */
static void GI000001(CuTest* tc) {
	char buffer[128];
	QParser *qp = 0;
        CuAssertTrue(tc, qp == 0);
        CuAssertTrue(tc, QParserVersionMajor(qp) == QUOHAPARSER_VER_MAJOR);
        CuAssertTrue(tc, QParserVersionMinor(qp) == QUOHAPARSER_VER_MINOR);
        CuAssertTrue(tc, QParserVersionPatch(qp) == QUOHAPARSER_VER_PATCH);
        CuAssertTrue(tc, QParserVersionDttm(qp)  != 0);

	sprintf(buffer, "%02d.%03d.%04d", QParserVersionMajor(qp), QParserVersionMinor(qp), QParserVersionPatch(qp));
        CuAssertTrue(tc, strcmp(buffer, QParserVersionName(qp)) == 0);

	qp = QParserNew();
        CuAssertTrue(tc, qp != 0);
        CuAssertTrue(tc, QParserVersionMajor(qp) == QUOHAPARSER_VER_MAJOR);
        CuAssertTrue(tc, QParserVersionMinor(qp) == QUOHAPARSER_VER_MINOR);
        CuAssertTrue(tc, QParserVersionPatch(qp) == QUOHAPARSER_VER_PATCH);

	sprintf(buffer, "%02d.%03d.%04d", QParserVersionMajor(qp), QParserVersionMinor(qp), QParserVersionPatch(qp));
        CuAssertTrue(tc, strcmp(buffer, QParserVersionName(qp)) == 0);

        CuAssertTrue(tc, QParserVersionTag(qp) != 0);

	qp = QParserFree(qp);
}
/*****************************************************************************
 */
CuSuite *GetSuiteQParserIssue(void) {
	CuSuite *suite = CuSuiteNew();

        SUITE_ADD_TEST(suite, GI000001);

	return suite;
}
