#ifndef matrix_hpp
#define matrix_hpp

#include "program.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tyrannosaur
{
	const std::string UNIFORM_MODEL_MATRIX = "u_model";
	const std::string UNIFORM_VIEW_MATRIX = "u_view";
	const std::string UNIFORM_PROJECTION_MATRIX = "u_projection";
	
	class MatrixHolder
	{
		public:
			glm::mat4 matrix = glm::mat4(1.0f);
			
		public:
			MatrixHolder() {}
			
		public:
			virtual void update() = 0;
	};
	
	class Transform : public MatrixHolder
	{
		public:
			glm::vec3 translate = glm::vec3(0.0f,0.0f,0.0f);
			glm::vec3 rotate = glm::vec3(0.0f,0.0f,0.0f);
			glm::vec3 scale = glm::vec3(1.0f,1.0f,1.0f);
			
		public:
			Transform() {}
			
		public:
			virtual void update()
			{
				matrix = glm::mat4(1.0f);
				matrix = glm::translate(matrix,translate);
				matrix = glm::rotate(matrix,rotate.x,glm::vec3(0,0,0));
				matrix = glm::rotate(matrix,rotate.x,glm::vec3(0,0,0));
				matrix = glm::rotate(matrix,rotate.x,glm::vec3(0,0,0));
				matrix = glm::scale(matrix,scale);
			}
	};
	
	class View : public MatrixHolder
	{
		public:
			glm::vec3 position = glm::vec3(0.0f,0.0f,1.0f);
			glm::vec3 front = glm::vec3(0.0f,0.0f,-1.0f);
			glm::vec3 up = glm::vec3(0.0f,1.0f,0.0f);
			
		public:
			View() {}
			
		public:
			virtual void update()
			{
				matrix = glm::lookAt(position,position + front,up);
			}
	};
	
	class Projection : public MatrixHolder
	{
		public:
			enum ProjectionMode
			{
				FRUSTUM,
				ORTHO
			};
			
		public:
			ProjectionMode mode = ProjectionMode::FRUSTUM;
			glm::vec4 viewport = glm::vec4(-1.0f,1.0f,-1.0f,1.0f);
			glm::vec2 plane = glm::vec2(0.1f,100.0f);
			
		public:
			Projection() {}
			
		public:
			virtual void update()
			{
				if(mode == ProjectionMode::FRUSTUM)
				{
					matrix = glm::frustum(viewport.x,viewport.y,viewport.z,viewport.w,plane.x,plane.y);
				}
				if(mode == ProjectionMode::ORTHO)
				{
					matrix = glm::ortho(viewport.x,viewport.y,viewport.z,viewport.w,plane.x,plane.y);
				}
			}
	};
	
	class Camera : public View,public Projection
	{
		public:
			Camera() {}
			
		public:
			glm::mat4 getViewMatrix() const
			{
				return View::matrix;
			}
			glm::mat4 getProjectionMatrix() const
			{
				return Projection::matrix;
			}
			void updateViewMatrix()
			{
				View::update();
			}
			void updateProjectionMatrix()
			{
				Projection::update();
			}
	};
	
	void postModelMatrix(Program& program,const Transform& matrix)
	{
		program.setUniform(UNIFORM_MODEL_MATRIX,matrix.matrix);
	}
	
	void postCameraMatrix(Program& program,const Camera& camera)
	{
		program.setUniform(UNIFORM_VIEW_MATRIX,camera.getViewMatrix());
		program.setUniform(UNIFORM_PROJECTION_MATRIX,camera.getProjectionMatrix());
	}
}

#endif
