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
static void TestQBuffer0000(CuTest* tc) {
	QBuffer *qb = QBufferFromFile("data/qdjinn/buffer/0000.nonExistantFile", 0);
	CuAssertTrue(tc, qb == 0);
}

/*****************************************************************************
 */
static void TestQBuffer0001a(CuTest* tc) {
	QBuffer *qb = QBufferFromFile("data/qdjinn/buffer/0001.emptyFile", 0);
	CuAssertTrue(tc, qb != 0);
	CuAssertTrue(tc, qb->length == 0);
	CuAssertTrue(tc, qb->data == qb->currData);
	CuAssertTrue(tc, qb->data == qb->startOfData);
	CuAssertTrue(tc, qb->data == qb->endOfData);
	CuAssertTrue(tc, qb->data[0] == 0);
	CuAssertTrue(tc, qb->data[qb->length] == 0);
	CuAssertTrue(tc, qb->endOfData[0]     == 0);
}

/*****************************************************************************
 */
static void TestQBuffer0001b(CuTest* tc) {
	QBuffer *qb = QBufferFromFile("data/qdjinn/buffer/0001.emptyFile", 1);
	CuAssertTrue(tc, qb != 0);
	CuAssertTrue(tc, qb->length == 1);
	CuAssertTrue(tc, qb->data == qb->currData);
	CuAssertTrue(tc, qb->data == qb->startOfData);
	CuAssertTrue(tc, qb->data <  qb->endOfData);
	CuAssertTrue(tc, qb->data[0] == '\n');
	CuAssertTrue(tc, qb->data[qb->length] == 0);
	CuAssertTrue(tc, qb->endOfData[0]     == 0);
}

/*****************************************************************************
 */
static void TestQBuffer0002a(CuTest* tc) {
	const char *expect = "Hello, World!\n";
	QBuffer *qb = QBufferFromFile("data/qdjinn/buffer/0002.helloWorld", 0);
	CuAssertTrue(tc, qb != 0);
	CuAssertTrue(tc, qb->length == 14);
	CuAssertTrue(tc, qb->data == qb->currData);
	CuAssertTrue(tc, qb->data == qb->startOfData);
	CuAssertTrue(tc, strcmp(qb->startOfData, expect) == 0);
	CuAssertTrue(tc, qb->data[qb->length] == 0);
	CuAssertTrue(tc, qb->endOfData[0]     == 0);
}

/*****************************************************************************
 */
static void TestQBuffer0003a(CuTest* tc) {
	const char *expect = "line one\nline two";
	QBuffer *qb = QBufferFromFile("data/qdjinn/buffer/0003.missingNewLine", 0);
	CuAssertTrue(tc, qb != 0);
	CuAssertTrue(tc, qb->length == 17);
	CuAssertTrue(tc, strcmp(qb->startOfData, expect) == 0);
	CuAssertTrue(tc, qb->data[qb->length] == 0);
	CuAssertTrue(tc, qb->endOfData[0]     == 0);
}

/*****************************************************************************
 */
static void TestQBuffer0003b(CuTest* tc) {
	const char *expect = "line one\nline two\n";
	QBuffer *qb = QBufferFromFile("data/qdjinn/buffer/0003.missingNewLine", 1);
	CuAssertTrue(tc, qb != 0);
	CuAssertTrue(tc, qb->length == 18);
	CuAssertTrue(tc, strcmp(qb->startOfData, expect) == 0);
	CuAssertTrue(tc, qb->data[qb->length] == 0);
	CuAssertTrue(tc, qb->endOfData[0]     == 0);
}

/*****************************************************************************
 */
static void TestQBuffer0004a(CuTest* tc) {
	QBuffer *qb = QBufferFromFile("data/qdjinn/buffer/0004.lotsOfText", 0);
	CuAssertTrue(tc, qb != 0);
	CuAssertTrue(tc, qb->length == 3488);
	CuAssertTrue(tc, qb->data[qb->length] == 0);
	CuAssertTrue(tc, qb->endOfData[0]     == 0);
}

/*****************************************************************************
 */
static void TestQBuffer0004b(CuTest* tc) {
	QBuffer *qb = QBufferFromFile("data/qdjinn/buffer/0004.lotsOfText", 1);
	CuAssertTrue(tc, qb != 0);
	CuAssertTrue(tc, qb->length == 3488);
	CuAssertTrue(tc, qb->data[qb->length] == 0);
	CuAssertTrue(tc, qb->endOfData[0]     == 0);
}

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
CuSuite *GetSuiteQBuffer(void) {
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestQBuffer0000);
	SUITE_ADD_TEST(suite, TestQBuffer0001a);
	SUITE_ADD_TEST(suite, TestQBuffer0001b);
	SUITE_ADD_TEST(suite, TestQBuffer0002a);
	SUITE_ADD_TEST(suite, TestQBuffer0003a);
	SUITE_ADD_TEST(suite, TestQBuffer0003b);
	SUITE_ADD_TEST(suite, TestQBuffer0004a);
	SUITE_ADD_TEST(suite, TestQBuffer0004b);
	SUITE_ADD_TEST(suite, TestQBuffer0005a);
	SUITE_ADD_TEST(suite, TestQBuffer0005b);
	SUITE_ADD_TEST(suite, TestQBuffer0006a);
	SUITE_ADD_TEST(suite, TestQBuffer0006b);

	return suite;
}
