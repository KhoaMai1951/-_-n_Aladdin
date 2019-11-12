#pragma once
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <fstream>
#include <string>

//#include "define.h"
//#include "Map.h"
//#include "Ground.h"
#include "Goomba.h"
#include "Textures.h"

class ResourceLoader
{
public:
	~ResourceLoader();
	ResourceLoader();
	vector<LPGAMEOBJECT> objects;
	vector<LPGAMEOBJECT> map_vector;

	static ResourceLoader* GetInstance();
	void LoadObjectFromFile(string FileName);
	void LoadObjectFromFile(string FileName, vector<LPGAMEOBJECT> &objects);
	//void LoadMapFromFile(string FileName, LPDIRECT3DTEXTURE9 texMap);
	void LoadMapFromFile(string FileName, LPDIRECT3DTEXTURE9 texMap, vector<LPGAMEOBJECT>& map_vector);

	//void LoadSprite();
	//void CreateAnimation();
	void ChangeYtoDecart(float& y);
	//void LoadResource();


private:
	static ResourceLoader* _instance;

};

