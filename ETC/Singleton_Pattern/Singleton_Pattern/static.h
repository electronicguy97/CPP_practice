#pragma once
#include <iostream>
#include <cstdio>

namespace s_printf {

	class Str
	{
	private:
		std::string a;

	public:
		Str(const Str&) = delete;
		void operator=(const Str&) = delete;

		Str()
		{
			printf("Memory Address = %p \n", this);
			std::cout << "생성자 호출!" << std::endl;
		}
		~Str()
		{
			printf("Memory Address = %p \n", this);
			std::cout << "소멸자 호출!" << std::endl;
		}

		static Str& GetInstance()
		{
			static Str s_Instance;
			return (s_Instance);
		}

		std::string printf_() { return a; }
		void Setshow(std::string str = "Test") { a = str; }
	};
}
