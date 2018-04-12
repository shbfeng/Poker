/*!
 * \file SceneNode.h
 *
 * \author LYG
 * \date ���� 2018
 *
 * 
 */
#pragma once
#include "Common.h"
#include "Math/SimpleMath.h"
#include "Math/Vector3.h"
#include "Math/Quaternion.h"
#include "Math/Matrix4.h"
#include "Mesh.h"
#include <vector>

class SceneNode
{
	friend class Scene;
public:
	std::string GetName() const;
	Vector3 GetPosition() const;
	Quaternion GetRotation() const;
	Vector3 GetScale() const;

	Vector3 GetWorldPosition() const;
	Quaternion GetWorldRotation() const;
	Vector3 GetWorldScale() const;

	void SetPosition(const Vector3& Pos);
	void SetRotation(const Quaternion& Rot);
	void SetScale(const Vector3& Scale);

	SceneNode* CreateChild(std::string Name, Vector3 Pos, Quaternion Rot, Vector3 Scale);
	bool RemoveChild(SceneNode* SN);
	bool RemoveChild(std::string Name);
	void RemoveAllChild();

	bool RemoveAndDestroyChild(std::string Name);
	bool RemoveAndDestroyChild(SceneNode* SN);
	void DestroyAllChild();

	bool AttachMesh(Mesh* M);
	bool DetachMesh(Mesh* M);

	int GetAttachMeshCount() const;
	Mesh* GetAttachMeshByIndex(int Index) const;
	Mesh* GetAttachMeshByName(std::string Name) const;

	int GetChildCount() const;
	SceneNode* GetChildByIndex(int Index) const;
	SceneNode* GetChildByName(std::string Name) const;

	Matrix4 GetWorldTransform() const;
protected:
	SceneNode(std::string Name);
	~SceneNode();

	void _NotifyModify(SceneNode* Parent);
private:
	SceneNode* mParentNode;
	std::string mName;

	Vector3 mPosition;
	Quaternion mRotation;
	Vector3 mScale;

	Vector3 mWorldPosition;
	Quaternion mWorldRotation;
	Vector3 mWorldScale;

	std::vector<SceneNode*> mChildArray;
	std::vector<Mesh*> mAttachMeshArray;
};
