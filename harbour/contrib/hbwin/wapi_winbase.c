/*
 * $Id$
 */

/*
 * Harbour Project source code:
 * Windows API functions (winbase)
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

#define HB_OS_WIN_USED

#include "hbapi.h"
#include "hbwapi.h"

HB_FUNC( WAPI_GETCOMMANDLINE )
{
   char * buffer = HB_TCHAR_CONVFROM( GetCommandLine() );

   {
      /* Convert from OS codepage */
      char * pszFree = NULL;
      const char * pszResult = hb_osDecodeCP( buffer, &pszFree, NULL );

      if( pszFree )
         hb_retc_buffer( pszFree );
      else
         hb_retc( pszResult );
   }

   HB_TCHAR_FREE( buffer );
}

HB_FUNC( WAPI_GETCURRENTPROCESS )
{
   wapi_ret_HANDLE( GetCurrentProcess() );
}

HB_FUNC( WAPI_GETCURRENTPROCESSID )
{
   hb_retnint( GetCurrentProcessId() );
}

HB_FUNC( WAPI_GETCURRENTTHREAD )
{
   wapi_ret_HANDLE( GetCurrentThread() );
}

HB_FUNC( WAPI_SETPROCESSWORKINGSETSIZE )
{
#if ! defined( HB_OS_WIN_CE )
   wapi_ret_L( SetProcessWorkingSetSize(
      wapi_par_HANDLE( 1 ) /* hProcess */,
      ( SIZE_T ) hb_parnint( 2 ) /* dwMinimumWorkingSetSize */,
      ( SIZE_T ) hb_parnint( 3 ) /* dwMaximumWorkingSetSize */ ) );
#else
   wapi_ret_L( FALSE );
#endif
}

HB_FUNC( WAPI_GETLASTERROR )
{
   hb_retnl( ( long ) GetLastError() );
}

HB_FUNC( WAPI_SETLASTERROR )
{
   SetLastError( ( DWORD ) hb_parnl( 1 ) );
}

HB_FUNC( WAPI_SETERRORMODE )
{
   hb_retni( SetErrorMode( ( UINT ) hb_parni( 1 ) ) );
}

HB_FUNC( WAPI_LOADLIBRARY )
{
   hb_retptr( LoadLibraryA( ( LPCSTR ) hb_parcx( 1 ) ) );
}

HB_FUNC( WAPI_FREELIBRARY )
{
   hb_retl( FreeLibrary( ( HMODULE ) hb_parptr( 1 ) ) );
}

HB_FUNC( WAPI_GETPROCADDRESS )
{
#if defined( HB_OS_WIN_CE )
   hb_retptr( NULL );
#else
   hb_retptr( ( void * ) GetProcAddress( ( HMODULE ) hb_parptr( 1 ), HB_ISCHAR( 2 ) ? ( LPCSTR ) hb_parc( 2 ) : ( LPCSTR ) ( HB_PTRDIFF ) hb_parnint( 2 ) ) );
#endif
}

/* HMODULE WINAPI GetModuleHandle( __in_opt LPCTSTR lpModuleName ); */
HB_FUNC( WAPI_GETMODULEHANDLE )
{
   LPTSTR lpModuleName = HB_ISCHAR( 1 ) ? ( LPTSTR ) HB_TCHAR_CONVTO( hb_parc( 1 ) ) : ( LPTSTR ) NULL;

   wapi_ret_HANDLE( GetModuleHandle( lpModuleName ) );

   if( lpModuleName )
      HB_TCHAR_FREE( lpModuleName );
}

/* VOID WINAPI Sleep( __in DWORD dwMilliseconds ); */
HB_FUNC( WAPI_SLEEP )
{
   Sleep( ( DWORD ) hb_parnl( 1 ) );
}

HB_FUNC( WAPI_OUTPUTDEBUGSTRING )
{
   LPTSTR lpOutputString = HB_ISCHAR( 1 ) ? ( LPTSTR ) HB_TCHAR_CONVTO( hb_parc( 1 ) ) : ( LPTSTR ) NULL;

   OutputDebugString( lpOutputString );

   if( lpOutputString )
      HB_TCHAR_FREE( lpOutputString );
}

HB_FUNC( WAPI_FORMATMESSAGE )
{
   LPTSTR lpSource = HB_ISCHAR( 2 ) ? HB_TCHAR_CONVTO( hb_parc( 2 ) ) : NULL;
   ULONG nBufferLen = hb_parclen( 5 );
   LPTSTR lpBuffer = nBufferLen > 0 ? ( LPTSTR ) hb_xgrab( nBufferLen * sizeof( LPTSTR ) ) : NULL;

   hb_retnl( FormatMessage( ( DWORD ) hb_parnldef( 1, FORMAT_MESSAGE_FROM_SYSTEM ) /* dwFlags */,
                            ( LPCVOID ) ( HB_ISCHAR( 2 ) ? lpSource : hb_parptr( 2 ) ),
                            HB_ISNUM( 3 ) ? ( DWORD ) hb_parnl( 3 ) : GetLastError() /* dwMessageId */,
                            ( DWORD ) hb_parnldef( 4, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ) ) /* dwLanguageId */,
                            ( LPTSTR ) lpBuffer,
                            nBufferLen,
                            NULL /* TODO: Add support for this parameter. */ ) );

   if( lpBuffer )
   {
      char * buffer = HB_TCHAR_CONVFROM( lpBuffer );
      hb_storc( buffer, 5 );
      HB_TCHAR_FREE( buffer );

      hb_xfree( lpBuffer );
   }

   if( lpSource )
      HB_TCHAR_FREE( lpSource );
}
