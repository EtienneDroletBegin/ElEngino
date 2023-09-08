#include "iInput.h"
namespace engino {
class SdlInput final : public IInput
{
public:
	virtual ~SdlInput() = default;
	virtual bool IsKeyDown(int keycode) override;
	virtual bool IsButtonDown(int button) override;
	virtual void GetMousePosition(int* x, int* y) override;
	bool quit = false;
	virtual bool _quit() override { return quit; } ;
	const unsigned char* _KeyStates() { return m_KeyStates; }
	
private:
	const unsigned char* m_KeyStates = nullptr;
	int m_MouseX = 0;
	int m_MouseY = 0;
	bool m_MouseStates[3]{ false, false, false };
protected:
	virtual void Update() override;
};

}
