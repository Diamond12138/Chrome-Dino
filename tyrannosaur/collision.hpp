#ifndef collision_hpp
#define collision_hpp

#include "math.hpp"
#include <glm/glm.hpp>

namespace Tyrannosaur
{
	class CollisionShape {};

	class CollisionShape2D : public CollisionShape
	{
		public:
			glm::vec2 position;
	};

	class BoxShape : public CollisionShape2D
	{
		public:
			glm::vec2 half;

		public:
			BoxShape() {}

		public:
			static BoxShape create(glm::vec2 left_top, glm::vec2 size)
			{
				glm::vec2 half = size / 2.0f;
				glm::vec2 position = glm::vec2(left_top.x + half.x, left_top.y - half.y);
				BoxShape result;
				result.position = position;
				result.half = half;
				return result;
			}
	};

	class AxisAlignmentLineShape : public CollisionShape2D
	{
		public:
			float distance;
	};

	class YAxisAlignmentLineShape : public AxisAlignmentLineShape
	{
		public:
			static YAxisAlignmentLineShape create(float distance)
			{
				YAxisAlignmentLineShape result;
				result.distance = distance;
				return result;
			}
	};

	bool is_collision(BoxShape box1, BoxShape box2)
	{
		glm::vec2 delta = abs(box1.position - box2.position);
		glm::vec2 half_sum = box1.half + box2.half;
		return ((delta.x <= half_sum.x) && (delta.y <= half_sum.y));
	}

	bool is_collision(BoxShape box, YAxisAlignmentLineShape line)
	{
		float top = box.position.y + box.half.y;
		float bottom = box.position.y - box.half.y;
		return ((top > line.distance)&&(bottom < line.distance));
	}
}

#endif
