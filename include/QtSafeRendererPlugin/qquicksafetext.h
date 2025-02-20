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
#ifndef SAFETEXT_H
#define SAFETEXT_H

#include <QQuickItem>
#include <QTextOption>
#include <QColor>

QT_BEGIN_NAMESPACE

class QQuickSafeTextPrivate;
class QQuickSafeText : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QFont font READ font WRITE setFont NOTIFY fontChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QColor fillColor READ fillColor WRITE setFillColor NOTIFY fillColorChanged)
    Q_PROPERTY(HAlignment horizontalAlignment READ hAlign WRITE setHAlign NOTIFY horizontalAlignmentChanged)
    Q_PROPERTY(VAlignment verticalAlignment READ vAlign WRITE setVAlign NOTIFY verticalAlignmentChanged)
    Q_PROPERTY(WrapMode wrapMode READ wrapMode WRITE setWrapMode NOTIFY wrapModeChanged)
    Q_PROPERTY(bool runtimeEditable READ runtimeEditable WRITE setRuntimeEditable NOTIFY runtimeEditableChanged)


public:
    QQuickSafeText(QQuickItem *parent = nullptr);
    enum HAlignment { AlignLeft = Qt::AlignLeft,
                       AlignRight = Qt::AlignRight,
                       AlignHCenter = Qt::AlignHCenter,
                       AlignJustify = Qt::AlignJustify };
    Q_ENUM(HAlignment)

    enum VAlignment { AlignTop = Qt::AlignTop,
                       AlignBottom = Qt::AlignBottom,
                       AlignVCenter = Qt::AlignVCenter };
    Q_ENUM(VAlignment)

    enum WrapMode { NoWrap = QTextOption::NoWrap,
                    WordWrap = QTextOption::WordWrap,
                    WrapAnywhere = QTextOption::WrapAnywhere,
                    WrapAtWordBoundaryOrAnywhere = QTextOption::WrapAtWordBoundaryOrAnywhere, // COMPAT
                    Wrap = QTextOption::WrapAtWordBoundaryOrAnywhere
                  };
    Q_ENUM(WrapMode)

    QString text() const;
    void setText(const QString &text);

    QFont font() const;
    void setFont(const QFont &font);

    QColor color() const;
    void setColor(const QColor &c);

    QColor fillColor() const;
    void setFillColor(const QColor &fillColor);

    QQuickSafeText::HAlignment hAlign() const;
    void setHAlign(HAlignment align);

    QQuickSafeText::VAlignment vAlign() const;
    void setVAlign(VAlignment align);

    QQuickSafeText::WrapMode wrapMode() const;
    void setWrapMode(WrapMode w);

    void setRuntimeEditable(const bool editable);
    bool runtimeEditable() const;

Q_SIGNALS:
    void colorChanged();
    void fillColorChanged();
    void fontChanged(const QFont &font);
    void sourceChanged(const QUrl &url);
    void textChanged(const QString &text);
    void horizontalAlignmentChanged(QQuickSafeText::HAlignment alignment);
    void verticalAlignmentChanged(QQuickSafeText::VAlignment alignment);
    void wrapModeChanged();
    void positionChanged(const QPointF& pos);
    void runtimeEditableChanged();
public Q_SLOTS:
    void updateTexture();

protected:
    QQuickSafeText(QQuickSafeTextPrivate &dd, QQuickItem *parent = nullptr);

    void itemChange(ItemChange change, const ItemChangeData &value) override;
    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *data) override;

private:
    Q_DECLARE_PRIVATE(QQuickSafeText)
};

QT_END_NAMESPACE

#endif // SAFETEXT_H
