/*
 * $Id$
 */

/*
   Harbour Project source code

   Harbour compiler and runtime configuration file

   Copyright 1999  Ryszard Glab
   www - http://www.harbour-project.org

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version, with one exception:

   The exception is that if you link the Harbour Runtime Library (HRL)
   and/or the Harbour Virtual Machine (HVM) with other files to produce
   an executable, this does not by itself cause the resulting executable
   to be covered by the GNU General Public License. Your use of that
   executable is in no way restricted on account of linking the HRL
   and/or HVM code into it.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA (or visit
   their web site at http://www.gnu.org/).
 */

#ifndef HB_SETUP_H_
#define HB_SETUP_H_

/* ***********************************************************************
 * This symbol defines if Harbour is compiled using C compiler
 * that support strict ANSI C only
 *
 * The only non ANSI C feature that we are using is an ability
 * to call functions before the 'main' module is called.
 * This trick is used to automatically join all symbol tables defined
 * in run-time support modules and in user defined modules.
 *   If strict ANSI C compability is required then all symbol tables
 * have to be joined manually by calling special function named
 * <module_name>__InitSymbols
 * (for example for myfirst.prg it will be: 'MYFIRST__InitSymbols'
 * The generation of this function is performed by the macro called
 * HB_CALL_ON_STARTUP that is defined in 'init.h'
 *
 * By default we are using extensions to ANSI C (symbol is not defined)
*/
/*#define HARBOUR_STRICT_ANSI_C */

/* ***********************************************************************
 * This symbol defines if we are trying to compile using GCC for OS/2
 *
 * By default it is disabled (symbol is not defined)
*/
/*#define HARBOUR_GCC_OS2*/

/* ***********************************************************************
 * The name of starting procedure
 * Note: You have to define it in case when Harbour cannot find the proper
 * starting procedure (due to incorrect order of static data initialization)
 *
 * The list of compilers that require it:
 * - Watcom C/C++ 10.0
 * - GCC on Linux
 *
 * By default we are using automatic lookup (symbol not defined)
*/
#if defined(__WATCOMC__) || defined(__GNUC__)
  #if !defined(__DJGPP__) && !defined(HARBOUR_GCC_OS2)
    #define HARBOUR_START_PROCEDURE "MAIN"
  #endif
#endif

/* ***********************************************************************
 * This symbol defines which national language module should be included
 * in the Harbour run time library. See source/rtl/msgxxx for all allowed
 * values for <nl> in this manifest constant.
 *
 * By default it is disabled (symbol is not defined), which selects UK
*/
/*#define HARBOUR_LANGUAGE_<nl>*/

/* ***********************************************************************
 * This symbol defines if we want an ability to create and link OBJ files
 * generated by Harbour compiler
 *
 * By default it is disabled (symbol is not defined)
*/
/*#define HARBOUR_OBJ_GENERATION*/

/* ***********************************************************************
 * This symbol defines if we want to use strict Clipper compatibility
 *
 * By default it is disabled (symbol is not defined)
*/
/*#define HARBOUR_STRICT_CLIPPER_COMPATIBILITY*/

/* ***********************************************************************
 * These symbols defines if we want to use the GT API (and which platform
 * to build the GT API for, if using the GNU Make System).
 *
 * By default they are disabled (symbols are not defined)
*/
/*#define HARBOUR_USE_DOS_GTAPI*/
/*#define HARBOUR_USE_OS2_GTAPI*/
/*#define HARBOUR_USE_WIN_GTAPI*/

/* Indicate that one of the GTAPIs is defined */
#if defined(HARBOUR_USE_DOS_GTAPI) || defined(HARBOUR_USE_OS2_GTAPI) || defined(HARBOUR_USE_WIN_GTAPI)
  #define HARBOUR_USE_GTAPI
#endif

/* ***********************************************************************
 * These symbols defined if we want to use the MOUSE API (and which platform
 * to build the MOUSE API for, if using the GNU Make System).
 *
 * By default they are disabled (symbols are not defined)
*/
/*#define HARBOUR_USE_DOS_MSAPI*/
/*#define HARBOUR_USE_OS2_MSAPI*/
/*#define HARBOUR_USE_WIN_MSAPI*/

/* Indicate that one of the GTAPIs is defined */
#if defined(HARBOUR_USE_DOS_MSAPI) || defined(HARBOUR_USE_OS2_MSAPI) || defined(HARBOUR_USE_WIN_MSAPI)
  #define HARBOUR_USE_MSAPI
#endif

/* ***********************************************************************
 * Operating system specific definitions
 */
#ifdef __GNUC__
  /* The GNU C compiler is used */
  #if defined(__DJGPP__) || defined(HARBOUR_GCC_OS2) || defined(_Windows) || defined(_WIN32)
    /* The DJGPP port of GNU C is used - for DOS platform */
    #define OS_PATH_LIST_SEPARATOR   ';'
    #define OS_PATH_DELIMITER '\\'
    #define OS_DOS_COMPATIBLE
  #else
    #define OS_PATH_LIST_SEPARATOR   ':'
    #define OS_PATH_DELIMITER '/'
    #define OS_UNIX_COMPATIBLE
  #endif
#else
  /* we are assuming here the DOS compatible OS */
  #define OS_PATH_LIST_SEPARATOR    ';'
  #define OS_PATH_DELIMITER '\\'
  #define OS_DOS_COMPATIBLE
#endif

/* ***********************************************************************
 * Platform detection
 */

#ifndef DOS
#if defined(_QC) || defined(__DOS__) || defined(MSDOS) || defined(__MSDOS__)
#define DOS
#endif
#endif

#ifndef OS2
#if defined(__OS2__) || defined(OS_2) || defined(HARBOUR_GCC_OS2)
#define OS2
#endif
#endif

#ifndef EMX
#if defined(__EMX__)
#define EMX
#endif
#endif

#ifndef WINNT
#if defined(__NT__)
#define WINNT
#endif
#endif

#endif /* HB_SETUP_H_ */
