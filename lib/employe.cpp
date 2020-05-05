#include <iostream>
#include "employe.h"
#include "fichier.h"
#include "constante.h"

using namespace std;

employe::employe(string & nom, string & prenom, string & email, string & code_postal, vector<int> & colleagues, vector<string> & skills,int & id_enterprise)
{
    _id = -1;
    _nom =nom;
    _prenom = prenom;
    _email = email;
    _code_postal = code_postal;
    _skills = skills;
    _colleagues.clear();
    _colleagues = colleagues;
    _id_etp = id_enterprise;
}  

int employe::addSkill(vector<string> & skills)
{
    int code;
    int taille = skills.size();
    
    code = emp_add_skills(_id,skills);
    if(code == SUCCESS)
        for (int i = 0; i < taille; i++)
            _skills.push_back(skills[i]);

    return code;
}

int employe::addColleague(vector<int> & colleagues)
{
    int code;
    int taille = colleagues.size();
    
    code = emp_add_colleague(_id,colleagues);
    if(code == SUCCESS)
        for (int i = 0; i < taille; i++)
            _colleagues.push_back(colleagues[i]);
    

    return code;
}

int employe::updateCodePostal(std::string & code_postal)
{
    int code;
    
    code = emp_update_code_postal(_id,code_postal);
    if(code == SUCCESS)
        _code_postal = code_postal;
    
    return code;
}

void employe::getEmployeByEmail(std::string & email)
{

}

int employe::createEmploye()
{
    int code;
    code = emp_create_profile(_nom,_prenom,_email,_code_postal,_skills,_colleagues,_id_etp);
    if(code == SUCCESS)
    {   
        int id;
        id = get_lastID(tableEmployes);
        _id = id;
    }
    return code;
}

int employe::deleteEmploye()
{
    return emp_delete_profile(_id);
}

vector<vector<string>> employe::searchJob(vector<string> & list_competence,string & code_postal)
{
    return emp_searchJob(list_competence,code_postal);
}

vector<vector <string>> employe::find_former_colleagues_by_enterprise(int & enterprise)
{
    return emp_find_former_colleagues();
}

