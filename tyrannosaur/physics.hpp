#ifndef physics_hpp
#define physics_hpp

#include "collision.hpp"

namespace Tyrannosaur
{
	class RigidBody
	{
		public:
			enum RigidBodyState
			{
				ACTIVE,
				STATIC
			};

		public:
			RigidBodyState state = RigidBodyState::ACTIVE;
	};

	class RigidBody2D : public RigidBody, public CollisionShape2D
	{
		public:
			glm::vec2 velocity = glm::vec2(0.0f, 0.0f);
			CollisionShape2D shape;
	};

	class BoxRigidBody : public RigidBody2D, public BoxShape
	{
		public:
			static BoxRigidBody createActive(glm::vec2 posiiton, glm::vec2 size, glm::vec2 velocity = glm::vec2(0.0f, 0.0f))
			{
				BoxRigidBody result;
				result.shape = BoxShape::create(posiiton, size);
				result.velocity = velocity;
				return result;
			}

			static BoxRigidBody createStatic(glm::vec2 posiiton, glm::vec2 size)
			{
				BoxRigidBody result;
				result.shape = BoxShape::create(posiiton, size);
				result.state = RigidBodyState::STATIC;
				return result;
			}
	};

	class YAxisAlignmentLineRigidBody : public RigidBody2D, public YAxisAlignmentLineShape
	{
		public:
			static YAxisAlignmentLineRigidBody createActive(float distance, glm::vec2 velocity = glm::vec2(0.0f, 0.0f))
			{
				YAxisAlignmentLineRigidBody result;
				result.shape = YAxisAlignmentLineShape::create(distance);
				result.velocity = velocity;
				return result;
			}

			static YAxisAlignmentLineRigidBody createStatic(float distance)
			{
				YAxisAlignmentLineRigidBody result;
				result.shape = YAxisAlignmentLineShape::create(distance);
				result.state = RigidBodyState::STATIC;
				return result;
			}
	};

	void updateRigidBody(RigidBody2D& rigidbody, glm::vec2 gravity, float deltaTime)
	{
		if (rigidbody.state == RigidBody::RigidBodyState::ACTIVE)
		{
			rigidbody.velocity += gravity * deltaTime;
			rigidbody.shape.position += rigidbody.velocity * deltaTime;
		}
	}

	void checkCollision(BoxRigidBody& rigidbody1, YAxisAlignmentLineRigidBody& rigidbody2)
	{
		if (rigidbody1.state == RigidBody::RigidBodyState::STATIC && rigidbody2.state == RigidBody::RigidBodyState::STATIC)
		{
			return;
		}
		else if (rigidbody1.state == RigidBody::RigidBodyState::ACTIVE && rigidbody2.state == RigidBody::RigidBodyState::STATIC)
		{
			if(is_collision((BoxShape)rigidbody1.shape,(YAxisAlignmentLineShape)rigidbody2.shape))
			{
				
			}
		}
		else if (rigidbody1.state == RigidBody::RigidBodyState::STATIC && rigidbody2.state == RigidBody::RigidBodyState::ACTIVE)
		{

		}
	}
}

#endif
