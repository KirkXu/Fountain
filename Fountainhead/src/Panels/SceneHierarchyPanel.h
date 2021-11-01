#pragma once

#include "Fountain/Core/Base.h"
#include "Fountain/Core/Log.h"
#include "Fountain/Scene/Scene.h"
#include "Fountain/Scene/Entity.h"

namespace Fountain {

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& scene);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};
}
