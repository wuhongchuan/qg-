#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

int _input;
int temp = 1;

int map[13][13] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
	0, 0, 14, 1, 2, 1, 1, 0, 17, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 1, 0, 0, 6, 0, 0, 0,
	0, 0, 1, 1, 1, 1, 1, 15, 6, 8, 6, 6, 0,
	0, 0, 9, 0, 0, 0, 1, 0, 0, 0, 0, 15, 0,
	0, 0, 16, 17, 0, 0, 1, 0, 6, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0,
	0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0,
	0, 5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
	0, 1, 1, 17, 7, 0, 18, 0, 6, 16, 14, 6, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int map1[13][13] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 14, 1, 4, 1, 6, 0, 14, 1, 1, 0, 17, 0,
	0, 17, 1, 0, 1, 6, 0, 0, 0, 10, 0, 6, 0,
	0, 0, 0, 0, 6, 0, 0, 6, 1, 1, 6, 6, 0,
	0, 17, 1, 6, 1, 0, 1, 1, 6, 1, 1, 6, 0,
	0, 1, 6, 1, 0, 15, 1, 6, 0, 0, 1, 1, 0,
	0, 0, 0, 1, 6, 1, 0, 0, 0, 1, 1, 0, 0,
	0, 1, 15, 1, 0, 1, 0, 17, 6, 6, 1, 6, 0,
	0, 1, 3, 1, 1, 1, 0, 6, 6, 0, 1, 0, 0,
	0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 6, 0,
	0, 1, 0, 17, 1, 6, 0, 1, 0, 0, 0, 0, 0,
	0, 13, 0, 6, 1, 6, 0, 1, 1, 1, 1, 18, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int map2[13][13] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 16, 8, 6, 0, 6, 1, 6, 0, 17, 17, 17, 0,
	0, 17, 19, 6, 15, 1, 18, 1, 0, 1, 1, 1, 0,
	0, 14, 8, 6, 0, 6, 1, 6, 0, 0, 15, 0, 0,
	0, 0, 0, 0, 0, 0, 15, 0, 0, 1, 12, 1, 0,
	0, 1, 6, 14, 6, 1, 1, 1, 6, 6, 6, 6, 0,
	0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0,
	0, 1, 1, 6, 1, 6, 0, 1, 0, 1, 1, 15, 0,
	0, 6, 0, 1, 6, 1, 0, 1, 6, 6, 0, 17, 0,
	0, 11, 0, 6, 1, 6, 0, 6, 1, 1, 0, 14, 0,
	0, 17, 0, 1, 0, 0, 0, 0, 0, 6, 0, 0, 0,
	0, 17, 0, 1, 14, 6, 13, 0, 14, 6, 1, 17, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int map3[13][13] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 6, 6, 6, 0, 0, 22, 0, 0, 6, 6, 6, 0,
	0, 6, 3, 6, 0, 0, 23, 0, 0, 6, 12, 6, 0,
	0, 6, 6, 6, 0, 0, 1, 0, 0, 6, 6, 6, 0,
	0, 6, 11, 6, 0, 0, 21, 0, 0, 6, 4, 6, 0,
	0, 6, 6, 6, 0, 0, 1, 0, 0, 6, 6, 6, 0,
	0, 6, 5, 6, 0, 0, 1, 0, 0, 6, 7, 6, 0,
	0, 6, 6, 6, 0, 0, 15, 0, 0, 6, 6, 10, 0,
	0, 6, 6, 6, 0, 6, 6, 6, 0, 6, 6, 6, 0,
	0, 6, 6, 6, 0, 6, 6, 6, 0, 6, 6, 6, 0,
	0, 8, 8, 8, 0, 6, 6, 6, 0, 8, 8, 8, 0,
	0, 8, 8, 8, 0, 0, 18, 0, 0, 8, 8, 8, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

int map4[13][13] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 6, 6, 6, 0, 0, 13, 0, 0, 6, 6, 6, 0,
	0, 6, 10, 6, 0, 0, 15, 0, 0, 6, 12, 6, 0,
	0, 6, 6, 6, 0, 0, 1, 0, 0, 6, 6, 6, 0,
	0, 6, 11, 6, 0, 0, 3, 0, 0, 6, 4, 6, 0,
	0, 6, 6, 6, 0, 0, 6, 0, 0, 6, 6, 6, 0,
	0, 6, 5, 6, 0, 0, 6, 0, 0, 6, 7, 6, 0,
	0, 6, 6, 6, 0, 0, 6, 0, 0, 6, 6, 6, 0,
	0, 6, 6, 6, 0, 0, 6, 0, 0, 6, 6, 6, 0,
	0, 6, 6, 6, 0, 6, 20, 6, 0, 6, 6, 6, 0,
	0, 8, 8, 8, 0, 6, 6, 6, 0, 8, 8, 8, 0,
	0, 8, 8, 8, 0, 0, 18, 0, 0, 8, 8, 8, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

IMAGE img[30], role, start, end, intro;
HWND hwnd;
LOGFONT f;

struct Player
{
	char name[20];
	int health;
	int mp;
	int attack;
	int defense;
	int key1;
	int key2;
}player;

struct Enemy
{
	int health;
	int attack;
	int defense;
};

struct Enemy 海军小兵 = { 10, 10, 5 };
struct Enemy 催眠师赞高 = { 22, 15, 10 };
struct Enemy 鹰眼米霍克 = { 100, 80, 50 };
struct Enemy 和平主义者 = { 38, 30, 30 };
struct Enemy 月光莫利亚 = { 50, 35, 35 };
struct Enemy 赤犬萨卡斯基 = { 110, 80, 80 };
struct Enemy 烟男斯摩格 = { 38, 30, 30 };
struct Enemy 克比 = { 34, 18, 18 };
struct Enemy 战桃丸 = { 40, 40, 40 };
struct Enemy 青雉库赞 = { 102, 80, 50 };
struct Enemy 黄猿波鲁萨利诺 = { 105, 80, 50 };
struct Enemy 海军英雄卡普 = { 50, 80, 50 };
struct Enemy 战国元帅 = { 105, 80, 50 };



bool PK(struct Enemy enemy)
{
	player.health = player.health - enemy.health;
	if (player.health <= 0)
	{
		player.health = 0;
		return false;
	}
	else
	{
		return true;
	}
}

void begin()
{	
	initgraph(1500, 500, SHOWCONSOLE);
	loadimage(&start, "start.jpg", 1500, 500);
	putimage(0, 0, &start);
	// 在屏幕中央输出字符串
	RECT r = { 0, 0, 600, 600 };
	setbkmode(TRANSPARENT);       //去掉文字的背景
	gettextstyle(&f);                     //获取当前字体设置
	f.lfHeight = 48;                      //设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("方正舒体"));		// 设置字体为“楷体”
	f.lfQuality = ANTIALIASED_QUALITY;     // 设置输出效果为抗锯齿  
	settextstyle(&f);                      // 设置字体样式
	settextcolor(YELLOW);
	outtextxy(120, 50, _T("魔塔——海贼王"));
	RECT r1 = { 0, 0, 600, 600 };
	setbkmode(TRANSPARENT);       
	gettextstyle(&f);                     
	f.lfHeight = 24;                      
	_tcscpy_s(f.lfFaceName, _T("华文行楷"));		
	f.lfQuality = ANTIALIASED_QUALITY;     
	settextstyle(&f);    
	outtextxy(225, 100, _T("Made by 吴泓川"));
}

void finish()
{
	PlaySound(NULL, NULL, SND_LOOP | SND_FILENAME | SND_ASYNC);
	PlaySound("attack.wav", NULL, SND_LOOP | SND_FILENAME | SND_ASYNC);
	initgraph(600, 600, SHOWCONSOLE);
	loadimage(&end, "finish.jpg", 600, 600);
	putimage(0, 0, &end);
	RECT r2 = { 0, 0, 600, 600 };
	setbkmode(TRANSPARENT);
	gettextstyle(&f);
	f.lfHeight = 40;
	_tcscpy_s(f.lfFaceName, _T("华文新魏"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	settextcolor(BLACK);
	outtextxy(80, 100, _T("游戏结束，通关胜利！！！"));
}

void user()
{
	printf("此游戏没有回头路，包含五个地图，祝游戏愉快！！！~~~\n\n\n");
	printf("输入角色名字（最好三字及以内）:");
	scanf("%s", player.name);
	//初始化角色信息--->创建角色最初的状态
	player.health = 150;
	player.mp = 100;
	player.attack = 20;
	player.defense = 10;
	player.key1 = 0;
	player.key2 = 0;
}

void source()
{
	//角色信息
	loadimage(&role, "info.jpg");
	for (int i = 0; i < 30; i++)
	{
		char filename[30] = "";
		sprintf(filename, "%d.jpg", i);
		//数组名代表首地址
		//&img[i]
		loadimage(img + i, filename, 60, 60);
	}

}


//把数字转换为字符串
char str[20] = "";
char * intToWchar(int Number)
{
	sprintf(str, "%d", Number);
	return str;
}


void GameWindows()
{
	int i, j;
	int x, y;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 13; j++)
		{
			x = j * 60;
			y = i * 60;
			putimage(x, y, &img[map[i][j]]);
		}
	}
	putimage(60 * 13, 0, &role);
	setbkmode(TRANSPARENT);
	outtextxy(60 * 13 + 8, 100, player.name);
	outtextxy(60 * 13 + 12, 362, intToWchar(player.health));
	outtextxy(60 * 13 + 12, 425, intToWchar(player.mp));
	outtextxy(60 * 13 + 12, 517, intToWchar(player.attack));
	outtextxy(60 * 13 + 12, 567, intToWchar(player.defense));
	outtextxy(60 * 13 + 12, 689, intToWchar(player.key1));
	outtextxy(60 * 13 + 12, 759, intToWchar(player.key2));
}

void GameWindows1()
{
	int i, j;
	int x, y;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 13; j++)
		{
			x = j * 60;
			y = i * 60;
			putimage(x, y, &img[map1[i][j]]);
		}
	}
	putimage(60 * 13, 0, &role);
	setbkmode(TRANSPARENT);
	outtextxy(60 * 13 + 8, 100, player.name);
	outtextxy(60 * 13 + 12, 362, intToWchar(player.health));
	outtextxy(60 * 13 + 12, 425, intToWchar(player.mp));
	outtextxy(60 * 13 + 12, 517, intToWchar(player.attack));
	outtextxy(60 * 13 + 12, 567, intToWchar(player.defense));
	outtextxy(60 * 13 + 12, 689, intToWchar(player.key1));
	outtextxy(60 * 13 + 12, 759, intToWchar(player.key2));
}

void GameWindows2()
{
	int i, j;
	int x, y;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 13; j++)
		{
			x = j * 60;
			y = i * 60;
			putimage(x, y, &img[map2[i][j]]);
		}
	}
	putimage(60 * 13, 0, &role);
	setbkmode(TRANSPARENT);
	outtextxy(60 * 13 + 8, 100, player.name);
	outtextxy(60 * 13 + 12, 362, intToWchar(player.health));
	outtextxy(60 * 13 + 12, 425, intToWchar(player.mp));
	outtextxy(60 * 13 + 12, 517, intToWchar(player.attack));
	outtextxy(60 * 13 + 12, 567, intToWchar(player.defense));
	outtextxy(60 * 13 + 12, 689, intToWchar(player.key1));
	outtextxy(60 * 13 + 12, 759, intToWchar(player.key2));
}

void GameWindows3()
{
	int i, j;
	int x, y;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 13; j++)
		{
			x = j * 60;
			y = i * 60;
			putimage(x, y, &img[map3[i][j]]);
		}
	}
	putimage(60 * 13, 0, &role);
	setbkmode(TRANSPARENT);
	outtextxy(60 * 13 + 8, 100, player.name);
	outtextxy(60 * 13 + 12, 362, intToWchar(player.health));
	outtextxy(60 * 13 + 12, 425, intToWchar(player.mp));
	outtextxy(60 * 13 + 12, 517, intToWchar(player.attack));
	outtextxy(60 * 13 + 12, 567, intToWchar(player.defense));
	outtextxy(60 * 13 + 12, 689, intToWchar(player.key1));
	outtextxy(60 * 13 + 12, 759, intToWchar(player.key2));
}

void GameWindows4()
{
	int i, j;
	int x, y;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 13; j++)
		{
			x = j * 60;
			y = i * 60;
			putimage(x, y, &img[map4[i][j]]);
		}
	}
	putimage(60 * 13, 0, &role);
	setbkmode(TRANSPARENT);
	outtextxy(60 * 13 + 8, 100, player.name);
	outtextxy(60 * 13 + 12, 362, intToWchar(player.health));
	outtextxy(60 * 13 + 12, 425, intToWchar(player.mp));
	outtextxy(60 * 13 + 12, 517, intToWchar(player.attack));
	outtextxy(60 * 13 + 12, 567, intToWchar(player.defense));
	outtextxy(60 * 13 + 12, 689, intToWchar(player.key1));
	outtextxy(60 * 13 + 12, 759, intToWchar(player.key2));
}

void key_down()
{
	char cuse;
	int i = 0, j = 0;
	while (temp == 1)   //temp==2表示已经成功逃离
	{
		//锁定角色位置，2为角色位置
		//二维数组的查找
		for (i = 0; i < 13; i++)
		{
			for (j = 0; j < 13; j++)
			{
				if (map[i][j] == 18)
				{
					break;
				}
			}
			if (map[i][j] == 18)
			{
				break;
			}
		}
		GameWindows();
		cuse = _getch();  //当用户按下某个字符时，函数自动读取
		switch (cuse)
		{
		case 75:        //左箭头的ASCII码      第一张地图的←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←
		case 'A':
		case 'a':
			if (map[i][j - 1] == 1)  //瓷砖,可走
			{
				map[i][j] -= 17;
				map[i][j - 1] += 17;
			}
			else if (map[i][j - 1] == 14)
			{
				map[i][j] -= 17;
				map[i][j - 1] += 4;
				player.key1++;
			}
			else if (map[i][j - 1] == 15 && player.key1 > 0)
			{
				player.key1--;
				map[i][j] -= 17;
				map[i][j - 1] += 3;
			}
			else if (map[i][j - 1] == 6)
			{
				int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(海军小兵) == true)
					{
						map[i][j] -= 17;
						map[i][j - 1] += 12;
					}
					else
					{
						MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
					}
				}
			}
			else if (map[i][j - 1] == 8)
			{
				int ID = MessageBox(hwnd, "遭遇和平主义者", "是否攻击", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(和平主义者) == true)
					{
						map[i][j] -= 17;
						map[i][j - 1] += 10;
					}
					else
					{
						MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
					}
				}
			}
			else if (map[i][j - 1] == 2)
			{
				int ID = MessageBox(hwnd, "遭遇催眠师赞高", "是否攻击", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(催眠师赞高) == true)
					{
						map[i][j] -= 17;
						map[i][j - 1] += 16;
					}
					else
					{
						MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
					}
				}
			}
			else if (map[i][j - 1] == 17)
			{
				player.health += 60;
				map[i][j] -= 17;
				map[i][j - 1] += 1;
			}
			else if (map[i][j - 1] == 16)
			{
				player.mp += 40;
				map[i][j] -= 17;
				map[i][j - 1] += 2;
			}
			else if (map[i][j - 1] == 13)
			{
				if (temp == 2)         //temp==2表示已经成功逃离
				{
					break;
				}  
				map[i][j] -= 17;
				map[i][j - 1] += 5;
				closegraph();
				hwnd = initgraph(60 * 14, 60 * 13);
				while (temp == 1)
				{
					for (i = 0; i < 13; i++)
					{
						for (j = 0; j < 13; j++)
						{
							if (map1[i][j] == 18)
							{
								break;
							}
						}
						if (map1[i][j] == 18)
						{
							break;
						}
					}
					GameWindows1();
					cuse = _getch();  //当用户按下某个字符时，函数自动读取
					switch (cuse)
					{
					case 75:        //左箭头的ASCII码         第二个地图←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←
					case 'A':
					case 'a':
						if (map1[i][j - 1] == 1)  //瓷砖,可走
						{
							map1[i][j] -= 17;
							map1[i][j - 1] += 17;
						}
						else if (map1[i][j - 1] == 14)
						{
							map1[i][j] -= 17;
							map1[i][j - 1] += 4;
							player.key1++;
						}
						else if (map1[i][j - 1] == 15 && player.key1 > 0)
						{
							player.key1--;
							map1[i][j] -= 17;
							map1[i][j - 1] += 3;
						}
						else if (map1[i][j - 1] == 6)
						{
							int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(海军小兵) == true)
								{
									map1[i][j] -= 17;
									map1[i][j - 1] += 12;
								}
								else
								{
									MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
								}
							}
						}
						else if (map1[i][j - 1] == 4)
						{
							int ID = MessageBox(hwnd, "遭遇鹰眼米霍克", "是否攻击", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(鹰眼米霍克) == true)
								{
									map1[i][j] -= 17;
									map1[i][j - 1] += 14;
								}
								else
								{
									MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
								}
							}
						}
						else if (map1[i][j - 1] == 3)
						{
							int ID = MessageBox(hwnd, "遭遇赤犬萨卡斯基", "是否攻击", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(赤犬萨卡斯基) == true)
								{
									map1[i][j] -= 17;
									map1[i][j - 1] += 15;
								}
								else
								{
									MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
								}
							}
						}
						else if (map1[i][j - 1] == 17)
						{
							player.health += 60;
							map1[i][j] -= 17;
							map1[i][j - 1] += 1;
						}
						else if (map1[i][j - 1] == 16)
						{
							player.mp += 40;
							map1[i][j] -= 17;
							map1[i][j - 1] += 2;
						}
						break;

					case 77:        //右箭头的ASCII码  第二张地图→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→
					case 'D':
					case 'd':
						if (map1[i][j + 1] == 1)  //瓷砖,可走
						{
							map1[i][j] -= 17;
							map1[i][j + 1] += 17;
						}
						else if (map1[i][j + 1] == 14)
						{
							map1[i][j] -= 17;
							map1[i][j + 1] += 4;
							player.key1++;
						}
						else if (map1[i][j + 1] == 15 && player.key1 > 0)
						{
							player.key1--;
							map1[i][j] -= 17;
							map1[i][j + 1] += 3;
						}
						else if (map1[i][j + 1] == 6)
						{
							int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(海军小兵) == true)
								{
									map1[i][j] -= 17;
									map1[i][j + 1] += 12;
								}
								else
								{
									MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
								}
							}
						}
						else if (map1[i][j + 1] == 3)
						{
							int ID = MessageBox(hwnd, "遭遇赤犬萨卡斯基", "是否攻击", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(赤犬萨卡斯基) == true)
								{
									map1[i][j] -= 17;
									map1[i][j + 1] += 15;
								}
								else
								{
									MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
								}
							}
						}
						else if (map1[i][j + 1] == 17)
						{
							player.health += 60;
							map1[i][j] -= 17;
							map1[i][j + 1] += 1;
						}
						else if (map1[i][j + 1] == 16)
						{
							player.mp += 40;
							map1[i][j] -= 17;
							map1[i][j + 1] += 2;
						}
						break;
					case 72:        //上箭头的ASCII码       第二张地图↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
					case 'W':
					case 'w':
						if (map1[i - 1][j] == 1)  //瓷砖,可走
						{
							map1[i][j] -= 17;
							map1[i - 1][j] += 17;
						}
						else if (map1[i - 1][j] == 15 && player.key1 > 0)
						{
							player.key1--;
							map1[i][j] -= 17;
							map1[i - 1][j] += 3;
						}
						else if (map1[i - 1][j] == 6)
						{
							int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(海军小兵) == true)
								{
									map1[i][j] -= 17;
									map1[i - 1][j] += 12;
								}
								else
								{
									MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
								}
							}
						}
						else if (map1[i - 1][j] == 10)
						{
							int ID = MessageBox(hwnd, "遭遇克比", "是否攻击", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(克比) == true)
								{
									map1[i][j] -= 17;
									map1[i - 1][j] += 8;
								}
								else
								{
									MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
								}
							}
						}			
						else if (map1[i - 1][j] == 14)
						{
							map1[i][j] -= 17;
							map1[i - 1][j] += 4;
							player.key1++;
						}
						else if (map1[i - 1][j] == 15 && player.key1 > 0)
						{
							player.key1--;
							map1[i][j] -= 17;
							map1[i - 1][j] += 3;
						}
						else if (map1[i - 1][j] == 17)
						{
							player.health += 60;
							map1[i][j] -= 17;
							map1[i - 1][j] += 1;
						}
						else if (map[i - 1][j] == 16)
						{
							player.mp += 40;
							map1[i][j] -= 17;
							map1[i - 1][j] += 2;
						}
						break;
					case 80:        //下箭头的ASCII码         //第二张地图↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
					case 'S':
					case 's':
						if (map1[i + 1][j] == 1)  //瓷砖,可走
						{
							map1[i][j] -= 17;
							map1[i + 1][j] += 17;
						}
						else if (map1[i + 1][j] == 14)
						{
							map1[i][j] -= 17;
							map1[i + 1][j] += 4;
							player.key1++;
						}
						else if (map1[i + 1][j] == 15 && player.key1 > 0)
						{
							player.key1--;
							map1[i][j] -= 17;
							map1[i + 1][j] += 3;
						}
						else if (map1[i + 1][j] == 6)
						{
							int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(海军小兵) == true)
								{
									map1[i][j] -= 17;
									map1[i + 1][j] += 12;
								}
								else
								{
									MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
								}
							}
						}
						else if (map1[i + 1][j] == 3)
						{
							int ID = MessageBox(hwnd, "遭遇赤犬萨卡斯基", "是否攻击", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(赤犬萨卡斯基) == true)
								{
									map1[i][j] -= 17;
									map1[i + 1][j] += 15;
								}
								else
								{
									MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
								}
							}
						}							
						else if (map1[i + 1][j] == 17)
						{
							player.health += 60;
							map1[i][j] -= 17;
							map1[i + 1][j] += 1;
						}
						else if (map1[i + 1][j] == 16)
						{
							player.mp += 40;
							map1[i][j] -= 17;
							map1[i + 1][j] += 2;
						}
						else if (map1[i + 1][j] == 13)
						{
							if (temp == 2)
							{
								break;
							}
							map1[i][j] -= 17;
							map1[i + 1][j] += 5;
							closegraph();
							hwnd = initgraph(60 * 14, 60 * 13);
							while (temp == 1)
							{
								for (i = 0; i < 13; i++)
								{
									for (j = 0; j < 13; j++)
									{
										if (map2[i][j] == 18)
										{
											break;
										}
									}
									if (map2[i][j] == 18)
									{
										break;
									}
								}
								GameWindows2();
								cuse = _getch();  //当用户按下某个字符时，函数自动读取
								switch (cuse)
								{
								case 75:        //左箭头的ASCII码         第三个地图←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←
								case 'A':
								case 'a':
									if (map2[i][j - 1] == 1)  //瓷砖,可走
									{
										map2[i][j] -= 17;
										map2[i][j - 1] += 17;
									}
									else if (map2[i][j - 1] == 14)
									{
										map2[i][j] -= 17;
										map2[i][j - 1] += 4;
										player.key1++;
									}
									else if (map2[i][j - 1] == 15 && player.key1 > 0)
									{
										player.key1--;
										map2[i][j] -= 17;
										map2[i][j - 1] += 3;
									}
									else if (map2[i][j - 1] == 6)
									{
										int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(海军小兵) == true)
											{
												map2[i][j] -= 17;
												map2[i][j - 1] += 12;
											}
											else
											{
												MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
											}
										}
									}
									else if (map2[i][j - 1] == 12)
									{
										int ID = MessageBox(hwnd, "遭遇青雉库赞", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(青雉库赞) == true)
											{
												map2[i][j] -= 17;
												map2[i][j - 1] += 6;
											}
											else
											{
												MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
											}
										}
									}
									else if (map2[i][j - 1] == 19)
									{
										int ID = MessageBox(hwnd, "遭遇战桃丸", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(战桃丸) == true)
											{
												map2[i][j] -= 17;
												map2[i][j - 1] -= 1;
											}
											else
											{
												MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
											}
										}
									}
									else if (map2[i][j - 1] == 8)
									{
										int ID = MessageBox(hwnd, "遭遇和平主义者", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(和平主义者) == true)
											{
												map2[i][j] -= 17;
												map2[i][j - 1] += 10;
											}
											else
											{
												MessageBox(hwnd, "你凉了", "是否复活", MB_YESNO);
											}
										}
									}
									else if (map2[i][j - 1] == 17)
									{
										player.health += 60;
										map2[i][j] -= 17;
										map2[i][j - 1] += 1;
									}
									else if (map2[i][j - 1] == 16)
									{
										player.mp += 40;
										map2[i][j] -= 17;
										map2[i][j - 1] += 2;
									}
									break;

								case 77:        //右箭头的ASCII码  第三张地图→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→
								case 'D':
								case 'd':
									if (map2[i][j + 1] == 1)  //瓷砖,可走
									{
										map2[i][j] -= 17;
										map2[i][j + 1] += 17;
									}
									else if (map2[i][j + 1] == 14)
									{
										map2[i][j] -= 17;
										map2[i][j + 1] += 4;
										player.key1++;
									}
									else if (map2[i][j + 1] == 15 && player.key1 > 0)
									{
										player.key1--;
										map2[i][j] -= 17;
										map2[i][j + 1] += 3;
									}
									else if (map2[i][j + 1] == 6)
									{
										int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(海军小兵) == true)
											{
												map2[i][j] -= 17;
												map2[i][j + 1] += 12;
											}
											else
											{
												MessageBox(hwnd, "你凉了", "是否复活", MB_YESNO);
											}
										}
									}
									else if (map2[i][j + 1] == 12)
									{
										int ID = MessageBox(hwnd, "遭遇青雉库赞", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(青雉库赞) == true)
											{
												map2[i][j] -= 17;
												map2[i][j + 1] += 6;
											}
											else
											{
												MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
											}
										}
									}
									else if (map2[i][j + 1] == 19)
									{
										int ID = MessageBox(hwnd, "遭遇战桃丸", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(战桃丸) == true)
											{
												map2[i][j] -= 17;
												map2[i][j + 1] -= 1;
											}
											else
											{
												MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
											}
										}
									}
									else if (map2[i][j + 1] == 8)
									{
										int ID = MessageBox(hwnd, "遭遇和平主义者", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(和平主义者) == true)
											{
												map2[i][j] -= 17;
												map2[i][j + 1] += 10;
											}
											else
											{
												MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
											}
										}
									}
									else if (map2[i][j + 1] == 17)
									{
										player.health += 60;
										map2[i][j] -= 17;
										map2[i][j + 1] += 1;
									}
									else if (map2[i][j + 1] == 16)
									{
										player.mp += 40;
										map2[i][j] -= 17;
										map2[i][j + 1] += 2;
									}
									else if (map2[i][j + 1] == 13)            //进入第四关.................................................
									{
										if (temp == 2)         //temp==2表示已经成功逃离
										{
											break;
										}
										map2[i][j] -= 17;
										map2[i][j + 1] += 5;
										closegraph();
										hwnd = initgraph(60 * 14, 60 * 13);
										while (temp == 1)
										{
											for (i = 0; i < 13; i++)
											{
												for (j = 0; j < 13; j++)
												{
													if (map3[i][j] == 18)
													{
														break;
													}
												}
												if (map3[i][j] == 18)
												{
													break;
												}
											}
											GameWindows3();
											cuse = _getch();  //当用户按下某个字符时，函数自动读取
											switch (cuse)
											{
											case 75:        //左箭头的ASCII码         第四个地图←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←
											case 'A':
											case 'a':
												if (map3[i][j - 1] == 1)  //瓷砖,可走
													{
														map3[i][j] -= 17;
														map3[i][j - 1] += 17;
													}
												else if (map3[i][j - 1] == 14)
													{
														map3[i][j] -= 17;
														map3[i][j - 1] += 4;
														player.key1++;
													}
												else if (map3[i][j - 1] == 15 && player.key1 > 0)
													{
														player.key1--;
														map3[i][j] -= 17;
														map3[i][j - 1] += 3;
													}
												else if (map3[i][j - 1] == 6)
													{
														int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
														if (ID == IDYES)
														{
															if (PK(海军小兵) == true)
															{
																map3[i][j] -= 17;
																map3[i][j - 1] += 12;
															}
															else
															{
																MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
															}
														}
													}																				
												else if (map3[i][j - 1] == 17)
													{
														player.health += 60;
														map3[i][j] -= 17;
														map3[i][j - 1] += 1;
													}
												else if (map3[i][j - 1] == 16)
													{
														player.mp += 40;
														map3[i][j] -= 17;
														map3[i][j - 1] += 2;
													}
												break;
											case 77:        //右箭头的ASCII码        第四张地图→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→
											case 'D':
											case 'd':
												if (map3[i][j + 1] == 1)  //瓷砖,可走
												{
													map3[i][j] -= 17;
													map3[i][j + 1] += 17;
												}
												else if (map3[i][j + 1] == 14)
													{
														map3[i][j] -= 17;
														map3[i][j + 1] += 4;
														player.key1++;
													}
												else if (map3[i][j + 1] == 15 && player.key1 > 0)
													{
														player.key1--;
														map3[i][j] -= 17;
														map3[i][j + 1] += 3;
													}
												else if (map3[i][j + 1] == 6)
													{
														int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
														if (ID == IDYES)
														{
															if (PK(海军小兵) == true)
															{
																map3[i][j] -= 17;
																map3[i][j + 1] += 12;
															}
															else
															{
																MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
															}
														}
													}
												else if (map3[i][j + 1] == 17)
													{
														player.health += 60;
														map3[i][j] -= 17;
														map3[i][j + 1] += 1;
													}
												else if (map3[i][j + 1] == 16)
													{
														player.mp += 40;
														map3[i][j] -= 17;
														map3[i][j + 1] += 2;
													}
												else if (map3[i][j + 1] == 7)
													{
														int ID = MessageBox(hwnd, "遇到女帝汉库克", "是否接受钥匙", MB_YESNO);
														if (ID == IDYES)
														{
															map3[i][j] -= 17;
															map3[i][j + 1] += 11;
															player.key2++;
														}
														else;
													}
												break;
											case 72:        //上箭头的ASCII码       第四张地图↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
											case 'W':
											case 'w':
												if (map3[i - 1][j] == 1)  //瓷砖,可走
													{
														map3[i][j] -= 17;
														map3[i - 1][j] += 17;
													}
												else if (map3[i - 1][j] == 15 && player.key1 > 0)
													{
														player.key1--;
														map3[i][j] -= 17;
														map3[i - 1][j] += 3;
													}
												else if (map3[i - 1][j] == 6)
													{
														int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
														if (ID == IDYES)
														{
															if (PK(海军小兵) == true)
															{
																map3[i][j] -= 17;
																map3[i - 1][j] += 12;
															}
															else
															{
																MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
															}
														}
													}
												else if (map3[i - 1][j] == 12)
													{
														int ID = MessageBox(hwnd, "遭遇青雉库赞", "是否攻击", MB_YESNO);
														if (ID == IDYES)
														{
															if (PK(青雉库赞) == true)
															{
																map3[i][j] -= 17;
																map3[i - 1][j] += 6;
															}
															else
															{
																MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
															}
														}
													}
												else if (map3[i - 1][j] == 21)
													{
														int ID = MessageBox(hwnd, "遭遇海军英雄卡普", "是否攻击", MB_YESNO);
														if (ID == IDYES)
														{
															if (PK(海军英雄卡普) == true)
															{
																map3[i][j] -= 17;
																map3[i - 1][j] -= 3;
															}
															else
															{
																MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
															}
														}
													}
												else if (map3[i - 1][j] == 14)
													{
														map3[i][j] -= 17;
														map3[i - 1][j] += 4;
														player.key1++;
													}
												else if (map3[i - 1][j] == 17)
													{
														player.health += 60;
														map3[i][j] -= 17;
														map3[i - 1][j] += 1;
													}
												else if (map3[i - 1][j] == 16)
													{
														player.mp += 40;
														map3[i][j] -= 17;
														map3[i - 1][j] += 2;
													}
												else if (map3[i - 1][j] == 23)
												{
													int ID = MessageBox(hwnd, "艾斯手上戴着海楼石手铐", "是否解开海楼石手铐", MB_YESNO);
													if (ID == IDYES)
													{
														if (player.key2 > 0)
														{
															player.key2--;
															map3[i][j] -= 17;
															map3[i - 1][j] -= 5;
														}	
														else
														{
															MessageBoxA(hwnd, "你身上的海楼石钥匙数量不够", "发生错误了", 0); //第一个是正中间，第二个在左上角
														}
													}
												}	
												else if (map3[i - 1][j] == 22)
												{
													if (temp == 2)   //temp==2表示已经成功逃离
													{
														break;
													}
													MessageBoxA(hwnd, "成功救下艾斯与艾斯会合", "嘿嘿嘿", 0);
													map3[i][j] -= 17;
													map3[i - 1][j] -= 4;
													closegraph();
													hwnd = initgraph(60 * 14, 60 * 13);    //第五个地图..................................................................
													while (temp == 1)
													{													
														for (i = 0; i < 13; i++)
														{
															for (j = 0; j < 13; j++)
															{
																if (map4[i][j] == 18)
																{
																	break;
																}
															}
															if (map4[i][j] == 18)
															{
																break;
															}
														}
														GameWindows4();
														cuse = _getch();  //当用户按下某个字符时，函数自动读取
														switch (cuse)
														{												
														case 75:        //左箭头的ASCII码         第五张地图←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←←
														case 'A':
														case 'a':
															if (map4[i][j - 1] == 1)  //瓷砖,可走
															{
																map4[i][j] -= 17;
																map4[i][j - 1] += 17;
															}
															else if (map4[i][j - 1] == 6)
															{
																int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(海军小兵) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i][j - 1] += 12;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
																	}
																}
															}
															else if (map4[i][j - 1] == 20)
															{
																int ID = MessageBox(hwnd, "遭遇战国元帅", "是否攻击", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(战国元帅) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i][j - 1] -= 2;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
																	}
																}
															}
															break;
														case 77:        //右箭头的ASCII码        第五张地图→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→
														case 'D':
														case 'd':
															if (map4[i][j + 1] == 1)  //瓷砖,可走
															{
																map4[i][j] -= 17;
																map4[i][j + 1] += 17;
															}
															else if (map4[i][j + 1] == 6)
															{
																int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(海军小兵) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i][j + 1] += 12;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
																	}
																}
															}
															else if (map4[i][j + 1] == 20)
															{
																int ID = MessageBox(hwnd, "遭遇战国元帅", "是否攻击", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(战国元帅) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i][j + 1] -= 2;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
																	}
																}
															}
															break;
														case 72:        //上箭头的ASCII码       第五张地图↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
														case 'W':
														case 'w':
															if (map4[i - 1][j] == 1)  //瓷砖,可走
															{
																map4[i][j] -= 17;
																map4[i - 1][j] += 17;
															}	
															else if (map4[i - 1][j] == 6)
															{
																int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(海军小兵) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i - 1][j] += 12;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
																	}
																}
															}
															else if (map4[i - 1][j] == 15 && player.key1 > 0)
															{
																player.key1--;
																map4[i][j] -= 17;
																map4[i - 1][j] += 3;
															}
															else if (map4[i - 1][j] == 20)
															{
																int ID = MessageBox(hwnd, "遭遇战国元帅", "是否攻击", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(战国元帅) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i - 1][j] -= 2;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
																	}
																}
															}
															else if (map4[i - 1][j] == 3)
															{
																int ID = MessageBox(hwnd, "遭遇赤犬萨卡斯基", "是否攻击", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(赤犬萨卡斯基) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i - 1][j] += 15;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
																	}
																}
															}	
															else if (map4[i - 1][j] == 13)
															{
																MessageBoxA(hwnd, "与艾斯成功逃离", "嘿嘿嘿", 0);
																map4[i][j] -= 17;
																map4[i - 1][j] += 5;
																temp = 2;
																closegraph();			
															}
															if (temp == 2)
															{
																break;
															}
															break;
														case 80:        //下箭头的ASCII码         //第五张地图↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
														case 'S':
														case 's':
															if (map4[i + 1][j] == 1)  //瓷砖,可走
															{
																map4[i][j] -= 17;
																map4[i + 1][j] += 17;
															}
															else if (map4[i + 1][j] == 6)
															{
																int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(海军小兵) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i + 1][j] += 12;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
																	}
																}
															}
															break;
														}

													}
												}
												break;												
											case 80:        //下箭头的ASCII码       第四张地图↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓  
											case 'S':
											case 's':
												if (map3[i + 1][j] == 1)  //瓷砖,可走
													{
														map3[i][j] -= 17;
														map3[i + 1][j] += 17;
													}
												else if (map3[i + 1][j] == 15 && player.key1 > 0)
													{
														player.key1--;
														map3[i][j] -= 17;
														map3[i + 1][j] += 3;
													}
												else if (map3[i + 1][j] == 6)
													{
														int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
														if (ID == IDYES)
														{
															if (PK(海军小兵) == true)
															{
																map3[i][j] -= 17;
																map3[i + 1][j] += 12;
															}
															else
															{
																MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
															}
														}
													}																							
												else if (map3[i + 1][j] == 17)
													{
														player.health += 60;
														map3[i][j] -= 17;
														map3[i + 1][j] += 1;
													}
												else if (map3[i + 1][j] == 16)
													{
														player.mp += 40;
														map3[i][j] -= 17;
														map3[i + 1][j] += 2;
													}
												break;
											}																	
										}
									}
									break;
								case 72:        //上箭头的ASCII码       第三张地图↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
								case 'W':
								case 'w':
									if (map2[i - 1][j] == 1)  //瓷砖,可走
									{
										map2[i][j] -= 17;
										map2[i - 1][j] += 17;
									}
									else if (map2[i - 1][j] == 15 && player.key1 > 0)
									{
										player.key1--;
										map2[i][j] -= 17;
										map2[i - 1][j] += 3;
									}
									else if (map2[i - 1][j] == 6)
									{
										int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(海军小兵) == true)
											{
												map2[i][j] -= 17;
												map2[i - 1][j] += 12;
											}
											else
											{
												MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
											}
										}
									}
									else if (map2[i - 1][j] == 12)
									{
										int ID = MessageBox(hwnd, "遭遇青雉库赞", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(青雉库赞) == true)
											{
												map2[i][j] -= 17;
												map2[i - 1][j] += 6;
											}
											else
											{
												MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
											}
										}
									}
									else if (map2[i - 1][j] == 19)
									{
										int ID = MessageBox(hwnd, "遭遇战桃丸", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(战桃丸) == true)
											{
												map2[i][j] -= 17;
												map2[i - 1][j] -= 1;
											}
											else
											{
												MessageBox(hwnd, "你凉了", "是否复活", MB_YESNO);
											}
										}
									}
									else if (map2[i - 1][j] == 8)
									{
										int ID = MessageBox(hwnd, "遭遇和平主义者", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(和平主义者) == true)
											{
												map2[i][j] -= 17;
												map2[i - 1][j] += 10;
											}
											else
											{
												MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
											}
										}
									}
									else if (map2[i - 1][j] == 14)
									{
										map2[i][j] -= 17;
										map2[i - 1][j] += 4;
										player.key1++;
									}
									else if (map2[i - 1][j] == 17)
									{
										player.health += 60;
										map2[i][j] -= 17;
										map2[i - 1][j] += 1;
									}
									else if (map2[i - 1][j] == 16)
									{
										player.mp += 40;
										map2[i][j] -= 17;
										map2[i - 1][j] += 2;
									}
									break;
								case 80:        //下箭头的ASCII码         //第三张地图↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
								case 'S':
								case 's':
									if (map2[i + 1][j] == 1)  //瓷砖,可走
									{
										map2[i][j] -= 17;
										map2[i + 1][j] += 17;
									}
									else if (map2[i + 1][j] == 14)
									{
										map2[i][j] -= 17;
										map2[i + 1][j] += 4;
										player.key1++;
									}
									else if (map2[i + 1][j] == 15 && player.key1 > 0)
									{
										player.key1--;
										map2[i][j] -= 17;
										map2[i + 1][j] += 3;
									}
									else if (map2[i + 1][j] == 6)
									{
										int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(海军小兵) == true)
											{
												map2[i][j] -= 17;
												map2[i + 1][j] += 12;
											}
											else
											{
												MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
											}
										}
									}
									else if (map2[i + 1][j] == 19)
									{
										int ID = MessageBox(hwnd, "遭遇战桃丸", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(战桃丸) == true)
											{
												map2[i][j] -= 17;
												map2[i + 1][j] -= 1;
											}
											else
											{
												MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
											}
										}
									}
									else if (map2[i + 1][j] == 8)
									{
										int ID = MessageBox(hwnd, "遭遇和平主义者", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(和平主义者) == true)
											{
												map2[i][j] -= 17;
												map2[i + 1][j] += 10;
											}
											else
											{
												MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
											}
										}
									}
									else if (map2[i + 1][j] == 11)
									{
										int ID = MessageBox(hwnd, "遭遇黄猿波鲁萨利诺", "是否攻击", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(黄猿波鲁萨利诺) == true)
											{
												map2[i][j] -= 17;
												map2[i + 1][j] += 7;
											}
											else
											{
												MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
											}
										}
									}
									else if (map2[i + 1][j] == 17)
									{
										player.health += 60;
										map2[i][j] -= 17;
										map2[i + 1][j] += 1;
									}
									else if (map2[i + 1][j] == 16)
									{
										player.mp += 40;
										map2[i][j] -= 17;
										map2[i + 1][j] += 2;
									}
									break; 							
							}
						}
						break;
					}
				}
			}
			break;

		case 77:        //右箭头的ASCII码        第一张地图→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→→
		case 'D':
		case 'd':
			if (map[i][j + 1] == 1)  //瓷砖,可走
			{
				map[i][j] -= 17;
				map[i][j + 1] += 17;
			}
			else if (map[i][j + 1] == 14)
			{
				map[i][j] -= 17;
				map[i][j + 1] += 4;
				player.key1++;
			}
			else if (map[i][j + 1] == 15 && player.key1 > 0)
			{
				player.key1--;
				map[i][j] -= 17;
				map[i][j + 1] += 3;
			}
			else if (map[i][j + 1] == 6)
			{
				int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(海军小兵) == true)
					{
						map[i][j] -= 17;
						map[i][j + 1] += 12;
					}
					else
					{
						MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
					}
				}
			}
			else if (map[i][j + 1] == 8)
			{
				int ID = MessageBox(hwnd, "遭遇和平主义者", "是否攻击", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(和平主义者) == true)
					{
						map[i][j] -= 17;
						map[i][j + 1] += 10;
					}
					else
					{
						MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
					}
				}
			}
			else if (map[i][j + 1] == 17)
			{
				player.health += 60;
				map[i][j] -= 17;
				map[i][j + 1] += 1;
			}
			else if (map[i][j + 1] == 16)
			{
				player.mp += 40;
				map[i][j] -= 17;
				map[i][j + 1] += 2;
			}
			else if (map[i][j + 1] == 7)
			{
				int ID = MessageBox(hwnd, "遇到女帝汉库克", "是否接受钥匙", MB_YESNO);
				if (ID == IDYES)
				{
					map[i][j] -= 17;
					map[i][j + 1] += 11;
					player.key2++;
				}
				else;
			}
			break;
		case 72:        //上箭头的ASCII码   第一张地图↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
		case 'W':
		case 'w':
			if (map[i - 1][j] == 1)  //瓷砖,可走
			{
				map[i][j] -= 17;
				map[i - 1][j] += 17;
			}
			else if (map[i - 1][j] == 15 && player.key1 > 0)
			{
				player.key1--;
				map[i][j] -= 17;
				map[i - 1][j] += 3;
			}
			else if (map[i - 1][j] == 6)
			{
				int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(海军小兵) == true)
					{
						map[i][j] -= 17;
						map[i - 1][j] += 12;
					}
					else
					{
						MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
					}
				}
			}
			else if (map[i - 1][j] == 17)
			{
				player.health += 60;
				map[i][j] -= 17;
				map[i - 1][j] += 1;
			}
			else if (map[i - 1][j] == 16)
			{
				player.mp += 40;
				map[i][j] -= 17;
				map[i - 1][j] += 2;
			}
			break;
		case 80:        //下箭头的ASCII码       第一张地图↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓  
		case 'S':
		case 's':
			if (map[i + 1][j] == 1)  //瓷砖,可走
			{
				map[i][j] -= 17;
				map[i + 1][j] += 17;
			}
			else if (map[i + 1][j] == 15 && player.key1 > 0)
			{
				player.key1--;
				map[i][j] -= 17;
				map[i + 1][j] += 3;
			}
			else if (map[i + 1][j] == 6)
			{
				int ID = MessageBox(hwnd, "遭遇海军小兵", "是否攻击", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(海军小兵) == true)
					{
						map[i][j] -= 17;
						map[i + 1][j] += 12;
					}
					else
					{
						MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
					}
				}
			}
			else if (map[i + 1][j] == 9)
			{
				int ID = MessageBox(hwnd, "遭遇月光莫利亚", "是否攻击", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(月光莫利亚) == true)
					{
						map[i][j] -= 17;
						map[i + 1][j] += 9;
					}
					else
					{
						MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
					}
				}
			}
			else if (map[i + 1][j] == 5)
			{
				int ID = MessageBox(hwnd, "遇到烟男斯摩格", "是否攻击", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(烟男斯摩格) == true)
					{
						map[i][j] -= 17;
						map[i + 1][j] += 13;
					}
					else
					{
						MessageBoxA(hwnd, "你凉了，重开一下游戏吧", "嘿嘿嘿", 0);
					}
				}
			}
			else if (map[i + 1][j] == 17)
			{
				player.health += 60;
				map[i][j] -= 17;
				map[i + 1][j] += 1;
			}
			else if (map[i + 1][j] == 16)
			{
				player.mp += 40;
				map[i][j] -= 17;
				map[i + 1][j] += 2;
			}
			break;
		}
	}
	}
}

void wait()
{
	Sleep(100);
	_input = getchar();
}

int main()
{    // SND_LOOP循环播放，要和SND_ASYNC一起用，SND_FILENAME表示pszSound参数指定的是文件名	
	PlaySound("white.wav", NULL, SND_LOOP | SND_FILENAME | SND_ASYNC);
	begin();
	user();
	PlaySound(NULL, NULL, SND_LOOP | SND_FILENAME | SND_ASYNC);
	closegraph();
	source();
	hwnd = initgraph(60 * 14, 60 * 13);
	while (temp == 1)
	{
		PlaySound("fire.wav", NULL, SND_LOOP | SND_FILENAME | SND_ASYNC);
		GameWindows();
		key_down();
		finish();
	}
	finish();
	while (1);
	closegraph();
	return 0;
}