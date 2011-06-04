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
static void TestQAtom(CuTest* tc) {
	QAtom *atom = QAtomNew();
	CuAssertTrue(tc, atom != 0);

	CuAssertTrue(tc, !QAtomIsInteger(atom));
	CuAssertTrue(tc, QAtomIsNil(atom));
	CuAssertTrue(tc, !QAtomIsString(atom));

	atom = QAtomFree(atom);
	CuAssertTrue(tc, atom == 0);
}

/*****************************************************************************
 */
static void TestInteger(CuTest* tc) {
	QAtom *atom = QAtomNew();
	CuAssertTrue(tc, atom != 0);

	int integer = 42;

	CuAssertTrue(tc, QAtomSetInteger(atom, integer) == atom);
	CuAssertTrue(tc, QAtomIsInteger(atom));
	CuAssertTrue(tc, !QAtomIsNil(atom));
	CuAssertTrue(tc, !QAtomIsString(atom));

	CuAssertTrue(tc, QAtomAsInteger(atom) == integer);

	CuAssertTrue(tc, QAtomSetInteger(atom, integer / 2) == atom);
	CuAssertTrue(tc, QAtomIsInteger(atom));
	CuAssertTrue(tc, !QAtomIsNil(atom));
	CuAssertTrue(tc, !QAtomIsString(atom));

	CuAssertTrue(tc, QAtomAsInteger(atom) == (integer / 2));

	CuAssertTrue(tc, QAtomSetNil(atom) == atom);
	CuAssertTrue(tc, QAtomIsNil(atom));
	CuAssertTrue(tc, QAtomAsInteger(atom) == 0);

	atom = QAtomFree(atom);
	CuAssertTrue(tc, atom == 0);
}

/*****************************************************************************
 */
static void TestNil(CuTest* tc) {
	QAtom *atom = QAtomNew();
	CuAssertTrue(tc, atom != 0);

	CuAssertTrue(tc, QAtomSetNil(atom) == atom);
	CuAssertTrue(tc, !QAtomIsInteger(atom));
	CuAssertTrue(tc, QAtomIsNil(atom));
	CuAssertTrue(tc, !QAtomIsString(atom));

	CuAssertTrue(tc, QAtomAsString(atom) == 0);

	int integer = 42;
	CuAssertTrue(tc, QAtomSetInteger(atom, integer) == atom);
	CuAssertTrue(tc, QAtomIsInteger(atom));

	CuAssertTrue(tc, QAtomSetNil(atom) == atom);
	CuAssertTrue(tc, QAtomIsNil(atom));

	atom = QAtomFree(atom);
	CuAssertTrue(tc, atom == 0);
}

/*****************************************************************************
 */
static void TestString(CuTest* tc) {
	QAtom *atom = QAtomNew();
	CuAssertTrue(tc, atom != 0);

	const char *string = "42";

	QAtomSetString(atom, string);
	CuAssertTrue(tc, QAtomSetString(atom, string) == atom);
	CuAssertTrue(tc, !QAtomIsInteger(atom));
	CuAssertTrue(tc, !QAtomIsNil(atom));
	CuAssertTrue(tc, QAtomIsString(atom));
	CuAssertTrue(tc, !QAtomIsUString(atom));

	CuAssertTrue(tc, QAtomAsString(atom) == string);
	CuAssertTrue(tc, QAtomAsUString(atom) == 0);

	CuAssertTrue(tc, strcmp(QAtomAsString(atom), string) == 0);

	string = "quoha";
	CuAssertTrue(tc, strcmp(QAtomAsString(atom), string) != 0);

	atom = QAtomFree(atom);
	CuAssertTrue(tc, atom == 0);
}

/*****************************************************************************
 */
static void TestUString(CuTest* tc) {
	QAtom *atom = QAtomNew();
	CuAssertTrue(tc, atom != 0);

	const unsigned char *ustring = "42";

	QAtomSetString(atom, ustring);
	CuAssertTrue(tc, QAtomSetUString(atom, ustring) == atom);
	CuAssertTrue(tc, !QAtomIsInteger(atom));
	CuAssertTrue(tc, !QAtomIsNil(atom));
	CuAssertTrue(tc, !QAtomIsString(atom));
	CuAssertTrue(tc, QAtomIsUString(atom));

	CuAssertTrue(tc, QAtomAsString(atom) == 0);
	CuAssertTrue(tc, QAtomAsUString(atom) == ustring);

	CuAssertTrue(tc, strcmp(QAtomAsUString(atom), ustring) == 0);

	ustring = "quoha";
	CuAssertTrue(tc, strcmp(QAtomAsUString(atom), ustring) != 0);

	atom = QAtomFree(atom);
	CuAssertTrue(tc, atom == 0);
}

/*****************************************************************************
 */
CuSuite *GetSuiteAtom(void) {
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestQAtom);
	SUITE_ADD_TEST(suite, TestNil);
	SUITE_ADD_TEST(suite, TestInteger);
	SUITE_ADD_TEST(suite, TestString);
	SUITE_ADD_TEST(suite, TestUString);

	return suite;
}
