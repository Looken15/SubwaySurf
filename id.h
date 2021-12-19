#pragma once

#include <gl/glew.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

GLuint shaderProgram;

GLint attribVertex;

GLint attribTex;

GLint attribNormal;

GLint unifTexture;

GLint unifRotate;
GLint unifMove;
GLint unifScale;

GLuint roadVBO;
GLuint busVBO;

GLint roadTextureHandle;
GLint busTextureHandle;

sf::Texture roadTextureData;
sf::Texture busTextureData;

GLuint roadVAO;
GLuint busVAO;