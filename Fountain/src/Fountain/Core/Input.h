#pragma once

#include <glm/glm.hpp>

#include "Fountain/Core/KeyCodes.h"
#include "Fountain/Core/MouseCodes.h"

namespace Fountain {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
