#pragma once

// Исходный код фрагментного шейдера
const char* FragShaderSource = R"(
    #version 330 core

	uniform sampler2D textureData;

    in Vertex {
		vec2 texcoord;
		vec3 normal;
	} Vert;

	out vec4 color;

    void main() {
		color = texture(textureData, Vert.texcoord);
    }
)";