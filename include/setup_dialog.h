/*
 * setup_dialog.h - dialog for setting up LMMS
 *
 * Copyright (c) 2005-2008 Tobias Doerffel <tobydox/at/users.sourceforge.net>
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
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */


#ifndef _SETUP_DIALOG_H
#define _SETUP_DIALOG_H

#include <QtGui/QDialog>
#include <QtCore/QMap>

#include "audio_device.h"
#include "midi_client.h"


class QComboBox;
class QLabel;
class QLineEdit;
class QSlider;

class tabBar;


class setupDialog : public QDialog
{
	Q_OBJECT
public:
	enum ConfigTabs
	{
		GeneralSettings,
		DirectorySettings,
		PerformanceSettings,
		AudioSettings,
		MidiSettings
	} ;

	setupDialog( ConfigTabs _tab_to_open = GeneralSettings );
	virtual ~setupDialog();


protected slots:
	virtual void accept( void );


private slots:
	// general settings widget
	void setBufferSize( int _value );
	void resetBufSize( void );
	void displayBufSizeHelp( void );

	// directory settings widget
	void setWorkingDir( const QString & _wd );
	void setVSTDir( const QString & _vd );
	void setArtworkDir( const QString & _ad );
	void setFLDir( const QString & _fd );
	void setLADSPADir( const QString & _fd );
	void setSTKDir( const QString & _fd );
	
	// audio settings widget
	void audioInterfaceChanged( const QString & _driver );
	void displayAudioHelp( void );

	// MIDI settings widget
	void midiInterfaceChanged( const QString & _driver );
	void displayMIDIHelp( void );


	void toggleToolTips( bool _enabled );
	void toggleKnobUsability( bool _classical );
	void toggleMdiWindows( bool _enabled );
	void toggleWizard( bool _enabled );
	void toggleWarnAfterSetup( bool _enabled );
	void toggleDisplaydBV( bool _enabled );
	void toggleMMPZ( bool _enabled );
	void toggleHQAudioDev( bool _enabled );

	void openWorkingDir( void );
	void openVSTDir( void );
	void openArtworkDir( void );
	void openFLDir( void );
	void openLADSPADir( void );
	void openSTKDir( void );

	void toggleDisableChActInd( bool _disabled );
	void toggleManualChPiano( bool _enabled );


private:
	tabBar * m_tabBar;

	QSlider * m_bufSizeSlider;
	QLabel * m_bufSizeLbl;
	int m_bufferSize;

	bool m_toolTips;
	bool m_classicalKnobUsability;
	bool m_MDI;
	bool m_wizard;
	bool m_warnAfterSetup;
	bool m_displaydBV;
	bool m_MMPZ;
	bool m_hqAudioDev;


	QLineEdit * m_wdLineEdit;
	QLineEdit * m_vdLineEdit;
	QLineEdit * m_adLineEdit;
	QLineEdit * m_fdLineEdit;
	QLineEdit * m_ladLineEdit;
#ifdef HAVE_STK_H
	QLineEdit * m_stkLineEdit;
#endif

	QString m_workingDir;
	QString m_vstDir;
	QString m_artworkDir;
	QString m_flDir;
	QString m_ladDir;
#ifdef HAVE_STK_H
	QString m_stkDir;
#endif

	bool m_disableChActInd;
	bool m_manualChPiano;

	typedef QMap<QString, audioDevice::setupWidget *> aswMap;
	typedef QMap<QString, midiClient::setupWidget *> mswMap;
	typedef QMap<QString, QString> trMap;

	QComboBox * m_audioInterfaces;
	aswMap m_audioIfaceSetupWidgets;
	trMap m_audioIfaceNames;

	QComboBox * m_midiInterfaces;
	mswMap m_midiIfaceSetupWidgets;
	trMap m_midiIfaceNames;


} ;


#endif
