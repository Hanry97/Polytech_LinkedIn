#include "display.h"
#include <iostream>
using namespace std;

//last modif: Mihary R.  15/04/2020
//=========================================




void display_general_menu()
{
	int choice ;

	system( "clear" ) ;
	cout<<"================================================================================="<<endl;
	cout<<"||                                MENU GENERAL                                 ||"<<endl;
	cout<<"================================================================================="<<endl;
	cout<<"|                                                                               |"<<endl;
	cout<<"|           Vous souhaitez utilisez l'applications en tant que:                 |"<<endl;
	cout<<"|                                                                               |"<<endl;
	cout<<"|                             1-Entreprise                                      |"<<endl;
	cout<<"|                             2-Employé                                         |"<<endl;
	cout<<"|                             3-Chercheur d'emploie                             |"<<endl;
	cout<<"|                             9-Quitter le programme                            |"<<endl;
	cout<<"================================================================================="<<endl;
	cout<<"\n Veuillez entrer le numero de votre choix: " ;
	cin >> choice ;

	return navigation_general_menu( choice ) ;
}


void navigation_general_menu( int const& choice )
{
	switch( choice )
	{
		case 1:
			return menu_entreprise() ; // ...
		case 2:
			return display_person_connection( 'e' ) ;
		case 3:
			return display_person_connection( 'j' ) ;
		case 9:
			return quit() ;
		default:
			cout << "\n Ce numero n'existe pas " << endl ;
			return display_general_menu() ;
	}
}















/*========================
                        ||
    COMPANY             ||
                        ||
========================*/

void menu_entreprise()
{           
    
    cout<<"===================================================================================="<<endl;
    cout<<"||                                MENU ENTREPRISE                                 ||"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                         Que souhaitez vous faire:                                |"<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                             1-Créer un profil                                    |"<<endl;
    cout<<"|                             2-Supprimer un profil                                |"<<endl;
    cout<<"|                             3-Créer le profil d'un poste à pourvoir              |"<<endl;
    cout<<"|                             4-Supprimer le profil d'un poste pourvu              |"<<endl;
    cout<<"|                             5- Rechercher parmi les chercheurs d'emploi pour     |"<<endl;
    cout<<"|                              des profils qui correspondent à un poste à pourvoir |"<<endl;
    cout<<"|                             8-Retourner au menu précédent                        |"<<endl;
    cout<<"|                             9-Quitter le programme                               |"<<endl;
    cout<<"|                                                                                  |"<<endl; 
    cout<<"===================================================================================="<<endl;
    cout<<" Veuillez entrer le numero de votre choix  : ";
}






void rechercher_profil_v_entreprise()
{
    cout<<"===================================================================================="<<endl;
    cout<<"||                   RECHERCHER UN CHERCHEUR D'EMPLOI                             ||"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                         Comment souhaitez vous rechercher :                      |"<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                             1-Par Competence                                     |"<<endl;
    cout<<"|                             2-Par Competence et par Code Postal                  |"<<endl;
    cout<<"|                             7-Retourner au Menu precedent                        |"<<endl;
    cout<<"|                             8-Retourner au MENU GENERAL                          |"<<endl;
    cout<<"|                             9-Quitter le Programme                               |"<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<" Veuillez entrer le numero de votre choix  : ";
}
























/*========================================
                                        ||
    CONNEXION EMPLOYEE/JOB_SEEKER       ||
                                        ||
========================================*/

void display_person_connection( char const& status )
{
	int choice ;

	system( "clear" ) ;
	cout<<"========================================================================================"<<endl;
	cout<<"||                                CONNEXION                                           ||"<<endl;
	cout<<"========================================================================================"<<endl;
	cout<<"|                                                                                      |"<<endl;
	cout<<"|                         Que souhaitez vous faire:                                    |"<<endl;
	cout<<"|                                                                                      |"<<endl;
	cout<<"|                         1-Créer un profil                                            |"<<endl;
	cout<<"|                         2-Se connecter à mon profil                                  |"<<endl;
	cout<<"|                         8-Retourner au menu général                                  |"<<endl;
	cout<<"|                         9-Quitter le programme                                       |"<<endl;
	cout<<"|                                                                                      |"<<endl; 
	cout<<"======================================================================================="<<endl;
	cout<<"\n Veuillez entrer le numero de votre choix: ";
	cin >> choice ;

	return navigation_person_connection( choice, status ) ;
}


void navigation_person_connection( int const& choice, char const& status )
{
	Person person ;
	string password ;
	bool succes ;

	switch( choice )
	{
		case 1: person.create_profil( status ) ; break ;
		
		case 2:
			succes = person.load_my_profil() ;      
			if( !succes ) return display_person_connection( status ) ;
			break ;
		case 8:
			return display_general_menu() ;		
		case 9: 
			return quit() ;		
		default:
			cout << "\n Ce numero n'existe pas " << endl ;
			return display_person_connection( status ) ;
	}

	if( status == 'e' ) return display_employee_menu( person ) ;
	if( status == 'j' ) return display_jobSeeker_menu( person ) ;
}




/*==========================
                          ||
    EMPLOYEE MENU         ||
                          ||
==========================*/

void display_employee_menu( Person &person )
{
	int choice ;

	system( "clear" ) ;
	cout<<"========================================================================================"<<endl;
	cout<<"||                                MENU EMPLOYÉ(E)                                     ||"<<endl;
	cout<<"========================================================================================"<<endl;
	cout<<"|                                                                                      |"<<endl;
	cout<<"|                         Que souhaitez vous faire:                                    |"<<endl;
	cout<<"|                                                                                      |"<<endl;
	cout<<"|                         1-Modifier votre profil                                      |"<<endl;
	cout<<"|                         2-Devenir un chercheur d'emploi                              |"<<endl;
	cout<<"|                         3-Supprimer le profil                                        |"<<endl; 
	cout<<"|                         4-Rechercher les postes me correspondant                     |"<<endl;
	cout<<"|                         5-Recherche parmi les anciens collègues                      |"<<endl;
	cout<<"|                         7-Retourner au menu précédent                                |"<<endl;
	cout<<"|                         8-Retourner au menu général                                  |"<<endl;
	cout<<"|                         9-Quitter le programme                                       |"<<endl;
	cout<<"|                                                                                      |"<<endl; 
	cout<<"======================================================================================="<<endl;
	cout<<"\n Veuillez entrer le numero de votre choix  : " ;
	cin >> choice ;

	return navigation_employee_menu( choice, person ) ;
}


void navigation_employee_menu( int const& choice, Person &person )
{
	switch( choice )
	{
		case 1: 
			return display_modify_profil_employee( person ) ;		
		case 2:
			person.employee_to_jobSeeker() ;
			return display_jobSeeker_menu( person ) ;		
		case 3:
			person.delete_profil() ;
			return display_general_menu() ;	
		case 4: 
			return display_search_position( person ) ;	
		case 5: 
			return display_search_oldColleagues( person ) ;
		case 7:
			logout() ;
			return display_person_connection( 'e' ) ;
		case 8:
			logout() ;
			return display_general_menu() ;	
		case 9: 
			return quit() ;	
		default:
			cout << "\n Ce numero n'existe pas " << endl ;
			return display_employee_menu( person ) ;
	}
}




/*=========================================
                                         ||
    MODIFICATION EMPLOYEE PROFIL         ||
                                         ||
=========================================*/

void display_modify_profil_employee( Person &person )
{
	int choice ;

	system( "clear" ) ;
	cout<<"===================================================================================="<<endl;
	cout<<"||                            MODIFIER MON PROFIL EMPLOYÉ(E)                      ||"<<endl;
	cout<<"===================================================================================="<<endl;
	cout<<"|                                                                                  |"<<endl;
	cout<<"|                             Que souhaitez vous faire ?:                          |"<<endl;
	cout<<"|                                                                                  |"<<endl;
	cout<<"|                             1-Afficher mon profil                                |"<<endl;
	cout<<"|                             2-Ajouter une compétence                             |"<<endl;
	cout<<"|                             3-Ajouter un(e) ancien(ne) collègue de travail       |"<<endl;
	cout<<"|                             4-Modifier mon code postal                           |"<<endl;
	cout<<"|                             5-Modifier mon entreprise                            |"<<endl;
	cout<<"|                             7-Retourner au menu précédent                        |"<<endl;
	cout<<"|                             8-Retourner au menu general                          |"<<endl;
	cout<<"|                             9-Quitter le Programme                               |"<<endl;
	cout<<"|                                                                                  |"<<endl;
	cout<<"===================================================================================="<<endl;
	cout<<"\n Veuillez entrer le numero de votre choix: ";
	cin >> choice ;

	return navigation_modify_profil_employee( choice, person ) ;
}


void navigation_modify_profil_employee( int const& choice, Person &person )
{
	switch( choice )
	{
		case 1:
			person.print_profil() ; break ;
		case 2: 
			person.add_skill() ; break ;
		case 3: 
			person.add_oldColleague() ; break ;
		case 4: 
			person.modify_postalCode() ; break ;
		case 5: 
			person.modify_company() ; break ;
		case 7: 
			return display_employee_menu( person ) ;
		case 8: 
			logout() ;
			return display_general_menu() ;	
		case 9: 
			return quit() ;	
		default: 
			cout << "\n Ce numero n'existe pas " << endl ;
	}

	return display_modify_profil_employee( person ) ;
}




/*============================
                            ||
    JOB_SEEKER MENU         ||
                            ||
============================*/

void display_jobSeeker_menu( Person &person )
{
	int choice ;

	system( "clear" ) ;
	cout<<"========================================================================================"<<endl;
	cout<<"||                                MENU CHERCHEUR D'EMPLOI                             ||"<<endl;
	cout<<"========================================================================================"<<endl;
	cout<<"|                                                                                      |"<<endl;
	cout<<"|                         Que souhaitez vous faire:                                    |"<<endl;
	cout<<"|                                                                                      |"<<endl;
	cout<<"|                         1-Modifier votre profil                                      |"<<endl;
	cout<<"|                         2-Devenir employé                                            |"<<endl;
	cout<<"|                         3-Supprimer le profil                                        |"<<endl; 
	cout<<"|                         4-Rechercher les postes me correspondant                     |"<<endl;
	cout<<"|                         5-Recherche parmi les anciens collègues                      |"<<endl;
	cout<<"|                         7-Retourner au menu précédent                                |"<<endl;
	cout<<"|                         8-Retourner au menu général                                  |"<<endl;
	cout<<"|                         9-Quitter le programme                                       |"<<endl;
	cout<<"|                                                                                      |"<<endl;
	cout<<"======================================================================================="<<endl;
	cout<<"\n Veuillez entrer le numero de votre choix  : ";
	cin >> choice ;

	return navigation_jobSeeker_menu( choice, person ) ;
}


void navigation_jobSeeker_menu( int const& choice, Person &person )
{
	switch( choice )
	{
		case 1: 
			return display_modify_profil_jobSeeker( person ) ;		
		case 2:
			person.jobSeeker_to_employee() ;
			return display_employee_menu( person ) ;		
		case 3:
			person.delete_profil() ;
			return display_general_menu() ;	
		case 4: 
			return display_search_position( person ) ;	
		case 5:
			return display_search_oldColleagues( person ) ;
		case 7:
			logout() ;
			return display_person_connection( 'e' ) ;
		case 8: 
			logout() ;
			return display_general_menu() ;			
		case 9: 
			return quit() ;	
		default:
			cout << "\n Ce numero n'existe pas " << endl ;
			return display_employee_menu( person ) ;
	}
}




/*===========================================
                                           ||
    MODIFICATION JOB_SEEKER PROFIL         ||
                                           ||
===========================================*/

void display_modify_profil_jobSeeker( Person &person )
{
	int choice ;

	system( "clear" ) ;
	cout<<"===================================================================================="<<endl;
	cout<<"||                     MODIFIER MON PROFIL CHERCHEUR D'EMPLOI                     ||"<<endl;
	cout<<"===================================================================================="<<endl;
	cout<<"|                                                                                  |"<<endl;
	cout<<"|                             Que souhaitez vous faire ?:                          |"<<endl;
	cout<<"|                                                                                  |"<<endl;
	cout<<"|                             1-Afficher mon profil                                |"<<endl;
	cout<<"|                             2-Ajouter une compétence                             |"<<endl;
	cout<<"|                             3-Ajouter un(e) ancien(ne) collègue de travail       |"<<endl;
	cout<<"|                             4-Modifier mon code postal                           |"<<endl;
	cout<<"|                             7-Retourner au menu précédent                        |"<<endl;
	cout<<"|                             8-Retourner au menu général                          |"<<endl;
	cout<<"|                             9-Quitter le Programme                               |"<<endl;
	cout<<"|                                                                                  |"<<endl;
	cout<<"===================================================================================="<<endl;
	cout<<"\n Veuillez entrer le numero de votre choix  : ";
	cin >> choice ;

	return navigation_modify_profil_jobSeeker( choice, person ) ;
}


void navigation_modify_profil_jobSeeker( int const& choice, Person &person )
{
	switch( choice )
	{
		case 1:
			person.print_profil() ; break ;	
		case 2: 
			person.add_skill() ; break ;
		case 3: 
			person.add_oldColleague() ; break ;
		case 5: 
			person.modify_postalCode() ; break ;
		case 7: 
			return display_employee_menu( person ) ;
		case 8: 
			logout() ;
			return display_general_menu() ;		
		case 9: 
			return quit() ;	
		default: 
			cout << "\n Ce numero n'existe pas " << endl ;
	}

	return display_modify_profil_employee( person ) ;
}




/*===================================
                                   ||
    SEARCH POSITION                ||
                                   ||
===================================*/

void display_search_position( Person &person )
{
	int choice ;

	system( "clear" ) ;
	cout<<"===================================================================================="<<endl;
	cout<<"||                          RECHERCHER UN POSTE                                   ||"<<endl;
	cout<<"===================================================================================="<<endl;
	cout<<"|                                                                                  |"<<endl;
	cout<<"|                         Comment souhaitez vous rechercher :                      |"<<endl;
	cout<<"|                                                                                  |"<<endl;
	cout<<"|                             1-Par Competence                                     |"<<endl;
	cout<<"|                             2-Par Competence et par Code Postal                  |"<<endl;
	cout<<"|                             7-Retourner au menu précédent                        |"<<endl;
	cout<<"|                             8-Retourner au menu général                          |"<<endl;
	cout<<"|                             9-Quitter le Programme                               |"<<endl;
	cout<<"|                                                                                  |"<<endl;
	cout<<"===================================================================================="<<endl;
	cout<<"\n Veuillez entrer le numero de votre choix: ";
	cin >> choice ;

	return navigation_search_position( choice, person ) ;
}


void navigation_search_position( int const& choice, Person &person )
{
	char status = person.get_status() ;
	
	switch( choice )
	{
		case 1:
			person.search_position_by_skill() ; break ;
		case 2:
			person.search_position_by_skill_postalCode() ; break ;
		case 7: 			
			if( status == 'e' ) return display_employee_menu( person ) ;
			else return display_jobSeeker_menu( person ) ;
		case 8: 
			logout() ;
			return display_general_menu() ;		
		case 9: 
			return quit() ;	
		default: 
			cout << "\n Ce numero n'existe pas " << endl ; break ;
	}
	
	return display_search_position( person ) ;
}




/*===================================
                                   ||
    SEARCH COLLEAGUES              ||
                                   ||
===================================*/

void display_search_oldColleagues( Person &person )
{
	int choice ;

	system( "clear" ) ;	
	cout<<"===================================================================================="<<endl;
	cout<<"||                   AFFICHER MES ANCIEN COLLEGUES DE TRAVAIL                     ||"<<endl;
	cout<<"===================================================================================="<<endl;
	cout<<"|                                                                                  |"<<endl;
	cout<<"|                   Comment souhaitez lister vos ancien collegues :                |"<<endl;
	cout<<"|                                                                                  |"<<endl;
	cout<<"|                             1-Lister par entreprise                              |"<<endl;
	cout<<"|                             2-Lister par Competence                              |"<<endl;
	cout<<"|                             7-Retourner au menu précédent                        |"<<endl;
	cout<<"|                             8-Retourner au menu general                          |"<<endl;
	cout<<"|                             9-Quitter le Programme                               |"<<endl;
	cout<<"|                                                                                  |"<<endl;
	cout<<"===================================================================================="<<endl;
	cout<<"\n Veuillez entrer le numero de votre choix: ";
	cin >> choice ;

	return navigation_search_oldColleagues( choice, person ) ;
}


void navigation_search_oldColleagues( int const& choice, Person &person )
{
	char status = person.get_status() ;

	switch( choice )
	{
		case 1:
			person.search_colleagues_by_company() ; break ;
		case 2:
			person.search_colleagues_by_skill() ; break ;
		case 7: 
			if( status == 'e' ) return display_employee_menu( person ) ;
			else return display_jobSeeker_menu( person ) ;
		case 8: 
			logout() ;
			return display_general_menu() ;		
		case 9: 
			return quit() ;	
		default: 
			cout << "\n Ce numero n'existe pas " << endl ;
	}

	return display_search_oldColleagues( person ) ;
}





/*===================================
                                   ||
    SEARCH COLLEAGUES              ||
                                   ||
===================================*/

void quit()
{
	system( "clear" ) ;
	
	cout << "||====================================================================================||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||                        MERCI D'UTILISER NOTRE APPLICATION                          ||" << endl ;
	cout << "||                                   AU REVOIR                                        ||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||====================================================================================||" << endl ;
	cout << "\n\n\n\n\n\n" ;

}



void logout()
{
	string useless ;
	system( "clear" ) ;
	
	cout << "||====================================================================================||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||                                  DECONNEXION                                       ||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||                                                                                    ||" << endl ;
	cout << "||====================================================================================||" << endl << endl ;

	cout << " Saisir qqch pour ne plus afficher ce message " ;
	cin >> useless ;
}