#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

#include "Pong.h"

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
	bool vytazeno = 0;
	bool balic = 0;

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

	char pohyb_vpravo = 'd';
	char pohyb_vlevo = 'a';
	char pauza = char(27);
	char pouziti_schopnosti = ' ';

	std::vector<char> pole_skin;


	void setCursorPosition(int x, int y)
	{
		static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout.flush();
		COORD coord = { (SHORT)x, (SHORT)y };
		SetConsoleCursorPosition(hOut, coord);
	}

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
	std::string jazykEN = "Language";
	std::string ceskyCZ = "Cesky";
	std::string ceskyEN = "Czech";
	std::string anglickyCZ = "Anglicky";
	std::string anglickyEN = "English";
	std::string ovladaniCZ = "Ovladani";
	std::string ovladaniEN = "Controls";
	std::string OVLADANICZ = "OVLADANI";
	std::string OVLADANIEN = "CONTROLS";

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

	std::string ovladani_menuCZ = "Ovladani v menu";
	std::string ovladani_menuEN = "Menu controls";
	std::string ovladani_hraCZ = "Ovladani ve hre";
	std::string ovladani_hraEN = "In-game controls";
	std::string ovladani_mezernikCZ = "Mezernik";
	std::string ovladani_mezernikEN = "Spacebar";
	std::string ovladani_schopnostCZ = "Pouzit schopnost";
	std::string ovladani_schopnostEN = "Use ability";
	std::string ovladani_pohyb_vlevoCZ = "Pohyb - vlevo";
	std::string ovladani_pohyb_vlevoEN = "Movement - left";
	std::string ovladani_pohyb_vpravoCZ = "Pohyb - vpravo";
	std::string ovladani_pohyb_vpravoEN = "Movement - right";
	std::string ovladani_pauzaCZ = "Pauza";
	std::string ovladani_pauzaEN = "Pause";

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
			if (y_tecka == 8)
			{
				return -1;
			}
			if (y_tecka == 10)
			{
				exit = 0;
				if (vytazeno)
					vytazeno = 0;
				else
					vytazeno = 1;
				return balic = 1;
			}
			if (y_tecka == 12)
			{
				vytazeno = 0;
				exit = 1;
				return jazyk_zmena = 0;
			}
			if (y_tecka == 14)
			{
				vytazeno = 0;
				exit = 1;
				return jazyk_zmena = 1;
			}
		}
	}
};

