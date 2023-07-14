#include "MyGridScript.h"
#include "MyConstantBuffer.h"
#include "MyCamera.h"
#include "MyTransform.h"
#include "MyApplication.h"
#include "MyGameObject.h"
#include "MyRenderer.h"
#include "MyTime.h"
#include "MyObject.h"

extern My::Application application;

namespace My
{
	GridScript::GridScript()
		: mCamera(nullptr)
	{
	}
	GridScript::~GridScript()
	{
	}
	void GridScript::Initialize()
	{
	}
	void GridScript::Update()
	{
		//static float chTime = 0.0f;
		//chTime += Time::DeltaTime();

		//if (chTime > 3.0f)
		//{
		//	object::Destroy(GetOwner());
		//}

		if (mCamera == nullptr)
			return;


		GameObject* gameObj = mCamera->GetOwner();

		Transform* tr = gameObj->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();

		float scale = mCamera->GetSize();

		HWND hWnd = application.GetHwnd();
		RECT winRect = {};
		GetClientRect(hWnd, &winRect);

		float width = winRect.right - winRect.left;
		float height = winRect.bottom - winRect.top;
		Vector2 resolution(width, height);

		///cs buffer
		graphics::ConstantBuffer* cb
			= renderer::constantBuffer[(int)eCBType::Grid];

		renderer::GridCB data;
		data.CameraPosition = Vector4(pos.x, pos.y, pos.z, 1.0f);
		data.Resolution = resolution;
		data.CameraScale = Vector2(scale, scale);

		cb->SetData(&data);
		cb->Bind(eShaderStage::VS);
		cb->Bind(eShaderStage::PS);
	}


	void GridScript::LateUpdate()
	{
	}
	void GridScript::Render()
	{
	}
}