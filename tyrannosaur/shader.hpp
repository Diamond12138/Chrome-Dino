#ifndef shader_hpp
#define shader_hpp

#include "globject.hpp"
#include "stringbuilder.hpp"

namespace Tyrannosaur
{
	class Shader : public GLObject
	{
		public:
			GLenum shaderType;

		public:
			Shader() {}

		public:
			Shader& operator=(const Shader& from)
			{
				objectID = from.objectID;
				shaderType = from.shaderType;
				return *this;
			}

		public:
			void loadFromFile(GLenum type, std::string filename)
			{
				shaderType = type;
				std::string source = loadStringFromFile(filename);
				const char* source_ptr = source.data();
				objectID = glCreateShader(shaderType);
				glShaderSource(objectID, 1, &source_ptr, nullptr);
				glCompileShader(objectID);
			}

		public:
			virtual void deleteObject()
			{
				if (!is_null())
				{
					glDeleteShader(objectID);
					objectID = GL_NULL_OBJECT;
				}
			}
	};
}

#endif
