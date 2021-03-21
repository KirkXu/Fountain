#pragma once
#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Fountain {

	class FOUNTAIN_API Log
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
