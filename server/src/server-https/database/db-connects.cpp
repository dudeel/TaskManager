#include "db-connects.h"

#include <QDebug>

namespace database {
DBConnects::DBConnects(const std::shared_ptr<DBUserData> dbUserData)
    : _dbUserData{dbUserData}, _db{QSqlDatabase::addDatabase("QPSQL")},
      _isHave{}, _lastError{} {}

DBConnects::~DBConnects() { drop(); }

const bool DBConnects::create() {
  _db.setHostName(_dbUserData.get()->hostAddress());
  _db.setPort(_dbUserData.get()->hostPort());
  _db.setDatabaseName(_dbUserData.get()->databaseName());
  _db.setUserName(_dbUserData.get()->userName());
  _db.setPassword(_dbUserData.get()->userPassword());

  if (!_db.open()) {
    _lastError = _db.lastError().text();
    qFatal() << "db is not connected: " << _lastError;
    return _isHave = false;
  }

  return _isHave = true;
}

const bool DBConnects::isHave() const noexcept { return _isHave; }

const QString &DBConnects::lastError() const noexcept { return _lastError; }

const bool DBConnects::drop() {
  _db.close();
  _isHave = false;
  return true;
}

} // namespace database
