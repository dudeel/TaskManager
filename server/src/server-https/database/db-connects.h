#pragma once

#include <QSqlDatabase>
#include <QtSql>

#include "db-user-data.h"
#include <memory>

namespace database {
class DBConnects {
public:
  /**
   * @brief Конструктор класса DBConnects.
   * @param dbUserData Указатель на объект DBUserData,
   * в котором данные для подключении к базе данных.
   */
  DBConnects(const std::shared_ptr<DBUserData> dbUserData);
  ~DBConnects();

  DBConnects(const DBConnects &other) = delete;
  DBConnects &operator=(const DBConnects &other) = delete;

  DBConnects(DBConnects &&other) noexcept = default;
  DBConnects &operator=(DBConnects &&other) noexcept = default;

public:
  /**
   * @brief Устанавливает соединение с базой данных.
   * @return true, если соединение установлено успешно, иначе false.
   */
  const bool createConnection();

  /**
   * @brief Проверяет текущее состояние соединения с базой данных.
   * @return true, если соединение активно, иначе false.
   */
  const bool isConnection() const;

  /**
   * @brief Возвращает сообщение об ошибке соединения, если оно есть.
   * @return Ссылка на строку с сообщением об ошибке соединения.
   */
  const QString &isConnectionError() const;

  /**
   * @brief Закрывает соединение с базой данных.
   */
  void closeConnection();

private:
  QSqlDatabase _db;
  std::shared_ptr<DBUserData> _dbUserData;
  bool _isConnection;
  QString _connectionError;
};
} // namespace database
