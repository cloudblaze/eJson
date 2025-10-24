/* JsonBase.cpp */
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

#include "JsonBase.h"

namespace hy::json
{
	JsonBase::JsonBase(const JsonBase &src)
	{
		if (&src == this)
		{
			return;
		}

		this->type = src.type;
		this->key = src.key;
	}

	JsonBase &JsonBase::operator=(const JsonBase &rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}

		this->type = rhs.type;
		this->key = rhs.key;
		return *this;
	}

	JsonBase::JsonBase(JsonBase &&src)
	{
		if (&src == this)
		{
			return;
		}

		this->type = src.type;
		this->key = src.key;
	}

	JsonBase &JsonBase::operator=(JsonBase &&rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}

		this->type = rhs.type;
		this->key = rhs.key;
		return *this;
	}

	JsonBase::~JsonBase()
	{
	}

	JsonBase::JsonBase(const std::string &key, JsonNodeType type) : key(key), type(type)
	{
	}

	void JsonBase::setKey(const std::string &key)
	{
		this->key = key;
	}

	std::string JsonBase::getKey() const
	{
		return this->key;
	}

	JsonNodeType JsonBase::getType() const
	{
		return this->type;
	}

	bool operator==(const JsonBase &lhs, const JsonBase &rhs)
	{
		return lhs.type == rhs.type && lhs.key == rhs.key;
	}

	std::ostream &operator<<(std::ostream &os, const JsonBase &jsonBase)
	{
		// os << "type: ";
		// switch (jsonBase.type)
		// {
		// case JsonNodeType::Number:
		// 	os << "Number";
		// 	break;
		// case JsonNodeType::String:
		// 	os << "String";
		// 	break;
		// case JsonNodeType::Boolean:
		// 	os << "Boolean";
		// 	break;
		// case JsonNodeType::Null:
		// 	os << "Null";
		// 	break;
		// case JsonNodeType::Array:
		// 	os << "Array";
		// 	break;
		// case JsonNodeType::Object:
		// 	os << "Object";
		// 	break;
		// }
		// os << ", key: " << jsonBase.key;
		return os;
	}
}