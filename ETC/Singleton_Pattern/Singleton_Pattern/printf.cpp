#include <iostream>
#include "printf.h"

printf::Str::Str()
{
	int a;
	std::cin >> a;
}

printf::Str::~Str()
{
	if (s_Instance != nullptr)
		delete s_Instance;
}
