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
			Position( std::string name, std::vector<std::string> _skills, Company _company ) ;

		// Name
			std::string get_name() ;
			void set_name( std::string company ) ;
		
		// Skills
			void print_skills() ;
			void add_skills( std::vector<std::string> skills ) ;
			void delete_skills( std::vector<std::string> skills ) ;

		// Company
			Company get_company() ;
			void setCompany() ;


	private:
		std::string _name ;
		std::vector<std::string> _skills ;
		Company _company ;
} ;


#endif