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
static void TestAtom(CuTest* tc) {
	QParser *qp = QParserNew();
        CuAssertTrue(tc, qp != 0);

	const char testString[] = "atom";
	int        testLength   = sizeof(testString);

	unsigned char buffer[128];
	memcpy(buffer, testString, testLength);
	CuAssertTrue(tc, memcmp(testString, buffer, testLength) == 0);

	int rc = QParserSetBuffer(qp, buffer, testLength);
	CuAssertTrue(tc, rc == 0);
	//CuAssertTrue(tc, qp->data.start == buffer);
	//CuAssertTrue(tc, qp->data.end   == qp->data.start + testLength);
	//CuAssertTrue(tc, qp->data.next  == qp->data.start);

	const char *expectString = "atom";

	QToken *qt = QParserNextToken(qp);
	CuAssertTrue(tc, qt != 0);
	CuAssertTrue(tc, qt->data == buffer);
	CuAssertTrue(tc, strlen(qt->data) == strlen(expectString));
	CuAssertTrue(tc, strcmp(qt->data, expectString) == 0);
	//CuAssertTrue(tc, qp->data.next == qp->data.end);

	qt = QParserNextToken(qp);
	CuAssertTrue(tc, qt == 0);

	qp = QParserFree(qp);
}

/*****************************************************************************
 */
static void TestSetBufferInvalid(CuTest *tc) {
	const char testString[] = "atom";
	int        testLength   = sizeof(testString);

	unsigned char buffer[128];
	memcpy(buffer, testString, testLength);
	CuAssertTrue(tc, memcmp(testString, buffer, testLength) == 0);

	QParser *qp = 0;

	int rc = QParserSetBuffer(qp, buffer, testLength);
	CuAssertTrue(tc, rc == -1);

	qp = QParserNew();
        CuAssertTrue(tc, qp != 0);

	rc = QParserSetBuffer(qp, 0, testLength);
	CuAssertTrue(tc, rc == -2);

	rc = QParserSetBuffer(qp, buffer, -1);
	CuAssertTrue(tc, rc == -3);

	rc = QParserSetBuffer(qp, buffer, QUOHAPARSER_MAX_BUFSZ - 1);
	CuAssertTrue(tc, rc == 0);

	rc = QParserSetBuffer(qp, buffer, QUOHAPARSER_MAX_BUFSZ + 0);
	CuAssertTrue(tc, rc == 0);

	rc = QParserSetBuffer(qp, buffer, QUOHAPARSER_MAX_BUFSZ + 1);
	CuAssertTrue(tc, rc == -4);

	qp = QParserFree(qp);
}

/*****************************************************************************
 */
static void TestSetBufferValid(CuTest *tc) {
	QParser *qp = QParserNew();
        CuAssertTrue(tc, qp != 0);

	const char testString[] = "atom";
	int        testLength   = sizeof(testString);

	unsigned char buffer[128];
	memcpy(buffer, testString, testLength);
	CuAssertTrue(tc, memcmp(testString, buffer, testLength) == 0);

	int rc = QParserSetBuffer(qp, buffer, testLength);
	CuAssertTrue(tc, rc == 0);
	//CuAssertTrue(tc, qp->data.start == buffer);
	//CuAssertTrue(tc, qp->data.end   == qp->data.start + testLength);
	//CuAssertTrue(tc, qp->data.next  == qp->data.start);

	qp = QParserFree(qp);
}

/*****************************************************************************
 */
CuSuite *GetSuiteFromBuffer(void) {
	CuSuite *suite = CuSuiteNew();

        SUITE_ADD_TEST(suite, TestSetBufferValid);
        SUITE_ADD_TEST(suite, TestSetBufferInvalid);
        SUITE_ADD_TEST(suite, TestAtom);

	return suite;
}
