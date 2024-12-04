#pragma once
#include <iostream>
#include <cstdio>

namespace s_printf {

	class SuperStr
	{
	private:
		static std::shared_ptr<SuperStr> s_instance;

	public:
		static std::shared_ptr<SuperStr> GetInstance();

		virtual inline std::string printf_() = 0;
		virtual inline void Setshow(std::string str = "Test") = 0;
	};
}
