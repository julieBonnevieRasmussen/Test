#include "photoalbum.h"
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

PhotoAlbum::PhotoAlbum(QObject *parent) : QObject(parent)
{
    readFromJsonFileAndSetPhotos("photos.json");
}

void PhotoAlbum::readFromJsonFileAndSetPhotos(QString path)
{
    QFile file(path);
    if(!file.open(QFile::ReadOnly)){
        qDebug()<< "Error, Cannot open the file.";
    }

    QJsonDocument jsonResponse = QJsonDocument::fromJson(file.readAll());
    QJsonArray jsonArray = jsonResponse.array();

    int arrayLength = jsonArray.count();

    for (int index = 0; index < arrayLength; index++){
        m_photos.append(jsonArray[index].toObject().value("url").toString());
    }
}

QStringList PhotoAlbum::getPhotos()
{
    return m_photos;
}
