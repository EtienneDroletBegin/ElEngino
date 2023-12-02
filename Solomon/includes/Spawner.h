#pragma once
#include "Monster.h"

namespace engino {
	class Spawner
	{
	public:
		~Spawner() {
			delete m_Prototypes;
		}
		void Destroy();
		/// <summary>
		/// takes a given prototype and adds it to the map
		/// </summary>
		/// <param name="name">the prototype's name</param>
		/// <param name="proto">the prototype</param>
		void AddPrototype(const std::string& name, IClonable* proto)
		{
			m_Prototypes->emplace(name,proto);
		}
		/// <summary>
		/// spawns the given prototype as a new entity
		/// </summary>
		/// <param name="name">the name of the prototype to find</param>
		/// <param name="x">the X coordinate where to spawn them</param>
		/// <param name="y">the Y coordinate where to spawn them</param>
		/// <returns>the cloned entity</returns>
		IClonable* Spawn(const std::string& name, float x, float y)
		{ 
			index++;
			if (m_Prototypes->count(name) > 0)
			{
				return m_Prototypes->at(name)->Clone(x, y, index);
			}
			return nullptr;
		}
	private:
		int index = 0;
		std::map<std::string, IClonable*> *m_Prototypes = new std::map<std::string, IClonable*>();
	};

}