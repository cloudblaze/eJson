/* JsonBoolean.h */
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
	/// @brief 布尔类型
	class JsonBoolean : public JsonBase
	{
	private:
		bool value;

	public:
		JsonBoolean() = delete;
		JsonBoolean(const JsonBoolean &src);
		JsonBoolean &operator=(const JsonBoolean &rhs);
		JsonBoolean(JsonBoolean &&src);
		JsonBoolean &operator=(JsonBoolean &&rhs);
		~JsonBoolean();

		/// @brief 构造函数
		/// @param key 关键字
		/// @param value 值
		JsonBoolean(const std::string &key, bool value);

		/// @brief 设置值
		/// @param value 值
		void setValue(bool value);
		/// @brief 获取值
		/// @return 值
		bool getValue() const;

		friend bool operator==(const JsonBoolean &lhs, const JsonBoolean &rhs);
		friend bool operator!=(const JsonBoolean &lhs, const JsonBoolean &rhs);
		friend std::ostream &operator<<(std::ostream &os, const JsonBoolean &jsonBoolean);
	};
}