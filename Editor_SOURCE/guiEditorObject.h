#pragma once
#include "..\\Engine_SOURCE\\MyGameObject.h"


namespace gui
{
	class EditorObject : public My::GameObject
	{
	public:
		EditorObject();
		virtual ~EditorObject();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
	};
}