#pragma once
#include "Bullet.h"
class BulletManager
{
public:

	// コンストラクタ
	BulletManager();

	// 初期化処理
	static void Initialize();

	// 更新処理
	static void Update();

	// 描画処理
	static void Draw();

	/// <summary>
	/// 指定された弾が射撃中かどうかを取得するゲッター
	/// </summary>
	/// <param name="bulletNum">情報を取得する弾</param>
	/// <returns></returns>
	bool GetBulletIsShot(int bulletNum);

	// 射撃していない弾を探し、射撃中にする
	void SetBulletIsShot();

private:

	

	// 静的なメンバ変数を宣言
	static Bullet* bullet[30];

};

