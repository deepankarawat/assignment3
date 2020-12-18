#pragma once
#include "Scene.h"
#include "polygon.h"
#include "Brick.h"
struct CPoints
{
	CPoints()
	{
		Position = {0,0};
		Line = 0;
	}
	CPoints(glm::vec2 Pos, int line)
	{
		Position = Pos;
		Line = line;
	}
	glm::vec2 Position;
	int Line;
};
class playscene2: public Scene
{
public:
	playscene2();
	~playscene2();

	// Scene LifeCycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	void BounceWithCollisionLines(CPoints collisionPoint, bool isBrick);
	bool checkCollision(UnorderedArray<Line>& lines1, UnorderedArray<Line>& lines2);
	glm::vec2 CollisionPoint(Line line1, Line line2);
private:
	// IMGUI Function
	void GUI_Function() const;
	glm::vec2* m_pMousePos;
	float* ENERGYLOSS;
	bool* drawCollisionPoints;
	
	Brick* m_pBrick;
	polygon* m_GenPolygon;
	Borders* m_borders;
	UnorderedArray<CPoints>* CollisionPoints;
	UnorderedArray<CPoints>* CollisionPointsDraw;
	int* m_pNumberVertices;

};
