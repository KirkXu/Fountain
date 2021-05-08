#pragma once

#include "Fountain/Input.h"

namespace Fountain {

	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float IsMouseXImpl() override;
		virtual float IsMouseYImpl() override;
	};
}
