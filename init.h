#pragma once

#include <gl/glew.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#include "parser.h"
#include "log.h"
#include "id.h"
#include "vertShader.h"
#include "fragShader.h"

int road_count = 0;
int bus_count = 0;
int grass_count = 0;

void InitVBO()
{
	//road
	std::vector<float> pos_tex = InitializeVBO("models/road.obj", road_count);

	glGenBuffers(1, &roadVBO);
	glGenVertexArrays(1, &roadVAO);

	glBindVertexArray(roadVAO);

	glEnableVertexAttribArray(attribVertex);
	glEnableVertexAttribArray(attribTex);
	glEnableVertexAttribArray(attribNormal);
	glBindBuffer(GL_ARRAY_BUFFER, roadVBO);
	glBufferData(GL_ARRAY_BUFFER, pos_tex.size() * sizeof(GLfloat), pos_tex.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(attribVertex, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glVertexAttribPointer(attribTex, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glVertexAttribPointer(attribNormal, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	//bus
	pos_tex = InitializeVBO("models/bus2.obj", bus_count);

	glGenBuffers(1, &busVBO);
	glGenVertexArrays(1, &busVAO);

	glBindVertexArray(busVAO);

	glEnableVertexAttribArray(attribVertex);
	glEnableVertexAttribArray(attribTex);
	glEnableVertexAttribArray(attribNormal);
	glBindBuffer(GL_ARRAY_BUFFER, busVBO);
	glBufferData(GL_ARRAY_BUFFER, pos_tex.size() * sizeof(GLfloat), pos_tex.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(attribVertex, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glVertexAttribPointer(attribTex, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glVertexAttribPointer(attribNormal, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);

	//grass
	pos_tex = InitializeVBO("models/grass.obj", grass_count);

	glGenBuffers(1, &grassVBO);
	glGenVertexArrays(1, &grassVAO);

	glBindVertexArray(grassVAO);

	glEnableVertexAttribArray(attribVertex);
	glEnableVertexAttribArray(attribTex);
	glEnableVertexAttribArray(attribNormal);
	glBindBuffer(GL_ARRAY_BUFFER, grassVBO);
	glBufferData(GL_ARRAY_BUFFER, pos_tex.size() * sizeof(GLfloat), pos_tex.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(attribVertex, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glVertexAttribPointer(attribTex, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glVertexAttribPointer(attribNormal, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	checkOpenGLerror();
}

void InitShader() {
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &VertexShaderSource, NULL);
	glCompileShader(vShader);
	std::cout << "vertex shader \n";
	ShaderLog(vShader);

	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader, 1, &FragShaderSource, NULL);
	glCompileShader(fShader);
	std::cout << "fragment shader \n";
	ShaderLog(fShader);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vShader);
	glAttachShader(shaderProgram, fShader);

	glLinkProgram(shaderProgram);
	int link_status;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &link_status);
	if (!link_status)
	{
		std::cout << "error attach shaders \n";
		return;
	}

	attribVertex = glGetAttribLocation(shaderProgram, "coord");
	if (attribVertex == -1)
	{
		std::cout << "could not bind attrib coord" << std::endl;
		return;
	}

	attribTex = glGetAttribLocation(shaderProgram, "texcoord");
	if (attribVertex == -1)
	{
		std::cout << "could not bind attrib texcoord" << std::endl;
		return;
	}

	attribNormal = glGetAttribLocation(shaderProgram, "normal");
	if (attribNormal == -1)
	{
		std::cout << "could not bind attrib normal" << std::endl;
		return;
	}

	unifTexture = glGetUniformLocation(shaderProgram, "textureData");
	if (unifTexture == -1)
	{
		std::cout << "could not bind uniform textureData" << std::endl;
		return;
	}

	unifRotate = glGetUniformLocation(shaderProgram, "rotate");
	if (unifRotate == -1)
	{
		std::cout << "could not bind uniform rotate" << std::endl;
		return;
	}

	unifMove = glGetUniformLocation(shaderProgram, "move");
	if (unifMove == -1)
	{
		std::cout << "could not bind uniform move" << std::endl;
		return;
	}

	unifScale = glGetUniformLocation(shaderProgram, "scale");
	if (unifScale == -1)
	{
		std::cout << "could not bind uniform scale" << std::endl;
		return;
	}

	checkOpenGLerror();
}

void InitTexture()
{
	const char* road = "textures/road.png";
	const char* bus = "textures/bus2.png";
	const char* grass = "textures/grass.png";
	if (!busTextureData.loadFromFile(bus))
	{
		std::cout << "could not load texture bus";
		return;
	}
	if (!roadTextureData.loadFromFile(road))
	{
		std::cout << "could not load texture road";
		return;
	}
	if (!grassTextureData.loadFromFile(grass))
	{
		std::cout << "could not load texture grass";
		return;
	}
	roadTextureHandle = roadTextureData.getNativeHandle();
	busTextureHandle = busTextureData.getNativeHandle();
	busTextureHandle = grassTextureData.getNativeHandle();
}


void Init() {
	InitShader();
	InitVBO();
	InitTexture();
}