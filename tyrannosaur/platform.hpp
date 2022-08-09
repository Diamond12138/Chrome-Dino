#ifndef platform_hpp
#define platform_hpp

#include <iostream>
#include <string>
#include <GL/freeglut.h>

namespace Tyrannosaur
{
	void _freeglut_error(const char* fmt, va_list ap)
	{
		char buf[1024];
		sprintf(buf, fmt, ap);
		std::cout << buf << std::endl;
	}

	void initFreeGLUT(int* argc,char** argv,int major = 3, int minor = 3)
	{
		glutInit(argc,argv);
		glutInitErrorFunc(_freeglut_error);
		glutInitWarningFunc(_freeglut_error);
		glutInitContextFlags(GLUT_FORWARD_COMPATIBLE | GLUT_DEBUG);
		glutInitContextProfile(GLUT_CORE_PROFILE);
		glutInitContextVersion(major, minor);
	}
	
	void createWindow(std::string title = "",bool fullscreen = false)
	{
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
		glutCreateWindow(title.data());
		if(fullscreen)
		{
			glutFullScreen();
		}
	}
}

#endif
