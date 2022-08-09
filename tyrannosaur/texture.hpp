#ifndef texture_hpp
#define texture_hpp

#include "gl.hpp"
#include "globject.hpp"
#include "bindable.hpp"
#include "log.hpp"

#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

namespace Tyrannosaur
{
	class Texture : public GLObject,public Bindable
	{
		public:
			GLenum textureType;
			
		public:
			Texture() {}
			
		public:
			bool loadFromFile(std::string filename,GLenum type = GL_TEXTURE_2D)
			{
				textureType = type;
				glBindTexture(textureType, objectID);
				glTexParameteri(textureType, GL_TEXTURE_WRAP_S, GL_REPEAT);   
				glTexParameteri(textureType, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				int width, height, nrChannels;
				unsigned char *data = stbi_load(filename.data(), &width, &height, &nrChannels, 0);
				if (data != nullptr)
				{
					GLenum format = (nrChannels == 3 ? GL_RGB : GL_RGBA);
				    glTexImage2D(textureType, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
				    glGenerateMipmap(textureType);
				    logi("Texture successfully loaded from \"",filename,"\"");
				}
				else
				{
				    loge("Unable to load texture from file \"",filename,"\"");
				    return false;
				}
				stbi_image_free(data);
				glBindTexture(textureType,0);
				return true;
			}
			
		public:
			virtual void genObject()
			{
				glGenTextures(1,&objectID);
			}
			
			virtual void bindObject()
			{
				glBindTexture(textureType,objectID);
			}
			
			virtual void deleteObject()
			{
				if(!is_null())
				{
					glDeleteTextures(1,&objectID);
				}
			}
	};
}

#endif
