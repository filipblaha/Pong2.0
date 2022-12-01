#pragma once
#include <iostream>
#include <vector>
#include <fcntl.h>
#include <io.h> // graficke knihovny

class Pong
{
public:
	bool program = 1;
	bool pokracovani = 1;
	bool ztrata_zivotu = 0;
	bool power_up = 0;
	bool slow = 0;
	bool trvani = 0;
	bool bomba = 0;
	bool bomba_pocitadlo = 0;

	const wchar_t* zed = L"\x2588";
	const wchar_t* blok1 = L"\x2591";
	const wchar_t* blok2 = L"\x2592";
	const wchar_t* blok3 = L"\x2593";
	const wchar_t* mic_skin = L"\x058e";
	const wchar_t* bomba_skin = L"\x263c"; //L"\x047a"  L"\x058e"  L"\x263c"  x03b8
	const wchar_t* bomba_skin_start = L"\x25cc";
	const wchar_t* slow_skin = L"\x25ca";

	int DELKA = 20;
	int VYSKA = 20;
	int velikost_plosina = 6;
	int x_plosina = (DELKA - velikost_plosina) / 2;

	int pohyb = 0;
	int ax_mic = 1;
	int ay_mic = -1;
	int x_mic = DELKA / 2;
	int y_mic = VYSKA - 5;
	int ax_bomba = 0;
	int ay_bomba = 0;
	int x_bomba = DELKA / 2;
	int y_bomba = VYSKA - 8;
	int x_powerup = y_mic;
	int y_powerup = x_mic;

	int pocet_bloku = 0;
	int pocet_vykresleni = 0;
	int pocet_rozbitych_bloku = 0;
	int pocet_trvani_power_up = 0;

	int cas = 0;
	int bomba_zacatek = 0;
	int rychlost_hry = 2;
	int rychlost_plosiny = 2;
	int padani = 0;
	int zivoty = 0;
	int n_exp = 0;

	std::vector<std::vector<int>> bloky;
	std::vector<std::vector<int>> zasobnik;
	std::vector<int> docas;
	std::vector<int> exp_pole;

	void bloky_vytvoreni_klasik()
	{
		for (int j = 0; j < VYSKA + 1; j++)
		{
			docas.clear();
			for (int i = 0; i < DELKA + 1; i++)
			{
				if (i != 0 && i != DELKA - 1 && j > 0 && j < 7 && ((i % 3 == 0 && i < 10) || (i % 3 == 1 && i >= 10)))
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
};