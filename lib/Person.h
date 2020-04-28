/*==============================
                              ||
LAST MODIFICATION:            ||
	DATE: 15/04/2020         ||
	AUTHOR: Mihary R.        ||
                              ||
==============================*/


#ifndef __PERSON__
#define __PERSON__

#include "Company.h"
#include <iostream>
#include <vector>


class Person
{
	public:
		// Functionnal specifications
		
			// Creation
				Person() ;
				void create_profil( char const& status ) ;																																					// Create a profile
				bool load_my_profil() ;									// in order to connect
																	// Ask the user an id and a password
																	// If the couple (id, password) is correct, then:
																		// - fill the current object and
																		// - return true  
																	// Otherwise return false
			// profil modification
				void add_skill() ;				
				void add_oldColleague() ;
				void modify_postalCode() ;
				void modify_company() ;
				void jobSeeker_to_employee() ;		
				void employee_to_jobSeeker() ; 							// the employees of the company left are added automaticlly to the list of old colleagues

			// Deletion profil
				void delete_profil() ;
			
			// Search job vacancy										// The 2 next fonctions print: postition title, company name, company email adress, company postal code
				void search_position_by_skill() const ;							// Seach jobs vacancy corresponding to the skills enter by the user																														
				void search_position_by_skill_postalCode() const ;				// Seach jobs vacancy corresponding to the skills enter by the user	
		
			// Search old colleagues										// The 2 next fonctions print: surname, firstname, email adress
				void search_colleagues_by_company() const ;						// Search the old colleagues who are in the company entered by the user
				void search_colleagues_by_skill() const ;						// Search the old colleagues who have the skills entered by the user																	

		// Display		
				void print_profil() const ;
				void print_listSkills() const ;
				void print_listOldColleagues() const ;

		// Getters
				char get_status() const ;
				int get_id() const ;
				std::string get_surname() const ;
				std::string get_firstname() const ;
				int get_postalCode() const ;
				std::string get_email() const ;
				

			
	private:
		char _status ;																			// 'e' <--> employee  ;  'j' <-->  job_seeker
		int _id ;
		std::string _password ;																	
		
		std::string _surname ;
		std::string _firstname ;
		int _postalCode ;
		std::string _email ;           
		std::vector<std::string> _listSkills ;
		std::vector<Person> _listOldColleagues ;
		Company _company ;
} ;



/*============================
                            ||
	OTHERS                 ||
                            ||
============================*/

// Put the person with the id 'idPerson' in the argument 'person'
// The person is load in the argument 'person'
// Return true if the loading is succesful ; false otherwise
bool load_a_profil( int const& idPerson, Person &person ) ;

// Put the co
// The company is load in the argument 'company'
// Return true if the loading is succesful ; false otherwise
bool load_a_company( std::string const& nameCompany, Company &company ) ;


// Return a list of skills 
// These skills are input by the user
std::vector<std::string> input_skills() ;

// Return a postal code input by the user
int input_postalCode() ;


void put_sth_for_come_back() ;


#endif