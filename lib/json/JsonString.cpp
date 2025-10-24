/* JsonString.cpp */
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

#include "JsonString.h"

namespace hy::json
{
	JsonString::JsonString(const JsonString &src)
		: JsonBase(src.key, JsonNodeType::String)
	{
		if (&src == this)
		{
			return;
		}

		this->type = src.type;
		this->value = src.value;
	}

	JsonString &JsonString::operator=(const JsonString &rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}

		this->type = rhs.type;
		this->value = rhs.value;
		return *this;
	}

	JsonString::JsonString(JsonString &&src)
		: JsonBase(src.key, JsonNodeType::String)
	{
		if (&src == this)
		{
			return;
		}

		this->type = src.type;
		this->value = src.value;
	}

	JsonString &JsonString::operator=(JsonString &&rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}

		this->type = rhs.type;
		this->value = rhs.value;
		return *this;
	}

	JsonString::~JsonString()
	{
	}

	JsonString::JsonString(const std::string &key, const std::string &value)
		: JsonBase(key, JsonNodeType::String),
		  value(value)
	{
	}

	void JsonString::setValue(const std::string &value)
	{
		this->value = value;
	}

	std::string JsonString::getValue() const
	{
		return this->value;
	}

	bool operator==(const JsonString &lhs, const JsonString &rhs)
	{
		return lhs.value == rhs.value;
	}

	bool operator!=(const JsonString &lhs, const JsonString &rhs)
	{
		return !(lhs == rhs);
	}

	std::ostream &operator<<(std::ostream &os, const JsonString &jsonString)
	{
		os << jsonString.value << "\"";

		return os;
	}
}