#ifndef math_hpp
#define math_hpp

#include <cmath>
#include <glm/glm.hpp>

namespace Tyrannosaur
{
	glm::vec2 abs(glm::vec2 value)
	{
		float x = std::abs(value.x);
		float y = std::abs(value.y);
		return glm::vec2(x,y);
	}
}

#endif
