#pragma once
#include "MyGameObject.h"

namespace My
{
	class Layer
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Destory();

		void AddGameObject(GameObject* gameObj);
		const std::vector<GameObject*> GetGameObjects()
		{
			return mGameObjects;
		}

	private:
		std::vector<GameObject*> mGameObjects;
	};
}
