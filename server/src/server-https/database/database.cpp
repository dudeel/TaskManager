#include "database.hpp"

#include <QDebug>
#include <QSqlDatabase>
#include <QtSql>

namespace database {
Database::Database()
    : _isConnected{false}, _hostName{"127.0.0.1"}, _port{5432},
      _databaseName{"taskManager"}, _userName{"host"},
      _password{"hostPassword"} {
  QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

  db.setHostName("localhost");
  db.setPort(5432);

  db.setDatabaseName("postgres");
  db.setUserName("postgres");
  db.setPassword("password");

  if (!db.open()) {
    qFatal() << "db is not connected: " << db.lastError().text();
  }
}
} // namespace database
