#include "BulletManager.h"

// コンストラクタ
BulletManager::BulletManager() {

}

// 初期化処理
void BulletManager::Initialize() {
	// 弾を初期化
	for (int i = 0; i < 30; i++) {
		bullet[i] = new Bullet;
		bullet[i]->Initialize();
	}
}

// 更新処理
void BulletManager::Update(){
	// 弾の更新処理
	for (int i = 0; i < 30; i++) {
		bullet[i]->Update();
	}
}

// 描画処理
void BulletManager::Draw() {
	// 弾の描画処理
	for (int i = 0; i < 30; i++) {
		if(bullet[i]->GetIsShot() == true)
		bullet[i]->Draw();
	}
}

/// <summary>
/// 指定された弾が射撃中かどうかを取得するゲッター
/// </summary>
/// <param name="bulletNum">情報を取得する弾</param>
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

// メンバ変数の実体を宣言
Bullet* BulletManager::bullet[30];