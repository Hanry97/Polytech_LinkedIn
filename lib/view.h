#ifndef _VIEW_
#define _VIEW_

#include "company.h"
#include "employe.h"
#include "Position.h"
#include "constante.h"

//Page d'acceuil
int home_screen();
int quit() ;
bool isValidEmail(std::string email);
int navigation_general_menu( const int & choice );

//Page de connexion
int login_screen();
//page de création
int creation_screen();

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
//========================================================
//Menu employé
int emp_home(employe & emp);
//========================================================

//Menu jobseeker
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
#endif
