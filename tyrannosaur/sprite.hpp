#ifndef sprite_hpp
#define sprite_hpp

#include "modelbuilder.hpp"
#include "matrix.hpp"
#include "renderable.hpp"

namespace Tyrannosaur
{
	class Sprite : public Transform, public Renderable
	{
		public:
			Sprite() {}
	};

	Sprite createSprite(Model model)
	{
		Sprite result;
		result.VAO = model.VAO;
		return result;
	}
}

#endif
