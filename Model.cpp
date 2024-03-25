

#include "Model.h"


// Constructor
Model::Model(QObject *parent) : QObject(parent){
    size = 0;

}




// The user wants to create a project from scratch. An empty project is created into a Json and aded to filePath.
void Model::createModel(int thisSize, QString name, const QString& filePath){
    // Populate the Model
    size = thisSize;

    // Create JSON object
    QJsonObject jsonObject;
    jsonObject["size"] = size;

    // Write JSON to file
    QFile file(filePath + "/" + name + ".json");
    if (!file.open(QIODevice::WriteOnly)) {
        // Handle error
        qDebug() << "Failed to open file for writing:" << file.errorString();
        return;
    }

    QJsonDocument jsonDoc(jsonObject);
    file.write(jsonDoc.toJson());
    file.close();

}

// The user wants to load a previous project. The project is saved in a Json at that filePath.
// Deserialize the json and send it to view.
void Model::loadModel(const QString& filePath){
    // Read JSON file
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        // Handle error
        return;
    }

    // Parse JSON
    QByteArray jsonData = file.readAll();
    QJsonDocument jsonDoc(QJsonDocument::fromJson(jsonData));
    QJsonObject jsonObject = jsonDoc.object();

    // Deserialize size
    size = jsonObject["size"].toInt();

    // Deserialize imageMap
    frames.clear();
    QJsonObject imageMapObject = jsonObject["imageMap"].toObject();
    QStringList keys = imageMapObject.keys();
    for (const QString& key : keys) {
        int mapKey = key.toInt();
        QImage image = base64ToImage(imageMapObject[key].toString());
        frames[mapKey] = image;
    }


    file.close();
}

// The user wants to save the current project state. Update the json.
void Model::saveModel(){
    // Create JSON object
    QJsonObject jsonObject;
    jsonObject["size"] = size;

    // Serialize QMap<int, QImage>
    QJsonObject imageMapObject;
    for (auto it = frames.begin(); it != frames.end(); ++it) {
        imageMapObject[QString::number(it.key())] = imageToBase64(it.value());
    }
    jsonObject["imageMap"] = imageMapObject;

    // Write JSON to file
    QFile file(saveFilePath);
    if (file.open(QIODevice::WriteOnly)) {
        QJsonDocument jsonDoc(jsonObject);
        file.write(jsonDoc.toJson());
        file.close();
    } else {
        // Handle error
    }
}


QString Model::imageToBase64(const QImage& image) {
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "PNG"); // Save QImage as PNG format, you can change this if needed
    return QString::fromLatin1(byteArray.toBase64().data());
}

QImage Model::base64ToImage(const QString& base64) {
    QByteArray imageData = QByteArray::fromBase64(base64.toLatin1());
    QImage image;
    image.loadFromData(imageData);
    return image;
}




// Slots
void Model::acceptNewFile(QString name, int size, QString path){
    createModel(size, name, path);
}

void Model::acceptLoadFile(QString path){
    loadModel(path);
}














