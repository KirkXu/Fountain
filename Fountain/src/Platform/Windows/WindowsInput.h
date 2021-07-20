#pragma once

#include "Fountain/Core/Input.h"

namespace Fountain {

	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(KeyCode key) override;

		virtual bool IsMouseButtonPressedImpl(MouseCode button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float IsMouseXImpl() override;
		virtual float IsMouseYImpl() override;
	};
}
