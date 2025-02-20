// Copyright (C) 2022 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial

#ifndef QTINSIGHTTRACKEREXPORTS_H
#define QTINSIGHTTRACKEREXPORTS_H

#include <QtCore/qglobal.h>

QT_BEGIN_NAMESPACE

#if defined(QT_SHARED) || !defined(QT_STATIC)
#  if defined(QT_BUILD_INSIGHTTRACKER_LIB)
#    define Q_INSIGHTTRACKER_EXPORT Q_DECL_EXPORT
#  else
#    define Q_INSIGHTTRACKER_EXPORT Q_DECL_IMPORT
#  endif
#else
#  define Q_INSIGHTTRACKER_EXPORT
#endif

#if !defined(QT_BUILD_INSIGHTTRACKER_LIB) || defined(QT_STATIC)
/* outside library → inline decl + defi */
#  define QT_INSIGHTTRACKER_INLINE_SINCE(major, minor) inline
#  define QT_INSIGHTTRACKER_INLINE_IMPL_SINCE(major, minor) 1
#elif defined(QT_INSIGHTTRACKER_BUILD_REMOVED_API)
/* inside library, inside removed_api.cpp:
 * keep deprecated API → non-inline decl;
 * remove deprecated API → inline decl;
 * definition is always available */
#  define QT_INSIGHTTRACKER_INLINE_SINCE(major, minor) \
    QT_IF_DEPRECATED_SINCE(major, minor, inline, /* not inline */)
#  define QT_INSIGHTTRACKER_INLINE_IMPL_SINCE(major, minor) 1
#else
/* inside library, outside removed_api.cpp:
 * keep deprecated API → non-inline decl, no defi;
 * remove deprecated API → inline decl, defi */
#  define QT_INSIGHTTRACKER_INLINE_SINCE(major, minor) \
    QT_IF_DEPRECATED_SINCE(major, minor, inline, /* not inline */)
#  define QT_INSIGHTTRACKER_INLINE_IMPL_SINCE(major, minor) \
    QT_IF_DEPRECATED_SINCE(major, minor, 1, 0)
#endif

#ifdef QT_INSIGHTTRACKER_BUILD_REMOVED_API
#  define QT_INSIGHTTRACKER_REMOVED_SINCE(major, minor) QT_DEPRECATED_SINCE(major, minor)
#else
#  define QT_INSIGHTTRACKER_REMOVED_SINCE(major, minor) 0
#endif

QT_END_NAMESPACE

#endif // QTINSIGHTTRACKEREXPORTS_H
