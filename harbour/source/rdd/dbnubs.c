/*
 * $Id$
 */

/*
 * Harbour Project source code:
 * Internal versions for database version (Clipper undocumented)
 *
 * Copyright 1999 Victor Szel <info@szelvesz.hu>
 * www - http://www.harbour-project.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version, with one exception:
 *
 * The exception is that if you link the Harbour Runtime Library (HRL)
 * and/or the Harbour Virtual Machine (HVM) with other files to produce
 * an executable, this does not by itself cause the resulting executable
 * to be covered by the GNU General Public License. Your use of that
 * executable is in no way restricted on account of linking the HRL
 * and/or HVM code into it.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA (or visit
 * their web site at http://www.gnu.org/).
 *
 */

#include "hbdefs.h"

extern HARBOUR HB_DBSEEK();
extern HARBOUR HB_DBSKIP();
extern HARBOUR HB_DBGOTOP();
extern HARBOUR HB_DBGOBOTTOM();
extern HARBOUR HB_DBGOTO();
extern HARBOUR HB_DBAPPEND();
extern HARBOUR HB_DBDELETE();
extern HARBOUR HB_DBRECALL();
extern HARBOUR HB_DBCOMMITALL();
extern HARBOUR HB_DBUNLOCK();
extern HARBOUR HB_DBUNLOCKALL();
extern HARBOUR HB_DBSETFILTER();
extern HARBOUR HB_DBCLEARRELATION();
extern HARBOUR HB_DBSETRELATION();
extern HARBOUR HB_DBREINDEX();
extern HARBOUR HB_DBCREATEINDEX();
extern HARBOUR HB_DBCLEARINDEX();
extern HARBOUR HB_DBSETINDEX();
extern HARBOUR HB_DBSETORDER();
extern HARBOUR HB_DBCLOSEALL();
extern HARBOUR HB_DBCLOSEAREA();
extern HARBOUR HB_DBUSEAREA();
extern HARBOUR HB_DBSELECTAREA();

HARBOUR HB___DBSEEK( void )
{
   HB_DBSEEK();
}

HARBOUR HB___DBSKIP( void )
{
   HB_DBSKIP();
}

HARBOUR HB___DBGOTOP( void )
{
   HB_DBGOTOP();
}

HARBOUR HB___DBGOBOTTOM( void )
{
   HB_DBGOBOTTOM();
}

HARBOUR HB___DBGOTO( void )
{
   HB_DBGOTO();
}

HARBOUR HB___DBAPPEND( void )
{
   HB_DBAPPEND();
}

HARBOUR HB___DBDELETE( void )
{
   HB_DBDELETE();
}

HARBOUR HB___DBRECALL( void )
{
   HB_DBRECALL();
}

/* NOTE: Clipper does exactly that, __dbCommit() will call dbCommitAll() 
         This may be a bug. */

HARBOUR HB___DBCOMMIT( void )
{
   HB_DBCOMMITALL();
}

HARBOUR HB___DBCOMMITALL( void )
{
   HB_DBCOMMITALL();
}

HARBOUR HB___DBUNLOCK( void )
{
   HB_DBUNLOCK();
}

HARBOUR HB___DBUNLALL( void )
{
   HB_DBUNLOCKALL();
}

HARBOUR HB___DBSETFILTER( void )
{
   HB_DBSETFILTER();
}

HARBOUR HB___DBCLEARRELATION( void )
{
   HB_DBCLEARRELATION();
}

HARBOUR HB___DBSETRELATION( void )
{
   HB_DBSETRELATION();
}

HARBOUR HB___DBREINDEX( void )
{
   HB_DBREINDEX();
}

HARBOUR HB___DBCREATINDEX( void )
{
   HB_DBCREATEINDEX();
}

HARBOUR HB___DBCLEARINDEX( void )
{
   HB_DBCLEARINDEX();
}

HARBOUR HB___DBSETINDEX( void )
{
   HB_DBSETINDEX();
}

HARBOUR HB___DBSETORDER( void )
{
   HB_DBSETORDER();
}

HARBOUR HB___DBCLOSEAREA( void )
{
   HB_DBCLOSEALL();
}

HARBOUR HB___DBCLOSE( void )
{
   HB_DBCLOSEAREA();
}

HARBOUR HB___DBUSE( void )
{
   HB_DBUSEAREA();
}

HARBOUR HB___DBSELECT( void )
{
   HB_DBSELECTAREA();
}

