#pragma once

#include "Base.h"

#include "Window.h"
#include "Fountain/Core/LayerStack.h"
#include "Fountain/Events/Event.h"
#include "Fountain/Events/ApplicationEvent.h"

#include "Fountain/Core/Timestep.h"

#include "Fountain/ImGui/ImGuiLayer.h"

namespace Fountain {

	class Application
	{
	public:
		Application(const std::string& name = "Fountain App");
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		ImGuiLayer* m_ImGuiLayer;
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
