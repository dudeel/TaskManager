#include "json-parser.h"

#include <QFile>
#include <QJsonDocument>

namespace json {
JsonParser::JsonParser(const QString &filePath)
    : _filePath{filePath}, _jsonObject{}, _isRead{false}, _lastError{} {}

const bool JsonParser::read() {
  QFile file(_filePath);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    _lastError = file.errorString();
    file.close();
    return _isRead = false;
  }

  QByteArray jsonData = file.readAll();
  file.close();

  QJsonParseError error;
  QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &error);

  if (jsonDoc.isNull()) {
    _lastError = error.errorString();
    return _isRead = false;
  }

  if (!jsonDoc.isObject()) {
    _lastError = "JSON не является объектом";
    return _isRead = false;
  }

  _jsonObject = jsonDoc.object();
  return _isRead = true;
}

const bool JsonParser::isRead() const noexcept { return _isRead; }

const QString &JsonParser::lastError() const noexcept { return _lastError; }

const QJsonObject &JsonParser::data() const noexcept { return _jsonObject; }
} // namespace json
