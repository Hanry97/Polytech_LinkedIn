/*==============================
                              ||
LAST MODIFICATION:            ||
	DATE: 03/04/2020         ||
	AUTHOR: Mihary R.        ||
                              ||
==============================*/

#ifndef __POSITION__
#define __POSITION__

#include "Company.h"
#include <iostream>
#include <vector>


class Position
{
	public:
		// Creation
			Position( std::string const& title, Company const& company ) ;
			Position( std::string const& title, Company const& company, std::vector<std::string> const& skills ) ;

		// Deletion
			void delete_position() ;
			~Position() ;																				// (  IL FAUDRA NOTAMMENT DETRUIRE '_listSkills' PROPREMENT DE SORTE QU'IL N'Y AIT PAS DE FUITE DE MEMOIRE  )

		// Name
			std::string get_title() const ;
			void set_title( std::string const& title ) ;
		
		// Company
			Company get_company() const ;
			void set_company( Company const& company) ;

		// Skills
			void print_listSkills() const ;
			void add_skill( std::string const& skill ) ;
			void delete_skill( std::string const& skill ) ;


	private:
		std::string _title ;
		Company _company ;
		std::vector<std::string> _listSkills ;		
} ;


#endif