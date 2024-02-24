#include "json-db-user-data.h"

namespace json::structures {
JsonDBUserData::JsonDBUserData(const QJsonObject *parseData)
    : _parseData(parseData) {}

const QString JsonDBUserData::hostAddress() const noexcept {
  const QString key = "hostAddress";
  if (_parseData->contains(key))
    return _parseData->value(key).toString();
  else
    return {};
}

const int JsonDBUserData::hostPort() const noexcept {
  const QString key = "hostPort";
  if (_parseData->contains(key))
    return _parseData->value(key).toInt();
  else
    return 0;
}

const QString JsonDBUserData::databaseName() const noexcept {
  const QString key = "databaseName";
  if (_parseData->contains(key))
    return _parseData->value(key).toString();
  else
    return {};
}

const QString JsonDBUserData::userName() const noexcept {
  const QString key = "userName";
  if (_parseData->contains(key))
    return _parseData->value(key).toString();
  else
    return {};
}

const QString JsonDBUserData::userPassword() const noexcept {
  const QString key = "userPassword";
  if (_parseData->contains(key))
    return _parseData->value(key).toString();
  else
    return {};
}
} // namespace json::structures
