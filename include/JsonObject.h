/* JsonObject.h */
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

#include <list>
#include <sstream>

#include "JsonBase.h"
#include "JsonNumber.h"
#include "JsonString.h"
#include "JsonBoolean.h"
#include "JsonNull.h"

namespace hy::json
{
	/// @brief 对象
	class JsonObject : public JsonBase
	{
	private:
		std::list<JsonBase *> array;

	public:
		JsonObject() = delete;
		JsonObject(const JsonObject &src);
		JsonObject &operator=(const JsonObject &rhs);
		JsonObject(JsonObject &&src);
		JsonObject &operator=(JsonObject &&rhs);
		~JsonObject();

		/// @brief 构造函数
		/// @param key 关键字
		/// @param isArray 是否是数组
		JsonObject(const std::string &key, bool isArray = false);

		/// @brief 插入项
		/// @param pos 位置序号
		/// @param value 值
		void Insert(int pos, const JsonBase &value);
		/// @brief 删除项
		/// @param pos 位置序号
		void Remove(int pos);
		/// @brief 追加项
		/// @param value 值
		void Append(const JsonBase &value);

		/// @brief 获取所有项
		/// @return
		std::list<JsonBase> getValue();

		/// @brief 获取项
		/// @param index 位置序号
		/// @return 项
		JsonBase &&operator[](std::size_t index);
		/// @brief 获取项
		/// @param key 关键字
		/// @return 项
		JsonBase &&operator[](const std::string &key);

		friend bool operator==(const JsonObject &lhs, const JsonObject &rhs);
		friend bool operator!=(const JsonObject &lhs, const JsonObject &rhs);
		friend std::ostream &operator<<(std::ostream &os, const JsonObject &jsonObject);
	};
}