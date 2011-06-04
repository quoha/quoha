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

#ifndef Quoha_src_lib_QExpr_local_H
#define Quoha_src_lib_QExpr_local_H

#include "QCons.h"

//#include "QExpr.h"

#define QE_TYPE_ATOM         0x0001  /*          0x01 */
#define QE_TYPE_ATOM_NIL     0x0003  /* 0x0002 + 0x01 */
#define QE_TYPE_ATOM_INTEGER 0x0005  /* 0x0004 + 0x01 */
#define QE_TYPE_ATOM_STRING  0x0007  /* 0x0006 + 0x01 */
#define QE_TYPE_ATOM_USTRING 0x0009  /* 0x0008 + 0x01 */
#define QE_TYPE_LIST         0x0010  /*          0x10 */
#define QE_TYPE_LIST_NIL     0x0030  /* 0x0020 + 0x10 */

#define QCELL_TYPE_NIL     0x0000
#define QCELL_TYPE_INTEGER 0x0001
#define QCELL_TYPE_STRING  0x0002

#endif
