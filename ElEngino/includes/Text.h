#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "IDrawable.h"


namespace engino {
	class Text : public Component, public IDrawable
	{
	public:
		void Init(const char* filename, const char* text, float size);
		virtual void Draw() override;
		Text(Entity* parent) :Component(parent) {

		}
		void SetText(const char* _text);
		Text() = default;
		~Text() = default;


	private:
		size_t m_fontId;
		const char* m_text;
		float m_size;
		float m_scale;
	};

}