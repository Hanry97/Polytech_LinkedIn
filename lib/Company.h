/*==============================
                              ||
LAST MODIFICATION:            ||
	DATE: 04/04/2020         ||
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

			// Creation
				Company() ;																					// Create the profil of the company
				Company( std::string const& name, int const& postalCode, std::string const& email ) ;						//
				int create_company();
				int delete_company();
			// Deletion
				void delete_profile() ;																			// Delete the profile of the company
				~Company() ;																					// (  IL FAUDRA NOTAMMENT DETRUIRE '_listSkills' PROPREMENT DE SORTE QU'IL N'Y AIT PAS DE FUITE DE MEMOIRE  )

			// Job vacancy																				
				int create_profile_jobVacancy() ;			// Create a job vacancy and add it to "_listJobsVacancy"			
				int delete_profile_jobVacancy() ;											// Delete of "_listJobsVacancy"  the job vacancy passed in argument

			// Search																							// The 2 next fonctions print surname, firstname and email address
				int search_by_skill( std::vector<std::string> const& skills ) const ;									// Search the job seekers corresponding to the skills			
				int search_by_skill_postalCode( std::vector<std::string> const& skills, int const& postalCode ) const ;			// Search the job seekers corresponding to the skills and the postal code		
		
																										
		// Accessors
			// Name
				std::string get_name() const ;			
				void set_name( std::string const& name ) ;
			// Postal code
				int get_postalCode() const ;
				void set_postalCode( int const& postalCode ) ;
			// Email
				std::string get_mail() const ;
				void set_mail( std::string const& email ) ;


		// Others		
			void print_listJobsVacancy() const ;																	// Print the list of jobs vacancy


	private:
		std::string name ;
		int postalCode ;
		std::string email ;
		std::vector<Position> listJobsVacancy ;	
		//std::string _																// list of job vacancy
} ;


#endif