/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "HUD.h"
#include "Font.h"
#include "Color.h"
#include "GraphicsBuffer.h"
#include "GraphicsSystem.h"
#include "Sprite.h"
#include "Game.h"

HUD::HUD()
{
	mpGraphicsBuffer = nullptr;
	mpFont = nullptr;
	mpSprite = nullptr;
	mpColorWhite = nullptr;
	mpColorBlack = nullptr;
	mScoreN = 0;
	mScoreS = "";
}

HUD::~HUD()
{
	delete mpGraphicsBuffer;
	delete mpFont;
	delete mpSprite;
	delete mpColorWhite;
	delete mpColorBlack;
}

// Initilizes HUD
void HUD::hudInit()
{
	mpColorWhite = new Color(255, 255, 255);
	mpColorBlack = new Color(0, 0, 0);
	mpGraphicsBuffer = new GraphicsBuffer(mpColorBlack, 700, 950);
	mpFont = new Font(FONT_FILENAME, 30);
	mpSprite = new Sprite(Vector2D(0,0), 800, 600, mpGraphicsBuffer);
}

// Displays Title Screen
void HUD::displayScreen()
{
	clearScreen(getBlack());
	Game::getInstance()->getSystem()->draw(Vector2D(0, 0), getSprite(), 1.0);
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 250), 
		getFont(), getWhite(), "Welcome to Snake");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 300), 
		getFont(), getWhite(), "Press Spacebar to start");
}

// Displays current score
void HUD::displayScore(int score)
{
	convertIntToString(score);
	Game::getInstance()->getSystem()->draw(Vector2D(0, 0), getSprite(), 1.0);
	Game::getInstance()->getSystem()->writeText(Vector2D(0, 0), 
		getFont(), getWhite(), mScoreS);
}

//Displays the total amount of score
void HUD::displayTotalScore()
{
	clearScreen(getBlack());
	Game::getInstance()->getSystem()->draw(Vector2D(0, 0), getSprite(), 1.0);
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 250), 
		getFont(), getWhite(), "Your Current Score is: " + mScoreS);
}

// Displays Play Again Screen
void HUD::displayPlayAgain()
{
	clearScreen(getBlack());
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 250), getFont(), getWhite(), "Play Again?");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 300), getFont(), getWhite(), "Y/N");
}

// Displays Win Screen
void HUD::displayWin()
{
	clearScreen(getBlack());
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 150), getFont(), getWhite(), "You Win");
}

// Displays Lose Screen
void HUD::displayLose()
{
	clearScreen(getBlack());
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 150), getFont(), getWhite(), "You Lose");
}

// Displays option Screen
void HUD::displayOptions()
{
	clearScreen(getBlack());
	Game::getInstance()->getSystem()->draw(Vector2D(0, 0), getSprite(), 1.0);
	Game::getInstance()->getSystem()->writeText(Vector2D(50, 150), getFont(), getWhite(), "What would you like to customize,");
	Game::getInstance()->getSystem()->writeText(Vector2D(50, 200), getFont(), getWhite(), "the game's Speed or Sound?");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 250), getFont(), getWhite(), "1 = Speed");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 300), getFont(), getWhite(), "2 = Sound");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 350), getFont(), getWhite(), "B = Back");
}

// Displays sound Screen
void HUD::displaySound()
{
	clearScreen(getBlack());
	Game::getInstance()->getSystem()->draw(Vector2D(0, 0), getSprite(), 1.0);
	Game::getInstance()->getSystem()->writeText(Vector2D(50, 150), getFont(), getWhite(), "Would you like the sound on or off?");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 200), getFont(), getWhite(), "Y = Yes");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 250), getFont(), getWhite(), "N = No");
}

// Displays speed Screen
void HUD::displaySpeed()
{
	clearScreen(mpColorBlack);
	Game::getInstance()->getSystem()->draw(Vector2D(0, 0), getSprite(), 1.0);
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 150), getFont(), getWhite(), "Select Difficulty");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 200), getFont(), getWhite(), "E = Easy");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 250), getFont(), getWhite(), "N = Normal");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 300), getFont(), getWhite(), "H = Hard");
}

// Displays Main Menu
void HUD::displayMainMenu()
{
	clearScreen(getBlack());
	Game::getInstance()->getSystem()->draw(Vector2D(0, 0), getSprite(), 1.0);
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 250),
		getFont(), getWhite(), "Welcome to One Shot Pilot");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 300),
		getFont(), getWhite(), "Press P to start a New Game");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 350),
		getFont(), getWhite(), "Press O for options");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 400),
		getFont(), getWhite(), "Press L to Load Game");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 450),
		getFont(), getWhite(), "Press ESC to exit");
}

// Adds Score
void HUD::addScore(int score)
{
	mScoreN = score;
	convertIntToString(mScoreN);
}

string HUD::getScore()
{
	return mScoreS;
}

void HUD::convertIntToString(int score)
{
	mScoreN = score;
	mScoreS = to_string(mScoreN);
}

// Clears Screen
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

// Displays High Score Screen
void HUD::highScore()
{
	Game::getInstance()->getSystem()->draw(Vector2D(0, 0), mpSprite, 1.0);
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 150), mpFont, mpColorWhite, "Your Score is " + mScoreS);
}

// Displays Elapsed Time Screen
void HUD::displayElapsedTime(double elapse)
{
	mTime = to_string(elapse);

	Game::getInstance()->getSystem()->writeText(Vector2D(100, 0), 
		mpFont, mpColorWhite, "Elapsed Time: " + mTime);
}

// Displays Lives Screen
void HUD::displayLives(int life)
{
	mLives = to_string(life);

	Game::getInstance()->getSystem()->writeText(Vector2D(550, 0),
		mpFont, mpColorWhite, "Lives: " + mLives);
}

// Displays Game Over Screen
void HUD::displayGameOver()
{
	clearScreen(mpColorBlack);
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 150), mpFont, mpColorWhite, "Game Over");
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 200), mpFont, mpColorWhite, "Your Score is " + mScoreS);
	Game::getInstance()->getSystem()->writeText(Vector2D(150, 250), mpFont, mpColorWhite, "Press Enter to Continue");
}

