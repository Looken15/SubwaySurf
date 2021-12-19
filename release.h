#pragma once

#include <gl/glew.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "id.h"

void ReleaseShader() {
	glUseProgram(0);
	glDeleteProgram(shaderProgram);
}

// Освобождение буфера
void ReleaseVBO()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteVertexArrays(1, &road1VAO);
	glDeleteBuffers(1, &road1VBO);
}

void Release() {
	ReleaseShader();
	ReleaseVBO();
}