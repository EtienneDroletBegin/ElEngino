#include "SpriteRenderer.h"
#include "Engine.h"

using namespace engino;

void SpriteRenderer::Init()
{
	m_spriteID = Engine::Get()->gfx().LoadTexture("assets/Gorgo.png");
}


void SpriteRenderer::Draw()
{
	Engine::Get()->gfx().DrawSprite(m_Entity->GetX(), m_Entity->GetY(), 696, 564, 0, m_spriteID);

}
