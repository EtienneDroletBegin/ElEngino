#pragma once
#include <vector>
#include <map>
#include <Component.h>
#include <IDrawable.h>
#include "Engine.h"


namespace engino {
    typedef std::vector<std::vector<int>> TLayer;
    typedef std::map<std::string, TLayer> TTilemap;
    typedef std::vector<RectI> TTileset;

	class Tilemap : public Component, public IDrawable
	{
	public:
		Tilemap();
		Tilemap(Entity* parent);
		virtual ~Tilemap() =default;

		virtual void Draw() override;
		/// <summary>
		/// loads the tilemap's image and necessary values
		/// </summary>
		/// <param name="filename">the file's name in the game files</param>
		/// <param name="mapW">the full width of the map</param>
		/// <param name="mapH">the full height of the map</param>
		/// <param name="tileW">the width of a tile</param>
		/// <param name="tileH">the height of a tile</param>
		void Load(std::string filename, int mapW, int mapH, int tileW, int tileH);
		/// <summary>
		/// adds a layer to the tilemap, allowing for depth and specific colision detection
		/// </summary>
		/// <param name="layer">the layer's name</param>
		/// <param name="tiles">the int vectors signifying the layer</param>
		void AddLayer(std::string layer, TLayer tiles);
		/// <summary>
		/// returns a layer with a given name
		/// </summary>
		/// <param name="name">the given name</param>
		/// <returns>the layer with the given name</returns>
		TLayer GetLayer(std::string name);
		/// <summary>
		/// reads the CSV file containing the layer and converts it to vectors
		/// </summary>
		/// <param name="filename">the CSV file in the game files</param>
		/// <param name="layername">the name of the layer</param>
		void ReadCSV(std::string filename, std::string layername);
		/// <summary>
		/// checks collisions between a given collider and a layer of the tilemap
		/// </summary>
		/// <param name="layer">the layer to check</param>
		/// <param name="_entity">the entity to check on the tilemap</param>
		/// <param name="tileIndex">the tile being touched. -1 if none</param>
		/// <param name="dir">the direction in which it is being touched</param>
		/// <returns>a bool indicating if the entity is touching the tilemap</returns>
		bool IsColliding(std::string layer, Entity* _entity, int* tileIndex, int* dir);
		/// <summary>
		/// gets the closest tile value
		/// </summary>
		/// <param name="value">the location to clamp</param>
		/// <param name="min">the smallest value</param>
		/// <param name="max">the highest value</param>
		/// <returns>the clamped value</returns>
		int Clamp(int value, const int min, const int max);
		void Destroy() override;
		/// <summary>
		/// checks the tile in front of the player
		/// </summary>
		/// <param name="ntt">the entity to check</param>
		/// <param name="dir">the direction they are facing</param>
		/// <param name="crouch">whether the entity is crouched</param>
		/// <returns>the tile index of the tile in front</returns>
		int NextTile(Entity* ntt, int dir, bool crouch);
		/// <summary>
		/// breaks a block on the destructables layer
		/// </summary>
		/// <param name="ntt">the entity in front of which to break the block</param>
		/// <param name="dir">the direction they are facing</param>
		/// <param name="ydir">whether to break the block under the player's Y or not</param>
		void Break(Entity* ntt, int dir, int ydir);
		/// <summary>
		/// creates a block on the destructables layer
		/// </summary>
		/// <param name="ntt">the entity in front of which to put the block</param>
		/// <param name="dir">the direction they are looking</param>
		/// <param name="ydir">whether to place the block under the player's Y or not</param>
		void Create(Entity* ntt, int dir, int ydir);
		/// <summary>
		/// turns a given tile's index into another index
		/// </summary>
		/// <param name="layer">the layer to comb through</param>
		/// <param name="indexToChange">index to replace</param>
		/// <param name="targetIndex">new index</param>
		void switchTile(std::string layer, int indexToChange, int targetIndex);

	private:
		TTilemap m_Tilemap;
		TTileset m_Tileset;

		int m_Width =0;
		int m_Height =0;
		size_t m_tileSetID =0;
		int m_TileWidth = 0;
		int m_TileHeight = 0;
		int m_ScaleFactor = 3;

	};

}