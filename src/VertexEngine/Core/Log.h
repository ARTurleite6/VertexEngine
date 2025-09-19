#pragma once

#include <spdlog/spdlog.h>

namespace VertexEngine
{
	class Log final
	{
	public:
		static void Init();
		static std::shared_ptr<spdlog::logger> GetCoreLogger()
		{
			return s_CoreLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};
}

#define VE_CORE_TRACE(...) ::VertexEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VE_CORE_DEBUG(...) ::VertexEngine::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define VE_CORE_INFO(...) ::VertexEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VE_CORE_WARN(...) ::VertexEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VE_CORE_ERROR(...) ::VertexEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
