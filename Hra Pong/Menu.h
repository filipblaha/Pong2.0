#pragma once
#include <iostream>
#include <vector>
#include <conio.h>

#ifndef WIN32_LEAN_AND_MEAN // xml a windows.h nejdou do sebe, tohle to vyresi
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

#include "Pong.h"
#include "tinyxml2.h"

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace tinyxml2;

class profil0
{
public:
	XMLDocument xmlDoc;
	int jazyk_s;
	int plosina_skin_s;
	int highscore_cas_s;
	int highscore_znicenych_bloku_s;
	int level_s;
	int exp_s;

	int vytvoreni_noveho_profilu()
	{
		XMLNode* pRoot = xmlDoc.NewElement("Profil");
		xmlDoc.InsertFirstChild(pRoot);

		XMLElement* pElement1 = xmlDoc.NewElement("jazyk");
		pElement1->SetText(0);
		pRoot->InsertEndChild(pElement1);

		XMLElement* pElement2 = xmlDoc.NewElement("plosina_skin");
		pElement2->SetText(0);
		pRoot->InsertEndChild(pElement2);


		XMLElement* pElement3 = xmlDoc.NewElement("highscore_cas");
		pElement3->SetText(0);
		pRoot->InsertEndChild(pElement3);

		XMLElement* pElement4 = xmlDoc.NewElement("highscore_znicenych_bloku");
		pElement4->SetText(0);
		pRoot->InsertEndChild(pElement4);

		XMLElement* pElement5 = xmlDoc.NewElement("level");
		pElement5->SetText(0);
		pRoot->InsertEndChild(pElement5);

		XMLElement* pElement6 = xmlDoc.NewElement("exp");
		pElement6->SetText(0);
		pRoot->InsertEndChild(pElement6);

		XMLError eResult = xmlDoc.SaveFile("profil0.xml");
		XMLCheckResult(eResult);
	}
	int nacteni_profilu()
	{
		XMLError eResult = xmlDoc.LoadFile("profil0.xml");
		XMLCheckResult(eResult);

		XMLNode* pRoot = xmlDoc.FirstChild();
		if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;

		XMLElement* pElement0 = pRoot->FirstChildElement("jazyk"); //nalezeni int value
		if (pElement0 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement0->QueryIntText(&jazyk_s); // vyndani int
		XMLCheckResult(eResult);

		XMLElement* pElement1 = pRoot->FirstChildElement("plosina_skin");
		if (pElement1 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement1->QueryIntText(&plosina_skin_s);
		XMLCheckResult(eResult);

		XMLElement* pElement2 = pRoot->FirstChildElement("highscore_cas");
		if (pElement2 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement2->QueryIntText(&highscore_cas_s);
		XMLCheckResult(eResult);

		XMLElement* pElement3 = pRoot->FirstChildElement("highscore_znicenych_bloku");
		if (pElement3 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement3->QueryIntText(&highscore_znicenych_bloku_s);
		XMLCheckResult(eResult);

		XMLElement* pElement4 = pRoot->FirstChildElement("level");
		if (pElement4 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement4->QueryIntText(&level_s);
		XMLCheckResult(eResult);

		XMLElement* pElement5 = pRoot->FirstChildElement("exp");
		if (pElement5 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement5->QueryIntText(&exp_s);
		XMLCheckResult(eResult);
		return XML_SUCCESS;
	}
};
class profil1
{
public:
	XMLDocument xmlDoc;
	int jazyk_s;
	int plosina_skin_s;
	int highscore_cas_s;
	int highscore_znicenych_bloku_s;
	int level_s;
	int exp_s;

	int vytvoreni_noveho_profilu()
	{
		XMLNode* pRoot = xmlDoc.NewElement("Profil");
		xmlDoc.InsertFirstChild(pRoot);

		XMLElement* pElement1 = xmlDoc.NewElement("jazyk");
		pElement1->SetText(0);
		pRoot->InsertEndChild(pElement1);

		XMLElement* pElement2 = xmlDoc.NewElement("plosina_skin");
		pElement2->SetText(0);
		pRoot->InsertEndChild(pElement2);


		XMLElement* pElement3 = xmlDoc.NewElement("highscore_cas");
		pElement3->SetText(0);
		pRoot->InsertEndChild(pElement3);

		XMLElement* pElement4 = xmlDoc.NewElement("highscore_znicenych_bloku");
		pElement4->SetText(0);
		pRoot->InsertEndChild(pElement4);

		XMLElement* pElement5 = xmlDoc.NewElement("level");
		pElement5->SetText(0);
		pRoot->InsertEndChild(pElement5);

		XMLElement* pElement6 = xmlDoc.NewElement("exp");
		pElement6->SetText(0);
		pRoot->InsertEndChild(pElement6);

		XMLError eResult = xmlDoc.SaveFile("profil1.xml");
		XMLCheckResult(eResult);
	}
	int nacteni_profilu()
	{
		XMLError eResult = xmlDoc.LoadFile("profil1.xml");
		XMLCheckResult(eResult);

		XMLNode* pRoot = xmlDoc.FirstChild();
		if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;

		XMLElement* pElement0 = pRoot->FirstChildElement("jazyk"); //nalezeni int value
		if (pElement0 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement0->QueryIntText(&jazyk_s); // vyndani int
		XMLCheckResult(eResult);

		XMLElement* pElement1 = pRoot->FirstChildElement("plosina_skin");
		if (pElement1 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement1->QueryIntText(&plosina_skin_s);
		XMLCheckResult(eResult);

		XMLElement* pElement2 = pRoot->FirstChildElement("highscore_cas");
		if (pElement2 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement2->QueryIntText(&highscore_cas_s);
		XMLCheckResult(eResult);

		XMLElement* pElement3 = pRoot->FirstChildElement("highscore_znicenych_bloku");
		if (pElement3 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement3->QueryIntText(&highscore_znicenych_bloku_s);
		XMLCheckResult(eResult);

		XMLElement* pElement4 = pRoot->FirstChildElement("level");
		if (pElement4 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement4->QueryIntText(&level_s);
		XMLCheckResult(eResult);

		XMLElement* pElement5 = pRoot->FirstChildElement("exp");
		if (pElement5 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement5->QueryIntText(&exp_s);
		XMLCheckResult(eResult);
		return XML_SUCCESS;
	}
};
class profil2
{
public:
	XMLDocument xmlDoc;
	int jazyk_s;
	int plosina_skin_s;
	int highscore_cas_s;
	int highscore_znicenych_bloku_s;
	int level_s;
	int exp_s;

	int vytvoreni_noveho_profilu()
	{
		XMLNode* pRoot = xmlDoc.NewElement("Profil");
		xmlDoc.InsertFirstChild(pRoot);

		XMLElement* pElement1 = xmlDoc.NewElement("jazyk");
		pElement1->SetText(0);
		pRoot->InsertEndChild(pElement1);

		XMLElement* pElement2 = xmlDoc.NewElement("plosina_skin");
		pElement2->SetText(0);
		pRoot->InsertEndChild(pElement2);


		XMLElement* pElement3 = xmlDoc.NewElement("highscore_cas");
		pElement3->SetText(0);
		pRoot->InsertEndChild(pElement3);

		XMLElement* pElement4 = xmlDoc.NewElement("highscore_znicenych_bloku");
		pElement4->SetText(0);
		pRoot->InsertEndChild(pElement4);

		XMLElement* pElement5 = xmlDoc.NewElement("level");
		pElement5->SetText(0);
		pRoot->InsertEndChild(pElement5);

		XMLElement* pElement6 = xmlDoc.NewElement("exp");
		pElement6->SetText(0);
		pRoot->InsertEndChild(pElement6);

		XMLError eResult = xmlDoc.SaveFile("profil2.xml");
		XMLCheckResult(eResult);
	}
	int nacteni_profilu()
	{
		XMLError eResult = xmlDoc.LoadFile("profil2.xml");
		XMLCheckResult(eResult);

		XMLNode* pRoot = xmlDoc.FirstChild();
		if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;

		XMLElement* pElement0 = pRoot->FirstChildElement("jazyk"); //nalezeni int value
		if (pElement0 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement0->QueryIntText(&jazyk_s); // vyndani int
		XMLCheckResult(eResult);

		XMLElement* pElement1 = pRoot->FirstChildElement("plosina_skin");
		if (pElement1 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement1->QueryIntText(&plosina_skin_s);
		XMLCheckResult(eResult);

		XMLElement* pElement2 = pRoot->FirstChildElement("highscore_cas");
		if (pElement2 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement2->QueryIntText(&highscore_cas_s);
		XMLCheckResult(eResult);

		XMLElement* pElement3 = pRoot->FirstChildElement("highscore_znicenych_bloku");
		if (pElement3 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement3->QueryIntText(&highscore_znicenych_bloku_s);
		XMLCheckResult(eResult);

		XMLElement* pElement4 = pRoot->FirstChildElement("level");
		if (pElement4 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement4->QueryIntText(&level_s);
		XMLCheckResult(eResult);

		XMLElement* pElement5 = pRoot->FirstChildElement("exp");
		if (pElement5 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement5->QueryIntText(&exp_s);
		XMLCheckResult(eResult);
		return XML_SUCCESS;
	}
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
	bool vytazeno = 0;
	bool balic = 0;

	int jazyk = 0;
	int plosina_skin = 0;
	int highscore_cas = 0;
	int highscore_znicenych_bloku = 0;
	int level = 0;
	int exp = 0;
	int profil_probiha = 0;

	void vyber_profilu(int vybrany_profil)
	{
		if (vybrany_profil == 0)
		{
			profil_probiha = 0;

			profil0 profil;
			profil.nacteni_profilu();
			jazyk = profil.jazyk_s;
			plosina_skin = profil.plosina_skin_s;
			highscore_cas = profil.highscore_cas_s;
			highscore_znicenych_bloku = profil.highscore_znicenych_bloku_s;
			level = profil.level_s;
			exp = profil.exp_s;
		}
		if (vybrany_profil == 1)
		{
			profil_probiha = 1;

			profil1 profil;
			profil.nacteni_profilu();
			jazyk = profil.jazyk_s;
			plosina_skin = profil.plosina_skin_s;
			highscore_cas = profil.highscore_cas_s;
			highscore_znicenych_bloku = profil.highscore_znicenych_bloku_s;
			level = profil.level_s;
			exp = profil.exp_s;
		}
		if (vybrany_profil == 2)
		{
			profil_probiha = 2;

			profil2 profil;
			profil.nacteni_profilu();
			jazyk = profil.jazyk_s;
			plosina_skin = profil.plosina_skin_s;
			highscore_cas = profil.highscore_cas_s;
			highscore_znicenych_bloku = profil.highscore_znicenych_bloku_s;
			level = profil.level_s;
			exp = profil.exp_s;
		}
	}
	
	int jazyk_s;
	int plosina_skin_s;
	int highscore_cas_s;
	int highscore_znicenych_bloku_s;
	int level_s;
	int exp_s;

	int ukladani_profilu()
	{
		XMLDocument xmlDoc;
		if (profil_probiha == 0)
		{
			XMLNode* pRoot = xmlDoc.NewElement("Profil");
			xmlDoc.InsertFirstChild(pRoot);

			XMLElement* pElement1 = xmlDoc.NewElement("jazyk");
			pElement1->SetText(jazyk);
			pRoot->InsertEndChild(pElement1);

			XMLElement* pElement2 = xmlDoc.NewElement("plosina_skin");
			pElement2->SetText(plosina_skin);
			pRoot->InsertEndChild(pElement2);


			XMLElement* pElement3 = xmlDoc.NewElement("highscore_cas");
			pElement3->SetText(highscore_cas);
			pRoot->InsertEndChild(pElement3);

			XMLElement* pElement4 = xmlDoc.NewElement("highscore_znicenych_bloku");
			pElement4->SetText(highscore_znicenych_bloku);
			pRoot->InsertEndChild(pElement4);

			XMLElement* pElement5 = xmlDoc.NewElement("level");
			pElement5->SetText(level);
			pRoot->InsertEndChild(pElement5);

			XMLElement* pElement6 = xmlDoc.NewElement("exp");
			pElement6->SetText(exp);
			pRoot->InsertEndChild(pElement6);

			XMLError eResult = xmlDoc.SaveFile("profil0.xml");
			XMLCheckResult(eResult);
		}
		if (profil_probiha == 1)
		{
			XMLNode* pRoot = xmlDoc.NewElement("Profil");
			xmlDoc.InsertFirstChild(pRoot);

			XMLElement* pElement1 = xmlDoc.NewElement("jazyk");
			pElement1->SetText(jazyk);
			pRoot->InsertEndChild(pElement1);

			XMLElement* pElement2 = xmlDoc.NewElement("plosina_skin");
			pElement2->SetText(plosina_skin);
			pRoot->InsertEndChild(pElement2);


			XMLElement* pElement3 = xmlDoc.NewElement("highscore_cas");
			pElement3->SetText(highscore_cas);
			pRoot->InsertEndChild(pElement3);

			XMLElement* pElement4 = xmlDoc.NewElement("highscore_znicenych_bloku");
			pElement4->SetText(highscore_znicenych_bloku);
			pRoot->InsertEndChild(pElement4);

			XMLElement* pElement5 = xmlDoc.NewElement("level");
			pElement5->SetText(level);
			pRoot->InsertEndChild(pElement5);

			XMLElement* pElement6 = xmlDoc.NewElement("exp");
			pElement6->SetText(exp);
			pRoot->InsertEndChild(pElement6);

			XMLError eResult = xmlDoc.SaveFile("profil1.xml");
			XMLCheckResult(eResult);
		}
		if (profil_probiha == 2)
		{
			XMLNode* pRoot = xmlDoc.NewElement("Profil");
			xmlDoc.InsertFirstChild(pRoot);

			XMLElement* pElement1 = xmlDoc.NewElement("jazyk");
			pElement1->SetText(jazyk);
			pRoot->InsertEndChild(pElement1);

			XMLElement* pElement2 = xmlDoc.NewElement("plosina_skin");
			pElement2->SetText(plosina_skin);
			pRoot->InsertEndChild(pElement2);


			XMLElement* pElement3 = xmlDoc.NewElement("highscore_cas");
			pElement3->SetText(highscore_cas);
			pRoot->InsertEndChild(pElement3);

			XMLElement* pElement4 = xmlDoc.NewElement("highscore_znicenych_bloku");
			pElement4->SetText(highscore_znicenych_bloku);
			pRoot->InsertEndChild(pElement4);

			XMLElement* pElement5 = xmlDoc.NewElement("level");
			pElement5->SetText(level);
			pRoot->InsertEndChild(pElement5);

			XMLElement* pElement6 = xmlDoc.NewElement("exp");
			pElement6->SetText(exp);
			pRoot->InsertEndChild(pElement6);

			XMLError eResult = xmlDoc.SaveFile("profil2.xml");
			XMLCheckResult(eResult);
		}
	}

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
	
	std::string vyber_profiluCZ = "Vyber si svuj profil";
	std::string vyber_profiluEN = "Choose your profile";
	std::string novy_profilCZ = "Novy profil";
	std::string novy_profilEN = "New profile";
	std::string muj_profilCZ = "Muj profil";
	std::string muj_profilEN = "My profile";
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
		/////////////////////    Profily     //////////////////////////
		if (strana == -1)
		{
			if (y_tecka == 10)
				vyber_profilu(0);
			if (y_tecka == 12)
				vyber_profilu(1);
			if (y_tecka == 14)
				vyber_profilu(2);
		}

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