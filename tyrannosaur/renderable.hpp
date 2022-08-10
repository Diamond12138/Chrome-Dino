#ifndef renderable_hpp
#define renderable_hpp

#include "gl.hpp"
#include "modelbuilder.hpp"

namespace Tyrannosaur
{
	class Renderable
	{
		public:
			VertexArrayObject VAO;

		public:
			virtual void draw(GLenum mode, GLint first, GLsizei count)
			{
				glBindVertexArray(VAO.objectID);
				glDrawArrays(mode, first, count);
				glBindVertexArray(0);
			}
	};
}

#endif
