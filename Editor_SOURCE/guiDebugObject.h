#pragma once
#include "..\\Engine_SOURCE\\MyGameObject.h"


namespace gui
{
	class DebugObject : public My::GameObject
	{
	public:
		DebugObject();
		~DebugObject();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
	};
}
