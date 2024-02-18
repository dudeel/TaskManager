#include "db-user-data.hpp"

namespace database {
DBUserData::DBUserData()
    : _hostName{"127.0.0.1"}, _port{5432}, _databaseName{"taskManager"},
      _userName{"host"}, _password{"hostPassword"} {}

void DBUserData::setHostName(const std::string &&hostName) {
  _hostName = hostName;
}

void DBUserData::setPort(const int &&port) { _port = port; }

void DBUserData::setDatabaseName(const std::string &&databaseName) {
  _databaseName = databaseName;
}

void DBUserData::setUserName(const std::string &&userName) {
  _userName = userName;
}

void DBUserData::setPassword(const std::string &&password) {
  _password = password;
}

auto DBUserData::hostName() const noexcept -> const std::string && {
  return std::move(_hostName);
}

auto DBUserData::port() const noexcept -> const int { return _port; }

auto DBUserData::databaseName() const noexcept -> const std::string && {
  return std::move(_databaseName);
}

auto DBUserData::userName() const noexcept -> const std::string && {
  return std::move(_userName);
}

auto DBUserData::password() const noexcept -> const std::string && {
  return std::move(_password);
}
} // namespace database
