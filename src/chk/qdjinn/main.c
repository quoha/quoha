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
int main(int argc, char *argv[]) {
	int idx;
	for (idx = 1; idx < argc; ++idx) {
		if (strcmp(argv[idx], "--env-file-name") == 0) {
			printf("envDefault");
			return 0;
		} else {
			printf("error:\tinvalid option '%s'\n", argv[idx]);
			return 2;
		}
	}

	/* this is our global suite */
	CuSuite *suite  = CuSuiteNew();

	/* register the functions in the order that we should run them */
	CuSuiteAddSuite(suite, GetSuiteQBuffer());
	CuSuiteAddSuite(suite, GetSuiteQBufferIssue());
	CuSuiteAddSuite(suite, GetSuiteQChunk());
	CuSuiteAddSuite(suite, GetSuiteQChunkIssue());
	CuSuiteAddSuite(suite, GetSuiteQToken());
	CuSuiteAddSuite(suite, GetSuiteQTokenIssue());
	CuSuiteAddSuite(suite, GetSuiteQParser());
	CuSuiteAddSuite(suite, GetSuiteQParserIssue());
	CuSuiteAddSuite(suite, GetSuiteQState());
	CuSuiteAddSuite(suite, GetSuiteQStateIssue());

	/* run them */
	CuSuiteRun(suite);

	/* format our output for the log */
	CuString *output = CuStringNew();
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);

	/* there's no public interface to the failCount, so cheat
	 * and use the value directly
	 */
	return suite->failCount == 0 ? 0 : 2;
}
