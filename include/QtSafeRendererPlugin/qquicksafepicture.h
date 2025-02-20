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
#ifndef SAFEPICTURE_H
#define SAFEPICTURE_H

#include <QQuickItem>
#include <QColor>

QT_BEGIN_NAMESPACE

class QQuickSafePicturePrivate;
class QQuickSafePicture : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QColor fillColor READ fillColor WRITE setFillColor NOTIFY fillColorChanged)

public:
    QQuickSafePicture(QQuickItem *parent = nullptr);

    QUrl source() const;
    void setSource(const QUrl &url);
    QColor color() const;
    void setColor(const QColor &color);
    QColor fillColor() const;
    void setFillColor(const QColor &color);
Q_SIGNALS:
    void sourceChanged(const QUrl &url);
    void positionChanged(const QPointF& pos);
    void colorChanged(const QColor &color);
    void fillColorChanged(const QColor &color);

public Q_SLOTS:
    void updateTexture();

protected:
    QQuickSafePicture(QQuickSafePicturePrivate &dd, QQuickItem *parent = nullptr);

    void itemChange(ItemChange change, const ItemChangeData &value) override;
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *data) override;

private:
    Q_DECLARE_PRIVATE(QQuickSafePicture)
};

QT_END_NAMESPACE

#endif // SAFEPICTURE_H
