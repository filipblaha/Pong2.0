#pragma once
#include <iostream>
#include <vector>
#include <conio.h>

#ifndef WIN32_LEAN_AND_MEAN // xml a windows.h nejdou do sebe, tohle to vyresi
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

#include <fcntl.h>
#include <io.h> // graficke knihovny

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
	int pouzit_s = 0;
	int jazyk_s = 0;
	int plosina_skin_s = 0;
	int highscore_cas_s = 0;
	int highscore_znicenych_bloku_s = 0;
	int level_s = 0;
	int exp_s = 0;

	int pohyb_vlevo_s = 68;
	int pohyb_vpravo_s = 65;
	int pouziti_schopnosti_s = 32;
	int pauza_s = 27;

	int vytvoreni_noveho_profilu()
	{
		XMLNode* pRoot = xmlDoc.NewElement("Profil");
		xmlDoc.InsertFirstChild(pRoot);

		XMLElement* pElement0 = xmlDoc.NewElement("pouzit");
		pElement0->SetText(0);
		pRoot->InsertEndChild(pElement0);

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

		XMLElement* pElement7 = xmlDoc.NewElement("pohyb_vlevo");
		pElement7->SetText(68);
		pRoot->InsertEndChild(pElement7);

		XMLElement* pElement8 = xmlDoc.NewElement("pohyb_vpravo");
		pElement8->SetText(65);
		pRoot->InsertEndChild(pElement8);

		XMLElement* pElement9 = xmlDoc.NewElement("pouziti_schopnosti");
		pElement9->SetText(32);
		pRoot->InsertEndChild(pElement9);

		XMLElement* pElement10 = xmlDoc.NewElement("pauza");
		pElement10->SetText(27);
		pRoot->InsertEndChild(pElement10);

		XMLError eResult = xmlDoc.SaveFile("profil0.xml");
		XMLCheckResult(eResult);
	}
	int nacteni_profilu()
	{
		XMLError eResult = xmlDoc.LoadFile("profil0.xml");
		XMLCheckResult(eResult);

		XMLNode* pRoot = xmlDoc.FirstChild();
		if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;

		XMLElement* pElement0 = pRoot->FirstChildElement("pouzit"); //nalezeni int value
		if (pElement0 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement0->QueryIntText(&pouzit_s); // vyndani int
		XMLCheckResult(eResult);

		XMLElement* pElement1 = pRoot->FirstChildElement("jazyk");
		if (pElement1 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement1->QueryIntText(&jazyk_s);
		XMLCheckResult(eResult);

		XMLElement* pElement2 = pRoot->FirstChildElement("plosina_skin");
		if (pElement2 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement2->QueryIntText(&plosina_skin_s);
		XMLCheckResult(eResult);

		XMLElement* pElement3 = pRoot->FirstChildElement("highscore_cas");
		if (pElement3 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement3->QueryIntText(&highscore_cas_s);
		XMLCheckResult(eResult);

		XMLElement* pElement4 = pRoot->FirstChildElement("highscore_znicenych_bloku");
		if (pElement4 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement4->QueryIntText(&highscore_znicenych_bloku_s);
		XMLCheckResult(eResult);

		XMLElement* pElement5 = pRoot->FirstChildElement("level");
		if (pElement5 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement5->QueryIntText(&level_s);
		XMLCheckResult(eResult);

		XMLElement* pElement6 = pRoot->FirstChildElement("exp");
		if (pElement6 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement6->QueryIntText(&exp_s);
		XMLCheckResult(eResult);

		XMLElement* pElement7 = pRoot->FirstChildElement("pohyb_vlevo");
		if (pElement7 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement7->QueryIntText(&pohyb_vlevo_s);
		XMLCheckResult(eResult);

		XMLElement* pElement8 = pRoot->FirstChildElement("pohyb_vpravo");
		if (pElement8 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement8->QueryIntText(&pohyb_vpravo_s);
		XMLCheckResult(eResult);

		XMLElement* pElement9 = pRoot->FirstChildElement("pouziti_schopnosti");
		if (pElement9 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement9->QueryIntText(&pouziti_schopnosti_s);
		XMLCheckResult(eResult);

		XMLElement* pElement10 = pRoot->FirstChildElement("pauza");
		if (pElement10 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement10->QueryIntText(&pauza_s);
		XMLCheckResult(eResult);

		return XML_SUCCESS;
	}
};
class profil1
{
public:
	XMLDocument xmlDoc;
	int pouzit_s = 0;
	int jazyk_s = 0;
	int plosina_skin_s = 0;
	int highscore_cas_s = 0;
	int highscore_znicenych_bloku_s = 0;
	int level_s = 0;
	int exp_s = 0;


	int pohyb_vlevo_s = 68;
	int pohyb_vpravo_s = 65;
	int pouziti_schopnosti_s = 32;
	int pauza_s = 27;

	int vytvoreni_noveho_profilu()
	{
		XMLNode* pRoot = xmlDoc.NewElement("Profil");
		xmlDoc.InsertFirstChild(pRoot);

		XMLElement* pElement0 = xmlDoc.NewElement("pouzit");
		pElement0->SetText(0);
		pRoot->InsertEndChild(pElement0);

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

		XMLElement* pElement7 = xmlDoc.NewElement("pohyb_vlevo");
		pElement7->SetText(68);
		pRoot->InsertEndChild(pElement7);

		XMLElement* pElement8 = xmlDoc.NewElement("pohyb_vpravo");
		pElement8->SetText(65);
		pRoot->InsertEndChild(pElement8);

		XMLElement* pElement9 = xmlDoc.NewElement("pouziti_schopnosti");
		pElement9->SetText(32);
		pRoot->InsertEndChild(pElement9);

		XMLElement* pElement10 = xmlDoc.NewElement("pauza");
		pElement10->SetText(27);
		pRoot->InsertEndChild(pElement10);

		XMLError eResult = xmlDoc.SaveFile("profil1.xml");
		XMLCheckResult(eResult);
	}
	int nacteni_profilu()
	{
		XMLError eResult = xmlDoc.LoadFile("profil1.xml");
		XMLCheckResult(eResult);

		XMLNode* pRoot = xmlDoc.FirstChild();
		if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;

		XMLElement* pElement0 = pRoot->FirstChildElement("pouzit"); //nalezeni int value
		if (pElement0 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement0->QueryIntText(&pouzit_s); // vyndani int
		XMLCheckResult(eResult);

		XMLElement* pElement1 = pRoot->FirstChildElement("jazyk");
		if (pElement1 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement1->QueryIntText(&jazyk_s);
		XMLCheckResult(eResult);

		XMLElement* pElement2 = pRoot->FirstChildElement("plosina_skin");
		if (pElement2 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement2->QueryIntText(&plosina_skin_s);
		XMLCheckResult(eResult);

		XMLElement* pElement3 = pRoot->FirstChildElement("highscore_cas");
		if (pElement3 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement3->QueryIntText(&highscore_cas_s);
		XMLCheckResult(eResult);

		XMLElement* pElement4 = pRoot->FirstChildElement("highscore_znicenych_bloku");
		if (pElement4 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement4->QueryIntText(&highscore_znicenych_bloku_s);
		XMLCheckResult(eResult);

		XMLElement* pElement5 = pRoot->FirstChildElement("level");
		if (pElement5 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement5->QueryIntText(&level_s);
		XMLCheckResult(eResult);

		XMLElement* pElement6 = pRoot->FirstChildElement("exp");
		if (pElement6 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement6->QueryIntText(&exp_s);
		XMLCheckResult(eResult);

		XMLElement* pElement7 = pRoot->FirstChildElement("pohyb_vlevo");
		if (pElement7 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement7->QueryIntText(&pohyb_vlevo_s);
		XMLCheckResult(eResult);

		XMLElement* pElement8 = pRoot->FirstChildElement("pohyb_vpravo");
		if (pElement8 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement8->QueryIntText(&pohyb_vpravo_s);
		XMLCheckResult(eResult);

		XMLElement* pElement9 = pRoot->FirstChildElement("pouziti_schopnosti");
		if (pElement9 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement9->QueryIntText(&pouziti_schopnosti_s);
		XMLCheckResult(eResult);

		XMLElement* pElement10 = pRoot->FirstChildElement("pauza");
		if (pElement10 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement10->QueryIntText(&pauza_s);
		XMLCheckResult(eResult);

		return XML_SUCCESS;
	}
};
class profil2
{
public:
	XMLDocument xmlDoc;
	int pouzit_s = 0;
	int jazyk_s = 0;
	int plosina_skin_s = 0;
	int highscore_cas_s = 0;
	int highscore_znicenych_bloku_s = 0;
	int level_s = 0;
	int exp_s = 0;


	int pohyb_vlevo_s = 68;
	int pohyb_vpravo_s = 65;
	int pouziti_schopnosti_s = 32;
	int pauza_s = 27;

	int vytvoreni_noveho_profilu()
	{
		XMLNode* pRoot = xmlDoc.NewElement("Profil");
		xmlDoc.InsertFirstChild(pRoot);

		XMLElement* pElement0 = xmlDoc.NewElement("pouzit");
		pElement0->SetText(0);
		pRoot->InsertEndChild(pElement0);

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

		XMLElement* pElement7 = xmlDoc.NewElement("pohyb_vlevo");
		pElement7->SetText(68);
		pRoot->InsertEndChild(pElement7);

		XMLElement* pElement8 = xmlDoc.NewElement("pohyb_vpravo");
		pElement8->SetText(65);
		pRoot->InsertEndChild(pElement8);

		XMLElement* pElement9 = xmlDoc.NewElement("pouziti_schopnosti");
		pElement9->SetText(32);
		pRoot->InsertEndChild(pElement9);

		XMLElement* pElement10 = xmlDoc.NewElement("pauza");
		pElement10->SetText(27);
		pRoot->InsertEndChild(pElement10);

		XMLError eResult = xmlDoc.SaveFile("profil2.xml");
		XMLCheckResult(eResult);
	}
	int nacteni_profilu()
	{
		XMLError eResult = xmlDoc.LoadFile("profil2.xml");
		XMLCheckResult(eResult);

		XMLNode* pRoot = xmlDoc.FirstChild();
		if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;

		XMLElement* pElement0 = pRoot->FirstChildElement("pouzit"); //nalezeni int value
		if (pElement0 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement0->QueryIntText(&pouzit_s); // vyndani int
		XMLCheckResult(eResult);

		XMLElement* pElement1 = pRoot->FirstChildElement("jazyk");
		if (pElement1 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement1->QueryIntText(&jazyk_s);
		XMLCheckResult(eResult);

		XMLElement* pElement2 = pRoot->FirstChildElement("plosina_skin");
		if (pElement2 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement2->QueryIntText(&plosina_skin_s);
		XMLCheckResult(eResult);

		XMLElement* pElement3 = pRoot->FirstChildElement("highscore_cas");
		if (pElement3 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement3->QueryIntText(&highscore_cas_s);
		XMLCheckResult(eResult);

		XMLElement* pElement4 = pRoot->FirstChildElement("highscore_znicenych_bloku");
		if (pElement4 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement4->QueryIntText(&highscore_znicenych_bloku_s);
		XMLCheckResult(eResult);

		XMLElement* pElement5 = pRoot->FirstChildElement("level");
		if (pElement5 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement5->QueryIntText(&level_s);
		XMLCheckResult(eResult);

		XMLElement* pElement6 = pRoot->FirstChildElement("exp");
		if (pElement6 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement6->QueryIntText(&exp_s);
		XMLCheckResult(eResult);

		XMLElement* pElement7 = pRoot->FirstChildElement("pohyb_vlevo");
		if (pElement7 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement7->QueryIntText(&pohyb_vlevo_s);
		XMLCheckResult(eResult);

		XMLElement* pElement8 = pRoot->FirstChildElement("pohyb_vpravo");
		if (pElement8 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement8->QueryIntText(&pohyb_vpravo_s);
		XMLCheckResult(eResult);

		XMLElement* pElement9 = pRoot->FirstChildElement("pouziti_schopnosti");
		if (pElement9 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement9->QueryIntText(&pouziti_schopnosti_s);
		XMLCheckResult(eResult);

		XMLElement* pElement10 = pRoot->FirstChildElement("pauza");
		if (pElement10 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement10->QueryIntText(&pauza_s);
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
	bool zmena_jazyka = 1;
	bool del = 0;
	
	int pouzit = 0;
	int jazyk = 0;
	int plosina_skin = 0;
	int highscore_cas = 0;
	int highscore_znicenych_bloku = 0;
	int level = 0;
	int exp = 0;
	int profil_probiha = 0;

	int pohyb_vlevo = 65;
	int pohyb_vpravo = 68;
	int pouziti_schopnosti = 32;
	int pauza = 27;

	int uroven_profil0 = 0;
	int uroven_profil1 = 0;
	int uroven_profil2 = 0;

	void vyber_profilu(int vybrany_profil)
	{
		if (vybrany_profil == 0)
		{
			profil_probiha = 0;

			profil0 profil;
			profil.nacteni_profilu();
			pouzit = profil.pouzit_s;
			jazyk = profil.jazyk_s;
			plosina_skin = profil.plosina_skin_s;
			highscore_cas = profil.highscore_cas_s;
			highscore_znicenych_bloku = profil.highscore_znicenych_bloku_s;
			level = profil.level_s;
			exp = profil.exp_s;
			pohyb_vlevo = profil.pohyb_vlevo_s;
			pohyb_vpravo = profil.pohyb_vpravo_s;
			pouziti_schopnosti = profil.pouziti_schopnosti_s;
			pauza = profil.pauza_s;
		}
		if (vybrany_profil == 1)
		{
			profil_probiha = 1;

			profil1 profil;
			profil.nacteni_profilu();
			pouzit = profil.pouzit_s;
			jazyk = profil.jazyk_s;
			plosina_skin = profil.plosina_skin_s;
			highscore_cas = profil.highscore_cas_s;
			highscore_znicenych_bloku = profil.highscore_znicenych_bloku_s;
			level = profil.level_s;
			exp = profil.exp_s;
			pohyb_vlevo = profil.pohyb_vlevo_s;
			pohyb_vpravo = profil.pohyb_vpravo_s;
			pouziti_schopnosti = profil.pouziti_schopnosti_s;
			pauza = profil.pauza_s;
		}
		if (vybrany_profil == 2)
		{
			profil_probiha = 2;

			profil2 profil;
			profil.nacteni_profilu();
			pouzit = profil.pouzit_s;
			jazyk = profil.jazyk_s;
			plosina_skin = profil.plosina_skin_s;
			highscore_cas = profil.highscore_cas_s;
			highscore_znicenych_bloku = profil.highscore_znicenych_bloku_s;
			level = profil.level_s;
			exp = profil.exp_s;
			pohyb_vlevo = profil.pohyb_vlevo_s;
			pohyb_vpravo = profil.pohyb_vpravo_s;
			pouziti_schopnosti = profil.pouziti_schopnosti_s;
			pauza = profil.pauza_s;
		}
	}
	int ukladani_profilu()
	{
		pouzit = 1;
		XMLDocument xmlDoc;
		if (profil_probiha == 0)
		{
			XMLNode* pRoot = xmlDoc.NewElement("Profil");
			xmlDoc.InsertFirstChild(pRoot);

			XMLElement* pElement0 = xmlDoc.NewElement("pouzit");
			pElement0->SetText(pouzit);
			pRoot->InsertEndChild(pElement0);

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

			XMLElement* pElement7 = xmlDoc.NewElement("pohyb_vlevo");
			pElement7->SetText(pohyb_vlevo);
			pRoot->InsertEndChild(pElement7);

			XMLElement* pElement8 = xmlDoc.NewElement("pohyb_vpravo");
			pElement8->SetText(pohyb_vpravo);
			pRoot->InsertEndChild(pElement8);

			XMLElement* pElement9 = xmlDoc.NewElement("pouziti_schopnosti");
			pElement9->SetText(pouziti_schopnosti);
			pRoot->InsertEndChild(pElement9);

			XMLElement* pElement10 = xmlDoc.NewElement("pauza");
			pElement10->SetText(pauza);
			pRoot->InsertEndChild(pElement10);

			XMLError eResult = xmlDoc.SaveFile("profil0.xml");
			XMLCheckResult(eResult);
		}
		if (profil_probiha == 1)
		{
			XMLNode* pRoot = xmlDoc.NewElement("Profil");
			xmlDoc.InsertFirstChild(pRoot);

			XMLElement* pElement0 = xmlDoc.NewElement("pouzit");
			pElement0->SetText(pouzit);
			pRoot->InsertEndChild(pElement0);


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

			XMLElement* pElement7 = xmlDoc.NewElement("pohyb_vlevo");
			pElement7->SetText(pohyb_vlevo);
			pRoot->InsertEndChild(pElement7);

			XMLElement* pElement8 = xmlDoc.NewElement("pohyb_vpravo");
			pElement8->SetText(pohyb_vpravo);
			pRoot->InsertEndChild(pElement8);

			XMLElement* pElement9 = xmlDoc.NewElement("pouziti_schopnosti");
			pElement9->SetText(pouziti_schopnosti);
			pRoot->InsertEndChild(pElement9);

			XMLElement* pElement10 = xmlDoc.NewElement("pauza");
			pElement10->SetText(pauza);
			pRoot->InsertEndChild(pElement10);

			XMLError eResult = xmlDoc.SaveFile("profil1.xml");
			XMLCheckResult(eResult);
		}
		if (profil_probiha == 2)
		{
			XMLNode* pRoot = xmlDoc.NewElement("Profil");
			xmlDoc.InsertFirstChild(pRoot);

			XMLElement* pElement0 = xmlDoc.NewElement("pouzit");
			pElement0->SetText(pouzit);
			pRoot->InsertEndChild(pElement0);


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

			XMLElement* pElement7 = xmlDoc.NewElement("pohyb_vlevo");
			pElement7->SetText(pohyb_vlevo);
			pRoot->InsertEndChild(pElement7);

			XMLElement* pElement8 = xmlDoc.NewElement("pohyb_vpravo");
			pElement8->SetText(pohyb_vpravo);
			pRoot->InsertEndChild(pElement8);

			XMLElement* pElement9 = xmlDoc.NewElement("pouziti_schopnosti");
			pElement9->SetText(pouziti_schopnosti);
			pRoot->InsertEndChild(pElement9);

			XMLElement* pElement10 = xmlDoc.NewElement("pauza");
			pElement10->SetText(pauza);
			pRoot->InsertEndChild(pElement10);

			XMLError eResult = xmlDoc.SaveFile("profil2.xml");
			XMLCheckResult(eResult);
		}
	}
	int nacteni_vyberu_profilu()
	{
		XMLDocument xmlDoc;
		XMLError eResult = xmlDoc.LoadFile("profil_vyber.xml");
		XMLCheckResult(eResult);

		XMLNode* pRoot = xmlDoc.FirstChild();
		if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;

		XMLElement* pElement0 = pRoot->FirstChildElement("profil0");
		if (pElement0 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		XMLElement* pListElement0 = pElement0->FirstChildElement("Item");
		nazev_profil0.clear();
		while (pListElement0 != nullptr)
		{
			int iOutListValue;
			eResult = pListElement0->QueryIntText(&iOutListValue);
			XMLCheckResult(eResult);

			nazev_profil0.push_back(iOutListValue);
			pListElement0 = pListElement0->NextSiblingElement("Item");
		}

		XMLElement* pElement1 = pRoot->FirstChildElement("profil1");
		if (pElement1 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		XMLElement* pListElement1 = pElement1->FirstChildElement("Item");
		nazev_profil1.clear();
		while (pListElement1 != nullptr)
		{
			int iOutListValue;
			eResult = pListElement1->QueryIntText(&iOutListValue);
			XMLCheckResult(eResult);

			nazev_profil1.push_back(iOutListValue);
			pListElement1 = pListElement1->NextSiblingElement("Item");
		}

		XMLElement* pElement2 = pRoot->FirstChildElement("profil2");
		if (pElement2 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		XMLElement* pListElement2 = pElement2->FirstChildElement("Item");
		nazev_profil2.clear();
		while (pListElement2 != nullptr)
		{
			int iOutListValue;
			eResult = pListElement2->QueryIntText(&iOutListValue);
			XMLCheckResult(eResult);

			nazev_profil2.push_back(iOutListValue);
			pListElement2 = pListElement2->NextSiblingElement("Item");
		}

		XMLElement* pElement3 = pRoot->FirstChildElement("uroven0");
		if (pElement3 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement3->QueryIntText(&uroven_profil0);
		XMLCheckResult(eResult);

		XMLElement* pElement4 = pRoot->FirstChildElement("uroven11");
		if (pElement4 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement4->QueryIntText(&uroven_profil1);
		XMLCheckResult(eResult);

		XMLElement* pElement5 = pRoot->FirstChildElement("uroven2");
		if (pElement5 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement5->QueryIntText(&uroven_profil2);
		XMLCheckResult(eResult);
		return XML_SUCCESS;
	}
	int ulozeni_vyberu_profilu()
	{
		XMLDocument xmlDoc;
		XMLNode* pRoot = xmlDoc.NewElement("Profil");
		xmlDoc.InsertFirstChild(pRoot);

		XMLElement* pElement0 = xmlDoc.NewElement("profil0");
		for (const auto& item : nazev_profil0)
		{
			XMLElement* pListElement0 = xmlDoc.NewElement("Item");
			pListElement0->SetText(item);

			pElement0->InsertEndChild(pListElement0);
		}
		pRoot->InsertEndChild(pElement0);

		XMLElement* pElement1 = xmlDoc.NewElement("profil1");
		for (const auto& item : nazev_profil1)
		{
			XMLElement* pListElement1 = xmlDoc.NewElement("Item");
			pListElement1->SetText(item);

			pElement1->InsertEndChild(pListElement1);
		}
		pRoot->InsertEndChild(pElement1);

		XMLElement* pElement2 = xmlDoc.NewElement("profil2");
		for (const auto& item : nazev_profil2)
		{
			XMLElement* pListElement2 = xmlDoc.NewElement("Item");
			pListElement2->SetText(item);

			pElement2->InsertEndChild(pListElement2);
		}
		pRoot->InsertEndChild(pElement2);

		if (profil_probiha == 0)
		{
			profil0 profil;
			uroven_profil0 = level;
		}
		if (profil_probiha == 1)
		{
			profil0 profil;
			uroven_profil1 = level;
		}
		if (profil_probiha == 2)
		{
			profil0 profil;
			uroven_profil2 = level;
		}

		XMLElement* pElement3 = xmlDoc.NewElement("uroven0");
		pElement3->SetText(uroven_profil0);
		pRoot->InsertEndChild(pElement3);

		XMLElement* pElement4 = xmlDoc.NewElement("uroven1");
		pElement4->SetText(uroven_profil1);
		pRoot->InsertEndChild(pElement4);

		XMLElement* pElement5 = xmlDoc.NewElement("uroven2");
		pElement5->SetText(uroven_profil2);
		pRoot->InsertEndChild(pElement5);

		XMLError eResult = xmlDoc.SaveFile("profil_vyber.xml");
		XMLCheckResult(eResult);
	}

	int pocet_zivotu = 2;
	int potr_urov1 = 1;
	int potr_urov2 = 2;
	int potr_urov3 = 3;
	int potr_urov4 = 4;
	int potr_urov5 = 5;

	std::vector<char> pole_skin;
	std::vector<char> nazev_profil0;
	std::vector<char> nazev_profil1;
	std::vector<char> nazev_profil2;

	std::vector<char> nazev_profil_novy;
	std::vector<char> vytvoreni_noveho_nazvu_profilu()
	{
		for (int i = 0; i < novy_profil.size(); i++)
		{
			nazev_profil_novy.push_back(novy_profil.at(i));
		}
		return nazev_profil_novy;

	}

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
			for (int i = 0; i < (int)pole_skin.size() / 2; i++)
			{
				pole_skin.at(i) = char(174);
			}
			for (int i = pole_skin.size() / 2; i < (int)pole_skin.size(); i++)
			{
				pole_skin.at(i) = char(175);
			}
		}
		if (plosina_skin == 5)
		{
				pole_skin;
		}
	}

	/////////////////////    Preklad     //////////////////////////
	
	std::wstring vyber_profiluCZ = L"Vyber si svuj profil";
	std::wstring vyber_profiluEN = L"Choose your profile";
	std::wstring profil1CZ = L"Profil 1";
	std::wstring profil1EN = L"Profile 1";
	std::wstring profil2CZ = L"Profil 2";
	std::wstring profil2EN = L"Profile 2";
	std::wstring profil3CZ = L"Profil 3";
	std::wstring profil3EN = L"Profile 3";
	std::wstring smazani_pokrokCZ = L"Smazat pokrok";
	std::wstring smazani_pokrokEN = L"Delete progress";
	std::wstring smazani_pokrok_otazka1CZ = L"Opravdu chcete smazat pokrok?";
	std::wstring smazani_pokrok_otazka1EN = L"Do you want to delete progress?";
	std::wstring smazani_pokrok_otazka2CZ = L"[ENTER]";
	std::wstring smazani_pokrok_otazka2EN = L"[ENTER]";
	std::wstring profil_nazevCZ = L"Zadej nazev profilu";
	std::wstring profil_nazevEN = L"Enter a profile name";

	std::wstring herni_modyCZ = L"Herni mody";
	std::wstring herni_modyEN = L"Game modes";
	std::wstring vzhled_plosinyCZ = L"Vzhled plosiny";
	std::wstring vzhled_plosinyEN = L"Skins";
	std::wstring nastaveniCZ = L"Nastaveni";
	std::wstring nastaveniEN = L"Settings";
	std::wstring verzeCZ = L"verze ";
	std::wstring verzeEN = L"version ";
	std::wstring HERNI_MODYCZ = L"HERNI MODY";
	std::wstring HERNI_MODYEN = L"GAME MODES";
	std::wstring NASTAVENICZ = L"NASTAVENI";
	std::wstring NASTAVENIEN = L"SETTINGS";
	std::wstring VZHLED_PLOSINYCZ = L"VZHLED PLOSINY";
	std::wstring VZHLED_PLOSINYEN = L"SKINS";
	std::wstring neodemcenoCZ = L"Odemkne se na urovni  ";
	std::wstring neodemcenoEN = L"Unlocks after level ";
	std::wstring klasikCZ = L"Klasik";
	std::wstring klasikEN = L"Classic";
	std::wstring rogue_likeCZ = L"Rogue like - zatim nefunkcni";
	std::wstring rogue_likeEN = L"Rogue like - zatim nefunkcni";
	std::wstring stejne_tvaryCZ = L"Stejne tvary - zatim nefunkcni";
	std::wstring stejne_tvaryEN = L"Hit the same color - zatim nefunkcni";
	std::wstring bloky_padajiCZ = L"Bloky padaji";
	std::wstring bloky_padajiEN = L"Falling blocks";
	std::wstring jazykCZ = L"Jazyk";
	std::wstring jazykEN = L"Language";
	std::wstring ceskyCZ = L"Cesky";
	std::wstring ceskyEN = L"Czech";
	std::wstring anglickyCZ = L"Anglicky";
	std::wstring anglickyEN = L"English";
	std::wstring ovladaniCZ = L"Ovladani";
	std::wstring ovladaniEN = L"Controls";
	std::wstring OVLADANICZ = L"OVLADANI";
	std::wstring OVLADANIEN = L"CONTROLS";

	std::wstring odchodP1CZ = L"Zkus to znovu.";
	std::wstring odchodP1EN = L"Try again.";
	std::wstring odchodV1CZ = L"VYHRAL JSI!";
	std::wstring odchodV1EN = L"YOU'VE WON!";
	std::wstring odchod2CZ = L"Restart[MEZERNIK]";
	std::wstring odchod2EN = L"Restart [SPACEBAR]";
	std::wstring odchod3CZ = L"Menu[Q]";
	std::wstring odchod3EN = L"Menu [Q]";
	std::wstring odchod4CZ = L"NEJLEPSI CAS: ";
	std::wstring odchod4EN = L"BEST TIME: ";
	std::wstring odchodV5CZ = L"Dosazeny cas: ";
	std::wstring odchodV5EN = L"Your time: ";
	std::wstring odchodP5CZ = L"Bloku zbylo: ";
	std::wstring odchodP5EN = L"Blocks left: ";
	std::wstring odchod6CZ = L"Uroven ";
	std::wstring odchod6EN = L"Level ";
	std::wstring odchod7CZ = L"Bloku zniceno: ";
	std::wstring odchod7EN = L"Blocks destroyed: ";
	std::wstring odchod8CZ = L"NEJVICE ZNICENYCH BLOKU: ";
	std::wstring odchod8EN = L"HIGHSCORE: ";

	std::wstring ovladani_menuCZ = L"Ovladani v menu";
	std::wstring ovladani_menuEN = L"Menu controls";
	std::wstring ovladani_hraCZ = L"Ovladani ve hre";
	std::wstring ovladani_hraEN = L"In-game controls";
	std::wstring ovladani_enterCZ = L"Enter";
	std::wstring ovladani_enterEN = L"Enter";
	std::wstring ovladani_mezernikCZ = L"Mezernik";
	std::wstring ovladani_mezernikEN = L"Spacebar";
	std::wstring ovladani_schopnostCZ = L"Pouzit schopnost";
	std::wstring ovladani_schopnostEN = L"Use ability";
	std::wstring ovladani_pohyb_vlevoCZ = L"Pohyb - vlevo";
	std::wstring ovladani_pohyb_vlevoEN = L"Movement - left";
	std::wstring ovladani_pohyb_vpravoCZ = L"Pohyb - vpravo";
	std::wstring ovladani_pohyb_vpravoEN = L"Movement - right";
	std::wstring ovladani_pauzaCZ = L"Pauza";
	std::wstring ovladani_pauzaEN = L"Pause";

	std::wstring novy_profil = L"Novy_profil";
	std::wstring muj_profil0;
	std::wstring muj_profil1;
	std::wstring muj_profil2;
	int rozhodovac(int strana, int& plosina_skin_zmena, int& jazyk_zmena)
	{
		Pong navod;
		/////////////////////    Profily     //////////////////////////
		if (strana == -1)
		{
			nazev_profil_novy.clear();
			nacteni_vyberu_profilu();
			vytvoreni_noveho_nazvu_profilu();
			if (y_tecka == 8)
			{
				profil0 profil;
				if (enter)
					vyber_profilu(0);
				if (del)
				{
					profil.vytvoreni_noveho_profilu();
					nazev_profil0 = nazev_profil_novy;
					level = 0;
					ulozeni_vyberu_profilu();
					enter = 0;
					del = 0;
					exit = 1;
				}
				return 2;
			}
			if (y_tecka == 10)
			{
				profil1 profil;
				if (enter)
					vyber_profilu(1);
				if (del)
				{
					profil.vytvoreni_noveho_profilu();
					nazev_profil1 = nazev_profil_novy;
					level = 0;
					ulozeni_vyberu_profilu();
					enter = 0;
					del = 0;
					exit = 1;
				}
				return 2;
			}
			if (y_tecka == 12)
			{
				profil2 profil;
				if (enter)
					vyber_profilu(2);
				if (del)
				{
					profil.vytvoreni_noveho_profilu();
					nazev_profil2 = nazev_profil_novy;
					level = 0;
					ulozeni_vyberu_profilu();
					enter = 0;
					del = 0;
					exit = 1;
				}
				return 2;
			}
			if (y_tecka == 17)
			{
				if (!jazyk)
					return jazyk_zmena = 1;
				else
					return jazyk_zmena = 0;
			}
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
					std::wcout << L"      ";
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
		/////////////////////    Nastaveni     //////////////////////////

		if (strana == 4)
		{
			if (y_tecka == 12)
			{
				setCursorPosition(29, 12);
				pohyb_vpravo = _getch();
				if (pohyb_vpravo >= 97 && pohyb_vpravo <= 122)
					pohyb_vpravo -= 32;
			}
			if (y_tecka == 13)
			{
				setCursorPosition(29, 13);
				pohyb_vlevo = _getch();
				if (pohyb_vlevo >= 97 && pohyb_vlevo <= 122)
					pohyb_vlevo -= 32;
			}
			if (y_tecka == 14)
			{
				setCursorPosition(29, 14);
				pouziti_schopnosti = _getch();
				if (pouziti_schopnosti >= 97 && pouziti_schopnosti <= 122)
					pouziti_schopnosti -= 32;
			}
			if (y_tecka == 14)
			{
				setCursorPosition(29, 15);
				pauza = _getch();
				if (pauza >= 97 && pauza <= 122)
					pauza -= 32;
			}
		}
	}
};
