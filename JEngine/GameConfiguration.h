#pragma once
#include "Utilities_Macro.h"

namespace JSample
{
	class GameConfiguration
	{	
		SINGLETON(GameConfiguration)

	public:
		static const int FRAME_BUFFER_COUNT = 3;
		static const int SCREEN_WIDTH = 1024;
		static const int SCREEN_HEIGHT = 768;
		
		static const bool IS_FULL_SCREEN = false;

		int TARGET_FPS = 60;
		int JOP_SLEEP_TIME = 1000;
		char* LOG_PATH = "..\\Log";
		char* FILE_EXTENSION = ".txt";
		char* configFilePath = "config.txt";
		

	public:
		GameConfiguration();
	};
}

