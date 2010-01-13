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

/*
 *  enum Shadow { Plain, Raised, Sunken }
 *  enum Shape { NoFrame, Box, Panel, StyledPanel, ..., WinPanel }
 *  enum StyleMask { Shadow_Mask, Shape_Mask }
 */

#include <QtCore/QPointer>

#include <QtGui/QFrame>


/*
 * QFrame ( QWidget * parent = 0, Qt::WindowFlags f = 0 )
 * ~QFrame ()
 */

typedef struct
{
  void * ph;
  QT_G_FUNC_PTR func;
  QPointer< QFrame > pq;
} QGC_POINTER_QFrame;

QT_G_FUNC( hbqt_gcRelease_QFrame )
{
   QGC_POINTER_QFrame * p = ( QGC_POINTER_QFrame * ) Cargo;

   HB_TRACE( HB_TR_DEBUG, ( "hbqt_gcRelease_QFrame                       p=%p", p));
   HB_TRACE( HB_TR_DEBUG, ( "hbqt_gcRelease_QFrame                      ph=%p pq=%p", p->ph, (void *)(p->pq)));

   if( p && p->ph && p->pq )
   {
      const QMetaObject * m = ( ( QObject * ) p->ph )->metaObject();
      if( ( QString ) m->className() != ( QString ) "QObject" )
      {
         switch( hbqt_get_object_release_method() )
         {
         case HBQT_RELEASE_WITH_DELETE:
            delete ( ( QFrame * ) p->ph );
            break;
         case HBQT_RELEASE_WITH_DESTRUTOR:
            ( ( QFrame * ) p->ph )->~QFrame();
            break;
         case HBQT_RELEASE_WITH_DELETE_LATER:
            ( ( QFrame * ) p->ph )->deleteLater();
            break;
         }
         p->ph = NULL;
         HB_TRACE( HB_TR_DEBUG, ( "hbqt_gcRelease_QFrame                      Object deleted! %i B %i KB", ( int ) hb_xquery( 1001 ), hbqt_getmemused() ) );
      }
      else
      {
         HB_TRACE( HB_TR_DEBUG, ( "NO hbqt_gcRelease_QFrame                      Object Name Missing!" ) );
      }
   }
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "DEL hbqt_gcRelease_QFrame                      Object Already deleted!" ) );
   }
}

void * hbqt_gcAllocate_QFrame( void * pObj )
{
   QGC_POINTER_QFrame * p = ( QGC_POINTER_QFrame * ) hb_gcAllocate( sizeof( QGC_POINTER_QFrame ), hbqt_gcFuncs() );

   p->ph = pObj;
   p->func = hbqt_gcRelease_QFrame;
   new( & p->pq ) QPointer< QFrame >( ( QFrame * ) pObj );
   HB_TRACE( HB_TR_DEBUG, ( "          new_QFrame                      %i B %i KB", ( int ) hb_xquery( 1001 ), hbqt_getmemused() ) );
   return p;
}

HB_FUNC( QT_QFRAME )
{
   void * pObj = NULL;

   pObj = new QFrame( hbqt_par_QWidget( 1 ), ( Qt::WindowFlags ) hb_parni( 2 ) ) ;

   hb_retptrGC( hbqt_gcAllocate_QFrame( pObj ) );
}
/*
 * QRect frameRect () const
 */
HB_FUNC( QT_QFRAME_FRAMERECT )
{
   hb_retptrGC( hbqt_gcAllocate_QRect( new QRect( hbqt_par_QFrame( 1 )->frameRect() ) ) );
}

/*
 * Shadow frameShadow () const
 */
HB_FUNC( QT_QFRAME_FRAMESHADOW )
{
   hb_retni( ( QFrame::Shadow ) hbqt_par_QFrame( 1 )->frameShadow() );
}

/*
 * Shape frameShape () const
 */
HB_FUNC( QT_QFRAME_FRAMESHAPE )
{
   hb_retni( ( QFrame::Shape ) hbqt_par_QFrame( 1 )->frameShape() );
}

/*
 * int frameStyle () const
 */
HB_FUNC( QT_QFRAME_FRAMESTYLE )
{
   hb_retni( hbqt_par_QFrame( 1 )->frameStyle() );
}

/*
 * int frameWidth () const
 */
HB_FUNC( QT_QFRAME_FRAMEWIDTH )
{
   hb_retni( hbqt_par_QFrame( 1 )->frameWidth() );
}

/*
 * int lineWidth () const
 */
HB_FUNC( QT_QFRAME_LINEWIDTH )
{
   hb_retni( hbqt_par_QFrame( 1 )->lineWidth() );
}

/*
 * int midLineWidth () const
 */
HB_FUNC( QT_QFRAME_MIDLINEWIDTH )
{
   hb_retni( hbqt_par_QFrame( 1 )->midLineWidth() );
}

/*
 * void setFrameRect ( const QRect & )
 */
HB_FUNC( QT_QFRAME_SETFRAMERECT )
{
   hbqt_par_QFrame( 1 )->setFrameRect( *hbqt_par_QRect( 2 ) );
}

/*
 * void setFrameShadow ( Shadow )
 */
HB_FUNC( QT_QFRAME_SETFRAMESHADOW )
{
   hbqt_par_QFrame( 1 )->setFrameShadow( ( QFrame::Shadow ) hb_parni( 2 ) );
}

/*
 * void setFrameShape ( Shape )
 */
HB_FUNC( QT_QFRAME_SETFRAMESHAPE )
{
   hbqt_par_QFrame( 1 )->setFrameShape( ( QFrame::Shape ) hb_parni( 2 ) );
}

/*
 * void setFrameStyle ( int style )
 */
HB_FUNC( QT_QFRAME_SETFRAMESTYLE )
{
   hbqt_par_QFrame( 1 )->setFrameStyle( hb_parni( 2 ) );
}

/*
 * void setLineWidth ( int )
 */
HB_FUNC( QT_QFRAME_SETLINEWIDTH )
{
   hbqt_par_QFrame( 1 )->setLineWidth( hb_parni( 2 ) );
}

/*
 * void setMidLineWidth ( int )
 */
HB_FUNC( QT_QFRAME_SETMIDLINEWIDTH )
{
   hbqt_par_QFrame( 1 )->setMidLineWidth( hb_parni( 2 ) );
}


/*----------------------------------------------------------------------*/
#endif             /* #if QT_VERSION >= 0x040500 */
/*----------------------------------------------------------------------*/
