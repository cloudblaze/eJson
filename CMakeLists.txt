# 所需CMake的最小版本。
cmake_minimum_required(VERSION 3.28)

# 设置项目的名称，并将其存储在变量PROJECT_NAME中。
project(ejson)

# 显示编译命令。
set(CMAKE_VERBOSE_MAKEFILE OFF)

# 设置C编译器遵循的标准。
set(CMAKE_C_STANDARD 23)
# 设置是否打开GNU C扩展。
set(CMAKE_C_EXTENSIONS ON)
# 设置C++编译器遵循的标准。
set(CMAKE_CXX_STANDARD 23)
# 设置是否打开GNU C++扩展。
set(CMAKE_CXX_EXTENSIONS ON)

# 添加编译选项
add_compile_options(-Wextra -Werror)

# 设置包含目录。
include_directories(include)
# 设置程序的输出路径。
#	PROJECT_SOURCE_DIR -- CMake内置变量之一，它代表当前项目根目录的路径。
#		当使用project命令指定项目名称时，CMake会自动设置PROJECT_SOURCE_DIR的默认值为项目根目录的路径（CMakeLists.txt所在的路径）。
#		如果你使用的是子目录CMakeLists.txt，那么PROJECT_SOURCE_DIR将会是子目录的路径。
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 设置库的输出路径。
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 搜索第三方工具pkg-config。
#	REQUIRED -- 如果找不到，则报错并停止生成。
find_package(PkgConfig REQUIRED)
# 通过pkg-config搜索fmt库。
#	REQUIRED -- 如果找不到，则报错并停止生成。
#	IMPORTED_TARGET -- 创建一个名为'PkgConfig::fmt'的导入目标，该目标可以作为参数直接传递给target_link_libraries()。
# pkg_search_module(fmt REQUIRED IMPORTED_TARGET fmt)

# 添加子目录
add_subdirectory(lib)
add_subdirectory(src)
