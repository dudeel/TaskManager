add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(server-https)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Sql PostgreSQL)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Sql)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql server-https)
