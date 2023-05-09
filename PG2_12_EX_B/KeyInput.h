#pragma once
#include "Struct.h"
#include "Enum.h"
#include <Novice.h>

/*********************************
	���͏�Ԍ��m�p�N���X
*********************************/

class KeyInput {

public:

	//������
	static void Initialize();

	//�X�V
	static void Update();

	//�}�E�X���W�擾
	static Vector2 GetMousePosition();

	//�}�E�X���͏�Ԏ擾
	static bool GetMouseState(MouseButton key, InputState state);

	//�L�[���͏�Ԏ擾
	static bool GetKeyboardState(int key, InputState state);

private:

	//�}�E�X���W
	static Vector2 mousePosition;

	//�L�[���͏��
	static char keys[];

	//�O�t���[���̃L�[���͏��
	static char preKeys[];

};

#pragma region �R�����g�A�E�g�p

/*********************************
	�匩�o���R�s�y
*********************************/

/******** �����o���R�s�y�p **********/

#pragma endregion
