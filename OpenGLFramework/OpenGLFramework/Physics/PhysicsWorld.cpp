#include "PhysicsWorld.h"

namespace Physics
{

	PhysicsWorld::PhysicsWorld()
	{
		m_broadphase = new btDbvtBroadphase();
		m_collisionConfiguration = new btDefaultCollisionConfiguration();
		m_dispatcher = new btCollisionDispatcher(m_collisionConfiguration);
		m_solver = new btSequentialImpulseConstraintSolver;
		m_dynamicsWorld = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase, m_solver, m_collisionConfiguration);

		m_dynamicsWorld->setGravity(btVector3(0, -10, 0));
	}


	PhysicsWorld::~PhysicsWorld()
	{
	}

	void PhysicsWorld::AddRigidbody(Rigidbody& _rigidbody)
	{
		m_rigidbodies.push_back(&_rigidbody);
		btRigidBody* rigidbody = &_rigidbody.GetPhysicsRigidbody();
		m_dynamicsWorld->addRigidBody(rigidbody);
	}

	void PhysicsWorld::Update()
	{
		m_dynamicsWorld->stepSimulation(1 / 60.0f, 10);
		btTransform trans;
		m_rigidbodies[0]->GetPhysicsRigidbody().getMotionState()->getWorldTransform(trans);
	}

}