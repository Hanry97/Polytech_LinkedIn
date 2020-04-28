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
#include "fichier.h"
class Company
{
	public:	
		// Functionnal specifications

			// Creation
				Company() ;																					// Create the profil of the company
				Company(int id_etp,std::string const& name, std::string const& postalCode, std::string const& email ) ;						//
				void create_company();
				void delete_company();
			
			// Job vacancy																				
				void create_profile_jobVacancy() ;			// Create a job vacancy and add it to "_listJobsVacancy"			
				void delete_profile_jobVacancy() ;											// Delete of "_listJobsVacancy"  the job vacancy passed in argument

			// Search																							// The 2 next fonctions print surname, firstname and email address
				void search_by_skill();									// Search the job seekers corresponding to the skills			
				void search_by_skill_postalCode();			// Search the job seekers corresponding to the skills and the postal code		
		
																										
		// Accessors
			// Name
				std::string get_name() const ;			
				void set_name( std::string const& name ) ;
			// Postal code
				std::string get_postalCode() const ;
				void set_postalCode( int const& postalCode ) ;
			// Email
				std::string get_mail() const ;
				void set_mail( std::string const& email ) ;
			//ID
			     int get_etpId() const ;
				  void set_etpId( int const& Id ) ;


		// Others		
			void print_listJobsVacancy() const ;																	// Print the list of jobs vacancy


	private:
		int etpId;
		std::string name ;
		std::string postalCode ;
		std::string email ;
		std::vector<Position> listJobsVacancy ;	
		//std::string _																// list of job vacancy
} ;


#endif