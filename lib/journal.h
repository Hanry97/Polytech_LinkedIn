#ifndef _JOURNAL_
#define _JOURNAL_
#include <ctime>
#include <string>
#include "company.h"
#include "employe.h"





 //static time_t t_debut;

//FONCTION POUR LE JOURNAL
//==================================================================================================================================
void intialise_date_journal(time_t );              //Ecrit la date d'ouverture du programme dans le journal
void intialise_user_journal(std::string user);   //Ecrit le login de l'utilisateur dans le journal
void memorise(std::string a);                    //Enregistre une chaine de caractère dans le journal(nom des fonction)    
void memorise_avec_code(std::string a ,int code );  //En plus d'enregistrer le nom d'une fonction,il retourne le code d'erreur de la focntion 
void fin_de_session(time_t );                  //Enregistre les paramètre de fin d'exécution

void intialise_emp_journal(std::string a,std::string postalcode);
void intialise_jsk_journal(std::string a,std::string postalcode);
void intialise_etp_journal(std::string a,std::string postalcode);
void login_fail_journal();

void initialise_new_etp(company etp);
void initialise_new_jsk(jobseeker jsk);
void initialise_new_emp(employe emp);

#endif