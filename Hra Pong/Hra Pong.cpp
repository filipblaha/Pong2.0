#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

class Pong
{
public:
	bool program = 1;
	bool pokracovani = 1;
	bool ztrata_zivotu = 0;
	bool power_up = 0;
	bool slow = 0;

	char zed = char(219);
	char blok1 = char(176);
	char blok2 = char(177);
	char blok3 = char(178);
	char mic = 'O';

	int DELKA = 20;
	int VYSKA = 20;
	int velikost_plosina = 6;
	int x_plosina = (DELKA - velikost_plosina) / 2;

	int pohyb = 0;
	int ax_mic = 1;
	int ay_mic = -1;
	int x_mic = DELKA / 2;
	int y_mic = VYSKA - 5;
	int x_powerup = y_mic;
	int y_powerup = x_mic;

	int pocet_bloku = 0;
	int pocet_vykresleni = 0;
	int cas = 0;
	int rychlost_hry = 2;
	int padani = 0;
	int zivoty = 0;
	int pocet_rozbitych_bloku;
	int n_exp = 0;

	std::vector<std::vector<int>> bloky;
	std::vector<std::vector<int>> zasobnik;
	std::vector<int> docas;
	std::vector<int> exp_pole;

	void bloky_vytvoreni_klasik()
	{
		for (int j = 0; j < VYSKA; j++)
		{
			docas.clear();
			for (int i = 0; i < DELKA; i++)
			{
				if (i != 0 && i != DELKA - 1 && j != 0 && j < 7 && i % 3 == 0)
				{
					if (j < 4)
					{
						if (j < 2)
							docas.push_back(3);
						else
							docas.push_back(2);
					}
					else
						docas.push_back(1);
				}
				else
					docas.push_back(0);
			}
			bloky.push_back(docas);
		}
	}
	void bloky_vytvoreni_padajici()
	{
		/////////////////    hraci pole   ////////////////////
		for (int j = 0; j < VYSKA; j++)
		{
			docas.clear();
			for (int i = 0; i < DELKA; i++)
			{
				if (i != 0 && i != DELKA - 1 && j < 2)
					docas.push_back(1);
				else
					docas.push_back(0);
			}
			bloky.push_back(docas);
		}
		/////////////////    zasobnik   ////////////////////
		for (int j = 0; j < 50; j++)
		{
			docas.clear();
			for (int i = 0; i < DELKA; i++)
			{
				if (i != 0 && i != DELKA - 1 && j % 2 == 0)
					docas.push_back(1);
				else
					docas.push_back(0);
			}
			zasobnik.push_back(docas);
		}


	}
private:
};
class Menu
{
public:
	int delka_menu = 40;
	int vyska_menu = 20;
	int x_tecka = 0;
	int y_tecka = 0;
	int x_oznaceni = 0;
	int y_oznaceni = 0;
	int horni_zavora_hlavni = 0;
	int dolni_zavora_hlavni = 0;
	int prava_zavora_hlavni = 0;
	int leva_zavora_hlavni = 0;

	bool enter = 0;
	bool exit = 0;
	bool reset = 0;
	int jazyk = 0;
	int plosina_skin = 0;
	int highscore_cas = 0;
	int highscore_znicenych_bloku = 0;
	int level = 7;
	int exp = 0;
	int pocet_zivotu = 3;
	int potr_urov1 = 1;
	int potr_urov2 = 2;
	int potr_urov3 = 3;
	int potr_urov4 = 4;
	int potr_urov5 = 5;

	std::vector<char> pole_skin;

	/////////////////////    Skiny     //////////////////////////
	void skin()
	{
		Pong navod;
		pole_skin.resize(navod.velikost_plosina);

		if (plosina_skin == 0)
		{
			for (int i = 0; i < pole_skin.size(); i++)
			{
				pole_skin.at(i) = 'I';
			}
		}
		if (plosina_skin == 1)
		{
			for (int i = 0; i < pole_skin.size(); i++)
			{
				pole_skin.at(i) = '=';
			}
		}
		if (plosina_skin == 2)
		{
			pole_skin.at(0) = 'F';
			pole_skin.at(1) = 'E';
			pole_skin.at(2) = 'L';
			pole_skin.at(3) = 'Z';
			pole_skin.at(4) = 'C';
			pole_skin.at(5) = 'U';
		}
		if (plosina_skin == 3)
		{
			pole_skin.at(0) = '8';
			pole_skin.at(1) = '=';
			pole_skin.at(2) = '=';
			pole_skin.at(3) = '=';
			pole_skin.at(4) = '=';
			pole_skin.at(5) = 'D';
		}
		if (plosina_skin == 4)
		{
			for (int i = 0; i < pole_skin.size() / 2; i++)
			{
				pole_skin.at(i) = char(174);
			}
			for (int i = pole_skin.size() / 2; i < pole_skin.size(); i++)
			{
				pole_skin.at(i) = char(175);
			}
		}
		if (plosina_skin == 5)
		{
			for (int i = 0; i < pole_skin.size(); i++)
			{
				pole_skin.at(i);
			}
		}
	}

	/////////////////////    Preklad     //////////////////////////
	std::string herni_modyCZ = "Herni mody";
	std::string herni_modyEN = "Game modes";
	std::string vzhled_plosinyCZ = "Vzhled plosiny";
	std::string vzhled_plosinyEN = "Skins";
	std::string nastaveniCZ = "Nastaveni";
	std::string nastaveniEN = "Settings";
	std::string verzeCZ = "verze ";
	std::string verzeEN = "version ";
	std::string HERNI_MODYCZ = "HERNI MODY";
	std::string HERNI_MODYEN = "GAME MODES";
	std::string NASTAVENICZ = "NASTAVENI";
	std::string NASTAVENIEN = "SETTINGS";
	std::string VZHLED_PLOSINYCZ = "VZHLED PLOSINY";
	std::string VZHLED_PLOSINYEN = "SKINS";
	std::string neodemcenoCZ = "Odemkne se na urovni  ";
	std::string neodemcenoEN = "Unlocks after level ";
	std::string klasikCZ = "Klasik";
	std::string klasikEN = "Classic";
	std::string rogue_likeCZ = "Rogue like - zatim nefunkcni";
	std::string rogue_likeEN = "Rogue like - zatim nefunkcni";
	std::string stejne_tvaryCZ = "Stejne tvary - zatim nefunkcni";
	std::string stejne_tvaryEN = "Hit the same color - zatim nefunkcni";
	std::string bloky_padajiCZ = "Bloky padaji";
	std::string bloky_padajiEN = "Falling blocks";
	std::string jazykCZ = "Jazyk";
	std::string jazykEN = "Lanuguage";
	std::string ceskyCZ = "Cesky";
	std::string ceskyEN = "Czech";
	std::string anglickyCZ = "Anglicky";
	std::string anglickyEN = "English";
	std::string odchodP1CZ = "Zkus to znovu.";
	std::string odchodP1EN = "Try again.";
	std::string odchodV1CZ = "VYHRAL JSI!";
	std::string odchodV1EN = "YOU'VE WON!";
	std::string odchod2CZ = "Restart[MEZERNIK]";
	std::string odchod2EN = "Restart [SPACEBAR]";
	std::string odchod3CZ = "Menu[Q]";
	std::string odchod3EN = "Menu [Q]";
	std::string odchod4CZ = "NEJLEPSI CAS: ";
	std::string odchod4EN = "BEST TIME: ";
	std::string odchodV5CZ = "Dosazeny cas: ";
	std::string odchodV5EN = "Your time: ";
	std::string odchodP5CZ = "Bloku zbylo: ";
	std::string odchodP5EN = "Blocks left: ";
	std::string odchod6CZ = "Uroven ";
	std::string odchod6EN = "Level ";
	std::string odchod7CZ = "Bloku zniceno: ";
	std::string odchod7EN = "Blocks destroyed: ";
	std::string odchod8CZ = "NEJVICE ZNICENYCH BLOKU: ";
	std::string odchod8EN = "HIGHSCORE: ";
	int rozhodovac(int strana, int& plosina_skin_zmena, int& jazyk_zmena)
	{
		/////////////////////    Hlavni menu     //////////////////////////
		if (strana == 0)
		{
			if (y_tecka == 10)
				return 1;
			if (y_tecka == 12)
				return 2;
			if (y_tecka == 14)
				return 3;
		}

		/////////////////////    Herni mody     //////////////////////////
		if (strana == 1)
		{
			if (y_tecka == 8)
				return 1;
			/*if (navod_menu.y_tecka == 10)
			if (navod_menu.y_tecka == 12)*/
			if (y_tecka == 14)
				return 4;
		}

		/////////////////////    Skiny     //////////////////////////
		if (strana == 2)
		{
			if (y_oznaceni == 9 && x_oznaceni == 6)
				return plosina_skin_zmena = 0;
			if (y_oznaceni == 9 && x_oznaceni == 16)
				if (level >= potr_urov1)
					return plosina_skin_zmena = 1;
				else
					return -1;
			if (y_oznaceni == 9 && x_oznaceni == 26)
				if (level >= potr_urov2)
					return plosina_skin_zmena = 2;
				else
					return -2;
			if (y_oznaceni == 13 && x_oznaceni == 6)
				if (level >= potr_urov3)
					return plosina_skin_zmena = 3;
				else
					return -3;
			if (y_oznaceni == 13 && x_oznaceni == 16)
				if (level >= potr_urov4)
					return plosina_skin_zmena = 4;
				else
					return -4;
			if (y_oznaceni == 13 && x_oznaceni == 26)
			{
				if (level >= potr_urov5)
				{
					setCursorPosition(27, 14);
					std::cout << "      ";
					setCursorPosition(27, 14);
					Pong navod;
					pole_skin.resize(navod.velikost_plosina);
					for (int i = 0; i < pole_skin.size(); i++)
					{
						pole_skin.at(i) = _getche();
					}
					return plosina_skin_zmena = 5;
				}
				else
					return -5;
			}
		}

		/////////////////////    Nastaveni     //////////////////////////
		if (strana == 3)
		{
			if (y_tecka == 10)
				return jazyk_zmena = 0;
			if (y_tecka == 12)
				return jazyk_zmena = 1;
		}
	}
private:
};

/////////////////////    Commands     //////////////////////////

void font(int f1, int f2)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.dwFontSize.X = f1;
	cfi.dwFontSize.Y = f2;
	cfi.FontFamily = FF_DONTCARE;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void SetWindow(int delka, int vyska)
{
	_COORD coord;
	coord.X = delka;
	coord.Y = vyska;
	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = vyska + 1;
	Rect.Right = delka - 1;
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
}
void prechod()
{
	setCursorPosition(0, 0);
	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 40; i++)
		{
			std::cout << " ";
		}
		std::cout << "\n";
	}
}

int vstup_hra(Pong& navod)
{
	switch (_getch())
	{
	case 'd':
	{
		if (!(navod.x_plosina == navod.DELKA - navod.velikost_plosina - 1)) //zed vpravo
		{
			return navod.pohyb = 1;
		}
		break;
	}
	case 'a':
	{
		if (!(navod.x_plosina == 1)) // zed vlevo
		{
			return navod.pohyb = -1;
		}
		break;
	}
	case ' ':
	{
		if (navod.power_up)
		{
			navod.slow = 0;
		}
		break;
	}
	default:
		navod.pohyb = 0;
		break;
	}
}
Menu vstup_menu(Menu& navod_menu, Pong& navod, int strana)
{
	switch (_getch())
	{
	case 'w':
	{
		{
			if (navod_menu.y_tecka > navod_menu.horni_zavora_hlavni && (strana == 0 || 1))
			{
				navod_menu.y_tecka = navod_menu.y_tecka - 2;
				navod_menu.exit = 0;
				navod_menu.enter = 0;
			}
			if (navod_menu.y_oznaceni > navod_menu.horni_zavora_hlavni && strana == 2)
			{
				navod_menu.y_oznaceni = navod_menu.y_oznaceni - 4;
				navod_menu.exit = 0;
				navod_menu.enter = 0;
			}
			return navod_menu;
		}
		break;
	}
	case 's':
	{
		{
			if (navod_menu.y_tecka < navod_menu.dolni_zavora_hlavni && (strana == 0 || 1))
			{
				navod_menu.y_tecka = navod_menu.y_tecka + 2;
				navod_menu.exit = 0;
				navod_menu.enter = 0;
			}
			if (navod_menu.y_oznaceni < navod_menu.dolni_zavora_hlavni && strana == 2)
			{
				navod_menu.y_oznaceni = navod_menu.y_oznaceni + 4;
				navod_menu.exit = 0;
				navod_menu.enter = 0;
			}
			return navod_menu;
		}
		break;
	}
	case 'a':
	{
		{
			if (navod_menu.x_oznaceni > navod_menu.leva_zavora_hlavni)
			{
				navod_menu.x_oznaceni = navod_menu.x_oznaceni - 10;
				navod_menu.exit = 0;
				navod_menu.enter = 0;
			}
			return navod_menu;
		}
		break;
	}
	case 'd':
	{
		{
			if (navod_menu.x_oznaceni < navod_menu.prava_zavora_hlavni)
			{
				navod_menu.x_oznaceni = navod_menu.x_oznaceni + 10;
				navod_menu.exit = 0;
				navod_menu.enter = 0;
			}
			return navod_menu;
		}
		break;
	}
	case '\r':
	{
		{
			navod_menu.exit = 0;
			navod_menu.enter = 1;
			return navod_menu;
		}
		break;
	}
	case ' ':
	{
		{
			if (strana == -1)
			{
				navod.pokracovani = 0;
				navod_menu.exit = 1;
				return navod_menu;
			}
		}
		break;
	}
	case 'q':
	{
		{
			if (strana == 0)
			{
				navod_menu.exit = 1;
				navod.program = 0;
				return navod_menu;
			}
			else if (strana == -1)
			{
				navod_menu.reset = 1;
				navod.pokracovani = 0;
				navod_menu.exit = 1;
				navod_menu.enter = 0;
				return navod_menu;
			}
			else
			{
				navod_menu.exit = 1;
				navod_menu.enter = 0;
				return navod_menu;
			}
		}
		break;
	}
	default:
	{
		navod_menu.exit = 0;
		navod_menu.enter = 0;
		return navod_menu;
	}
	break;
	}
}

/////////////////////    Vyhra / prohra     //////////////////////////

void vykresleni_konec(Menu navod_menu)
{
	int m = 4;
	int n = 2;
	setCursorPosition(m, n);
	////////////    vykreslovani plocha    ////////////
	for (int j = 0; j < navod_menu.vyska_menu * 3 / 4 + 1; j++)
	{
		setCursorPosition(m, n + j);
		for (int i = 0; i < navod_menu.delka_menu * 3 / 4 + 2; i++)
		{
			if (j == 0 && i == 0)
			{
				std::cout << char(201);
			}
			else if (i == 0 && j == navod_menu.vyska_menu * 3 / 4)
			{
				std::cout << char(200);
			}
			else if (j == 0 && i == navod_menu.delka_menu * 3 / 4 + 1)
			{
				std::cout << char(187);
			}
			else if (j == navod_menu.vyska_menu * 3 / 4 && i == navod_menu.delka_menu * 3 / 4 + 1)
			{
				std::cout << char(188);
			}
			else if (j == 4 && i == navod_menu.delka_menu * 3 / 4 + 1)
			{
				std::cout << char(185);
			}
			else if (j == 4 && i == 0)
			{
				std::cout << char(204);
			}
			else if (j == 0 || j == 4 || j == navod_menu.vyska_menu * 3 / 4)
			{
				std::cout << char(205);
			}
			else if (i == 0 || i == navod_menu.delka_menu * 3 / 4 + 1)
			{
				std::cout << char(186);
			}
			else
			{
				std::cout << ' ';
			}
		}
		if (!(j == navod_menu.vyska_menu * 3 / 4 + 1))
			std::cout << '\n';
	}
}

void konec_logika(int mod, bool vyhra, Menu& navod_menu, Pong& navod)
{
	if (navod.zivoty <= 1 || vyhra == 1)
	{
		navod.pokracovani = 0;
		navod_menu.exit = 0;

		if (vyhra)
			navod.n_exp = 7;

		if (mod == 0)
			navod.n_exp = navod.n_exp + navod.cas / 5;

		//////////    Highscore    ////////
		if (vyhra)
		{
			if (mod == 0)
			{
				if (navod_menu.highscore_cas == 0)
					navod_menu.highscore_cas = navod.cas;
				if (navod.cas < navod_menu.highscore_cas)
				{
					navod_menu.highscore_cas = navod.cas;
					navod.n_exp = +4;
				}
			}
		}
		if (mod == 3)
		{
			if (navod.pocet_rozbitych_bloku > navod_menu.highscore_znicenych_bloku)
			{
				navod_menu.highscore_znicenych_bloku = navod.pocet_rozbitych_bloku;
				navod.n_exp = navod.n_exp + navod.pocet_rozbitych_bloku / 5;
			}
		}

		//////////    Level bar    ////////
		navod.exp_pole.clear();
		navod_menu.exp = navod_menu.exp + navod.n_exp;
		int docas_exp = 0;
		bool level_up = 0;
		if (navod_menu.exp >= 20)
		{
			navod_menu.exp = navod_menu.exp - 20;
			docas_exp = navod_menu.exp;
			navod_menu.level++;
			level_up = 1;
		}
		if (level_up)
		{
			for (int i = 0; i < docas_exp; i++)
			{
				navod.exp_pole.push_back(1);
			}
			for (int i = 0; i < 20 - docas_exp; i++)
			{
				navod.exp_pole.push_back(0);
			}
		}
		else
		{
			for (int i = 0; i < navod_menu.exp - navod.n_exp; i++)
			{
				navod.exp_pole.push_back(2);
			}
			for (int i = 0; i < navod.n_exp; i++)
			{
				navod.exp_pole.push_back(1);
			}
			for (int i = 0; i < 20 - navod_menu.exp; i++)
			{
				navod.exp_pole.push_back(0);
			}
		}
	}
}
void prohra(int mod, Menu& navod_menu, Pong& navod)
{
	if (mod == 0)
		konec_logika(0, 0, navod_menu, navod);
	if (mod == 3)
		konec_logika(3, 0, navod_menu, navod);
	if (navod.zivoty <= 1)
	{
		prechod();
		font(0, 20);
		SetWindow(navod_menu.delka_menu, navod_menu.vyska_menu - 2);

		vykresleni_konec(navod_menu);
		setCursorPosition(14, 4);
		if (!navod_menu.jazyk)
		{
			std::cout << navod_menu.odchodP1CZ;
			setCursorPosition(6, 16);
			std::cout << navod_menu.odchod2CZ;
			setCursorPosition(27, 16);
			std::cout << navod_menu.odchod3CZ;
			setCursorPosition(6, 8);
			if (mod == 0)
			{
				if (navod_menu.highscore_cas == 0)
				{
					navod_menu.highscore_cas = 45;
					std::cout << navod_menu.odchod4CZ << (char)navod_menu.highscore_cas;
				}
				else
					std::cout << navod_menu.odchod4CZ << navod_menu.highscore_cas;
			}
			if (mod == 3)
			{
				std::cout << navod_menu.odchod8CZ << navod_menu.highscore_znicenych_bloku;
			}
			setCursorPosition(8, 10);
			if (mod == 0)
			{
				std::cout << navod_menu.odchodP5CZ << navod.cas;
			}
			if (mod == 3)
			{
				std::cout << navod_menu.odchod7CZ << navod.pocet_rozbitych_bloku;
			}
			setCursorPosition(16, 12);
			std::cout << navod_menu.odchod6CZ << navod_menu.level;
			setCursorPosition(10, 14);
			for (int i = 0; i < navod.exp_pole.size(); i++)
			{
				if (navod.exp_pole.at(i) == 2)
					std::cout << char(219);
				if (navod.exp_pole.at(i) == 1)
					std::cout << char(178);
				if (navod.exp_pole.at(i) == 0)
					std::cout << char(176);
			}
		}
		if (navod_menu.jazyk)
		{
			std::cout << navod_menu.odchodP1EN;
			setCursorPosition(6, 16);
			std::cout << navod_menu.odchod2EN;
			setCursorPosition(27, 16);
			std::cout << navod_menu.odchod3EN;
			setCursorPosition(6, 8);
			if (mod == 0)
			{
				if (navod_menu.highscore_cas == 0)
				{
					navod_menu.highscore_cas = 45;
					std::cout << navod_menu.odchod4EN << (char)navod_menu.highscore_cas;
				}
				else
					std::cout << navod_menu.odchod4EN << navod_menu.highscore_cas;
			}
			if (mod == 3)
			{
				std::cout << navod_menu.odchod8CZ << navod_menu.highscore_znicenych_bloku;
			}
			setCursorPosition(8, 10);
			if (mod == 0)
			{
				std::cout << navod_menu.odchodP5EN << navod.cas;
			}
			if (mod == 3)
			{
				std::cout << navod_menu.odchod7CZ << navod.pocet_rozbitych_bloku;
			}
			setCursorPosition(16, 12);
			std::cout << navod_menu.odchod6EN << navod_menu.level;


			setCursorPosition(10, 14);
			for (int i = 0; i < navod.exp_pole.size(); i++)
			{
				if (navod.exp_pole.at(i) == 2)
					std::cout << char(219);
				if (navod.exp_pole.at(i) == 1)
					std::cout << char(178);
				if (navod.exp_pole.at(i) == 0)
					std::cout << char(176);
			}
		}
		while (navod_menu.exit == 0)
		{
			while (!_kbhit());
			navod_menu = vstup_menu(navod_menu, navod, -1);
			navod.zivoty = navod_menu.pocet_zivotu;
		}
	}
	else
	{
		navod.zivoty--;
		navod.ztrata_zivotu = 1;
	}
}
void vyhra(int mod, Menu& navod_menu, Pong& navod)
{
	if (mod == 0)
		konec_logika(0, 1, navod_menu, navod);
	if (mod == 3)
		konec_logika(3, 1, navod_menu, navod);
	prechod();
	font(0, 20);
	SetWindow(navod_menu.delka_menu, navod_menu.vyska_menu - 2);

	vykresleni_konec(navod_menu);
	setCursorPosition(14, 4);
	if (!navod_menu.jazyk)
	{
		std::cout << navod_menu.odchodV1CZ;
		setCursorPosition(6, 16);
		std::cout << navod_menu.odchod2CZ;
		setCursorPosition(27, 16);
		std::cout << navod_menu.odchod3CZ;
		setCursorPosition(6, 8);
		std::cout << navod_menu.odchod4CZ << navod_menu.highscore_cas;
		setCursorPosition(8, 10);
		std::cout << navod_menu.odchodV5CZ << navod.cas;
		setCursorPosition(16, 12);
		std::cout << navod_menu.odchod6CZ << navod_menu.level;


		setCursorPosition(10, 14);
		for (int i = 0; i < navod.exp_pole.size(); i++)
		{
			if (navod.exp_pole.at(i) == 2)
				std::cout << char(219);
			if (navod.exp_pole.at(i) == 1)
				std::cout << char(178);
			if (navod.exp_pole.at(i) == 0)
				std::cout << char(176);
		}
	}
	if (navod_menu.jazyk)
	{
		std::cout << navod_menu.odchodV1EN;
		setCursorPosition(6, 16);
		std::cout << navod_menu.odchod2EN;
		setCursorPosition(27, 16);
		std::cout << navod_menu.odchod3EN;
		setCursorPosition(6, 8);
		std::cout << navod_menu.odchod4EN << navod_menu.highscore_cas;;
		setCursorPosition(8, 10);
		std::cout << navod_menu.odchodV5EN << navod.cas;
		setCursorPosition(16, 12);
		std::cout << navod_menu.odchod6EN << navod_menu.level;


		setCursorPosition(10, 14);
		for (int i = 0; i < 4; i++)
			std::cout << char(219);
		for (int i = 0; i < 8; i++)
			std::cout << char(178);
		for (int i = 0; i < 8; i++)
			std::cout << char(176);
	}
	while (navod_menu.exit == 0)
	{
		while (!_kbhit());
		navod_menu = vstup_menu(navod_menu, navod, -1);
		navod.zivoty = navod_menu.pocet_zivotu;
	}
}

/////////////////////    Hra     //////////////////////////

Pong logika(int mod, Menu& navod_menu, Pong& navod)
{
	int U = navod.bloky.at(navod.y_mic - 1).at(navod.x_mic);
	int D = navod.bloky.at(navod.y_mic + 1).at(navod.x_mic);
	int L = navod.bloky.at(navod.y_mic).at(navod.x_mic - 1);
	int R = navod.bloky.at(navod.y_mic).at(navod.x_mic + 1);

	int DR = navod.bloky.at(navod.y_mic + 1).at(navod.x_mic + 1);
	int UL = navod.bloky.at(navod.y_mic - 1).at(navod.x_mic - 1);
	int UR = navod.bloky.at(navod.y_mic - 1).at(navod.x_mic + 1);
	int DL = navod.bloky.at(navod.y_mic + 1).at(navod.x_mic - 1);

	bool plosina = (navod.y_mic == navod.VYSKA - 4);
	bool stenaU = (navod.y_mic == 1);
	bool stenaL = (navod.x_mic == 1);
	bool stenaR = (navod.x_mic == navod.DELKA - 2);

	////////////    casomira    ////////////

	navod.pocet_vykresleni++;
	if (navod.pocet_vykresleni % 11 == 0)
		navod.cas++;
	if (navod.pocet_vykresleni % 20 == 0)
		navod.padani++;



	////////////   prohra / vyhra   ////////////

	if (mod == 0)
	{
		if (navod.pocet_bloku == 0)
		{
			vyhra(0, navod_menu, navod);
		}
	}
	if (navod.y_mic == navod.VYSKA - 2 && navod.pocet_vykresleni % navod.rychlost_hry == 0) // spodni
	{
		if (mod == 0)
			prohra(0, navod_menu, navod);
		if (mod == 3)
			prohra(3, navod_menu, navod);
	}

	////////////   bloky padaji   ////////////

	if (mod == 3)
	{
		if (mod == 3 && navod.pocet_vykresleni % 20 == 19)
		{
			navod.bloky.pop_back();

			navod.docas.clear();
			for (int i = 0; i < navod.DELKA - 2; i++)
			{
				navod.docas = navod.zasobnik.back();
			}
			navod.bloky.insert(navod.bloky.begin(), navod.docas);

			navod.zasobnik.pop_back();
		}
	}

	////////////    mic    ////////////

	if (!navod.ztrata_zivotu && navod.pokracovani)
	{
		if (navod.pocet_vykresleni % navod.rychlost_hry == 0)
		{
			if (plosina || stenaR || stenaL || stenaU || L > 0 || U > 0 || R > 0 || D > 0)
			{
				////  plosina  ////
				if (plosina)
				{
					if (navod.x_mic > navod.x_plosina - 1 && navod.x_mic <= (navod.x_plosina + navod.velikost_plosina / 2))
					{
						navod.ay_mic = -1; // vlevo
						navod.ax_mic = -1;
					}
					if (navod.x_mic >= (navod.x_plosina + navod.velikost_plosina / 2) && navod.x_mic < (navod.x_plosina + navod.velikost_plosina + 1))
					{
						navod.ay_mic = -1; // vpravo
						navod.ax_mic = 1;
					}
				}

				////  steny  ////

				if (stenaR) // prava stena
				{
					navod.ax_mic = -1;
				}
				if (stenaL) // leva stena
				{
					navod.ax_mic = 1;
				}
				if (stenaU) // horni stena
				{
					navod.ay_mic = 1;
				}

				////  bloky  ////

				if (L > 0) // levy
				{
					navod.bloky.at(navod.y_mic).at(navod.x_mic - 1)--;
					navod.ax_mic = 1;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
				if (R > 0) // pravy
				{
					navod.bloky.at(navod.y_mic).at(navod.x_mic + 1)--;
					navod.ax_mic = -1;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
				if (U > 0) // hroni
				{
					navod.bloky.at(navod.y_mic - 1).at(navod.x_mic)--;
					navod.ay_mic = 1;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
				if (D > 0) // spodni
				{
					navod.bloky.at(navod.y_mic + 1).at(navod.x_mic)--;
					navod.ay_mic = -1;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
			}
			else if ((plosina || stenaR || stenaL || stenaU || L > 0 || U > 0 || R > 0 || D > 0) && (UL > 0 || UR > 0 || DL > 0 || DR > 0))
			{
				if (DR > 0)
				{
					if (U > 0 || stenaU) // pravo/dolni - shora
					{
						if (U > 0)
							navod.bloky.at(navod.y_mic - 1).at(navod.x_mic)--;
						navod.ax_mic = -1;
						navod.ay_mic = 1;
					}
					if (L > 0 || stenaL) // pravo/dolni - zleva
					{
						if (L > 0)
							navod.bloky.at(navod.y_mic).at(navod.x_mic - 1)--;
						navod.ax_mic = 1;
						navod.ay_mic = -1;
					}
					navod.bloky.at(navod.y_mic + 1).at(navod.x_mic + 1)--;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
				if (UL > 0)
				{
					if (D > 0 || plosina) // levo/horni - zdola
					{
						if (D > 0)
							navod.bloky.at(navod.y_mic + 1).at(navod.x_mic)--;
						navod.ax_mic = 1;
						navod.ay_mic = -1;
					}
					if (R > 0 || stenaR) // levo/horni - zprava
					{
						if (R > 0)
							navod.bloky.at(navod.y_mic).at(navod.x_mic + 1)--;
						navod.ax_mic = -1;
						navod.ay_mic = 1;
					}
					navod.bloky.at(navod.y_mic - 1).at(navod.x_mic - 1)--;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
				if (DL > 0)
				{
					if (U > 0 || stenaU) // levo/dolni - shora
					{
						if (U > 0)
							navod.bloky.at(navod.y_mic - 1).at(navod.x_mic)--;
						navod.ax_mic = 1;
						navod.ay_mic = 1;
					}
					if (R > 0 || stenaR) // levo/dolni - zprava
					{
						if (R > 0)
							navod.bloky.at(navod.y_mic).at(navod.x_mic + 1)--;
						navod.ax_mic = -1;
						navod.ay_mic = -1;
					}
					navod.bloky.at(navod.y_mic + 1).at(navod.x_mic - 1)--;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
				if (UR > 0)
				{
					if (D > 0 || plosina) // pravo/dolni - zdola
					{
						if (D > 0)
							navod.bloky.at(navod.y_mic + 1).at(navod.x_mic)--;
						navod.ax_mic = -1;
						navod.ay_mic = -1;
					}
					if (L > 0 || stenaL) // pravo/dolni - zleva
					{
						if (L > 0)
							navod.bloky.at(navod.y_mic).at(navod.x_mic - 1)--;
						navod.ax_mic = 1;
						navod.ay_mic = 1;
					}
					navod.bloky.at(navod.y_mic - 1).at(navod.x_mic + 1)--;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
			}
			else if (!(plosina || stenaR || stenaL || stenaU || L > 0 || U > 0 || R > 0 || D > 0) && (UL > 0 || UR > 0 || DL > 0 || DR > 0))
			{
				if (DL > 0 && navod.ax_mic == -1 && navod.ay_mic == 1) // levo/spodni
				{
					navod.bloky.at(navod.y_mic + 1).at(navod.x_mic - 1)--;
					navod.ax_mic = 1;
					navod.ay_mic = -1;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
				if (DR > 0 && navod.ax_mic == 1 && navod.ay_mic == 1) // pravo/spodni
				{
					navod.bloky.at(navod.y_mic + 1).at(navod.x_mic + 1)--;
					navod.ax_mic = -1;
					navod.ay_mic = -1;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
				if (UL > 0 && navod.ax_mic == -1 && navod.ay_mic == -1) // levo/horni
				{
					navod.bloky.at(navod.y_mic - 1).at(navod.x_mic - 1)--;
					navod.ax_mic = 1;
					navod.ay_mic = 1;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
				if (UR > 0 && navod.ax_mic == 1 && navod.ay_mic == -1) // pravo/horni
				{
					navod.bloky.at(navod.y_mic - 1).at(navod.x_mic + 1)--;
					navod.ax_mic = -1;
					navod.ay_mic = 1;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
			}
			///////////   zrychleni    /////////////


			if (navod.ax_mic == 1)
			{
				navod.x_mic++;
			}
			if (navod.ax_mic == -1)
			{
				navod.x_mic--;
			}
			if (navod.ay_mic == 1)
			{
				navod.y_mic++;
			}
			if (navod.ay_mic == -1)
			{
				navod.y_mic--;
			}

			////////////    power-up    ////////////

			if (navod.pocet_vykresleni % 100 == 0)
			{
				while (navod.bloky.at(navod.y_powerup).at(navod.x_powerup) != 0)
				{
					navod.y_powerup--;
				}
				navod.x_powerup = navod.y_mic * 3 / 4 + navod.VYSKA * 1 / 8;
				navod.y_powerup = navod.x_mic * 3 / 4 + navod.DELKA * 1 / 8;
				navod.bloky.at(navod.y_powerup).at(navod.x_powerup) = -1;
			}
			if (L == -1) // levy
			{
				navod.bloky.at(navod.y_mic).at(navod.x_mic - 1)++;
				navod.power_up = 1;
			}
			if (R == -1) // pravy
			{
				navod.bloky.at(navod.y_mic).at(navod.x_mic + 1)++;
				navod.power_up = 1;
			}
			if (U == -1) // hroni
			{
				navod.bloky.at(navod.y_mic - 1).at(navod.x_mic)++;
				navod.power_up = 1;
			}
			if (D == -1) // spodni
			{
				navod.bloky.at(navod.y_mic + 1).at(navod.x_mic)++;
				navod.power_up = 1;
			}
		}

		////////////    plosina    ////////////

		if (!(navod.pohyb == 0))
		{
			if (navod.pohyb == 1)
			{
				navod.x_plosina++;
			}
			if (navod.pohyb == -1)
			{
				navod.x_plosina--;
			}
		}
	}
	else
	{
		navod.ax_mic = vstup_hra(navod);
		navod.ay_mic = -1;
		navod.y_mic = navod.VYSKA - 5;
		navod.x_mic = navod.DELKA / 2;
		navod.ztrata_zivotu = 0;
	}
	return navod;
}
Pong vykresleni_start(int mod, Menu& navod_menu, Pong& navod)
{
	////////////    vykreslovani plocha    ////////////
	setCursorPosition(0, 0);
	for (int j = 0; j < navod.VYSKA - 1; j++)
	{
		for (int i = 0; i < navod.DELKA; i++)
		{
			if (j == 0 || i == 0 || i == navod.DELKA - 1)
			{
				std::cout << navod.zed;
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}

	////////////    vykreslovani plosiny na zacatku    ////////////
	navod_menu.skin();
	for (int i = 0; i < navod.velikost_plosina; i++)
	{
		setCursorPosition(navod.x_plosina + i, navod.VYSKA - 3);
		std::cout << navod_menu.pole_skin[i];
	}

	////////////    vykreslovani mice na zacatku    ////////////
	setCursorPosition(navod.x_mic, navod.y_mic);
	std::cout << navod.mic;

	////////////    vykreslovani bloku na zacatku    ////////////
	for (int j = 0; j < navod.bloky.size(); j++)
	{
		for (int i = 0; i < navod.bloky.at(j).size(); i++)
		{
			if (navod.bloky.at(j).at(i) == 1)
			{
				setCursorPosition(i, j);
				std::cout << navod.blok1;
				navod.pocet_bloku++;
			}
			if (navod.bloky.at(j).at(i) == 2)
			{
				setCursorPosition(i, j);
				std::cout << navod.blok2;
				navod.pocet_bloku = navod.pocet_bloku + 2;
			}
			if (navod.bloky.at(j).at(i) == 3)
			{
				setCursorPosition(i, j);
				std::cout << navod.blok3;
				navod.pocet_bloku = navod.pocet_bloku + 3;
			}
		}
	}

	////////////    vykreslovani HUD    ////////////
	setCursorPosition(0, navod.VYSKA - 1);
	for (int i = 0; i < navod.DELKA; i++)
	{
		if (i == 0 || i == navod.DELKA - 1)
			std::cout << char(223);
		else
			std::cout << '-';
	}
	if (mod == 0)
	{
		setCursorPosition(2, navod.VYSKA);
		std::cout << navod.blok2 << navod.pocet_bloku;
	}

	setCursorPosition(navod.DELKA - 4, navod.VYSKA);
	std::cout << navod.cas;

	setCursorPosition(8, navod.VYSKA);
	for (int i = 0; i < navod.zivoty; i++)
		std::cout << char(3);

	return navod;
}
void smazani_hra(int mod, Menu& navod_menu, Pong& navod)
{
	int C = navod.bloky.at(navod.y_mic).at(navod.x_mic);

	int U = navod.bloky.at(navod.y_mic - 1).at(navod.x_mic);
	int D = navod.bloky.at(navod.y_mic + 1).at(navod.x_mic);
	int L = navod.bloky.at(navod.y_mic).at(navod.x_mic - 1);
	int R = navod.bloky.at(navod.y_mic).at(navod.x_mic + 1);

	int DR = navod.bloky.at(navod.y_mic + 1).at(navod.x_mic + 1);
	int UL = navod.bloky.at(navod.y_mic - 1).at(navod.x_mic - 1);
	int UR = navod.bloky.at(navod.y_mic - 1).at(navod.x_mic + 1);
	int DL = navod.bloky.at(navod.y_mic + 1).at(navod.x_mic - 1);

	int SCX = navod.x_mic;
	int SCY = navod.y_mic;

	int SU = navod.y_mic - 1;
	int SL = navod.x_mic - 1;
	int SR = navod.x_mic + 1;
	int SD = navod.y_mic + 1;

	bool plosina = (navod.y_mic == navod.VYSKA - 4);
	bool stenaU = (navod.y_mic == 1);
	bool stenaL = (navod.x_mic == 1);
	bool stenaR = (navod.x_mic == navod.DELKA - 2);

	////////////    mazani plosiny    ////////////
	if (!(navod.pohyb == 0))
	{
		setCursorPosition(navod.x_plosina, navod.VYSKA - 3);
		for (int i = 0; i < navod.velikost_plosina; i++)
		{
			std::cout << " ";
		}
	}

	////////////    padani bloku    ////////////
	if (mod == 3)
	{
		if (navod.pocet_vykresleni % 20 == 19)
		{
			for (int j = 0; j < navod.bloky.size(); j++)
			{
				for (int i = 0; i < navod.bloky.at(j).size(); i++)
				{
					if (navod.bloky.at(j).at(i))
					{
						setCursorPosition(i, j);
						std::cout << ' ';
					}
				}
			}
		}
	}

	////////////    mazani bloku    ////////////

	if (!navod.ztrata_zivotu && navod.pokracovani)
	{
		if (navod.pocet_vykresleni % navod.rychlost_hry == navod.rychlost_hry - 1)
		{
			if (L > 0 || U > 0 || R > 0 || D > 0)
			{
				////  bloky  ////

				if (L > 0) // levy
				{
					setCursorPosition(SL, SCY);
					if (L == 1)
						std::cout << " ";
					if (L == 2)
						std::cout << navod.blok1;
					if (L == 3)
						std::cout << navod.blok2;
				}
				if (R > 0) // pravy
				{
					setCursorPosition(SR, SCY);
					if (R == 1)
						std::cout << " ";
					if (R == 2)
						std::cout << navod.blok1;
					if (R == 3)
						std::cout << navod.blok2;
				}
				if (U > 0) // horni
				{
					setCursorPosition(SCX, SU);
					if (U == 1)
						std::cout << " ";
					if (U == 2)
						std::cout << navod.blok1;
					if (U == 3)
						std::cout << navod.blok2;
				}
				if (D > 0) // spodni
				{
					setCursorPosition(SCX, SD);
					if (D == 1)
						std::cout << " ";
					if (D == 2)
						std::cout << navod.blok1;
					if (D == 3)
						std::cout << navod.blok2;
				}
			}
			else if ((L > 0 || U > 0 || R > 0 || D > 0) && (UL > 0 || UR > 0 || DL > 0 || DR > 0))
			{
				if (DR > 0)
				{
					if (U > 0 || stenaU) // pravo/dolni - shora
					{
						if (U > 0)
						{
							setCursorPosition(SCX, SU);
							if (U == 1)
								std::cout << " ";
							if (U == 2)
								std::cout << navod.blok1;
							if (U == 3)
								std::cout << navod.blok2;
						}

					}
					if (L > 0 || stenaL) // pravo/dolni - zleva
					{
						if (L > 0)
						{
							setCursorPosition(SL, SCY);
							if (L == 1)
								std::cout << " ";
							if (L == 2)
								std::cout << navod.blok1;
							if (L == 3)
								std::cout << navod.blok2;
						}
					}
					setCursorPosition(SR, SD);
					if (DR == 1)
						std::cout << " ";
					if (DR == 2)
						std::cout << navod.blok1;
					if (DR == 3)
						std::cout << navod.blok2;
				}
				if (UL > 0)
				{
					if (D > 0 || plosina) // levo/horni - zdola
					{
						if (D > 0)
						{
							setCursorPosition(SCX, SD);
							if (D == 1)
								std::cout << " ";
							if (D == 2)
								std::cout << navod.blok1;
							if (D == 3)
								std::cout << navod.blok2;
						}
					}
					if (R > 0 || stenaR) // levo/horni - zprava
					{
						if (R > 0)
						{
							setCursorPosition(SR, SCY);
							if (R == 1)
								std::cout << " ";
							if (R == 2)
								std::cout << navod.blok1;
							if (R == 3)
								std::cout << navod.blok2;
						}
					}
					setCursorPosition(SL, SU);
					if (UL == 1)
						std::cout << " ";
					if (UL == 2)
						std::cout << navod.blok1;
					if (UL == 3)
						std::cout << navod.blok2;
				}
				if (DL > 0)
				{
					if (U > 0 || stenaU) // levo/dolni - shora
					{
						if (U > 0)
						{
							setCursorPosition(SCX, SU);
							if (U == 1)
								std::cout << " ";
							if (U == 2)
								std::cout << navod.blok1;
							if (U == 3)
								std::cout << navod.blok2;
						}
					}
					if (R > 0 || stenaR) // levo/dolni - zprava
					{
						if (R > 0)
						{
							setCursorPosition(SR, SCY);
							if (R == 1)
								std::cout << " ";
							if (R == 2)
								std::cout << navod.blok1;
							if (R == 3)
								std::cout << navod.blok2;
						}
					}
					setCursorPosition(SL, SD);
					if (DL == 1)
						std::cout << " ";
					if (DL == 2)
						std::cout << navod.blok1;
					if (DL == 3)
						std::cout << navod.blok2;
				}
				if (UR > 0)
				{
					if (D > 0 || plosina) // pravo/dolni - zdola
					{
						if (D > 0)
						{
							setCursorPosition(SCX, SD);
							if (D == 1)
								std::cout << " ";
							if (D == 2)
								std::cout << navod.blok1;
							if (D == 3)
								std::cout << navod.blok2;
						}
					}
					if (L > 0 || stenaL) // pravo/dolni - zleva
					{
						if (L > 0)
						{
							setCursorPosition(SL, SCY);
							if (L == 1)
								std::cout << " ";
							if (L == 2)
								std::cout << navod.blok1;
							if (L == 3)
								std::cout << navod.blok2;
						}
					}
					setCursorPosition(SR, SU);
					if (UR == 1)
						std::cout << " ";
					if (UR == 2)
						std::cout << navod.blok1;
					if (UR == 3)
						std::cout << navod.blok2;
				}
			}
			else if (!(plosina || stenaR || stenaL || stenaU || L > 0 || U > 0 || R > 0 || D > 0) && (UL > 0 || UR > 0 || DL > 0 || DR > 0))
			{
				if (DL > 0 && navod.ax_mic == -1 && navod.ay_mic == 1) // levo/spodni
				{
					setCursorPosition(SL, SD);
					if (DL == 1)
						std::cout << " ";
					if (DL == 2)
						std::cout << navod.blok1;
					if (DL == 3)
						std::cout << navod.blok2;
				}
				if (DR > 0 && navod.ax_mic == 1 && navod.ay_mic == 1) // pravo/spodni
				{
					setCursorPosition(SR, SD);
					if (DR == 1)
						std::cout << " ";
					if (DR == 2)
						std::cout << navod.blok1;
					if (DR == 3)
						std::cout << navod.blok2;
				}
				if (UL > 0 && navod.ax_mic == -1 && navod.ay_mic == -1) // levo/horni
				{
					setCursorPosition(SL, SU);
					if (UL == 1)
						std::cout << " ";
					if (UL == 2)
						std::cout << navod.blok1;
					if (UL == 3)
						std::cout << navod.blok2;
				}
				if (UR > 0 && navod.ax_mic == 1 && navod.ay_mic == -1) // pravo/horni
				{
					setCursorPosition(SR, SU);
					if (UR == 1)
						std::cout << " ";
					if (UR == 2)
						std::cout << navod.blok1;
					if (UR == 3)
						std::cout << navod.blok2;
				}

			}


			////////////    mazani mice    ////////////

			setCursorPosition(SCX, SCY);
			std::cout << " ";
		}
		////////////    mazani power-upu    ////////////
		if (navod.bloky[navod.y_mic + 1][navod.x_mic] == -1)
		{
			setCursorPosition(navod.x_mic + 1, navod.y_mic);
			std::cout << " ";
		}
		if (navod.bloky[navod.y_mic - 1][navod.x_mic] == -1)
		{
			setCursorPosition(navod.x_mic - 1, navod.y_mic);
			std::cout << " ";
		}
		if (navod.bloky[navod.y_mic][navod.x_mic + 1] == -1)
		{
			setCursorPosition(navod.x_mic, navod.y_mic + 1);
			std::cout << " ";
		}
		if (navod.bloky[navod.y_mic][navod.x_mic - 1] == -1)
		{
			setCursorPosition(navod.x_mic, navod.y_mic - 1);
			std::cout << " ";
		}

		if (navod.bloky[navod.y_mic + 1][navod.x_mic + 1] == -1)
		{
			setCursorPosition(navod.x_mic + 1, navod.y_mic + 1);
			std::cout << " ";
		}
		if (navod.bloky[navod.y_mic - 1][navod.x_mic + 1] == -1)
		{
			setCursorPosition(navod.x_mic - 1, navod.y_mic + 1);
			std::cout << " ";
		}
		if (navod.bloky[navod.y_mic + 1][navod.x_mic - 1] == -1)
		{
			setCursorPosition(navod.x_mic + 1, navod.y_mic - 1);
			std::cout << " ";
		}
		if (navod.bloky[navod.y_mic - 1][navod.x_mic - 1] == -1)
		{
			setCursorPosition(navod.x_mic - 1, navod.y_mic - 1);
			std::cout << " ";
		}

		////////////    zmena zivotu    ////////////
		if (navod.ztrata_zivotu == 1)
		{
			setCursorPosition(8, navod.VYSKA);
			for (int i = 0; i < navod.zivoty + 1; i++)
			{
				if (i < navod.zivoty)
					std::cout << char(3);
				else
					std::cout << ' ';
			}
		}
	}
}
void vykresleni_hra(int mod, Menu& navod_menu, Pong& navod)
{
	if (navod.pokracovani)
	{
		////////////    vykreslovani plosiny    ////////////
		if (!(navod.pohyb == 0))
		{
			navod_menu.skin();
			for (int i = 0; i < navod.velikost_plosina; i++)
			{
				setCursorPosition(navod.x_plosina + i, navod.VYSKA - 3);
				std::cout << navod_menu.pole_skin[i];
			}
			navod.pohyb = 0;
		}
		if (navod.pocet_vykresleni % navod.rychlost_hry == 0)
		{
			////////////    vykreslovani mice    ////////////
			setCursorPosition(navod.x_mic, navod.y_mic);
			std::cout << navod.mic;

			////////////    vykreslovani bloku    ////////////
			if (mod == 3 && navod.pocet_vykresleni % 20 == 0)
			{
				for (int j = 0; j < navod.bloky.size(); j++)
				{
					for (int i = 0; i < navod.bloky.at(j).size(); i++)
					{
						if (navod.bloky.at(j).at(i) == 1)
						{
							setCursorPosition(i, j);
							std::cout << navod.blok1;
							navod.pocet_bloku++;
						}
						if (navod.bloky.at(j).at(i) == 2)
						{
							setCursorPosition(i, j);
							std::cout << navod.blok2;
							navod.pocet_bloku = navod.pocet_bloku + 2;
						}
						if (navod.bloky.at(j).at(i) == 3)
						{
							setCursorPosition(i, j);
							std::cout << navod.blok3;
							navod.pocet_bloku = navod.pocet_bloku + 3;
						}
					}
				}

			}

			////////////    vykreslovani power-upu   ////////////
			if (navod.pocet_vykresleni % 100 == 0)
			{
				for (int j = 0; j < navod.bloky.size(); j++)
				{
					for (int i = 0; i < navod.bloky.at(j).size(); i++)
					{
						if (navod.bloky.at(j).at(i) == -1)
						{
							setCursorPosition(navod.x_powerup, navod.y_powerup);
							std::cout << '$';
						}
					}
				}
			}
			////////////    vykreslovani poctu bloku    ////////////
			if (mod == 0)
			{
				setCursorPosition(3, navod.VYSKA);
				std::cout << "    ";
				setCursorPosition(3, navod.VYSKA);
				std::cout << navod.pocet_bloku;
			}
		}
		//////////    vykreslovani casomiry  ////////////
		setCursorPosition(navod.DELKA - 4, navod.VYSKA);
		std::cout << "   ";
		setCursorPosition(navod.DELKA - 4, navod.VYSKA);
		std::cout << navod.cas;

		//////////    vykreslovani power-up  ////////////
		if (navod.power_up)
		{
			setCursorPosition(12, navod.VYSKA);
			std::cout << '$';
			navod.slow = 1;
			navod.power_up = 0;
		}
	}
}


void klasik(Menu& navod_menu)
{
	navod_menu.reset = 0;
	while (navod_menu.reset == 0)
	{
		Pong navod;
		navod.zivoty = navod_menu.pocet_zivotu;
		prechod();
		font(20, 20);
		SetWindow(navod.DELKA, navod.VYSKA);

		navod.bloky_vytvoreni_klasik();
		navod = vykresleni_start(0, navod_menu, navod);
		while (!_kbhit());
		navod.ax_mic = vstup_hra(navod);

		while (navod.pokracovani)
		{
			smazani_hra(0, navod_menu, navod);
			navod = logika(0, navod_menu, navod);
			vykresleni_hra(0, navod_menu, navod);

			for (int i = 0; i < 3; i++)
			{
				Sleep(14);
				if (navod.pohyb == 0)
					if (_kbhit())
						vstup_hra(navod);
			}
		}
	}
}
void stejna_barva(Menu& navod_menu)
{
	navod_menu.reset = 0;
	while (navod_menu.reset == 0)
	{
		Pong navod;
		navod.zivoty = navod_menu.pocet_zivotu;
		prechod();
		font(20, 20);
		SetWindow(navod.DELKA, navod.VYSKA);

		navod.bloky_vytvoreni_klasik();
		navod = vykresleni_start(2, navod_menu, navod);
		while (!_kbhit());
		navod.ax_mic = vstup_hra(navod);

		while (navod.pokracovani)
		{
			smazani_hra(2, navod_menu, navod);
			navod = logika(2, navod_menu, navod);
			vykresleni_hra(2, navod_menu, navod);

			for (int i = 0; i < 3; i++)
			{
				Sleep(25);
				if (navod.pohyb == 0)
					if (_kbhit())
						vstup_hra(navod);
			}
		}
	}
}
void bloky_padaji(Menu& navod_menu)
{
	navod_menu.reset = 0;
	while (navod_menu.reset == 0)
	{
		Pong navod;
		navod.zivoty = navod_menu.pocet_zivotu;
		prechod();
		SetWindow(navod.DELKA, navod.VYSKA);
		font(20, 20);
		navod.bloky_vytvoreni_padajici();
		navod = vykresleni_start(3, navod_menu, navod);

		while (navod.pokracovani)
		{
			smazani_hra(3, navod_menu, navod);
			navod = logika(3, navod_menu, navod);
			vykresleni_hra(3, navod_menu, navod);

			for (int i = 0; i < 3; i++)
			{
				Sleep(25);
				if (navod.pohyb == 0)
					if (_kbhit())
						vstup_hra(navod);
			}
		}
	}
}

/////////////////////    Menu vykresleni   //////////////////////////

void vykresleni_logo(Menu navod_menu)
{
	int m = 10;
	int n = 2;
	setCursorPosition(m, n);
	for (int j = 0; j < navod_menu.vyska_menu; j++)
	{
		for (int i = 0; i < navod_menu.delka_menu; i++)
		{
			if (j == 2)
			{
				if (i == 0 || i == 3 || i == 5 || i == 8 || i == 10 || i == 13 || i == 15 || i == 18)
					std::cout << char(219);
				else if (i == 1 || i == 2 || i == 6 || i == 7 || i == 16 || i == 17)
					std::cout << char(223);
				else
				{
					if (i < 19)
						std::cout << ' ';
				}
			}
		}
	}
	setCursorPosition(m, n + 1);
	for (int j = 0; j < navod_menu.vyska_menu; j++)
	{
		for (int i = 0; i < navod_menu.delka_menu; i++)
		{
			if (j == 2)
			{
				if (i == 0 || i == 3 || i == 5 || i == 8 || i == 10 || i == 11 || i == 13 || i == 15)
					std::cout << char(219);
				else
				{
					if (i < 19)
						std::cout << ' ';
				}
			}
		}
	}
	setCursorPosition(m, n + 2);
	for (int j = 0; j < navod_menu.vyska_menu; j++)
	{
		for (int i = 0; i < navod_menu.delka_menu; i++)
		{
			if (j == 2)
			{
				if (i == 0 || i == 5 || i == 8 || i == 10 || i == 12 || i == 13 || i == 15 || i == 18)
					std::cout << char(219);
				else if (i > 0 && i < 4 || i == 17)
					std::cout << char(223);
				else
				{
					if (i < 19)
						std::cout << ' ';
				}
			}
		}
	}
	setCursorPosition(m, n + 3);
	for (int j = 0; j < navod_menu.vyska_menu; j++)
	{
		for (int i = 0; i < navod_menu.delka_menu; i++)
		{
			if (j == 2)
			{
				if (i == 0 || i == 5 || i == 8 || i == 10 || i == 13 || i == 15 || i == 18)
					std::cout << char(219);
				else if (i == 6 || i == 7 || i == 16 || i == 17)
					std::cout << char(220);
				else
				{
					if (i < 19)
						std::cout << ' ';
				}
			}
		}
	}
}
Menu vykresleni_text_hlavni(Menu navod_menu)
{
	setCursorPosition(6, 10);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.herni_modyCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.herni_modyEN;
	setCursorPosition(6, 12);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.vzhled_plosinyCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.vzhled_plosinyEN;
	setCursorPosition(6, 14);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.nastaveniCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.nastaveniEN;
	setCursorPosition(2, 18);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.verzeCZ << 2.9;
	if (navod_menu.jazyk)
		std::cout << navod_menu.verzeEN << 2.9;

	navod_menu.x_tecka = 4;
	navod_menu.y_tecka = 10;
	navod_menu.horni_zavora_hlavni = 10;
	navod_menu.dolni_zavora_hlavni = 14;
	return navod_menu;
}
Menu vykresleni_text_herni_mody(Menu navod_menu)
{
	setCursorPosition(14, 3);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.HERNI_MODYCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.HERNI_MODYEN;
	setCursorPosition(6, 8);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.klasikCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.klasikEN;
	setCursorPosition(6, 10);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.rogue_likeCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.rogue_likeEN;
	setCursorPosition(6, 12);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.stejne_tvaryCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.stejne_tvaryEN;
	setCursorPosition(6, 14);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.bloky_padajiCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.bloky_padajiEN;

	navod_menu.x_tecka = 4;
	navod_menu.y_tecka = 8;
	navod_menu.horni_zavora_hlavni = 8;
	navod_menu.dolni_zavora_hlavni = 14;
	return navod_menu;
}
Menu vykresleni_text_nastaveni(Menu navod_menu)
{
	setCursorPosition(15, 3);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.NASTAVENICZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.NASTAVENIEN;
	setCursorPosition(6, 8);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.jazykCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.jazykEN;
	setCursorPosition(9, 10);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.ceskyCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.ceskyEN;
	setCursorPosition(9, 12);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.anglickyCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.anglickyEN;

	navod_menu.x_tecka = 7;
	navod_menu.y_tecka = 10;
	navod_menu.horni_zavora_hlavni = 10;
	navod_menu.dolni_zavora_hlavni = 12;
	return navod_menu;
}
Menu vykresleni_vzhled_plosiny(Menu navod_menu)
{
	if (!navod_menu.jazyk)
	{
		setCursorPosition(13, 3);
		std::cout << navod_menu.VZHLED_PLOSINYCZ;
	}
	if (navod_menu.jazyk)
	{
		setCursorPosition(18, 3);
		std::cout << navod_menu.VZHLED_PLOSINYEN;
	}

	setCursorPosition(7, 10);
	std::cout << "IIIIII";

	if (navod_menu.level >= navod_menu.potr_urov1)
	{
		setCursorPosition(17, 10);
		std::cout << "======";
	}
	else
	{
		setCursorPosition(17, 10);
		std::cout << "??????";
	}
	if (navod_menu.level >= navod_menu.potr_urov2)
	{
		setCursorPosition(27, 10);
		std::cout << "FELZCU";
	}
	else
	{
		setCursorPosition(27, 10);
		std::cout << "??????";
	}
	if (navod_menu.level >= navod_menu.potr_urov3)
	{
		setCursorPosition(7, 14);
		std::cout << "8====D";
	}
	else
	{
		setCursorPosition(7, 14);
		std::cout << "??????";
	}
	if (navod_menu.level >= navod_menu.potr_urov4)
	{
		setCursorPosition(17, 14);
		std::cout << char(174) << char(174) << char(174) << char(175) << char(175) << char(175);
	}
	else
	{
		setCursorPosition(17, 14);
		std::cout << "??????";
	}
	if (navod_menu.level >= navod_menu.potr_urov5)
	{
		setCursorPosition(27, 14);
		std::cout << "______";
	}
	else
	{
		setCursorPosition(27, 14);
		std::cout << "??????";
	}
	navod_menu.x_oznaceni = 6;
	navod_menu.y_oznaceni = 9;
	navod_menu.horni_zavora_hlavni = 9;
	navod_menu.dolni_zavora_hlavni = 12;
	navod_menu.prava_zavora_hlavni = 26;
	navod_menu.leva_zavora_hlavni = 6;
	return navod_menu;
}

void vykresleni_tecka(Menu navod_menu)
{
	setCursorPosition(navod_menu.x_tecka, navod_menu.y_tecka);
	std::cout << char(254);
}
void smazani_tecka(Menu navod_menu)
{
	setCursorPosition(navod_menu.x_tecka, navod_menu.y_tecka);
	std::cout << ' ';
}
void vykresleni_oznaceni(Menu navod_menu)
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (j == 0 && i == 0)
			{
				setCursorPosition(navod_menu.x_oznaceni, navod_menu.y_oznaceni);
				std::cout << char(201);
			}
			if (j == 0 && i == 7)
			{
				setCursorPosition(navod_menu.x_oznaceni + 7, navod_menu.y_oznaceni);
				std::cout << char(187);
			}
			if (j == 2 && i == 0)
			{
				setCursorPosition(navod_menu.x_oznaceni, navod_menu.y_oznaceni + 2);
				std::cout << char(200);
			}
			if (j == 2 && i == 7)
			{
				setCursorPosition(navod_menu.x_oznaceni + 7, navod_menu.y_oznaceni + 2);
				std::cout << char(188);
			}
		}
	}
}
void smazani_oznaceni(Menu navod_menu)
{

	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (i == 0 && j == 0)
			{
				setCursorPosition(navod_menu.x_oznaceni, navod_menu.y_oznaceni);
				std::cout << ' ';
			}
			if (i == 7 && j == 0)
			{
				setCursorPosition(navod_menu.x_oznaceni + 7, navod_menu.y_oznaceni);
				std::cout << ' ';
			}
			if (i == 0 && j == 2)
			{
				setCursorPosition(navod_menu.x_oznaceni, navod_menu.y_oznaceni + 2);
				std::cout << ' ';
			}
			if (i == 7 && j == 2)
			{
				setCursorPosition(navod_menu.x_oznaceni + 7, navod_menu.y_oznaceni + 2);
				std::cout << ' ';
			}
		}
	}
}

void vykresleni_menu_start(Menu navod_menu, Pong navod)
{
	setCursorPosition(0, 0);
	////////////    vykreslovani plocha    ////////////
	for (int j = 0; j < navod_menu.vyska_menu; j++)
	{
		for (int i = 0; i < navod_menu.delka_menu; i++)
		{
			if (j == 0 && i == 0)
			{
				std::cout << char(201);
			}
			else if (i == 0 && j == navod_menu.vyska_menu - 1)
			{
				std::cout << char(200);
			}
			else if (j == 0 && i == navod_menu.delka_menu - 1)
			{
				std::cout << char(187);
			}
			else if (j == navod_menu.vyska_menu - 1 && i == navod_menu.delka_menu - 1)
			{
				std::cout << char(188);
			}
			else if (j == 0 || j == navod_menu.vyska_menu - 1)
			{
				std::cout << char(205);
			}
			else if (i == 0 || i == navod_menu.delka_menu - 1)
			{
				std::cout << char(186);
			}
			else
			{
				std::cout << ' ';
			}
		}
		if (!(j == navod_menu.vyska_menu - 1))
			std::cout << '\n';
	}

	////////////    vykreslovani uroven    ////////////
	if (!navod_menu.jazyk)
	{
		setCursorPosition(27, 17);
		std::cout << navod_menu.odchod6CZ << navod_menu.level;
	}
	else
	{
		setCursorPosition(27, 17);
		std::cout << navod_menu.odchod6EN << navod_menu.level;
	}

	navod.zivoty = 0;
	konec_logika(0, 0, navod_menu, navod);
	setCursorPosition(17, 18);
	for (int i = 0; i < navod.exp_pole.size(); i++)
	{
		if (navod.exp_pole.at(i) == 2)
			std::cout << char(219);
		if (navod.exp_pole.at(i) == 1)
			std::cout << char(178);
		if (navod.exp_pole.at(i) == 0)
			std::cout << char(176);
	}
}
void smazani_menu()
{
	setCursorPosition(0, 0);
	for (int i = 0; i < 40; i++)
	{
		std::cout << " ";
	}
}

/////////////////////    Menu logika    //////////////////////////

void menu_herni_mody(Menu& navod_menu, Pong& navod)
{
	prechod();
	vykresleni_menu_start(navod_menu, navod);
	navod_menu = vykresleni_text_herni_mody(navod_menu);
	navod_menu.exit = 0;
	navod_menu.enter = 0;

	while (!navod_menu.exit)
	{
		vykresleni_tecka(navod_menu);
		while (!_kbhit());
		smazani_tecka(navod_menu);
		vstup_menu(navod_menu, navod, 1);
		if (navod_menu.enter == 1)
		{
			if (navod_menu.rozhodovac(1, navod_menu.plosina_skin, navod_menu.jazyk) == 1)
				klasik(navod_menu);
			if (navod_menu.rozhodovac(1, navod_menu.plosina_skin, navod_menu.jazyk) == 4)
				bloky_padaji(navod_menu);
			navod_menu.exit = 1;
		}
	}
}
void menu_vzhled_plosiny(Menu& navod_menu, Pong& navod)
{
	prechod();
	vykresleni_menu_start(navod_menu, navod);
	navod_menu = vykresleni_vzhled_plosiny(navod_menu);
	navod_menu.exit = 0;
	navod_menu.enter = 0;

	while (!navod_menu.exit)
	{
		vykresleni_oznaceni(navod_menu);
		while (!_kbhit());
		smazani_oznaceni(navod_menu);
		vstup_menu(navod_menu, navod, 2);
		if (navod_menu.enter == 1)
		{
			if (navod_menu.rozhodovac(2, navod_menu.plosina_skin, navod_menu.jazyk) == -1)
			{
				if (!navod_menu.jazyk)
				{
					setCursorPosition(8, 7);
					std::cout << navod_menu.neodemcenoCZ << navod_menu.potr_urov1;
				}
				else
				{
					setCursorPosition(9, 7);
					std::cout << navod_menu.neodemcenoEN << navod_menu.potr_urov1;
				}
			}
			else if (navod_menu.rozhodovac(2, navod_menu.plosina_skin, navod_menu.jazyk) == -2)
			{

				if (!navod_menu.jazyk)
				{
					setCursorPosition(8, 7);
					std::cout << navod_menu.neodemcenoCZ << navod_menu.potr_urov2;
				}
				else
				{
					setCursorPosition(9, 7);
					std::cout << navod_menu.neodemcenoEN << navod_menu.potr_urov2;
				}
			}
			else if (navod_menu.rozhodovac(2, navod_menu.plosina_skin, navod_menu.jazyk) == -3)
			{

				if (!navod_menu.jazyk)
				{
					setCursorPosition(8, 7);
					std::cout << navod_menu.neodemcenoCZ << navod_menu.potr_urov3;
				}
				else
				{
					setCursorPosition(9, 7);
					std::cout << navod_menu.neodemcenoEN << navod_menu.potr_urov3;
				}
			}
			else if (navod_menu.rozhodovac(2, navod_menu.plosina_skin, navod_menu.jazyk) == -4)
			{

				if (!navod_menu.jazyk)
				{
					setCursorPosition(8, 7);
					std::cout << navod_menu.neodemcenoCZ << navod_menu.potr_urov4;
				}
				else
				{
					setCursorPosition(9, 7);
					std::cout << navod_menu.neodemcenoEN << navod_menu.potr_urov4;
				}
			}
			else if (navod_menu.rozhodovac(2, navod_menu.plosina_skin, navod_menu.jazyk) == -5)
			{

				if (!navod_menu.jazyk)
				{
					setCursorPosition(8, 7);
					std::cout << navod_menu.neodemcenoCZ << navod_menu.potr_urov5;
				}
				else
				{
					setCursorPosition(9, 7);
					std::cout << navod_menu.neodemcenoEN << navod_menu.potr_urov5;
				}
			}
			navod_menu.exit = 1;
		}
	}
}
void menu_nastaveni(Menu& navod_menu, Pong& navod)
{
	prechod();
	vykresleni_menu_start(navod_menu, navod);
	navod_menu = vykresleni_text_nastaveni(navod_menu);
	navod_menu.exit = 0;
	navod_menu.enter = 0;

	while (!navod_menu.exit)
	{
		vykresleni_tecka(navod_menu);
		while (!_kbhit());
		smazani_tecka(navod_menu);
		vstup_menu(navod_menu, navod, 3);
		if (navod_menu.enter == 1)
		{
			navod_menu.rozhodovac(3, navod_menu.plosina_skin, navod_menu.jazyk);
			navod_menu.exit = 1;
		}
	}
}
void menu_hlavni(Menu& navod_menu, Pong& navod)
{
	prechod();
	font(0, 20);
	SetWindow(navod_menu.delka_menu, navod_menu.vyska_menu - 2);

	vykresleni_menu_start(navod_menu, navod);
	vykresleni_logo(navod_menu);
	navod_menu = vykresleni_text_hlavni(navod_menu);
	navod_menu.exit = 0;
	navod_menu.enter = 0;

	while (!navod_menu.exit)
	{
		vykresleni_tecka(navod_menu);
		while (!_kbhit());
		smazani_tecka(navod_menu);
		vstup_menu(navod_menu, navod, 0);
		if (navod_menu.enter == 1)
		{
			if (navod_menu.rozhodovac(0, navod_menu.plosina_skin, navod_menu.jazyk) == 1)
				menu_herni_mody(navod_menu, navod);
			else if (navod_menu.rozhodovac(0, navod_menu.plosina_skin, navod_menu.jazyk) == 2)
				menu_vzhled_plosiny(navod_menu, navod);
			else if (navod_menu.rozhodovac(0, navod_menu.plosina_skin, navod_menu.jazyk) == 3)
				menu_nastaveni(navod_menu, navod);
			navod_menu.exit = 1;
		}
	}
}

int main()
{
	Menu navod_menu;
	Pong navod;
	while (navod.program)
	{
		//stejna_barva(navod_menu);
		//bloky_padaji(navod_menu);
		//menu_vzhled_plosiny(navod_menu, navod);
		klasik(navod_menu);
		menu_hlavni(navod_menu, navod);
	}
}