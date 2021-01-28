import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    width: 350
    height: 420
    visible: true
    color: "#ffffff"
    title: qsTr("Hello World")

    TextEdit {
        id: textEdit
        y: 20
        height: 108
        color: "#000000"
        text: qsTr("Text Edit")
        anchors.left: parent.left
        anchors.right: parent.right
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        wrapMode: Text.WordWrap
        anchors.rightMargin: 24
        anchors.leftMargin: 27
        selectionColor: "#000000"
        selectByMouse: true
        textMargin: 10
        padding: 0
        leftPadding: 0
        topPadding: 0

        Rectangle {
            id: rectangle
            y: 0
            height: 108
            color: "#00ffffff"
            border.width: 2
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.leftMargin: 0
        }
    }

    TextEdit {
        id: textEdit1
        y: 162
        height: 108
        color: "#000000"
        text: qsTr("Text Edit")
        anchors.left: parent.left
        anchors.right: parent.right
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        wrapMode: Text.WordWrap
        anchors.rightMargin: 24
        anchors.leftMargin: 27
        selectionColor: "#000000"
        selectByMouse: true
        padding: 0
        topPadding: 0
        leftPadding: 0
        textMargin: 10

        Rectangle {
            id: rectangle1
            height: 108
            color: "#00ffffff"
            border.width: 2
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.leftMargin: 0
        }
    }

    Button {
        id: button
        y: 307
        height: 35
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.rightMargin: 24
        anchors.leftMargin: 27
        label: "Сравнить"
        onButtonClick:
        {
            text1.text = textEdit.text == textEdit1.text ? "Текст совпадает" : "Текст не совпадает"
        }
    }

    Text {
        id: text1
        y: 361
        height: 36
        text: qsTr("Введите текст и нажмите кнопку")
        anchors.left: parent.left
        anchors.right: parent.right
        font.pixelSize: 16
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WordWrap
        anchors.rightMargin: 24
        anchors.leftMargin: 27
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}D{i:2}D{i:4}D{i:5}
}
##^##*/
