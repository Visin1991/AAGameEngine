#pragma once

#include <iostream>


namespace AAEngine
{
	class Debug
	{
	public:
		Debug();
		~Debug();

		static void Log(std::string str)
		{
			std::cout << "Log:  " << str.c_str() << std::endl;
		}

		static void LogWarning(std::string str)
		{
			std::cout << "LogWarning:  " << str.c_str() << std::endl;
		}

		static void LogError(std::string str)
		{
			std::cout << "LogError:  " << str.c_str() << std::endl;
		}

	private:

	};
}