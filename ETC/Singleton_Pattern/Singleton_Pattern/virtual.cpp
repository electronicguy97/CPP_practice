#include "virtual.h"

namespace s_printf {

	class Str final : public SuperStr
	{
	private:
		std::string a;

	public:
		Str(const Str&) = delete;
		void operator=(const Str&) = delete;

		Str()
		{
			printf("Memory Address = %p \n", this);
			std::cout << "������ ȣ��!" << std::endl;
		}
		~Str()
		{
			printf("Memory Address = %p \n", this);
			std::cout << "�Ҹ��� ȣ��!" << std::endl;
		}

		virtual inline std::string printf_()					{ return a; }
		virtual inline void Setshow(std::string str = "Test")	{ a = str; }
	};

	std::shared_ptr<SuperStr> SuperStr::s_instance = nullptr;

	std::shared_ptr<SuperStr> s_printf::SuperStr::GetInstance()
	{
		if (s_instance == nullptr)
			s_instance = std::make_shared<Str>();
		return (s_instance);
	}

}