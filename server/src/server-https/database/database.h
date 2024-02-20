#pragma once

#include <iostream>
#include <memory>

#include "db-connects.h"
#include "db-table.h"
#include "db-user-data.h"

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
