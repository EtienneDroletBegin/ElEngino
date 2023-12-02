#pragma once
#include "SpriteRenderer.h"
#include "Engine.h"

using namespace engino;

/// <summary>
/// Initialises the File ID when the component is created
/// </summary>
/// <param name="filename">the file's path from /deployment</param>
void SpriteRenderer::Init(std::string filename, float _w, float _h)
{
	m_spriteID = Engine::Get()->gfx().LoadTexture(filename);
	m_w = _w;
	m_h = _h;
}


void SpriteRenderer::Draw()
{
	Engine::Get()->gfx().DrawSprite(m_Entity->GetX(), m_Entity->GetY(), m_w, m_h, 0, m_spriteID);

}

