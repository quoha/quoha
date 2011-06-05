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
static void TestQParserMajor(CuTest* tc) {
	QParser *qp = QParserNew();
        CuAssertTrue(tc, qp != 0);
        CuAssertTrue(tc, QParserVersionMajor(qp) == QUOHAPARSER_VER_MAJOR);
	qp = QParserFree(qp);
}

/*****************************************************************************
 */
static void TestQParserMinor(CuTest* tc) {
	QParser *qp = QParserNew();
        CuAssertTrue(tc, qp != 0);
        CuAssertTrue(tc, QParserVersionMinor(qp) == QUOHAPARSER_VER_MINOR);
	qp = QParserFree(qp);
}

/*****************************************************************************
 */
static void TestQParserPatch(CuTest* tc) {
	QParser *qp = QParserNew();
        CuAssertTrue(tc, qp != 0);
        CuAssertTrue(tc, QParserVersionPatch(qp) == QUOHAPARSER_VER_PATCH);
	qp = QParserFree(qp);
}

/*****************************************************************************
 */
static void TestQParserName(CuTest* tc) {
	QParser *qp = QParserNew();
        CuAssertTrue(tc, qp != 0);
        CuAssertTrue(tc, QParserVersionName(qp) != 0);

	char buffer[128];
	sprintf(buffer, "%02d.%03d.%04d", QParserVersionMajor(qp), QParserVersionMinor(qp), QParserVersionPatch(qp));
        CuAssertTrue(tc, strcmp(buffer, QParserVersionName(qp)) == 0);

	qp = QParserFree(qp);
}

/*****************************************************************************
 */
static void TestQParserTag(CuTest* tc) {
	QParser *qp = QParserNew();
        CuAssertTrue(tc, qp != 0);
        CuAssertTrue(tc, QParserVersionTag(qp) != 0);

	qp = QParserFree(qp);
}
/*****************************************************************************
 */
CuSuite *GetSuiteVersion(void) {
	CuSuite *suite = CuSuiteNew();

        SUITE_ADD_TEST(suite, TestQParserMajor);
        SUITE_ADD_TEST(suite, TestQParserMinor);
        SUITE_ADD_TEST(suite, TestQParserPatch);
        SUITE_ADD_TEST(suite, TestQParserName);
        SUITE_ADD_TEST(suite, TestQParserTag);

	return suite;
}
