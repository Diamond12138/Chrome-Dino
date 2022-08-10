#include <iostream>
#include "../tyrannosaur/tyrannosaur.hpp"

void out(glm::vec2 vec)
{
	std::cout << vec.x << "," << vec.y;
}

void out(std::string name,Tyrannosaur::BoxShape box)
{
	std::cout << name << std::endl << "posiiton:";
	out(box.position);
	std::cout << std::endl << "half:";
	out(box.half);
	std::cout << std::endl << std::endl;
}

void out(std::string name1,Tyrannosaur::BoxShape box1,std::string name2,Tyrannosaur::BoxShape box2)
{
	std::cout << name1 << " and " << name2 << ":" << Tyrannosaur::is_collision(box1,box2) << std::endl << std::endl;
}

int main()
{
	Tyrannosaur::BoxShape box1 = Tyrannosaur::BoxShape::create(glm::vec2(0.1,0.1),glm::vec2(0.1,0.1));
	Tyrannosaur::BoxShape box2 = Tyrannosaur::BoxShape::create(glm::vec2(0.05,0.1),glm::vec2(0.1,0.1));
	Tyrannosaur::BoxShape box3 = Tyrannosaur::BoxShape::create(glm::vec2(0.0,0.2),glm::vec2(0.1,0.1));
	
	out("box1",box1);
	out("box2",box2);
	out("box3",box3);
	
	out("box1",box1,"box2",box2);
	out("box1",box1,"box3",box3);
	out("box2",box2,"box3",box3);
	return 0;
}
