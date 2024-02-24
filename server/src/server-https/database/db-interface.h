#pragma once

#include <QString>

class DBInterface {
  virtual const bool create() = 0;
  virtual const bool isHave() const noexcept = 0;
  virtual const QString &lastError() const noexcept = 0;
  virtual const bool drop() = 0;
};
