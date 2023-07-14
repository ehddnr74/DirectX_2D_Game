#pragma once
#include "..\Engine_SOURCE\MySceneManager.h"
#include "MyPlayScene.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\MyEngine.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\YamYamEngine.lib")
#endif



//#include "..\YamYamEngine\\yaPlayScene.h"
//#include "yaSceneManager.h"
namespace My
{
	void InitializeScenes()
	{
		//PlayScene* playScene = new PlayScene();
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
	}
}