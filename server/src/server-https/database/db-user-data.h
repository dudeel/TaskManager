#pragma once

#include <QString>

namespace database {
class DBUserData final {
public:
  /**
   * @brief Конструктор класса DBUserData.
   * @param hostAddress Адрес хоста.
   * @param port Порт хоста.
   * @param databaseName Имя базы данных.
   * @param userName Имя пользователя.
   * @param password Пароль пользователя.
   */
  explicit DBUserData();
  ~DBUserData() = default;

  DBUserData(const DBUserData &other) = delete;
  DBUserData &operator=(const DBUserData &other) = delete;

  DBUserData(DBUserData &&other) noexcept = delete;
  DBUserData &operator=(DBUserData &&other) noexcept = delete;

public:
  /**
   * @brief Устанавливает адрес хоста.
   * @param hostAddress Новый адрес хоста.
   */
  void setHostAddress(const QString &hostAddress);

  /**
   * @brief Устанавливает порт хоста.
   * @param hostPort Новый порт хоста.
   */
  void setHostPort(const int &hostPort);

  /**
   * @brief Устанавливает имя базы данных.
   * @param databaseName Новое имя базы данных.
   */
  void setDatabaseName(const QString &databaseName);

  /**
   * @brief Устанавливает имя пользователя.
   * @param hostAddress Новое имя пользователя.
   */
  void setUserName(const QString &userName);

  /**
   * @brief Устанавливает пароль пользователя.
   * @param hostAddress Новый пароль пользователя.
   */
  void setUserPassword(const QString &userPassword);

  /**
   * @brief Возвращает адрес хоста.
   * @return Ссылка на строку с адресом хоста.
   */
  const QString &hostAddress() const noexcept;

  /**
   * @brief Возвращает порт хоста.
   * @return Порт хоста.
   */
  const int hostPort() const noexcept;

  /**
   * @brief Возвращает имя базы данных.
   * @return Ссылка на строку с именем базы данных.
   */
  const QString &databaseName() const noexcept;

  /**
   * @brief Возвращает имя пользователя.
   * @return Ссылка на строку с именем пользователя.
   */
  const QString &userName() const noexcept;

  /**
   * @brief Возвращает пароль пользователя.
   * @return Ссылка на строку с паролем пользователя.
   */
  const QString &userPassword() const noexcept;

private:
  QString _hostAddress;
  int _hostPort;
  QString _databaseName;
  QString _userName;
  QString _userPassword;
};
} // namespace database
