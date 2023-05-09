#include "UI.h"

// �R���X�g���N�^
UI::UI() {

	// ���e�B�N�����W
	reticlePos = {0.0f, 0.0f};
	// ���e�B�N���T�C�Y
	reticleSize = { 0.0f, 0.0f };

	// ���e�B�N���e�N�X�`��
	reticleTex = Novice::LoadTexture("./Resources/Graph/Reticle.png");
	// ���e�B�N���摜�T�C�Y
	reticleTexSize = {128.0f, 128.0f};

}

void UI::Draw() {
	// ���e�B�N���`��
	Novice::DrawQuad(
		reticlePos.x - reticleSize.x, reticlePos.y - reticleSize.y,
		reticlePos.x + reticleSize.x, reticlePos.y - reticleSize.y,
		reticlePos.x - reticleSize.x, reticlePos.y + reticleSize.y,
		reticlePos.x + reticleSize.x, reticlePos.y + reticleSize.y,
		0, 0,
		reticleTexSize.x, reticleTexSize.y,
		reticleTex,
		0xFFFFFFFF
	);
}
