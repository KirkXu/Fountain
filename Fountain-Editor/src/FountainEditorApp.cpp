#include <Fountain.h>
#include <Fountain/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Fountain {

	class FountainEditor : public Application
	{
	public:
		FountainEditor()
			: Application("Fountain Editor")
		{
			PushLayer(new EditorLayer());
		}

		~FountainEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new FountainEditor();
	}

}