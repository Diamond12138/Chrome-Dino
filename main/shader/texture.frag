#version 330 core

in vec2 v_texCoord;
out vec4 o_color;

uniform sampler2D u_sampler;

void main()
{
	vec4 color = texture(u_sampler,v_texCoord);
	if(color == vec4(0.0,1.0,0.0,1.0))
	{
		color.a = 0.0f;
	}
	o_color -= color;
}
