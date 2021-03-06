#pragma once

#include <memory>

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

namespace Fountain {
	
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}