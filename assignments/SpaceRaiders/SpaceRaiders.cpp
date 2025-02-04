// SpaceRaiders.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <memory>

#include "Vector2D.h"
#include "Renderer.h"

std::default_random_engine rGen;
typedef std::uniform_int_distribution<int> intRand;
typedef std::uniform_real_distribution<float> floatRand;

char ObjectType[][64] =
{
	"ot_AlienShip",
	"ot_PlayerShip",
	"ot_AlienLaser",
	"ot_PlayerLaser",
	"ot_Explosion"
};

class PlayField;
class GameObject
{
public:
	char* m_objType = nullptr;
	Vector2D pos;
	unsigned char sprite;

	virtual void Update(PlayField& world) {};
	virtual bool DecreaseHealth() { return true; };
};

class Input
{
public:
	virtual bool Left() = 0;
	virtual bool Right() = 0;
	virtual bool Fire() = 0;
};

class RndInput : public Input
{
public:	
	virtual bool Left() { floatRand keyRate(0, 1); return (keyRate(rGen) < 0.3f); }
	virtual bool Right() { floatRand keyRate(0, 1); return (keyRate(rGen) < 0.4f); };
	virtual bool Fire() { floatRand keyRate(0, 1); return (keyRate(rGen) < 0.5f); };
};

class PlayField
{
private:
	typedef GameObject* GameObjPtr;
	std::vector<GameObjPtr> gameObjects;

public:
	Input* cotrollerInput = nullptr;
	Vector2D bounds;
	// Number of available active laser slots for aliens and player
	int AlienLasers = 10;
	int PlayerLasers = 4;

	PlayField(Vector2D iBounds) : bounds(iBounds) {};
	const std::vector<GameObjPtr>& GameObjects() { return gameObjects; }

	void Update()
	{
		// Update list of active objects in the world
		for (auto it : gameObjects)
		{
			it->Update(*this);
			return;
		}
	}

	GameObject* GetPlayerObject()
	{
		auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [](GameObjPtr in) { return (strcmp(in->m_objType,"ot_PlayerShip")==0); });
		if (it != gameObjects.end())
			return (*it);
		else
			return nullptr;
	}

	
	void SpawnLaser(GameObject* newObj)
	{
		if (strcmp(newObj->m_objType, "ot_AlienLaser")==0)
			AlienLasers--;
		else if (strcmp(newObj->m_objType, "ot_PlayerLaser")==0)
			PlayerLasers--;
		AddObject(newObj);
	}
	void DespawnLaser(GameObject* newObj)
	{
		if (strcmp(newObj->m_objType, "ot_AlienLaser")==0)
			AlienLasers++;
		else if (strcmp(newObj->m_objType, "ot_PlayerLaser")==0)
			PlayerLasers++;
		RemoveObject(newObj);
	}

	void AddObject(GameObject* newObj)
	{
		//gameObjectsToAdd.push_back(GameObjPtr(newObj));
		gameObjects.push_back(newObj);
	}
	void RemoveObject(GameObject* newObj)
	{
		//gameObjectsToRemove.push_back(newObj);
		auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [&](GameObjPtr in) { return (in==newObj); });
		gameObjects.erase(it);
	}
};

class Explosion : public GameObject
{
public:
	// Explosion lasts 5 ticks before it dissappears
	int timer = 5;
	Explosion() { m_objType = new char[64];  strcpy(m_objType, "ot_Explosion"); sprite = RS_Explosion; }
	~Explosion() { delete[] m_objType; }
	void Update(PlayField& world)
	{
		timer--;
		if (!timer)
		{
			world.RemoveObject(this);
			delete this;
		}
	}
};

class AlienLaser : public GameObject
{
public:
	AlienLaser() { m_objType = new char[64]; strcpy(m_objType, "ot_AlienLaser"); sprite = RS_AlienLaser; }
	~AlienLaser() {	delete[] m_objType; }

	void Update(PlayField& world)
	{
		bool deleted = false;
		pos.y += 1.f;
		if (pos.y > world.bounds.y)
		{
			deleted = true;
		}
		GameObject* player = world.GetPlayerObject();
		if (player && pos.IntCmp(player->pos))
		{
			deleted = true;
			//Spawn explosion, kill player
			GameObject& no = *(new Explosion);
			no.pos = pos;
			world.AddObject(&no);
			world.RemoveObject(player);
		}

		if (deleted)
		{
			world.DespawnLaser((GameObject*)this);
			delete this;
		}
	}
};

class PlayerLaser : public GameObject
{
public:
	PlayerLaser() { m_objType = new char[64]; strcpy(m_objType, "ot_PlayerLaser"); sprite = RS_PlayerLaser; }
	~PlayerLaser() { delete[] m_objType; }

	void Update(PlayField& world)
	{
		bool deleted = false;
		pos.y -= 1.f;
		if (pos.y < 0)
		{
			deleted = true;
		}

		for (auto it : world.GameObjects())
		{
			if (strcmp(it->m_objType,"ot_AlienShip")==0 && it->pos.IntCmp(pos))
			{
				deleted = true;
				//Spawn explosion, kill the alien that we hit
				//ToDo - add scoring
				GameObject& no = *(new Explosion);
				no.pos = pos;
				world.AddObject(&no);
				if (it->DecreaseHealth())
					world.RemoveObject(it);
			}
		}

		if (deleted)
		{
			world.DespawnLaser(this);
			delete this;
		}
	}
};

class Alien : public GameObject
{
public:
	Alien() { m_objType = new char[64]; strcpy(m_objType,"ot_AlienShip"); sprite = RS_Alien; }
	~Alien() { delete m_objType; }

private:
	// Alien constants - these could move out into PlayField as configurable variables
	const float maxUpdateRate = 0.01f;
	const float transformEnergy = 1.f;
	enum AlienState
	{
		as_Normal,
		as_Better
	};
	// Variables dictating energy level for upgrade, direction of movement, and current speed
	float health = 1.f;
	float energy = 0.f;
	float direction = 1.f;
	float velocity = 0.5f;
	AlienState state;

	void Transform()
	{
		state = as_Better;
		sprite = RS_BetterAlien;
		velocity *= 2.f;
	}
	bool DecreaseHealth() { health -= 1.f; return health <= 0;  }

	void Update(PlayField& world)
	{
		pos.x += direction * velocity;
		// Border check
		if (pos.x < 0 || pos.x >= world.bounds.x - 1)
		{
			direction = -direction;
			pos.y += 1;
		}
		
		// Border check vertical:
		if (pos.y >= world.bounds.y - 1)
		{
			// kill player
			GameObject* player = world.GetPlayerObject();
			if (player && pos.IntCmp(player->pos))
			{
				//Spawn explosion
				GameObject& no = *(new Explosion);
				no.pos = pos;
				world.AddObject(&no);
				world.RemoveObject(player);
			}
		}

		// Transform into better Alien
		if (state!=as_Better)
		{
			floatRand updateRate(-maxUpdateRate, 2*maxUpdateRate);
			energy += updateRate(rGen);
			if (energy >= transformEnergy)
				Transform();
		}

		floatRand fireRate(0, 1);
		if (fireRate(rGen) < 0.5 && world.AlienLasers>0)
		{
			//Spawn laser
			GameObject& newLaser = *(new AlienLaser);
			newLaser.pos = pos;
			world.SpawnLaser(&newLaser);
		}
	}
};

class PlayerShip : public GameObject
{
public:
	PlayerShip() { m_objType = new char[64]; strcpy(m_objType, "ot_PlayerShip"); sprite = RS_Player; }
	~PlayerShip() { delete m_objType; }

	void Update(PlayField& world)
	{
		if (world.cotrollerInput->Left())
			pos.x -= 1;
		else if (world.cotrollerInput->Right())
			pos.x += 1;
	
		if (world.cotrollerInput->Fire() && world.PlayerLasers>0)
		{
			//Spawn laser
			GameObject& newLaser = *(new PlayerLaser);
			newLaser.pos = pos;
			world.SpawnLaser(&newLaser);
		}
	}
};

int main()
{
	rGen.seed(1);
	Vector2D size(80, 28);
	Renderer mainRenderer(size);
	PlayField world(size);

	intRand xCoord(0, (int)size.x-1);
	intRand yCoord(0, 10);

	// Populate aliens
	for (int k = 0; k < 20; k++)
	{
		Alien& a = *(new Alien);
		a.pos.x = (float)xCoord(rGen);
		a.pos.y = (float)yCoord(rGen);
		world.AddObject(&a);
	}
	// Add player
	PlayerShip& p = *(new PlayerShip);
	p.pos = Vector2D(40, 27);
	world.AddObject(&p);

#define TEST_RUN
#ifdef TEST_RUN
	// Test run with random input
	world.cotrollerInput = new RndInput;
	for (int i = 0; i < 100; i++)
#else
	// ToDo - implement keyboard (or other device input)
	//world.cotrollerInput = new KeyboardInput;
	while (;;) // break when game-over
#endif
	{
		world.Update();

		RenderItemList rl;
		for (auto it : world.GameObjects())
		{
			RenderItem a = RenderItem(Vector2D(it->pos), it->sprite );
			rl.push_back(a);
		}

		mainRenderer.Update(rl);
		// Sleep a bit so updates don't run too fast
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	return 0;
}

