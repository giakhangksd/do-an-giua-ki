
#pragma once

//
// This file contains all IDs of game assets 
//

#define ID_TEX_MARIO 0
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20
#define ID_TEX_MAP 30



#pragma region MARIO 

#define ID_SPRITE_MARIO 10000
#define ID_SPRITE_MARIO_BIG (ID_SPRITE_MARIO + 1000)
#define ID_SPRITE_MARIO_BIG_IDLE (ID_SPRITE_MARIO_BIG + 100)
#define ID_SPRITE_MARIO_BIG_IDLE_LEFT (ID_SPRITE_MARIO_BIG_IDLE + 10)
#define ID_SPRITE_MARIO_BIG_IDLE_RIGHT (ID_SPRITE_MARIO_BIG_IDLE + 20)

#define ID_SPRITE_MARIO_BIG_WALKING (ID_SPRITE_MARIO_BIG + 200)
#define ID_SPRITE_MARIO_BIG_WALKING_LEFT (ID_SPRITE_MARIO_BIG_WALKING + 10)
#define ID_SPRITE_MARIO_BIG_WALKING_RIGHT (ID_SPRITE_MARIO_BIG_WALKING + 20)
#define ID_SPRITE_MARIO_BIG_RUNNING (ID_SPRITE_MARIO_BIG + 300)
#define ID_SPRITE_MARIO_BIG_RUNNING_LEFT (ID_SPRITE_MARIO_BIG_RUNNING + 10)
#define ID_SPRITE_MARIO_BIG_RUNNING_RIGHT (ID_SPRITE_MARIO_BIG_RUNNING + 20)
#define ID_SPRITE_MARIO_BIG_JUMP (ID_SPRITE_MARIO_BIG + 400)
#define ID_SPRITE_MARIO_BIG_JUMP_WALK (ID_SPRITE_MARIO_BIG_JUMP + 10)
#define ID_SPRITE_MARIO_BIG_JUMP_WALK_LEFT (ID_SPRITE_MARIO_BIG_JUMP_WALK + 2)
#define ID_SPRITE_MARIO_BIG_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_BIG_JUMP_WALK + 6)
#define ID_SPRITE_MARIO_BIG_JUMP_RUN (ID_SPRITE_MARIO_BIG_JUMP + 20)
#define ID_SPRITE_MARIO_BIG_JUMP_RUN_LEFT (ID_SPRITE_MARIO_BIG_JUMP_RUN + 2)
#define ID_SPRITE_MARIO_BIG_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_BIG_JUMP_RUN + 6)

#define ID_SPRITE_MARIO_BIG_SIT (ID_SPRITE_MARIO_BIG + 500)
#define ID_SPRITE_MARIO_BIG_SIT_LEFT (ID_SPRITE_MARIO_BIG_SIT + 10)
#define ID_SPRITE_MARIO_BIG_SIT_RIGHT (ID_SPRITE_MARIO_BIG_SIT + 20)

#define ID_SPRITE_MARIO_BIG_BRACE (ID_SPRITE_MARIO_BIG + 600)
#define ID_SPRITE_MARIO_BIG_BRACE_LEFT (ID_SPRITE_MARIO_BIG_BRACE + 10)
#define ID_SPRITE_MARIO_BIG_BRACE_RIGHT (ID_SPRITE_MARIO_BIG_BRACE + 20)

#define ID_SPRITE_MARIO_DIE (ID_SPRITE_MARIO + 9000)
//SMALL_MARIO
#define ID_SPRITE_MARIO_SMALL (ID_SPRITE_MARIO + 2000)
#define ID_SPRITE_MARIO_SMALL_IDLE (ID_SPRITE_MARIO_SMALL + 100)
#define ID_SPRITE_MARIO_SMALL_IDLE_LEFT (ID_SPRITE_MARIO_SMALL_IDLE + 10)
#define ID_SPRITE_MARIO_SMALL_IDLE_RIGHT (ID_SPRITE_MARIO_SMALL_IDLE + 20)

#define ID_SPRITE_MARIO_SMALL_WALKING (ID_SPRITE_MARIO_SMALL + 200)
#define ID_SPRITE_MARIO_SMALL_WALKING_LEFT (ID_SPRITE_MARIO_SMALL_WALKING + 10)
#define ID_SPRITE_MARIO_SMALL_WALKING_RIGHT (ID_SPRITE_MARIO_SMALL_WALKING + 20)
#define ID_SPRITE_MARIO_SMALL_RUNNING (ID_SPRITE_MARIO_SMALL + 300)
#define ID_SPRITE_MARIO_SMALL_RUNNING_LEFT (ID_SPRITE_MARIO_SMALL_RUNNING + 10)
#define ID_SPRITE_MARIO_SMALL_RUNNING_RIGHT (ID_SPRITE_MARIO_SMALL_RUNNING + 20)
#define ID_SPRITE_MARIO_SMALL_JUMP (ID_SPRITE_MARIO_SMALL + 400)
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK (ID_SPRITE_MARIO_SMALL_JUMP + 10)
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK_LEFT (ID_SPRITE_MARIO_SMALL_JUMP_WALK + 2)
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_SMALL_JUMP_WALK + 6)
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN (ID_SPRITE_MARIO_SMALL_JUMP + 20)
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN_LEFT (ID_SPRITE_MARIO_SMALL_JUMP_RUN + 2)
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_SMALL_JUMP_RUN + 6)

#define ID_SPRITE_MARIO_SMALL_SIT (ID_SPRITE_MARIO_SMALL + 500)
#define ID_SPRITE_MARIO_SMALL_SIT_LEFT (ID_SPRITE_MARIO_SMALL_SIT + 10)
#define ID_SPRITE_MARIO_SMALL_SIT_RIGHT (ID_SPRITE_MARIO_SMALL_SIT + 20)

#define ID_SPRITE_MARIO_SMALL_BRACE (ID_SPRITE_MARIO_SMALL + 500)
#define ID_SPRITE_MARIO_SMALL_BRACE_LEFT (ID_SPRITE_MARIO_SMALL_BRACE + 10)
#define ID_SPRITE_MARIO_SMALL_BRACE_RIGHT (ID_SPRITE_MARIO_SMALL_BRACE + 20)
//FOX_MARIO
#define ID_SPRITE_MARIO_FOX (ID_SPRITE_MARIO + 3000)
#define ID_SPRITE_MARIO_FOX_IDLE (ID_SPRITE_MARIO_FOX + 100)
#define ID_SPRITE_MARIO_FOX_IDLE_LEFT (ID_SPRITE_MARIO_FOX_IDLE + 10)
#define ID_SPRITE_MARIO_FOX_IDLE_RIGHT (ID_SPRITE_MARIO_FOX_IDLE + 20)

#define ID_SPRITE_MARIO_FOX_WALKING (ID_SPRITE_MARIO_FOX + 200)
#define ID_SPRITE_MARIO_FOX_WALKING_LEFT (ID_SPRITE_MARIO_FOX_WALKING + 10)
#define ID_SPRITE_MARIO_FOX_WALKING_RIGHT (ID_SPRITE_MARIO_FOX_WALKING + 20)
#define ID_SPRITE_MARIO_FOX_RUNNING (ID_SPRITE_MARIO_FOX + 300)
#define ID_SPRITE_MARIO_FOX_RUNNING_LEFT (ID_SPRITE_MARIO_FOX_RUNNING + 10)
#define ID_SPRITE_MARIO_FOX_RUNNING_RIGHT (ID_SPRITE_MARIO_FOX_RUNNING + 20)
#define ID_SPRITE_MARIO_FOX_JUMP (ID_SPRITE_MARIO_FOX + 400)
#define ID_SPRITE_MARIO_FOX_JUMP_WALK (ID_SPRITE_MARIO_FOX_JUMP + 10)
#define ID_SPRITE_MARIO_FOX_JUMP_WALK_LEFT (ID_SPRITE_MARIO_FOX_JUMP_WALK + 2)
#define ID_SPRITE_MARIO_FOX_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_FOX_JUMP_WALK + 6)
#define ID_SPRITE_MARIO_FOX_JUMP_RUN (ID_SPRITE_MARIO_FOX_JUMP + 20)
#define ID_SPRITE_MARIO_FOX_JUMP_RUN_LEFT (ID_SPRITE_MARIO_FOX_JUMP_RUN + 2)
#define ID_SPRITE_MARIO_FOX_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_FOX_JUMP_RUN + 6)

#define ID_SPRITE_MARIO_FOX_SIT (ID_SPRITE_MARIO_FOX + 500)
#define ID_SPRITE_MARIO_FOX_SIT_LEFT (ID_SPRITE_MARIO_FOX_SIT + 10)
#define ID_SPRITE_MARIO_FOX_SIT_RIGHT (ID_SPRITE_MARIO_FOX_SIT + 20)

#define ID_SPRITE_MARIO_FOX_BRACE (ID_SPRITE_MARIO_FOX + 600)
#define ID_SPRITE_MARIO_FOX_BRACE_LEFT (ID_SPRITE_MARIO_FOX_BRACE + 10)
#define ID_SPRITE_MARIO_FOX_BRACE_RIGHT (ID_SPRITE_MARIO_FOX_BRACE + 20)

#define ID_SPRITE_MARIO_FOX_HIT	(ID_SPRITE_MARIO_FOX + 700)
#define ID_SPRITE_MARIO_FOX_HIT_LEFT (ID_SPRITE_MARIO_FOX_HIT + 10)
#define ID_SPRITE_MARIO_FOX_HIT_RIGHT (ID_SPRITE_MARIO_FOX_HIT + 20)

#define ID_SPRITE_MARIO_FOX_FLY (ID_SPRITE_MARIO_FOX + 800)

#define ID_SPRITE_MARIO_FOX_FLY_RIGHT_UP (ID_SPRITE_MARIO_FOX_FLY + 10)
#define ID_SPRITE_MARIO_FOX_FLY_RIGHT_DOWN (ID_SPRITE_MARIO_FOX_FLY + 20)
#define ID_SPRITE_MARIO_FOX_FLY_LEFT_UP (ID_SPRITE_MARIO_FOX_FLY + 30)
#define ID_SPRITE_MARIO_FOX_FLY_LEFT_DOWN (ID_SPRITE_MARIO_FOX_FLY + 40)

#pragma endregion 

#define ID_SPRITE_BRICK 20000

#define ID_SPRITE_QUESBOX 25000



#define ID_SPRITE_GOOMBA 30000
#define ID_SPRITE_GOOMBA_WALK (ID_SPRITE_GOOMBA + 1000)
#define ID_SPRITE_GOOMBA_DIE (ID_SPRITE_GOOMBA + 2000)
#define ID_SPRITE_GOOMBA_WING_WALK (ID_SPRITE_GOOMBA + 3000)
#define ID_SPRITE_GOOMBA_WING_FLY (ID_SPRITE_GOOMBA + 4000)

#define ID_SPRITE_KOOPA 80000
#define ID_SPRITE_GREEN_KOOPA 80500
#define ID_SPRITE_KOOPA_WALKING 81000
#define ID_SPRITE_GREEN_KOOPA_WALKING 81500
#define ID_SPRITE_KOOPA_SHELL 82000
#define ID_SPRITE_KOOPA_WINGFLY 83000
#define ID_SPRITE_KOOPA_WALKING_RIGHT 84000
#define ID_SPRITE_GREEN_KOOPA_WALKING_RIGHT 84500
#define ID_SPRITE_KOOPA_SHELL_CHANGE 85000


#define ID_SPRITE_COIN 30000

#define ID_SPRITE_BLOCK 39000

#define ID_SPRITE_CLOUD 50000
#define ID_SPRITE_CLOUD_BEGIN (ID_SPRITE_CLOUD+1000)
#define ID_SPRITE_CLOUD_MIDDLE (ID_SPRITE_CLOUD+2000)
#define ID_SPRITE_CLOUD_END (ID_SPRITE_CLOUD+3000)

#define ID_SPRITE_PIPE 40000
#define ID_SPRITE_UNDERPIPE 45000

#define ID_SPRITE_MUSHROOM 60000
#define ID_SPRITE_MUSHROOM_WALK (ID_SPRITE_MUSHROOM + 1000)

#define ID_SPRITE_LEAF 70000
#define ID_SPRITE_LEAF_FALLING (ID_SPRITE_LEAF + 1000)

#define ID_SPRITE_WORLDMAP 24000





