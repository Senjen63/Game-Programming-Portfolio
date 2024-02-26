#include "Blaster.h"
#include "PlayerManager.h"
#include "Unit.h"
#include "InputSystem.h"
#include "Animation.h"
#include "Sprite.h"
#include "Game.h"
#include "GraphicsSystem.h"
#include "EnemyManager.h"

Blaster::Blaster()
{
	mpBullet = nullptr;
	mpTrigger = nullptr;
}

Blaster::~Blaster()
{
	delete mpBullet;
	delete mpTrigger;
}

void Blaster::init(PlayerManager* player)
{
	mpTrigger = new InputSystem();
	bulletX = player->getPlayer()->getSource().getX();
	bulletY = player->getPlayer()->getSource().getY();
	mpBullet = new Unit(Vector2D(bulletX + 65, bulletY + 50));
}

void Blaster::follow(PlayerManager* player)
{
	bulletX = player->getPlayer()->getSource().getX();
	bulletY = player->getPlayer()->getSource().getY();
	mpBullet->setPosition(Vector2D(bulletX + 65, bulletY + 50));
}

void Blaster::fire()
{
	if (mpTrigger->getKeyState(mpTrigger->SPACEBAR_KEY))
	{
		mIsFired = true;
	}
}

void Blaster::update(PlayerManager* player, EnemyManager* enemy)
{
	if (!mIsFired)
	{
		follow(player);
	}
	if (mIsFired)
	{
		Game::getInstance()->getSystem()->draw(mpBullet->getSource(), mpBullet->getAnimation()->getCurrentSprite(), .05);

		mpBullet->setPosition(mpBullet->getSource() - velocity);

		// to check and see if the bullet left the screen
		if (mpBullet->getSource().getY() < 0)
		{
			mIsFired = false;
		}
	}
}

void Blaster::reset(PlayerManager* player)
{
	mIsFired = false;
	follow(player);
}

bool Blaster::isFired(bool fire)
{
	fire = mIsFired;

	return fire;
}