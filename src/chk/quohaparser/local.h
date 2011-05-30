#ifndef quoha_src_chk_quohaparser_local_H
#define quoha_src_chk_quohaparser_local_H

/*****************************************************************************
 * we use CuTest as our framework
 */
#include <CuTest.h>

/*****************************************************************************
 * bring in the parser
 */
#include "../../lib/quohaparser/QuohaParser.h"

/*****************************************************************************
 * declare our test suites. every test suite looks like
 *    CuSuite *GetSuiteXXXX(void);
 */
CuSuite *GetSuiteInit();

#endif
