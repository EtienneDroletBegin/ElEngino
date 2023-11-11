#pragma once
#include "SpriteRenderer.h"
#include "Engine.h"

using namespace engino;

/// <summary>
/// Initialises the File ID when the component is created
/// </summary>
/// <param name="filename">the file's path from /deployment</param>
void SpriteRenderer::Init(const char* filename)
{
	m_spriteID = Engine::Get()->gfx().LoadTexture(filename);
}


void SpriteRenderer::Draw()
{
	Engine::Get()->gfx().DrawSprite(m_Entity->GetX(), m_Entity->GetY(), 696, 564, 0, m_spriteID);

}

