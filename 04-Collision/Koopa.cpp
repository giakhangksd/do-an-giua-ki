#include "Koopa.h"
#include "Goomba.h"
#include "Mario.h"
#include "Platform.h"
#include "Brick.h"
#include "quesbox.h"
#include "leaf.h"
#include "Mushroom.h"

CKoopa::CKoopa(float x, float y, int type) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = KOOPA_GRAVITY;
	this->isOnPlatform = FALSE;
	this->isOnBrick = FALSE;
	this->isOnBlock = FALSE;
	this->m_x = nullptr;
	this->m_y = nullptr;
	this->m_nx = nullptr;
	l_bounded = r_bounded = 0;
	this->nx = 1;
	this->isheld = false;
	die_start = -1;
	wait1 = wait2 = wait_2_walk = wait_2_fly = -1;
	if (type == 0) {
		SetState(KOOPA_STATE_RED_WALKING);
	}
	if (type == 1) {
		SetState(KOOPA_STATE_WING_WALK);
	}
}

void CKoopa::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
		left = x - KOOPA_BBOX_WIDTH / 2;
		top = y - KOOPA_BBOX_HEIGHT / 2;
		right = left + KOOPA_BBOX_WIDTH;
		bottom = top + KOOPA_BBOX_HEIGHT;
	
}

void CKoopa::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CKoopa::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) {
		OnCollisionWithOthers(e);
	
	}
	if (e->obj->IsBlocking()) {
		OnCollisionWithQuesbox(e);

	}
	if (e->ny != 0)
	{
		vy = 0;
		if (e->ny < 0) {
			isOnPlatform = true;
			isOnBrick = true;
		}
	}
	else if (e->nx != 0 && e->obj->IsBlocking())
	{
		vx = -vx;
		nx = -nx;
	}
	if (dynamic_cast<CPlatform*>(e->obj))
		OnCollisionWithPlatform(e);
	else if (dynamic_cast<CBrick*>(e->obj)) {
		OnCollisionWithBrick(e);
	}
}
void CKoopa::OnCollisionWithOthers(LPCOLLISIONEVENT e) {
	if (state == KOOPA_STATE_SHELL_MOV||state==KOOPA_STATE_SHELL_MOV_RIGHT)
	{
		if (dynamic_cast<CMario*>(e->obj))
		{
			CMario* mario = dynamic_cast<CMario*>(e->obj);
			mario->OnCollisionWith(e);
		}
		else if (dynamic_cast<CGoomba*>(e->obj))
		{
		CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);
		goomba->SetState(GOOMBA_STATE_DIE_SHELL);
		}
		else if (dynamic_cast<CQuesbox*>(e->obj))
		{
			CQuesbox* quesbox = dynamic_cast<CQuesbox*>(e->obj);
			if (quesbox->GetState() == QUESBOX_STATE && (state == KOOPA_STATE_SHELL_MOV || state == KOOPA_STATE_SHELL_MOV_RIGHT)) {
				if (e->nx < 0 || e->nx>0) {
					quesbox->SetState(QUESBOX_STATE_NOT);
				}
			}
		}
	}
}
void CKoopa::OnCollisionWithQuesbox(LPCOLLISIONEVENT e) {
	if (dynamic_cast<CQuesbox*>(e->obj))
	{
		CQuesbox* quesbox = dynamic_cast<CQuesbox*>(e->obj);
		if (quesbox->GetState() == QUESBOX_STATE && (state == KOOPA_STATE_SHELL_MOV || state == KOOPA_STATE_SHELL_MOV_RIGHT)) {
			quesbox->SetState(QUESBOX_STATE_NOT);
			if (e->nx < 0) {
				vx = -KOOPA_WALKING_SPEED*3;
			}
			if (e->nx > 0) {
				vx = KOOPA_WALKING_SPEED*3;
			}
		}
	}
	if (dynamic_cast<CMushroom*>(e->obj))
	{
		CMushroom* mushroom = dynamic_cast<CMushroom*>(e->obj);
		mushroom->SetState(MUSHROOM_STATE_WALKING);
	}
	if (dynamic_cast<CLeaf*>(e->obj))
	{
		CLeaf* leaf = dynamic_cast<CLeaf*>(e->obj);
		leaf->SetState(LEAF_STATE_FALLING);
		if (e->nx < 0) {
			vx = -KOOPA_WALKING_SPEED * 3;
		}
		if (e->nx > 0) {
			vx = KOOPA_WALKING_SPEED * 3;
		}
	}
}


void CKoopa::OnCollisionWithPlatform(LPCOLLISIONEVENT e)
{
	if (e->ny < 0)
	{
		isOnBlock = FALSE;
		CGameObject* platform = dynamic_cast<CGameObject*>(e->obj);

		float l, r, t, b;
		platform->GetBoundingBox(l, t, r, b);

		l_bounded = l;
		r_bounded = r;
	}
}

void CKoopa::OnCollisionWithBrick(LPCOLLISIONEVENT e)
{
	if (e->ny < 0)
	{
		CGameObject* brick = dynamic_cast<CGameObject*>(e->obj);
		float l, r, t, b;
		brick->GetBoundingBox(l, t, r, b);
		if (!isOnBlock)
		{
			l_bounded = l * 1000;
			r_bounded = r * 1000;
			isOnBlock = TRUE;
		}
		else
		{
			l_bounded = min(l, l_bounded);
			r_bounded = max(r, r_bounded);
		}
	}
}

void CKoopa::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;
	if (isOnPlatform && state == KOOPA_STATE_RED_WALKING)
	{
		if ((x <= l_bounded && vx < 0) || (x >= r_bounded && vx > 0))
		{
			vx = -vx;
			nx = -nx;
		}
	}
	if (isOnBrick && state == KOOPA_STATE_RED_WALKING)
	{
		if ((x <= l_bounded && vx < 0) || (x >= r_bounded && vx > 0))
		{
			vx = -vx;
			nx = -nx;
		}
	}

	isOnBrick = false;
	isOnPlatform = false;


	if (state == KOOPA_STATE_SHELL && (GetTickCount64() - wait1 > KOOPA_WAIT_TIMEOUT * 6)) {
		SetState(KOOPA_STATE_SHELL_CHANGE);
	}
	if (state == KOOPA_STATE_SHELL_HOLDED && (GetTickCount64() - wait1 > KOOPA_WAIT_TIMEOUT * 10)) {
		SetState(KOOPA_STATE_SHELL_CHANGE);
	}
	if (state == KOOPA_STATE_SHELL_CHANGE && (GetTickCount64() - wait2 > KOOPA_WAIT_TIMEOUT)) {
		SetState(KOOPA_STATE_RED_WALKING);
	}
	//koopa wing bay
	if ((state == KOOPA_STATE_WING_WALK) && (GetTickCount64() - wait_2_fly > 500 * 2))
	{
		SetState(KOOPA_STATE_WING_FLY);
	}
	if ((state == KOOPA_STATE_WING_WALK_RIGHT) && (GetTickCount64() - wait_2_fly > 500 * 2))
	{
		SetState(KOOPA_STATE_WING_FLY);
	}
	if ((state == KOOPA_STATE_WING_FLY) && (GetTickCount64() - wait_2_walk > 500 * 2) && vx < 0)
	{
		SetState(KOOPA_STATE_WING_WALK);
	}
	if ((state == GOOMBA_STATE_WING_FLY) && (GetTickCount64() - wait_2_walk > 500 * 2) && vx > 0)
	{
		SetState(KOOPA_STATE_WING_WALK_RIGHT);
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CKoopa::Render()
{
	int aniId = -1;
	if (state == KOOPA_STATE_RED_WALKING) {
		if (vx > 0) {
			aniId = ID_ANI_KOOPA_WALKING_RIGHT;
		}
		if (vx < 0) {
			aniId = ID_ANI_KOOPA_WALKING;
		}
	}
	if (state == KOOPA_STATE_WING_WALK||state==KOOPA_STATE_WING_FLY||state==KOOPA_STATE_WING_WALK_RIGHT) {
		if (vx > 0) {
			aniId = ID_ANI_GREEN_KOOPA_WALKING_RIGHT;
		}
		if (vx < 0) {
			aniId = ID_ANI_GREEN_KOOPA_WALKING;
		}
	}
	if (state == KOOPA_STATE_SHELL||state ==KOOPA_STATE_SHELL_HOLDED)
	{
		aniId = ID_ANI_KOOPA_SHELL;
	}
	if (state == KOOPA_STATE_SHELL_MOV || state == KOOPA_STATE_SHELL_MOV_RIGHT) {
		aniId = ID_ANI_KOOPA_SHELL;
	}
	if (state == KOOPA_STATE_SHELL_CHANGE) {
		aniId = ID_ANI_KOOPA_SHELL_CHANGE;
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CKoopa::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case KOOPA_STATE_SHELL:
		y -= 1.0f;
		vx = 0;
		wait1 = GetTickCount64();
		break;
	case KOOPA_STATE_SHELL_MOV:
		isheld = FALSE;
		m_x = nullptr;
		m_y = nullptr;
		m_nx = nullptr;
		vx = -KOOPA_WALKING_SPEED * 3;
		y -= 0.5f;
		break;
	case KOOPA_STATE_SHELL_MOV_RIGHT:
		isheld = FALSE;
		m_x = nullptr;
		m_y = nullptr;
		m_nx = nullptr;
		vx = KOOPA_WALKING_SPEED * 3;
		y -= 0.5f;
		break;
	case KOOPA_STATE_RED_WALKING:
		vx = -KOOPA_WALKING_SPEED;
		isheld = FALSE;
		break;
	case KOOPA_STATE_WALKING_RIGHT:
		vx = KOOPA_WALKING_SPEED;
		isheld = FALSE;
		break;
	case KOOPA_STATE_SHELL_CHANGE:
		vx = 0;
		y -= 1;
		wait2 = GetTickCount64();
		break;
	case KOOPA_STATE_WING_WALK:
		vx = -KOOPA_WALKING_SPEED;
		vy = 0;
		wait_2_fly = GetTickCount64();
		break;
	case KOOPA_STATE_WING_WALK_RIGHT:
		vx = KOOPA_WALKING_SPEED;
		vy =0 ;
		wait_2_fly = GetTickCount64();
		break;
	case KOOPA_STATE_WING_FLY:
		vy -= 0.25f;
		wait_2_walk = GetTickCount64();
		break;
	case KOOPA_STATE_SHELL_HOLDED:
		isheld = true;
		break;
	}
}

//shell movment with mario

void CKoopa::HoldByMario(float* x, float* y, int* nx)
{
	m_x = x;
	m_y = y;
	m_nx = nx;
	SetState(KOOPA_STATE_SHELL_HOLDED);
}

void CKoopa::UpdatePositionFollowMario()
{
	if (isheld)
	{
		x = *m_x + *m_nx * (KOOPA_BBOX_WIDTH / 2 + 4);
		y = *m_y - 1;
	}
}
