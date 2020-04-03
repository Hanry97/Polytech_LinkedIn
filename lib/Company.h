/*==============================
                              ||
LAST MODIFICATION:            ||
	DATE: 03/04/2020         ||
	AUTHOR: Mihary R.        ||
                              ||
==============================*/

#ifndef __COMPANY__
#define __COMPANY__

#include "Position.h"

#include <iostream>
#include <vector>


class Company
{
	public:	
		// Functionnal specifications
		
			Company( std::string name, int postalCode, std::string email ) ;							// Create the profil of the company

			void delete_profile() ;															// Delete the profile of the company
			
			void create_profile_jobVacancy( std::string title, std::vector<std::string> skills ) ;		// Create a job vacancy and add it to "_listJobsVacancy"
			
			void delete_profile_jobVacancy( std::string titre ) ;									// Delete the job vacancy of "_listJobsVacancy"

			void search_by_skill( std::vector<std::string> skills ) ;								// Search the job seekers corresponding to the skills
																						// Print: surname, firstname and email address
			
			void search_by_skill_postalCode( std::vector<std::string> skills, int postalCode ) ;			// Search the job seekers corresponding to the skills and the postal code		
																						// Print: surname, firstname and email address
		// Accessors

			std::string get_name() ;			
			void set_name( std::string name ) ;

			int get_postalCode() ;
			void set_postalCode( int postalCode ) ;

			std::string get_mail() ;
			void set_mail( std::string email ) ;

		// Others
			
			void print_listJobsVacancy() ;													// Print the list of jobs vacancy


	private:
		std::string _name ;
		int _postalCode ;
		std::string _email ;
		std::vector<Position> _listJobsVacancy ;												// list of job vacancy
} ;


#endif