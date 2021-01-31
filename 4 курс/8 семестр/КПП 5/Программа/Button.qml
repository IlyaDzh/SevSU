import QtQuick 2.0

Rectangle {
    id: button

    property int buttonHeight: 75
    property int buttonWidth: 150

    property string label
    property real labelSize: 14

    radius: 3
    antialiasing: true
    border {
        width: 2
        color: "#000"
    }
    width: buttonWidth;
    height: buttonHeight
    color: "#fff"

    Text {
        id: buttonLabel
        anchors.centerIn: parent
        text: label
        color: "#000"
        font.pointSize: labelSize

        Behavior on color {
            ColorAnimation {
                duration: 200
            }
        }
    }

    signal buttonClick()

    MouseArea {
        id: buttonMouseArea
        anchors.fill: parent
        onClicked: buttonClick()
        hoverEnabled: true
        onEntered: {
            parent.color = "#000"
            buttonLabel.color = "#fff"
        }
        onExited: {
            parent.color = "#fff"
            buttonLabel.color = "#000"
        }
    }

    scale: buttonMouseArea.pressed ? 1.03 : 1.00

    Behavior on scale {
        NumberAnimation {
            duration: 100
        }
    }

    Behavior on color {
        ColorAnimation {
            duration: 200
        }
    }
}
