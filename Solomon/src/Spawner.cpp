#include "Spawner.h"

void engino::Spawner::Destroy()
{
	for (auto it : *m_Prototypes)
	{
		delete it.second;
	}
	delete m_Prototypes;
}
