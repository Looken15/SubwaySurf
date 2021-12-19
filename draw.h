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
	glUniform3fv(unifRotate, 1, busRotate);
	glUniform3fv(unifMove, 1, busMove);
	glUniform3fv(unifScale, 1, busScale);
	glActiveTexture(GL_TEXTURE0);
	sf::Texture::bind(&busTextureData);
	glUniform1i(unifTexture, 0);
	glBindVertexArray(busVAO);
	glDrawArrays(GL_TRIANGLES, 0, bus_count);
	glBindVertexArray(0);

	//road1
	glUniform3fv(unifRotate, 1, roadRotate);
	glUniform3fv(unifMove, 1, road1Move);
	glUniform3fv(unifScale, 1, roadScale);
	glActiveTexture(GL_TEXTURE0);
	sf::Texture::bind(&roadTextureData);
	glUniform1i(unifTexture, 0);
	glBindVertexArray(roadVAO);
	glDrawArrays(GL_TRIANGLES, 0, road_count);
	glBindVertexArray(0);

	//road2
	glUniform3fv(unifRotate, 1, roadRotate);
	glUniform3fv(unifMove, 1, road2Move);
	glUniform3fv(unifScale, 1, roadScale);
	glActiveTexture(GL_TEXTURE0);
	sf::Texture::bind(&roadTextureData);
	glUniform1i(unifTexture, 0);
	glBindVertexArray(roadVAO);
	glDrawArrays(GL_TRIANGLES, 0, road_count);
	glBindVertexArray(0);

	//road3
	glUniform3fv(unifRotate, 1, roadRotate);
	glUniform3fv(unifMove, 1, road3Move);
	glUniform3fv(unifScale, 1, roadScale);
	glActiveTexture(GL_TEXTURE0);
	sf::Texture::bind(&roadTextureData);
	glUniform1i(unifTexture, 0);
	glBindVertexArray(roadVAO);
	glDrawArrays(GL_TRIANGLES, 0, road_count);
	glBindVertexArray(0);

	glUseProgram(0);
	checkOpenGLerror();
}