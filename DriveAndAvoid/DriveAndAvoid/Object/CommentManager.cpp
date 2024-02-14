#include "CommentManager.h"
#include "DxLib.h"
#include<math.h>

#define FONT_SIZE 25.0f
#define MAX_COMMENT_NUM 50//コメントの最大表示数


CommentManager::CommentManager()
{
	SetFontSize(FONT_SIZE);

	comment = new Comment * [MAX_COMMENT_NUM];

	for (int i = 0; i < MAX_COMMENT_NUM; i++)
	{
		comment[i] = nullptr;
	}

	//ランキングデータの読み込み
	FILE* fp = nullptr;

	//ファイルオープン
	errno_t result = fopen_s(&fp, "Resource/dat/comment.csv", "r");

	if (result != 0)
	{
		throw("Resource/dat/comment.csvが読み込めません\n");
	}

	//対象ファイルから読み込む
	for (int i = 0; i < COMMENT_TYPE; i++)
	{
		fscanf_s(fp, "%50s", comments[i], 50);
	}

	//ファイルクローズ
	fclose(fp);
}

CommentManager::~CommentManager()
{

}

void CommentManager::Update(Player* player)
{
	CommentGenerate();

	for (int i = 0; i < MAX_COMMENT_NUM; i++)
	{
		if (comment[i] != nullptr)
		{
			comment[i]->Update();
		}
	}
}

void CommentManager::Draw() const
{
	SetFontSize(FONT_SIZE);

	for (int i = 0; i < MAX_COMMENT_NUM; i++)
	{
		if (comment[i] != nullptr)
		{
			comment[i]->Draw();
		}

	}
}

void CommentManager::CommentGenerate()
{
	if (GetRand(40) == 0)
	{
		SetFontSize(FONT_SIZE);

		for (int i = 0; i < MAX_COMMENT_NUM; i++)
		{
			if (comment[i] == nullptr)
			{
				comment[i] = new Comment(comments[GetRand(COMMENT_TYPE)], FONT_SIZE);
			}
		}
	}
}

bool CommentManager::HitComment(Collider* collider, bool can_delete)
{
	bool is_hit = false;
	for (int i = 0; i < MAX_COMMENT_NUM; i++)
	{
		if (comment[i] != nullptr)
		{
			if (comment[i]->Hit(collider))
			{
				is_hit = true;
				if (can_delete)
				{
					delete comment[i];
					comment[i] = nullptr;
				}
				else break;
			}
		}
	}
	return is_hit;
}