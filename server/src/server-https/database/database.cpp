#include "database.h"

#include <QDebug>
#include <QString>
#include <iostream>

#include "../json-parser/json-parser.h"
#include "../json-parser/structures/json-db-user-data.h"

namespace database {
Database::Database() {
  _dbUserData = std::make_shared<DBUserData>();

  initializationData();

  _dbConnects = std::make_shared<DBConnects>(_dbUserData);
  _dbTable = std::make_unique<DBTable>(_dbConnects);
}

void Database::initializationData() {
  json::JsonParser jp("../../data/database/databaseConfig.json");

  if (jp.read()) {
    json::structures::JsonDBUserData data(&jp.data());
    _dbUserData.get()->setHostAddress(data.hostAddress());
    _dbUserData.get()->setHostPort(data.hostPort());
    _dbUserData.get()->setDatabaseName(data.databaseName());
    _dbUserData.get()->setUserName(data.userName());
    _dbUserData.get()->setUserPassword(data.userPassword());
    qDebug() << _dbUserData.get()->userName();
  } else {
    qCritical() << jp.lastError();
  }
}

} // namespace database
