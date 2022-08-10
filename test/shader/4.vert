#version 330 core

layout(location=0)in vec3 a_position;
layout(location=1)in vec4 a_color;
out vec4 v_color;

uniform mat4 u_projection;
uniform mat4 u_view;
uniform mat4 u_model;

void main()
{
	gl_Position = u_projection * u_view * u_model * vec4(a_position,1.0);
	v_color = a_color;
}
