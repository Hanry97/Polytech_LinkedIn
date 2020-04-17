#ifndef FICHIER_H 
#define FICHIER_H

#include <string>
#include <vector>

//GENERICS FUNCTIONS
bool skillFounded(std::vector<std::string> tab, std::string val);
bool existOnVector(std::vector<int> tab, int val);

//Renvoi -1 si une erreur s'est produite
int get_lastID(std::string const path);

std::vector <int> get_List_Of_idPost_Of_Enterprise(int id_enterprise);

int delete_list_of_row_from_table(std::vector<int> listOfRowsID, std::string const path_table);

//FUNCTIONS OF THE ENTERPRISE

//Retourne un code erreur ou succeès
int etp_create_profile(std::string nom, std::string code_postal, std::string email);

//Retourne un code erreur ou succès
//Supprime le profil d'une entreprise et les postes à pourvoir qui lui sont liés
int etp_delete_profile(int id_entreprise);

//Retourne un code erreur ou succès
int etp_create_profileOfPosition(std::string titre, std::vector<std::string> skills, int entreprise_id);

//Retourne un code erreur ou succès
int etp_delete_profileOfPosition(int id_etp, int id_poste);

//Pour une recherche sans code postal renseigner # comme donnée de code postal
std::vector<std::vector<std::string>> etp_searchToHire(std::vector<std::string> list_competence,std::string code_postal);

#endif
