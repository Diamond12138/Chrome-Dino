#include <iostream>
#include <memory>
#include "../tyrannosaur/tyrannosaur.hpp"
#include <GL/freeglut.h>

struct UserData
{
	Tyrannosaur::Program program_texture;
	Tyrannosaur::Texture texture_ground;
	Tyrannosaur::TextureSprite sprite_ground;
	Tyrannosaur::Model model_ground;
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
	ud->program_texture.use();
	Tyrannosaur::postCameraMatrix(ud->program_texture,ud->camera);
	Tyrannosaur::postModelMatrix(ud->program_texture,ud->sprite_ground);
	ud->sprite_ground.draw(GL_TRIANGLES,0,6);

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
	
	Tyrannosaur::initGL();
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	ud->program_texture.loadFromFile("shader/vertex.vert","shader/texture.frag");
	ud->texture_ground.loadFromFile("resources/desert.png");
	ud->model_ground = Tyrannosaur::createPlane(glm::vec2(0.5,0.05));
	
	ud->camera.updateViewMatrix();
	ud->camera.updateProjectionMatrix();
	
	ud->sprite_ground = Tyrannosaur::createTextureSprite(ud->model_ground,ud->texture_ground);
	ud->sprite_ground.translate = glm::vec3(0,-0,0);
	ud->sprite_ground.update();
}

void term()
{
	UserData* ud = (UserData*)glutGetWindowData();
	
	ud->program_texture.deleteObject();
}
