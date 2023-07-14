#include "guiEditor.h"
#include "..\\Engine_SOURCE\\MyMesh.h"
#include "..\\Engine_SOURCE\\MyMesh.h"
#include "..\\Engine_SOURCE\\MyResources.h"
#include "..\\Engine_SOURCE\\MyTransform.h"
#include "..\\Engine_SOURCE\\MyMeshRenderer.h"
#include "..\\Engine_SOURCE\\MyMaterial.h"
#include "..\\Engine_SOURCE\\MyRenderer.h"


#include "MyGridScript.h"

namespace gui
{
	using namespace My::enums;
	std::vector<Widget*> Editor::mWidgets = {};
	std::vector<EditorObject*> Editor::mEditorObjects = {};
	std::vector<DebugObject*> Editor::mDebugObjects = {};

	void Editor::Initialize()
	{
		mDebugObjects.resize((UINT)eColliderType::End);

		std::shared_ptr<My::Mesh> mesh
			= My::Resources::Find<My::Mesh>(L"DebugRect");
		std::shared_ptr<My::Material> material
			= My::Resources::Find<My::Material>(L"DebugMaterial");

		mDebugObjects[(UINT)eColliderType::Rect] = new DebugObject();
		mDebugObjects[(UINT)eColliderType::Rect]->AddComponent<My::Transform>();
		My::MeshRenderer* mr
			= mDebugObjects[(UINT)eColliderType::Rect]->AddComponent<My::MeshRenderer>();
		mr->SetMaterial(material);
		mr->SetMesh(mesh);


		EditorObject* grid = new EditorObject();
		grid->SetName(L"Grid");

		mr = grid->AddComponent<My::MeshRenderer>();
		mr->SetMesh(My::Resources::Find<My::Mesh>(L"RectMesh"));
		mr->SetMaterial(My::Resources::Find<My::Material>(L"GridMaterial"));
		My::GridScript* gridSc = grid->AddComponent<My::GridScript>();
		gridSc->SetCamera(renderer::cameras[0]);

		mEditorObjects.push_back(grid);

	}
	void Editor::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Editor::Update()
	{


		for (EditorObject* obj : mEditorObjects)
		{
			obj->Update();
		}
	}
	void Editor::LateUpdate()
	{
		for (EditorObject* obj : mEditorObjects)
		{
			obj->LateUpdate();
		}
	}
	void Editor::Render()
	{

		for (EditorObject* obj : mEditorObjects)
		{
			obj->Render();
		}

		for (const My::graphics::DebugMesh& mesh
			: renderer::debugMeshs)
		{
			DebugRender(mesh);
		}
		renderer::debugMeshs.clear();
	}
	void Editor::Release()
	{
		for (auto widget : mWidgets)
		{
			delete widget;
			widget = nullptr;
		}

		for (auto editorObj : mEditorObjects)
		{
			delete editorObj;
			editorObj = nullptr;
		}

		for (auto debugObj : mDebugObjects)
		{
			delete debugObj;
			debugObj = nullptr;
		}

	}

	void Editor::DebugRender(const My::graphics::DebugMesh& mesh)
	{
		DebugObject* debugObj = mDebugObjects[(UINT)mesh.type];

		// ��ġ ũ�� ȸ�� ������ �޾ƿͼ�
		// �ش� ���ӿ�����Ʈ���� �׷��ָ�ȴ�.
		My::Transform* tr = debugObj->GetComponent<My::Transform>();

		Vector3 pos = mesh.position;
		pos.z -= 0.01f;

		tr->SetPosition(pos);
		tr->SetScale(mesh.scale);
		tr->SetRotation(mesh.rotation);

		tr->LateUpdate();

		/*My::MeshRenderer * mr
			= debugObj->GetComponent<My::MeshRenderer>();*/
			// main camera
		My::Camera* mainCamara = renderer::mainCamera;

		My::Camera::SetGpuViewMatrix(mainCamara->GetViewMatrix());
		My::Camera::SetGpuProjectionMatrix(mainCamara->GetProjectionMatrix());

		debugObj->Render();
	}
}
