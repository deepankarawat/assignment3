#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "ship.h"
#include "Button.h"

class StartScene final : public Scene
{
public:
	StartScene();
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
	
private:
	Label* m_pStartLabel{};
	Label* m_pStartLabel2{};
	Label* m_pStartLabel3{};
	Label* m_pStartLabel4{};

	Button* m_pStartButton;
	Button* m_pStartButton2;
};

#endif /* defined (__START_SCENE__) */