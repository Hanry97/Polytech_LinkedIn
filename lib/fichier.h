/*
 ===============================================
||  Auteur ::                 Hanry Nzale      ||
 ===============================================
|| Dernière modification ::   05/05/2020       ||
 ===============================================
*/

#ifndef FICHIER_H 
#define FICHIER_H

#include <string>
#include <vector>

//GENERICS FUNCTIONS
//==============================================================================================================================

bool skillFounded(std::vector<std::string> tab, std::string val);
bool existOnVector(std::vector<int> tab, int val);
bool existOnVectorString(std::vector<std::string> tab, std::string val);


//Renvoi -1 si une erreur s'est produite
int get_lastID(std::string const path);
int get_log_lastID(std::string const path);

std::vector <int> get_List_Of_idPost_Of_Enterprise(int id_enterprise);

int delete_list_of_row_from_table(std::vector<int> listOfRowsID, std::string const path_table);

int update_row(int id_row, std::string new_row, std::string const path_table);

std::string get_tableHeader(std::string const path_table);

std::string get_tableRow(int id, std::string const path);

std::vector<std::string> get_Allemploye_fromEnterprise(int id_entreprise);

//connexion à un compte via une adresse mail, le deuxième paramètre doit correspondre à un tag de profil
std::vector<std::string> login_byEmail(std::string email, std::string profil_tag);

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

//Récupère tous les offres d'emploi de l'entreprise dont l'id est passé en paramètre
std::vector<std::string> get_AllPoste_fromEnterprise(int id_entreprise);

std::vector<std::string> get_EntrepriseByID(int id_etp);

//FUNCTIONS FOR THE JOB SEEKER
//==============================================================================================================================

//Retourne un code erreur ou succeès
int jsk_create_profile(std::string nom, std::string prenom, std::string email, std::string code_postal, std::vector<std::string> skills);

int jsk_add_skills(int id_jsk, std::vector<std::string> skills);

int jsk_add_colleague(int id_jsk, std::vector<int> colleague);

int jsk_update_code_postal(int id_jsk, std::string new_code_postale);

int jsk_profile_transition_to_employe(int id_jsk, int id_enterprise);

int jsk_delete_profile(int id);

std::vector<std::string> jsk_search_entreprise(std::string nom, std::string code_postal);

//Résultats
    //Titre du poste                dans [0]
    //Nom de l'entreprise           dans [1]
    //Adresse mail de l'entreprise  dans [2]
    //Code postal de l'entreprise   dans [3]
//Pour une recherche sans code postal renseigner # comme donnée de code postal
//La recherche par code postale recherche dans la table entreprise en fonction de l'id de l'entreprise qui propose le poste
std::vector<std::vector<std::string>> jsk_searchJob(std::vector<std::string> list_competence,std::string code_postal);

//Résultats
    //Nom du (de la) collègue
    //Prénom du (de la) collègue
    //Adresse mail du (de la) collègue
//Recherche par entreprise (retoune les ancien(ne)s collègues employés à l'entreprise)

std::vector<std::vector <std::string>> jsk_find_former_colleagues_by_enterprise(int enterprise);

std::vector<std::vector <std::string>> jsk_find_former_colleagues_by_skills(std::vector<int> list_id, std::vector<std::string> list_competence);

std::vector<std::string> jsk_get_old_colleagues_by_id(std::vector<int> list_id);

//FUNCTIONS FOR THE EMPLOYE
//================================================================================================================================

int emp_create_profile(std::string nom, std::string prenom, std::string email, std::string code_postal, std::vector<std::string> skills, std::vector<int> colleagues,int id_enterprise);

int emp_add_skills(int id_emp, std::vector<std::string> skills);

int emp_add_colleague(int id_emp, std::vector<int> colleague);

int emp_update_code_postal(int id_emp, std::string new_code_postale);

int emp_update_enterprise(int id_emp, int new_id_enterprise);

//Les employés de l'entreprise quittée s'ajoutent automatiquement à la liste des anciens collègues
int emp_profile_transition_to_jobseeker(int id_emp, int id_etp);

int emp_delete_profile(int id);

//Pour une recherche sans code postal renseigner # comme donnée de code postal
std::vector<std::vector<std::string>> emp_searchJob(std::vector<std::string> list_competence,std::string code_postal);

std::vector<std::vector <std::string>> emp_find_former_colleagues();

//FONCTION CHIFFREMENT DES PASSWORD (VIGENERE)
//==================================================================================================================================

//Type définit le type d'utilisateur pour lequel on crée le mot de passe
//Le type correspond à un TAG, les TAGs sont prédéfinits dans le fichier de déclaration des constantes.
 
int create_password(int id, std::string mdp, std::string type);
bool password_existAndOk(int id, std::string mdp, std::string type);
int delete_password(int id_user, std::string type);
int update_password(int user_id, std::string n_mdp, std::string o_mdp, std::string type);

//JOURNAL
//==================================================================================================================================

//Vérifie l'existence du fichier journal, le crée s'il n'existe pas déjà.
bool check_file(const std::string &file);

//Ecriture dans le journal d'une operation liée à une fonction spécification fonctionnelle
//operation_label : Le nom de l'opération
//parameters : les paramètres passés à la fonction
//code retour : le code retour renvoyé à l'issue de l'execution
int write_operation(const std::string &file ,std::string operation_label,std::vector<std::string> parameters,int code_retour);

//Ecrit dans le journal le resultat d'un échec d'execution
int write_error_message(const std::string &file, const std::string &message, int code_retour);

#endif
