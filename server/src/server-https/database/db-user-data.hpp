#pragma once

#include <iostream>

namespace database {
class DBUserData {
public:
  DBUserData();
  ~DBUserData() = default;

  DBUserData(const DBUserData &other) = delete;
  DBUserData &operator=(const DBUserData &other) = delete;

  DBUserData(DBUserData &&other) noexcept = default;
  DBUserData &operator=(DBUserData &&other) noexcept = default;

public:
  void setHostName(const std::string &&hostName);
  void setPort(const int &&port);
  void setDatabaseName(const std::string &&databaseName);
  void setUserName(const std::string &&userName);
  void setPassword(const std::string &&password);

  auto hostName() const noexcept -> const std::string &&;
  auto port() const noexcept -> const int;
  auto databaseName() const noexcept -> const std::string &&;
  auto userName() const noexcept -> const std::string &&;
  auto password() const noexcept -> const std::string &&;

private:
  std::string _hostName;
  int _port;
  std::string _databaseName;
  std::string _userName;
  std::string _password;
};
} // namespace database
