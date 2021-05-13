#include <Fountain.h>

#include "imgui/imgui.h"

class ExampleLayer : public Fountain::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{

		if (Fountain::Input::IsKeyPressed(FT_KEY_TAB))
			FT_TRACE("Tab key is pressed (poll)!");

	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Fountain::Event& event) override
	{
		if (event.GetEventType() == Fountain::EventType::KeyPressed)
		{
			Fountain::KeyPressedEvent& e = (Fountain::KeyPressedEvent&)event;
			if (e.GetKeyCode() == FT_KEY_TAB)
				FT_TRACE("Tab key is pressed (event)!");
			FT_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public Fountain::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	
	~Sandbox()
	{

	}
};

Fountain::Application* Fountain::CreateApplication()
{
	return new Sandbox();
}