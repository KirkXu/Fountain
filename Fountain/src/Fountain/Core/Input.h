#pragma once

#include "Fountain/Core/Base.h"
#include "Fountain/Core/KeyCodes.h"
#include "Fountain/Core/MouseCodes.h"

namespace Fountain {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
