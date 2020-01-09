/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#include "game.h"
#include "resource_manager.h"
#include "sprite_renderer.h"


// Game-related State data
SpriteRenderer* Renderer;


Game::Game(GLuint width, GLuint height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
    delete Renderer;
}

void Game::Init()
{
    std::string base_dir = "E:\\zksj\\project\\vs\\gllearn\\Debug\\";
    // Load shaders
    ResourceManager::LoadShader("E:\\zksj\\project\\vs\\gllearn\\Debug\\shaders/sprite.vs", "E:\\zksj\\project\\vs\\gllearn\\Debug\\shaders/sprite.frag", nullptr, "sprite");
    // Configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width), static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // Load textures
    ResourceManager::LoadTexture("E:\\zksj\\project\\vs\\gllearn\\Debug\\textures/awesomeface.png", GL_TRUE, "face");
    // Set render-specific controls
    
    //Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
    Shader s1 = ResourceManager::GetShader("sprite");
    Renderer = new SpriteRenderer(s1);
}

void Game::Update(GLfloat dt)
{

}


void Game::ProcessInput(GLfloat dt)
{

}

void Game::Render()
{
    Texture2D t1 = ResourceManager::GetTexture("face");
    Renderer->DrawSprite(t1, glm::vec2(200, 200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
    //Renderer->DrawSprite(ResourceManager::GetTexture("face"), glm::vec2(200, 200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}