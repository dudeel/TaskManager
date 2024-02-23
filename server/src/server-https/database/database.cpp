#include "database.h"

#include <QString>
#include <iostream>

namespace database {
Database::Database() {
  static const QString HOST_ADDRESS = "127.0.0.1";
  constexpr int HOST_PORT = 5432;
  static const QString DATABASE_NAME = "taskManager";
  static const QString USER_NAME = "host";
  static const QString USER_PASSWORD = "hostPassword";

  _dbUserData = std::make_shared<DBUserData>(
      HOST_ADDRESS, HOST_PORT, DATABASE_NAME, USER_NAME, USER_PASSWORD);
  _dbConnects = std::make_shared<DBConnects>(_dbUserData);
  _dbTable = std::make_unique<DBTable>(_dbConnects);
}

} // namespace database
