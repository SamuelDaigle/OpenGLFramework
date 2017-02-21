#pragma once

#include "..\Utils\Log.h"
#include "Rigidbody.h"
#include <vector>

namespace Physics
{

	class PhysicsWorld
	{
	public:
		PhysicsWorld();
		~PhysicsWorld();

		void AddRigidbody(Rigidbody& _rigidbody);
		void Update();

	private:
		btBroadphaseInterface* m_broadphase;
		btDefaultCollisionConfiguration* m_collisionConfiguration;
		btCollisionDispatcher* m_dispatcher;
		btSequentialImpulseConstraintSolver* m_solver;
		btDiscreteDynamicsWorld* m_dynamicsWorld;

		std::vector<Rigidbody*> m_rigidbodies;
	};

}