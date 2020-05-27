/*==============================
                              ||
    LAST MODIFICATION:        ||
	DATE: 03/04/2020          ||
	AUTHOR: Mihary R.         ||
                              ||
==============================*/

#include <iostream>
#include "Position.h"

using namespace std ;
Position::Position(){

}

Position::~Position(){

}

Position::Position(string const& title, vector<string> const& skills, int id_entreprise)
{
    _id = -1;
    _titre = title;
    _id_entreprise = id_entreprise;

    for(size_t i=0; i<skills.size(); i++)
        _skills.push_back(skills[i]);
}

void Position::setSkills(vector<string> & skills)
{
    _skills.clear();
    _skills = skills;
}
