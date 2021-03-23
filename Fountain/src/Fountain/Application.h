#pragma once

#include "Core.h"

#include "Window.h"
#include "Fountain/LayerStack.h"
#include "Fountain/Events/Event.h"
#include "Fountain/Events/ApplicationEvent.h"

namespace Fountain {

	class FOUNTAIN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Winodw;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
