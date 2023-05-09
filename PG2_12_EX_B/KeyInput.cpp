#include "KeyInput.h"

/******** ������ **********/
void KeyInput::Initialize() {

	//�}�E�X�ʒu������
	mousePosition = { 0.0f, 0.0f };

	//�L�[��Ԃ̏�����
	for (int i = 0; i < 256; i++) {

		keys[i] = { 0 };
		preKeys[i] = { 0 };

	}

}

/******** �X�V **********/
void KeyInput::Update() {

	/******** �}�E�X�ʒu�擾 **********/
	//�擾�����}�E�X�ʒu��2�������W(x, y)�Ŏ󂯎��
	int x = 0, y = 0;
	Novice::GetMousePosition(&x, &y);
	mousePosition = { (float)x, (float)y };

	/******** �L�[���擾 **********/
	//�ǂ̃L�[���ǂ̂悤�ȏ�Ԃœ��͂���Ă��邩���󂯎��
	//key ... �m�F����L�[
	//state ... �m�F�������L�[�̏��
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

}

/******** �}�E�X�ʒu�擾�֐� **********/
Vector2 KeyInput::GetMousePosition() {

	return mousePosition;

}

/******** �}�E�X���͂̏�Ԍ��m **********/
//key ... �m�F����}�E�X����
//state ... �m�F�������}�E�X���͂̏��
bool KeyInput::GetMouseState(MouseButton key, InputState state) {

	switch (state)
	{
		//������Ă��Ȃ��ꍇ
	case Null:

		if (!Novice::IsTriggerMouse(key)) {

			return true;

		}
		else {

			return false;

		}

		//�����ꂽ�u��
	case Trigger:

		if (Novice::IsTriggerMouse(key)) {

			return true;

		}
		else {

			return false;

		}

		//�����Ă����
	case Press:

		if (Novice::IsPressMouse(key)) {

			return true;

		}
		else {

			return false;

		}

		//�������u��
	case Release:

		//���ݎg�p�\�肪�Ȃ����ߌ�Ɏ���

	//��L�ȊO�������ꍇ�G���[
	default:

		return false;

	}

}

/******** �L�[�{�[�h���͂̏�Ԍ��m **********/
//key ... �m�F����}�E�X����
//state ... �m�F�������}�E�X���͂̏��
bool KeyInput::GetKeyboardState(int key, InputState state) {

	switch (state)
	{

		//������Ă��Ȃ��ꍇ
	case Null:

		if (!keys[key] && !preKeys[key]) {

			return true;

		}
		else {

			return false;

		}

		//�������u��
	case Trigger:

		if (keys[key] && !preKeys[key]) {

			return true;

		}
		else {

			return false;

		}

		//�����Ă����
	case Press:

		if (keys[key]) {

			return true;

		}
		else {

			return false;

		}

		//�������u��
	case Release:

		if (keys[key]) {

			return true;

		}
		else {

			return false;

		}

		//��L�ȊO�������ꍇ�̓G���[
	default:

		return false;

	}

}

/******** �w�b�_�t�@�C���Ő錾�����ϐ��̎��Ԑ錾 **********/

//�}�E�X���W
Vector2 KeyInput::mousePosition;

//�L�[���͏�
char KeyInput::keys[256];

//�O�t���[���ł̓��͏�
char KeyInput::preKeys[256];

#pragma region �R�����g�A�E�g�p

/*********************************
	�匩�o���R�s�y
*********************************/

/******** �����o���R�s�y�p **********/

#pragma endregion