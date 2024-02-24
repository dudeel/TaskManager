#include "db-user-data.h"

namespace database {
DBUserData::DBUserData()
    : _hostAddress{"127.0.0.1"}, _hostPort{5432}, _databaseName{"taskManager"},
      _userName{"host"}, _userPassword{"hostPassword"} {}

void DBUserData::setHostAddress(const QString &hostAddress) {
  _hostAddress = hostAddress;
}

void DBUserData::setHostPort(const int &hostPort) { _hostPort = hostPort; }

void DBUserData::setDatabaseName(const QString &databaseName) {
  _databaseName = databaseName;
}

void DBUserData::setUserName(const QString &userName) { _userName = userName; }

void DBUserData::setUserPassword(const QString &userPassword) {
  _userPassword = userPassword;
}

const QString &DBUserData::hostAddress() const noexcept { return _hostAddress; }

const int DBUserData::hostPort() const noexcept { return _hostPort; }

const QString &DBUserData::databaseName() const noexcept {
  return _databaseName;
}

const QString &DBUserData::userName() const noexcept { return _userName; }

const QString &DBUserData::userPassword() const noexcept {
  return _userPassword;
}
} // namespace database
