//Pour les fonctions Supplementaires
//last modif: Mihary R   15/04/2020
//=========================================


#ifndef __FONCTIONSUP__
#define __FONCTIONSUP__

#include "Person.h"



// General menu
	void display_general_menu() ;
	void navigation_general_menu( int const& choice ) ;


// Company menu
	void menu_entreprise() ;
	// ... A COMPLETER PAR Sheq le Vrai ;)


// Connexion ( employee / job_seeker ) menu
	void display_person_connection( char const& status ) ;
	void navigation_person_connection( int const& choice, char const& status ) ;

// Employee menu
	void display_employee_menu( Person &person ) ;
	void navigation_employee_menu( int const& choice, Person &person ) ;

// Modification employee profil menu
	void display_modify_profil_employee( Person &person ) ;
	void navigation_modify_profil_employee( int const& choice, Person &person ) ;

// Job_seeker menu
	void display_jobSeeker_menu( Person &person ) ;
	void navigation_jobSeeker_menu( int const& choice, Person &person ) ;

// Modification job_seeker profil menu
	void display_modify_profil_jobSeeker( Person &person ) ;
	void navigation_modify_profil_jobSeeker( int const& choice, Person &person ) ;

// Search position
	void display_search_position( Person &person ) ;
	void navigation_search_position( int const& choice, Person &person ) ;

// Search colleagues
	void display_search_oldColleagues( Person &person ) ;
	void navigation_search_oldColleagues( int const& choice, Person &person ) ;


// Others
	void quit() ;
	void logout() ;

#endif