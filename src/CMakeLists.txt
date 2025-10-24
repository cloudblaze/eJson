project(ejson_demo)

# 生成程序
add_executable(${PROJECT_NAME} main.cpp)
# 指定链接给定目标和/或其依赖项时要使用的库或标志。
#	CMAKE_SOURCE_DIR -- CMake内置变量之一，它代表顶层项目根目录的路径，即顶层CMakeLists.txt所在的目录。
target_link_libraries(${PROJECT_NAME} PRIVATE
	json
)
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/lib")