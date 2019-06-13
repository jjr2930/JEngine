#pragma once
#if __DIRECTX_12__
#include "DirectX12\JMath_DX12.h"
#elif __METAL__			//apple
//include something
#elif __VULKAN__		//multi platform
//include something
#elif __OPENGL_4_X__	
//include something
#elif __OPENGL_ES_2_x__	//except apple
//include something
#elif __OPENGL_ES_3_X__ //except apple
//include something
#endif
