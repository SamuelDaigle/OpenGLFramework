#pragma once

#include "..\Dependencies\bullet\src\btBulletDynamicsCommon.h"
#include "..\Math\Vector3.h"
#include "..\Framework\Component.h"
#include "..\Framework\BaseObject.h"

namespace Physics
{

	class Rigidbody : public Framework::Component
	{
	public:
		Rigidbody(Framework::BaseObject& _baseObject, btCollisionShape& _shape, float _mass);
		~Rigidbody();

		btRigidBody& GetPhysicsRigidbody();

		void Update() override;
		void Render(const ICamera& _camera, const Math::Matrix4& _worldMatrix, const Math::Matrix4& _localWorldMatrix) const override;

	private:
		Framework::BaseObject* m_baseObject;
		btRigidBody* m_rigidbody;
	};

}