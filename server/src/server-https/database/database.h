#pragma once

#include <iostream>
#include <memory>

#include "db-connects.h"
#include "db-table.h"
#include "db-user-data.h"

namespace database {
class Database final {
public:
  Database();
  ~Database() = default;

  Database(const Database &other) = delete;
  Database &operator=(const Database &other) = delete;

  Database(Database &&other) noexcept = delete;
  Database &operator=(Database &&other) noexcept = delete;

private:
  void initializationData();

private:
  std::shared_ptr<DBUserData> _dbUserData;
  std::shared_ptr<DBConnects> _dbConnects;
  std::unique_ptr<DBTable> _dbTable;
};
} // namespace database
