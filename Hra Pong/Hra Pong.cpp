#include <iostream>
#include <vector>
#include <conio.h>

#ifndef WIN32_LEAN_AND_MEAN // xml a windows.h nejdou do sebe, tohle to vyresi
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <Winuser.h> // lepsi ovladani

#include "Menu.h"
#include "Pong.h"

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
void prechod(Menu navod_menu)
{
	navod_menu.setCursorPosition(0, 0);
	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 40; i++)
		{
			std::cout << " ";
		}
		std::cout << "\n";
	}
}
void smazani_HUD_power_up(Pong navod)
{
	Menu navod_menu;
	navod_menu.setCursorPosition(12, navod.VYSKA);
	std::cout << ' ';
}
std::vector<char> string_na_vektor(Menu& navod_menu, std::string nazev)
{
	if (navod_menu.profil_probiha == 0)
	{
		navod_menu.nazev_profil0.clear();
		for (int i = 0; i < nazev.size(); i++)
		{
			navod_menu.nazev_profil0.push_back(nazev.at(i));
		}
		return navod_menu.nazev_profil0;
	}
	if (navod_menu.profil_probiha == 1)
	{
		navod_menu.nazev_profil1.clear();
		for (int i = 0; i < nazev.size(); i++)
		{
			navod_menu.nazev_profil1.push_back(nazev.at(i));
		}
		return navod_menu.nazev_profil1;
	}
	if (navod_menu.profil_probiha == 2)
	{
		navod_menu.nazev_profil2.clear();
		for (int i = 0; i < nazev.size(); i++)
		{
			navod_menu.nazev_profil2.push_back(nazev.at(i));
		}
		return navod_menu.nazev_profil2;
	}
}
void vektor_na_string(Menu& navod_menu, std::vector<char> p0, std::vector<char> p1, std::vector<char> p2)
{
	navod_menu.muj_profil0.clear();
	for (int i = 0; i < p0.size(); i++)
	{
		navod_menu.muj_profil0.push_back(p0.at(i));
	}
	navod_menu.muj_profil0;
	navod_menu.muj_profil1.clear();
	for (int i = 0; i < p1.size(); i++)
	{
		navod_menu.muj_profil1.push_back(p1.at(i));
	}
	navod_menu.muj_profil1;
	navod_menu.muj_profil2.clear();
	for (int i = 0; i < p2.size(); i++)
	{
		navod_menu.muj_profil2.push_back(p2.at(i));
	}
	navod_menu.muj_profil2;
}

/////////////////////    Vstupy     //////////////////////////

int vstup_hra(Pong& navod)
{
	if (GetAsyncKeyState(0x44)) 
	//if (_getch() == 'd') // pro testovani
	{
		if (!(navod.x_plosina == navod.DELKA - navod.velikost_plosina - 1)) //zed vpravo
		{
			return navod.pohyb = 1;
		}
	}
	else if (GetAsyncKeyState(0x41)) 
	//else if (_getch() == 'a')
	{
		if (!(navod.x_plosina == 1)) // zed vlevo
		{
			return navod.pohyb = -1;
		}
	}
	else if (GetAsyncKeyState(0x20))
	{
		if (navod.slow)
		{
			navod.slow = 0;
			smazani_HUD_power_up(navod);
			navod.trvani = 1;
			
		}
	}
}
void vstup_menu(Menu& navod_menu, Pong& navod, int strana)
{
	switch (_getch())
	{
	case 'w':
	{
		{
			if ((navod_menu.y_tecka > navod_menu.horni_zavora_hlavni) && (strana == -1))
			{
				if (navod_menu.y_tecka <= 12)
				{
					navod_menu.y_tecka -= 2;
				}
				else
				{
					navod_menu.y_tecka -= 5;
					navod_menu.x_tecka = 10;
				}
			}
			if ((navod_menu.y_tecka > navod_menu.horni_zavora_hlavni) && (strana == 0 || strana == 1))
			{
				navod_menu.y_tecka -= 2;
			}

			if ((navod_menu.y_oznaceni > navod_menu.horni_zavora_hlavni) && (strana == 2))
			{
				navod_menu.y_oznaceni -= 4;
			}
			if ((navod_menu.y_tecka > navod_menu.horni_zavora_hlavni) && (strana == 3))
			{
				if (navod_menu.y_tecka <= 12)
				{
					navod_menu.x_tecka = 4;
				}
				else
				{
					navod_menu.x_tecka = 7;
				}
				navod_menu.y_tecka -= 2;
			}
			if ((navod_menu.y_tecka > navod_menu.horni_zavora_hlavni) && (strana == 4))
			{
				navod_menu.y_tecka = navod_menu.y_tecka--;
			}
			navod_menu.exit = 0;
			navod_menu.enter = 0;
			navod_menu.del = 0;
		}
		break;
	}
	case 's':
	{
		{
			if ((navod_menu.y_tecka < navod_menu.dolni_zavora_hlavni) && (strana == -1))
			{
				if (navod_menu.y_tecka < 12)
				{
					navod_menu.y_tecka += 2;
				}
				else
				{
					navod_menu.y_tecka += 5;
					navod_menu.x_tecka = 2;
				}
			}
			if ((navod_menu.y_tecka < navod_menu.dolni_zavora_hlavni) && (strana == 0 || strana == 1))
			{
				navod_menu.y_tecka += 2;
			}
			if ((navod_menu.y_oznaceni < navod_menu.dolni_zavora_hlavni) && (strana == 2))
			{
				navod_menu.y_oznaceni += 4;
			}
			if ((navod_menu.y_tecka < navod_menu.dolni_zavora_hlavni) && (strana == 3))
			{
				if (navod_menu.y_tecka <= 8)
				{
					navod_menu.x_tecka = 4;
				}
				else
				{
					navod_menu.x_tecka = 7;
				}
				navod_menu.y_tecka += 2;
			}
			if ((navod_menu.y_tecka < navod_menu.dolni_zavora_hlavni) && (strana == 4))
			{
				navod_menu.y_tecka++;
			}
			navod_menu.exit = 0;
			navod_menu.enter = 0;
			navod_menu.del = 0;
		}
		break;
	}
	case 'a':
	{
		{
			if (navod_menu.x_oznaceni > navod_menu.leva_zavora_hlavni)
			{
				navod_menu.x_oznaceni -= 10;
				navod_menu.exit = 0;
				navod_menu.enter = 0;
				navod_menu.del = 0;
			}
		}
		break;
	}
	case 'd':
	{
		{
			if (navod_menu.x_oznaceni < navod_menu.prava_zavora_hlavni)
			{
				navod_menu.x_oznaceni += 10;
				navod_menu.exit = 0;
				navod_menu.enter = 0;
				navod_menu.del = 0;
			}
		}
		break;
	}
	case '\r':
	{
		{
			navod_menu.enter = 1;
			navod_menu.exit = 0;
		}
		break;
	}
	case ' ':
	{
		{
			if (strana == -1)
			{
				navod_menu.exit = 1;
				navod_menu.del = 0;
				navod.pokracovani = 0;
			}
		}
		break;
	}
	case 'q':
	{
		{
			if (strana == 0)
			{
				navod.program = 0;
			}
			else if (strana == -1)
			{
				navod_menu.reset = 1;
				navod.pokracovani = 0;
				navod_menu.enter = 0;
				navod_menu.del = 0;
			}
			else
			{
				navod_menu.enter = 0;
				navod_menu.del = 0;
			}
			navod_menu.exit = 1;
		}
		break;
	}
	case char(8):
	{
		if (strana == -1)
		{
			navod_menu.del = 1;
		}
		break;
	}
	default:
		break;
	}
}

/////////////////////    Vyhra / prohra     //////////////////////////

void vykresleni_konec(Menu navod_menu)
{
	int m = 4;
	int n = 2;
	navod_menu.setCursorPosition(m, n);
	////////////    vykreslovani plocha    ////////////
	for (int j = 0; j < navod_menu.vyska_menu * 3 / 4 + 1; j++)
	{
		navod_menu.setCursorPosition(m, n + j);
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
			navod.n_exp += 7;

		if (mod == 0)
			navod.n_exp += navod.pocet_rozbitych_bloku / 5;

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
		int docas_exp = 0;
		int level_up = 0;
		while (navod.n_exp >= 20)
		{
			navod.n_exp -= 20;
			level_up++;
			docas_exp = navod.n_exp;
		}

		navod_menu.exp += navod.n_exp;
		if (navod_menu.exp >= 20)
		{
			navod_menu.exp -= 20;
			docas_exp = navod_menu.exp;
			level_up++;
		}
		if (level_up > 0)
		{
			navod_menu.level += level_up;
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
		prechod(navod_menu);
		font(0, 20);
		SetWindow(navod_menu.delka_menu, navod_menu.vyska_menu - 2);

		vykresleni_konec(navod_menu);
		navod_menu.setCursorPosition(14, 4);
		if (!navod_menu.jazyk)
		{
			std::cout << navod_menu.odchodP1CZ;
			navod_menu.setCursorPosition(6, 16);
			std::cout << navod_menu.odchod2CZ;
			navod_menu.setCursorPosition(27, 16);
			std::cout << navod_menu.odchod3CZ;
			navod_menu.setCursorPosition(6, 8);
			if (mod == 0)
			{
				if (navod_menu.highscore_cas == 0)
				{
					navod_menu.highscore_cas = 45;
					std::cout << navod_menu.odchod4CZ << (char)navod_menu.highscore_cas;
					navod_menu.highscore_cas = 0;
				}
				else
					std::cout << navod_menu.odchod4CZ << navod_menu.highscore_cas;
			}
			if (mod == 3)
			{
				std::cout << navod_menu.odchod8CZ << navod_menu.highscore_znicenych_bloku;
			}
			navod_menu.setCursorPosition(8, 10);
			if (mod == 0)
			{
				std::cout << navod_menu.odchodP5CZ << navod.pocet_bloku;
			}
			if (mod == 3)
			{
				std::cout << navod_menu.odchod7CZ << navod.pocet_rozbitych_bloku;
			}
			navod_menu.setCursorPosition(16, 12);
			std::cout << navod_menu.odchod6CZ << navod_menu.level;
			navod_menu.setCursorPosition(10, 14);
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
			navod_menu.setCursorPosition(6, 16);
			std::cout << navod_menu.odchod2EN;
			navod_menu.setCursorPosition(27, 16);
			std::cout << navod_menu.odchod3EN;
			navod_menu.setCursorPosition(6, 8);
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
			navod_menu.setCursorPosition(8, 10);
			if (mod == 0)
			{
				std::cout << navod_menu.odchodP5EN << navod.cas;
			}
			if (mod == 3)
			{
				std::cout << navod_menu.odchod7CZ << navod.pocet_rozbitych_bloku;
			}
			navod_menu.setCursorPosition(16, 12);
			std::cout << navod_menu.odchod6EN << navod_menu.level;


			navod_menu.setCursorPosition(10, 14);
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
			vstup_menu(navod_menu, navod, -1);
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
	prechod(navod_menu);
	font(0, 20);
	SetWindow(navod_menu.delka_menu, navod_menu.vyska_menu - 2);

	vykresleni_konec(navod_menu);
	navod_menu.setCursorPosition(14, 4);
	if (!navod_menu.jazyk)
	{
		std::cout << navod_menu.odchodV1CZ;
		navod_menu.setCursorPosition(6, 16);
		std::cout << navod_menu.odchod2CZ;
		navod_menu.setCursorPosition(27, 16);
		std::cout << navod_menu.odchod3CZ;
		navod_menu.setCursorPosition(6, 8);
		std::cout << navod_menu.odchod4CZ << navod_menu.highscore_cas;
		navod_menu.setCursorPosition(8, 10);
		std::cout << navod_menu.odchodV5CZ << navod.cas;
		navod_menu.setCursorPosition(16, 12);
		std::cout << navod_menu.odchod6CZ << navod_menu.level;


		navod_menu.setCursorPosition(10, 14);
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
		navod_menu.setCursorPosition(6, 16);
		std::cout << navod_menu.odchod2EN;
		navod_menu.setCursorPosition(27, 16);
		std::cout << navod_menu.odchod3EN;
		navod_menu.setCursorPosition(6, 8);
		std::cout << navod_menu.odchod4EN << navod_menu.highscore_cas;;
		navod_menu.setCursorPosition(8, 10);
		std::cout << navod_menu.odchodV5EN << navod.cas;
		navod_menu.setCursorPosition(16, 12);
		std::cout << navod_menu.odchod6EN << navod_menu.level;


		navod_menu.setCursorPosition(10, 14);
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
		vstup_menu(navod_menu, navod, -1);
		navod.zivoty = navod_menu.pocet_zivotu;
	}
}

/////////////////////    Hra     //////////////////////////

Pong logika(int mod, Menu& navod_menu, Pong& navod)
{
	////////////    mic    ////////////

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

	////////////    Bomba    ////////////

	int n = 1;
	int Ub = navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba);
	int Db = navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba);
	int Lb = navod.bloky.at(navod.y_bomba).at(navod.x_bomba - n);
	int Rb = navod.bloky.at(navod.y_bomba).at(navod.x_bomba + n);

	int DRb = navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba + n);
	int ULb = navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba - n);
	int URb = navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba + n);
	int DLb = navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba - n);

	bool plosinab = (navod.y_bomba == navod.VYSKA - 4);
	bool stenaUb = (navod.y_bomba == 1);
	bool stenaLb = (navod.x_bomba == 1);
	bool stenaRb = (navod.x_bomba == navod.DELKA - 2);

	bool vybuch_stena = 0;

	////////////    casomira    ////////////

	navod.pocet_vykresleni++;
	if (navod.pocet_vykresleni % 20 == 0)
		navod.cas++;
	if (navod.pocet_vykresleni % 20 == 0)
		navod.padani++;

	////////////    power-up trvani    ////////////

	if (navod.trvani)
	{
		navod.rychlost_hry = 4;
		navod.pocet_trvani_power_up++;
		if (navod.pocet_trvani_power_up == 50)
		{
			navod.rychlost_hry = 2;
			navod.trvani = 0;
			navod.pocet_trvani_power_up = 0;
		}
	}

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
		Sleep(500);
		if (mod == 0)
			prohra(0, navod_menu, navod);
		if (mod == 3)
			prohra(3, navod_menu, navod);
	}

	////////////   vytvoreni bomby  ////////////

	if (navod.bomba_pocitadlo)
		navod.bomba_zacatek++;
	if (navod.bomba_zacatek == 20)
	{
		navod.bomba_zacatek = 0;
		navod.bomba_pocitadlo = 0;
		navod.ay_bomba = 1;
	}
	if (navod.pocet_vykresleni % 300 == 0)
	{
		navod.bomba_pocitadlo = 1;
		navod.bomba = 1;
		navod.ax_bomba = 0;
		navod.ay_bomba = 0;
		navod.y_bomba = navod.VYSKA - 8;;

		int random_x = navod.cas + navod.x_mic;
		while (random_x > 16)
		{
			random_x -= 17;
			if (random_x < 3)
			{
				random_x += 10;
			}
		}
		navod.x_bomba = random_x;
	}
	////////////   bomba propadla   ////////////

	if (navod.y_bomba == navod.VYSKA - 2 && navod.pocet_vykresleni % navod.rychlost_hry == 0) // spodni
	{
		navod.bomba = 0;
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
			////  plosina - mic  ////
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
			while (navod.bloky.at(navod.y_mic + navod.ay_mic).at(navod.x_mic + navod.ax_mic) > 0 || navod.bloky.at(navod.y_mic).at(navod.x_mic + navod.ax_mic) > 0 || 
				navod.bloky.at(navod.y_mic + navod.ay_mic).at(navod.x_mic) > 0 || (navod.x_mic + navod.ax_mic == navod.DELKA - 1) || (navod.x_mic + navod.ax_mic == 0) || (navod.y_mic + navod.ay_mic == 0))
			{
				if ((stenaR || stenaL || stenaU || L > 0 || U > 0 || R > 0 || D > 0))
				{
					////  steny - mic ////

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

					////  bloky - mic  ////

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
				if (UL > 0 || UR > 0 || DL > 0 || DR > 0)
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
			}
			

			////////////    power-up    ////////////

			if (navod.pocet_vykresleni % 200 == 0)
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
			if (U == -1) // horni
			{
				navod.bloky.at(navod.y_mic - 1).at(navod.x_mic)++;
				navod.power_up = 1;
			}
			if (D == -1) // spodni
			{
				navod.bloky.at(navod.y_mic + 1).at(navod.x_mic)++;
				navod.power_up = 1;
			}
			if (DR == -1)
			{
				navod.bloky.at(navod.y_mic + 1).at(navod.x_mic + 1)++;
				navod.power_up = 1;
			}
			if (UR == -1)
			{
				navod.bloky.at(navod.y_mic - 1).at(navod.x_mic + 1)++;
				navod.power_up = 1;
			}
			if (DL == -1)
			{
				navod.bloky.at(navod.y_mic + 1).at(navod.x_mic - 1)++;
				navod.power_up = 1;
			}
			if (UL == -1)
			{
				navod.bloky.at(navod.y_mic - 1).at(navod.x_mic - 1)++;
				navod.power_up = 1;
			}

			///////////   zrychleni - mic    /////////////

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
		}
		////  plosina - bomba  ////

		if (navod.pocet_vykresleni % (2 * navod.rychlost_hry) == 0)
		{
			if (plosinab)
			{

				if (ULb > 0 || URb > 0)
				{
					if (ULb > 0)
					{
						navod.bomba = 0;
						navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba - n)--;
						navod.pocet_bloku--;
						navod.pocet_rozbitych_bloku++;
					}
					if (URb > 0)
					{
						navod.bomba = 0;
						navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba + n)--;
						navod.pocet_bloku--;
						navod.pocet_rozbitych_bloku++;
					}
				}
				else
				{
					if (navod.x_bomba > navod.x_plosina - 1 && navod.x_bomba <= (navod.x_plosina + navod.velikost_plosina / 2))
					{
						navod.ay_bomba = -1; // vlevo
						navod.ax_bomba = -1;
					}
					if (navod.x_bomba >= (navod.x_plosina + navod.velikost_plosina / 2) && navod.x_bomba < (navod.x_plosina + navod.velikost_plosina + 1))
					{
						navod.ay_bomba = -1; // vpravo
						navod.ax_bomba = 1;
					}
				}
			}

			////  steny - bomba ////

			if (stenaRb) // prava stena
			{
				if (DLb > 0 || ULb > 0)
				{
					if (DLb > 0)
					{
						navod.bomba = 0;
						navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba - n)--;
						navod.pocet_bloku--;
						navod.pocet_rozbitych_bloku++;
					}
					if (ULb > 0)
					{
						navod.bomba = 0;
						navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba - n)--;
						navod.pocet_bloku--;
						navod.pocet_rozbitych_bloku++;
					}
				}
				else
					navod.ax_bomba = -1;
			}
			if (stenaLb) // leva stena
			{
				if (DRb > 0 || URb > 0)
				{
					if (DRb > 0)
					{
						navod.bomba = 0;
						navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba + n)--;
						navod.pocet_bloku--;
						navod.pocet_rozbitych_bloku++;
					}
					if (URb > 0)
					{
						navod.bomba = 0;
						navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba + n)--;
						navod.pocet_bloku--;
						navod.pocet_rozbitych_bloku++;
					}
				}
				else
					navod.ax_bomba = 1;
			}
			if (stenaUb) // horni stena
			{
				if (DRb > 0 || DLb > 0)
				{
					if (DRb > 0)
					{
						navod.bomba = 0;
						navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba + n)--;
						navod.pocet_bloku--;
						navod.pocet_rozbitych_bloku++;
					}
					if (DLb > 0)
					{
						navod.bomba = 0;
						navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba - n)--;
						navod.pocet_bloku--;
						navod.pocet_rozbitych_bloku++;
					}
				}
				else
					navod.ay_bomba = 1;
			}

			/////////    bloky - bomba    ///////

			if (Rb > 0 || (DRb > 0 && navod.ax_mic == 1 && navod.ay_bomba == 1) || Db > 0 || (DLb > 0 && navod.ax_bomba == -1 && navod.ay_bomba == 1) || Lb > 0 || (ULb > 0 && navod.ax_bomba == -1 && navod.ay_bomba == -1) || Ub > 0 || (URb > 0 && navod.ax_bomba == 1 && navod.ay_bomba == -1))
			{
				//navod_menu.vybuch;
				for (n = 1; n < 3; n++)
				{
					int Ub = navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba);
					int Db = navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba);
					int Lb = navod.bloky.at(navod.y_bomba).at(navod.x_bomba - n);
					int Rb = navod.bloky.at(navod.y_bomba).at(navod.x_bomba + n);

					int DRb = navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba + n);
					int ULb = navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba - n);
					int URb = navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba + n);
					int DLb = navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba - n);
					if (Lb > 0) // levy
					{
						navod.bomba = 0;
						navod.bloky.at(navod.y_bomba).at(navod.x_bomba - n)--;
						navod.pocet_bloku--;
						navod.pocet_rozbitych_bloku++;
					}
					if (Rb > 0) // pravy
					{
						navod.bomba = 0;
						navod.bloky.at(navod.y_bomba).at(navod.x_bomba + n)--;
						navod.pocet_bloku--;
						navod.pocet_rozbitych_bloku++;
					}
					if (Ub > 0) // hroni
					{
						navod.bomba = 0;
						navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba)--;
						navod.pocet_bloku--;
						navod.pocet_rozbitych_bloku++;
					}
					if (Db > 0) // spodni
					{
						navod.bomba = 0;
						navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba)--;
						navod.pocet_bloku--;
						navod.pocet_rozbitych_bloku++;
					}
				}
				n = 1;
				if (DLb > 0) // levo/spodni
				{
					navod.bomba = 0;
					navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba - n)--;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
				if (DRb > 0) // pravo/spodni
				{
					navod.bomba = 0;
					navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba + n)--;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
				if (ULb > 0) // levo/horni
				{
					navod.bomba = 0;
					navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba - n)--;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
				if (URb > 0) // pravo/horni
				{
					navod.bomba = 0;
					navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba + n)--;
					navod.pocet_bloku--;
					navod.pocet_rozbitych_bloku++;
				}
			}
			///////////   zrychleni - bomba    /////////////

			if (navod.bomba)
			{
				if (navod.ax_bomba == 1)
				{
					navod.x_bomba++;
				}
				if (navod.ax_bomba == -1)
				{
					navod.x_bomba--;
				}
				if (navod.ay_bomba == 1)
				{
					navod.y_bomba++;
				}
				if (navod.ay_bomba == -1)
				{
					navod.y_bomba--;
				}
			}
			else
			{
				navod.ay_bomba = 0;
				navod.ax_bomba = 0;
			}
		}
		if (navod.pocet_vykresleni % navod.rychlost_plosiny == 0)
		{
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
	}
	else if (navod.pokracovani)
	{
		navod.ax_mic = vstup_hra(navod);
		navod.ay_mic = -1;
		navod.y_mic = navod.VYSKA - 5;
		navod.x_mic = navod.DELKA / 2;
	}
	return navod;
}
Pong vykresleni_start(int mod, Menu& navod_menu, Pong& navod)
{
	////////////    vykreslovani plocha    ////////////
	navod_menu.setCursorPosition(0, 0);
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
		navod_menu.setCursorPosition(navod.x_plosina + i, navod.VYSKA - 3);
		std::cout << navod_menu.pole_skin[i];
	}

	////////////    vykreslovani mice na zacatku    ////////////
	navod_menu.setCursorPosition(navod.x_mic, navod.y_mic);
	std::cout << navod.mic;

	////////////    vykreslovani bloku na zacatku    ////////////
	for (int j = 0; j < navod.bloky.size(); j++)
	{
		for (int i = 0; i < navod.bloky.at(j).size(); i++)
		{
			if (navod.bloky.at(j).at(i) == 1)
			{
				navod_menu.setCursorPosition(i, j);
				std::cout << navod.blok1;
				navod.pocet_bloku++;
			}
			if (navod.bloky.at(j).at(i) == 2)
			{
				navod_menu.setCursorPosition(i, j);
				std::cout << navod.blok2;
				navod.pocet_bloku = navod.pocet_bloku + 2;
			}
			if (navod.bloky.at(j).at(i) == 3)
			{
				navod_menu.setCursorPosition(i, j);
				std::cout << navod.blok3;
				navod.pocet_bloku = navod.pocet_bloku + 3;
			}
		}
	}

	////////////    vykreslovani HUD    ////////////
	navod_menu.setCursorPosition(0, navod.VYSKA - 1);
	for (int i = 0; i < navod.DELKA; i++)
	{
		if (i == 0 || i == navod.DELKA - 1)
			std::cout << char(223);
		else
			std::cout << '-';
	}
	if (mod == 0)
	{
		navod_menu.setCursorPosition(2, navod.VYSKA);
		std::cout << navod.blok2 << navod.pocet_bloku;
	}

	navod_menu.setCursorPosition(navod.DELKA - 4, navod.VYSKA);
	std::cout << navod.cas;

	navod_menu.setCursorPosition(8, navod.VYSKA);
	for (int i = 0; i < navod.zivoty; i++)
		std::cout << char(3);

	return navod;
}
void smazani_hra(int mod, Menu& navod_menu, Pong& navod)
{
	////////////    mic    ////////////

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


	////////////    Bomba    ////////////
	int n = 1;
	int Ub = navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba);
	int Db = navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba);
	int Lb = navod.bloky.at(navod.y_bomba).at(navod.x_bomba - n);
	int Rb = navod.bloky.at(navod.y_bomba).at(navod.x_bomba + n);

	int DRb = navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba + n);
	int ULb = navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba - n);
	int URb = navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba + n);
	int DLb = navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba - n);

	int SCXb = navod.x_bomba;
	int SCYb = navod.y_bomba;

	int SUb = navod.y_bomba - n;
	int SLb = navod.x_bomba - n;
	int SRb = navod.x_bomba + n;
	int SDb = navod.y_bomba + n;

	bool plosinab = (navod.y_bomba == navod.VYSKA - 4);
	bool stenaUb = (navod.y_bomba == 1);
	bool stenaLb = (navod.x_bomba == 1);
	bool stenaRb = (navod.x_bomba == navod.DELKA - 2);

	if (navod.pocet_vykresleni % navod.rychlost_plosiny == navod.rychlost_plosiny - 1)
	{
		////////////    mazani plosiny    ////////////
		if (!(navod.pohyb == 0))
		{
			navod_menu.setCursorPosition(navod.x_plosina, navod.VYSKA - 3);
			for (int i = 0; i < navod.velikost_plosina; i++)
			{
				std::cout << " ";
			}
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
						navod_menu.setCursorPosition(i, j);
						std::cout << ' ';
					}
				}
			}
		}
	}

	////////////    zmena zivotu    ////////////
	if (navod.ztrata_zivotu == 1)
	{
		navod_menu.setCursorPosition(8, navod.VYSKA);
		for (int i = 0; i < navod.zivoty + 1; i++)
		{
			if (i < navod.zivoty)
				std::cout << char(3);
			else
				std::cout << ' ';
		}
		navod.ztrata_zivotu = 0;
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
					navod_menu.setCursorPosition(SL, SCY);
					if (L == 1)
						std::cout << " ";
					if (L == 2)
						std::cout << navod.blok1;
					if (L == 3)
						std::cout << navod.blok2;
				}
				if (R > 0) // pravy
				{
					navod_menu.setCursorPosition(SR, SCY);
					if (R == 1)
						std::cout << " ";
					if (R == 2)
						std::cout << navod.blok1;
					if (R == 3)
						std::cout << navod.blok2;
				}
				if (U > 0) // horni
				{
					navod_menu.setCursorPosition(SCX, SU);
					if (U == 1)
						std::cout << " ";
					if (U == 2)
						std::cout << navod.blok1;
					if (U == 3)
						std::cout << navod.blok2;
				}
				if (D > 0) // spodni
				{
					navod_menu.setCursorPosition(SCX, SD);
					if (D == 1)
						std::cout << " ";
					if (D == 2)
						std::cout << navod.blok1;
					if (D == 3)
						std::cout << navod.blok2;
				}
			}
			else if ((plosina || stenaR || stenaL || stenaU || L > 0 || U > 0 || R > 0 || D > 0) && (UL > 0 || UR > 0 || DL > 0 || DR > 0))
			{
				if (DR > 0)
				{
					if (U > 0 || stenaU) // pravo/dolni - shora
					{
						if (U > 0)
						{
							navod_menu.setCursorPosition(SCX, SU);
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
							navod_menu.setCursorPosition(SL, SCY);
							if (L == 1)
								std::cout << " ";
							if (L == 2)
								std::cout << navod.blok1;
							if (L == 3)
								std::cout << navod.blok2;
						}
					}
					navod_menu.setCursorPosition(SR, SD);
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
							navod_menu.setCursorPosition(SCX, SD);
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
							navod_menu.setCursorPosition(SR, SCY);
							if (R == 1)
								std::cout << " ";
							if (R == 2)
								std::cout << navod.blok1;
							if (R == 3)
								std::cout << navod.blok2;
						}
					}
					navod_menu.setCursorPosition(SL, SU);
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
							navod_menu.setCursorPosition(SCX, SU);
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
							navod_menu.setCursorPosition(SR, SCY);
							if (R == 1)
								std::cout << " ";
							if (R == 2)
								std::cout << navod.blok1;
							if (R == 3)
								std::cout << navod.blok2;
						}
					}
					navod_menu.setCursorPosition(SL, SD);
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
							navod_menu.setCursorPosition(SCX, SD);
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
							navod_menu.setCursorPosition(SL, SCY);
							if (L == 1)
								std::cout << " ";
							if (L == 2)
								std::cout << navod.blok1;
							if (L == 3)
								std::cout << navod.blok2;
						}
					}
					navod_menu.setCursorPosition(SR, SU);
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
					navod_menu.setCursorPosition(SL, SD);
					if (DL == 1)
						std::cout << " ";
					if (DL == 2)
						std::cout << navod.blok1;
					if (DL == 3)
						std::cout << navod.blok2;
				}
				if (DR > 0 && navod.ax_mic == 1 && navod.ay_mic == 1) // pravo/spodni
				{
					navod_menu.setCursorPosition(SR, SD);
					if (DR == 1)
						std::cout << " ";
					if (DR == 2)
						std::cout << navod.blok1;
					if (DR == 3)
						std::cout << navod.blok2;
				}
				if (UL > 0 && navod.ax_mic == -1 && navod.ay_mic == -1) // levo/horni
				{
					navod_menu.setCursorPosition(SL, SU);
					if (UL == 1)
						std::cout << " ";
					if (UL == 2)
						std::cout << navod.blok1;
					if (UL == 3)
						std::cout << navod.blok2;
				}
				if (UR > 0 && navod.ax_mic == 1 && navod.ay_mic == -1) // pravo/horni
				{
					navod_menu.setCursorPosition(SR, SU);
					if (UR == 1)
						std::cout << " ";
					if (UR == 2)
						std::cout << navod.blok1;
					if (UR == 3)
						std::cout << navod.blok2;
				}

			}

			////////////    mazani mice    ////////////

			navod_menu.setCursorPosition(SCX, SCY);
			std::cout << " ";

		}
			////////////   bomba   ////////////

		if (navod.pocet_vykresleni % (2 * navod.rychlost_hry) == (2 * navod.rychlost_hry) - 1)
		{
			if (plosinab)
			{
				if (ULb > 0)
				{
					navod_menu.setCursorPosition(SLb, SUb);
					if (ULb == 1)
						std::cout << " ";
					if (ULb == 2)
						std::cout << navod.blok1;
					if (ULb == 3)
						std::cout << navod.blok2;
				}
				if (URb > 0)
				{
					navod_menu.setCursorPosition(SRb, SUb);
					if (URb == 1)
						std::cout << " ";
					if (URb == 2)
						std::cout << navod.blok1;
					if (URb == 3)
						std::cout << navod.blok2;
				}
			}

			////  steny - bomba ////

			if (stenaRb) // prava stena
			{
				if (DLb > 0)
				{
					navod_menu.setCursorPosition(SLb, SDb);
					if (DLb == 1)
						std::cout << " ";
					if (DLb == 2)
						std::cout << navod.blok1;
					if (DLb == 3)
						std::cout << navod.blok2;
				}
				if (ULb > 0)
				{
					navod_menu.setCursorPosition(SLb, SUb);
					if (ULb == 1)
						std::cout << " ";
					if (ULb == 2)
						std::cout << navod.blok1;
					if (ULb == 3)
						std::cout << navod.blok2;
				}
			}
			if (stenaLb) // leva stena
			{
				
				if (DRb > 0)
				{
					navod_menu.setCursorPosition(SRb, SDb);
					if (DRb == 1)
						std::cout << " ";
					if (DRb == 2)
						std::cout << navod.blok1;
					if (DRb == 3)
						std::cout << navod.blok2;
				}
				if (URb > 0)
				{
					navod_menu.setCursorPosition(SRb, SUb);
					if (URb == 1)
						std::cout << " ";
					if (URb == 2)
						std::cout << navod.blok1;
					if (URb == 3)
						std::cout << navod.blok2;
				}
			}
			if (stenaUb) // horni stena
			{
				if (DRb > 0)
				{
					navod_menu.setCursorPosition(SRb, SDb);
					if (DRb == 1)
						std::cout << " ";
					if (DRb == 2)
						std::cout << navod.blok1;
					if (DRb == 3)
						std::cout << navod.blok2;
				}
				if (DLb > 0)
				{
					navod_menu.setCursorPosition(SLb, SDb);
					if (DLb == 1)
						std::cout << " ";
					if (DLb == 2)
						std::cout << navod.blok1;
					if (DLb == 3)
						std::cout << navod.blok2;
				}
			}
			if (Rb > 0 || (DRb > 0 && navod.ax_mic == 1 && navod.ay_bomba == 1) || Db > 0 || (DLb > 0 && navod.ax_bomba == -1 && navod.ay_bomba == 1) || Lb > 0 || (ULb > 0 && navod.ax_bomba == -1 && navod.ay_bomba == -1) || Ub > 0 || (URb > 0 && navod.ax_bomba == 1 && navod.ay_bomba == -1))
			{
				
				for (n = 1; n < 3; n++)
				{
					int Ub = navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba);
					int Db = navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba);
					int Lb = navod.bloky.at(navod.y_bomba).at(navod.x_bomba - n);
					int Rb = navod.bloky.at(navod.y_bomba).at(navod.x_bomba + n);

					int DRb = navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba + n);
					int ULb = navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba - n);
					int URb = navod.bloky.at(navod.y_bomba - n).at(navod.x_bomba + n);
					int DLb = navod.bloky.at(navod.y_bomba + n).at(navod.x_bomba - n);

					int SUb = navod.y_bomba - n;
					int SLb = navod.x_bomba - n;
					int SRb = navod.x_bomba + n;
					int SDb = navod.y_bomba + n;

					if (Lb > 0) // levy
					{
						navod_menu.setCursorPosition(SLb, SCYb);
						if (Lb == 1)
							std::cout << " ";
						if (Lb == 2)
							std::cout << navod.blok1;
						if (Lb == 3)
							std::cout << navod.blok2;
					}
					if (Rb > 0)
					{
						navod_menu.setCursorPosition(SRb, SCYb);
						if (Rb == 1)
							std::cout << " ";
						if (Rb == 2)
							std::cout << navod.blok1;
						if (Rb == 3)
							std::cout << navod.blok2;
					}
					if (Ub > 0) // horni
					{
						navod_menu.setCursorPosition(SCXb, SUb);
						if (Ub == 1)
							std::cout << " ";
						if (Ub == 2)
							std::cout << navod.blok1;
						if (Ub == 3)
							std::cout << navod.blok2;
					}
					if (Db > 0) // spodni
					{
						navod_menu.setCursorPosition(SCXb, SDb);
						if (Db == 1)
							std::cout << " ";
						if (Db == 2)
							std::cout << navod.blok1;
						if (Db == 3)
							std::cout << navod.blok2;
					}
				}
				n = 1;
				if (DLb > 0) // levo/spodni
				{
					navod_menu.setCursorPosition(SLb, SDb);
					if (DLb == 1)
						std::cout << " ";
					if (DLb == 2)
						std::cout << navod.blok1;
					if (DLb == 3)
						std::cout << navod.blok2;
				}
				if (DRb > 0) // pravo/spodni
				{
					navod_menu.setCursorPosition(SRb, SDb);
					if (DRb == 1)
						std::cout << " ";
					if (DRb == 2)
						std::cout << navod.blok1;
					if (DRb == 3)
						std::cout << navod.blok2;
				}
				if (ULb > 0) // levo/horni
				{
					navod_menu.setCursorPosition(SLb, SUb);
					if (ULb == 1)
						std::cout << " ";
					if (ULb == 2)
						std::cout << navod.blok1;
					if (ULb == 3)
						std::cout << navod.blok2;
				}
				if (URb > 0) // pravo/horni
				{
					navod_menu.setCursorPosition(SRb, SUb);
					if (URb == 1)
						std::cout << " ";
					if (URb == 2)
						std::cout << navod.blok1;
					if (URb == 3)
						std::cout << navod.blok2;
				}
				
			}

			////////////    mazani bomby    ////////////

			navod_menu.setCursorPosition(SCXb, SCYb);
			std::cout << " ";
		}
		////////////    mazani power-upu    ////////////
		if (D == -1)
		{
			navod_menu.setCursorPosition(SCX, SD);
			std::cout << " ";
		}
		if (U == -1)
		{
			navod_menu.setCursorPosition(SCX, SU);
			std::cout << " ";
		}
		if (R == -1)
		{
			navod_menu.setCursorPosition(SR, SCY);
			std::cout << " ";
		}
		if (L == -1)
		{
			navod_menu.setCursorPosition(SL, SCY);
			std::cout << " ";
		}
		if (DR == -1)
		{
			navod_menu.setCursorPosition(SR, SD);
			std::cout << " ";
		}
		if (UR == -1)
		{
			navod_menu.setCursorPosition(SR, SU);
			std::cout << " ";
		}
		if (DL == -1)
		{
			navod_menu.setCursorPosition(SL, SD);
			std::cout << " ";
		}
		if (UL == -1)
		{
			navod_menu.setCursorPosition(SU, SL);
			std::cout << " ";
		}
	}
}
void vykresleni_hra(int mod, Menu& navod_menu, Pong& navod)
{
	if (navod.pokracovani)
	{
		if (navod.pocet_vykresleni % navod.rychlost_plosiny == 0)
		{
			////////////    vykreslovani plosiny    ////////////
			if (!(navod.pohyb == 0))
			{
				navod_menu.skin();
				for (int i = 0; i < navod.velikost_plosina; i++)
				{
					navod_menu.setCursorPosition(navod.x_plosina + i, navod.VYSKA - 3);
					std::cout << navod_menu.pole_skin[i];
				}
				navod.pohyb = 0;
			}
		}
		if (navod.pocet_vykresleni % navod.rychlost_hry == 0)
		{
			////////////    vykreslovani mice    ////////////

			navod_menu.setCursorPosition(navod.x_mic, navod.y_mic);
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
							navod_menu.setCursorPosition(i, j);
							std::cout << navod.blok1;
							navod.pocet_bloku++;
						}
						if (navod.bloky.at(j).at(i) == 2)
						{
							navod_menu.setCursorPosition(i, j);
							std::cout << navod.blok2;
							navod.pocet_bloku = navod.pocet_bloku + 2;
						}
						if (navod.bloky.at(j).at(i) == 3)
						{
							navod_menu.setCursorPosition(i, j);
							std::cout << navod.blok3;
							navod.pocet_bloku = navod.pocet_bloku + 3;
						}
					}
				}

			}

			////////////    vykreslovani power-upu   ////////////

			if (navod.pocet_vykresleni % 200 == 0)
			{
				for (int j = 0; j < navod.bloky.size(); j++)
				{
					for (int i = 0; i < navod.bloky.at(j).size(); i++)
					{
						if (navod.bloky.at(j).at(i) == -1)
						{
							navod_menu.setCursorPosition(navod.x_powerup, navod.y_powerup);
							std::cout << '$';
						}
					}
				}
			}

			////////////    vykreslovani poctu bloku    ////////////

			if (mod == 0)
			{
				navod_menu.setCursorPosition(3, navod.VYSKA);
				std::cout << "    ";
				navod_menu.setCursorPosition(3, navod.VYSKA);
				std::cout << navod.pocet_bloku;
			}
		}
		if (navod.pocet_vykresleni % (2 * navod.rychlost_hry) == 0)
		{
			////////////    vykreslovani bomby    ////////////
			if (navod.bomba || navod.bomba_pocitadlo)
			{
				navod_menu.setCursorPosition(navod.x_bomba, navod.y_bomba);
				std::cout << 'X';
			}
			//////////    vykreslovani casomiry  ////////////
		}
		if (navod.pocet_vykresleni % 20 == 0)
		{
			navod_menu.setCursorPosition(navod.DELKA - 4, navod.VYSKA);
			std::cout << "   ";
			navod_menu.setCursorPosition(navod.DELKA - 4, navod.VYSKA);
			std::cout << navod.cas;
		}

		//////////    vykreslovani HUD power-up  ////////////

		if (navod.power_up)
		{
			navod_menu.setCursorPosition(12, navod.VYSKA);
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
		prechod(navod_menu);
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
		prechod(navod_menu);
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
		prechod(navod_menu);
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

Menu vykresleni_profil(Menu navod_menu)
{
	///////    Ramecek   ///////
	navod_menu.setCursorPosition(8, 7);
	for (int i = 0; i < 24; i++)
	{
		if(i == 0)
			std::cout << char(218);
		else if (i == 23)
			std::cout << char(191);
		else
			std::cout << char(196);
	}
	for (int j = 8; j < 13; j++)
	{
		navod_menu.setCursorPosition(8, j);
		for (int i = 0; i < 24; i++)
		{
			if (i == 0)
				std::cout << char(179);
		}
	}
	for (int j = 8; j < 13; j++)
	{
		navod_menu.setCursorPosition(31, j);
		for (int i = 0; i < 24; i++)
		{
			if (i == 0)
				std::cout << char(179);
		}
	}
	navod_menu.setCursorPosition(8, 13);
	for (int i = 0; i < 24; i++)
	{
		if (i == 0)
			std::cout << char(192);
		else if (i == 23)
			std::cout << char(217);
		else
			std::cout << char(196);
	}
	navod_menu.setCursorPosition(32, 16);
	for (int i = 0; i < 7; i++)
	{
		if (i == 0)
			std::cout << char(218);
		else if (i == 6)
			std::cout << char(191);
		else
			std::cout << char(196);
	}
	navod_menu.setCursorPosition(32, 17);
	for (int i = 0; i < 7; i++)
	{
		if (i == 0 || i == 6)
			std::cout << char(179);
		else if (i == 3)
			std::cout << char(17);
		else if (i == 4 || i == 5)
			std::cout << char(196);
		else
			std::cout << ' ';
	}
	navod_menu.setCursorPosition(32, 18);
	for (int i = 0; i < 7; i++)
	{
		if (i == 0)
			std::cout << char(192);
		else if (i == 6)
			std::cout << char(217);
		else
			std::cout << char(196);
	}

	///////    Text   ///////

	navod_menu.setCursorPosition(10, 5);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.vyber_profiluCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.vyber_profiluEN;
	navod_menu.setCursorPosition(12, 8);
	std::cout << navod_menu.muj_profil0;
	navod_menu.setCursorPosition(12, 10);
	std::cout << navod_menu.muj_profil1;
	navod_menu.setCursorPosition(12, 12);
	std::cout << navod_menu.muj_profil2;

	navod_menu.setCursorPosition(4, 16);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.jazykCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.jazykEN;
	navod_menu.setCursorPosition(4, 17);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.ceskyCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.anglickyEN;
	if (!navod_menu.jazyk)
	{
		navod_menu.setCursorPosition(18, 17);
		std::cout << navod_menu.smazani_pokrokCZ;
	}
	if (navod_menu.jazyk)
	{
		navod_menu.setCursorPosition(17, 17);
		std::cout << navod_menu.smazani_pokrokEN;
	}

	navod_menu.x_tecka = 10;
	navod_menu.y_tecka = 8;
	navod_menu.horni_zavora_hlavni = 8;
	navod_menu.dolni_zavora_hlavni = 17;
	return navod_menu;
}
Menu vykresleni_hlavni(Menu navod_menu)
{
	navod_menu.setCursorPosition(6, 10);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.herni_modyCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.herni_modyEN;
	navod_menu.setCursorPosition(6, 12);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.vzhled_plosinyCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.vzhled_plosinyEN;
	navod_menu.setCursorPosition(6, 14);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.nastaveniCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.nastaveniEN;
	navod_menu.setCursorPosition(2, 18);
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
Menu vykresleni_herni_mody(Menu navod_menu)
{
	navod_menu.setCursorPosition(14, 3);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.HERNI_MODYCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.HERNI_MODYEN;
	navod_menu.setCursorPosition(6, 8);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.klasikCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.klasikEN;
	navod_menu.setCursorPosition(6, 10);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.rogue_likeCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.rogue_likeEN;
	navod_menu.setCursorPosition(6, 12);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.stejne_tvaryCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.stejne_tvaryEN;
	navod_menu.setCursorPosition(6, 14);
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
Menu vykresleni_nastaveni(Menu navod_menu)
{
	navod_menu.setCursorPosition(15, 3);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.NASTAVENICZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.NASTAVENIEN;
	navod_menu.setCursorPosition(6, 8);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.ovladaniCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.ovladaniEN;
	navod_menu.setCursorPosition(6, 10);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.jazykCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.jazykEN;
	if (navod_menu.vytazeno)
	{
		navod_menu.setCursorPosition(9, 12);
		if (!navod_menu.jazyk)
			std::cout << navod_menu.ceskyCZ;
		if (navod_menu.jazyk)
			std::cout << navod_menu.ceskyEN;
		navod_menu.setCursorPosition(9, 14);
		if (!navod_menu.jazyk)
			std::cout << navod_menu.anglickyCZ;
		if (navod_menu.jazyk)
			std::cout << navod_menu.anglickyEN;
	}
	else
	{
		navod_menu.setCursorPosition(9, 12);
			std::cout << "        ";
		navod_menu.setCursorPosition(9, 14);
		std::cout << "        ";
	}

	navod_menu.x_tecka = 4;
	if (navod_menu.balic)
	navod_menu.y_tecka = 10;
	else
		navod_menu.y_tecka = 8;

	navod_menu.horni_zavora_hlavni = 8;
	if (navod_menu.vytazeno)
		navod_menu.dolni_zavora_hlavni = 14;
	else
		navod_menu.dolni_zavora_hlavni = 10;
	return navod_menu;
}
Menu vykresleni_ovladani(Menu navod_menu)
{
	navod_menu.setCursorPosition(15, 3);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.OVLADANICZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.OVLADANIEN;
	navod_menu.setCursorPosition(6, 5);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.ovladani_menuCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.ovladani_menuEN;
	navod_menu.setCursorPosition(9, 7);
		std::cout << "W";
	navod_menu.setCursorPosition(7, 8);
		std::cout << "A S D";
	navod_menu.setCursorPosition(15, 8);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.ovladani_mezernikCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.ovladani_mezernikEN;
	navod_menu.setCursorPosition(26, 8);
	std::cout << "Q";

	navod_menu.setCursorPosition(7, 12);
	for (int i = 0; i < 20;i++)
		std::cout << ".";
	navod_menu.setCursorPosition(7, 13);
	for (int i = 0; i < 20;i++)
		std::cout << ".";
	navod_menu.setCursorPosition(7, 14);
	for (int i = 0; i < 20;i++)
		std::cout << ".";
	navod_menu.setCursorPosition(7, 15);
	for (int i = 0; i < 20;i++)
		std::cout << ".";

	navod_menu.setCursorPosition(6, 10);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.ovladani_hraCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.ovladani_hraEN;
	navod_menu.setCursorPosition(7, 12);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.ovladani_pohyb_vlevoCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.ovladani_pohyb_vlevoEN;
	navod_menu.setCursorPosition(29, 12);
	std::cout << navod_menu.pohyb_vpravo;
	navod_menu.setCursorPosition(7, 13);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.ovladani_pohyb_vpravoCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.ovladani_pohyb_vpravoEN;
	navod_menu.setCursorPosition(29, 13);
	std::cout << navod_menu.pohyb_vlevo;
	navod_menu.setCursorPosition(7, 14);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.ovladani_schopnostCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.ovladani_schopnostEN;
	navod_menu.setCursorPosition(29, 14);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.ovladani_mezernikCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.ovladani_mezernikEN;
	navod_menu.setCursorPosition(7, 15);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.ovladani_pauzaCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.ovladani_pauzaEN;
	navod_menu.setCursorPosition(29, 15);
	std::cout << "Esc";

	navod_menu.x_tecka = 5;
	navod_menu.y_tecka = 12;
	navod_menu.horni_zavora_hlavni = 12;
	navod_menu.dolni_zavora_hlavni = 15;
	return navod_menu;
}
Menu vykresleni_vzhled_plosiny(Menu navod_menu)
{
	if (!navod_menu.jazyk)
	{
		navod_menu.setCursorPosition(13, 3);
		std::cout << navod_menu.VZHLED_PLOSINYCZ;
	}
	if (navod_menu.jazyk)
	{
		navod_menu.setCursorPosition(18, 3);
		std::cout << navod_menu.VZHLED_PLOSINYEN;
	}

	navod_menu.setCursorPosition(7, 10);
	std::cout << "IIIIII";

	if (navod_menu.level >= navod_menu.potr_urov1)
	{
		navod_menu.setCursorPosition(17, 10);
		std::cout << "======";
	}
	else
	{
		navod_menu.setCursorPosition(17, 10);
		std::cout << "??????";
	}
	if (navod_menu.level >= navod_menu.potr_urov2)
	{
		navod_menu.setCursorPosition(27, 10);
		std::cout << "FELZCU";
	}
	else
	{
		navod_menu.setCursorPosition(27, 10);
		std::cout << "??????";
	}
	if (navod_menu.level >= navod_menu.potr_urov3)
	{
		navod_menu.setCursorPosition(7, 14);
		std::cout << "8====D";
	}
	else
	{
		navod_menu.setCursorPosition(7, 14);
		std::cout << "??????";
	}
	if (navod_menu.level >= navod_menu.potr_urov4)
	{
		navod_menu.setCursorPosition(17, 14);
		std::cout << char(174) << char(174) << char(174) << char(175) << char(175) << char(175);
	}
	else
	{
		navod_menu.setCursorPosition(17, 14);
		std::cout << "??????";
	}
	if (navod_menu.level >= navod_menu.potr_urov5)
	{
		navod_menu.setCursorPosition(27, 14);
		std::cout << "______";
	}
	else
	{
		navod_menu.setCursorPosition(27, 14);
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

void vykresleni_nazev_profilu(Menu navod_menu)
{
	for (int j = 8; j < 13; j++)
	{
		navod_menu.setCursorPosition(9, j);
		for (int i = 0; i < 22; i++)
		{
			std::cout << ' ';
		}
	}
	navod_menu.setCursorPosition(10, 8);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.profil_nazevCZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.profil_nazevEN;
}
void vykresleni_otazka(Menu navod_menu)
{
	navod_menu.setCursorPosition(5, 2);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.smazani_pokrok_otazka1CZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.smazani_pokrok_otazka1EN;
	navod_menu.setCursorPosition(26, 3);
	if (!navod_menu.jazyk)
		std::cout << navod_menu.smazani_pokrok_otazka2CZ;
	if (navod_menu.jazyk)
		std::cout << navod_menu.smazani_pokrok_otazka2EN;
}
void smazani_otazka(Menu navod_menu)
{
	navod_menu.setCursorPosition(5, 2);
	std::cout << "                               ";
	navod_menu.setCursorPosition(26, 3);
	std::cout << "       ";
}
void vykresleni_logo(Menu navod_menu)
{
	int m = 10;
	int n = 2;
	navod_menu.setCursorPosition(m, n);
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
	navod_menu.setCursorPosition(m, n + 1);
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
	navod_menu.setCursorPosition(m, n + 2);
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
	navod_menu.setCursorPosition(m, n + 3);
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
void vykresleni_tecka(Menu navod_menu)
{
	navod_menu.setCursorPosition(navod_menu.x_tecka, navod_menu.y_tecka);
	std::cout << char(254);
}
void smazani_tecka(Menu navod_menu)
{
	navod_menu.setCursorPosition(navod_menu.x_tecka, navod_menu.y_tecka);
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
				navod_menu.setCursorPosition(navod_menu.x_oznaceni, navod_menu.y_oznaceni);
				std::cout << char(201);
			}
			if (j == 0 && i == 7)
			{
				navod_menu.setCursorPosition(navod_menu.x_oznaceni + 7, navod_menu.y_oznaceni);
				std::cout << char(187);
			}
			if (j == 2 && i == 0)
			{
				navod_menu.setCursorPosition(navod_menu.x_oznaceni, navod_menu.y_oznaceni + 2);
				std::cout << char(200);
			}
			if (j == 2 && i == 7)
			{
				navod_menu.setCursorPosition(navod_menu.x_oznaceni + 7, navod_menu.y_oznaceni + 2);
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
				navod_menu.setCursorPosition(navod_menu.x_oznaceni, navod_menu.y_oznaceni);
				std::cout << ' ';
			}
			if (i == 7 && j == 0)
			{
				navod_menu.setCursorPosition(navod_menu.x_oznaceni + 7, navod_menu.y_oznaceni);
				std::cout << ' ';
			}
			if (i == 0 && j == 2)
			{
				navod_menu.setCursorPosition(navod_menu.x_oznaceni, navod_menu.y_oznaceni + 2);
				std::cout << ' ';
			}
			if (i == 7 && j == 2)
			{
				navod_menu.setCursorPosition(navod_menu.x_oznaceni + 7, navod_menu.y_oznaceni + 2);
				std::cout << ' ';
			}
		}
	}
}

void vykresleni_menu_start(Menu navod_menu, Pong navod)
{
	navod_menu.setCursorPosition(0, 0);
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
}
void vykresleni_uroven(Menu navod_menu, Pong navod)
{
	if (!navod_menu.jazyk)
	{
		navod_menu.setCursorPosition(27, 17);
		std::cout << navod_menu.odchod6CZ << navod_menu.level;
	}
	else
	{
		navod_menu.setCursorPosition(27, 17);
		std::cout << navod_menu.odchod6EN << navod_menu.level;
	}
	for (int i = 0; i < navod_menu.exp; i++)
	{
		navod.exp_pole.push_back(2);
	}
	for (int i = 0; i < 20 - navod_menu.exp; i++)
	{
		navod.exp_pole.push_back(0);
	}
	navod_menu.setCursorPosition(17, 18);
	for (int i = 0; i < navod.exp_pole.size(); i++)
	{
		if (navod.exp_pole.at(i) == 2)
			std::cout << char(219);
		if (navod.exp_pole.at(i) == 0)
			std::cout << char(176);
	}
}
void smazani_menu(Menu navod_menu)
{
	navod_menu.setCursorPosition(0, 0);
	for (int i = 0; i < 40; i++)
	{
		std::cout << " ";
	}
}

/////////////////////    Menu logika    //////////////////////////

void menu_herni_mody(Menu& navod_menu, Pong& navod)
{
	prechod(navod_menu);
	vykresleni_menu_start(navod_menu, navod);
	vykresleni_uroven(navod_menu, navod);
	navod_menu = vykresleni_herni_mody(navod_menu);
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
	prechod(navod_menu);
	vykresleni_menu_start(navod_menu, navod);
	vykresleni_uroven(navod_menu, navod);
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
			switch (navod_menu.rozhodovac(2, navod_menu.plosina_skin, navod_menu.jazyk))
			{
				case '-1':
				{
					if (!navod_menu.jazyk)
					{
						navod_menu.setCursorPosition(8, 7);
						std::cout << navod_menu.neodemcenoCZ << navod_menu.potr_urov1;
					}
					else
					{
						navod_menu.setCursorPosition(9, 7);
						std::cout << navod_menu.neodemcenoEN << navod_menu.potr_urov1;
					}
					navod_menu.exit = 1;
				}
				case '-2':
				{
					if (!navod_menu.jazyk)
					{
						navod_menu.setCursorPosition(8, 7);
						std::cout << navod_menu.neodemcenoCZ << navod_menu.potr_urov2;
					}
					else
					{
						navod_menu.setCursorPosition(9, 7);
						std::cout << navod_menu.neodemcenoEN << navod_menu.potr_urov2;
					}
				}
				case '-3':
				{
					if (!navod_menu.jazyk)
					{
						navod_menu.setCursorPosition(8, 7);
						std::cout << navod_menu.neodemcenoCZ << navod_menu.potr_urov3;
					}
					else
					{
						navod_menu.setCursorPosition(9, 7);
						std::cout << navod_menu.neodemcenoEN << navod_menu.potr_urov3;
					}
				}
				case '-4':
					{
					if (!navod_menu.jazyk)
					{
						navod_menu.setCursorPosition(8, 7);
						std::cout << navod_menu.neodemcenoCZ << navod_menu.potr_urov4;
					}
					else
					{
						navod_menu.setCursorPosition(9, 7);
						std::cout << navod_menu.neodemcenoEN << navod_menu.potr_urov4;
					}
				}
				case '-5':
				{
					if (!navod_menu.jazyk)
					{
						navod_menu.setCursorPosition(8, 7);
						std::cout << navod_menu.neodemcenoCZ << navod_menu.potr_urov5;
					}
					else
					{
						navod_menu.setCursorPosition(9, 7);
						std::cout << navod_menu.neodemcenoEN << navod_menu.potr_urov5;
					}
				}
			}
			navod_menu.exit = 1;
		}
	}
}

void menu_ovladani(Menu& navod_menu, Pong& navod)
{
	prechod(navod_menu);
	vykresleni_menu_start(navod_menu, navod);
	vykresleni_uroven(navod_menu, navod);
	navod_menu = vykresleni_ovladani(navod_menu);
	navod_menu.exit = 0;
	navod_menu.enter = 0;

	while (!navod_menu.exit)
	{
		vykresleni_tecka(navod_menu);
		while (!_kbhit());
		smazani_tecka(navod_menu);
		vstup_menu(navod_menu, navod, 4);
		if (navod_menu.enter == 1)
		{
			navod_menu.rozhodovac(3, navod_menu.plosina_skin, navod_menu.jazyk);
			navod_menu.exit = 1;
		}
	}
}
void menu_nastaveni(Menu& navod_menu, Pong& navod)
{
	prechod(navod_menu);
	vykresleni_menu_start(navod_menu, navod);
	vykresleni_uroven(navod_menu, navod);
	navod_menu = vykresleni_nastaveni(navod_menu);
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
			if (navod_menu.rozhodovac(3, navod_menu.plosina_skin, navod_menu.jazyk) == -1)
			{
				menu_ovladani(navod_menu, navod);
				navod_menu.exit = 1;
			}
		}
		if (navod_menu.balic)
		{
			navod_menu = vykresleni_nastaveni(navod_menu);
			navod_menu.balic = 0;
		}
	}
}

void menu_hlavni(Menu& navod_menu, Pong& navod)
{
	prechod(navod_menu);
	font(0, 20);
	SetWindow(navod_menu.delka_menu, navod_menu.vyska_menu - 2);

	vykresleni_menu_start(navod_menu, navod);
	vykresleni_logo(navod_menu);
	vykresleni_uroven(navod_menu, navod);
	navod_menu = vykresleni_hlavni(navod_menu);
	navod_menu.exit = 0;
	navod_menu.enter = 0;
	navod_menu.del = 0;

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
void menu_profil(Menu& navod_menu, Pong& navod)
{
	prechod(navod_menu);
	font(0, 20);
	SetWindow(navod_menu.delka_menu, navod_menu.vyska_menu - 2);

	navod_menu.nacteni_vyberu_profilu();
	vektor_na_string(navod_menu, navod_menu.nazev_profil0, navod_menu.nazev_profil1, navod_menu.nazev_profil2);
	vykresleni_menu_start(navod_menu, navod);
	navod_menu = vykresleni_profil(navod_menu);
	navod_menu.exit = 0;
	navod_menu.enter = 0;
	navod_menu.del = 0;
	navod_menu.zmena_jazyka = 0;
	navod.program = 1;

	while (!navod_menu.exit)
	{
		std::string nazev;
		bool jazyk_profil = navod_menu.jazyk;

		vykresleni_tecka(navod_menu);
		while (!_kbhit()); 
		smazani_tecka(navod_menu);
		vstup_menu(navod_menu, navod, -1);
		if (navod_menu.enter || navod_menu.del)
		{
			if (navod_menu.del)
			{
				vykresleni_otazka(navod_menu);
				while (!_kbhit());
				vstup_menu(navod_menu, navod, -1);
				smazani_otazka(navod_menu);
			}
			if (navod_menu.rozhodovac(-1, navod_menu.plosina_skin, navod_menu.jazyk) == 2)
			{
				if (navod_menu.enter)
				{
					if (navod_menu.pouzit == 0)
					{
						if (jazyk_profil != navod_menu.jazyk)
							navod_menu.jazyk = jazyk_profil;
						vykresleni_nazev_profilu(navod_menu);

						navod_menu.nacteni_vyberu_profilu();

						navod_menu.setCursorPosition(10, 10);
						std::cin >> nazev;
						string_na_vektor(navod_menu, nazev);
						navod_menu.ulozeni_vyberu_profilu();
					}
					while (navod.program)
					{
						menu_hlavni(navod_menu, navod);
						navod_menu.ukladani_profilu();
						navod_menu.ulozeni_vyberu_profilu();
						navod_menu.exit = 1;
					}
				}
			}
			else
			{
				navod_menu.exit = 1;
			}
			navod_menu.ulozeni_vyberu_profilu();
		}
	}
}

int main()
{
	Menu navod_menu;
	Pong navod;
	/*
	profil_vyber profil;
	profil.vytvoreni_noveho_profilu();*/
	while (navod.program)
	{
		//klasik(navod_menu);
		menu_profil(navod_menu, navod);
	}
}
/// bombu chvili ukazat