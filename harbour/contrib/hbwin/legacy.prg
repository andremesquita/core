/*
 * $Id$
 */

/*
 * Harbour Project source code:
 * Compatibility calls.
 *
 * Copyright 2009 Viktor Szakats (harbour.01 syenar.hu)
 * www - http://www.harbour-project.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307 USA (or visit the web site http://www.gnu.org/).
 *
 * As a special exception, the Harbour Project gives permission for
 * additional uses of the text contained in its release of Harbour.
 *
 * The exception is that, if you link the Harbour libraries with other
 * files to produce an executable, this does not by itself cause the
 * resulting executable to be covered by the GNU General Public License.
 * Your use of that executable is in no way restricted on account of
 * linking the Harbour library code into it.
 *
 * This exception does not however invalidate any other reasons why
 * the executable file might be covered by the GNU General Public License.
 *
 * This exception applies only to the code released by the Harbour
 * Project under the name Harbour.  If you copy code from other
 * Harbour Project or Free Software Foundation releases into a copy of
 * Harbour, as the General Public License permits, the exception does
 * not apply to the code that you add in this way.  To avoid misleading
 * anyone as to the status of such modified files, you must delete
 * this exception notice from them.
 *
 * If you write modifications of your own for Harbour, it is your choice
 * whether to permit this exception to apply to your modifications.
 * If you do not wish that, delete this exception notice.
 *
 */

#define HB_CLS_NOTOBJECT  /* avoid definition of method: INIT */

#include "hbclass.ch"

#include "common.ch"

CREATE CLASS TOLEAUTO FROM WIN_OLEAUTO
   /* TODO: Implement compatibility to the required extent */
   METHOD New( xOle, cIID )
   METHOD hObj( xOle )
ENDCLASS

METHOD New( xOle, cIID ) CLASS TOLEAUTO

   IF ISNUMBER( xOle )
      xOle := win_N2P( xOle )
   ENDIF

   IF hb_isPointer( xOle )
      ::__hObj := xOle
   ELSEIF ISCHARACTER( xOle )
      xOle := __OleCreateObject( xOle, cIID )
      IF ! Empty( xOle )
         ::__hObj := xOle
      ENDIF
   ENDIF

   RETURN Self

METHOD hObj( xOle ) CLASS TOLEAUTO

   IF PCount() > 0 .AND. xOle != NIL
      IF ISNUMBER( xOle )
         xOle := win_N2P( xOle )
      ENDIF
      IF hb_isPointer( xOle )
         ::__hObj := xOle
      ENDIF
   ENDIF

   RETURN ::__hObj

FUNCTION CreateObject( xOle, cIID )
   RETURN TOleAuto():New( xOle, cIID )

FUNCTION GetActiveObject( xOle, cIID )
   LOCAL o := TOleAuto():New( xOle, cIID )

   IF ISNUMBER( xOle )
      xOle := win_N2P( xOle )
   ENDIF

   IF hb_isPointer( xOle )
      o:__hObj := xOle
   ELSEIF ISCHARACTER( xOle )
      xOle := __OleGetActiveObject( xOle, cIID )
      IF ! Empty( xOle )
         o:__hObj := xOle
      ENDIF
   ENDIF

   RETURN o

FUNCTION CreateOLEObject( ... )
   RETURN win_P2N( __OleCreateObject( ... ) )

CREATE CLASS Win32Prn FROM WIN_PRN
ENDCLASS

CREATE CLASS Win32Bmp FROM WIN_BMP
ENDCLASS
