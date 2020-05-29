/*
 ===============================================
||  Auteur ::                 Hanry Nzale      ||
 ===============================================
|| Dernière modification ::   28/04/2020       ||
 ===============================================
*/

#ifndef CONSTANTE_H 
#define CONSTANTE_H
#include <string>

//Dénifition des constantes et des codes retour utilisés dans tous le programme

//TAGS
std::string const TAG_ENTREPRISE = "etp";
std::string const TAG_JOBSEEKER = "jsk";
std::string const TAG_EMPLOYE = "emp";

std::string const TAG_CLE_CHIFFREMENT = "linkedin";

//CHEMIN D'ACCES DES TABLES

std::string const tableEntreprise("database/Entreprise.csv");
std::string const tablePoste("database/Poste.csv");
std::string const tableEmployes("database/Employes.csv");
std::string const tableJobseeker("database/Jobseeker.csv");
std::string const tablePassword("database/Password.csv");
std::string const header_tablePoste("id,titre,competences,entreprise");
std::string const header_tableEntreprise("id,nom,code postal,mail");
std::string const header_tableEmployes("id,nom,prenom,mail,code postal,competences,collegues,entreprise");
std::string const header_tableJobseeker("id,nom,prenom,mail,code postal,competences,collegues");
std::string const header_tablePassword("id,password,user,type");

std::string const journalFile("journal/log.txt");
std::string const journalTestFile("journal/log_test.txt");
std::string const header_journalFile("id,date,operation,code returned");


//CODES DE RETOUR

//Quitter le programme
const int EXIT_PROGRAM = 100;

//Deconnexion
const int DECONNEXION = 101;

//Back to previous menu
const int BACK_PREV_MENU = 102;

//Tout s'est bien passé
const int SUCCESS = 0;

//Erreur à l'ouverture du fichier
const int OPEN_FILE_ERROR = -1;

//Une fonction appelée dans la fonction a retourné un code erreur
const int SUB_FUNCTION_ERROR = -2;

//Une erreur s'est produite au sein de la fonction
const int EXIT_WITH_ERROR = -3;

//Une erreur s'est produite lors de la suppression d'un fichier
const int ERROR_REMOVE_FILE = -4;

//Une erreur s'est produite lors de l'opération de renomage du fichier
const int ERROR_RENAME_FILE = -5;

//Résutat neutre
const int NOTHING_TO_DO = -6;

//Erreur lors de l'écrituure dans le journal
const int ERROR_WRITE_LOG = -7;

#endif
