#include <fstream>
#include <iostream>

#include <cstdlib>

#include "Json.h"
#include "JsonAnalyzer.h"

using namespace hy::json;

int main()
{
	try
	{
		std::ifstream ifstream("../emake.json");
		std::string json((std::istreambuf_iterator<char>(ifstream)),
						 std::istreambuf_iterator<char>());

		JsonAnalyzer jAnalyzer(json);
		std::cout << jAnalyzer.getJsonObject() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown error!" << std::endl;
	}

	return EXIT_SUCCESS;
}