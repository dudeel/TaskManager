#include "database.h"

#include <QDebug>
#include <QString>
#include <iostream>

#include "../json-parser/json-parser.h"
#include "../json-parser/structures/json-db-user-data.h"

namespace database {
Database::Database() {
  _dbUserData = std::make_shared<DBUserData>();
  if (!initData()) {
    return;
  }

  _dbConnects = std::make_shared<DBConnects>(_dbUserData);
  if (!_dbConnects.get()->create()) {
    qCritical() << _dbConnects.get()->lastError();
    return;
  }

  _dbTable = std::make_unique<DBTable>(_dbConnects);
  if (!_dbTable.get()->isHave()) {
    if (!_dbTable.get()->create()) {
      qCritical() << _dbTable.get()->lastError();
      return;
    }
  }
}

bool Database::initData() {
  json::JsonParser jp("../../data/database/databaseConfig.json");

  if (jp.read()) {
    json::structures::JsonDBUserData data(&jp.data());
    _dbUserData.get()->setHostAddress(data.hostAddress());
    _dbUserData.get()->setHostPort(data.hostPort());
    _dbUserData.get()->setDatabaseName(data.databaseName());
    _dbUserData.get()->setUserName(data.userName());
    _dbUserData.get()->setUserPassword(data.userPassword());
  } else {
    qCritical() << jp.lastError();
    return false;
  }

  return true;
}

} // namespace database
