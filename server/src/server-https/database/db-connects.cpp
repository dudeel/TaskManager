#include "db-connects.h"

namespace database {
DBConnects::DBConnects(const std::shared_ptr<DBUserData> dbUserData)
    : _dbUserData{dbUserData}, _db{QSqlDatabase::addDatabase("QPSQL")},
      _isConnection{}, _lastError{} {}

DBConnects::~DBConnects() { closeConnection(); }

const bool DBConnects::createConnection() {
  _db.setHostName(_dbUserData.get()->hostAddress());
  _db.setPort(_dbUserData.get()->port());
  _db.setDatabaseName(_dbUserData.get()->databaseName());
  _db.setUserName(_dbUserData.get()->userName());
  _db.setPassword(_dbUserData.get()->password());

  if (!_db.open()) {
    _lastError = _db.lastError().text();
    qFatal() << "db is not connected: " << _lastError;
    return _isConnection = false;
  }

  return _isConnection = true;
}

const bool DBConnects::isConnection() const noexcept { return _isConnection; }

const QString &DBConnects::lastError() const noexcept { return _lastError; }

void DBConnects::closeConnection() { _db.close(); }

} // namespace database
