#include <iostream>
#include <string>
#include "virtual.h"

int main()
{	
	using namespace s_printf;
	auto str1 = SuperStr::GetInstance();
	auto str2 = SuperStr::GetInstance();
	auto str3 = SuperStr::GetInstance();
	str1->Setshow();
	str2->Setshow();
}
