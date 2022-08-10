#ifndef sprites_hpp
#define sprites_hpp

#include "sprite.hpp"
#include "texture.hpp"
//#include "physics.hpp"

namespace Tyrannosaur
{
	class TextureSprite : public Sprite, public Texture
	{
		public:
			Texture texture;

		public:
			TextureSprite() {}

		public:
			void setTexture(Texture tex)
			{
				texture = tex;
			}

		public:
			virtual void draw(GLenum mode, GLint first, GLsizei count)
			{
				texture.bindObject();
				Renderable::draw(mode,first,count);
			}
	};
	
	TextureSprite createTextureSprite(Model model,Texture texture)
	{
		TextureSprite sprite;
		sprite.VAO = model.VAO;
		sprite.texture = texture;
		return sprite;
	}

	/*class RigidBodySprite2D : public Sprite, public RigidBody2D {};
	class RigidBodyTextureSprite2D : public Sprite, public Texture, public RigidBody {};*/
}

#endif
