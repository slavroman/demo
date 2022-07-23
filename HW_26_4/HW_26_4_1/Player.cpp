#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Player.h"

enum Player::status
{
	PLAY = 0,
	PAUSE,
	STOP
};

void Player::play(std::string name)
{
	if (getStatus() != PLAY && mTrackList.size() > 0)
	{
		if (!searchTrack(name))
		{
			std::cout << "\nThe track: " << name << " not found!!!\n";
		}
		else
		{
			std::cout << "\nNow playing:\n";
			mTrackList[mCurrentTrackNumber].showTrack();
			mStatus = PLAY;
		}		
	}	
}

void Player::pause()
{
	if (mStatus != PAUSE && mStatus != STOP)
	{
		std::cout << "\nPlayback paused.\n";
		mStatus = PAUSE;
	}	
}

void Player::next()
{
	if (mStatus != PLAY)
	{
		int min = 0;
		int max = mTrackList.size() - 1;
		int randVvalue = min + rand() % (max - min);

		std::cout << "\nNow playing:\n";
		mTrackList[mCurrentTrackNumber].showTrack();
		mStatus = PLAY;
	}
}

void Player::stop()
{
	if (getStatus() != STOP)
	{
		std::cout << "\nPlayback stopped.\n";
		mStatus = STOP;
	}	
}

void Player::addTrack(Track obj)
{
	mTrackList.push_back(obj);
	std::cout << "\nTrack added successfully.\n";
}

bool Player::searchTrack(std::string track)
{
	for (size_t i = 0; i < mTrackList.size(); i++)
	{
		if (mTrackList[i].getTrackName() == track)
		{
			mCurrentTrackNumber = i;
			return true;
		}
	}

	return false;
}

void Player::showTracklist()
{
	if (mTrackList.size() > 0)
	{
		std::cout << "\nTracklist:\n";

		for (const auto& v : mTrackList)
		{
			v.showTrack();
		}
	}
	else
	{
		std::cout << "\nTracklist empty!!!\n";
	}	
}

int Player::getStatus()
{
	return mStatus;
}

Player::Player()
{
	mStatus = STOP;
	mCurrentTrackNumber = 0;
	std::vector<Track> mTrackList;
}