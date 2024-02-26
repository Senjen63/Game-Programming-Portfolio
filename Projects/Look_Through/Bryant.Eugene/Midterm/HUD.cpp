#include "HUD.h"
#include "GraphicsSystem.h"
#include "Font.h"
#include "Color.h"
#include "GraphicsBuffer.h"
#include "Sprite.h"
#include "Game.h"

HUD::HUD()
{
	mpGraphicsSystem = nullptr;
	mpGraphicsBuffer = nullptr;
	mpFont = nullptr;
	mpSprite = nullptr;
	mpColorWhite = nullptr;
	mScoreN = 0;
	mScoreS = "";
}

HUD::~HUD()
{
	delete mpGraphicsSystem;
	delete mpGraphicsBuffer;
	delete mpFont;
	delete mpSprite;
	delete mpColorWhite;
}

void HUD::hudInit()
{
	mpColorWhite = new Color(255, 255, 255);
	
	mpGraphicsSystem = new GraphicsSystem;
	mpGraphicsBuffer = new GraphicsBuffer(COLOR_BACKGROUND_FILENAME, 800, 600);
	mpFont = new Font(FONT_FILENAME, 30);
	mpSprite = new Sprite(Vector2D(0,0), 800, 600, mpGraphicsBuffer);

	
}

void HUD::displayScreen()
{
	Game::getInstance()->getSystem()->draw(Vector2D(0, 0), mpSprite, 1.0);
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 250), mpFont, mpColorWhite, "Welcome to Snake");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 300), mpFont, mpColorWhite, "Press Spacebar to start");
}

void HUD::displayScore()
{
	convertIntToString();
	Game::getInstance()->getSystem()->writeText(Vector2D(0, 0), mpFont, mpColorWhite, mScoreS);
}

void HUD::displayPlayAgain()
{
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 250), mpFont, mpColorWhite, "Play Again?");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 300), mpFont, mpColorWhite, "Y/N");
}

void HUD::displayWin()
{
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 150), mpFont, mpColorWhite, "You Win");
}

void HUD::displayLose()
{
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 150), mpFont, mpColorWhite, "You Lose");
}

void HUD::addScore(int score)
{
	mScoreN = score;
	convertIntToString();
	
}

string HUD::getScore()
{
	return mScoreS;
}
void HUD::convertIntToString()
{
	mScoreS = to_string(mScoreN);
}

void HUD::clearScreen(Color* color)
{
	al_clear_to_color(color->getBlack());
}

string HUD::sResetScore()
{
	nResetScore();

	mScoreS = "0";

	return mScoreS;
}

int HUD::nResetScore()
{
	mScoreN = 0;

	return mScoreN;
}