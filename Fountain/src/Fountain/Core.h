#pragma once

#ifdef FT_PLATFORM_WINDOWS
#if HZ_DYNAMIC_LINK
	#ifdef FT_BUILD_DLL
		#define FOUNTAIN_API __declspec(dllexport)
	#else
		#define FOUNTAIN_API __declspec(dllimport)
	#endif
#else
	#define FOUNTAIN_API
#endif
#else
	#error Fountain  only supports Windows!
#endif

#ifdef FT_DEBUG
	#define FT_ENABLE_ASSERTS
#endif

#ifdef FT_ENABLE_ASSERTS
	#define FT_ASSERT(x, ...) { if(!(x)) {FT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define FT_CORE_ASSERT(x, ...) { if(!(x)) { FT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define FT_ASSERT(x, ...)
	#define FT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define FT_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)