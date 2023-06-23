#pragma once
#include "MyEngine.h"
#include "MyGraphicDevice_Dx11.h"
#include "MyMesh.h"
#include "MyShader.h"
#include "MyConstantBuffer.h"

using namespace My::math;
using namespace My::graphics;
namespace renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
		Vector2 uv;
	};

	CBUFFER(TransformCB, CBSLOT_TRANSFORM)
	{
		Matrix mWorld;
		Matrix mView;
		Matrix mProjection;
	};

	extern Vertex vertexes[];
	extern My::graphics::ConstantBuffer* constantBuffer[(UINT)eCBType::End];

	void Initialize();
	void Release();
}