#include <Fountain.h>
#include <Fountain/Core/EntryPoint.h>

#include "Sandbox2D.h"

#include "ExampleLayer.h"

class Sandbox : public Fountain::Application
{
public:
	Sandbox()
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}
	
	~Sandbox()
	{

	}
};

Fountain::Application* Fountain::CreateApplication()
{
	return new Sandbox();
}