#pragma once

#include <QSqlDatabase>
#include <QtSql>

#include <memory>

#include "db-interface.h"
#include "db-user-data.h"

namespace database {
class DBConnects final : public DBInterface {
public:
  /**
   * @brief Конструктор класса DBConnects.
   * @param dbUserData Указатель на объект DBUserData,
   * в котором данные для подключении к базе данных.
   */
  explicit DBConnects(const std::shared_ptr<DBUserData> dbUserData);
  ~DBConnects();

  DBConnects(const DBConnects &other) = delete;
  DBConnects &operator=(const DBConnects &other) = delete;

  DBConnects(DBConnects &&other) noexcept = delete;
  DBConnects &operator=(DBConnects &&other) noexcept = delete;

public:
  /**
   * @brief Устанавливает соединение с базой данных.
   * @return true, если соединение установлено успешно, иначе false.
   */
  const bool create() override;

  /**
   * @brief Проверяет было ли установлено соединения с базой данных.
   * @return true, если соединение активно, иначе false.
   */
  const bool isHave() const noexcept override;

  /**
   * @brief Возвращает сообщение об ошибке соединения, если оно есть.
   * @return Ссылка на строку с сообщением об ошибке соединения.
   */
  const QString &lastError() const noexcept override;

  /**
   * @brief Закрывает соединение с базой данных.
   */
  const bool drop() override;

private:
  QSqlDatabase _db;
  std::shared_ptr<DBUserData> _dbUserData;

  bool _isHave;
  QString _lastError;
};
} // namespace database
