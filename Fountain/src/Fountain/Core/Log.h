#pragma once


#include "Fountain/Core/Base.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Fountain {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternio)
{
	return os << glm::to_string(quaternio);
}

// Core log marcos
#define FT_CORE_TRACE(...)     ::Fountain::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FT_CORE_INFO(...)      ::Fountain::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FT_CORE_WARN(...)      ::Fountain::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FT_CORE_ERROR(...)     ::Fountain::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FT_CORE_FATAL(...)     ::Fountain::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log marcos
#define FT_TRACE(...)          ::Fountain::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FT_INFO(...)           ::Fountain::Log::GetClientLogger()->info(__VA_ARGS__)
#define FT_WARN(...)           ::Fountain::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FT_ERROR(...)          ::Fountain::Log::GetClientLogger()->error(__VA_ARGS__)
#define FT_FATAL(...)          ::Fountain::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define FT_CRITICAL(...)       ::Fountain::Log::GetClientLogger()->critical(__VA_ARGS__)
