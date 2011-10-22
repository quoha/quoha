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

#ifndef quoha_src_chk_QBuffer_local_H
#define quoha_src_chk_QBuffer_local_H

/*****************************************************************************
 * we use CuTest as our framework
 */
#include <CuTest.h>

/*****************************************************************************
 * standard libraries
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*****************************************************************************
 * bring in the engine
 */
#include "../../lib/qdjinn/qdjinn.h"

/*****************************************************************************
 * declare our test suites. every test suite looks like
 *    CuSuite *GetSuiteXXXX(void);
 */
CuSuite *GetSuiteQBuffer();

#endif
