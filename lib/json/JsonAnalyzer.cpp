/* JsonAnalyzer.cpp */
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

#include "JsonAnalyzer.h"

namespace hy::json
{
	JsonAnalyzer::~JsonAnalyzer()
	{
		delete jObject;
	}

	JsonAnalyzer::JsonAnalyzer(std::string jsonString)
		: json(jsonString)
	{
		json_c_str = new char[json.size() + 1];
		strncpy(json_c_str, json.c_str(), json.size());
		json_c_str[json.size()] = '\0';
		jObject = new JsonObject("");

		const char *str = json_c_str;
		analyzer(str, jObject);
	}

	JsonObject &&JsonAnalyzer::getJsonObject() const
	{
		return std::move(*(this->jObject));
	}

	std::string JsonAnalyzer::getJsonString() const
	{
		return json;
	}

	void JsonAnalyzer::analyzer(const char *&str, JsonObject *&jObject)
	{
		while (std::isspace(*str))
		{
			str++;
		}

		if (*str == '\0')
		{
			std::string msg = "Argument 'str' should not be a null-string.";
			throw std::invalid_argument(msg);
		}

		if (*str == '{' || *str == '[')
		{
			str++;

		LABEL_item:
			while (std::isspace(*str))
			{
				str++;
			}

			// key
			std::string key;
			if (jObject->type == JsonNodeType::Object)
			{
				if (*str != '\"')
				{
					std::string msg = "Argument 'str' should be a valid json string.";
					throw std::invalid_argument(msg);
				}
				key = getString(str);

				str++;
			}
			else
			{
				key = "";
			}

			while (std::isspace(*str))
			{
				str++;
			}

			// value
			if (*str == '\"')
			{
				// STRING
				std::string value = getString(str);
				jObject->Append(JsonString(key, value));
			}
			else
			{
				double numValue;
				if (getDouble(str, numValue))
				{
					// NUMBER
					jObject->Append(JsonNumber(key, numValue));
				}
				else
				{
					if (std::strncmp(str, "true", std::strlen("true")) == 0)
					{
						// BOOLEAN -- true
						jObject->Append(JsonBoolean(key, true));
						str += std::strlen("true");
					}
					else if (std::strncmp(str, "false", std::strlen("false")) == 0)
					{
						// BOOLEAN -- false
						jObject->Append(JsonBoolean(key, false));
						str += std::strlen("false");
					}
					else if (std::strncmp(str, "null", std::strlen("null")) == 0)
					{
						// NULL
						jObject->Append(JsonNull(key));
						str += std::strlen("null");
					}
					else
					{
						if (*str == '{')
						{
							// OBJECT
							JsonObject *child = new JsonObject(key);
							analyzer(str, child);
							jObject->Append(JsonObject(*child));
						}
						else if (*str == '[')
						{
							// ARRAY
							JsonObject *child = new JsonObject(key, true);
							analyzer(str, child);
							jObject->Append(JsonObject(*child));
						}
						else
						{
							std::string msg = "Argument 'str' should be a valid json string.";
							throw std::invalid_argument(msg);
						}
					}
				}
			}

			while (std::isspace(*str))
			{
				str++;
			}

			if (*str == ',')
			{
				str++;
				goto LABEL_item;
			}
			else if (*str == '}')
			{
				str++;
				return;
			}
			else if (*str == ']')
			{
				str++;
				return;
			}
		}
		else
		{
			std::string msg = "Argument 'str' should be a valid json string.";
			throw std::invalid_argument(msg);
		}
	}

	bool JsonAnalyzer::getDouble(const char *&str, double &value)
	{
		std::istringstream isstream(str);

		std::streampos start = isstream.tellg();
		if (isstream >> value)
		{
			std::streampos current = isstream.tellg();
			str += (current - start);
			return true;
		}
		else
		{
			return false;
		}
	}

	std::string JsonAnalyzer::getString(const char *&str)
	{
		if (*str != '\"')
		{
			std::string msg = std::format("{0}: Argument 'str' is not a valid c-style string enclosed with double quotation marks.", __FUNCTION__);
			throw std::runtime_error(msg);
		}

		str++;

		std::stringstream sstream;
		while (*str)
		{
			if (*str == '\"')
			{
				str++;
				return sstream.str();
			}

			sstream << *str;
			str++;
		}

		std::string msg = std::format("{0}: Argument 'str' is not a valid c-style string enclosed with double quotation marks.", __FUNCTION__);
		throw std::runtime_error(msg);
	}
}