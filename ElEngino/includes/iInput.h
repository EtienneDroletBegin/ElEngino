#pragma once
namespace engino {
	enum EKeycodes {
		KEY_A,
		KEY_D,
		KEY_S,
		KEY_W,
		Key_Esc,
		Key_Space,
		Key_R,
		Key_T,
		Key_Y
	};
class IInput
{
public:
	virtual ~IInput() = default;

	virtual bool IsKeyDown(int key) = 0;
	virtual bool IsButtonDown(int button) = 0;
	virtual void GetMousePosition(int* x, int* y) = 0;
	virtual bool _quit() = 0;


protected:
	friend class Engine;
	virtual void Update() = 0;
};

}

