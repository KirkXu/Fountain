#include <Fountain.h>
#include <Fountain/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Fountain {

	class Fountainhead : public Application
	{
	public:
		Fountainhead()
			: Application("Fountainhead")
		{
			PushLayer(new EditorLayer());
		}

		~Fountainhead()
		{
		}
	};

	Application* CreateApplication()
	{
		return new Fountainhead();
	}

}