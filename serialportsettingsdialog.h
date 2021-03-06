/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Copyright (C) 2014 Miklos Marton <martonmiklosqdev@gmail.com>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QSettings>
#include "qtserialportwidgets_global.h"

QT_USE_NAMESPACE

QT_BEGIN_NAMESPACE

namespace Ui {
class SerialPortSettingsDialog;
}

class QIntValidator;

QT_END_NAMESPACE

class QTSERIALPORTWIDGETS_EXPORT SerialPortSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    struct Settings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
    };

    explicit SerialPortSettingsDialog(QWidget *parent = nullptr);
    ~SerialPortSettingsDialog();
    void addWidget(QWidget *widget);
    Settings settings() const;

    void loadSettingsFromPort(QSerialPort *port);
    void applySettingsToPort(QSerialPort *port);

    void loadSettings(QSettings & settings);
    void saveSettings(QSettings & settings);

    void setPort(QSerialPort *port);

private slots:
    void on_applyButton_clicked();
    void on_serialPortInfoListBox_activated(int index);

private:
    void updateSettings();
    Ui::SerialPortSettingsDialog *ui;
    int widgetCount;
    Settings currentSettings;
    QSerialPort *m_port;
    void applyPortSettings(QSerialPort *port);

signals:
    void portSettingsApplied();
};

#endif // SETTINGSDIALOG_H
