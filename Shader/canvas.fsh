#version 440
#extension GL_EXT_gpu_shader4 : enable
out vec4 FragColor;
in vec3 outuv;
void main()
{
    FragColor=vec4(outuv,1);
}
