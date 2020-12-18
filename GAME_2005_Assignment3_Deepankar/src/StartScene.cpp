#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	TextureManager::Instance()->draw("background", 0.0f, 0.0f);
	drawDisplayList();
}

void StartScene::update()
{
	updateDisplayList();
}

void StartScene::clean()
{
	removeAllChildren();
}

void StartScene::handleEvents()
{
	EventManager::Instance().update();

	// Keyboard Events
	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	}
}

void StartScene::start()
{
	TextureManager::Instance()->load("../Assets/sprites/background3.png", "background");


	const SDL_Color blue = { 0, 0, 255, 255 };
	const SDL_Color Green = { 10, 115, 20, 255 };
	m_pStartLabel = new Label("ASSIGNEMNT 3", "Consolas", 60, Green, glm::vec2(400.0f, 200.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pStartLabel2 = new Label("DEEPANKAR 101276472", "Consolas", 20, Green, glm::vec2(400.0f, 270.0f));
	m_pStartLabel2->setParent(this);
	addChild(m_pStartLabel2);

	m_pStartLabel3 = new Label("SCENE 1 BULLET POOL", "Consolas", 20, Green, glm::vec2(600.0f, 320.0f));
	m_pStartLabel3->setParent(this);
	addChild(m_pStartLabel3);

	m_pStartLabel3 = new Label("SCENE 2 BOUNCING COLLISION", "Consolas", 20, Green, glm::vec2(200.0f, 320.0f));
	m_pStartLabel3->setParent(this);
	addChild(m_pStartLabel3);


	// Start Button
	m_pStartButton = new Button();
	m_pStartButton->getTransform()->position = glm::vec2(600.0f, 400.0f);

	m_pStartButton->addEventListener(CLICK, [&]()-> void
		{
			m_pStartButton->setActive(false);
			TheGame::Instance()->changeSceneState(PLAY_SCENE);
		});

	m_pStartButton->addEventListener(MOUSE_OVER, [&]()->void
		{
			m_pStartButton->setAlpha(128);
		});

	m_pStartButton->addEventListener(MOUSE_OUT, [&]()->void
		{
			m_pStartButton->setAlpha(255);
		});
	addChild(m_pStartButton);

	m_pStartButton2 = new Button();
	m_pStartButton2->getTransform()->position = glm::vec2(200.0f, 400.0f);

	m_pStartButton2->addEventListener(CLICK, [&]()-> void
		{
			m_pStartButton->setActive(false);
			TheGame::Instance()->changeSceneState(PLAY_SCENE_2);
		});

	m_pStartButton2->addEventListener(MOUSE_OVER, [&]()->void
		{
			m_pStartButton2->setAlpha(128);
		});

	m_pStartButton2->addEventListener(MOUSE_OUT, [&]()->void
		{
			m_pStartButton2->setAlpha(255);
		});
	addChild(m_pStartButton2);


	
}

