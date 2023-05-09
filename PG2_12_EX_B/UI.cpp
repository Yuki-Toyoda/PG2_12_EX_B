#include "UI.h"

// コンストラクタ
UI::UI() {

	// レティクル座標
	reticlePos = {0.0f, 0.0f};
	// レティクルサイズ
	reticleSize = { 0.0f, 0.0f };

	// レティクルテクスチャ
	reticleTex = Novice::LoadTexture("./Resources/Graph/Reticle.png");
	// レティクル画像サイズ
	reticleTexSize = {128.0f, 128.0f};

}

void UI::Draw() {
	// レティクル描画
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
