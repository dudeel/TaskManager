#include "database.hpp"

// #include <QDebug>
// #include <QSqlDatabase>
// #include <QtSql>

namespace database {
Database::Database() : _isConnected{false} {
  // QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

  // db.setHostName("localhost");
  // db.setPort(5432);

  // db.setDatabaseName("postgres");
  // db.setUserName("postgres");
  // db.setPassword("password");

  // if (!db.open()) {
  //   qFatal() << "db is not connected: " << db.lastError().text();
  // } else {
  //   qInfo() << "db is connected!";
  // }

  std::cout << "123" << std::endl;
  std::cout << _dbUserData.hostName() << std::endl;
  _dbUserData.setHostName("124");
  std::cout << _dbUserData.hostName() << std::endl;
}
} // namespace database
