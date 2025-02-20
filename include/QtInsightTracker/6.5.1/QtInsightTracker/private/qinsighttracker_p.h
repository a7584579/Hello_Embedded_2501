// Copyright (C) 2022 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial

#ifndef QINSIGHTTRACKER_P_H
#define QINSIGHTTRACKER_P_H

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
#include <QtCore/QObject>

QT_BEGIN_NAMESPACE

class QInsightReporter;

class Q_INSIGHTTRACKER_EXPORT InsightTrackerImpl
{
    Q_DISABLE_COPY(InsightTrackerImpl)

public:
    static InsightTrackerImpl &instance()
    {
        static InsightTrackerImpl instance;
        return instance;
    }

    virtual ~InsightTrackerImpl();

    // TODO: make this a struct?
    using ContextData = std::pair<QString, double>;

    void sendScreenView(const QString &name,
                        const std::optional<ContextData> &context = std::nullopt);
    void sendClickEvent(const QString &name, const QString &category, int x, int y,
                        const std::optional<ContextData> &context = std::nullopt);
    void startNewSession();
    void clearCache();
    bool isEnabled() const;
    void setEnabled(bool enabled);
    QInsightConfiguration *configuration();

private:
    InsightTrackerImpl();
    void init();
    void deinit();

    QInsightConfiguration m_config;
    QInsightReporter *m_reporter = nullptr;
    QThread *m_workerThread = nullptr;
    bool m_initialized = false;
};

QT_END_NAMESPACE

#endif // QINSIGHTTRACKER_P_H
