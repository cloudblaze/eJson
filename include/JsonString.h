/* JsonString.h */
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

#include "JsonBase.h"

namespace hy::json
{
	/// @brief 字符串
	class JsonString : public JsonBase
	{
	private:
		std::string value;

	public:
		JsonString() = delete;
		JsonString(const JsonString &src);
		JsonString &operator=(const JsonString &rhs);
		JsonString(JsonString &&src);
		JsonString &operator=(JsonString &&rhs);
		~JsonString();

		/// @brief 构造函数
		/// @param key 关键字
		/// @param value 值
		JsonString(const std::string &key, const std::string &value);

		/// @brief 设置值
		/// @param value 值
		void setValue(const std::string &value);
		/// @brief 获取值
		/// @return 值
		std::string getValue() const;

		friend bool operator==(const JsonString &lhs, const JsonString &rhs);
		friend bool operator!=(const JsonString &lhs, const JsonString &rhs);
		friend std::ostream &operator<<(std::ostream &os, const JsonString &jsonString);
	};
}