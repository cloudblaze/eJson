/* JsonNull.cpp */
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

#include "JsonNull.h"

namespace hy::json
{
	JsonNull::JsonNull()
		: JsonBase("", JsonNodeType::Null)
	{
	}

	JsonNull::JsonNull(const JsonNull &src)
		: JsonBase(src.key, JsonNodeType::Null)
	{
		if (&src == this)
		{
			return;
		}

		this->type = src.type;
	}

	JsonNull &JsonNull::operator=(const JsonNull &rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}

		this->type = rhs.type;
		return *this;
	}

	JsonNull::JsonNull(JsonNull &&src)
		: JsonBase(src.key, JsonNodeType::Null)
	{
		if (&src == this)
		{
			return;
		}

		this->type = src.type;
	}

	JsonNull &JsonNull::operator=(JsonNull &&rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}

		this->type = rhs.type;
		return *this;
	}

	JsonNull::~JsonNull()
	{
	}

	JsonNull::JsonNull(const std::string &key)
		: JsonBase(key, JsonNodeType::Null)
	{
	}

	nullptr_t JsonNull::getValue() const
	{
		return nullptr;
	}

	bool operator==(const JsonNull &lhs, const JsonNull &rhs)
	{
		return true;
	}

	bool operator!=(const JsonNull &lhs, const JsonNull &rhs)
	{
		return !(lhs == rhs);
	}

	std::ostream &operator<<(std::ostream &os, const JsonNull &jsonNull)
	{
		os << "null";

		return os;
	}
}