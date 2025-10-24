/* JsonObject.cpp */
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

#include "JsonObject.h"

namespace hy::json
{
	JsonObject::JsonObject(const JsonObject &src)
		: JsonBase(src.key, JsonNodeType::Object)
	{
		if (&src == this)
		{
			return;
		}

		this->type = src.type;
		this->array.clear();
		for (auto it = src.array.cbegin(); it != src.array.cend(); it++)
		{
			JsonBase *ptr = nullptr;
			switch ((*it)->type)
			{
			case JsonNodeType::Number:
				ptr = new JsonNumber(*(JsonNumber *)(*it));
				break;
			case JsonNodeType::String:
				ptr = new JsonString(*(JsonString *)(*it));
				break;
			case JsonNodeType::Boolean:
				ptr = new JsonBoolean(*(JsonBoolean *)(*it));
				break;
			case JsonNodeType::Null:
				ptr = new JsonNull(*(JsonNull *)(*it));
				break;
			case JsonNodeType::Array:
			case JsonNodeType::Object:
				ptr = new JsonObject(*(JsonObject *)(*it));
				break;
			}

			this->array.insert(this->array.end(), ptr);
		}
	}

	JsonObject &JsonObject::operator=(const JsonObject &rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}

		this->type = rhs.type;
		this->array.clear();
		for (auto it = rhs.array.cbegin(); it != rhs.array.cend(); it++)
		{
			JsonBase *ptr = nullptr;
			switch ((*it)->type)
			{
			case JsonNodeType::Number:
				ptr = new JsonNumber(*(JsonNumber *)(*it));
				break;
			case JsonNodeType::String:
				ptr = new JsonString(*(JsonString *)(*it));
				break;
			case JsonNodeType::Boolean:
				ptr = new JsonBoolean(*(JsonBoolean *)(*it));
				break;
			case JsonNodeType::Null:
				ptr = new JsonNull(*(JsonNull *)(*it));
				break;
			case JsonNodeType::Array:
			case JsonNodeType::Object:
				ptr = new JsonObject(*(JsonObject *)(*it));
				break;
			}

			this->array.insert(this->array.end(), ptr);
		}
		return *this;
	}

	JsonObject::JsonObject(JsonObject &&src)
		: JsonBase(src.key, JsonNodeType::Object)
	{
		if (&src == this)
		{
			return;
		}

		this->type = src.type;
		this->array.clear();
		for (auto it = src.array.cbegin(); it != src.array.cend(); it++)
		{
			JsonBase *ptr = nullptr;
			switch ((*it)->type)
			{
			case JsonNodeType::Number:
				ptr = new JsonNumber(*(JsonNumber *)(*it));
				break;
			case JsonNodeType::String:
				ptr = new JsonString(*(JsonString *)(*it));
				break;
			case JsonNodeType::Boolean:
				ptr = new JsonBoolean(*(JsonBoolean *)(*it));
				break;
			case JsonNodeType::Null:
				ptr = new JsonNull(*(JsonNull *)(*it));
				break;
			case JsonNodeType::Array:
			case JsonNodeType::Object:
				ptr = new JsonObject(*(JsonObject *)(*it));
				break;
			}

			this->array.insert(this->array.end(), ptr);
		}
	}

	JsonObject &JsonObject::operator=(JsonObject &&rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}

		this->type = rhs.type;
		this->array.clear();
		for (auto it = rhs.array.cbegin(); it != rhs.array.cend(); it++)
		{
			JsonBase *ptr = nullptr;
			switch ((*it)->type)
			{
			case JsonNodeType::Number:
				ptr = new JsonNumber(*(JsonNumber *)(*it));
				break;
			case JsonNodeType::String:
				ptr = new JsonString(*(JsonString *)(*it));
				break;
			case JsonNodeType::Boolean:
				ptr = new JsonBoolean(*(JsonBoolean *)(*it));
				break;
			case JsonNodeType::Null:
				ptr = new JsonNull(*(JsonNull *)(*it));
				break;
			case JsonNodeType::Array:
			case JsonNodeType::Object:
				ptr = new JsonObject(*(JsonObject *)(*it));
				break;
			}

			this->array.insert(this->array.end(), ptr);
		}
		return *this;
	}

	JsonObject::~JsonObject()
	{
		for (auto it = this->array.cbegin(); it != this->array.cend(); it++)
		{
			delete *it;
		}
	}

	JsonObject::JsonObject(const std::string &key, bool isArray)
		: JsonBase(key, isArray ? JsonNodeType::Array : JsonNodeType::Object)
	{
	}

	void JsonObject::Insert(int pos, const JsonBase &value)
	{
		int array_size = this->array.size();

		if (pos < 0)
		{
			pos = -pos;
			pos = array_size - pos;
			if (pos < 0)
			{
				pos = 0;
			}
		}
		else if (pos >= array_size)
		{
			pos = this->array.size();
		}

		auto it = this->array.cbegin();
		if (pos == array_size)
		{
			it = this->array.end();
		}
		else
		{
			int index = 0;
			for (; it != this->array.end(); it++)
			{
				if (index == pos)
				{
					break;
				}
				index++;
			}
		}

		JsonBase *ptr = nullptr;
		switch (value.type)
		{
		case JsonNodeType::Number:
			ptr = new JsonNumber(*(JsonNumber *)&value);
			break;
		case JsonNodeType::String:
			ptr = new JsonString(*(JsonString *)&value);
			break;
		case JsonNodeType::Boolean:
			ptr = new JsonBoolean(*(JsonBoolean *)&value);
			break;
		case JsonNodeType::Null:
			ptr = new JsonNull(*(JsonNull *)&value);
			break;
		case JsonNodeType::Array:
		case JsonNodeType::Object:
			ptr = new JsonObject(*(JsonObject *)&value);
			break;
		}
		this->array.insert(it, ptr);
	}

	void JsonObject::Remove(int pos)
	{
		int array_size = this->array.size();

		if (pos < 0)
		{
			pos = -pos;
			pos = array_size - pos;
			if (pos < 0)
			{
				std::string msg = std::format("{0}: Argument 'pos' is out of range.", __FUNCTION__);
				throw std::range_error(msg);
			}
		}
		else if (pos >= array_size)
		{
			std::string msg = std::format("{0}: Argument 'pos' is out of range.", __FUNCTION__);
			throw std::range_error(msg);
		}

		int index = 0;
		auto it = this->array.cbegin();
		for (; it != this->array.end(); it++)
		{
			if (index == pos)
			{
				break;
			}
		}

		delete *it;
		this->array.remove(*it);
	}

	void JsonObject::Append(const JsonBase &value)
	{
		if (this->type == JsonNodeType::Object)
		{
			for (auto item : this->array)
			{
				if (item->key == value.key)
				{
					std::string msg = std::format("{0}: The key '{1}' already exists.", __FUNCTION__, value.key);
					throw std::runtime_error(msg);
				}
			}
		}

		JsonBase *ptr = nullptr;
		switch (value.type)
		{
		case JsonNodeType::Number:
			ptr = new JsonNumber(*(JsonNumber *)&value);
			break;
		case JsonNodeType::String:
			ptr = new JsonString(*(JsonString *)&value);
			break;
		case JsonNodeType::Boolean:
			ptr = new JsonBoolean(*(JsonBoolean *)&value);
			break;
		case JsonNodeType::Null:
			ptr = new JsonNull(*(JsonNull *)&value);
			break;
		case JsonNodeType::Array:
		case JsonNodeType::Object:
			ptr = new JsonObject(*(JsonObject *)&value);
			break;
		}
		this->array.insert(this->array.end(), ptr);
	}

	std::list<JsonBase> JsonObject::getValue()
	{
		std::list<JsonBase> result;

		for (auto it = this->array.cbegin(); it != this->array.cend(); it++)
		{
			JsonBase *ptr = nullptr;
			switch ((*it)->type)
			{
			case JsonNodeType::Number:
				ptr = new JsonNumber(*(JsonNumber *)(*it));
				break;
			case JsonNodeType::String:
				ptr = new JsonString(*(JsonString *)(*it));
				break;
			case JsonNodeType::Boolean:
				ptr = new JsonBoolean(*(JsonBoolean *)(*it));
				break;
			case JsonNodeType::Null:
				ptr = new JsonNull(*(JsonNull *)(*it));
				break;
			case JsonNodeType::Array:
			case JsonNodeType::Object:
				ptr = new JsonObject(*(JsonObject *)(*it));
				break;
			}

			result.insert(result.end(), *ptr);
		}

		return result;
	}

	JsonBase &&JsonObject::operator[](std::size_t index)
	{
		if (this->type != JsonNodeType::Array)
		{
			std::string msg = std::format("{0}: Only Array could be searched by the key.", __FUNCTION__);
			throw std::invalid_argument(msg);
		}

		if (index >= this->array.size())
		{
			std::string msg = std::format("{0}: The argument 'index' is too big.", __FUNCTION__);
			throw std::out_of_range(msg);
		}

		std::size_t i = 0;
		for (auto it = this->array.cbegin(); it != this->array.cend(); it++, i++)
		{
			if (i < index)
			{
				continue;
			}

			JsonBase *ptr = nullptr;
			switch ((*it)->type)
			{
			case JsonNodeType::Number:
				ptr = new JsonNumber(*(JsonNumber *)(*it));
				break;
			case JsonNodeType::String:
				ptr = new JsonString(*(JsonString *)(*it));
				break;
			case JsonNodeType::Boolean:
				ptr = new JsonBoolean(*(JsonBoolean *)(*it));
				break;
			case JsonNodeType::Null:
				ptr = new JsonNull(*(JsonNull *)(*it));
				break;
			case JsonNodeType::Array:
			case JsonNodeType::Object:
				ptr = new JsonObject(*(JsonObject *)(*it));
				break;
			}

			return std::move(*ptr);
		}

		std::string msg = std::format("{0}: The argument 'index' is too big.", __FUNCTION__);
		throw std::out_of_range(msg);
	}

	JsonBase &&JsonObject::operator[](const std::string &key)
	{
		if (this->type != JsonNodeType::Object)
		{
			std::string msg = std::format("{0}: Only Object could be searched by the key.", __FUNCTION__);
			throw std::invalid_argument(msg);
		}

		auto it = this->array.cbegin();
		for (; it != this->array.cend(); it++)
		{
			if ((*it)->key == key)
			{
				JsonBase *ptr = nullptr;
				switch ((*it)->type)
				{
				case JsonNodeType::Number:
					ptr = new JsonNumber(*(JsonNumber *)(*it));
					break;
				case JsonNodeType::String:
					ptr = new JsonString(*(JsonString *)(*it));
					break;
				case JsonNodeType::Boolean:
					ptr = new JsonBoolean(*(JsonBoolean *)(*it));
					break;
				case JsonNodeType::Null:
					ptr = new JsonNull(*(JsonNull *)(*it));
					break;
				case JsonNodeType::Array:
				case JsonNodeType::Object:
					ptr = new JsonObject(*(JsonObject *)(*it));
					break;
				}

				return std::move(*ptr);
			}
		}

		std::string msg = std::format("{0}: The key '{1}' dos not exist.", __FUNCTION__, key);
		throw std::runtime_error(msg);
	}

	bool operator==(const JsonObject &lhs, const JsonObject &rhs)
	{
		int lhs_array_size = lhs.array.size();
		int rhs_array_size = rhs.array.size();

		if (lhs_array_size != rhs_array_size)
		{
			return false;
		}

		auto it_lhs = lhs.array.cbegin();
		auto it_rhs = rhs.array.cbegin();
		for (int i = 0; i < lhs_array_size; i++, it_lhs++, it_rhs)
		{
			if ((*it_lhs)->type != (*it_rhs)->type)
			{
				return false;
			}

			switch ((*it_lhs)->type)
			{
			case JsonNodeType::Number:
				if ((*(JsonNumber *)(*it_lhs)).getValue() != (*(JsonNumber *)(*it_rhs)).getValue())
				{
					return false;
				}
				break;
			case JsonNodeType::String:
				if ((*(JsonString *)(*it_lhs)).getValue() != (*(JsonString *)(*it_rhs)).getValue())
				{
					return false;
				}
				break;
			case JsonNodeType::Boolean:
				if ((*(JsonBoolean *)(*it_lhs)).getValue() != (*(JsonBoolean *)(*it_rhs)).getValue())
				{
					return false;
				}
				break;
			case JsonNodeType::Null:
				break;
			case JsonNodeType::Array:
			case JsonNodeType::Object:
				if ((*(JsonObject *)(*it_lhs)).getValue() != (*(JsonObject *)(*it_rhs)).getValue())
				{
					return false;
				}
				break;
			}
		}

		return true;
	}

	bool operator!=(const JsonObject &lhs, const JsonObject &rhs)
	{
		return !(lhs == rhs);
	}

	std::ostream &operator<<(std::ostream &os, const JsonObject &jsonObject)
	{
		std::stringstream sstream;

		if (jsonObject.type == JsonNodeType::Array)
		{
			sstream << "[";
		}
		else
		{
			sstream << "{";
		}

		std::size_t index = 0;
		for (auto item : jsonObject.array)
		{
			if (jsonObject.type == JsonNodeType::Object)
			{
				sstream << "\"" << item->key << "\": ";
			}

			JsonBase *ptr = nullptr;
			switch (item->type)
			{
			case JsonNodeType::Number:
				sstream << ((JsonNumber *)item)->getValue();
				break;
			case JsonNodeType::String:
				sstream << "\"" << ((JsonString *)item)->getValue() << "\"";
				break;
			case JsonNodeType::Boolean:
				sstream << std::boolalpha << ((JsonBoolean *)item)->getValue();
				break;
			case JsonNodeType::Null:
				sstream << "null";
				break;
			case JsonNodeType::Array:
			case JsonNodeType::Object:
				sstream << *(JsonObject *)item;
				break;
			}
			sstream << *item;
			if (index < jsonObject.array.size() - 1)
			{
				sstream << ", ";
			}
			index++;
		}

		if (jsonObject.type == JsonNodeType::Array)
		{
			sstream << "]";
		}
		else
		{
			sstream << "}";
		}

		return os << sstream.str();
	}
}