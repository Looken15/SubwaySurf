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



void InitVBO()
{
	std::vector<float> pos_tex = InitializeVBO("models/road.obj");


	//bus
	glGenBuffers(1, &road1VBO);
	glGenVertexArrays(1, &road1VAO);

	glBindVertexArray(road1VAO);

	glEnableVertexAttribArray(attribVertex);
	glEnableVertexAttribArray(attribTex);
	glEnableVertexAttribArray(attribNormal);
	glBindBuffer(GL_ARRAY_BUFFER, road1VBO);
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

	unifRoad1Move = glGetUniformLocation(shaderProgram, "move");
	if (unifRoad1Move == -1)
	{
		std::cout << "could not bind uniform move" << std::endl;
		return;
	}

	checkOpenGLerror();
}

void InitTexture()
{
	const char* bus = "textures/road.png";
	if (!roadTextureData.loadFromFile(bus))
	{
		return;
	}
	roadTextureHandle = roadTextureData.getNativeHandle();
}


void Init() {
	InitShader();
	InitVBO();
	InitTexture();
}