#pragma once

#define SINGLETON(TYPE_NAME)\
static TYPE_NAME* _instance;\
public :\
static TYPE_NAME* GetInstance()\
{\
	if(nullptr == _instance)\
	{\
		_instance = new TYPE_NAME();\
	}\
	return _instance;\
}\

#define INIT_SINGLETON(TYPE_NAME)\
TYPE_NAME* TYPE_NAME::_instance = nullptr;

#define SAFE_RELEASE_DX(p)\
{\
	if((p))\
	{\
		p->Release();\
		(p) = 0;\
	}\
}\

#define SAVE_RELEASE(p)\
{\
	if(nullptr != p)\
	{\
		free(p);\
		p = nullptr;\
	}\
}