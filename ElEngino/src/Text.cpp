#include "Text.h"
#include "Engine.h"

void engino::Text::Init(std::string filename, std::string text, int size)
{
	m_scale = size;
	m_text = text;
	m_fontId = Engine::Get()->gfx().LoadFont(filename, 30);
}

void engino::Text::Draw()
{
	
	Engine::Get()->gfx().DrawFont(m_Entity->GetX(), m_Entity->GetY(), 0,0, m_fontId, m_text, Color::RED, m_scale);

}

void engino::Text::SetText(std::string _text)
{
	m_text = _text;
}
