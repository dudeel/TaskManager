#pragma once

#include <QJsonObject>

namespace parser {
class JsonParser {
public:
  /**
   * @brief Конструктор класса JsonParser.
   * @param filePath Ссылка на строку с расположением json файла.
   */
  JsonParser(const QString &filePath = "../data/database/databaseConfig.json");

  /**
   * @brief Открывает и читает json файл.
   * @return true, если json прочитан успешно, иначе false.
   */
  const bool read();

  /**
   * @brief Возвращает значение, был ли успешно прочитан json.
   * @return true, если json прочитан успешно, иначе false.
   */
  const bool isRead() const;

  /**
   * @brief Возвращает сообщение об ошибке при прочтении json, если оно есть.
   * @return Ссылка на строку с сообщением об ошибке.
   */
  const QString &readError() const;

private:
  QString _filePath;
  QJsonObject _jsonObject;
  bool _isRead;
  QString _readError;
};
} // namespace parser
