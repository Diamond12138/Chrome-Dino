#include <iostream>
#include <memory>
#include "../tyrannosaur/tyrannosaur.hpp"
#include <GL/freeglut.h>

struct UserData
{
	Tyrannosaur::Program program;
	GLuint vao;
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
	glBindVertexArray(ud->vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
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

	float ver[] =
	{
		0, 1,
		-1, -1,
		1, -1
	};
	float col[] =
	{
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
	};

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	GLuint vbo[2];
	glGenBuffers(2, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(ver), ver, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(col), col, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(2, vbo);
	ud->vao = vao;
	Tyrannosaur::logi("vao:",vao);
	//std::cout << Tyrannosaur::toStrings(1,",",2,",",3) << std::endl;
	
	ud->program.loadFromFile("shader/1.vert","shader/1.frag");
}

void term()
{
	UserData* ud = (UserData*)glutGetWindowData();

	ud->program.deleteObject();
	glDeleteVertexArrays(1, &ud->vao);
}
