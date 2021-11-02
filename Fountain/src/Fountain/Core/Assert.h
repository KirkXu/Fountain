#pragma once

#include "Fountain/Core/Base.h"
#include "Fountain/Core/Log.h"
#include <filesystem>

#ifdef FT_ENABLE_ASSERTS
	
	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define FT_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { FT##type##ERROR(msg, __VA_ARGS__); FT_DEBUGBREAK(); } }
	#define FT_INTERNAL_ASSERT_WITH_MSG(type, check, ...) FT_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define FT_INTERNAL_ASSERT_NO_MSG(type, check) FT_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", FT_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)
	
	#define FT_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define FT_INTERNAL_ASSERT_GET_MACRO(...) FT_EXPAND_MACRO( FT_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, FT_INTERNAL_ASSERT_WITH_MSG, FT_INTERNAL_ASSERT_NO_MSG) )
	
	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define FT_ASSERT(...) FT_EXPAND_MACRO( FT_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define FT_CORE_ASSERT(...) FT_EXPAND_MACRO( FT_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define FT_ASSERT(...)
	#define FT_CORE_ASSERT(...)
#endif
