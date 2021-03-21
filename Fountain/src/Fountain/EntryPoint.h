#pragma once

#ifdef FT_PLATFORM_WINDOWS

extern Fountain::Application* Fountain::CreateApplication();

int main(int argc, char** argv)
{
	Fountain::Log::Init();
	FT_CORE_WARN("Initialized Log!");
	FT_INFO("Hello!");
	int a = 5;
	FT_INFO("Hello! Var={0}", a);

	auto app = Fountain::CreateApplication();
	app->Run();
	delete app;

}

#endif
