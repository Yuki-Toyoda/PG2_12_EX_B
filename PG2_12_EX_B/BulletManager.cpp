#include "BulletManager.h"

// �R���X�g���N�^
BulletManager::BulletManager() {

}

// ����������
void BulletManager::Initialize() {
	// �e��������
	for (int i = 0; i < 30; i++) {
		bullet[i] = new Bullet;
		bullet[i]->Initialize();
	}
}

// �X�V����
void BulletManager::Update(){
	// �e�̍X�V����
	for (int i = 0; i < 30; i++) {
		bullet[i]->Update();
	}
}

// �`�揈��
void BulletManager::Draw() {
	// �e�̕`�揈��
	for (int i = 0; i < 30; i++) {
		if(bullet[i]->GetIsShot() == true)
		bullet[i]->Draw();
	}
}

/// <summary>
/// �w�肳�ꂽ�e���ˌ������ǂ������擾����Q�b�^�[
/// </summary>
/// <param name="bulletNum">�����擾����e</param>
/// <returns></returns>
bool BulletManager::GetBulletIsShot(int shotNum) {
	return bullet[shotNum]->GetIsShot();
}

void BulletManager::SetBulletIsShot() {
	for (int i = 0; i < 30; i++) {
		if (GetBulletIsShot(i) == false) {
			
		}
	}
}

// �����o�ϐ��̎��̂�錾
Bullet* BulletManager::bullet[30];