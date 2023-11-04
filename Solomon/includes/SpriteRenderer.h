#include "Component.h"
#include "IUpdatable.h"
#include "IDrawable.h"


namespace engino {
	class SpriteRenderer : public Component, public IDrawable
	{
	public:
		void Init();
		SpriteRenderer(Entity* parent):Component(parent) {
			Init();
		}
		SpriteRenderer() = default;
		~SpriteRenderer()= default;
		virtual void Draw() override;


	private:
		const char* filename;
		size_t m_spriteID;
	};

}