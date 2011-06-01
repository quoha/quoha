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
static void TestQConsCar(CuTest* tc) {
	QConsCell *qcc = 0;
        CuAssertTrue(tc, QConsCellCar(qcc) == 0);

	int         iCar = 42;
	const char *sCdr = "42";

	QCell *car = QCellNewInteger(iCar);
	QCell *cdr = QCellNewString(sCdr);

	qcc = QConsCellNew(car, cdr);

	QCell *rslt = QConsCellCar(qcc);
        CuAssertTrue(tc, rslt != 0);
        CuAssertTrue(tc, rslt == car);
	CuAssertTrue(tc, QCellAsInteger(rslt) == iCar);

	qcc = QConsCellFree(qcc);

	car = QCellFree(car);
	cdr = QCellFree(cdr);
}

/*****************************************************************************
 */
static void TestQConsCdr(CuTest* tc) {
	QConsCell *qcc = 0;
        CuAssertTrue(tc, QConsCellCdr(qcc) == 0);

	int         iCar = 42;
	const char *sCdr = "42";

	QCell *car = QCellNewInteger(iCar);
	QCell *cdr = QCellNewString(sCdr);

	qcc = QConsCellNew(car, cdr);

	QCell *rslt = QConsCellCdr(qcc);
        CuAssertTrue(tc, rslt != 0);
        CuAssertTrue(tc, rslt == cdr);
	CuAssertTrue(tc, strcmp(QCellAsString(rslt), sCdr) == 0);

	qcc = QConsCellFree(qcc);

	car = QCellFree(car);
	cdr = QCellFree(cdr);
}

/*****************************************************************************
 */
static void TestQConsCell(CuTest* tc) {
	int         iCar = 42;
	const char *sCdr = "42";

	QCell *car = QCellNewInteger(iCar);
	QCell *cdr = QCellNewString(sCdr);

	QConsCell *qcc = QConsCellNew(car, cdr);
        CuAssertTrue(tc, qcc != 0);
        CuAssertTrue(tc, QConsCellCar(qcc) == car);
        CuAssertTrue(tc, QConsCellCdr(qcc) == cdr);

	qcc = QConsCellFree(qcc);
        CuAssertTrue(tc, qcc == 0);

	car = QCellFree(car);
	cdr = QCellFree(cdr);
}

/*****************************************************************************
 */
CuSuite *GetSuiteConsCell(void) {
	CuSuite *suite = CuSuiteNew();

        SUITE_ADD_TEST(suite, TestQConsCell);
        SUITE_ADD_TEST(suite, TestQConsCar);
        SUITE_ADD_TEST(suite, TestQConsCdr);

	return suite;
}
