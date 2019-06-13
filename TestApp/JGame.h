#pragma once
#include <string>
namespace JSample
{
	class JScene;
	using ptrJScene = JScene*;

	class JNativeRenderer;
	using ptrJNativeRenderer = JNativeRenderer*;

	class JGame {
	private :
		ptrJScene			_scene			= nullptr;
		ptrJNativeRenderer	_nativeRenderer = nullptr;
	public:
		JGame(const std::wstring& fileName);
		void OpenStartSceneFile();
		void ParseSceneFile();
		void SetTargetSceneToCurrentScene();
		void Update();
		void Render();
	};
}