#pragma once
#include <Novice.h>
#include "Const.h"
#include "Struct.h"
#include "KeyInput.h"
class UI
{

public:

	// コンストラクタ
	UI();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

private:

	// レティクル座標
	Vector2 reticlePos;

	// レティクルサイズ
	Vector2 reticleSize;

	// レティクルテクスチャ
	int reticleTex;
	// レティクル画像サイズ
	Vector2 reticleTexSize;

};

