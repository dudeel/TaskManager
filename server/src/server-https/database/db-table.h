#pragma once

#include <iostream>
#include <memory>

namespace database {
class DBTable {
public:
  DBTable();
  ~DBTable() = default;

  DBTable(const DBTable &other) = delete;
  DBTable &operator=(const DBTable &other) = delete;

  DBTable(DBTable &&other) noexcept = default;
  DBTable &operator=(DBTable &&other) noexcept = default;
};
} // namespace database
