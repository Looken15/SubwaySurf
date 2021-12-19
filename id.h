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

GLint unifRoad1Move;

GLint unifRoad2Move;

GLuint road1VBO;

GLuint road2VBO;

GLint roadTextureHandle;

sf::Texture roadTextureData;

GLuint road1VAO;

GLuint road2VAO;