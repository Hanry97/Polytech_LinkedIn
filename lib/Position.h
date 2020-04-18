/*==============================
                              ||
LAST MODIFICATION:            ||
	DATE: 03/04/2020         ||
	AUTHOR: Mihary R.        ||
                              ||
==============================*/

#ifndef __POSITION__
#define __POSITION__

#include <iostream>
#include <vector>


class Position
{
	public:
		// Creation
			Position( std::string const& title ) ;		
			Position( std::string const& title, std::vector<std::string> const& skills ) ;

		// Deletion
			void delete_position() ;
		//	~Position() ;																				// 

		// Name
			std::string get_title() const ;
			void set_title( std::string const& title ) ;
		
		// Skills
			void print_listSkills() const ;
			void add_skill( std::string const& skill ) ;
			void delete_skill( std::string const& skill ) ;


	private:
		std::string _title ;
		std::vector<std::string> _listSkills ;		
} ;


#endif
