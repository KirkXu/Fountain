#pragma once

#include "Fountain/Layer.h"

#include "Fountain/Events/ApplicationEvent.h"
#include "Fountain/Events/KeyEvent.h"
#include "Fountain/Events/MouseEvent.h"

namespace Fountain {
	
	class FOUNTAIN_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}
