import QtQuick 2.0

Item {
    id: wisp

    Rectangle {
        height: 20
        width: 20
        radius: 10
        x: - width / 2
        y: - height / 2
        rotation: -90
        gradient: Gradient {
            GradientStop {
                position: 0.0
                color: "red"
            }
            GradientStop {
                position: 1.0
                color: "orange"
            }
        }
    }
}
