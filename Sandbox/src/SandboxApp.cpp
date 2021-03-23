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
		FT_INFO("ExampleLayer::Update");
	}

	void OnEvent(Fountain::Event& event) override
	{
		FT_TRACE("{0}", event);
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