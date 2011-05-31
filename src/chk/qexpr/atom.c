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
static void TestQExprAtom(CuTest* tc) {
	QExpr *qe = QExprNew();
        CuAssertTrue(tc, qe != 0);
        CuAssertTrue(tc, QExprIsAtom(qe) != 0);
}

/*****************************************************************************
 */
static void TestQExprInteger(CuTest* tc) {
	QExpr *qe = QExprNew();
        CuAssertTrue(tc, qe != 0);

	QExprSetAtomInteger(qe, 42);
        CuAssertTrue(tc, QExprIsAtom(qe) != 0);
        CuAssertTrue(tc, QExprIsAtomNil(qe) == 0);
        CuAssertTrue(tc, QExprIsInteger(qe) != 0);
        CuAssertTrue(tc, QExprIsString(qe) == 0);

        CuAssertTrue(tc, QExprAsInteger(qe) == 42);

	qe = QExprFree(qe);
        CuAssertTrue(tc, qe == 0);
}

/*****************************************************************************
 */
static void TestQExprNil(CuTest* tc) {
	QExpr *qe = QExprNew();
        CuAssertTrue(tc, qe != 0);
        CuAssertTrue(tc, QExprIsAtom(qe) != 0);
        CuAssertTrue(tc, QExprIsAtomNil(qe) != 0);
        CuAssertTrue(tc, QExprIsInteger(qe) == 0);
        CuAssertTrue(tc, QExprIsString(qe) == 0);
}

/*****************************************************************************
 */
static void TestQExprString(CuTest* tc) {
	QExpr *qe = QExprNew();
        CuAssertTrue(tc, qe != 0);

	const char *str = "42";

	QExprSetAtomString(qe, str);
        CuAssertTrue(tc, QExprIsAtom(qe) != 0);
        CuAssertTrue(tc, QExprIsAtomNil(qe) == 0);
        CuAssertTrue(tc, QExprIsInteger(qe) == 0);
        CuAssertTrue(tc, QExprIsString(qe) != 0);

        CuAssertTrue(tc, QExprAsString(qe) == str);
        CuAssertTrue(tc, strcmp(QExprAsString(qe), str) == 0);

	qe = QExprFree(qe);
        CuAssertTrue(tc, qe == 0);
}

/*****************************************************************************
 */
CuSuite *GetSuiteAtom(void) {
	CuSuite *suite = CuSuiteNew();

        SUITE_ADD_TEST(suite, TestQExprAtom);
        SUITE_ADD_TEST(suite, TestQExprNil);
        SUITE_ADD_TEST(suite, TestQExprInteger);
        SUITE_ADD_TEST(suite, TestQExprString);

	return suite;
}
