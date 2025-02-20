/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Safe Renderer module
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
**
**
**
**
**
**
**
****************************************************************************/
#ifndef QSAFEMESSAGESENDER_H
#define QSAFEMESSAGESENDER_H

#include <qqml.h>
#include <QObject>
#include <QPointF>

QT_BEGIN_NAMESPACE

class QSafeMessageInterface;

class QSafeMessageSender : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
public:
    explicit QSafeMessageSender(QObject *parent = nullptr);
    virtual ~QSafeMessageSender();
    Q_INVOKABLE void sendHeartBeat(const int timeout);
    Q_INVOKABLE void changeItemVisiblity(const QString& id, bool enable);
    Q_INVOKABLE void moveItem(const QString& itemId, const QPointF &pos);
    Q_INVOKABLE void changeLayout(const QString& layoutId);
    Q_INVOKABLE void setText(const QString& itemId, const QString &text);
    Q_INVOKABLE void setColor(const QString& itemId, const QString &colorStr);
    Q_INVOKABLE void changeState(const QString& id, const QString &state);
public Q_SLOTS:

private:
    QSafeMessageInterface *m_messageSender;
};

QT_END_NAMESPACE

#endif // QSAFEMESSAGESENDER_H
