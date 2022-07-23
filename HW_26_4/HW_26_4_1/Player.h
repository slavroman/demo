#pragma once
#include "Track.h"
#include <string>
#include <vector>

class Player
{
public:

	Player();

	enum status;
	
	void play(std::string name);
	void pause();
	void next();
	void stop();
	void addTrack(Track obj);
	bool searchTrack(std::string track);
	void showTracklist();
	int getStatus();

private:
	int mStatus;
	int mCurrentTrackNumber; // Index current position of mTrackList
	std::vector<Track> mTrackList;
};