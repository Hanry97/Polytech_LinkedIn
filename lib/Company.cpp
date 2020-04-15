/*==============================
                              ||
LAST MODIFICATION:            ||
	DATE: 03/04/2020         ||
	AUTHOR: Mihary R.        ||
                              ||
==============================*/

#include "Company.h"
using namespace std ;


Company::Company() {}

/*
Company::Company()
{
	cout << "\n Name: " ;
	cin >> _name ;
	cout << "\n Postal Code: " ;
	cin >> _postalCode ;
	cout << "\n email: " ;
	cin >> _email ;
}
*/



string Company::get_name() const
{
	return _name ;
}