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

	//grassleft1
	glUniform3fv(unifRotate, 1, grassLeftRotate);
	glUniform3fv(unifMove, 1, grassLeft1Move);
	glUniform3fv(unifScale, 1, grassScale);
	glActiveTexture(GL_TEXTURE0);
	sf::Texture::bind(&grassTextureData);
	glUniform1i(unifTexture, 0);
	glBindVertexArray(grassVAO);
	glDrawArrays(GL_TRIANGLES, 0, grass_count);
	glBindVertexArray(0);
	//grassleft2
	glUniform3fv(unifRotate, 1, grassLeftRotate);
	glUniform3fv(unifMove, 1, grassLeft2Move);
	glUniform3fv(unifScale, 1, grassScale);
	glActiveTexture(GL_TEXTURE0);
	sf::Texture::bind(&grassTextureData);
	glUniform1i(unifTexture, 0);
	glBindVertexArray(grassVAO);
	glDrawArrays(GL_TRIANGLES, 0, grass_count);
	glBindVertexArray(0);
	//grassleft3
	glUniform3fv(unifRotate, 1, grassLeftRotate);
	glUniform3fv(unifMove, 1, grassLeft3Move);
	glUniform3fv(unifScale, 1, grassScale);
	glActiveTexture(GL_TEXTURE0);
	sf::Texture::bind(&grassTextureData);
	glUniform1i(unifTexture, 0);
	glBindVertexArray(grassVAO);
	glDrawArrays(GL_TRIANGLES, 0, grass_count);
	glBindVertexArray(0);

	//grassright1
	glUniform3fv(unifRotate, 1, grassRightRotate);
	glUniform3fv(unifMove, 1, grassRight1Move);
	glUniform3fv(unifScale, 1, grassScale);
	glActiveTexture(GL_TEXTURE0);
	sf::Texture::bind(&grassTextureData);
	glUniform1i(unifTexture, 0);
	glBindVertexArray(grassVAO);
	glDrawArrays(GL_TRIANGLES, 0, grass_count);
	glBindVertexArray(0);
	//grassright2
	glUniform3fv(unifRotate, 1, grassRightRotate);
	glUniform3fv(unifMove, 1, grassRight2Move);
	glUniform3fv(unifScale, 1, grassScale);
	glActiveTexture(GL_TEXTURE0);
	sf::Texture::bind(&grassTextureData);
	glUniform1i(unifTexture, 0);
	glBindVertexArray(grassVAO);
	glDrawArrays(GL_TRIANGLES, 0, grass_count);
	glBindVertexArray(0);
	//grassright3
	glUniform3fv(unifRotate, 1, grassRightRotate);
	glUniform3fv(unifMove, 1, grassRight3Move);
	glUniform3fv(unifScale, 1, grassScale);
	glActiveTexture(GL_TEXTURE0);
	sf::Texture::bind(&grassTextureData);
	glUniform1i(unifTexture, 0);
	glBindVertexArray(grassVAO);
	glDrawArrays(GL_TRIANGLES, 0, grass_count);
	glBindVertexArray(0);

	glUseProgram(0);
	checkOpenGLerror();
}