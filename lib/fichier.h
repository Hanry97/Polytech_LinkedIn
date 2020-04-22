#ifndef FICHIER_H 
#define FICHIER_H

#include <string>
#include <vector>

//GENERICS FUNCTIONS
//==============================================================================================================================

bool skillFounded(std::vector<std::string> tab, std::string val);
bool existOnVector(std::vector<int> tab, int val);

//Renvoi -1 si une erreur s'est produite
int get_lastID(std::string const path);

std::vector <int> get_List_Of_idPost_Of_Enterprise(int id_enterprise);

int delete_list_of_row_from_table(std::vector<int> listOfRowsID, std::string const path_table);

int update_row(int id_row, std::string new_row, std::string const path_table);

std::string get_tableHeader(std::string const path_table);

std::string get_tableRow(int id, std::string const path);


//FUNCTIONS FOR THE ENTERPRISE
//==============================================================================================================================

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

//FUNCTIONS FOR THE JOB SEEKER
//==============================================================================================================================

//Retourne un code erreur ou succeès
int jsk_create_profile(std::string nom, std::string prenom, std::string email, std::string code_postal, std::vector<std::string> skills);

int jsk_add_skills(int id_jsk, std::vector<std::string> skills);

int jsk_add_colleague(int id_jsk, std::vector<int> colleague);

int jsk_update_code_postal(int id_jsk, std::string new_code_postale);

int jsk_profile_transition_to_employe(int id_jsk, int id_enterprise);

int jsk_delete_profile(int id);

//Pour une recherche sans code postal renseigner # comme donnée de code postal
std::vector<std::vector<std::string>> jsk_searchJob(std::vector<std::string> list_competence,std::string code_postal);

std::vector<std::vector <std::string>> jsk_find_former_colleagues();

//FUNCTIONS FOR THE EMPLOYE
//================================================================================================================================

int emp_create_profile(std::string nom, std::string prenom, std::string email, std::string code_postal, std::vector<std::string> skills, std::vector<std::string> colleagues,int id_enterprise);


#endif
