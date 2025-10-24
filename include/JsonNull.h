/* JsonNull.h */
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
	class JsonNull : public JsonBase
	{
	public:
		JsonNull();
		JsonNull(const JsonNull &src);
		JsonNull &operator=(const JsonNull &rhs);
		JsonNull(JsonNull &&src);
		JsonNull &operator=(JsonNull &&rhs);
		~JsonNull();

		/// @brief 构造函数
		/// @param key 关键字
		JsonNull(const std::string &key);

		/// @brief 获取值
		/// @return 值
		nullptr_t getValue() const;

		friend bool operator==(const JsonNull &lhs, const JsonNull &rhs);
		friend bool operator!=(const JsonNull &lhs, const JsonNull &rhs);
		friend std::ostream &operator<<(std::ostream &os, const JsonNull &jsonNull);
	};
}