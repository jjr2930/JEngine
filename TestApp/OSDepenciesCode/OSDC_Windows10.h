#if __WINDOWS_10__
#pragma once
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <thread>

using namespace std;

namespace JSample
{
	class OSDC	//Operating System Dependency Codes
	{
	public:
		static LARGE_INTEGER GetFrequency()
		{
			LARGE_INTEGER counter;
			if (!QueryPerformanceFrequency(&counter))
			{
				wcout << L"Do not supported QueryPerformanceFrequency";
				throw;
			}

			return counter;
		}

		static LARGE_INTEGER GetTickCount()
		{
			LARGE_INTEGER counter;
			if (!QueryPerformanceCounter(&counter))
			{
				wcout << L"do not support QueryPerformanceCounter" << endl;
				throw;
			}
			return counter;
		}

		static float GetTickTime()
		{
			return GetTickCount().QuadPart / (float)(GetFrequency().QuadPart);
		}

		static void Sleep(int milisecond) 
		{
			::Sleep(milisecond);
		}

		static uint32_t GetNumberOfThread()
		{
			return std::thread::hardware_concurrency();
		}
	};
}
#endif	