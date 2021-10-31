#pragma once

#include <memory>

#include "Fountain/Core/PlatformDetection.h"


#ifdef FT_DEBUG
#if defined(FT_PLATFORM_WINDOWS)
#define FT_DEBUGBREAK() __debugbreak()
#elif defined(FT_PLATFORM_LINUX)
#include <signal.h>
#define FT_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define FT_ENABLE_ASSERTS
#else
#define FT_DEBUGBREAK()
#endif

// TODO: Make this macro able to take in no arguments except condition
#ifdef FT_ENABLE_ASSERTS
#define FT_ASSERT(x, ...) { if(!(x)) { FT_ERROR("Assertion Failed: {0}", __VA_ARGS__); FT_DEBUGBREAK(); } }
#define FT_CORE_ASSERT(x, ...) { if(!(x)) { FT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); FT_DEBUGBREAK(); } }
#else
#define FT_ASSERT(x, ...)
#define FT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define FT_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) {return this->fn(std::forward<decltype(args)>(args)...);}

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