#pragma once

#include "Fountain/Core/Core.h"
#include "Fountain/Core/Timestep.h"
#include "Fountain/Events/Event.h"

namespace Fountain {
	
	class FOUNTAIN_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}
