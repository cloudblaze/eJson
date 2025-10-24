/* JsonBoolean.cpp */
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

#include "JsonBoolean.h"

namespace hy::json
{
	JsonBoolean::JsonBoolean(const JsonBoolean &src)
		: JsonBase(src.key, JsonNodeType::Boolean)
	{
		if (&src == this)
		{
			return;
		}

		this->type = src.type;
		this->value = src.value;
	}

	JsonBoolean &JsonBoolean::operator=(const JsonBoolean &rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}

		this->type = rhs.type;
		this->value = rhs.value;
		return *this;
	}

	JsonBoolean::JsonBoolean(JsonBoolean &&src)
		: JsonBase(src.key, JsonNodeType::Boolean)
	{
		if (&src == this)
		{
			return;
		}

		this->type = src.type;
		this->value = src.value;
	}

	JsonBoolean &JsonBoolean::operator=(JsonBoolean &&rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}

		this->type = rhs.type;
		this->value = rhs.value;
		return *this;
	}

	JsonBoolean::~JsonBoolean()
	{
	}

	JsonBoolean::JsonBoolean(const std::string &key, bool value)
		: JsonBase(key, JsonNodeType::Boolean),
		  value(value)
	{
	}

	void JsonBoolean::setValue(bool value)
	{
		this->value = value;
	}

	bool JsonBoolean::getValue() const
	{
		return this->value;
	}

	bool operator==(const JsonBoolean &lhs, const JsonBoolean &rhs)
	{
		return lhs.value == rhs.value;
	}

	bool operator!=(const JsonBoolean &lhs, const JsonBoolean &rhs)
	{
		return !(lhs == rhs);
	}

	std::ostream &operator<<(std::ostream &os, const JsonBoolean &jsonBoolean)
	{
		os << std::boolalpha << jsonBoolean.value;

		return os;
	}
}