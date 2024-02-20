set(TARGET server-https)
file(GLOB_RECURSE FILES "*.cpp" "*.h"  "*.hpp" "*.ui")
add_library(${TARGET} ${FILES}
    json-parser/json-parser.h json-parser/json-parser.cpp
    json-parser/structures/json-db-user-data.h json-parser/structures/json-db-user-data.cpp)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Sql PostgreSQL)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Sql)
target_link_libraries(${TARGET} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)
