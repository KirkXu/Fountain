#pragma once

#include "Fountain/Core/Base.h"
#include "Fountain/Core/KeyCodes.h"
#include "Fountain/Core/MouseCodes.h"

namespace Fountain {

	class Input
	{
	protected:
		Input() = default;
	public:
		Input(const Input&) = delete;
		Input& operator=(const Input&) = delete;

		inline static bool IsKeyPressed(KeyCode key) { return s_Instance->IsKeyPressedImpl(key); }

		inline static bool IsMouseButtonPressed(MouseCode button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		inline static float IsMouseX() { return s_Instance->IsMouseXImpl(); }
		inline static float IsMouseY() { return s_Instance->IsMouseYImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(KeyCode keycode) = 0;

		virtual bool IsMouseButtonPressedImpl(MouseCode button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float IsMouseXImpl() = 0;
		virtual float IsMouseYImpl() = 0;
	private:
		static Input* s_Instance;
	};
}
