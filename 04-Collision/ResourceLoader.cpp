#include "ResourceLoader.h"
#include "debug.h"
#include "Goomba.h"
#include "Brick.h"
#include "Map.h"
#include "define.h"

ResourceLoader* ResourceLoader::_instance = NULL;
ResourceLoader::ResourceLoader(void)
{
}

ResourceLoader::~ResourceLoader(void)
{
	/*objects.clear();
	objects.~vector();
	map_vector.clear();
	map_vector.~vector();*/
}

ResourceLoader* ResourceLoader::GetInstance()
{
	if (_instance == NULL)
		_instance = new ResourceLoader();
	return _instance;
}

void ResourceLoader::LoadObjectFromFile(string FileName)
{
	//CreateAnimation();
	std::ifstream infile(FileName);
	string id;
	float  x, y, w, h;
	while (infile >> id >> x >> y >> w >> h)
	{
		//Chuyen toa do y theo goc toa do cua file txt thanh toa do decart
		ChangeYtoDecart(y);

		/*if (id == GROUND0_ID)
		{
			Ground* ground = new Ground();
			ground->AddAnimation(301);
			ground->SetPosition(x, y);
			ground->SetID(BRICK_ID);
			ground->SetName("Ground");
			ground->width = w;
			ground->height = h;
			objects.push_back(ground);
		}*/
		//if (id == GOOMBA_ID)
		//{
		//	CGoomba* goomba = new CGoomba();
		//	goomba->AddAnimation(GOOMBA_WALKING);
		//	goomba->AddAnimation(702);
		//	goomba->SetPosition(x, y);
		//	//goomba->width = w;
		//	//goomba->height = h;
		//	goomba->SetState(GOOMBA_STATE_WALKING);
		//	//goomba->SetState(GOOMBA_STATE_DIE);
		//	goomba->SetID(GOOMBA_ID);
		//	//goomba->SetID(i);
		//	objects.push_back(goomba);
		//}
	}
}

void ResourceLoader::LoadObjectFromFile(string FileName, vector<LPGAMEOBJECT>& objects)
{
	//CreateAnimation();
	std::ifstream infile(FileName);
	string id;
	float  x, y, w, h;
	while (infile >> id >> x >> y >> w >> h)
	{
		//Chuyen toa do y theo goc toa do cua file txt thanh toa do decart
		ChangeYtoDecart(y);

		if (id == "brick_0")
		{
			CBrick* brick = new CBrick();
			brick->AddAnimation(601);
			brick->SetPosition(x, y);
			//brick->width = w;
			//brick->height = h;
			objects.push_back(brick);
		}
		if (id == "goomba_0 ")
		{
			CGoomba* goomba = new CGoomba();
			goomba->AddAnimation(701);
			goomba->AddAnimation(702);
			goomba->SetPosition(x, y);
			//brick->width = w;
			//brick->height = h;
			objects.push_back(goomba);
		}
	}
}

//Load map from file ver 1
void ResourceLoader::LoadMapFromFile(string FileName, LPDIRECT3DTEXTURE9 texMap, 
	vector<LPGAMEOBJECT>& map_vector)
{
	std::ifstream infile(FileName);
	string id;
	float  x, y, w, h;
	while (infile >> id >> x >> y >> w >> h)
	{
		//Add sprite 1 vào cell map 1
		CSprites* sprites = CSprites::GetInstance();
		sprites->Add(40001, x, y, x + w, y + h, texMap);

		LPANIMATION ani;
		ani = new CAnimation(100);
		ani->Add(40001);
		CAnimations* animations = CAnimations::GetInstance();
		animations->Add(801, ani);

		ChangeYtoDecart(y);
		//khởi tạo cell map
		CMap* map1 = new CMap();

		map1->AddAnimation(801);
		//map1->width = w;
		//map1->height = h;
		map1->SetPosition(x, y);
		map_vector.push_back(map1);
	}
}

void ResourceLoader::ChangeYtoDecart(float& y)
{
	y = MAP_HEIGHT + 38 - y; //38 la do lech pixel o duoi man hinh
}

//void ResourceLoader::CreateAnimation()
//{
//	LoadSprite();
//	LPANIMATION ani;
//
//	//Aladdin animation
//	int aladdin_sprite_id = 10000;
//	//idle right
//	ani = new CAnimation(100);
//	ani->Add(aladdin_sprite_id + 1);
//	animations->Add(AladdinAnimation::ALADDIN + 1, ani);
//
//	//idle right
//	ani = new CAnimation(100);
//	ani->Add(-(aladdin_sprite_id + 1));
//	animations->Add(-(AladdinAnimation::ALADDIN + 1), ani);
//
//	//running right
//	ani = new CAnimation(100);
//	for (int i = 1; i <= 13; i++)
//	{
//		ani->Add(aladdin_sprite_id + i);
//	}
//	animations->Add(AladdinAnimation::ALADDIN + 2, ani);
//
//	//running left
//	ani = new CAnimation(100);
//	for (int i = 1; i <= 13; i++)
//	{
//		ani->Add(-((aladdin_sprite_id + i));
//	}
//	animations->Add(-(AladdinAnimation::ALADDIN + 2), ani);
//
//	//Animation ground
//	ani = new CAnimation(100);
//	ani->Add(30001);
//	animations->Add(301, ani);
//
//	//////-------Load Map from file
//	//LPDIRECT3DTEXTURE9 texMap = textures->Get(TEX_MAP_DUNGEON);
//	///*ResourceLoader::GetInstance()->LoadMapFromFile("Map_Background.txt",
//	//	texMap, objects);*/
//	//LoadMapFromFile("Map_Background.txt",texMap);
//	///*ResourceLoader::GetInstance()->LoadMapFromFile("Map_Background.txt",
//	//	texMap, objects);*/
//
//
//	////Load Object From File
//	//string FileName = "test2.txt";
//	//ResourceLoader::GetInstance()->LoadObjectFromFile(FileName);
//}

//void ResourceLoader::LoadSprite()
//{
//	CTextures* textures = CTextures::GetInstance();
//
//	textures->Add(TEX_BBOX, L"textures\\bbox.png", D3DCOLOR_XRGB(255, 255, 255));
//	textures->Add(TEX_MAP_DUNGEON, L"textures\\Sultans Dungeon_Back.png", D3DCOLOR_XRGB(255, 255, 255));
//	textures->Add(TEX_DUNGEON_ENVIRONMENT, L"textures\\Sultans Dungeon_Object.png", D3DCOLOR_XRGB(163, 73, 164));
//	textures->Add(TEX_ALADDIN, L"textures\\Aladdin.png", D3DCOLOR_XRGB(255, 0, 255));
//	textures->Add(TEX_ALADDIN_LEFT, L"textures\\Aladdin_left.png", D3DCOLOR_XRGB(255, 0, 255));
//	textures->Add(TEX_GUARD, L"textures\\Guards.png", D3DCOLOR_XRGB(255, 0, 255));
//	textures->Add(TEX_GUARD_LEFT, L"textures\\Guards_left.png", D3DCOLOR_XRGB(120, 193, 152));
//	textures->Add(TEX_APPLE, L"textures\\Apple.png", D3DCOLOR_XRGB(120, 193, 152));
//	textures->Add(TEX_GROUND, L"textures\\Ground.png", D3DCOLOR_XRGB(255, 255, 255));
//
//
//
//	CSprites* sprites = CSprites::GetInstance();
//	CAnimations* animations = CAnimations::GetInstance();
//
//	LPDIRECT3DTEXTURE9 texAladdin = textures->Get(TEX_ALADDIN);
//	LPDIRECT3DTEXTURE9 texAladdin_Left = textures->Get(TEX_ALADDIN_LEFT);
//
//	//Aladdin
//	sprites->Add(10001, 14, 1225, 54, 1273, texAladdin);		// idle right
//	sprites->Add(10002, 66, 1222, 109, 1273, texAladdin);
//	sprites->Add(10003, 120, 1220, 161, 1273, texAladdin);
//	sprites->Add(10004, 171, 1216, 212, 1273, texAladdin);
//	sprites->Add(10005, 220, 1216, 272, 1273, texAladdin);
//	sprites->Add(10006, 279, 1219, 325, 1273, texAladdin);
//	sprites->Add(10007, 334, 1215, 376, 1273, texAladdin);
//	sprites->Add(10008, 386, 1221, 427, 1273, texAladdin);
//	sprites->Add(10009, 440, 1219, 475, 1273, texAladdin);
//	sprites->Add(10010, 488, 1216, 537, 1273, texAladdin);
//	sprites->Add(10011, 547, 1215, 602, 1273, texAladdin);
//	sprites->Add(10012, 611, 1219, 666, 1273, texAladdin);
//	sprites->Add(10013, 679, 1218, 723, 1273, texAladdin);
//
//	sprites->Add(-10001, 1067, 1225, 1107, 1273, texAladdin_Left); //left
//	sprites->Add(-10002, 1012, 1222, 1055, 1273, texAladdin_Left);
//	sprites->Add(-10003, 960, 1220, 1001, 1273, texAladdin_Left);
//	sprites->Add(-10004, 909, 1216, 950, 1273, texAladdin_Left);
//	sprites->Add(-10005, 849, 1216, 901, 1273, texAladdin_Left);
//	sprites->Add(-10006, 796, 1219, 842, 1273, texAladdin_Left);
//	sprites->Add(-10007, 745, 1215, 787, 1273, texAladdin_Left);
//	sprites->Add(-10008, 694, 1221, 690, 1273, texAladdin_Left);
//	sprites->Add(-10009, 646, 1219, 681, 1273, texAladdin_Left);
//	sprites->Add(-10010, 584, 1216, 633, 1273, texAladdin_Left);
//	sprites->Add(-10011, 519, 1215, 574, 1273, texAladdin_Left);
//	sprites->Add(-10012, 455, 1219, 510, 1273, texAladdin_Left);
//	sprites->Add(-10013, 398, 1218, 442, 1273, texAladdin_Left);
//
//
//	LPDIRECT3DTEXTURE9 texApple = textures->Get(TEX_APPLE);
//	//Apple
//	sprites->Add(20001, 8, 18, 19, 30, texApple);		// idle apple
//	sprites->Add(20002, 35, 19, 47, 30, texApple);
//	sprites->Add(20003, 62, 19, 73, 31, texApple);
//	sprites->Add(20004, 87, 19, 99, 30, texApple);
//	sprites->Add(20005, 113, 20, 120, 30, texApple);
//	sprites->Add(20006, 133, 15, 153, 33, texApple);
//	sprites->Add(20007, 163, 13, 192, 35, texApple);
//	sprites->Add(20008, 240, 11, 235, 36, texApple);
//	sprites->Add(20009, 251, 10, 281, 37, texApple);
//
//	LPDIRECT3DTEXTURE9 texGround = textures->Get(TEX_GROUND);
//	//Ground
//	sprites->Add(30001, 10, 10, 100, 100, texGround);
//}
