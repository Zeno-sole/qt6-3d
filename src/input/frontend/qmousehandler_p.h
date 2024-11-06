// Copyright (C) 2015 Klaralvdalens Datakonsult AB (KDAB).
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QT3DINPUT_QMOUSEHANDLER_P_H
#define QT3DINPUT_QMOUSEHANDLER_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of other Qt classes.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <Qt3DInput/qmouseevent.h>
#include <Qt3DInput/qmousehandler.h>

#include <Qt3DCore/private/qcomponent_p.h>

QT_BEGIN_NAMESPACE

class QTimer;

namespace Qt3DInput {

class QMouseHandler;
class QMouseDevice;

class QMouseHandlerPrivate : public Qt3DCore::QComponentPrivate
{
public:
    QMouseHandlerPrivate();
    ~QMouseHandlerPrivate();

    void init();

    QMouseDevice *m_mouseDevice;
    bool m_containsMouse;
    QTimer *m_pressAndHoldTimer = nullptr;
    QMouseEventPtr m_lastPressedEvent;

    void mouseEvent(const QMouseEventPtr &event);

    Q_DECLARE_PUBLIC(QMouseHandler)
};

struct QMouseHandlerData
{
    Qt3DCore::QNodeId mouseDeviceId;
};

} // namespace Qt3DInput

QT_END_NAMESPACE

#endif // QT3DINPUT_QMOUSEHANDLER_P_H

