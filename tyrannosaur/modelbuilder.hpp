#ifndef model_builder_hpp
#define model_builder_hpp

#include "gl.hpp"
#include "globject.hpp"
#include "bindable.hpp"
#include "program.hpp"
#include <glm/glm.hpp>
#include <vector>

namespace Tyrannosaur
{
	class VertexArrayObject : public GLObject, public Bindable
	{
		public:
			VertexArrayObject() {}

		public:
			virtual void genObject()
			{
				glGenVertexArrays(1, &objectID);
			}

			virtual void bindObject()
			{
				glBindVertexArray(objectID);
			}

			virtual void deleteObject()
			{
				if (!is_null())
				{
					glDeleteVertexArrays(1, &objectID);
				}
			}
	};

	class Model
	{
		public:
			std::vector<float> vertices;
			std::vector<float> colors;
			std::vector<float> normals;
			std::vector<float> texCoords;
			VertexArrayObject VAO;
	};

	GLuint bindVBO(GLuint location, GLuint size, std::vector<float> vertices)
	{
		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
		glEnableVertexAttribArray(location);
		glVertexAttribPointer(location, size, GL_FLOAT, GL_FALSE, size * sizeof(float), nullptr);
		return vbo;
	}

	Model createPlane(glm::vec2 half, glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f))
	{
		std::vector<float> ver
		{
			-half.x, half.y, 0.0f,
			    -half.x, -half.y, 0.0f,
			    half.x, -half.y, 0.0f,

			    -half.x, half.y, 0.0f,
			    half.x, -half.y, 0.0f,
			    half.x, half.y, 0.0f,
		    };

		std::vector<float> col =
		{
			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w,

			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w,
			color.x, color.y, color.z, color.w,
		};

		std::vector<float> nor =
		{
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f,

			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f,
		};

		std::vector<float> tex =
		{
			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,

			0.0f, 0.0f,
			1.0f, 1.0f,
			1.0f, 0.0f
		};

		GLuint vao;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		GLuint vbo[] =
		{
			bindVBO(VertexAttribLocation::POSITION, 3, ver),
			bindVBO(VertexAttribLocation::COLOR, 4, col),
			bindVBO(VertexAttribLocation::NORMAL, 3, nor),
			bindVBO(VertexAttribLocation::TEX_COORD, 2, tex)
		};
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER,0);
		glDeleteBuffers(4,vbo);
		
		Model result;
		result.VAO.objectID = vao;
		result.vertices = ver;
		result.colors = col;
		result.normals = nor;
		result.texCoords = tex;
		return result;
	}
}

#endif
