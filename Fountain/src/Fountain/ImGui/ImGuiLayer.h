#pragma once

#include "Fountain/Core/Layer.h"

#include "Fountain/Events/ApplicationEvent.h"
#include "Fountain/Events/KeyEvent.h"
#include "Fountain/Events/MouseEvent.h"

namespace Fountain {
	
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
}
