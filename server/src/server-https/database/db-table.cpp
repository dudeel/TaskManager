#include "db-table.h"

#include <QSqlQuery>

namespace database {
DBTable::DBTable(const std::shared_ptr<DBConnects> dbConnects)
    : _isHave{false}, _lastError{} {}

const bool DBTable::isHave() const noexcept { return _isHave; }

const bool DBTable::create() { return false; }

const bool DBTable::insert() { return false; }

const bool DBTable::update() { return false; }

const bool DBTable::remove() { return false; }

const QString &DBTable::lastError() const noexcept { return _lastError; }
} // namespace database
