#pragma once
/*********************************
	�\���̊Ǘ�
*********************************/

/******** �񎟌����W **********/
struct Vector2 {
	float x;
	float y;
};

struct IntVector2 {
	int x;
	int y;
};

/******** ��` **********/
struct Quad {
	Vector2 q1;
	Vector2 q2;
	Vector2 q3;
	Vector2 q4;
};

/******** �G�t�F�N�g **********/
struct Effect {
	Vector2 translate;
	Vector2 startPos;
	Vector2 endPos;

	Vector2 size;
	Vector2 startSize;
	Vector2 endSize;

	unsigned int color;

	bool isAlive;

	float t;

};

/*================================
	�\���̊Ǘ�
=================================*/

