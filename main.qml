import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import PhotoAlbum 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello Trump")

      PhotoAlbum{
          id: myAlbum;
      }

      property var photos: myAlbum.getPhotos();
      property int currentIndex: 0;
      property int lastIndex: photos.length -1;

      Button {
          id: myButton
          anchors.bottom: parent.bottom
          text: "Show next photo"
          onClicked: {
              if (currentIndex < lastIndex) currentIndex++
              rotate.start()
          }
      }

      Image {
        id: image

        width: parent.width - 20
        height: parent.height - 20

        fillMode: Image.PreserveAspectFit
        source: photos[currentIndex]
        RotationAnimator {
               id: rotate
               target: image;
               from: 0;
               to: 360;
               duration: 1000
               running: true
           }
      }
  }
