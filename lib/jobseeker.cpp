#include <iostream>
#include "jobseeker.h"
#include "fichier.h"
#include "constante.h"

using namespace std;

jobseeker::jobseeker(string & nom, string & prenom, string & email, string & code_postal, vector<string> & skills )
{
    _id = -1;
    _nom =nom;
    _prenom = prenom;
    _email = email;
    _code_postal = code_postal;
    _skills = skills;
    _colleagues.clear();
}

jobseeker::~jobseeker()
{
    //Appeller à 
}

void jobseeker::setSkills(vector<string> & skills)
{
    int taille = skills.size();

    for (int i = 0; i < taille; i++)
            _skills.push_back(skills[i]);
}
void jobseeker::setColleagues(vector<int> & colleagues)
{
    int taille = colleagues.size();
    
    for (int i = 0; i < taille; i++)
            _colleagues.push_back(colleagues[i]);
}

int jobseeker::addSkill(vector<string> & skills)
{
    int code;
    int taille = skills.size();
    
    code = jsk_add_skills(_id,skills);
    if(code == SUCCESS)
        for (int i = 0; i < taille; i++)
            _skills.push_back(skills[i]);

    return code;
}

int jobseeker::addColleague(vector<int> & colleagues)
{
    int code;
    int taille = colleagues.size();
    
    code = jsk_add_colleague(_id,colleagues);
    if(code == SUCCESS)
        for (int i = 0; i < taille; i++)
            _colleagues.push_back(colleagues[i]);
    

    return code;
}

int jobseeker::updateCodePostal(string & code_postal)
{
    int code;
    
    code = jsk_update_code_postal(_id,code_postal);
    if(code == SUCCESS)
        _code_postal = code_postal;
    
    return code;
}

void jobseeker::getJobseekerByEmail(string & email)
{
    
}

int jobseeker::createJobseeker()
{
    int code;
    code = jsk_create_profile(_nom,_prenom,_email,_code_postal,_skills);
    if(code == SUCCESS)
    {   
        int id;
        id = get_lastID(tableJobseeker);
        _id = id;
    }
    return code;
}

int jobseeker::deleteJobseeker()
{
    int code;
    code = jsk_delete_profile(_id);
    return code;
}

vector<vector<string>> jobseeker::searchJob(vector<string> & list_competence,string & code_postal)
{
    return jsk_searchJob(list_competence,code_postal);
}

vector<vector <string>> jobseeker::find_former_colleagues_by_enterprise(int & enterprise)
{
    return jsk_find_former_colleagues_by_enterprise(enterprise);
}