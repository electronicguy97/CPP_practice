#pragma once

#ifdef CREATEDLL_EXPORTS
#define MYMATH_DECLSPEC __declspec(dllexport) // dll�ܺη� ����-> __declspec(dllexport)Ű���尡 ���� �Լ��� ȣ�� ����
#else
#define MYMATH_DECLSPEC __declspec(dllimport) // DLL�� ���ǵ� �Լ��� ȣ�� -> __declspec(dllexport) ���ǵ� �Լ��� ȣ��
#endif


// extern "C" -> �ͱ۸��� ���� �ʰڴٴ� �� ��, ��Ŀ�� �򰥸��� �ʰ� �����ε��̶�� �˷��ִ� ��?
extern "C" MYMATH_DECLSPEC double Sum(double a, double b);
extern "C" MYMATH_DECLSPEC double Sub(double a, double b);
extern "C" MYMATH_DECLSPEC double Mul(double a, double b);
extern "C" MYMATH_DECLSPEC double Div(double a, double b);
