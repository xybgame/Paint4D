#version 440
#extension GL_EXT_gpu_shader4 : enable
out vec4 FragColor;
in vec3 outuv;
uniform sampler2D tex;
void main()
{
    FragColor=texture2D(tex,outuv.xy);
}
