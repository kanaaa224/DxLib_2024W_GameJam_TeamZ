#pragma once

#include"SceneBase.h"
#include"../Object/Enemy.h"
#include"../Object/Player.h"
#include"../Object/Comment.h"

#define BUFFER 2000

class GameMainScene :public SceneBase
{
private:
	int back_ground;  //背景画像
	int gamemainscene_image; //ゲームシーン画像
	int barrier_image;   //バリア画像
	int img_gameoverWindow;  // ゲームオーバー時のウィンドウ画像
	int img_gameclearWindow; // ゲームクリア時のウィンドウ画像
	int img_superChat;

	int high_score;  //ハイスコア
	int mileage;   //走行距離
	int enemy_image[3];  //敵画像
	int enemy_count[3];  //通り過ぎた敵カウント
	int comment_count;	//生成したコメント数
	const char *text[BUFFER];	//コメント表示
	unsigned int color_num[BUFFER];
	int disp_hpbar;	//HPバーの表示
	Player* player;  //プレイヤー

	Comment** comment;         // コメント（敵）
	CommentData* commentDatas; // コメントのデータ（csvファイルからロード）
	Enemy** enemy;//敵キャラ
	int commentDatas_num;      // コメントのデータの数

	bool isGameover;  // ゲームオーバーの状態
	bool isGameclear; // ゲームクリアの状態

public:
	GameMainScene();
	virtual ~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

private:
	//ハイスコア読み込み処理
	void ReadHighScore();
	//当たり判定
	bool IsHitCheck(Player* p, Comment* e);
};