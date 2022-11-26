#pragma once
#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

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