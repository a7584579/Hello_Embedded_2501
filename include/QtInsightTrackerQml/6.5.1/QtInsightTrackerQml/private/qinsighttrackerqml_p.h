// Copyright (C) 2022 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial

#ifndef INSIGHTTRACKERQML_P_H
#define INSIGHTTRACKERQML_P_H

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
#include <QtInsightTracker/QInsightTracker>
#include <QtInsightTrackerQml/private/qinsightcategory_p.h>
#include <QtInsightTrackerQml/private/qtinsighttrackerqml-config_p.h>
#include <QtInsightTrackerQml/qtinsighttrackerqmlexports.h>
#include <QtCore/QtGlobal>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlInfo>

#if QT_CONFIG(presignal)
#include <QtQml/private/qqmlengine_p.h>
#include <QtQuickTemplates2/private/qquickabstractbutton_p.h>
#endif

QT_BEGIN_NAMESPACE

struct Q_INSIGHTTRACKERQML_EXPORT QInsightConfigurationForeign
{
    Q_GADGET
    QML_FOREIGN(QInsightConfiguration)
    QML_NAMED_ELEMENT(InsightConfiguration)
    QML_ADDED_IN_VERSION(1, 0)
};

class Q_INSIGHTTRACKERQML_EXPORT QInsightTrackerQml : public QObject
#if QT_CONFIG(presignal)
 , public QQmlAnalyticsInterface
#endif
{
    Q_OBJECT
    QML_NAMED_ELEMENT(InsightTracker)
    QML_ADDED_IN_VERSION(1, 0)
    QML_SINGLETON
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged)

public:
    QInsightTrackerQml();

    Q_INVOKABLE void sendScreenView(const QString &name) const;
    Q_INVOKABLE void sendScreenView(const QString &name,
                                    const QString &contextKey, double contextValue) const;

    Q_INVOKABLE void sendClickEvent(const QString &name, const QString &category, int x, int y) const;
    Q_INVOKABLE void sendClickEvent(const QString &name, const QString &category, int x, int y,
                                    const QString &contextKey, double contextValue) const;

    Q_INVOKABLE void clearCache();
    Q_INVOKABLE void startNewSession();
    Q_INVOKABLE bool isEnabled() const;
    Q_INVOKABLE void setEnabled(bool enabled);

#if QT_CONFIG(presignal)
    bool shouldLog(const QObject *object, QMetaMethod method) override;
    void log(const QObject *object, QMetaMethod method, QVariantList arguments) override;
#endif

Q_SIGNALS:
    void enabledChanged(bool enabled);
};

QT_END_NAMESPACE

#endif // INSIGHTTRACKERQML_P_H
