
#include <iostream>
#include <memory>
#include "../tyrannosaur/tyrannosaur.hpp"
#include <GL/freeglut.h>

struct UserData
{
	Tyrannosaur::Program program;
	Tyrannosaur::Sprite plane;
	Tyrannosaur::Camera camera;
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
	Tyrannosaur::postCameraMatrix(ud->program,ud->camera);
	Tyrannosaur::postModelMatrix(ud->program,ud->plane);
	ud->plane.draw(GL_TRIANGLES,0,6);

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
	
	ud->program.loadFromFile("shader/4.vert","shader/4.frag");
	
	Tyrannosaur::Model plane_model = Tyrannosaur::createPlane(glm::vec2(0.5f,0.5f),glm::vec4(0,1,0,1));
	ud->plane = Tyrannosaur::createSprite(plane_model);
	
	ud->camera.viewport *= 0.1f;
	ud->camera.position = glm::vec3(1,1,1);
	ud->camera.front = -ud->camera.position;
	ud->camera.updateProjectionMatrix();
	ud->camera.updateViewMatrix();
	
	glViewport(0,0,glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT));
}

void term()
{
	UserData* ud = (UserData*)glutGetWindowData();

	ud->program.deleteObject();
	ud->plane.VAO.deleteObject();
}
