#include "db-connects.h"

namespace database {
DBConnects::DBConnects(const std::shared_ptr<DBUserData> dbUserData)
    : _dbUserData{dbUserData}, _db{QSqlDatabase::addDatabase("QPSQL")},
      _isConnection{}, _connectionError{} {}

DBConnects::~DBConnects() { closeConnection(); }

const bool DBConnects::createConnection() {
  _db.setHostName(_dbUserData.get()->hostAddress());
  _db.setPort(_dbUserData.get()->port());
  _db.setDatabaseName(_dbUserData.get()->databaseName());
  _db.setUserName(_dbUserData.get()->userName());
  _db.setPassword(_dbUserData.get()->password());

  if (!_db.open()) {
    _connectionError = _db.lastError().text();
    qFatal() << "db is not connected: " << _connectionError;
    return _isConnection = false;
  }

  return _isConnection = true;
}

const bool DBConnects::isConnection() const { return _isConnection; }

const QString &DBConnects::isConnectionError() const {
  return _connectionError;
}

void DBConnects::closeConnection() { _db.close(); }

} // namespace database
