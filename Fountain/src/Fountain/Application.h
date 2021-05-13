#pragma once

#include "Core.h"

#include "Window.h"
#include "Fountain/LayerStack.h"
#include "Fountain/Events/Event.h"
#include "Fountain/Events/ApplicationEvent.h"

#include "Fountain/ImGui/ImGuiLayer.h"

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

		inline Window& GetWindow() { return *m_Winodow; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		ImGuiLayer* m_ImGuiLayer;
		std::unique_ptr<Window> m_Winodow;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
