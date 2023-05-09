#pragma once
#include "Bullet.h"
class BulletManager
{
public:

	// �R���X�g���N�^
	BulletManager();

	// ����������
	static void Initialize();

	// �X�V����
	static void Update();

	// �`�揈��
	static void Draw();

	/// <summary>
	/// �w�肳�ꂽ�e���ˌ������ǂ������擾����Q�b�^�[
	/// </summary>
	/// <param name="bulletNum">�����擾����e</param>
	/// <returns></returns>
	bool GetBulletIsShot(int bulletNum);

	// �ˌ����Ă��Ȃ��e��T���A�ˌ����ɂ���
	void SetBulletIsShot();

private:

	

	// �ÓI�ȃ����o�ϐ���錾
	static Bullet* bullet[30];

};

