/* JsonBase.h */
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

#include <iostream>
#include <string>

namespace hy::json
{
	/// @brief JSON 数据类型
	enum class JsonNodeType
	{
		/// @brief 数值
		Number,
		/// @brief 字符串
		String,
		/// @brief 布尔类型
		Boolean,
		/// @brief 空类型
		Null,
		/// @brief 数组
		Array,
		/// @brief 对象
		Object
	};

	/// @brief JSON 基类
	class JsonBase
	{
	public:
		/// @brief 数据类型
		JsonNodeType type;
		/// @brief 关键字
		std::string key;

	public:
		JsonBase() = delete;
		JsonBase(const JsonBase &src);
		JsonBase &operator=(const JsonBase &rhs);
		JsonBase(JsonBase &&src);
		JsonBase &operator=(JsonBase &&rhs);
		~JsonBase();

		/// @brief 构造函数
		/// @param key 关键字
		/// @param type 数据类型
		JsonBase(const std::string &key, JsonNodeType type);

		/// @brief 设置关键字
		/// @param key 关键字
		void setKey(const std::string &key);
		/// @brief 获取关键字
		/// @return 关键字
		std::string getKey() const;
		/// @brief 获取数据类型
		/// @return 数据类型
		JsonNodeType getType() const;

		friend bool operator==(const JsonBase &lhs, const JsonBase &rhs);
		friend std::ostream &operator<<(std::ostream &os, const JsonBase &jsonBase);
	};
}