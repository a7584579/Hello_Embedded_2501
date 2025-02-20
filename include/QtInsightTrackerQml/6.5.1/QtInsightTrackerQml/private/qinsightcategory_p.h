// Copyright (C) 2022 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial

#ifndef QINSIGHTCATEGORY_H
#define QINSIGHTCATEGORY_H

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

#include <QtInsightTrackerQml/qtinsighttrackerqmlexports.h>
#include <QtCore/QObject>
#include <QtQml/QQmlEngine>

namespace QtInsightCategory {
    static const QLatin1String QuickControls("QtQuick.Controls");
}

QT_BEGIN_NAMESPACE

class Q_INSIGHTTRACKERQML_EXPORT QInsightCategoryAttached : public QObject
{
    Q_OBJECT
    QML_ANONYMOUS
    QML_ADDED_IN_VERSION(1,0)
    Q_PROPERTY(QString category READ category WRITE setCategory)
public:
    QInsightCategoryAttached(QObject *parent) : QObject(parent) {}
    QString category() { return m_category; }
    void setCategory(const QString &category) { m_category = category; }

private:
    QString m_category;
};

class Q_INSIGHTTRACKERQML_EXPORT QInsightCategory : public QObject
{
    Q_OBJECT
    QML_ATTACHED(QInsightCategoryAttached)
    QML_NAMED_ELEMENT(InsightCategory)
    QML_ADDED_IN_VERSION(1, 0)
public:
    QInsightCategory() = default;
    static QInsightCategoryAttached *qmlAttachedProperties(QObject *object)
    {
        return new QInsightCategoryAttached(object);
    }
};

QT_END_NAMESPACE

#endif // QINSIGHTCATEGORY_H
