// Copyright (C) 2022 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial

#ifndef QINSIGHTCONFIGURATION_H
#define QINSIGHTCONFIGURATION_H

#include <QtInsightTracker/qtinsighttracker_global.h>
#include <QtCore/QObject>
#include <QtCore/QString>

QT_BEGIN_NAMESPACE

class Q_INSIGHTTRACKER_EXPORT QInsightConfiguration : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(QInsightConfiguration)

    Q_PROPERTY(QString server READ server WRITE setServer)
    Q_PROPERTY(QString token READ token WRITE setToken)
    Q_PROPERTY(QString deviceModel READ deviceModel WRITE setDeviceModel)
    Q_PROPERTY(QString deviceVariant READ deviceVariant WRITE setDeviceVariant)
    Q_PROPERTY(QString deviceScreenType READ deviceScreenType WRITE setDeviceScreenType)
    Q_PROPERTY(QString appBuild READ appBuild WRITE setAppBuild)
    Q_PROPERTY(QString platform READ platform WRITE setPlatform)
    Q_PROPERTY(QString storageType READ storageType WRITE setStorageType)
    Q_PROPERTY(QString storagePath READ storagePath WRITE setStoragePath)
    Q_PROPERTY(int storageSize READ storageSize WRITE setStorageSize)
    Q_PROPERTY(int syncInterval READ syncInterval WRITE setSyncInterval)
    Q_PROPERTY(int batchSize READ batchSize WRITE setBatchSize)
    Q_PROPERTY(QStringList categories READ categories WRITE setCategories)

public:
    QInsightConfiguration(QObject *parent = nullptr);
    ~QInsightConfiguration() = default;

    bool load();
    bool isValid();

    QString server() const;
    void setServer(const QString &server);
    QString token() const;
    void setToken(const QString &token);
    QString deviceModel() const;
    void setDeviceModel(const QString &deviceModel);
    QString deviceVariant() const;
    void setDeviceVariant(const QString &deviceVariant);
    QString deviceScreenType() const;
    void setDeviceScreenType(const QString &deviceScreenType);
    QString appBuild() const;
    void setAppBuild(const QString &appBuild);
    QString platform() const;
    void setPlatform(const QString &platform);
    QString storageType() const;
    void setStorageType(const QString &storageType);
    QString storagePath() const;
    void setStoragePath(const QString &storagePath);
    int storageSize() const;
    void setStorageSize(int storageSize);
    int syncInterval() const;
    void setSyncInterval(int syncInterval);
    int batchSize() const;
    void setBatchSize(int batchSize);
    QStringList categories();
    void setCategories(const QStringList &categories);
};

QT_END_NAMESPACE

#endif // QINSIGHTCONFIGURATION_H
