#include "G_Gameplay.h"

G_Gameplay::G_Gameplay(C_Vec2 screenDimensions, EP_Player* player, E_EntityManager* entityManager, float* universalSpeed)
	: player(player), entityManager(entityManager), collisionManager(new G_CollisionManager(player, entityManager, universalSpeed)),
	spawnManager(new G_SpawnManager(screenDimensions, player, entityManager, universalSpeed)), screenDimensions(screenDimensions), 
	universalSpeed(universalSpeed)
{
}

G_Gameplay::~G_Gameplay()
{
	//delete pointers
	delete collisionManager;
	delete spawnManager;
}

void G_Gameplay::update(float dt)
{
	//Spawn Management
	spawnManager->update(dt);

	//Collision Detection
	collisionManager->entityCollisionDetection();
}