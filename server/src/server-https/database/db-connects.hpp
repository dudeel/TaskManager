#pragma once

#include "db-user-data.hpp"
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
  ~DBConnects() = default;

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
  const std::string &isConnectionError() const;

  /**
   * @brief Закрывает соединение с базой данных.
   */
  void closeConnection();

private:
  std::shared_ptr<DBUserData> _dbUserData;
  bool _isConnection;
  std::string _connectionError;
};
} // namespace database
