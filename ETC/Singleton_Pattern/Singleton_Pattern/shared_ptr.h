#pragma once
#include <iostream>

namespace s_printf {

	class Str 
	{
	private:
		static std::shared_ptr<Str> s_Instance;
		std::string a;
		
	public:
		Str()
		{
			std::cout << "������ ȣ��!" << std::endl;
		}
		~Str()
		{
			std::cout << "�Ҹ��� ȣ��!" << std::endl;
		}


		static std::shared_ptr<Str> GetInstance() 
		{
			if (s_Instance == nullptr) 
			{
				s_Instance = std::make_shared<Str>();
			}
			return (s_Instance);
		}

		std::string printf_() { return a; }
		void Setshow(std::string str = "Test") { a = str; }
	};

	std::shared_ptr<Str> Str::s_Instance = nullptr;
}
