#pragma once

#include <QJsonObject>

namespace json::structures {
class JsonDBUserData final {
public:
  explicit JsonDBUserData(const QJsonObject *parseData);
  ~JsonDBUserData() = default;

public:
  const QString hostAddress() const noexcept;
  const int hostPort() const noexcept;
  const QString databaseName() const noexcept;
  const QString userName() const noexcept;
  const QString userPassword() const noexcept;

private:
  const QJsonObject *_parseData;
};
} // namespace json::structures
