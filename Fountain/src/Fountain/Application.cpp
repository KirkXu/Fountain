#include "ftpch.h"
#include "Application.h"

#include "Fountain/Events/ApplicationEvent.h"
#include "Fountain/Log.h"

#include <GLFW/glfw3.h>

namespace Fountain {
	Application::Application()
	{
		m_Winodw = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Winodw->OnUpdate();
		}
	}
}
