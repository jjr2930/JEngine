/*
Transform must be implemented in dependence on each 3d rendering library
*/
#pragma once
#if __OPEN_GL__ 
#include "JTransform_OpenGL.h"
#elif __DIRECTX_12__ 
#include "JTransform_DX12.h"
#endif