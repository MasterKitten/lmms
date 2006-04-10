/*
 * midi_tab_widget.h - tab-widget in channel-track-window for setting up
 *                     MIDI-related stuff
 *
 * Copyright (c) 2005-2006 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 * 
 * This file is part of Linux MultiMedia Studio - http://lmms.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */


#ifndef _MIDI_TAB_WIDGET_H
#define _MIDI_TAB_WIDGET_H

#include "qt3support.h"

#ifdef QT4

#include <QtGui/QWidget>

#else

#include <qwidget.h>

#endif

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "journalling_object.h"
#include "engine.h"


class QMenu;
class QPixmap;
class QAction;

class instrumentTrack;
class tabWidget;
class ledCheckBox;
class lcdSpinBox;
class midiPort;


class midiTabWidget : public QWidget, public journallingObject
{
	Q_OBJECT
public:
	midiTabWidget( instrumentTrack * _channel_track, midiPort * _port );
	virtual ~midiTabWidget();


	virtual void FASTCALL saveSettings( QDomDocument & _doc,
							QDomElement & _parent );
	virtual void FASTCALL loadSettings( const QDomElement & _this );
	inline virtual QString nodeName( void ) const
	{
		return( "midi" );
	}


public slots:
	void midiPortModeToggled( bool = FALSE );


protected slots:
	void inputChannelChanged( int );
	void outputChannelChanged( int );
	void defaultVelInChanged( bool );
	void defaultVelOutChanged( bool );
	void readablePortsChanged( void );
	void writeablePortsChanged( void );
	void activatedReadablePort( QAction * _item );
	void activatedWriteablePort( QAction * _item );
	// Qt3-version
	void activatedReadablePort( int _id );
	void activatedWriteablePort( int _id );

private:
	instrumentTrack * m_instrumentTrack;
	midiPort * m_midiPort;

	tabWidget * m_setupTabWidget;
	lcdSpinBox * m_inputChannelSpinBox;
	lcdSpinBox * m_outputChannelSpinBox;
	ledCheckBox * m_receiveCheckBox;
	ledCheckBox * m_sendCheckBox;
	ledCheckBox * m_defaultVelocityInCheckBox;
	ledCheckBox * m_defaultVelocityOutCheckBox;

	QMenu * m_readablePorts;
	QMenu * m_writeablePorts;

	friend class instrumentTrack;

} ;


#endif
