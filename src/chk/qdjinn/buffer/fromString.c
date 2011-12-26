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
 */
static void TestQBuffer0005a(CuTest* tc) {
	const char *src    = "Hello, World!";
	const char *expect = "Hello, World!";
	QBuffer *qb = QBufferFromString(src, strlen(src), 0);
	CuAssertTrue(tc, qb != 0);
	CuAssertTrue(tc, qb->length == strlen(expect));
	CuAssertTrue(tc, strcmp(qb->startOfData, expect) == 0);
	CuAssertTrue(tc, qb->data[qb->length] == 0);
	CuAssertTrue(tc, qb->endOfData[0]     == 0);
}

/*****************************************************************************
 */
static void TestQBuffer0005b(CuTest* tc) {
	const char *src    = "Hello, World!";
	const char *expect = "Hello, World!\n";
	QBuffer *qb = QBufferFromString(src, strlen(src), 1);
	CuAssertTrue(tc, qb != 0);
	CuAssertTrue(tc, qb->length == strlen(expect));
	CuAssertTrue(tc, strcmp(qb->startOfData, expect) == 0);
	CuAssertTrue(tc, qb->data[qb->length] == 0);
	CuAssertTrue(tc, qb->endOfData[0]     == 0);
}

/*****************************************************************************
 */
static void TestQBuffer0006a(CuTest* tc) {
	const char *src    = "Hello, World!\n";
	const char *expect = "Hello, World!\n";
	QBuffer *qb = QBufferFromString(src, strlen(src), 0);
	CuAssertTrue(tc, qb != 0);
	CuAssertTrue(tc, qb->length == strlen(expect));
	CuAssertTrue(tc, strcmp(qb->startOfData, expect) == 0);
	CuAssertTrue(tc, qb->data[qb->length] == 0);
	CuAssertTrue(tc, qb->endOfData[0]     == 0);
}

/*****************************************************************************
 */
static void TestQBuffer0006b(CuTest* tc) {
	const char *src    = "Hello, World!\n";
	const char *expect = "Hello, World!\n";
	QBuffer *qb = QBufferFromString(src, strlen(src), 1);
	CuAssertTrue(tc, qb != 0);
	CuAssertTrue(tc, qb->length == strlen(expect));
	CuAssertTrue(tc, strcmp(qb->startOfData, expect) == 0);
	CuAssertTrue(tc, qb->data[qb->length] == 0);
	CuAssertTrue(tc, qb->endOfData[0]     == 0);
}

/*****************************************************************************
 */
static void TestQBuffer0007(CuTest* tc) {
	const char *src    = "testing free";
	QBuffer *qb = QBufferFromString(src, strlen(src), 0);
	CuAssertTrue(tc, qb != 0);
	qb = QBufferFree(qb);
	CuAssertTrue(tc, qb == 0);
}

/*****************************************************************************
 */
CuSuite *GetSuiteQBufferFromString(void) {
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestQBuffer0005a);
	SUITE_ADD_TEST(suite, TestQBuffer0005b);
	SUITE_ADD_TEST(suite, TestQBuffer0006a);
	SUITE_ADD_TEST(suite, TestQBuffer0006b);
	SUITE_ADD_TEST(suite, TestQBuffer0007);

	return suite;
}
