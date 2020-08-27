#include "MainGame.h"
#include <iostream>

using namespace std;

void MainGame::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			cout << event.motion.x << "," << event.motion.y << endl;
			break;
		default:
			break;
		}
	}
}

void MainGame::init()
{
	window = SDL_CreateWindow("Clase 01",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,witdh, height,SDL_WINDOW_OPENGL);
	if (window == nullptr) {
		//Msj error
	}
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		//TODO Error Glew
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(1.0f,0.0f,1.0f,1.0f);
}

MainGame::MainGame()
{
	window = nullptr;
	witdh = 800;
	height = 800;
	gameState = GameState::PLAY;
}

MainGame::~MainGame()
{
}

void MainGame::run()
{
	init();
	//TODO Sprite
	update();

}

void MainGame::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//TODO update sprite
	SDL_GL_SwapWindow(window);
}

void MainGame::update()
{
	while (gameState != GameState::EXIT) {
		draw();
		processInput();
	}
}
