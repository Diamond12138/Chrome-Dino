#ifndef globject_hpp
#define globject_hpp

#include "gl.hpp"

namespace Tyrannosaur
{
	const GLuint GL_NULL_OBJECT = 0;
	
	class GLObject
	{
		public:
			GLuint objectID;
			
		public:
			GLObject& operator=(const GLObject& from)
			{
				objectID = from.objectID;
				return *this;
			}
			
		public:
			virtual void deleteObject() = 0;
			virtual bool is_null()
			{
				return (objectID == GL_NULL_OBJECT);
			}
	};
}

#endif
