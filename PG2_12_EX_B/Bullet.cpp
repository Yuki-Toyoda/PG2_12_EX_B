#include "Bullet.h"

// �R���X�g���N�^
Bullet::Bullet() {
	
}

// �f�X�g���N�^
Bullet::~Bullet() {

}

// ����������
void Bullet::Initialize() {
	// ���S���W
	translate = { 10000, 10000 };
	// �T�C�Y
	size = { 16.0f, 16.0f };

	// ��]���S
	point = {
		-size.x / 2, -size.y / 2,
		size.x / 2, -size.y / 2,
		-size.x / 2, size.y / 2,
		size.x / 2, size.y / 2
	};

	// ��]����W
	rotate = {
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f
	};

	// �p�x
	theta = 0.0f;

	// ���˃X�s�[�h
	speed = { 10.0f, 10.0f };

	// ���˂���Ă��邩�̃g���K�[
	isShot = false;

	// �e�N�X�`��
	texture = Novice::LoadTexture("./Resources/Graph/Bullet.png");
	// �e�N�X�`���T�C�Y
	textureSize = { 64.0f, 64.0f };
}

// �X�V����
void Bullet::Update() {
	if (isShot == true) {
		// �e��]����
		rotate.q1.x = point.q1.x * cosf(theta) - point.q1.y * sinf(theta) + translate.x;
		rotate.q1.y = point.q1.y * cosf(theta) + point.q1.x * sinf(theta) + translate.y;

		rotate.q2.x = point.q2.x * cosf(theta) - point.q2.y * sinf(theta) + translate.x;
		rotate.q2.y = point.q2.y * cosf(theta) + point.q2.x * sinf(theta) + translate.y;

		rotate.q3.x = point.q3.x * cosf(theta) - point.q3.y * sinf(theta) + translate.x;
		rotate.q3.y = point.q3.y * cosf(theta) + point.q3.x * sinf(theta) + translate.y;

		rotate.q4.x = point.q4.x * cosf(theta) - point.q4.y * sinf(theta) + translate.x;
		rotate.q4.y = point.q4.y * cosf(theta) + point.q4.x * sinf(theta) + translate.y;

		translate.x += (cosf(theta) * speed.x);
		translate.y += (sinf(theta) * speed.y);

		if (translate.x > kWindowWidth + size.x || translate.x < 0 - size.x || 
			translate.y > kWindowHeight + size.y || translate.y < 0 - size.x) {
			isShot = false;
		}
		
	}
}

// �`�揈��
void Bullet::Draw() {
	// �e�̕`��
	if (isShot == true) {
		Novice::DrawQuad(
			rotate.q1.x, rotate.q1.y,
			rotate.q2.x, rotate.q2.y,
			rotate.q3.x, rotate.q3.y,
			rotate.q4.x, rotate.q4.y,
			0.0f, 0.0f,
			textureSize.x, textureSize.y,
			texture,
			0xFFFFFFFF
		);
	}
}