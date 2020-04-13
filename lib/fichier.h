#ifndef FICHIER_H 
#define FICHIER_H

#include <iostream>
#include <string>

std::string const tableEntreprise("../database/Entreprise.csv");

//FUNCTIONS OF THE ENTERPRISE

//Renvoi -1 si une erreur s'est produite
int get_lastID(std::string const path);

//Retourne un code erreur ou succeès
int etp_create_profile();

void etp_delete_profile();
void etp_create_profileOfPosition();
void etp_delete_profileOfPosition();
void etp_searchToHire();

#endif
