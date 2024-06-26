#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANY_PIPE 20000
#define PIPE_WIDTH 16
#define PIPE_BBOX_WIDTH 32
#define PIPE_BBOX_HEIGHT 32

class Cpipe : public CGameObject {
public:
	Cpipe(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};

