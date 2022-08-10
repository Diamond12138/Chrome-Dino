#include <iostream>
#include "../tyrannosaur/tyrannosaur.hpp"

void out(std::string name, glm::vec2 vec)
{
	std::cout << name << vec.x << "," << vec.y << std::endl;
}

int main()
{
	const glm::vec2 gravity = glm::vec2(0, -0.5);

	Tyrannosaur::BoxRigidBody rb1 = Tyrannosaur::BoxRigidBody::createActive(glm::vec2(0,0.1),glm::vec2(0.1,0.1),glm::vec2(0, 0.5));
	Tyrannosaur::YAxisAlignmentLineRigidBody rb2 = Tyrannosaur::YAxisAlignmentLineRigidBody::createStatic(0);

	for (float i = 0; i < 5; i += 0.01)
	{
		Tyrannosaur::updateRigidBody(rb1, gravity, 0.01);
		Tyrannosaur::updateRigidBody(rb2, gravity, 0.01);

		/*std::cout << i << std::endl;
		out("rb1.position", rb1.position);
		out("rb2.position", rb2.position);
		std::cout << std::endl;*/
		
		int spaces = rb1.shape.position.y * 100;
		for(int j = 0;j < spaces + 20;j++)
		{
			std::cout << " ";
		}
		if(spaces >= 0) std::cout << "rb1" << std::endl;
	}

	return 0;
}
