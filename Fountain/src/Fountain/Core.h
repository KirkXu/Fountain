#pragma once

#ifdef FT_PLATFORM_WINDOWS

	#ifdef FT_BUILD_DLL
		#define FOUNTAIN_API __declspec(dllexport)
	#else
		#define FOUNTAIN_API __declspec(dllimport)
	#endif
#else
	#error FOUNTAIN only supports Windows!
#endif

