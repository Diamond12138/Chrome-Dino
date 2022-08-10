#ifndef gl_hpp
#define gl_hpp

#include "log.hpp"
#include <GL/glew.h>

namespace Tyrannosaur
{
	void GLAPIENTRY _gl_debug(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
	{
		std::cout << std::hex
		          << "source:0x" << source << std::endl
		          << "type:0x" << type << std::endl
		          << "id:0x" << id << std::endl
		          << "severity:0x" << severity << std::endl
		          << std::dec
		          << "length:" << length << std::endl
		          << "message:" << message << std::endl
		          << "userParam:" << userParam << std::endl;
	}

	bool initGL()
	{
		bool success = (glewInit() == GLEW_OK);
		if (success)
		{
			logi("GL loaded successfully.");
			glDebugMessageCallback(_gl_debug, nullptr);
		}
		else
		{
			loge("Failed to load GL.");
		}
		return success;
	}
}

#endif
