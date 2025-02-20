// Copyright (C) 2022 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial

#ifndef QINSIGHTREPORTER_H
#define QINSIGHTREPORTER_H

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

#include <QtInsightTracker/QInsightConfiguration>
#include <QtInsightTracker/private/qinsightstorage_p.h>
#include <QtCore/QObject>
#include <QtCore/QTimer>
#include <QtCore/QUrl>

QT_BEGIN_NAMESPACE

class QNetworkAccessManager;
class QSettings;

class Q_INSIGHTTRACKER_EXPORT QInsightReporter : public QObject
{
    Q_OBJECT
public:
    QInsightReporter();

    void init(QInsightConfiguration *config);

    void trackDeviceAndAppInfo();

    using ContextData = std::pair<QString, double>;
    void trackScreenView(const QString &name,
                         const std::optional<ContextData> &context = std::nullopt);
    void trackClickEvent(const QString &name, const QString &category, int x, int y,
                         const std::optional<ContextData> &context = std::nullopt);

    void startNewSession();
    void clearCache();
    ~QInsightReporter() override;

private:
    QByteArray createUnstructuredEvent(const QJsonArray &contextArray);
    void startSyncTimer();

    void addEvent(const QByteArray &payload);
    void sync();
    void sendToBackend(const QSet<quint64> &ids, const QByteArray &payload);

    const QString m_appName;
    const QString m_userId;
    QString m_sessionId;
    QUrl m_url;
    QNetworkAccessManager *m_qnam = nullptr;
    QInsightConfiguration *m_config = nullptr;
    QSettings *m_settings = nullptr;
    std::unique_ptr<QInsightStorage> m_storage = nullptr;
    QString m_previousScreen;
    QTimer m_syncTimer;
};

QT_END_NAMESPACE

#endif // QINSIGHTREPORTER_H
