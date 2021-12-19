#pragma once

#include <gl/glew.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "id.h"
#include "structures.h"
#include "log.h"
#include "uniforms.h"

void Draw() {
	// Устанавливаем шейдерную программу текущей
	glUseProgram(shaderProgram);

	//bus
	/*glUniform3fv(unifRotate, 1, busRotate);
	glActiveTexture(GL_TEXTURE0);
	sf::Texture::bind(&roadTextureData);
	glUniform1i(unifTexture, 0);
	glBindVertexArray(road1VAO);
	glDrawArrays(GL_TRIANGLES, 0, 1000000);
	glBindVertexArray(0);*/

	//road1
	glUniform3fv(unifRotate, 1, busRotate);
	glUniform3fv(unifRoad1Move, 1, road1Move);
	glActiveTexture(GL_TEXTURE0);
	sf::Texture::bind(&roadTextureData);
	glUniform1i(unifTexture, 0);
	glBindVertexArray(road1VAO);
	glDrawArrays(GL_TRIANGLES, 0, 1000000);
	glBindVertexArray(0);

	//road2
	glUniform3fv(unifRotate, 1, busRotate);
	glUniform3fv(unifRoad1Move, 1, road2Move);
	glActiveTexture(GL_TEXTURE0);
	sf::Texture::bind(&roadTextureData);
	glUniform1i(unifTexture, 0);
	glBindVertexArray(road1VAO);
	glDrawArrays(GL_TRIANGLES, 0, 1000000);
	glBindVertexArray(0);

	//road3
	glUniform3fv(unifRotate, 1, busRotate);
	glUniform3fv(unifRoad1Move, 1, road3Move);
	glActiveTexture(GL_TEXTURE0);
	sf::Texture::bind(&roadTextureData);
	glUniform1i(unifTexture, 0);
	glBindVertexArray(road1VAO);
	glDrawArrays(GL_TRIANGLES, 0, 1000000);
	glBindVertexArray(0);

	glUseProgram(0);
	checkOpenGLerror();
}