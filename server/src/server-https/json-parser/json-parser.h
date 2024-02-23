#pragma once

#include <QJsonObject>

namespace parser {
class JsonParser final {
public:
  /**
   * @brief Конструктор класса JsonParser.
   * @param filePath Ссылка на строку с расположением json файла.
   */
  JsonParser(const QString &filePath = "../data/database/databaseConfig.json");
  ~JsonParser() = default;

  JsonParser(const JsonParser &other) = delete;
  JsonParser &operator=(const JsonParser &other) = delete;

  JsonParser(JsonParser &&other) noexcept = delete;
  JsonParser &operator=(JsonParser &&other) noexcept = delete;

public:
  /**
   * @brief Открывает и читает json файл.
   * @return true, если json прочитан успешно, иначе false.
   */
  const bool read();

  /**
   * @brief Возвращает значение, был ли успешно прочитан json.
   * @return true, если json прочитан успешно, иначе false.
   */
  inline const bool isRead() const noexcept;

  /**
   * @brief Возвращает сообщение об ошибке при прочтении json, если оно есть.
   * @return Ссылка на строку с сообщением об ошибке.
   */
  inline const QString &lastError() const noexcept;

  /**
   * @brief Возвращает данные полученные из json, если они есть.
   * @return Ссылка на QJsonobject с данными.
   */
  inline const QJsonObject &data() const noexcept;

private:
  QString _filePath;
  QJsonObject _jsonObject;
  bool _isRead;
  QString _lastError;
};
} // namespace parser
