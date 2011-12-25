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
static void TestQState0000(CuTest* tc) {
	QState *qs = 0;
	CuAssertTrue(tc, qs == 0);

	CuAssertTrue(tc, QStateStatus(qs) == QDJINN_ERROR);
	CuAssertTrue(tc, QStateError (qs) == QDJINN_ERROR);
}

/*****************************************************************************
 */
static void TestQState0001(CuTest* tc) {
	QState *qs = QStateNew();
	CuAssertTrue(tc, qs != 0);

	CuAssertTrue(tc, QStateStatus(qs) == QDJINN_OK);
	CuAssertTrue(tc, QStateError(qs)  == QDJINN_OK);

	qs = QStateFree(qs);
	CuAssertTrue(tc, qs == 0);
}

/*****************************************************************************
 */
static void TestQState0002(CuTest* tc) {
	QState *qs = QStateNew();
	CuAssertTrue(tc, qs != 0);

	CuAssertTrue(tc, QStateVersionMajor(qs) == QStateVersionMajor(0));
	CuAssertTrue(tc, QStateVersionMinor(qs) == QStateVersionMinor(0));
	CuAssertTrue(tc, QStateVersionPatch(qs) == QStateVersionPatch(0));
	CuAssertTrue(tc, QStateVersionName (qs) == QStateVersionName (0));
	CuAssertTrue(tc, QStateVersionTag  (qs) == QStateVersionTag  (0));

	char buffer[128];
	sprintf(buffer, "%02d.%03d.%04d", QStateVersionMajor(qs), QStateVersionMinor(qs), QStateVersionPatch(qs));
	CuAssertTrue(tc, strcmp(buffer, QStateVersionName(qs)) == 0);

	qs = QStateFree(qs);
	CuAssertTrue(tc, qs == 0);
}

/*****************************************************************************
 */
static void TestQState0003(CuTest* tc) {
	const char *fileName = "data/qdjinn/QState/0003.nonExistantFile";

	QState *qs = QStateNew();
	CuAssertTrue(tc, qs != 0);

	int rc = QStateLoadFromFile(qs, fileName);
	CuAssertTrue(tc, rc            == QDJINN_ERROR);
	CuAssertTrue(tc, qs->lastError == QDJINN_NONEXIST);
	CuAssertTrue(tc, QStateError(qs) == qs->lastError);

	qs = QStateFree(qs);
	CuAssertTrue(tc, qs == 0);
}

/*****************************************************************************
 */
static void TestQState0004(CuTest* tc) {
	const char *fileName = "data/qdjinn/QState/0004.dump";
	QState *qs = QStateNew();
	CuAssertTrue(tc, qs != 0);

	int rc = QStateLoadFromFile(qs, fileName);
	CuAssertTrue(tc, rc == QDJINN_OK);

	qs = QStateFree(qs);
	CuAssertTrue(tc, qs == 0);
}

/*****************************************************************************
 */
CuSuite *GetSuiteQState(void) {
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestQState0000);
	SUITE_ADD_TEST(suite, TestQState0001);
	SUITE_ADD_TEST(suite, TestQState0002);
	SUITE_ADD_TEST(suite, TestQState0003);
	SUITE_ADD_TEST(suite, TestQState0004);

	return suite;
}
