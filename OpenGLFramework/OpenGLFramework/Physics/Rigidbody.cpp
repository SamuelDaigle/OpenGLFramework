#include "Rigidbody.h"

namespace Physics
{

	Rigidbody::Rigidbody(Framework::BaseObject& _baseObject, btCollisionShape& _shape, float _mass) :
		m_baseObject(&_baseObject)
	{
		btDefaultMotionState* fallMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(_baseObject.m_position.x, _baseObject.m_position.y, _baseObject.m_position.z)));
		btScalar mass = _mass;
		btVector3 fallInertia(0, 0, 0);
		if (_mass != 0)
			_shape.calculateLocalInertia(_mass, fallInertia);
		btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, &_shape, fallInertia);
		m_rigidbody = new btRigidBody(fallRigidBodyCI);
	}

	Rigidbody::~Rigidbody()
	{
	}

	void Rigidbody::Update()
	{
		btTransform transform;
		m_rigidbody->getMotionState()->getWorldTransform(transform);
		m_baseObject->m_position.x = transform.getOrigin().getX();
		m_baseObject->m_position.y = transform.getOrigin().getY();
		m_baseObject->m_position.z = transform.getOrigin().getZ();
	}

	void Rigidbody::Render(const ICamera& _camera, const Math::Matrix4& _worldMatrix, const Math::Matrix4& _localWorldMatrix) const
	{

	}

	btRigidBody& Rigidbody::GetPhysicsRigidbody()
	{
		return *m_rigidbody;
	}

}