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

//CHEMIN D'ACCES DES TABLES

std::string const tableEntreprise("database/Entreprise.csv");
std::string const tablePoste("database/Poste.csv");
std::string const tableEmployes("database/Employes.csv");
std::string const tableJobseeker("database/Jobseeker.csv");
std::string const header_tablePoste("id,titre,competences,entreprise");
std::string const header_tableEntreprise("id,nom,code postal,mail");
std::string const header_tableEmployes("id,nom,prenom,mail,code postal,competences,collegues,entreprise");
std::string const header_tableJobseeker("id,nom,prenom,mail,code postal,competences,collegues");

//CODES DE RETOUR

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

#endif
