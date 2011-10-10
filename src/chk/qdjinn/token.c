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
static void TestQToken0000(CuTest* tc) {
	QToken *t = 0;
	CuAssertTrue(tc, t == 0);
}

/*****************************************************************************
 */
static void TestQToken0001(CuTest* tc) {
	const char *src = "a";
	QBuffer *qb = QBufferFromString(src, strlen(src), 0);
	CuAssertTrue(tc, qb != 0);

	QToken *qt = QTokenNext(qb);
	CuAssertTrue(tc, qt != 0);
	CuAssertTrue(tc, qt->data != 0);
	CuAssertTrue(tc, strcmp(src, qt->data) == 0);

	qt = QTokenNext(qb);
	CuAssertTrue(tc, qt == 0);
}

/*****************************************************************************
 */
static void TestQToken0002(CuTest* tc) {
	const char *src = "a b c d e";
	QBuffer *qb = QBufferFromString(src, strlen(src), 0);
	CuAssertTrue(tc, qb != 0);

	QToken *qt = QTokenNext(qb);
	CuAssertTrue(tc, qt != 0);
	CuAssertTrue(tc, qt->data != 0);
	CuAssertTrue(tc, strcmp(qt->data, "a") == 0);

	qt = QTokenNext(qb);
	CuAssertTrue(tc, qt != 0);
	CuAssertTrue(tc, qt->data != 0);
	CuAssertTrue(tc, strcmp(qt->data, "b") == 0);

	qt = QTokenNext(qb);
	CuAssertTrue(tc, qt != 0);
	CuAssertTrue(tc, qt->data != 0);
	CuAssertTrue(tc, strcmp(qt->data, "c") == 0);

	qt = QTokenNext(qb);
	CuAssertTrue(tc, qt != 0);
	CuAssertTrue(tc, qt->data != 0);
	CuAssertTrue(tc, strcmp(qt->data, "d") == 0);

	qt = QTokenNext(qb);
	CuAssertTrue(tc, qt != 0);
	CuAssertTrue(tc, qt->data != 0);
	CuAssertTrue(tc, strcmp(qt->data, "e") == 0);

	qt = QTokenNext(qb);
	CuAssertTrue(tc, qt == 0);
}

/*****************************************************************************
 */
static void TestQToken0003(CuTest* tc) {
	const char *src = "\"a\"";
	QBuffer *qb = QBufferFromString(src, strlen(src), 0);
	CuAssertTrue(tc, qb != 0);

	QToken *qt = QTokenNext(qb);
	CuAssertTrue(tc, qt != 0);
	CuAssertTrue(tc, qt->data != 0);
	CuAssertTrue(tc, strcmp(qt->data, "a") == 0);

	qt = QTokenNext(qb);
	CuAssertTrue(tc, qt == 0);
}

/*****************************************************************************
 */
static void TestQToken0004(CuTest* tc) {
	const char *src = "a \"b\" c d \"e f\" g";
	QBuffer *qb = QBufferFromString(src, strlen(src), 0);
	CuAssertTrue(tc, qb != 0);

	QToken *qt = QTokenNext(qb);
	CuAssertTrue(tc, qt != 0);
	CuAssertTrue(tc, qt->data != 0);
	CuAssertTrue(tc, strcmp(qt->data, "a") == 0);

	qt = QTokenNext(qb);
	CuAssertTrue(tc, qt != 0);
	CuAssertTrue(tc, qt->data != 0);
	CuAssertTrue(tc, strcmp(qt->data, "b") == 0);

	qt = QTokenNext(qb);
	CuAssertTrue(tc, qt != 0);
	CuAssertTrue(tc, qt->data != 0);
	CuAssertTrue(tc, strcmp(qt->data, "c") == 0);

	qt = QTokenNext(qb);
	CuAssertTrue(tc, qt != 0);
	CuAssertTrue(tc, qt->data != 0);
	CuAssertTrue(tc, strcmp(qt->data, "d") == 0);

	qt = QTokenNext(qb);
	CuAssertTrue(tc, qt != 0);
	CuAssertTrue(tc, qt->data != 0);
	CuAssertTrue(tc, strcmp(qt->data, "e f") == 0);

	qt = QTokenNext(qb);
	CuAssertTrue(tc, qt != 0);
	CuAssertTrue(tc, qt->data != 0);
	CuAssertTrue(tc, strcmp(qt->data, "g") == 0);

	qt = QTokenNext(qb);
	CuAssertTrue(tc, qt == 0);
}

/*****************************************************************************
 */
CuSuite *GetSuiteQToken(void) {
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestQToken0000);
	SUITE_ADD_TEST(suite, TestQToken0001);
	SUITE_ADD_TEST(suite, TestQToken0002);
	SUITE_ADD_TEST(suite, TestQToken0003);
	SUITE_ADD_TEST(suite, TestQToken0004);

	return suite;
}
