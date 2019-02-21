import QtQuick 2.9
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: status
        x: 210
        y: 42
        width: 200
        height: 33
        color: "#ffffff"
    }

    Rectangle {
        id: request
        x: 210
        y: 103
        width: 200
        height: 35
        color: "#ffffff"
    }

    Rectangle {
        id: response
        x: 210
        y: 151
        width: 200
        height: 37
        color: "#ffffff"
    }
}
