#include "G_SpawnManager.h"

G_SpawnManager::G_SpawnManager(C_Vec2 screenDimensions, EP_Player* player, E_EntityManager* entityManager, float* universalSpeed)
	: screenDimensions(screenDimensions), player(player), entityManager(entityManager), spawnTimer(1.0f), waveTimer(5.0f), 
	universalSpeed(universalSpeed), waveTime(1.0f)
{
}

G_SpawnManager::~G_SpawnManager()
{
}

void G_SpawnManager::update(float dt)
{
	//update the wave timer
	waveTimer.upadateTimer(dt);
	//check if the wave timer has ended
	if (waveTimer.checkTimer())
	{
		//decrease the time by 5 unless at min time
		if (waveTime > 0.5f)
		{
			waveTime -= 0.05f;
		}
		waveTimer.resetTimer();
	}
	
	//set the length of the timer length depending on the universal speed and wave time
	spawnTimer.setTimerLength(waveTime / *universalSpeed);
	//Update the spawn timer
	spawnTimer.upadateTimer(dt);
	//check if a new wave of entities should be spawned
	if (spawnTimer.checkTimer())
	{
		spawnEntityWave();
		spawnTimer.resetTimer();
	}
}

void G_SpawnManager::spawnEntityWave()
{
	//Get a number between 0 and 3 for max 4 number of things to spawn
	int numberToSpawn = (rand() % 4);

	//Divide the screen height into the number of things to spawn
	float zoneHeight = screenDimensions.y / numberToSpawn;

	for (int i = 0; i <= numberToSpawn; i++)
	{
		//Get a number between 0 and 5 for max 6 thing to spawn
		int entityToSpawn = pickEntity();

		//initialise the new spawn position
		float spawnY = 0.0f;

		//work out the minimum spawn y position within its heights zone
		float minimumY = i * zoneHeight;

		//work out the maximum spawn y position within its heights zone
		float maximumY = ((i + 1) * zoneHeight) - 1;
		maximumY -= entityManager->getEntityDimensions(getEntityID(entityToSpawn)).y;

		//make a random y spawn within the min and max height
		spawnY = (float)(rand() % (int)(maximumY - minimumY)) + minimumY;

		//spawn the entity
		spawnEntity(spawnY, entityToSpawn);
	}

}

int G_SpawnManager::pickEntity()
{
	//generate a new number between 1 and 200
	int spawnNumber = (rand() % 200) + 1;

	//work out the coin and health spawn % depending on lives left
	if (player->getHealth() == 3)//3 lives left - 50% coin, 0% health
	{
		if (spawnNumber <= 100) //50% chance
		{
			//entity is a coin
			return 2;
		}
	}
	else if (player->getHealth() == 2)//2 lives left - 40% coin, 10% health
	{
		if (spawnNumber <= 80) //40% chance
		{
			//entity is a coin
			return 2;
		}
		else if (spawnNumber >= 81 && spawnNumber <= 100) //10% chance
		{
			//entity is a health
			return 3;
		}
	}
	else//1 life left - 30% coin, 20% health
	{
		if (spawnNumber <= 60) //30% chance
		{
			//entity is a coin
			return 2;
		}
		else if (spawnNumber >= 61 && spawnNumber <= 100) //20% chance
		{
			//entity is a health
			return 3;
		}
	}

	if (spawnNumber >= 101 && spawnNumber <= 140) // 20% chance
	{
		//entity is a styphBird
		return 0;
	}
	else if (spawnNumber >= 141 && spawnNumber <= 170) // 15% chance
	{
		//entity is a cloud
		return 1;
	}
	else if (spawnNumber >= 171 && spawnNumber <= 186) // 17% chance
	{
		//entity is a archer
		return 5;
	}
	else if (spawnNumber >= 187 && spawnNumber <= 190) // 2% chance
	{
		//entity is a timeSlowPickup
		return 9;
	}
	else if (spawnNumber >= 191 && spawnNumber <= 194) // 2% chance
	{
		//entity is a firePowerUp
		return 4;
	}
	else if (spawnNumber >= 195 && spawnNumber <= 197) // 1.5% chance
	{
		//entity is a Shield
		return 8;
	}
	else if (spawnNumber >= 198 && spawnNumber <= 199) // 1% chance
	{
		//entity is a killAllPowerUp
		return 7;
	}
	else if (spawnNumber == 200) // 0.5% chance
	{
		//entity is a coinAllPowerUp
		return 6;
	}

	//something has gone wrong
	return -1;
}

std::string G_SpawnManager::getEntityID(int entityType)
{
	//Get the entity ID
	switch (entityType)
	{
	case 0: //StyphBird
		return "EE_StyphBird";
		break;
	case 1: //StormCloud
		return "EE_StormCloud";
		break;
	case 2: //Coin
		return "EPU_Coin";
		break;
	case 3: //Health
		return "EPU_Health";
		break;
	case 4: //Flaming
		return "EPU_Flaming";
		break;
	case 5: //Archer
		return "EE_Archer";
		break;
	case 6: //CoinAll
		return "EPU_CoinAll";
		break;
	case 7:  //KillAll
		return "EPU_KillAll";
		break;
	case 8: //Shields
		return "EPU_Shield";
		break;
	case 9: //TimeSlow
		return "EPU_TimeSlow";
		break;
	}
}

void G_SpawnManager::spawnEntity(float spawnY, int entityToSpawn)
{
	//Spawn the new entity
	switch (entityToSpawn)
	{
	case 0: //StyphBird
		entityManager->spawnStyphBird(
			C_Vec2(screenDimensions.x + entityManager->getEntityDimensions("EE_StyphBird").x, spawnY));
		break;
	case 1: //StormCloud
		entityManager->spawnStormCloud(
			C_Vec2(screenDimensions.x + entityManager->getEntityDimensions("EE_StormCloud").x, spawnY));
		break;
	case 2: //Coin
		entityManager->spawnCoin(
			C_Vec2(screenDimensions.x + entityManager->getEntityDimensions("EPU_Coin").x, spawnY));
		break;
	case 3: //Health
		entityManager->spawnHealth(
			C_Vec2(screenDimensions.x + entityManager->getEntityDimensions("EPU_Health").x, spawnY));
		break;
	case 4: //Flaming
		entityManager->spawnFlaming(
			C_Vec2(screenDimensions.x + entityManager->getEntityDimensions("EPU_Flaming").x, spawnY));
		break;
	case 5: //Archer
		entityManager->spawnArcher(
			C_Vec2(screenDimensions.x + entityManager->getEntityDimensions("EE_Archer").x, spawnY));
		break;
	case 6: //CoinAll
		entityManager->spawnCoinAll(
			C_Vec2(screenDimensions.x + entityManager->getEntityDimensions("EPU_CoinAll").x, spawnY));
		break;
	case 7:  //KillAll
		entityManager->spawnKillAll(
			C_Vec2(screenDimensions.x + entityManager->getEntityDimensions("EPU_KillAll").x, spawnY));
		break;
	case 8: //Shields
		entityManager->spawnShield(
			C_Vec2(screenDimensions.x + entityManager->getEntityDimensions("EPU_Shield").x, spawnY));
		break;
	case 9: //TimeSlow
		entityManager->spawnTimeSlow(
			C_Vec2(screenDimensions.x + entityManager->getEntityDimensions("EPU_TimeSlow").x, spawnY));
		break;
	}
}