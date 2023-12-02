#pragma once
namespace engino {
	/// <summary>
	/// more pleasant keycodes to use, make sure to have them in the same order as the list in SDL_Input
	/// </summary>
	enum EKeycodes {
		KEY_A,
		KEY_D,
		KEY_S,
		KEY_W,
		Key_Esc,
		Key_Space,
		Key_Enter,
		Key_R,
		Key_T,
		Key_Y
	};
class IInput
{
public:
	virtual ~IInput() = default;
	/// <summary>
	/// returns whether a given key is pressed
	/// </summary>
	/// <param name="key">the key to check</param>
	/// <returns>whether the key is pressed</returns>
	virtual bool IsKeyDown(int key) = 0;
	/// <summary>
	/// returns whether a mouse btyn is pressed
	/// </summary>
	/// <param name="button">the mouse button</param>
	/// <returns>whether the button is pressed</returns>
	virtual bool IsButtonDown(int button) = 0;
	/// <summary>
	/// returns the mouse X and Y coordinates
	/// </summary>
	/// <param name="x">the mouse X</param>
	/// <param name="y">the mouse Y</param>
	virtual void GetMousePosition(int* x, int* y) = 0;
	/// <summary>
	/// destroys the pointers to avoid memory leaks
	/// </summary>
	/// <returns></returns>
	virtual bool _quit() = 0;


protected:
	friend class Engine;
	virtual void Update() = 0;
};

}

