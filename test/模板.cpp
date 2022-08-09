#include <iostream>
#include <memory>
#include "../tyrannosaur/tyrannosaur.hpp"
#include <GL/freeglut.h>

struct UserData
{
	Tyrannosaur::Program program;
};

void display();
void keyboard(unsigned char key, int, int);

void init();
void term();

int main(int argc, char* argv[])
{
	std::shared_ptr<UserData> ud = std::make_shared<UserData>();

	Tyrannosaur::initFreeGLUT(&argc, argv);
	Tyrannosaur::createWindow();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSetWindowData(ud.get());

	init();

	glutMainLoop();

	term();

	return EXIT_SUCCESS;
}

void display()
{
	UserData* ud = (UserData*)glutGetWindowData();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int, int)
{
	UserData* ud = (UserData*)glutGetWindowData();

	if (key == 27) glutLeaveMainLoop();
}

void init()
{
	UserData* ud = (UserData*)glutGetWindowData();
}

void term()
{
	UserData* ud = (UserData*)glutGetWindowData();
}
