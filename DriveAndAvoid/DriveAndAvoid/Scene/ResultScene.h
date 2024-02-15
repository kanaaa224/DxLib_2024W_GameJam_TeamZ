#pragma once

#include"SceneBase.h"

class ResultScene :public SceneBase
{
private:
	int back_ground;  //wiæ
	int image;	//wiæ
	int titleback_SE;	//^CgÉßéSE
	int score;  //XRA
	int enemy_count[3];  //GÌJEg
	int enemy_image[3];  //Gæ

public:
	ResultScene();
	virtual ~ResultScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

private:
	void ReadResultData();
};