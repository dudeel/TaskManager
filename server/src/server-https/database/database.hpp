#pragma once

#include <iostream>
#include <memory>

#include "db-connects.hpp"
#include "db-table.hpp"
#include "db-user-data.hpp"

namespace database {
class Database final {
public:
  Database();
  ~Database() = default;

  Database(const Database &other) = delete;
  Database &operator=(const Database &other) = delete;

  Database(Database &&other) noexcept = default;
  Database &operator=(Database &&other) noexcept = default;

public:
  auto connectToDB() -> bool;
  inline auto isConnected() -> bool;

private:
  bool _isConnected;
  DBConnects _dbConnects;
  DBTable _dbTable;
  DBUserData _dbUserData;
};
} // namespace database
