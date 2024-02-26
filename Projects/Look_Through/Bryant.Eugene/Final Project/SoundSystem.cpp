/*
Author: Eugene Bryant
Class: GPR-250-02
Assignment: Final Project
Certification of Authenticity:
I certify that this assignment is entirely my own work.
 */

#include "SoundSystem.h"

SoundSystem::SoundSystem()
{
	mpIntro = nullptr;
	mpOption = nullptr;
	mpGame = nullptr;
}

SoundSystem::~SoundSystem()
{
	if (al_is_audio_installed)
	{
		al_uninstall_audio();
	}
}

void SoundSystem::init()
{
	al_install_audio();
	al_reserve_samples(10);
}

void SoundSystem::loadAudio()
{
	mpIntro = al_load_sample((MY_ASSET_PATH + INTRO_FILE).c_str());
	assert(mpIntro);
	mpOption = al_load_sample((MY_ASSET_PATH + OPTION_FILE).c_str());
	assert(mpOption);
	mpGame = al_load_sample((MY_ASSET_PATH + GAME_FILE).c_str());
	assert(mpGame);
}

bool SoundSystem::playIntro(bool isPlaying)
{
	if (!isPlaying)
	{
		al_play_sample(mpIntro, 1.0f, ALLEGRO_AUDIO_PAN_NONE, 1.0f, (ALLEGRO_PLAYMODE)LOOP, &mIntroID);
	}

	isPlaying = true;
	
	return isPlaying;
}

bool SoundSystem::stopIntro(bool isPlaying)
{
	if (isPlaying)
	{
		al_stop_sample(&mIntroID);
	}
	
	isPlaying = false;

	return isPlaying;
}

bool SoundSystem::playOption(bool isPlaying)
{
	if (!isPlaying)
	{
		al_play_sample(mpOption, 1.0f, ALLEGRO_AUDIO_PAN_NONE, 1.0f, (ALLEGRO_PLAYMODE)LOOP, &mOptionID);
	}

	isPlaying = true;

	return isPlaying;
}

bool SoundSystem::stopOption(bool isPlaying)
{
	if (isPlaying)
	{
		al_stop_sample(&mOptionID);
	}

	isPlaying = false;

	return isPlaying;
}

bool SoundSystem::playGame(bool isPlaying)
{
	if (!isPlaying)
	{
		al_play_sample(mpGame, 1.0f, ALLEGRO_AUDIO_PAN_NONE, 1.0f, (ALLEGRO_PLAYMODE)LOOP, &mGameID);
	}

	isPlaying = true;

	return isPlaying;
}

bool SoundSystem::stopGame(bool isPlaying)
{
	if (isPlaying)
	{
		al_stop_sample(&mGameID);
	}

	isPlaying = false;

	return isPlaying;
}