#pragma once

#ifdef CREATEDLL_EXPORTS
#define MYMATH_DECLSPEC __declspec(dllexport) // dll외부로 노출-> __declspec(dllexport)키워드가 붙은 함수를 호출 가능
#else
#define MYMATH_DECLSPEC __declspec(dllimport) // DLL에 정의된 함수를 호출 -> __declspec(dllexport) 정의된 함수를 호출
#endif


// extern "C" -> 맹글링을 하지 않겠다는 것 즉, 링커가 헷갈리지 않게 오버로딩이라고 알려주는 것?
extern "C" MYMATH_DECLSPEC double Sum(double a, double b);
extern "C" MYMATH_DECLSPEC double Sub(double a, double b);
extern "C" MYMATH_DECLSPEC double Mul(double a, double b);
extern "C" MYMATH_DECLSPEC double Div(double a, double b);
