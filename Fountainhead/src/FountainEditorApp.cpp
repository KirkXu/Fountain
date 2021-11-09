#include <Fountain.h>
#include <Fountain/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Fountain {

	class Fountainhead : public Application
	{
	public:
		Fountainhead(ApplicationCommandLineArgs args)
			: Application("Fountainhead", args)
		{
			PushLayer(new EditorLayer());
		}

		~Fountainhead()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new Fountainhead(args);
	}

}
