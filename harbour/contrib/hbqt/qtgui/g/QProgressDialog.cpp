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
 * Copyright 2009-2010 Pritpal Bedi <pritpal@vouchcac.com>
 *
 * Copyright 2009 Marcos Antonio Gambeta <marcosgambeta at gmail dot com>
 * www - http://harbour-project.org
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

#include "hbqtcore.h"
#include "hbqtgui.h"

/*----------------------------------------------------------------------*/
#if QT_VERSION >= 0x040500
/*----------------------------------------------------------------------*/

#include <QtCore/QPointer>

#include <QtGui/QProgressDialog>


/*
 * QProgressDialog ( QWidget * parent = 0, Qt::WindowFlags f = 0 )
 * QProgressDialog ( const QString & labelText, const QString & cancelButtonText, int minimum, int maximum, QWidget * parent = 0, Qt::WindowFlags f = 0 )
 * ~QProgressDialog ()
 */

typedef struct
{
   QPointer< QProgressDialog > ph;
   bool bNew;
   PHBQT_GC_FUNC func;
   int type;
} HBQT_GC_T_QProgressDialog;

HBQT_GC_FUNC( hbqt_gcRelease_QProgressDialog )
{
   QProgressDialog  * ph = NULL ;
   HBQT_GC_T_QProgressDialog * p = ( HBQT_GC_T_QProgressDialog * ) Cargo;

   if( p && p->bNew && p->ph )
   {
      ph = p->ph;
      if( ph )
      {
         const QMetaObject * m = ( ph )->metaObject();
         if( ( QString ) m->className() != ( QString ) "QObject" )
         {
            HB_TRACE( HB_TR_DEBUG, ( "ph=%p %p YES_rel_QProgressDialog   /.\\   ", (void*) ph, (void*) p->ph ) );
            delete ( p->ph );
            HB_TRACE( HB_TR_DEBUG, ( "ph=%p %p YES_rel_QProgressDialog   \\./   ", (void*) ph, (void*) p->ph ) );
            p->ph = NULL;
         }
         else
         {
            HB_TRACE( HB_TR_DEBUG, ( "ph=%p NO__rel_QProgressDialog          ", ph ) );
            p->ph = NULL;
         }
      }
      else
      {
         HB_TRACE( HB_TR_DEBUG, ( "ph=%p DEL_rel_QProgressDialog    :     Object already deleted!", ph ) );
         p->ph = NULL;
      }
   }
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "ph=%p PTR_rel_QProgressDialog    :    Object not created with new=true", ph ) );
      p->ph = NULL;
   }
}

void * hbqt_gcAllocate_QProgressDialog( void * pObj, bool bNew )
{
   HBQT_GC_T_QProgressDialog * p = ( HBQT_GC_T_QProgressDialog * ) hb_gcAllocate( sizeof( HBQT_GC_T_QProgressDialog ), hbqt_gcFuncs() );

   new( & p->ph ) QPointer< QProgressDialog >( ( QProgressDialog * ) pObj );
   p->bNew = bNew;
   p->func = hbqt_gcRelease_QProgressDialog;
   p->type = HBQT_TYPE_QProgressDialog;

   if( bNew )
   {
      HB_TRACE( HB_TR_DEBUG, ( "ph=%p    _new_QProgressDialog  under p->pq", pObj ) );
   }
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "ph=%p NOT_new_QProgressDialog", pObj ) );
   }
   return p;
}

HB_FUNC( QT_QPROGRESSDIALOG )
{
   QProgressDialog * pObj = NULL;

   pObj = new QProgressDialog( hbqt_par_QWidget( 1 ) ) ;

   hb_retptrGC( hbqt_gcAllocate_QProgressDialog( ( void * ) pObj, true ) );
}

/*
 * bool autoClose () const
 */
HB_FUNC( QT_QPROGRESSDIALOG_AUTOCLOSE )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      hb_retl( ( p )->autoClose() );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_AUTOCLOSE FP=hb_retl( ( p )->autoClose() ); p is NULL" ) );
   }
}

/*
 * bool autoReset () const
 */
HB_FUNC( QT_QPROGRESSDIALOG_AUTORESET )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      hb_retl( ( p )->autoReset() );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_AUTORESET FP=hb_retl( ( p )->autoReset() ); p is NULL" ) );
   }
}

/*
 * QString labelText () const
 */
HB_FUNC( QT_QPROGRESSDIALOG_LABELTEXT )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      hb_retc( ( p )->labelText().toAscii().data() );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_LABELTEXT FP=hb_retc( ( p )->labelText().toAscii().data() ); p is NULL" ) );
   }
}

/*
 * int maximum () const
 */
HB_FUNC( QT_QPROGRESSDIALOG_MAXIMUM )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      hb_retni( ( p )->maximum() );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_MAXIMUM FP=hb_retni( ( p )->maximum() ); p is NULL" ) );
   }
}

/*
 * int minimum () const
 */
HB_FUNC( QT_QPROGRESSDIALOG_MINIMUM )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      hb_retni( ( p )->minimum() );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_MINIMUM FP=hb_retni( ( p )->minimum() ); p is NULL" ) );
   }
}

/*
 * int minimumDuration () const
 */
HB_FUNC( QT_QPROGRESSDIALOG_MINIMUMDURATION )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      hb_retni( ( p )->minimumDuration() );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_MINIMUMDURATION FP=hb_retni( ( p )->minimumDuration() ); p is NULL" ) );
   }
}

/*
 * void open ( QObject * receiver, const char * member )
 */
HB_FUNC( QT_QPROGRESSDIALOG_OPEN )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      ( p )->open( hbqt_par_QObject( 2 ), hbqt_par_char( 3 ) );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_OPEN FP=( p )->open( hbqt_par_QObject( 2 ), hbqt_par_char( 3 ) ); p is NULL" ) );
   }
}

/*
 * void setAutoClose ( bool close )
 */
HB_FUNC( QT_QPROGRESSDIALOG_SETAUTOCLOSE )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      ( p )->setAutoClose( hb_parl( 2 ) );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_SETAUTOCLOSE FP=( p )->setAutoClose( hb_parl( 2 ) ); p is NULL" ) );
   }
}

/*
 * void setAutoReset ( bool reset )
 */
HB_FUNC( QT_QPROGRESSDIALOG_SETAUTORESET )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      ( p )->setAutoReset( hb_parl( 2 ) );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_SETAUTORESET FP=( p )->setAutoReset( hb_parl( 2 ) ); p is NULL" ) );
   }
}

/*
 * void setBar ( QProgressBar * bar )
 */
HB_FUNC( QT_QPROGRESSDIALOG_SETBAR )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      ( p )->setBar( hbqt_par_QProgressBar( 2 ) );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_SETBAR FP=( p )->setBar( hbqt_par_QProgressBar( 2 ) ); p is NULL" ) );
   }
}

/*
 * void setCancelButton ( QPushButton * cancelButton )
 */
HB_FUNC( QT_QPROGRESSDIALOG_SETCANCELBUTTON )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      ( p )->setCancelButton( hbqt_par_QPushButton( 2 ) );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_SETCANCELBUTTON FP=( p )->setCancelButton( hbqt_par_QPushButton( 2 ) ); p is NULL" ) );
   }
}

/*
 * void setLabel ( QLabel * label )
 */
HB_FUNC( QT_QPROGRESSDIALOG_SETLABEL )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      ( p )->setLabel( hbqt_par_QLabel( 2 ) );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_SETLABEL FP=( p )->setLabel( hbqt_par_QLabel( 2 ) ); p is NULL" ) );
   }
}

/*
 * virtual QSize sizeHint () const
 */
HB_FUNC( QT_QPROGRESSDIALOG_SIZEHINT )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      hb_retptrGC( hbqt_gcAllocate_QSize( new QSize( ( p )->sizeHint() ), true ) );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_SIZEHINT FP=hb_retptrGC( hbqt_gcAllocate_QSize( new QSize( ( p )->sizeHint() ), true ) ); p is NULL" ) );
   }
}

/*
 * int value () const
 */
HB_FUNC( QT_QPROGRESSDIALOG_VALUE )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      hb_retni( ( p )->value() );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_VALUE FP=hb_retni( ( p )->value() ); p is NULL" ) );
   }
}

/*
 * bool wasCanceled () const
 */
HB_FUNC( QT_QPROGRESSDIALOG_WASCANCELED )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      hb_retl( ( p )->wasCanceled() );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_WASCANCELED FP=hb_retl( ( p )->wasCanceled() ); p is NULL" ) );
   }
}

/*
 * void cancel ()
 */
HB_FUNC( QT_QPROGRESSDIALOG_CANCEL )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      ( p )->cancel();
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_CANCEL FP=( p )->cancel(); p is NULL" ) );
   }
}

/*
 * void reset ()
 */
HB_FUNC( QT_QPROGRESSDIALOG_RESET )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      ( p )->reset();
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_RESET FP=( p )->reset(); p is NULL" ) );
   }
}

/*
 * void setCancelButtonText ( const QString & cancelButtonText )
 */
HB_FUNC( QT_QPROGRESSDIALOG_SETCANCELBUTTONTEXT )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      ( p )->setCancelButtonText( QProgressDialog::tr( hb_parc( 2 ) ) );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_SETCANCELBUTTONTEXT FP=( p )->setCancelButtonText( QProgressDialog::tr( hb_parc( 2 ) ) ); p is NULL" ) );
   }
}

/*
 * void setLabelText ( const QString & text )
 */
HB_FUNC( QT_QPROGRESSDIALOG_SETLABELTEXT )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      ( p )->setLabelText( QProgressDialog::tr( hb_parc( 2 ) ) );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_SETLABELTEXT FP=( p )->setLabelText( QProgressDialog::tr( hb_parc( 2 ) ) ); p is NULL" ) );
   }
}

/*
 * void setMaximum ( int maximum )
 */
HB_FUNC( QT_QPROGRESSDIALOG_SETMAXIMUM )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      ( p )->setMaximum( hb_parni( 2 ) );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_SETMAXIMUM FP=( p )->setMaximum( hb_parni( 2 ) ); p is NULL" ) );
   }
}

/*
 * void setMinimum ( int minimum )
 */
HB_FUNC( QT_QPROGRESSDIALOG_SETMINIMUM )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      ( p )->setMinimum( hb_parni( 2 ) );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_SETMINIMUM FP=( p )->setMinimum( hb_parni( 2 ) ); p is NULL" ) );
   }
}

/*
 * void setMinimumDuration ( int ms )
 */
HB_FUNC( QT_QPROGRESSDIALOG_SETMINIMUMDURATION )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      ( p )->setMinimumDuration( hb_parni( 2 ) );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_SETMINIMUMDURATION FP=( p )->setMinimumDuration( hb_parni( 2 ) ); p is NULL" ) );
   }
}

/*
 * void setRange ( int minimum, int maximum )
 */
HB_FUNC( QT_QPROGRESSDIALOG_SETRANGE )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      ( p )->setRange( hb_parni( 2 ), hb_parni( 3 ) );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_SETRANGE FP=( p )->setRange( hb_parni( 2 ), hb_parni( 3 ) ); p is NULL" ) );
   }
}

/*
 * void setValue ( int progress )
 */
HB_FUNC( QT_QPROGRESSDIALOG_SETVALUE )
{
   QProgressDialog * p = hbqt_par_QProgressDialog( 1 );
   if( p )
      ( p )->setValue( hb_parni( 2 ) );
   else
   {
      HB_TRACE( HB_TR_DEBUG, ( "............................... F=QT_QPROGRESSDIALOG_SETVALUE FP=( p )->setValue( hb_parni( 2 ) ); p is NULL" ) );
   }
}


/*----------------------------------------------------------------------*/
#endif             /* #if QT_VERSION >= 0x040500 */
/*----------------------------------------------------------------------*/