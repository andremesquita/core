/*
 * $Id$
 */

/*
 * Harbour Project source code:
 * Windows communications library
 *
 * Copyright 2005-2009 Alex Strickland <sscc@mweb.co.za>
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
 * anyone as to the status o such modified files, you must delete
 * this exception notice from them.
 *
 * If you write modifications of your own for Harbour, it is your choice
 * whether to permit this exception to apply to your modifications.
 * If you do not wish that, delete this exception notice.
 *
 */

#include "hbwin.ch"

PROCEDURE Main( cPortName )

   LOCAL oWinPort
   LOCAL cString := Space( 32 )
   LOCAL lCTS, lDSR, lRing, lDCD
   LOCAL lCTSHold, lDSRHold, lDCDHold, lXoffHold, lXoffSent, nInQueue, nOutQueue
   LOCAL nResult

   IF Empty( cPortName )
      ? "Usage : winport portname"
      RETURN
   ENDIF

   ? "Attach a scanner now ..."
   ?
   Inkey( 0 )

   oWinPort := win_Com():Init( cPortName, CBR_9600, ODDPARITY, 7, ONESTOPBIT )
   IF ! oWinPort:Open()
      ? "Open() failed :", oWinPort:Error()
   ELSE
      ? "Open() succeeded"
      ?
      IF oWinPort:Status( @lCTS, @lDSR, @lRing, @lDCD )
         ? "Status() succeeded : CTS ", lCTS, ", DSR ", lDSR, ", Ring ", lRing, ", DCD ", lDCD
      ELSE
         ? "Status() failed :", oWinPort:Error()
      ENDIF
      ?
      ? "Testing DTR, configure a scanner to require DTR"
      ? "Scan something... and press enter (shouldn't scan)"
      Inkey( 0 )
      ? "Read() ", oWinPort:Read( @cString, 32 ), Len( cString ), cString
      ?
      IF oWinPort:SetDTR( .T. )
         ? "SetDTR( .T. ) succeeded"
      ELSE
         ? "SetDTR( .T. ) failed :", oWinPort:Error()
      ENDIF
      ? "Scan something... and press enter (read should work)"
      Inkey( 0 )
      ?
      IF oWinPort:QueueStatus( @lCTSHold, @lDSRHold, @lDCDHold, @lXoffHold, @lXoffSent, @nInQueue, @nOutQueue )
         ? "QueueStatus() : CTSHold", lCtsHold, ", DSRHold", lDsrHold, ", DCDHold", lDCDHold, ", XoffHold", lXoffHold, ;
                 ", Xoff Sent ", lXoffSent, ", InQueue ", nInQueue, ", nOutQueue ", nOutQueue
      ELSE
         ? "QueueStatus() failed :", oWinPort:Error()
      ENDIF
      ?
      ? "Read() ", oWinPort:Read( @cString, 32 ), Len( cString ), cString
      ?
      IF oWinPort:QueueStatus( @lCTSHold, @lDSRHold, @lDCDHold, @lXoffHold, @lXoffSent, @nInQueue, @nOutQueue )
         ? "QueueStatus() : CTSHold", lCtsHold, ", DSRHold", lDsrHold, ", DCDHold", lDCDHold, ", XoffHold", lXoffHold, ;
                 ", Xoff Sent ", lXoffSent, ", InQueue ", nInQueue, ", nOutQueue ", nOutQueue
      ELSE
         ? "QueueStatus() failed :", oWinPort:Error()
      ENDIF
      ?
      IF oWinPort:RTSFlow( RTS_CONTROL_HANDSHAKE )
         ? "RTSFlow( RTS_CONTROL_HANDSHAKE ) succeeded"
      ELSE
         ? "RTSFlow( RTS_CONTROL_HANDSHAKE ) failed :", oWinPort:Error()
      ENDIF
      ? oWinPort:DebugDCB(WPDBGFLOW)
      IF oWinPort:SetRTS( .F. )
         ? "SetRTS( .F. ) succeeded (it shouldn't according to docs!)"
      ELSE
         ? "SetRTS( .F. ) failed (it should) :", oWinPort:Error()
      ENDIF
      ?
      IF oWinPort:RTSFlow( RTS_CONTROL_DISABLE )
         ? "RTSFlow( RTS_CONTROL_DISABLE ) succeeded"
      ELSE
         ? "RTSFlow( RTS_CONTROL_DISABLE ) failed :", oWinPort:Error()
      ENDIF
      ? oWinPort:DebugDCB( WPDBGFLOW )
      IF oWinPort:SetRTS( .F. )
         ? "SetRTS( .F. ) succeeded (it should)"
      ELSE
         ? "SetRTS( .F. ) failed :", oWinPort:Error()
      ENDIF
      ?
      ? "Scan something... we'll not read it but purge it, press enter"
      Inkey( 0 )
      IF oWinPort:QueueStatus( @lCTSHold, @lDSRHold, @lDCDHold, @lXoffHold, @lXoffSent, @nInQueue, @nOutQueue )
         ? "QueueStatus() : CTSHold", lCtsHold, ", DSRHold", lDsrHold, ", DCDHold", lDCDHold, ", XoffHold", lXoffHold, ;
                 ", Xoff Sent ", lXoffSent, ", InQueue ", nInQueue, ", nOutQueue ", nOutQueue
      ELSE
         ? "QueueStatus() failed :", oWinPort:Error()
      ENDIF
      IF oWinPort:Purge( .T., .T. )
         ? "Purge() succeeded"
      ELSE
         ? "Purge() failed :", oWinPort:Error()
      ENDIF
      ? "InQueue should be zero"
      IF oWinPort:QueueStatus( @lCTSHold, @lDSRHold, @lDCDHold, @lXoffHold, @lXoffSent, @nInQueue, @nOutQueue )
         ? "QueueStatus() : CTSHold", lCtsHold, ", DSRHold", lDsrHold, ", DCDHold", lDCDHold, ", XoffHold", lXoffHold, ;
                 ", Xoff Sent ", lXoffSent, ", InQueue ", nInQueue, ", nOutQueue ", nOutQueue
      ELSE
         ? "QueueStatus() failed :", oWinPort:Error()
      ENDIF
      ?
      ? "Read ", oWinPort:Read( @cString, 32 ), Len( cString ), cString
      ?
      ? "Close", oWinPort:Close()
   ENDIF

   ?
   ? "This is going to fail, so no device needed"
   Inkey( 0 )

   oWinPort := WinPort():Init( cPortName, CBR_9600, NOPARITY, 99, ONESTOPBIT )
   IF !oWinPort:Open
      ? "Open() failed :", oWinPort:Error()
   ELSE
      ? "Open succeeded"
      ? "Close", oWinPort:Close()
   ENDIF

   ? "Attach a printer now ..."
   ?
   Inkey( 0 )

   oWinPort := WinPort():Init( cPortName, CBR_9600, NOPARITY, 8, ONESTOPBIT )
   IF ! oWinPort:Open
      ? "Open() failed :", oWinPort:Error()
   ELSE
      ? "Open succeeded"
      ?
      ? oWinPort:DebugDCB( WPDBGFLOW )
      ? "Printers will probably have CTS, DSR and DCD high, IF they are off they'll all be low"
      IF oWinPort:Status( @lCTS, @lDSR, @lRing, @lDCD )
         ? "Status() succeeded : CTS ", lCTS, ", DSR ", lDSR, ", Ring ", lRing, ", DCD ", lDCD
      ELSE
         ? "Status() failed :", oWinPort:Error()
      ENDIF
      ?

      ? "With no flow control the write should succeed whether printer is on or off"
      cString := "this is a test string " + Replicate( "012356789", 30 ) + Chr( 13 ) + Chr( 10 )
      IF ( nResult := oWinPort:Write( cString ) ) == Len( cString )
         ? "Write() succeeded"
      ELSE
         ? "Write() failed, returned ", nResult, " expected ", Len( cString )
      ENDIF
      IF oWinPort:QueueStatus( @lCTSHold, @lDSRHold, @lDCDHold, @lXoffHold, @lXoffSent, @nInQueue, @nOutQueue )
         ? "QueueStatus() : CTSHold", lCtsHold, ", DSRHold", lDsrHold, ", DCDHold", lDCDHold, ", XoffHold", lXoffHold, ;
                 ", Xoff Sent ", lXoffSent, ", InQueue ", nInQueue, ", nOutQueue ", nOutQueue
      ELSE
         ? "QueueStatus() failed :", oWinPort:Error()
      ENDIF

      ?
      ? "Switch all handshaking on (normally only hardware and RTS)"
      IF oWinPort:RTSFlow( DTR_CONTROL_HANDSHAKE )
         ? "RTSFlow( RTS_CONTROL_HANDSHAKE ) succeeded"
      ELSE
         ? "RTSFlow( RTS_CONTROL_HANDSHAKE ) failed :", oWinPort:Error()
      ENDIF
      IF oWinPort:DTRFlow( DTR_CONTROL_HANDSHAKE )
         ? "DTRFlow( DTR_CONTROL_HANDSHAKE ) succeeded"
      ELSE
         ? "DTRFlow( DTR_CONTROL_HANDSHAKE ) failed :", oWinPort:Error()
      ENDIF
      IF oWinPort:XonXoffFlow( .T. )
         ? "XonXoffFlow( .T. ) ", oWinPort:XonXoffFlow( .T. )
      ELSE
         ? "XonXoffFlow( .T. ) failed :", oWinPort:Error()
      ENDIF
      ?
      ? oWinPort:DebugDCB( WPDBGFLOW )

      ? "If it's on then no Hold status should be on, IF off then probably CTS and DSR"
      IF oWinPort:QueueStatus( @lCTSHold, @lDSRHold, @lDCDHold, @lXoffHold, @lXoffSent, @nInQueue, @nOutQueue )
         ? "QueueStatus() : CTSHold", lCtsHold, ", DSRHold", lDsrHold, ", DCDHold", lDCDHold, ", XoffHold", lXoffHold, ;
                 ", Xoff Sent ", lXoffSent, ", InQueue ", nInQueue, ", nOutQueue ", nOutQueue
      ELSE
         ? "QueueStatus() failed :", oWinPort:Error()
      ENDIF
      ?
      ? Seconds()
      IF ( nResult := oWinPort:Write( cString ) ) == Len( cString )
         ? "Write() succeeded"
      ELSE
         ? "Write() failed, returned ", nResult, " expected ", Len( cString )
      ENDIF
      ? Seconds()
      ? "Close", oWinPort:Close()
   ENDIF

   RETURN
