import QtQuick 2.12
import QtQuick.Controls 2.3


Rectangle{
    id: rectangle

    width: 640
    height: 480

    //    //title: "Please choose a file"
    //    folder: shortcuts.home
    //    selectFolder: false
    //    onAccepted: {
    //        var newDirName = fileDialog.fileUrl;
    //        fileNameTextField.text = newDirName;
    //        tableModel.loadFromFile(newDirName);
    //        console.log("Accepted" + newDirName);
    //    }
    //    onRejected: {
    //        //  console.log("Canceled")

    //    }
    Component.onCompleted: visible = false

    Button {
        id: button
        x: 540
        y: 418
        text: qsTr("Apply")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
    }

    ComboBox {
        id: comboBox
        width: 300
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: countryLabel.bottom
        anchors.topMargin: 10
    }

    Label {
        id: countryLabel
        width: 70
        height: 30
        text: qsTr("Country")
        lineHeight: 0.6
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
    }
}









/*##^## Designer {
    D{i:2;anchors_x:10;anchors_y:50}D{i:3;anchors_x:24;anchors_y:8}
}
 ##^##*/
