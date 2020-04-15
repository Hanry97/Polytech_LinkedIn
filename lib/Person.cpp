/*==============================
                              ||
LAST MODIFICATION:            ||
	DATE: 15/04/2020         ||
	AUTHOR: Mihary R.        ||
                              ||
==============================*/

#include "Person.h"
using namespace std ;


/*=================
                 ||
	Creation    ||
                 ||
=================*/

Person::Person()
{
	_status = 'x' ;
	_id = -1 ; 
	_surname = "non spécifié" ;
	_firstname = "non spécifié" ;
	_postalCode = -1 ;
	_email = "non spécifié" ;
}


void Person::create_profil( char const& status )
{
	_status = status ;

	system( "clear" ) ;
	cout << "\n\n" ;
	cout << " ||=====================|| " << endl ;
	cout << " ||                     || " << endl ;
	cout << " ||   CREATION PROFIL   || " << endl ;
	cout << " ||                     || " << endl ;
	cout << " ||=====================|| " << endl << endl ;

	cout << "   Nom: " ; cin >> _surname ;
	cout << "   Prenom: " ; cin >> _firstname ;
	cout << "   Code postal: " ; cin >> _postalCode ;
	cout << "   Email: " ; cin >> _email ;
}


bool Person::load_my_profil()
{
	int id ;
	string password ;

	system( "clear" ) ;	
	cout << "\n Afin d'acceder à votre profil, veuillez entrer les information suivantes: " << endl ;
	cout << " Id: "  ; cin >> id ;
	cout << " Passeword: "  ; cin >> password ;
	
	// ...
	
	return true ;
}




/*============================
                            ||
	Profil modification    ||
                            ||
============================*/

void Person::add_skill()
{
	string skill ;
	
	system( "clear" ) ;
	cout << "\n\n\n" ;
	print_listSkills() ;
	cout << "\n\n   Tapez la compétence à ajouter: " ;
	cin >> skill ;
	cout << "\n   Ajout réussi" << endl ;
	
	_listSkills.push_back( skill ) ;
}



void Person::add_oldColleague()
{
	Person colleague ;
	int idColleague ;
	bool success ;
	
	system( "clear" ) ;
	cout << "\n\n\n" ;
	print_listOldColleagues() ;
	cout << "\n   Veuilez saisir l'identifiant du collègue à ajouter: " ;
	cin >> idColleague ;
	success = load_a_profil( idColleague, colleague ) ;

	if( success ) 
	{
		_listOldColleagues.push_back( colleague ) ;
		cout << "\n Ajout réussi" << endl ;
		cout << colleague._surname << " " << colleague._firstname << " a été ajouté a votre liste d'ancien collègue" << endl ;
	}
	else {
		cout << "\n Echec de l'ajout" << endl ;
		cout << "Cette identitifiant n'existe pas" << endl ;
	}
	put_sth_for_come_back() ;
}



void Person::modify_postalCode()
{
	int tmp ;

	system( "clear" ) ;
	cout << "\n\n\n" ;	
	cout << "\n Code postal actuel: " << _postalCode << endl ;
	cout << "\n Veuillez entrer votre nouveau code postal: " ;
	cin >> tmp ;

	if( tmp <= 0 ) cout << "\n Numero invalide" << endl ;
	else 
	{
		_postalCode = tmp ;
		cout << "\n Modification réussi" << endl ;
		cout << " Votre nouveau code postal est: " << _postalCode << endl ;
	}
	put_sth_for_come_back() ;
}



void Person::modify_company()
{
	string nameCompany ;
	Company company ;
	bool success ;

	system( "clear" ) ;
	cout << "\n\n\n" ;	
	cout << "\n Entreprise actuelle: " << _company.get_name() << endl ;
	cout << "\n Veuillez entrer le nom de votre nouvelle entreprise: " ;
	cin >> nameCompany ;
	success = load_a_company( nameCompany, company ) ;

	if( success ) 
	{
		_company = company ;
		cout << "\n Modification réussi" << endl ;
		cout << "Votre nouvelle entreprise est " << nameCompany ;
	}
	else 
	{
		cout << "\n Echec modification " << endl ;
		cout << " Verifier que l'entreprise saisi est inscrit sur l'application" << endl ;
	}
	put_sth_for_come_back() ;
}



void Person::jobSeeker_to_employee()
{
	_status = 'e' ;

	// ... À COMPLETER
}



void Person::employee_to_jobSeeker()
{
	_status = 'j' ;
	
	// ... À COMPLETER
}




/*=========================
                         ||
	DELETE PROFILE      ||
                         ||
=========================*/

void Person::delete_profil()
{
	// ... À COMPLETER
}




/*===============================
                               ||
	SEARCH JOB VACANCY        ||
                               ||
===============================*/




void Person::search_position_by_skill() const
{
	vector<string> list_skills = input_skills() ;

	// ... À COMPLETER

	return ;
}



void Person::search_position_by_skill_postalCode() const
{
	vector<string> list_skills = input_skills() ;
	int postalCode = input_postalCode() ;

	if( postalCode == -1 ) return ;
	
	// ... À COMPLETER
	
	return ;
}




/*==================================
                                  ||
	SEARCH OLD COLLEAGUES        ||
                                  ||
==================================*/

void Person::search_colleagues_by_company() const
{
	string nameCompany ;

	cout << "\n Veuillez entrer le nom de l'entreprise: " << endl ;
	cin >> nameCompany ;
	
	// ... À COMPLETER
	
	return ;
}



void Person::search_colleagues_by_skill() const
{
	vector<string> list_skills = input_skills() ;

	// ... À COMPLETER
	
	return ;
}




/*========================
                        ||
	DISPLAY            ||
                        ||
========================*/

void Person::print_profil() const
{
	string useless ;
	
	system( "clear" ) ;
	cout << "\n\n" << endl ;
	cout << " ||==================|| " << endl ;
	cout << " ||                  || " << endl ;
	cout << " ||    MON PROFIL    || " << endl ;
	cout << " ||                  || " << endl ;
	cout << " ||==================|| " << endl << endl ;

	cout << "   Nom: " << _surname << endl ;
	cout << "   Prénom: " << _firstname << endl ;
	cout << "   Code Postal: " << _postalCode << endl ;
	cout << "   Email: " << _email << endl ;
	// cout << "Entreprise: " << company.get_name << endl ;
	print_listSkills() ;
	print_listOldColleagues() ;

	put_sth_for_come_back() ;
	cin >> useless ;
}





void Person::print_listSkills() const
{
	int i, n = _listSkills.size() ;
	
	cout << "   Liste des compétences:" ;
	if( n==0 ) cout << " (vide) " << endl ;
	else cout << endl ;

	for( i=0 ; i<n ; i++ )
	{
		cout << "\t" << "- " << _listSkills[i] << endl ;
	}
}



void Person::print_listOldColleagues() const
{
	int i, n = _listOldColleagues.size() ;
	Person c ;

	cout << "   Liste des anciens collègues:" ;
	if( n==0 ) cout << " (vide) " << endl ;
	else cout << endl ;
	
	for( i=0 ; i<n ; i++ )
	{
		c = _listOldColleagues[i] ;
		cout << "\t" << "- " << c._surname << " " << c._firstname << endl ;
	}
}




/*============================
                            ||
	ACCESSEURS             ||
                            ||
============================*/

char Person::get_status() const
{
	return _status ;
}

int Person::get_id() const
{
	return _id ;
}

string Person::get_surname() const
{
	return _surname ;
}

string Person::get_firstname() const
{
	return _firstname ;
}

int Person::get_postalCode() const
{
	return _postalCode ;
}

string Person::get_email() const
{
	return _email ;
}




/*============================
                            ||
	OTHERS                 ||
                            ||
============================*/

bool load_a_profil( int const& idPerson, Person &person )
{	
	// ... À COMPLETER

	return true ;
}



bool load_a_company( string const& nameCompany, Company &company )
{	
	// ... À COMPLETER

	return true ;
}



vector<string> input_skills()
{
	vector<string> list_skills ;
	string input ;
	bool exit = false ;

	cout << "\n Veuillez saisir les compétences qui vous interesse " << endl ;
	cout << " ( appuyer sur la touche 'entrée' 2 fois de suite pour finir la saisir ) " << endl ;
	do
	{
		cin >> input ;
		if( input == "" ) exit = true ;
		else list_skills.push_back( input ) ;
	} while( !exit ) ;

	return list_skills ;
}



int input_postalCode()
{
	int postalCode ;
	string answer ;
	
	cout << "\n Veuillez saisir le code postal qui vous interesse: " ;
	cin >> postalCode ;
	
	while( postalCode <= 0 )
	{
		cout << "\n Code postal invalide" << endl ;
		cout << " Voulez vous resaisir un code postal ? " << endl ;
		cout << " ( Tapez 'o' si oui ; 'n' si non ) " << endl ;
		cin >> answer ;

		if( answer == "o" ) { 
			cout << "\n Veuillez saisir le code postal qui vous interesse: " ;
			cin >> postalCode ;
		}
		else {
			cout << "Annulation recherche par code postal" << endl ;
			return -1 ;
		}
	}

	return postalCode ;
}




void put_sth_for_come_back()
{
	cout << "\n\n Entrez un numéro pour retourner au menu précédent: " ;
}