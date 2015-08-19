#include "G_Gameplay.h"

G_Gameplay::G_Gameplay(EP_Player* player, E_EntityManager* entityManager) 
	: player(player), entityManager(entityManager), collisionManager(new G_CollisionManager(player, entityManager))
{
}

G_Gameplay::~G_Gameplay()
{
	//delete pointers
	delete collisionManager;
}

void G_Gameplay::update(float dt)
{
	//Collision Detection
	collisionManager->entityCollisionDetection();
}