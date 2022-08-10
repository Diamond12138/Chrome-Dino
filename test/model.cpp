#include <iostream>
#include <memory>
#include "../tyrannosaur/tyrannosaur.hpp"
#include <GL/freeglut.h>

struct UserData
{
	Tyrannosaur::Program program;
	Tyrannosaur::Model plane;
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

	glClear(GL_COLOR_BUFFER_BIT);
	ud->program.use();
	ud->plane.VAO.bindObject();
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);

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

	if (!Tyrannosaur::initGL()) exit(EXIT_FAILURE);
	
	ud->program.loadFromFile("shader/2.vert","shader/2.frag");
	
	ud->plane = Tyrannosaur::createPlane(glm::vec2(0.5f,0.5f),glm::vec4(1,0,0,1));
}

void term()
{
	UserData* ud = (UserData*)glutGetWindowData();

	ud->program.deleteObject();
	ud->plane.VAO.deleteObject();
}
