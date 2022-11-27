#pragma once
#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

class vyber_profilu
{
    XMLDocument xmlDoc;
	int jazyk_s;
    std::string profil0 = "Muj profil1";
    std::string profil1 = "Muj profil2";
    std::string profil2 = "Muj profil3";

    int vytvoreni_noveho_profilu()
    {
        XMLNode* pRoot = xmlDoc.NewElement("Profil");
        xmlDoc.InsertFirstChild(pRoot);

        XMLElement* pElement1 = xmlDoc.NewElement("jazyk");
        pElement1->SetText(0);
        pRoot->InsertEndChild(pElement1);

		XMLElement* pElement2 = xmlDoc.NewElement("Muj profil1");
		pRoot->InsertEndChild(pElement2);

        XMLElement* pElement3 = xmlDoc.NewElement("Muj profil2");
        pRoot->InsertEndChild(pElement2);

        XMLElement* pElement4 = xmlDoc.NewElement("Muj profil3");
        pRoot->InsertEndChild(pElement2);

        XMLError eResult = xmlDoc.SaveFile("profil_vyber.xml");
        XMLCheckResult(eResult);
    }
    int nacteni_profilu()
    {
        XMLError eResult = xmlDoc.LoadFile("profil_vyber.xml");
        XMLCheckResult(eResult);

        XMLNode* pRoot = xmlDoc.FirstChild();
        if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;

        XMLElement* pElement0 = pRoot->FirstChildElement("jazyk"); //nalezeni int value
        if (pElement0 == nullptr) return XML_ERROR_PARSING_ELEMENT;
        eResult = pElement0->QueryIntText(&jazyk_s); // vyndani int
        XMLCheckResult(eResult);


        const char* szAttributeText = nullptr;
        XMLElement* pElement1;
        szAttributeText = pElement1->Attribute("month");
        if (szAttributeText == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;
        std::string strOutMonth = szAttributeText;

        return XML_SUCCESS;
    }
	int ukladani_profilu()
	{
        XMLNode* pRoot = xmlDoc.NewElement("Profil");
        xmlDoc.InsertFirstChild(pRoot);

        XMLElement* pElement1 = xmlDoc.NewElement("jazyk");
        pElement1->SetText(0);
        pRoot->InsertEndChild(pElement1);

        XMLElement* pElement2 = xmlDoc.NewElement("jazyk");
        pRoot->InsertEndChild(pElement2);

        XMLError eResult = xmlDoc.SaveFile("profil_vyber.xml");
        XMLCheckResult(eResult);
	}
};

