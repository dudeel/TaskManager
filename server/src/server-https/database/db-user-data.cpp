#include "db-user-data.h"

namespace database {
DBUserData::DBUserData(const QString &hostAddress, const int port,
                       const QString &databaseName, const QString &userName,
                       const QString &password)
    : _hostAddress{hostAddress}, _port{port}, _databaseName{databaseName},
      _userName{userName}, _password{password} {}

void DBUserData::setHostAddress(const QString &hostAddress) {
  _hostAddress = hostAddress;
}

void DBUserData::setPort(const int &port) { _port = port; }

void DBUserData::setDatabaseName(const QString &databaseName) {
  _databaseName = databaseName;
}

void DBUserData::setUserName(const QString &userName) { _userName = userName; }

void DBUserData::setPassword(const QString &password) { _password = password; }

const QString &DBUserData::hostAddress() const noexcept { return _hostAddress; }

const int DBUserData::port() const noexcept { return _port; }

const QString &DBUserData::databaseName() const noexcept {
  return _databaseName;
}

const QString &DBUserData::userName() const noexcept { return _userName; }

const QString &DBUserData::password() const noexcept { return _password; }
} // namespace database
