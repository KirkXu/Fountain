#include <Fountain.h>

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
		PushOverlay(new Fountain::ImGuiLayer());
	}
	
	~Sandbox()
	{

	}
};

Fountain::Application* Fountain::CreateApplication()
{
	return new Sandbox();
}