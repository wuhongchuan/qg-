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

struct Enemy ����С�� = { 10, 10, 5 };
struct Enemy ����ʦ�޸� = { 22, 15, 10 };
struct Enemy ӥ���׻��� = { 100, 80, 50 };
struct Enemy ��ƽ������ = { 38, 30, 30 };
struct Enemy �¹�Ī���� = { 50, 35, 35 };
struct Enemy ��Ȯ����˹�� = { 110, 80, 80 };
struct Enemy ����˹Ħ�� = { 38, 30, 30 };
struct Enemy �˱� = { 34, 18, 18 };
struct Enemy ս���� = { 40, 40, 40 };
struct Enemy �������� = { 102, 80, 50 };
struct Enemy ��Գ��³����ŵ = { 105, 80, 50 };
struct Enemy ����Ӣ�ۿ��� = { 50, 80, 50 };
struct Enemy ս��Ԫ˧ = { 105, 80, 50 };



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
	// ����Ļ��������ַ���
	RECT r = { 0, 0, 600, 600 };
	setbkmode(TRANSPARENT);       //ȥ�����ֵı���
	gettextstyle(&f);                     //��ȡ��ǰ��������
	f.lfHeight = 48;                      //��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("��������"));		// ��������Ϊ�����塱
	f.lfQuality = ANTIALIASED_QUALITY;     // �������Ч��Ϊ�����  
	settextstyle(&f);                      // ����������ʽ
	settextcolor(YELLOW);
	outtextxy(120, 50, _T("ħ������������"));
	RECT r1 = { 0, 0, 600, 600 };
	setbkmode(TRANSPARENT);       
	gettextstyle(&f);                     
	f.lfHeight = 24;                      
	_tcscpy_s(f.lfFaceName, _T("�����п�"));		
	f.lfQuality = ANTIALIASED_QUALITY;     
	settextstyle(&f);    
	outtextxy(225, 100, _T("Made by ������"));
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
	_tcscpy_s(f.lfFaceName, _T("������κ"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	settextcolor(BLACK);
	outtextxy(80, 100, _T("��Ϸ������ͨ��ʤ��������"));
}

void user()
{
	printf("����Ϸû�л�ͷ·�����������ͼ��ף��Ϸ��죡����~~~\n\n\n");
	printf("�����ɫ���֣�������ּ����ڣ�:");
	scanf("%s", player.name);
	//��ʼ����ɫ��Ϣ--->������ɫ�����״̬
	player.health = 150;
	player.mp = 100;
	player.attack = 20;
	player.defense = 10;
	player.key1 = 0;
	player.key2 = 0;
}

void source()
{
	//��ɫ��Ϣ
	loadimage(&role, "info.jpg");
	for (int i = 0; i < 30; i++)
	{
		char filename[30] = "";
		sprintf(filename, "%d.jpg", i);
		//�����������׵�ַ
		//&img[i]
		loadimage(img + i, filename, 60, 60);
	}

}


//������ת��Ϊ�ַ���
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
	while (temp == 1)   //temp==2��ʾ�Ѿ��ɹ�����
	{
		//������ɫλ�ã�2Ϊ��ɫλ��
		//��ά����Ĳ���
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
		cuse = _getch();  //���û�����ĳ���ַ�ʱ�������Զ���ȡ
		switch (cuse)
		{
		case 75:        //���ͷ��ASCII��      ��һ�ŵ�ͼ�ġ�����������������������������������������������������������������������������
		case 'A':
		case 'a':
			if (map[i][j - 1] == 1)  //��ש,����
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
				int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(����С��) == true)
					{
						map[i][j] -= 17;
						map[i][j - 1] += 12;
					}
					else
					{
						MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
					}
				}
			}
			else if (map[i][j - 1] == 8)
			{
				int ID = MessageBox(hwnd, "������ƽ������", "�Ƿ񹥻�", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(��ƽ������) == true)
					{
						map[i][j] -= 17;
						map[i][j - 1] += 10;
					}
					else
					{
						MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
					}
				}
			}
			else if (map[i][j - 1] == 2)
			{
				int ID = MessageBox(hwnd, "��������ʦ�޸�", "�Ƿ񹥻�", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(����ʦ�޸�) == true)
					{
						map[i][j] -= 17;
						map[i][j - 1] += 16;
					}
					else
					{
						MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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
				if (temp == 2)         //temp==2��ʾ�Ѿ��ɹ�����
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
					cuse = _getch();  //���û�����ĳ���ַ�ʱ�������Զ���ȡ
					switch (cuse)
					{
					case 75:        //���ͷ��ASCII��         �ڶ�����ͼ������������������������������������������������������������������
					case 'A':
					case 'a':
						if (map1[i][j - 1] == 1)  //��ש,����
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
							int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(����С��) == true)
								{
									map1[i][j] -= 17;
									map1[i][j - 1] += 12;
								}
								else
								{
									MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
								}
							}
						}
						else if (map1[i][j - 1] == 4)
						{
							int ID = MessageBox(hwnd, "����ӥ���׻���", "�Ƿ񹥻�", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(ӥ���׻���) == true)
								{
									map1[i][j] -= 17;
									map1[i][j - 1] += 14;
								}
								else
								{
									MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
								}
							}
						}
						else if (map1[i][j - 1] == 3)
						{
							int ID = MessageBox(hwnd, "������Ȯ����˹��", "�Ƿ񹥻�", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(��Ȯ����˹��) == true)
								{
									map1[i][j] -= 17;
									map1[i][j - 1] += 15;
								}
								else
								{
									MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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

					case 77:        //�Ҽ�ͷ��ASCII��  �ڶ��ŵ�ͼ������������������������������������������������������������������������������
					case 'D':
					case 'd':
						if (map1[i][j + 1] == 1)  //��ש,����
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
							int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(����С��) == true)
								{
									map1[i][j] -= 17;
									map1[i][j + 1] += 12;
								}
								else
								{
									MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
								}
							}
						}
						else if (map1[i][j + 1] == 3)
						{
							int ID = MessageBox(hwnd, "������Ȯ����˹��", "�Ƿ񹥻�", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(��Ȯ����˹��) == true)
								{
									map1[i][j] -= 17;
									map1[i][j + 1] += 15;
								}
								else
								{
									MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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
					case 72:        //�ϼ�ͷ��ASCII��       �ڶ��ŵ�ͼ��������������������������������������������������������������������������
					case 'W':
					case 'w':
						if (map1[i - 1][j] == 1)  //��ש,����
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
							int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(����С��) == true)
								{
									map1[i][j] -= 17;
									map1[i - 1][j] += 12;
								}
								else
								{
									MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
								}
							}
						}
						else if (map1[i - 1][j] == 10)
						{
							int ID = MessageBox(hwnd, "�����˱�", "�Ƿ񹥻�", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(�˱�) == true)
								{
									map1[i][j] -= 17;
									map1[i - 1][j] += 8;
								}
								else
								{
									MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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
					case 80:        //�¼�ͷ��ASCII��         //�ڶ��ŵ�ͼ����������������������������������������������������������������������
					case 'S':
					case 's':
						if (map1[i + 1][j] == 1)  //��ש,����
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
							int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(����С��) == true)
								{
									map1[i][j] -= 17;
									map1[i + 1][j] += 12;
								}
								else
								{
									MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
								}
							}
						}
						else if (map1[i + 1][j] == 3)
						{
							int ID = MessageBox(hwnd, "������Ȯ����˹��", "�Ƿ񹥻�", MB_YESNO);
							if (ID == IDYES)
							{
								if (PK(��Ȯ����˹��) == true)
								{
									map1[i][j] -= 17;
									map1[i + 1][j] += 15;
								}
								else
								{
									MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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
								cuse = _getch();  //���û�����ĳ���ַ�ʱ�������Զ���ȡ
								switch (cuse)
								{
								case 75:        //���ͷ��ASCII��         ��������ͼ������������������������������������������������������������������
								case 'A':
								case 'a':
									if (map2[i][j - 1] == 1)  //��ש,����
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
										int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(����С��) == true)
											{
												map2[i][j] -= 17;
												map2[i][j - 1] += 12;
											}
											else
											{
												MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
											}
										}
									}
									else if (map2[i][j - 1] == 12)
									{
										int ID = MessageBox(hwnd, "������������", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(��������) == true)
											{
												map2[i][j] -= 17;
												map2[i][j - 1] += 6;
											}
											else
											{
												MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
											}
										}
									}
									else if (map2[i][j - 1] == 19)
									{
										int ID = MessageBox(hwnd, "����ս����", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(ս����) == true)
											{
												map2[i][j] -= 17;
												map2[i][j - 1] -= 1;
											}
											else
											{
												MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
											}
										}
									}
									else if (map2[i][j - 1] == 8)
									{
										int ID = MessageBox(hwnd, "������ƽ������", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(��ƽ������) == true)
											{
												map2[i][j] -= 17;
												map2[i][j - 1] += 10;
											}
											else
											{
												MessageBox(hwnd, "������", "�Ƿ񸴻�", MB_YESNO);
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

								case 77:        //�Ҽ�ͷ��ASCII��  �����ŵ�ͼ������������������������������������������������������������������������������
								case 'D':
								case 'd':
									if (map2[i][j + 1] == 1)  //��ש,����
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
										int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(����С��) == true)
											{
												map2[i][j] -= 17;
												map2[i][j + 1] += 12;
											}
											else
											{
												MessageBox(hwnd, "������", "�Ƿ񸴻�", MB_YESNO);
											}
										}
									}
									else if (map2[i][j + 1] == 12)
									{
										int ID = MessageBox(hwnd, "������������", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(��������) == true)
											{
												map2[i][j] -= 17;
												map2[i][j + 1] += 6;
											}
											else
											{
												MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
											}
										}
									}
									else if (map2[i][j + 1] == 19)
									{
										int ID = MessageBox(hwnd, "����ս����", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(ս����) == true)
											{
												map2[i][j] -= 17;
												map2[i][j + 1] -= 1;
											}
											else
											{
												MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
											}
										}
									}
									else if (map2[i][j + 1] == 8)
									{
										int ID = MessageBox(hwnd, "������ƽ������", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(��ƽ������) == true)
											{
												map2[i][j] -= 17;
												map2[i][j + 1] += 10;
											}
											else
											{
												MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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
									else if (map2[i][j + 1] == 13)            //������Ĺ�.................................................
									{
										if (temp == 2)         //temp==2��ʾ�Ѿ��ɹ�����
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
											cuse = _getch();  //���û�����ĳ���ַ�ʱ�������Զ���ȡ
											switch (cuse)
											{
											case 75:        //���ͷ��ASCII��         ���ĸ���ͼ������������������������������������������������������������������
											case 'A':
											case 'a':
												if (map3[i][j - 1] == 1)  //��ש,����
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
														int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
														if (ID == IDYES)
														{
															if (PK(����С��) == true)
															{
																map3[i][j] -= 17;
																map3[i][j - 1] += 12;
															}
															else
															{
																MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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
											case 77:        //�Ҽ�ͷ��ASCII��        �����ŵ�ͼ����������������������������������������������������������������������������
											case 'D':
											case 'd':
												if (map3[i][j + 1] == 1)  //��ש,����
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
														int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
														if (ID == IDYES)
														{
															if (PK(����С��) == true)
															{
																map3[i][j] -= 17;
																map3[i][j + 1] += 12;
															}
															else
															{
																MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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
														int ID = MessageBox(hwnd, "����Ů�ۺ����", "�Ƿ����Կ��", MB_YESNO);
														if (ID == IDYES)
														{
															map3[i][j] -= 17;
															map3[i][j + 1] += 11;
															player.key2++;
														}
														else;
													}
												break;
											case 72:        //�ϼ�ͷ��ASCII��       �����ŵ�ͼ��������������������������������������������������������������������������
											case 'W':
											case 'w':
												if (map3[i - 1][j] == 1)  //��ש,����
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
														int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
														if (ID == IDYES)
														{
															if (PK(����С��) == true)
															{
																map3[i][j] -= 17;
																map3[i - 1][j] += 12;
															}
															else
															{
																MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
															}
														}
													}
												else if (map3[i - 1][j] == 12)
													{
														int ID = MessageBox(hwnd, "������������", "�Ƿ񹥻�", MB_YESNO);
														if (ID == IDYES)
														{
															if (PK(��������) == true)
															{
																map3[i][j] -= 17;
																map3[i - 1][j] += 6;
															}
															else
															{
																MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
															}
														}
													}
												else if (map3[i - 1][j] == 21)
													{
														int ID = MessageBox(hwnd, "��������Ӣ�ۿ���", "�Ƿ񹥻�", MB_YESNO);
														if (ID == IDYES)
														{
															if (PK(����Ӣ�ۿ���) == true)
															{
																map3[i][j] -= 17;
																map3[i - 1][j] -= 3;
															}
															else
															{
																MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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
													int ID = MessageBox(hwnd, "��˹���ϴ��ź�¥ʯ����", "�Ƿ�⿪��¥ʯ����", MB_YESNO);
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
															MessageBoxA(hwnd, "�����ϵĺ�¥ʯԿ����������", "����������", 0); //��һ�������м䣬�ڶ��������Ͻ�
														}
													}
												}	
												else if (map3[i - 1][j] == 22)
												{
													if (temp == 2)   //temp==2��ʾ�Ѿ��ɹ�����
													{
														break;
													}
													MessageBoxA(hwnd, "�ɹ����°�˹�밬˹���", "�ٺٺ�", 0);
													map3[i][j] -= 17;
													map3[i - 1][j] -= 4;
													closegraph();
													hwnd = initgraph(60 * 14, 60 * 13);    //�������ͼ..................................................................
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
														cuse = _getch();  //���û�����ĳ���ַ�ʱ�������Զ���ȡ
														switch (cuse)
														{												
														case 75:        //���ͷ��ASCII��         �����ŵ�ͼ������������������������������������������������������������������
														case 'A':
														case 'a':
															if (map4[i][j - 1] == 1)  //��ש,����
															{
																map4[i][j] -= 17;
																map4[i][j - 1] += 17;
															}
															else if (map4[i][j - 1] == 6)
															{
																int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(����С��) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i][j - 1] += 12;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
																	}
																}
															}
															else if (map4[i][j - 1] == 20)
															{
																int ID = MessageBox(hwnd, "����ս��Ԫ˧", "�Ƿ񹥻�", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(ս��Ԫ˧) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i][j - 1] -= 2;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
																	}
																}
															}
															break;
														case 77:        //�Ҽ�ͷ��ASCII��        �����ŵ�ͼ����������������������������������������������������������������������������
														case 'D':
														case 'd':
															if (map4[i][j + 1] == 1)  //��ש,����
															{
																map4[i][j] -= 17;
																map4[i][j + 1] += 17;
															}
															else if (map4[i][j + 1] == 6)
															{
																int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(����С��) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i][j + 1] += 12;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
																	}
																}
															}
															else if (map4[i][j + 1] == 20)
															{
																int ID = MessageBox(hwnd, "����ս��Ԫ˧", "�Ƿ񹥻�", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(ս��Ԫ˧) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i][j + 1] -= 2;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
																	}
																}
															}
															break;
														case 72:        //�ϼ�ͷ��ASCII��       �����ŵ�ͼ��������������������������������������������������������������������������
														case 'W':
														case 'w':
															if (map4[i - 1][j] == 1)  //��ש,����
															{
																map4[i][j] -= 17;
																map4[i - 1][j] += 17;
															}	
															else if (map4[i - 1][j] == 6)
															{
																int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(����С��) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i - 1][j] += 12;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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
																int ID = MessageBox(hwnd, "����ս��Ԫ˧", "�Ƿ񹥻�", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(ս��Ԫ˧) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i - 1][j] -= 2;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
																	}
																}
															}
															else if (map4[i - 1][j] == 3)
															{
																int ID = MessageBox(hwnd, "������Ȯ����˹��", "�Ƿ񹥻�", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(��Ȯ����˹��) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i - 1][j] += 15;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
																	}
																}
															}	
															else if (map4[i - 1][j] == 13)
															{
																MessageBoxA(hwnd, "�밬˹�ɹ�����", "�ٺٺ�", 0);
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
														case 80:        //�¼�ͷ��ASCII��         //�����ŵ�ͼ����������������������������������������������������������������������
														case 'S':
														case 's':
															if (map4[i + 1][j] == 1)  //��ש,����
															{
																map4[i][j] -= 17;
																map4[i + 1][j] += 17;
															}
															else if (map4[i + 1][j] == 6)
															{
																int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
																if (ID == IDYES)
																{
																	if (PK(����С��) == true)
																	{
																		map4[i][j] -= 17;
																		map4[i + 1][j] += 12;
																	}
																	else
																	{
																		MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
																	}
																}
															}
															break;
														}

													}
												}
												break;												
											case 80:        //�¼�ͷ��ASCII��       �����ŵ�ͼ������������������������������������������������������������������������  
											case 'S':
											case 's':
												if (map3[i + 1][j] == 1)  //��ש,����
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
														int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
														if (ID == IDYES)
														{
															if (PK(����С��) == true)
															{
																map3[i][j] -= 17;
																map3[i + 1][j] += 12;
															}
															else
															{
																MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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
								case 72:        //�ϼ�ͷ��ASCII��       �����ŵ�ͼ��������������������������������������������������������������������������
								case 'W':
								case 'w':
									if (map2[i - 1][j] == 1)  //��ש,����
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
										int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(����С��) == true)
											{
												map2[i][j] -= 17;
												map2[i - 1][j] += 12;
											}
											else
											{
												MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
											}
										}
									}
									else if (map2[i - 1][j] == 12)
									{
										int ID = MessageBox(hwnd, "������������", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(��������) == true)
											{
												map2[i][j] -= 17;
												map2[i - 1][j] += 6;
											}
											else
											{
												MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
											}
										}
									}
									else if (map2[i - 1][j] == 19)
									{
										int ID = MessageBox(hwnd, "����ս����", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(ս����) == true)
											{
												map2[i][j] -= 17;
												map2[i - 1][j] -= 1;
											}
											else
											{
												MessageBox(hwnd, "������", "�Ƿ񸴻�", MB_YESNO);
											}
										}
									}
									else if (map2[i - 1][j] == 8)
									{
										int ID = MessageBox(hwnd, "������ƽ������", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(��ƽ������) == true)
											{
												map2[i][j] -= 17;
												map2[i - 1][j] += 10;
											}
											else
											{
												MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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
								case 80:        //�¼�ͷ��ASCII��         //�����ŵ�ͼ����������������������������������������������������������������������
								case 'S':
								case 's':
									if (map2[i + 1][j] == 1)  //��ש,����
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
										int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(����С��) == true)
											{
												map2[i][j] -= 17;
												map2[i + 1][j] += 12;
											}
											else
											{
												MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
											}
										}
									}
									else if (map2[i + 1][j] == 19)
									{
										int ID = MessageBox(hwnd, "����ս����", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(ս����) == true)
											{
												map2[i][j] -= 17;
												map2[i + 1][j] -= 1;
											}
											else
											{
												MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
											}
										}
									}
									else if (map2[i + 1][j] == 8)
									{
										int ID = MessageBox(hwnd, "������ƽ������", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(��ƽ������) == true)
											{
												map2[i][j] -= 17;
												map2[i + 1][j] += 10;
											}
											else
											{
												MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
											}
										}
									}
									else if (map2[i + 1][j] == 11)
									{
										int ID = MessageBox(hwnd, "������Գ��³����ŵ", "�Ƿ񹥻�", MB_YESNO);
										if (ID == IDYES)
										{
											if (PK(��Գ��³����ŵ) == true)
											{
												map2[i][j] -= 17;
												map2[i + 1][j] += 7;
											}
											else
											{
												MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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

		case 77:        //�Ҽ�ͷ��ASCII��        ��һ�ŵ�ͼ����������������������������������������������������������������������������
		case 'D':
		case 'd':
			if (map[i][j + 1] == 1)  //��ש,����
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
				int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(����С��) == true)
					{
						map[i][j] -= 17;
						map[i][j + 1] += 12;
					}
					else
					{
						MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
					}
				}
			}
			else if (map[i][j + 1] == 8)
			{
				int ID = MessageBox(hwnd, "������ƽ������", "�Ƿ񹥻�", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(��ƽ������) == true)
					{
						map[i][j] -= 17;
						map[i][j + 1] += 10;
					}
					else
					{
						MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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
				int ID = MessageBox(hwnd, "����Ů�ۺ����", "�Ƿ����Կ��", MB_YESNO);
				if (ID == IDYES)
				{
					map[i][j] -= 17;
					map[i][j + 1] += 11;
					player.key2++;
				}
				else;
			}
			break;
		case 72:        //�ϼ�ͷ��ASCII��   ��һ�ŵ�ͼ��������������������������������������������������������������������������������
		case 'W':
		case 'w':
			if (map[i - 1][j] == 1)  //��ש,����
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
				int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(����С��) == true)
					{
						map[i][j] -= 17;
						map[i - 1][j] += 12;
					}
					else
					{
						MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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
		case 80:        //�¼�ͷ��ASCII��       ��һ�ŵ�ͼ������������������������������������������������������������������������  
		case 'S':
		case 's':
			if (map[i + 1][j] == 1)  //��ש,����
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
				int ID = MessageBox(hwnd, "��������С��", "�Ƿ񹥻�", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(����С��) == true)
					{
						map[i][j] -= 17;
						map[i + 1][j] += 12;
					}
					else
					{
						MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
					}
				}
			}
			else if (map[i + 1][j] == 9)
			{
				int ID = MessageBox(hwnd, "�����¹�Ī����", "�Ƿ񹥻�", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(�¹�Ī����) == true)
					{
						map[i][j] -= 17;
						map[i + 1][j] += 9;
					}
					else
					{
						MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
					}
				}
			}
			else if (map[i + 1][j] == 5)
			{
				int ID = MessageBox(hwnd, "��������˹Ħ��", "�Ƿ񹥻�", MB_YESNO);
				if (ID == IDYES)
				{
					if (PK(����˹Ħ��) == true)
					{
						map[i][j] -= 17;
						map[i + 1][j] += 13;
					}
					else
					{
						MessageBoxA(hwnd, "�����ˣ��ؿ�һ����Ϸ��", "�ٺٺ�", 0);
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
{    // SND_LOOPѭ�����ţ�Ҫ��SND_ASYNCһ���ã�SND_FILENAME��ʾpszSound����ָ�������ļ���	
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