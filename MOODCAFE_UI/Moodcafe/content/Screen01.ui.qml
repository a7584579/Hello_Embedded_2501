

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.5
import QtQuick.Controls 6.5
import Moodcafe
import QtQuick.Layouts 1.0
import QtMultimedia

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height
    visible: true
    color: "#ffffff"

    Rectangle {
        id: rectangle1
        x: 0
        y: 0
        width: 1024
        height: 600
        visible: true
        color: "#4a3c3b"

        Rectangle {
            id: rectangle5
            x: 50
            y: 50
            width: 300
            height: 550
            color: "#e5d4c2"

            Button {
                id: button
                x: 35
                y: 440
                width: 231
                height: 54
                text: qsTr("1")
                highlighted: false
                flat: false

                Connections {
                    target: button
                    onClicked: rectangle.state = "function1"
                }
            }

            TextEdit {
                id: textEdit
                x: 46
                y: 15
                width: 209
                height: 73
                color: "#c56c34"
                text: "Mood Recognition"
                font.pixelSize: 23
                horizontalAlignment: Text.AlignLeft
                font.bold: true
            }
        }

        Rectangle {
            id: rectangle6
            x: 362
            y: 51
            width: 300
            height: 548
            color: "#e5d4c2"

            Button {
                id: button1
                x: 33
                y: 440
                width: 231
                height: 54
                text: qsTr("2")

                Connections {
                    target: button1
                    onClicked: rectangle.state = "function2"
                }
            }

            TextEdit {
                id: textEdit1
                x: 59
                y: 15
                width: 170
                height: 73
                color: "#c56c34"
                text: "Physical Signs"
                font.pixelSize: 23
                font.bold: true
            }
        }

        Rectangle {
            id: rectangle7
            x: 674
            y: 51
            width: 300
            height: 549
            color: "#e5d4c2"

            Button {
                id: button4
                x: 35
                y: 440
                width: 231
                height: 54
                text: qsTr("3")
                Connections {
                    target: button4
                    onClicked: rectangle.state = "function3"
                }
            }

            TextEdit {
                id: textEdit2
                x: 51
                y: 15
                width: 163
                height: 73
                color: "#c56c34"
                text: "Coffee Maker"
                font.pixelSize: 23
                font.bold: true
            }
        }
    }

    Rectangle {
        id: rectangle2
        x: 0
        y: 0
        width: 1024
        height: 600
        visible: false
        color: "#e5d4c2"

        Button {
            id: button2
            x: 184
            y: 415
            text: qsTr("Button")

            Connections {
                target: button2
                onClicked: rectangle.state = ""
            }
        }

        TextEdit {
            id: textEdit3
            x: 96
            y: 174
            width: 209
            height: 73
            color: "#c56c34"
            text: "Mood Recognition"
            font.pixelSize: 23
            horizontalAlignment: Text.AlignLeft
            font.bold: true
        }

        Image {
            id: image
            x: 346
            y: 198
            width: 100
            height: 100
            source: "qrc:/qtquickplugin/images/template_image.png"
            fillMode: Image.PreserveAspectFit
        }
    }

    Rectangle {
        id: rectangle3
        x: 7
        y: 7
        width: 1024
        height: 600
        visible: false
        color: "#e5d4c2"

        Button {
            id: button3
            x: 184
            y: 415
            text: qsTr("Button")
            Connections {
                target: button3
                onClicked: rectangle.state = ""
            }
        }

        TextEdit {
            id: textEdit4
            x: 414
            y: 59
            width: 170
            height: 73
            color: "#c56c34"
            text: "Physical Signs"
            font.pixelSize: 23
            font.bold: true
        }

        Image {
            id: image2
            x: 128
            y: 250
            width: 100
            height: 100
            source: "qrc:/qtquickplugin/images/template_image.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image1
            x: 128
            y: 150
            width: 100
            height: 100
            source: "qrc:/qtquickplugin/images/template_image.png"
            fillMode: Image.PreserveAspectFit
        }

        TextEdit {
            id: textEdit6
            x: 413
            y: 58
            width: 170
            height: 73
            color: "#c56c34"
            text: "Physical Signs"
            font.pixelSize: 23
            font.bold: true
        }

        TextEdit {
            id: textEdit7
            x: 416
            y: 61
            width: 170
            height: 73
            color: "#c56c34"
            text: "Physical Signs"
            font.pixelSize: 23
            font.bold: true
        }
    }

    Rectangle {
        id: rectangle4
        x: 5
        y: 5
        width: 1024
        height: 600
        visible: false
        color: "#e5d4c2"

        Connections {
            target: rectangle4
            onClicked: console.log("clicked")
        }

        TextEdit {
            id: textEdit5
            x: 717
            y: 58
            width: 163
            height: 73
            color: "#c56c34"
            text: "Coffee Maker"
            font.pixelSize: 23
            font.bold: true
        }

        Image {
            id: image3
            x: 91
            y: 133
            width: 100
            height: 100
            source: "qrc:/qtquickplugin/images/template_image.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image4
            x: 267
            y: 151
            width: 100
            height: 100
            source: "qrc:/qtquickplugin/images/template_image.png"
            fillMode: Image.PreserveAspectFit
        }

        Button {
            id: button5
            x: 186
            y: 417
            text: qsTr("Button")
            Connections {
                target: button5
                onClicked: rectangle.state = ""
            }
        }


    }

    states: [
        State {
            name: "function1"

            PropertyChanges {
                target: rectangle1
                visible: false
            }

            PropertyChanges {
                target: rectangle2
                visible: true
            }

            PropertyChanges {
                target: button2
                x: 820
                y: 500
                width: 105
                height: 40
                text: qsTr("Button")
                font.pointSize: 16
            }

            PropertyChanges {
                target: textEdit3
                x: 333
                y: 38
                width: 306
                height: 73
                font.pixelSize: 30
            }

            PropertyChanges {
                target: image
                x: 299
                y: 155
                width: 375
                height: 330
            }
        },
        State {
            name: "function2"

            PropertyChanges {
                target: rectangle2
                visible: false
            }

            PropertyChanges {
                target: rectangle1
                visible: false
            }

            PropertyChanges {
                target: rectangle3
                x: 0
                y: 0
                visible: true
                color: "#e5d4c2"
            }

            PropertyChanges {
                target: rectangle4
                color: "#e5d4c2"
            }

            PropertyChanges {
                target: textEdit4
                x: 41
                y: 27
                width: 223
                height: 73
                text: "Physical Signs"
                font.pixelSize: 30
            }

            PropertyChanges {
                target: button3
                x: 820
                y: 500
                text: qsTr("Return")
                font.pointSize: 16
            }

            PropertyChanges {
                target: textEdit6
                x: 217
                y: 146
                text: "Heart Rate"
            }

            PropertyChanges {
                target: textEdit7
                x: 566
                y: 146
                text: "Blood Oxygen"
            }

            PropertyChanges {
                target: image1
                x: 198
                y: 203
                width: 213
                height: 266
            }

            PropertyChanges {
                target: image2
                x: 553
                y: 215
                width: 213
                height: 252
            }
        },
        State {
            name: "function3"

            PropertyChanges {
                target: rectangle1
                visible: false
            }

            PropertyChanges {
                target: rectangle4
                x: -1
                y: -1
                visible: true
            }

            PropertyChanges {
                target: rectangle2
                x: -7
                y: -6
                width: 1031
                height: 606
            }

            PropertyChanges {
                target: button5
                x: 820
                y: 500
                text: qsTr("Return")
                font.pointSize: 16
            }

            PropertyChanges {
                target: textEdit5
                x: 60
                y: 41
                width: 225
                height: 73
                text: "Coffee Maker"
                font.pixelSize: 30
            }

            PropertyChanges {
                target: image3
                x: 90
                y: 132
                source: "images/图片1.png"
            }

            PropertyChanges {
                target: image4
                x: 266
                y: 150
                source: "images/图片2.png"
            }
        }
    ]
}
