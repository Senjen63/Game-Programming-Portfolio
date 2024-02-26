#pragma once

#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <string>
#include "Trackable.h"


using namespace std;

const string MY_ASSET_PATH = "Assets\\";
const string INTRO_FILE = "Kawai Kitsune.wav"; // Kevin MacLeod
const string OPTION_FILE = "Space Fighter Loop.wav"; // Kevin MacLeod
const string GAME_FILE = "Ouroboros.wav"; // Kevin MacLeod

class SoundSystem : public Trackable
{
private:
	/*********Main Menu Music************/
	ALLEGRO_SAMPLE* mpIntro;
	ALLEGRO_SAMPLE_ID mIntroID;
	/************************************/

	/*********Options Music**************/
	ALLEGRO_SAMPLE* mpOption;
	ALLEGRO_SAMPLE_ID mOptionID;
	/************************************/

	/*********Game Music*****************/
	ALLEGRO_SAMPLE* mpGame;
	ALLEGRO_SAMPLE_ID mGameID;
	/************************************/

public:

	enum soundTrack
	{
		LOOP = ALLEGRO_PLAYMODE_LOOP
	};

	SoundSystem();
	~SoundSystem();

	void init();

	void loadAudio();

	bool playIntro(bool isPlaying);
	bool stopIntro(bool isPlaying);

	bool playOption(bool isPlaying);
	bool stopOption(bool isPlaying);

	bool playGame(bool isPlaying);
	bool stopGame(bool isPlaying);
};