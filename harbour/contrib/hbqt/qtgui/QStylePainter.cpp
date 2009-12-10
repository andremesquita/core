/*
 * $Id$
 */

/* -------------------------------------------------------------------- */
/* WARNING: Automatically generated source file. DO NOT EDIT!           */
/*          Instead, edit corresponding .qth file,                      */
/*          or the generator tool itself, and run regenarate.           */
/* -------------------------------------------------------------------- */

/*
 * Harbour Project source code:
 * QT wrapper main header
 *
 * Copyright 2009 Pritpal Bedi <pritpal@vouchcac.com>
 *
 * Copyright 2009 Marcos Antonio Gambeta <marcosgambeta at gmail dot com>
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
/*----------------------------------------------------------------------*/

#include "hbapi.h"
#include "../hbqt.h"

/*----------------------------------------------------------------------*/
#if QT_VERSION >= 0x040500
/*----------------------------------------------------------------------*/

#include <QtCore/QPointer>

#include <QtGui/QStylePainter>


/*
 * QStylePainter ()
 * QStylePainter ( QWidget * widget )
 * QStylePainter ( QPaintDevice * pd, QWidget * widget )
 */

QT_G_FUNC( release_QStylePainter )
{
   QGC_POINTER * p = ( QGC_POINTER * ) Cargo;

   HB_TRACE( HB_TR_DEBUG, ( "release_QStylePainter                p=%p", p ) );
   HB_TRACE( HB_TR_DEBUG, ( "release_QStylePainter               ph=%p", p->ph ) );

   if( p && p->ph )
   {
      delete ( ( QStylePainter * ) p->ph );
      p->ph = NULL;
      HB_TRACE( HB_TR_DEBUG, ( "YES release_QStylePainter               Object deleted! %i B %i KB", ( int ) hb_xquery( 1001 ), hbqt_getmemused() ) );
   }
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "DEL release_QStylePainter               Object Allready deleted!" ) );
   }
}

void * gcAllocate_QStylePainter( void * pObj )
{
   QGC_POINTER * p = ( QGC_POINTER * ) hb_gcAllocate( sizeof( QGC_POINTER ), gcFuncs() );

   p->ph = pObj;
   p->func = release_QStylePainter;
   HB_TRACE( HB_TR_DEBUG, ( "          new_QStylePainter               %i B %i KB", ( int ) hb_xquery( 1001 ), hbqt_getmemused() ) );
   return( p );
}

HB_FUNC( QT_QSTYLEPAINTER )
{
   void * pObj = NULL;

   pObj = ( QStylePainter* ) new QStylePainter() ;

   hb_retptrGC( gcAllocate_QStylePainter( pObj ) );
}
/*
 * bool begin ( QWidget * widget )
 */
HB_FUNC( QT_QSTYLEPAINTER_BEGIN )
{
   hb_retl( hbqt_par_QStylePainter( 1 )->begin( hbqt_par_QWidget( 2 ) ) );
}

/*
 * bool begin ( QPaintDevice * pd, QWidget * widget )
 */
HB_FUNC( QT_QSTYLEPAINTER_BEGIN_1 )
{
   hb_retl( hbqt_par_QStylePainter( 1 )->begin( hbqt_par_QPaintDevice( 2 ), hbqt_par_QWidget( 3 ) ) );
}

/*
 * void drawComplexControl ( QStyle::ComplexControl cc, const QStyleOptionComplex & option )
 */
HB_FUNC( QT_QSTYLEPAINTER_DRAWCOMPLEXCONTROL )
{
   hbqt_par_QStylePainter( 1 )->drawComplexControl( ( QStyle::ComplexControl ) hb_parni( 2 ), *hbqt_par_QStyleOptionComplex( 3 ) );
}

/*
 * void drawControl ( QStyle::ControlElement ce, const QStyleOption & option )
 */
HB_FUNC( QT_QSTYLEPAINTER_DRAWCONTROL )
{
   hbqt_par_QStylePainter( 1 )->drawControl( ( QStyle::ControlElement ) hb_parni( 2 ), *hbqt_par_QStyleOption( 3 ) );
}

/*
 * void drawItemPixmap ( const QRect & rect, int flags, const QPixmap & pixmap )
 */
HB_FUNC( QT_QSTYLEPAINTER_DRAWITEMPIXMAP )
{
   hbqt_par_QStylePainter( 1 )->drawItemPixmap( *hbqt_par_QRect( 2 ), hb_parni( 3 ), *hbqt_par_QPixmap( 4 ) );
}

/*
 * void drawItemText ( const QRect & rect, int flags, const QPalette & pal, bool enabled, const QString & text, QPalette::ColorRole textRole = QPalette::NoRole )
 */
HB_FUNC( QT_QSTYLEPAINTER_DRAWITEMTEXT )
{
   hbqt_par_QStylePainter( 1 )->drawItemText( *hbqt_par_QRect( 2 ), hb_parni( 3 ), *hbqt_par_QPalette( 4 ), hb_parl( 5 ), hbqt_par_QString( 6 ), ( HB_ISNUM( 7 ) ? ( QPalette::ColorRole ) hb_parni( 7 ) : ( QPalette::ColorRole ) QPalette::NoRole ) );
}

/*
 * void drawPrimitive ( QStyle::PrimitiveElement pe, const QStyleOption & option )
 */
HB_FUNC( QT_QSTYLEPAINTER_DRAWPRIMITIVE )
{
   hbqt_par_QStylePainter( 1 )->drawPrimitive( ( QStyle::PrimitiveElement ) hb_parni( 2 ), *hbqt_par_QStyleOption( 3 ) );
}

/*
 * QStyle * style () const
 */
HB_FUNC( QT_QSTYLEPAINTER_STYLE )
{
   hb_retptr( ( QStyle* ) hbqt_par_QStylePainter( 1 )->style() );
}


/*----------------------------------------------------------------------*/
#endif             /* #if QT_VERSION >= 0x040500 */
/*----------------------------------------------------------------------*/
