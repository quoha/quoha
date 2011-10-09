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
static const char *startChunk = "<?quoha ";
static const char *endChunk   = " ?>";

/*****************************************************************************
 */
static void TestQChunk0000(CuTest* tc) {
	QBuffer *qb = 0;
	CuAssertTrue(tc, qb == 0);
	QChunk  *qc = QChunkFromBuffer(qb, startChunk, endChunk);
	CuAssertTrue(tc, qc == 0);
}

/*****************************************************************************
 */
static void TestQChunk0001(CuTest* tc) {
	const char *src = "ab";
	QBuffer *qb = QBufferFromString(src, strlen(src), 0);
	CuAssertTrue(tc, qb != 0);
	QChunk *qc = QChunkFromBuffer(qb, "<", ">");
	CuAssertTrue(tc, qc         != 0);
	CuAssertTrue(tc, qc->prev   == 0);
	CuAssertTrue(tc, qc->next   == 0);
	CuAssertTrue(tc, qc->b      != 0);
	CuAssertTrue(tc, qc->isCode == 0);
	CuAssertTrue(tc, strcmp(qc->b->data, src) == 0);
}

/*****************************************************************************
 */
static void TestQChunk0002(CuTest* tc) {
	const char *src = "<ab>";
	QBuffer *qb = QBufferFromString(src, strlen(src), 0);
	CuAssertTrue(tc, qb != 0);
	QChunk *qc = QChunkFromBuffer(qb, "<", ">");
	CuAssertTrue(tc, qc         != 0);
	CuAssertTrue(tc, qc->prev   == 0);
	CuAssertTrue(tc, qc->next   == 0);
	CuAssertTrue(tc, qc->b      != 0);
	CuAssertTrue(tc, qc->isCode == 1);
	CuAssertTrue(tc, strcmp(qc->b->data, "ab") == 0);
}

/*****************************************************************************
 */
static void TestQChunk0003(CuTest* tc) {
	const char *src = "<ab";
	QBuffer *qb = QBufferFromString(src, strlen(src), 0);
	CuAssertTrue(tc, qb != 0);
	QChunk *qc = QChunkFromBuffer(qb, "<", ">");
	CuAssertTrue(tc, qc         != 0);
	CuAssertTrue(tc, qc->prev   == 0);
	CuAssertTrue(tc, qc->next   == 0);
	CuAssertTrue(tc, qc->b      != 0);
	CuAssertTrue(tc, qc->isCode == 1);
	CuAssertTrue(tc, strcmp(qc->b->data, "ab") == 0);
}

/*****************************************************************************
 */
static void TestQChunk0004(CuTest* tc) {
	const char *src = "<ab>cd";
	QBuffer *qb = QBufferFromString(src, strlen(src), 0);
	CuAssertTrue(tc, qb != 0);
	QChunk *qc = QChunkFromBuffer(qb, "<", ">");
	CuAssertTrue(tc, qc         != 0);
	CuAssertTrue(tc, qc->prev   == 0);
	CuAssertTrue(tc, qc->next   != 0);
	CuAssertTrue(tc, qc->b      != 0);
	CuAssertTrue(tc, qc->isCode == 1);
	CuAssertTrue(tc, strcmp(qc->b->data, "ab") == 0);
	CuAssertTrue(tc, qc->next->prev == qc);
	qc = qc->next;
	CuAssertTrue(tc, qc->next   == 0);
	CuAssertTrue(tc, qc->b      != 0);
	CuAssertTrue(tc, qc->isCode == 0);
	CuAssertTrue(tc, strcmp(qc->b->data, "cd") == 0);
}

/*****************************************************************************
 */
static void TestQChunk0005(CuTest* tc) {
	const char *src = "<ab><cd>";
	QBuffer *qb = QBufferFromString(src, strlen(src), 0);
	CuAssertTrue(tc, qb != 0);
	QChunk *qc = QChunkFromBuffer(qb, "<", ">");
	CuAssertTrue(tc, qc         != 0);
	CuAssertTrue(tc, qc->prev   == 0);
	CuAssertTrue(tc, qc->next   != 0);
	CuAssertTrue(tc, qc->b      != 0);
	CuAssertTrue(tc, qc->isCode == 1);
	CuAssertTrue(tc, strcmp(qc->b->data, "ab") == 0);
	CuAssertTrue(tc, qc->next->prev == qc);
	qc = qc->next;
	CuAssertTrue(tc, qc->next   == 0);
	CuAssertTrue(tc, qc->b      != 0);
	CuAssertTrue(tc, qc->isCode == 1);
	CuAssertTrue(tc, strcmp(qc->b->data, "cd") == 0);
}

/*****************************************************************************
 */
static void TestQChunk0006(CuTest* tc) {
	const char *src = "<ab><";
	QBuffer *qb = QBufferFromString(src, strlen(src), 0);
	CuAssertTrue(tc, qb != 0);
	QChunk *qc = QChunkFromBuffer(qb, "<", ">");
	CuAssertTrue(tc, qc         != 0);
	CuAssertTrue(tc, qc->prev   == 0);
	CuAssertTrue(tc, qc->next   != 0);
	CuAssertTrue(tc, qc->b      != 0);
	CuAssertTrue(tc, qc->isCode == 1);
	CuAssertTrue(tc, strcmp(qc->b->data, "ab") == 0);
	CuAssertTrue(tc, qc->next->prev == qc);
	qc = qc->next;
	CuAssertTrue(tc, qc->next   == 0);
	CuAssertTrue(tc, qc->b      != 0);
	CuAssertTrue(tc, qc->isCode == 1);
	CuAssertTrue(tc, strcmp(qc->b->data, "") == 0);
}

/*****************************************************************************
 */
CuSuite *GetSuiteQChunk(void) {
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestQChunk0000);

	SUITE_ADD_TEST(suite, TestQChunk0001);
	SUITE_ADD_TEST(suite, TestQChunk0002);
	SUITE_ADD_TEST(suite, TestQChunk0003);
	SUITE_ADD_TEST(suite, TestQChunk0004);
	SUITE_ADD_TEST(suite, TestQChunk0005);
	SUITE_ADD_TEST(suite, TestQChunk0006);

	return suite;
}
