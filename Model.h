#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QVector>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>
#include <QImage>
#include <QJsonArray>
#include <QBuffer>

#include <iostream>

class Model : public QObject{
    Q_OBJECT

private:
    int size;
    QMap<int, QImage> frames;
    QString saveFilePath;

public:

    explicit Model(QObject *parent = nullptr);

    // The user wants to create a project from scratch. An empty project is created into a Json and aded to filePath.
    Model(int size, QString name, const QString& filePath, QObject *parent = nullptr);

    // The user wants to load a previous project. The project is saved in a Json at that filePath.
    // Deserialize the json and send it to view.
    Model(const QString& filePath, QObject *parent = nullptr);


    bool saveToJson(const QString& filePath);
    QJsonObject toJson();


    // The user wants to create a project from scratch. An empty project is created into a Json and added to filePath.
    void createModel(int size, QString name, const QString& filePath);

    // The user wants to load a previous project. The project is saved in a Json at that filePath.
    // Deserialize the json and send it to view.
    void loadModel(const QString& filePath);

    // The user wants to save the current project state. Update the json.
    void saveModel();

    QString imageToBase64(const QImage& image);

    QImage base64ToImage(const QString& base64);


public slots:
    void acceptNewFile(QString name, int size, QString path);

    void acceptLoadFile(QString path);

signals:


};







#endif // MODEL_H
