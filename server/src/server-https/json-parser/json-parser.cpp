#include "json-parser.h"

#include <QFile>
#include <QJsonDocument>

namespace parser {
JsonParser::JsonParser(const QString &filePath)
    : _filePath{filePath}, _jsonObject{}, _isRead{false}, _readError{} {}

const bool JsonParser::read() {
  QFile file(_filePath);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    _readError = file.errorString();
    file.close();
    return _isRead = false;
  }

  QByteArray jsonData = file.readAll();
  file.close();

  QJsonParseError error;
  QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &error);

  if (jsonDoc.isNull()) {
    _readError = error.errorString();
    return _isRead = false;
  }

  if (!jsonDoc.isObject()) {
    _readError = "JSON не является объектом";
    return _isRead = false;
  }

  _jsonObject = jsonDoc.object();
  return _isRead = true;
}

const bool JsonParser::isRead() const { return _isRead; }

const QString &JsonParser::readError() const { return _readError; }
} // namespace parser
