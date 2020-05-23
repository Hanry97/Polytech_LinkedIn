#ifndef _JOURNAL_
#define _JOURNAL_
#include <ctime>
#include <string>

//FONCTION POUR LE JOURNAL
//==================================================================================================================================
void intialise_date_journal(time_t );              //Ecrit la date d'ouverture du programme dans le journal
void intialise_user_journal(std::string user,std::string email);   //Ecrit le login de l'utilisateur dans le journal
void memorise(std::string a);                    //Enregistre une chaine de caractère dans le journal(nom des fonction)    
void memorise_avec_code(std::string a ,int code );  //En plus d'enregistrer le nom d'une fonction,il retourne le code d'erreur de la focntion 
void fin_de_session(time_t debut);                  //Enregistre les paramètre de fin d'exécution

#endif