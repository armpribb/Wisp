import QtQuick 2.15

Item {
    id: background
    anchors.fill: parent

    signal mouseLeftButtonClicked(x: double, y: double)
    signal mouseRightButtonClicked(x: double, y: double)
    signal mouseHoverPositionChanged(x: double, y: double)

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop {
                position: 0.0
                color: "blue"
            }
            GradientStop {
                position: 1.0
                color: "cyan"
            }
        }
    }
    MouseArea {
        id: mouseArea
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton | Qt.MiddleButton
        hoverEnabled: true
        onPositionChanged: {
            if (pressedButtons & Qt.LeftButton)
                background.mouseLeftButtonClicked(mouse.x, mouse.y);
            background.mouseHoverPositionChanged(mouse.x, mouse.y);
        }
        onPressed: {
            if (mouse.button == Qt.LeftButton)
                background.mouseLeftButtonClicked(mouse.x, mouse.y);
            else if (mouse.button == Qt.RightButton)
                background.mouseRightButtonClicked(mouse.x, mouse.y);
        }
    }
}
