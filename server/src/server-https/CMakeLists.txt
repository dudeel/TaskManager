set(TARGET server-https)
file(GLOB_RECURSE FILES "*.cpp" "*.h" "*.ui")
add_library(${TARGET} ${FILES})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)
target_link_libraries(${TARGET} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)
