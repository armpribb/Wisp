import QtQuick 2.15

Item {
    id: controlPanel

    anchors.fill: parent

    Item {
        id: kp
        height: 200
        width: 200
        anchors.top: parent.top
        anchors.right: parent.right
        Rectangle {
            id: kpvisible
            anchors.fill: parent
            anchors.margins: 10
            radius: 10
            color: "white"
            opacity: 0.2
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            propagateComposedEvents: true
            onEntered: kpvisible.opacity = 0.5
            onExited: kpvisible.opacity = 0.2
            onPressed: {
                if (pressedButtons & Qt.LeftButton)
                    mouse.accepted = false
            }
        }
    }

    Item {
        id: ki
        height: 200
        width: 200
        anchors.top: kp.bottom
        anchors.right: parent.right
        Rectangle {
            id: kivisible
            anchors.fill: parent
            anchors.margins: 10
            radius: 10
            color: "white"
            opacity: 0.2
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            propagateComposedEvents: true
            onEntered: kivisible.opacity = 0.5
            onExited: kivisible.opacity = 0.2
            onPressed: {
                if (pressedButtons & Qt.LeftButton)
                    mouse.accepted = false
            }
        }
    }

    Item {
        id: kd
        height: 200
        width: 200
        anchors.top: ki.bottom
        anchors.right: parent.right
        Rectangle {
            id: kdvisible
            anchors.fill: parent
            anchors.margins: 10
            radius: 10
            color: "white"
            opacity: 0.2
        }
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            propagateComposedEvents: true
            onEntered: kdvisible.opacity = 0.5
            onExited: kdvisible.opacity = 0.2
            onPressed: {
                if (pressedButtons & Qt.LeftButton)
                    mouse.accepted = false
            }
        }
    }
}
