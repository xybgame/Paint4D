#version 440
#extension GL_EXT_gpu_shader4 : enable
attribute vec4 pos;
attribute vec3 nor;
attribute vec3 uv;

uniform mat4 pers;
uniform mat4 trans;
uniform mat4 scale;
uniform mat4 rotx;
uniform mat4 roty;

out vec3 outuv;
void main()
{
    outuv=uv;
    gl_Position=pos*scale*rotx*roty*trans*pers;
}
