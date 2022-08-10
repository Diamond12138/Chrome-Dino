#ifndef program_hpp
#define program_hpp

#include "shader.hpp"
#include <glm/glm.hpp>

namespace Tyrannosaur
{
	enum VertexAttribLocation
	{
		POSITION = 0,
		COLOR = 1,
		NORMAL = 2,
		TEX_COORD = 3
	};
	
	class Program : public GLObject
	{
		public:
			Program() {}

		public:
			Program& operator=(const Program& from)
			{
				objectID = from.objectID;
				return *this;
			}

		public:
			virtual void deleteObject()
			{
				if (!is_null())
				{
					glDeleteProgram(objectID);
					objectID = 0;
				}
			}

		public:
			void loadFromFile(std::string vfilename, std::string ffilename)
			{
				Shader vs;
				vs.loadFromFile(GL_VERTEX_SHADER, vfilename);
				Shader fs;
				fs.loadFromFile(GL_FRAGMENT_SHADER, ffilename);

				objectID = glCreateProgram();
				glAttachShader(objectID, vs.objectID);
				glAttachShader(objectID, fs.objectID);
				glLinkProgram(objectID);

				vs.deleteObject();
				fs.deleteObject();
			}

			void use()
			{
				glUseProgram(objectID);
			}
			
			GLuint getUniformLocation(std::string name)
			{
				return glGetUniformLocation(objectID,name.data());
			}
			
			void setUniform(std::string name,glm::mat4 value,GLboolean transpose = GL_FALSE)
			{
				if(!is_null())
				{
					GLuint location = getUniformLocation(name);
					glUniformMatrix4fv(location,1,transpose,&value[0][0]);
				}
			}
	};
}

#endif
