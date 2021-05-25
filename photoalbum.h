#ifndef PHOTOALBUM_H
#define PHOTOALBUM_H
#include <QObject>


class PhotoAlbum : public QObject
{
    Q_OBJECT
public:
    explicit PhotoAlbum(QObject *parent = nullptr);
    Q_INVOKABLE QStringList getPhotos();
    void readFromJsonFileAndSetPhotos(QString path);

private:
    QStringList m_photos;

};
#endif // PHOTOALBUM_H
