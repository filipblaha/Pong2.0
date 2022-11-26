#pragma once
#include <iostream>
#include "Menu.h"
#include "tinyxml2.h"

using namespace tinyxml2;

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif
class profil0_ukladani
{
public:
    XMLDocument xmlDoc;
    Menu navod_menu;
    int jazyk_s;
    int plosina_skin_s;
    int highscore_cas_s;
    int highscore_znicenych_bloku_s;
    int level_s;
    int exp_s;

    int ulozeni_profilu()
    {
        XMLNode* pRoot = xmlDoc.NewElement("Profil");
        xmlDoc.InsertFirstChild(pRoot);

        XMLElement* pElement1 = xmlDoc.NewElement("jazyk");
        pElement1->SetText(navod_menu.jazyk);
        pRoot->InsertEndChild(pElement1);

        XMLElement* pElement2 = xmlDoc.NewElement("plosina_skin");
        pElement2->SetText(navod_menu.plosina_skin);
        pRoot->InsertEndChild(pElement2);


        XMLElement* pElement3 = xmlDoc.NewElement("highscore_cas");
        pElement3->SetText(navod_menu.highscore_cas);
        pRoot->InsertEndChild(pElement3);

        XMLElement* pElement4 = xmlDoc.NewElement("highscore_znicenych_bloku");
        pElement4->SetText(navod_menu.highscore_znicenych_bloku);
        pRoot->InsertEndChild(pElement4);

        XMLElement* pElement5 = xmlDoc.NewElement("level");
        pElement5->SetText(navod_menu.level);
        pRoot->InsertEndChild(pElement5);

        XMLElement* pElement6 = xmlDoc.NewElement("exp");
        pElement6->SetText(navod_menu.exp);
        pRoot->InsertEndChild(pElement6);

        XMLError eResult = xmlDoc.SaveFile("profil0.xml");
        XMLCheckResult(eResult);
    }
};
class profil1_ukladani
{
public:
    XMLDocument xmlDoc;
    Menu navod_menu;
    int jazyk_s;
    int plosina_skin_s;
    int highscore_cas_s;
    int highscore_znicenych_bloku_s;
    int level_s;
    int exp_s;

    int ulozeni_profilu()
    {
        XMLNode* pRoot = xmlDoc.NewElement("Profil");
        xmlDoc.InsertFirstChild(pRoot);

        XMLElement* pElement1 = xmlDoc.NewElement("jazyk");
        pElement1->SetText(navod_menu.jazyk);
        pRoot->InsertEndChild(pElement1);

        XMLElement* pElement2 = xmlDoc.NewElement("plosina_skin");
        pElement2->SetText(navod_menu.plosina_skin);
        pRoot->InsertEndChild(pElement2);


        XMLElement* pElement3 = xmlDoc.NewElement("highscore_cas");
        pElement3->SetText(navod_menu.highscore_cas);
        pRoot->InsertEndChild(pElement3);

        XMLElement* pElement4 = xmlDoc.NewElement("highscore_znicenych_bloku");
        pElement4->SetText(navod_menu.highscore_znicenych_bloku);
        pRoot->InsertEndChild(pElement4);

        XMLElement* pElement5 = xmlDoc.NewElement("level");
        pElement5->SetText(navod_menu.level);
        pRoot->InsertEndChild(pElement5);

        XMLElement* pElement6 = xmlDoc.NewElement("exp");
        pElement6->SetText(navod_menu.exp);
        pRoot->InsertEndChild(pElement6);

        XMLError eResult = xmlDoc.SaveFile("profil1.xml");
        XMLCheckResult(eResult);
    }
};
class profil2_ukladani
{
public:
    XMLDocument xmlDoc;
    Menu navod_menu;
    int jazyk_s;
    int plosina_skin_s;
    int highscore_cas_s;
    int highscore_znicenych_bloku_s;
    int level_s;
    int exp_s;

    int ulozeni_profilu()
    {
        XMLNode* pRoot = xmlDoc.NewElement("Profil");
        xmlDoc.InsertFirstChild(pRoot);

        XMLElement* pElement1 = xmlDoc.NewElement("jazyk");
        pElement1->SetText(navod_menu.jazyk);
        pRoot->InsertEndChild(pElement1);

        XMLElement* pElement2 = xmlDoc.NewElement("plosina_skin");
        pElement2->SetText(navod_menu.plosina_skin);
        pRoot->InsertEndChild(pElement2);


        XMLElement* pElement3 = xmlDoc.NewElement("highscore_cas");
        pElement3->SetText(navod_menu.highscore_cas);
        pRoot->InsertEndChild(pElement3);

        XMLElement* pElement4 = xmlDoc.NewElement("highscore_znicenych_bloku");
        pElement4->SetText(navod_menu.highscore_znicenych_bloku);
        pRoot->InsertEndChild(pElement4);

        XMLElement* pElement5 = xmlDoc.NewElement("level");
        pElement5->SetText(navod_menu.level);
        pRoot->InsertEndChild(pElement5);

        XMLElement* pElement6 = xmlDoc.NewElement("exp");
        pElement6->SetText(navod_menu.exp);
        pRoot->InsertEndChild(pElement6);

        XMLError eResult = xmlDoc.SaveFile("profil2.xml");
        XMLCheckResult(eResult);
    }
};
