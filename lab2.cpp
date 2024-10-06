#include <iostream>
#include <iomanip>
#include <io.h>
#include <fcntl.h>
#include <cmath>
static bool isprime(int n)
{
	if (n == 1)
	{
		return 0;
	}
	if (n % 2 == 0 && n != 2)
	{
		return 0;
	}
	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int wmain(int argc, wchar_t* argv[])
{
	_setmode(_fileno(stdout), _O_U8TEXT);
	_setmode(_fileno(stdin), _O_U8TEXT);
	_setmode(_fileno(stderr), _O_U8TEXT);
	bool autoui = true;
	if (argc <= 1 || std::wcsncmp(argv[1], L"false", sizeof(L"false") - 1) != 0)
	{
		autoui = false;
	}
	int i = 0;
	int x = -1;
	int sum_all = 0;
	int mn = INT32_MAX, mx = INT32_MIN;
	int cnt_div_5 = 0;
	int cnt_power_2 = 0;
	int cnt_max_of_3 = 0;
	int prev = 0, pprev = 0;
	int n;
	if (!autoui)
	{
		std::wcout << L"Введите длину последовательности N:";
	}
	std::wcin >> n;
	for (i = 0; i < n; i++)
	{
		if (!autoui)
		{
			std::wcout << L"Введите X" << i << L":";
		}
		std::wcin >> x;
		std::wcout << std::pow(x, n - i) << '\n';
		if (isprime(x))
		{
			std::wcout << x;
			if (!autoui)
			{
				std::wcout << L" является простым числом";
			}
			std::wcout  <<'\n';
		}
		sum_all += x;
		if (x < mn)
		{
			mn = x;
		}
		if (x > mx)
		{
			mx = x;
		}
		if (x % 5 == 0)
		{
			cnt_div_5 += 1;
		}
		if (x > 0 && (x & (x - 1)) == 0)
		{
			cnt_power_2 += 1;
		}
		if (i > 1 && x > (prev + pprev))
		{
			cnt_max_of_3 += 1;
		}
		pprev = prev;
		prev = x;
	}
	if (autoui)
	{
		std::wcout << std::fixed << std::setprecision(2) << ((double)sum_all / n) << '\n';
		std::wcout << mx - mn << '\n';
		std::wcout << cnt_div_5 << '\n';
		std::wcout << cnt_power_2 << '\n';
		std::wcout << cnt_max_of_3 << '\n';
	}
	else
	{
		std::wcout << L"Среднее значение последовательности:" << std::fixed << std::setprecision(2) << ((double)sum_all / n)  << '\n';
		std::wcout << L"Размах последовательности (разница Xmin и Xmax):" << mx - mn << '\n';
		std::wcout << L"Количество элементов последовательности, кратных числу 5:" << cnt_div_5 << '\n';
		std::wcout << L"Количество элементов последовательности, являющихся степенью двойки:" << cnt_power_2 << '\n';
		std::wcout << L"Количество элементов последовательности, превышающих сумму двух предшествующих:" << cnt_max_of_3 << '\n';
	}
}