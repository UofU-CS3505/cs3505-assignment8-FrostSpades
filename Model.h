#ifndef MODEL_H
#define MODEL_H

#include <QBuffer>
#include <QDebug>
#include <QFile>
#include <QImage>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include <QVector>

#include <iostream>

class Model : public QObject
{
    Q_OBJECT

private:
    ///
    /// \brief size it stores the width/height of the squared canvas
    /// When the user creates a project they are offered a choice on resolution. That choice is stored here for QImage settings
    ///
    int size;

    ///
    /// \brief frames is a map from the key (which is the id of the QImage) to a QImage.
    ///
    QMap<int, QImage> frames;

    ///
    /// \brief saveFilePath just stores where the user would to save.
    ///
    QString saveFilePath;

    ///
    /// \brief imageToBase64 helper method for loading images to json
    /// \param image    the image that wants to be saved
    /// \return     json serialized version of that image.
    ///
    QString imageToBase64(const QImage &image);

    ///
    /// \brief base64ToImage helper method for loading QImages from json.
    /// \param base64   the json serialization part of an image
    /// \return     The QImage of the serialization.
    ///
    QImage base64ToImage(const QString &base64);

public:
    explicit Model(QObject *parent = nullptr);

    Model();

    Model(QString name, int size, QString path);
    Model(QString &filePath);

    ~Model();

    // The user wants to create a project from scratch. An empty project is created into a Json and added to filePath.
    void createModel(int size, QString name, const QString &filePath);

    // The user wants to load a previous project. The project is saved in a Json at that filePath.
    // Deserialize the json and send it to view.
    void loadModel(const QString &filePath);

    // The user wants to save the current project state. Update the json.
    void saveModel();

public slots:
    void acceptNewFile(QString name, int size, QString path);

    void acceptLoadFile(QString path);

signals:
};

#endif // MODEL_H
