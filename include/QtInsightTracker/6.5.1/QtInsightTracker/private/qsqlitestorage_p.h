// Copyright (C) 2022 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial

#ifndef QSQLITESTORAGE_H
#define QSQLITESTORAGE_H

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

#ifdef QT_SQL_LIB

#include <QtInsightTracker/qtinsighttracker_global.h>
#include <QtInsightTracker/private/qinsightstorage_p.h>
#include <QtSql/QSqlDatabase>

QT_BEGIN_NAMESPACE

class Q_INSIGHTTRACKER_EXPORT QSQLiteStorage : public QInsightStorage
{
public:
    explicit QSQLiteStorage(const QString &name = {}, int maxRecords = 0);

    bool open() override;
    bool add(const QByteArray &payload) override;
    bool remove(quint64 id) override;
    bool remove(const QSet<quint64> &ids) override;
    bool removeAll() override;
    QList<EventData> get(qsizetype n) override;

    ~QSQLiteStorage() override;

public:
    QString m_name;
    int m_maxRecords;
    QSqlDatabase m_db;
};

QT_END_NAMESPACE

#endif // QT_SQL_LIB

#endif // QSQLITESTORAGE_H
