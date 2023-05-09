#pragma once
#include <Novice.h>
#include "Const.h"
#include "Struct.h"
#include "KeyInput.h"
#include "BulletManager.h"
class Player
{
public:
	// �R���X�g���N�^
	Player();

	// �f�X�g���N�^
	~Player();

	// ����������
	void Initialize();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

	// ���ˏ���
	void Shot();

	// ���W�̃Q�b�^�[
	Vector2 GetPlayerPos() { return translate; }

	// �p�x�̃Q�b�^�[
	float GetPlayerTheta() { return theta; }

private:

	/// �����o�֐�

	/// <summary>
	///	�v���C���[�̓�����s���ϐ�
	/// </summary>
	void Move();

	// ���S���W
	Vector2 translate;
	// �T�C�Y
	Vector2 size;

	// ��]���S
	Quad point;
	// ��]����W
	Quad rotate;
	// �v���C���[�p�x
	float theta;

	// ���e�B�N�����W
	Vector2 reticlePos;

	// ���e�B�N���T�C�Y
	Vector2 reticleSize;

	// �p�x��ύX���邽�߂̃}�E�X���W
	Vector2 mousePosition;

	// �X�s�[�h
	Vector2 speed;
	// ����x�N�g��
	Vector2 moveVector;
	// �x�N�g���̒���
	float vectorLength;

	// �e�����ˉ\�ȏ�Ԃ�
	bool canShot;

	// �ˌ��t���[��
	float shotRate;

	// �e�N�X�`��
	int texture;
	// �e�N�X�`���T�C�Y
	Vector2 textureSize;
	// �F
	unsigned int color;

	// ���e�B�N���e�N�X�`��
	int reticleTex;
	// ���e�B�N���摜�T�C�Y
	Vector2 reticleTexSize;


};

