#include <Novice.h>
#include "Const.h"
#include "KeyInput.h"
#include "Player.h"
#include "BulletManager.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	/*********************************
		変数宣言ここから
	*********************************/

	// シーン管理用
	int scene = TITLE;

	Player* player = new Player;
	player->Initialize();

	BulletManager::Initialize();

	/*********************************
		変数宣言ここまで
	*********************************/

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// フルスクリーンに設定
		Novice::SetWindowMode(kFullscreen);

		// カーソル消去
		Novice::SetMouseCursorVisibility(0);

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		/*********************************
			更新処理ここから
		*********************************/
		// キー入力検知更新
		KeyInput::Update();

		switch (scene)
		{
		case TITLE:
			// スペースキーを押したらシーン切り替え
			if (KeyInput::GetKeyboardState(DIK_SPACE, Trigger)) {
				scene = GAME;
			}


			break;
		case GAME:
			// プレイヤーの更新処理
			player->Update();

			// 弾の更新処理
			BulletManager::Update();

			break;
		case RESULT:


			break;
		}

		/*********************************
			更新処理ここまで
		*********************************/

		/*********************************
			描画処理ここから
		*********************************/

		switch (scene)
		{
		case TITLE:
			Novice::ScreenPrintf(kWindowWidth / 2, kWindowHeight / 2, "TITLE");

			break;
		case GAME:

			player->Draw();
			
			BulletManager::Draw();

			break;
		case RESULT:


			break;
		}

		/*********************************
			描画処理ここまで
		*********************************/

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (KeyInput::GetKeyboardState(DIK_ESCAPE, Trigger)) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
