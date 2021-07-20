#pragma once

namespace Fountain
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define FT_KEY_SPACE           ::Fountain::Key::Space
#define FT_KEY_APOSTROPHE      ::Fountain::Key::Apostrophe    /* ' */
#define FT_KEY_COMMA           ::Fountain::Key::Comma         /* , */
#define FT_KEY_MINUS           ::Fountain::Key::Minus         /* - */
#define FT_KEY_PERIOD          ::Fountain::Key::Period        /* . */
#define FT_KEY_SLASH           ::Fountain::Key::Slash         /* / */
#define FT_KEY_0               ::Fountain::Key::D0
#define FT_KEY_1               ::Fountain::Key::D1
#define FT_KEY_2               ::Fountain::Key::D2
#define FT_KEY_3               ::Fountain::Key::D3
#define FT_KEY_4               ::Fountain::Key::D4
#define FT_KEY_5               ::Fountain::Key::D5
#define FT_KEY_6               ::Fountain::Key::D6
#define FT_KEY_7               ::Fountain::Key::D7
#define FT_KEY_8               ::Fountain::Key::D8
#define FT_KEY_9               ::Fountain::Key::D9
#define FT_KEY_SEMICOLON       ::Fountain::Key::Semicolon     /* ; */
#define FT_KEY_EQUAL           ::Fountain::Key::Equal         /* = */
#define FT_KEY_A               ::Fountain::Key::A
#define FT_KEY_B               ::Fountain::Key::B
#define FT_KEY_C               ::Fountain::Key::C
#define FT_KEY_D               ::Fountain::Key::D
#define FT_KEY_E               ::Fountain::Key::E
#define FT_KEY_F               ::Fountain::Key::F
#define FT_KEY_G               ::Fountain::Key::G
#define FT_KEY_H               ::Fountain::Key::H
#define FT_KEY_I               ::Fountain::Key::I
#define FT_KEY_J               ::Fountain::Key::J
#define FT_KEY_K               ::Fountain::Key::K
#define FT_KEY_L               ::Fountain::Key::L
#define FT_KEY_M               ::Fountain::Key::M
#define FT_KEY_N               ::Fountain::Key::N
#define FT_KEY_O               ::Fountain::Key::O
#define FT_KEY_P               ::Fountain::Key::P
#define FT_KEY_Q               ::Fountain::Key::Q
#define FT_KEY_R               ::Fountain::Key::R
#define FT_KEY_S               ::Fountain::Key::S
#define FT_KEY_T               ::Fountain::Key::T
#define FT_KEY_U               ::Fountain::Key::U
#define FT_KEY_V               ::Fountain::Key::V
#define FT_KEY_W               ::Fountain::Key::W
#define FT_KEY_X               ::Fountain::Key::X
#define FT_KEY_Y               ::Fountain::Key::Y
#define FT_KEY_Z               ::Fountain::Key::Z
#define FT_KEY_LEFT_BRACKET    ::Fountain::Key::LeftBracket   /* [ */
#define FT_KEY_BACKSLASH       ::Fountain::Key::Backslash     /* \ */
#define FT_KEY_RIGHT_BRACKET   ::Fountain::Key::RightBracket  /* ] */
#define FT_KEY_GRAVE_ACCENT    ::Fountain::Key::GraveAccent   /* ` */
#define FT_KEY_WORLD_1         ::Fountain::Key::World1        /* non-US #1 */
#define FT_KEY_WORLD_2         ::Fountain::Key::World2        /* non-US #2 */

/* Function keys */
#define FT_KEY_ESCAPE          ::Fountain::Key::Escape
#define FT_KEY_ENTER           ::Fountain::Key::Enter
#define FT_KEY_TAB             ::Fountain::Key::Tab
#define FT_KEY_BACKSPACE       ::Fountain::Key::Backspace
#define FT_KEY_INSERT          ::Fountain::Key::Insert
#define FT_KEY_DELETE          ::Fountain::Key::Delete
#define FT_KEY_RIGHT           ::Fountain::Key::Right
#define FT_KEY_LEFT            ::Fountain::Key::Left
#define FT_KEY_DOWN            ::Fountain::Key::Down
#define FT_KEY_UP              ::Fountain::Key::Up
#define FT_KEY_PAGE_UP         ::Fountain::Key::PageUp
#define FT_KEY_PAGE_DOWN       ::Fountain::Key::PageDown
#define FT_KEY_HOME            ::Fountain::Key::Home
#define FT_KEY_END             ::Fountain::Key::End
#define FT_KEY_CAPS_LOCK       ::Fountain::Key::CapsLock
#define FT_KEY_SCROLL_LOCK     ::Fountain::Key::ScrollLock
#define FT_KEY_NUM_LOCK        ::Fountain::Key::NumLock
#define FT_KEY_PRINT_SCREEN    ::Fountain::Key::PrintScreen
#define FT_KEY_PAUSE           ::Fountain::Key::Pause
#define FT_KEY_F1              ::Fountain::Key::F1
#define FT_KEY_F2              ::Fountain::Key::F2
#define FT_KEY_F3              ::Fountain::Key::F3
#define FT_KEY_F4              ::Fountain::Key::F4
#define FT_KEY_F5              ::Fountain::Key::F5
#define FT_KEY_F6              ::Fountain::Key::F6
#define FT_KEY_F7              ::Fountain::Key::F7
#define FT_KEY_F8              ::Fountain::Key::F8
#define FT_KEY_F9              ::Fountain::Key::F9
#define FT_KEY_F10             ::Fountain::Key::F10
#define FT_KEY_F11             ::Fountain::Key::F11
#define FT_KEY_F12             ::Fountain::Key::F12
#define FT_KEY_F13             ::Fountain::Key::F13
#define FT_KEY_F14             ::Fountain::Key::F14
#define FT_KEY_F15             ::Fountain::Key::F15
#define FT_KEY_F16             ::Fountain::Key::F16
#define FT_KEY_F17             ::Fountain::Key::F17
#define FT_KEY_F18             ::Fountain::Key::F18
#define FT_KEY_F19             ::Fountain::Key::F19
#define FT_KEY_F20             ::Fountain::Key::F20
#define FT_KEY_F21             ::Fountain::Key::F21
#define FT_KEY_F22             ::Fountain::Key::F22
#define FT_KEY_F23             ::Fountain::Key::F23
#define FT_KEY_F24             ::Fountain::Key::F24
#define FT_KEY_F25             ::Fountain::Key::F25

/* Keypad */
#define FT_KEY_KP_0            ::Fountain::Key::KP0
#define FT_KEY_KP_1            ::Fountain::Key::KP1
#define FT_KEY_KP_2            ::Fountain::Key::KP2
#define FT_KEY_KP_3            ::Fountain::Key::KP3
#define FT_KEY_KP_4            ::Fountain::Key::KP4
#define FT_KEY_KP_5            ::Fountain::Key::KP5
#define FT_KEY_KP_6            ::Fountain::Key::KP6
#define FT_KEY_KP_7            ::Fountain::Key::KP7
#define FT_KEY_KP_8            ::Fountain::Key::KP8
#define FT_KEY_KP_9            ::Fountain::Key::KP9
#define FT_KEY_KP_DECIMAL      ::Fountain::Key::KPDecimal
#define FT_KEY_KP_DIVIDE       ::Fountain::Key::KPDivide
#define FT_KEY_KP_MULTIPLY     ::Fountain::Key::KPMultiply
#define FT_KEY_KP_SUBTRACT     ::Fountain::Key::KPSubtract
#define FT_KEY_KP_ADD          ::Fountain::Key::KPAdd
#define FT_KEY_KP_ENTER        ::Fountain::Key::KPEnter
#define FT_KEY_KP_EQUAL        ::Fountain::Key::KPEqual

#define FT_KEY_LEFT_SHIFT      ::Fountain::Key::LeftShift
#define FT_KEY_LEFT_CONTROL    ::Fountain::Key::LeftControl
#define FT_KEY_LEFT_ALT        ::Fountain::Key::LeftAlt
#define FT_KEY_LEFT_SUPER      ::Fountain::Key::LeftSuper
#define FT_KEY_RIGHT_SHIFT     ::Fountain::Key::RightShift
#define FT_KEY_RIGHT_CONTROL   ::Fountain::Key::RightControl
#define FT_KEY_RIGHT_ALT       ::Fountain::Key::RightAlt
#define FT_KEY_RIGHT_SUPER     ::Fountain::Key::RightSuper
#define FT_KEY_MENU            ::Fountain::Key::Menu