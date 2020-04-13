#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fichier.h"
#include "constante.h"

using namespace std;

//TOOLS
void split(const string &chaine, char delimiteur, vector &elements)
{
    stringstream ss(chaine);
    string sousChaine;
    
    while (getline(ss, sousChaine, delimiteur))
    {
        elements.push_back(sousChaine);
    }
}

vector split(const string &chaine, char delimiteur) 
{
    vector elements;
    split(chaine, delimiteur, elements);

    return elements;
}

//FUNCTIONS OF THE ENTERPRISE

int get_lastID(string const path)
{
    int id = 0;
    vector <string> x; 

    ifstream flux(path.c_str());

    if(flux){
        
        string ligne;
        while(getline(flux, ligne));                        //Tant qu'on n'est pas à la fin, on lit. A la fin ligne contient la dernière ligne
        x = split(ligne, ',');                              //Split découpe la ligne en fonction du délimiteur
        id = (int) x[0];

    }else{

        cout << "ERREUR: Impossible d'ouvrir le fichier " << path << endl; //à écrire dans le journal
        id = -1;
    }

    flux.close();

    return id;
}

int etp_create_profile(string nom, string code_postal, string email) 
{ 
    int id;
    int code;

    int lastID = get_lastID(tableEntreprise);

    if(lastID != -1){
        
        id = lastID++;

        ofstream flux(tableEntreprise.c_str(), ios::app);

        if(flux)    
        {
            flux << id << "," << nom << "," << code_postal << "," << email << endl;
            code = SUCCESS;
        }else{
            cout << "ERREUR: Impossible d'ouvrir le fichier " << tableEntreprise << endl;
            code = OPEN_FILE_ERROR;
        }

        flux.close();
    
    }else{
        code = SUB_FUNCTION_ERROR;
    }

    return code;
	
} 
