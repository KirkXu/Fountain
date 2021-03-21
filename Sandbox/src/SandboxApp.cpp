#include <Fountain.h>

class Sandbox : public Fountain::Application
{
public:
	Sandbox()
	{
		
	}
	
	~Sandbox()
	{

	}
};

Fountain::Application* Fountain::CreateApplication()
{
	return new Sandbox();
}