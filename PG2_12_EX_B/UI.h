#pragma once
#include <Novice.h>
#include "Const.h"
#include "Struct.h"
#include "KeyInput.h"
class UI
{

public:

	// �R���X�g���N�^
	UI();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

private:

	// ���e�B�N�����W
	Vector2 reticlePos;

	// ���e�B�N���T�C�Y
	Vector2 reticleSize;

	// ���e�B�N���e�N�X�`��
	int reticleTex;
	// ���e�B�N���摜�T�C�Y
	Vector2 reticleTexSize;

};

