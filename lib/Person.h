/*==============================
                              ||
LAST MODIFICATION:            ||
	DATE: 04/04/2020         ||
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
				Person() ;																									// Create a profile
				Person( std::string const& _surname, std::string const& _firstname, std::string const& _email, Company const& _company ) ;			//
			
			// Modify profil
				void add_skill( std::string const& skill ) ;				
				void delete_skill( std::string const& skill ) ;
				void add_oldColleague( Person colleague ) ;
				void modify_postalCode( int const& postalCode ) ;
				void jobSeeker_to_employee() ;				
				void employee_to_job_seeker() ;

			// Deletion profil
				void delete_profil() ;																							// Deleate a profile
				~Person() ;																									// (  IL FAUDRA NOTAMMENT DETRUIRE '_listSkills' et '_listOldColleagues' PROPREMENT DE SORTE QU'IL N'Y AIT PAS DE FUITE DE MEMOIRE  )
			
			// Search job vacancy																								// The 2 next fonctions print: postition title, company name, company email adress, company postal code
				void search_position_by_skill() const ;																				// Seach jobs vacancy corresponding to its competences																															
				void search_position_by_skill_postalCode( std::vector<std::string> const& skills, int const& postalCode ) const ;					// Seach jobs vacancy corresponding to its competences and its postal code		
		
			// Search among old colleagues																						// The 2 next fonctions print: surname, firstname, email adress
				void search_colleagues_by_company( std::string const& company ) const ;													// Search the old colleagues who are in the company passed in argument
				void search_colleagues_by_competences( std::vector<std::string> listSkills ) const ;											// Search the old colleagues who have the skills passed in argument																	


		// Accessors
			// Status
				char get_status() ;
				void set_status( char status ) ;
			// Surname
				std::string get_surname() const ;
				void set_surname( std::string const& surname )  ;
			// Postal Code
				int get_postalCode() ;
				void set_postalCode( int const& postalCode ) ;
			// Email
				std::string get_email() const ;
				void set_email( std::string const& email ) ;
			// ...

			
	private:
		char _status ;																											// e <--> employee | j <--> job_seeker
		std::string _surname ;
		std::string _firstname ;
		int _postalCode ;
		std::string _email ;
		std::vector<std::string> _listSkills ;
		std::vector<Person> _listOldColleagues ;
		Company _company ;
} ;


#endif