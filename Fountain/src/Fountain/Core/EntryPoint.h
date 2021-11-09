#pragma once
#include "Fountain/Core/Base.h"
#include "Fountain/Core/Application.h"

#ifdef FT_PLATFORM_WINDOWS

extern Fountain::Application* Fountain::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Fountain::Log::Init();

	FT_PROFILE_BEGIN_SESSION("Startup", "FountainProfile-Startup.json"); 
	auto app = Fountain::CreateApplication({ argc, argv });
	FT_PROFILE_END_SESSION();
	
	FT_PROFILE_BEGIN_SESSION("Runtime", "FountainProfile-Runtime.json");
	app->Run();
	FT_PROFILE_END_SESSION();

	FT_PROFILE_BEGIN_SESSION("Shutdown", "FountainProfile-Shutdown.json");
	delete app;
	FT_PROFILE_END_SESSION();

}

#endif
