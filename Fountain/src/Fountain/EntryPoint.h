#pragma once

#ifdef FT_PLATFORM_WINDOWS

extern Fountain::Application* Fountain::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Fountain::CreateApplication();
	app->Run();
	delete app;

}

#endif
