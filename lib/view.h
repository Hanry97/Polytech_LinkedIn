#ifndef _VIEW_
#define _VIEW_

#include "company.h"
#include "employe.h"
#include "Position.h"
#include "constante.h"

//Page d'acceuil
int home_screen();
int quit() ;

//Vérifie que l'email est correcte (contien le symbole @)
bool isValidEmail(std::string email);

int navigation_general_menu( const int & choice );

//Page de connexion
int login_screen();

//page de création
int creation_screen();

//Vérifie l'exitence d'un entier dans un tableau d'entier
bool existOnVector(const std::vector<int> & tab,const int & val);

//Menu entreprise
//========================================================
int etp_home(company & etp);
int navigation_company( const int & choice, company & etp );
int etp_create_poste(company & etp);
int etp_delete_poste(company & etp);
int etp_search(company & etp) ;
int etp_logout(company & etp);
int etp_deleteProfil(company & etp);
int etp_create_profil();
int etp_update_password(company & etp);
//========================================================

//Menu employé
//========================================================
int emp_home(employe & emp);
int emp_create_profil();
int navigation_employe( const int & choice, employe & emp );
int display_modify_profil_employe(employe & emp );
int navigation_modify_profil_employe ( const int & choice, employe & emp);
int emp_afficher(employe & emp);
int emp_add_skills(employe & emp);
int emp_add_oldColleague(employe & emp);
int emp_update_codePostal(employe & emp);
int emp_update_entreprise(employe & emp);
int employe_to_jobseeker(employe & emp);
int emp_deleteProfile(employe & emp);
int emp_search_poste(employe & emp);
int emp_search_oldColleagues( employe & emp );
int emp_update_password(employe & emp);
//========================================================

//Menu jobseeker
//========================================================
int jsk_home(jobseeker & jsk);
int navigation_jobSeeker( int const& choice, jobseeker & jsk );
int display_modify_profil_jobSeeker( jobseeker & jsk );
int navigation_modify_profil_jobSeeker( int const& choice, jobseeker & jsk );

int jsk_afficher(jobseeker & jsk);
int jsk_add_skills(jobseeker & jsk);
int jsk_update_codePostal(jobseeker & jsk);
int jsk_deleteProfile(jobseeker & jsk);
int jobseeker_to_employe(jobseeker & jsk);
int jsk_search_poste(jobseeker & jsk);

int jsk_create_profil();
int jsk_search_oldColleagues(jobseeker & jsk );
int jsk_add_oldColleague(jobseeker & jsk);
int jsk_update_password(jobseeker & jsk);
//========================================================


#endif
