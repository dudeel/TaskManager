#include "db-connects.hpp"

#include <QSqlDatabase>
#include <QtSql>

namespace database {
DBConnects::DBConnects(const std::shared_ptr<DBUserData> dbUserData)
    : _dbUserData{dbUserData}, _isConnection{}, _connectionError{} {}

const bool DBConnects::createConnection() {
  QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

  db.setHostName(_dbUserData.get()->hostAddress());
  db.setPort(_dbUserData.get()->port());
  db.setDatabaseName(_dbUserData.get()->databaseName());
  db.setUserName(_dbUserData.get()->userName());
  db.setPassword(_dbUserData.get()->password());

  if (!db.open()) {
    qFatal() << "db is not connected: " << db.lastError().text();
    return _isConnection = false;
  }

  return _isConnection = true;
}

const bool DBConnects::isConnection() const { return _isConnection; }

const std::string &DBConnects::isConnectionError() const {
  return _connectionError;
}

void DBConnects::closeConnection() {}

} // namespace database
