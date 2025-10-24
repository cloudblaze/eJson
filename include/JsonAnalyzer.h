/* JsonAnalyzer.h */
/*
 * Copyright (C) 2025 Huo Yun(cloudblaze@yeah.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#pragma once

#include <sstream>
#include <string>

#include <cctype>
#include <cstring>

#include "Json.h"

namespace hy::json
{
	class JsonAnalyzer
	{
	private:
		std::string json;
		JsonObject *jObject = nullptr;

		char *json_c_str = nullptr;

	private:
		std::string getString(const char *&str);
		bool getDouble(const char *&str, double &value);
		void analyzer(const char *&str, JsonObject *&jObject);

	public:
		JsonAnalyzer() = delete;
		JsonAnalyzer(const JsonAnalyzer &src) = delete;
		JsonAnalyzer &operator=(const JsonAnalyzer &rhs) = delete;
		JsonAnalyzer(JsonAnalyzer &&src) = delete;
		JsonAnalyzer &operator=(JsonAnalyzer &&rhs) = delete;
		~JsonAnalyzer();

		/// @brief 构造函数
		/// @param jsonString JSON字符串
		JsonAnalyzer(std::string jsonString);

		/// @brief 获取JSON对象
		/// @return JSON对象
		JsonObject &&getJsonObject() const;
		/// @brief 获取JSON字符串
		/// @return JSON字符串
		std::string getJsonString() const;
	};
}