import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    width: 350
    height: 490
    minimumWidth: 350
    minimumHeight: 420
    visible: true
    color: "#ffffff"
    title: qsTr("Hello World")

    TextEdit {
        id: textEdit
        y: 70
        height: 108
        color: "#000000"
        text: qsTr("")
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
        y: 258
        height: 108
        color: "#000000"
        text: qsTr("")
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

    Button {
        id: button
        y: 392
        height: 35
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.rightMargin: 24
        anchors.leftMargin: 27
        label: "Сравнить"
        onButtonClick:
        {
            if (textEdit.text == textEdit1.text) {
                text1.text =  "Текст совпадает"
                text1.color = "#000000"
            }
            else {
                text1.text = "Текст не совпадает"
                text1.color = "#ff0000"
            }
        }
    }

    Text {
        id: text1
        y: 433
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

    Button {
        id: button1
        x: 27
        y: 22
        width: 100
        height: 35
        labelSize: 11
        label: "Загрузить"
        onButtonClick:
        {
            textEdit.text = file.load("text1.txt")
        }
    }

    Button {
        id: button2
        x: 146
        y: 22
        width: 100
        height: 35
        labelSize: 11
        label: "Сохранить"
        onButtonClick:
        {
            file.save("text1.txt", textEdit.text)
        }
    }

    Button {
        id: button3
        x: 27
        y: 210
        width: 100
        height: 35
        label: "Загрузить"
        labelSize: 11
        onButtonClick:
        {
            textEdit1.text = file.load("text2.txt")
        }
    }

    Button {
        id: button4
        x: 146
        y: 210
        width: 100
        height: 35
        label: "Сохранить"
        labelSize: 11
        onButtonClick:
        {
            file.save("text2.txt", textEdit1.text)
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}D{i:8}
}
##^##*/
