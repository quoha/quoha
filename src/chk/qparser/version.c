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
static void TestQuohaParserMajor(CuTest* tc) {
	QuohaParser *qp = QuohaParserNew();
        CuAssertTrue(tc, qp != 0);
        CuAssertTrue(tc, QuohaParserVersionMajor(qp) == QUOHAPARSER_VER_MAJOR);
	qp = QuohaParserFree(qp);
}

/*****************************************************************************
 */
static void TestQuohaParserMinor(CuTest* tc) {
	QuohaParser *qp = QuohaParserNew();
        CuAssertTrue(tc, qp != 0);
        CuAssertTrue(tc, QuohaParserVersionMinor(qp) == QUOHAPARSER_VER_MINOR);
	qp = QuohaParserFree(qp);
}

/*****************************************************************************
 */
static void TestQuohaParserPatch(CuTest* tc) {
	QuohaParser *qp = QuohaParserNew();
        CuAssertTrue(tc, qp != 0);
        CuAssertTrue(tc, QuohaParserVersionPatch(qp) == QUOHAPARSER_VER_PATCH);
	qp = QuohaParserFree(qp);
}

/*****************************************************************************
 */
static void TestQuohaParserName(CuTest* tc) {
	QuohaParser *qp = QuohaParserNew();
        CuAssertTrue(tc, qp != 0);
        CuAssertTrue(tc, QuohaParserVersionName(qp) != 0);

	char buffer[128];
	sprintf(buffer, "%02d.%03d.%04d", QuohaParserVersionMajor(qp), QuohaParserVersionMinor(qp), QuohaParserVersionPatch(qp));
        CuAssertTrue(tc, strcmp(buffer, QuohaParserVersionName(qp)) == 0);

	qp = QuohaParserFree(qp);
}

/*****************************************************************************
 */
static void TestQuohaParserTag(CuTest* tc) {
	QuohaParser *qp = QuohaParserNew();
        CuAssertTrue(tc, qp != 0);
        CuAssertTrue(tc, QuohaParserVersionTag(qp) != 0);

	qp = QuohaParserFree(qp);
}
/*****************************************************************************
 */
CuSuite *GetSuiteVersion(void) {
	CuSuite *suite = CuSuiteNew();

        SUITE_ADD_TEST(suite, TestQuohaParserMajor);
        SUITE_ADD_TEST(suite, TestQuohaParserMinor);
        SUITE_ADD_TEST(suite, TestQuohaParserPatch);
        SUITE_ADD_TEST(suite, TestQuohaParserName);
        SUITE_ADD_TEST(suite, TestQuohaParserTag);

	return suite;
}
