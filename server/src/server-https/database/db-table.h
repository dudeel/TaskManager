#pragma once

#include <QString>

#include <memory>

#include "db-connects.h"
#include "db-interface.h"

namespace database {
class DBTable final : public DBInterface {
public:
  /**
   * @brief Конструктор класса DBTable.
   * @param dbConnects Указатель на объект DBConnects,
   * в котором хранится объект базы данных.
   */
  explicit DBTable(const std::shared_ptr<DBConnects> dbConnects);
  ~DBTable() = default;

  DBTable(const DBTable &other) = delete;
  DBTable &operator=(const DBTable &other) = delete;

  DBTable(DBTable &&other) noexcept = delete;
  DBTable &operator=(DBTable &&other) noexcept = delete;

public:
  /**
   * @brief Создает таблицу в базе данных.
   * @return true, если таблица создана успешно, иначе false.
   */
  const bool create() override;

  /**
   * @brief Проверяет существует ли таблица в базе данных.
   * @return true, если таблица существует, иначе false.
   */
  const bool isHave() const noexcept override;

  /**
   * @brief Создает запись в таблице.
   * @return true, если запись создана успешно, иначе false.
   */
  const bool insert();

  /**
   * @brief Обновляет запись в базе данных.
   * @return true, если запись обновлена успешно, иначе false.
   */
  const bool update();

  /**
   * @brief Удаляет запись в базе данных.
   * @return true, если запись удалена успешно, иначе false.
   */
  const bool remove();

  /**
   * @brief Возвращает сообщение об ошибке при взаимодействии
   * с таблицей, если она есть.
   * @return Ссылка на строку с сообщением об ошибке взаимодействия,
   * с таблицей.
   */
  const QString &lastError() const noexcept override;

  /**
   * @brief Удаляет таблицу в базе данных.
   */
  const bool drop() override;

private:
  std::unique_ptr<DBConnects> _dbConnects;

  bool _isHave;
  QString _lastError;
};
} // namespace database
