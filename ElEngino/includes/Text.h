#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "IDrawable.h"


namespace engino {
	class Text : public Component, public IDrawable
	{
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="filename"></param>
		/// <param name="text"></param>
		/// <param name="size"></param>
		void Init(std::string filename, std::string text, int size);
		virtual void Draw() override;
		Text(Entity* parent) :Component(parent) {

		}
		/// <summary>
		/// changed the text to be displayed
		/// </summary>
		/// <param name="_text"></param>
		void SetText(std::string _text);
		Text() = default;
		~Text() = default;


	protected:
		size_t m_fontId;
		std::string m_text;
		float m_size;
		int m_scale;
	};

}