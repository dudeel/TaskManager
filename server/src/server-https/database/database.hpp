#pragma once

#include <iostream>
#include <memory>

#include "db-connects.hpp"
#include "db-table.hpp"
#include "db-user-data.hpp"

namespace database {
class Database final {
public:
  Database() = default;
  ~Database() = default;

  Database(const Database &other) = delete;
  Database &operator=(const Database &other) = delete;

  Database(Database &&other) noexcept = default;
  Database &operator=(Database &&other) noexcept = default;

private:
  std::unique_ptr<DBConnects> _dbConnects;
  std::unique_ptr<DBTable> _dbTable;
  std::unique_ptr<DBUserData> _dbUserData;
};
} // namespace database
