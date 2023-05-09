#include "Player.h"

// コンストラクタ
Player::Player() {
	

}

// デストラクタ
Player::~Player() {

}

void Player::Initialize() {
	// 座標初期化
	translate = { (float)kWindowWidth / 2, (float)kWindowHeight / 2 };
	// サイズ
	size = { 64.0f, 64.0f };

	// レティクル座標
	reticlePos = { 0.0f, 0.0f };
	// レティクルサイズ
	reticleSize = { 16.0f, 16.0f };

	// 回転中心
	point = {
		-size.x / 2, -size.y / 2,
		size.x / 2, -size.y / 2,
		-size.x / 2, size.y / 2,
		size.x / 2, size.y / 2
	};

	// 回転後座標
	rotate = {
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f
	};

	// プレイヤー角度
	theta = 0.0f;

	// 角度を変更するためのマウス座標
	mousePosition = { 0.0f, 0.0f };

	// スピード
	speed = { 5.0f, 5.0f };
	// 動作ベクトル
	moveVector = { 0.0f, 0.0f };
	// ベクトルの長さ
	vectorLength = 0.0f;

	// 弾が発射可能な状態か
	canShot = true;

	// テクスチャ
	texture = Novice::LoadTexture("./Resources/Graph/Player.png");
	// テクスチャサイズ
	textureSize = { 256.0f, 256.0f };

	// 色
	color = 0xFFFFFFFF;

	// レティクルテクスチャ
	reticleTex = Novice::LoadTexture("./Resources/Graph/Reticle.png");
	// レティクル画像サイズ
	reticleTexSize = { 128.0f, 128.0f };
}

// 更新処理
void Player::Update() {

	// マウス座標取得
	mousePosition = KeyInput::GetMousePosition();
	
	// レティクルをマウス座標に
	reticlePos = mousePosition;

	// マウス座標とプレイヤーの角度を求める
	theta = atan2(mousePosition.y - translate.y, mousePosition.x - translate.x);

	// プレイヤー回転処理
	rotate.q1.x = point.q1.x * cosf(theta) - point.q1.y * sinf(theta) + translate.x;
	rotate.q1.y = point.q1.y * cosf(theta) + point.q1.x * sinf(theta) + translate.y;

	rotate.q2.x = point.q2.x * cosf(theta) - point.q2.y * sinf(theta) + translate.x;
	rotate.q2.y = point.q2.y * cosf(theta) + point.q2.x * sinf(theta) + translate.y;

	rotate.q3.x = point.q3.x * cosf(theta) - point.q3.y * sinf(theta) + translate.x;
	rotate.q3.y = point.q3.y * cosf(theta) + point.q3.x * sinf(theta) + translate.y;

	rotate.q4.x = point.q4.x * cosf(theta) - point.q4.y * sinf(theta) + translate.x;
	rotate.q4.y = point.q4.y * cosf(theta) + point.q4.x * sinf(theta) + translate.y;

	// プレイヤーの動作処理
	Player::Move();

	if (this->shotRate > 0.0f) {
		shotRate -= 1.0 / 60.0f;
	}
	else {
		shotRate = 0.0f;
		canShot = true;
	}

}

// 描画処理
void Player::Draw() {
	// プレイヤーの描画
	Novice::DrawQuad(
		rotate.q1.x, rotate.q1.y,
		rotate.q2.x, rotate.q2.y,
		rotate.q3.x, rotate.q3.y,
		rotate.q4.x, rotate.q4.y,
		0.0f, 0.0f,
		textureSize.x, textureSize.y,
		texture,
		color
	);

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

/// <summary>
/// 射撃処理
/// </summary>
void Player::Shot() {
	
}

/// <summary>
///	プレイヤーの動作を行う変数
/// </summary>
void Player::Move() {

	// ベクトル初期化
	moveVector.x = 0.0f;
	moveVector.y = 0.0f;

	// 移動
	// 上
	if (KeyInput::GetKeyboardState(DIK_W, Press)) {
		moveVector.y--;
	}
	// 左
	if (KeyInput::GetKeyboardState(DIK_A, Press)) {
		moveVector.x--;
	}
	// 下
	if (KeyInput::GetKeyboardState(DIK_S, Press)) {
		moveVector.y++;
	}
	// 右
	if (KeyInput::GetKeyboardState(DIK_D, Press)) {
		moveVector.x++;
	}

	// ベクトルの長さを求める
	vectorLength = sqrt((moveVector.x * moveVector.x)
		+ (moveVector.y * moveVector.y));

	//ベクトルの長さが0以外の時
	if (vectorLength != 0.0f) {

		//プレイヤーのx座標にx方向のベクトルとベクトルの長さを割り、スピードをかけて足す
		translate.x += moveVector.x / vectorLength * speed.x;
		//プレイヤーのy座標にy方向のベクトルとベクトルの長さを割り、スピードをかけて足す
		translate.y += moveVector.y / vectorLength * speed.y;

	}
	else {

		translate.x += moveVector.x * speed.x;
		translate.y += moveVector.y * speed.y;

	}

}
