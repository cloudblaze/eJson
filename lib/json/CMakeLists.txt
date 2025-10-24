project(json)

# 生成库
# 库的类型可以为
#	STATIC -- 静态库
#	SHARED -- 动态库
#	MODULE -- 模块库
add_library(${PROJECT_NAME} SHARED
	JsonBase.cpp
	JsonNumber.cpp
	JsonString.cpp
	JsonBoolean.cpp
	JsonNull.cpp
	JsonObject.cpp
	JsonAnalyzer.cpp
)
