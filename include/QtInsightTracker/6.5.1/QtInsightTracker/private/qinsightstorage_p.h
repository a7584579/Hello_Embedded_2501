// Copyright (C) 2022 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial

#ifndef QINSIGHTSTORAGE_H
#define QINSIGHTSTORAGE_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtInsightTracker/qtinsighttracker_global.h>
#include <QtCore/QLoggingCategory>
#include <QtCore/QObject>

Q_DECLARE_LOGGING_CATEGORY(lcInsightStorage)

QT_BEGIN_NAMESPACE

class Q_INSIGHTTRACKER_EXPORT QInsightStorage : public QObject
{
    Q_OBJECT
public:
    struct EventData
    {
        EventData(quint64 i, const QByteArray &p) : id(i), payload(p) {}

        quint64 id;
        QByteArray payload;
    };

    QInsightStorage() = default;
    virtual bool open() = 0;
    virtual bool add(const QByteArray &payload) = 0;
    virtual bool remove(quint64 id) = 0;
    virtual bool remove(const QSet<quint64> &ids) = 0;
    virtual bool removeAll() = 0;
    virtual QList<EventData> get(qsizetype n) = 0;

    virtual ~QInsightStorage() = default;
};

QT_END_NAMESPACE

#endif // QINSIGHTSTORAGE_H
