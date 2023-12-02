#include "Tilemap.h"
#include <Engine.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "BoxCollider.h"


engino::Tilemap::Tilemap() : Tilemap(nullptr)
{
}


engino::Tilemap::Tilemap(Entity* parent) : Component(parent)
{
}

void engino::Tilemap::Draw()
{
    for (auto layer : m_Tilemap)
    {
        for (int y = 0; y < m_Height/m_TileHeight; y++)
        {
            for (int x = 0; x < m_Width/m_TileWidth; x++)
            {
                int _idx = layer.second[y][x];

                if (_idx > 0)
                {
                    _idx -= 1;
                    int _w = m_TileWidth;
                    int _h = m_TileHeight;
                    RectF _dst = {
                        static_cast<float>(x * _w),
                        static_cast<float>(y * _h),
                        static_cast<float>(_w),
                        static_cast<float>(_h)
                    };
                    engino::Engine::Get()->gfx().DrawSprite(m_Tileset[_idx+1], _dst, 0, Flip(), 
                        Color(255, 255, 255, 255),m_tileSetID);
                }
            }
        }
    }
}

void engino::Tilemap::Load(std::string filename, int mapW, int mapH, int tileW, int tileH)
{
    auto& graphics = engino::Engine::Get()->gfx();
    m_tileSetID = graphics.LoadTexture(filename);
    m_TileWidth = tileW;
    m_TileHeight = tileH;
    m_Width = mapW;
    m_Height = mapH;
    int _w, _h;
    graphics.GetTextureSize(&_w, &_h, m_tileSetID);

    int _tilePerRow = _w / m_TileWidth;
    int _tilePerCol = _h / m_TileHeight;
    int _tileCount = _tilePerRow * _tilePerCol;

    for (int i = 0; i < _tileCount; i++)
    {
        int _ty = i / _tilePerRow;
        int _tx = i - _ty * _tilePerRow;

        RectI _tile = {
            _tx * m_TileWidth,
            _ty * m_TileHeight,
            m_TileWidth,
            m_TileHeight
        };
        m_Tileset.push_back(_tile);
    }
    m_Width = mapW * m_ScaleFactor;
    m_Height = mapH * m_ScaleFactor;
    m_TileWidth = tileW *m_ScaleFactor;
    m_TileHeight = tileH * m_ScaleFactor;
}

void engino::Tilemap::AddLayer(std::string layer, TLayer tiles)
{
    if (m_Tilemap.count(layer) == 0)
    {
        m_Tilemap.emplace(layer, tiles);
    }
}

engino::TLayer engino::Tilemap::GetLayer(std::string name)
{
    if (m_Tilemap.count(name) > 0)
    {
        return m_Tilemap[name];
    }

    return TLayer{};
}

void engino::Tilemap::ReadCSV(std::string filename, std::string layername)
{
    TLayer layer = TLayer();
    std::ifstream file(filename);
    std::string line;
    std::string val;
    int index = 0;
    while (std::getline(file, line))
    {
        layer.push_back(vector<int>());
        std::stringstream ss(line);
        while (std::getline(ss, val,','))
        {
            layer[index].push_back(stoi(val));
        } 
        index++;
    }

    AddLayer(layername, layer);
}


bool engino::Tilemap::IsColliding(std::string layer, Entity* _entity, int* tileIndex, int* dir)
{   
    float x = _entity->GetX();
    float y = _entity->GetY();
    float w = _entity->GetComponent<BoxCollider>()->getW();
    float h = _entity->GetComponent<BoxCollider>()->getH();
    int tileW = m_Width / m_TileWidth;
    int tileH = m_Height / m_TileHeight;
    const int tLeftTile = Clamp(static_cast<int>( x/ m_TileWidth), 0, tileW);
    const int tRightTile = Clamp(static_cast<int>((x + w) / m_TileWidth), 0, tileW);
    const int tTopTile = Clamp(static_cast<int>(y / m_TileHeight), 0, tileH );
    const int tBottomTile = Clamp(static_cast<int>((y + h) / m_TileHeight), 0, tileH);

    for (int i = tLeftTile; i <= tRightTile; i++)
    {
        for (int j = tTopTile; j <= tBottomTile; j++)
        {
            int tileX = i * m_TileWidth;
            int tileY = j * m_TileHeight;
            if (tileX < m_Width  && tileY < m_Height )
            {
                if (m_Tilemap[layer][j][i] >= 0)
                {
                    *tileIndex = m_Tilemap[layer][j][i];

                    float entityT = y;
                    float entityB = y+h;
                    float entityL = x;
                    float entityR = x + w;
                    if (entityB >= tileY)
                    {
                        *dir |= (int)Directions::down;
                    }
                    else if (entityT <= tileY+tileH)
                    {
                        *dir |= (int)Directions::up;
                    }
                    if (entityR >= tileX) {
                        *dir |= (int)Directions::left;
                    }
                    else if (entityL <= tileX+tileW) {
                        *dir |= (int)Directions::right;
                    }
                    return true; 
                }
            }
        }
    }
    return false;
}



int engino::Tilemap::Clamp(int value, const int min, const int max)
{
    if (value < min)
    {
        value = min;
    }
    else if (value > max)
    {
        value = max;
    }

    return value;
}

void engino::Tilemap::Destroy()
{
    for (auto it = m_Tilemap.begin(); it != m_Tilemap.end(); ++it)
    {
    }
    m_Tilemap.clear();
    m_Tileset.clear();
}

int engino::Tilemap::NextTile(Entity* ntt, int dir, bool crouch)
{
    float x = ntt->GetX();
    float y = ntt->GetY();
    float w = ntt->GetComponent<BoxCollider>()->getW();
    float h = ntt->GetComponent<BoxCollider>()->getH();
    int tileW = m_Width / m_TileWidth;
    int tileH = m_Height / m_TileHeight;
    int XTileToBreak = 0;
    if (dir == 0)
    {
        XTileToBreak = Clamp(static_cast<int>(x / m_TileWidth), 0, tileW)-1;
    }
    else
    {
        XTileToBreak = Clamp(static_cast<int>((x + w) / m_TileWidth), 0, tileW) + 1;
    }
    int YTileToBreak = 0;
    if (crouch) {
        YTileToBreak = (int)(y / 3 / 16) + 1;
    }
    else
    {
        YTileToBreak = (int)(y / 3 / 16);
    }
    int tileIndex = m_Tilemap["breakables"][YTileToBreak][XTileToBreak];

    if (tileIndex == -1)
    {
        Create(ntt, XTileToBreak, YTileToBreak);
    }
    else if (tileIndex == 18)
    {
        Break(ntt, XTileToBreak, YTileToBreak);
    }

    return tileIndex;
}

void engino::Tilemap::Break(Entity* ntt, int xdir, int ydir)
{
    float x = ntt->GetX();
    float y = ntt->GetY();
    float w = ntt->GetComponent<BoxCollider>()->getW();
    float h = ntt->GetComponent<BoxCollider>()->getH();
    int tileW = m_Width / m_TileWidth;
    int tileH = m_Height / m_TileHeight;
    const int tTopTile = Clamp(static_cast<int>(y / m_TileHeight), 0, tileH);

    Engine::Get()->Aduio()->PlaySFX(Engine::Get()->Aduio()->LoadSound("assets/break.wav"), false);
    m_Tilemap["breakables"][ydir][xdir] = -1;
}

void engino::Tilemap::Create(Entity* ntt, int dir, int ydir)
{
    float x = ntt->GetX();
    float y = ntt->GetY();
    float w = ntt->GetComponent<BoxCollider>()->getW();
    float h = ntt->GetComponent<BoxCollider>()->getH();
    int tileW = m_Width / m_TileWidth;
    int tileH = m_Height / m_TileHeight;

    //const int tRightTile = Clamp(static_cast<int>((x + w) / m_TileWidth), 0, tileW);
    //const int tTopTile = Clamp(static_cast<int>(y / m_TileHeight), 0, tileH);

    for each (BoxCollider* col in Engine::Get()->wrld().GetColliders())
    {
        bool xOverlap = col->m_col.x + col->m_col.w >= dir* m_TileWidth && dir* m_TileWidth + m_TileWidth >= col->m_col.x;
        // Check for vertical overlap
        bool yOverlap = col->m_col.y + col->m_col.h >= ydir * m_TileHeight && ydir * m_TileHeight + m_TileHeight >= col->m_col.y;
        //bool yOverlap = r1.y + r1.h >= r2.y && r2.y + r2.h >= r1.y;

        if (xOverlap && yOverlap)
        {
            Engine::Get()->Aduio()->PlaySFX(Engine::Get()->Aduio()->LoadSound("assets/blockNotPlaced.wav"), false);
            return;
        }
    }

    Engine::Get()->Aduio()->PlaySFX(Engine::Get()->Aduio()->LoadSound("assets/place.wav"), false);
    m_Tilemap["breakables"][ydir][dir] = 18;
}

void engino::Tilemap::switchTile(std::string layer, int indexToChange, int targetIndex)
{
    for (int y = 0; y < m_Height / m_TileHeight; y++)
    {
        for (int x = 0; x < m_Width / m_TileWidth; x++)
        {
            int _idx = m_Tilemap[layer][y][x];

            if (_idx == indexToChange)
            {
                m_Tilemap[layer][y][x] = targetIndex;
            }
        }
    }
}



