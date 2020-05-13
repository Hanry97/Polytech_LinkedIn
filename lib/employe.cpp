#include <iostream>
#include "employe.h"
#include "fichier.h"
#include "constante.h"
#include <vector>
#include <string>
#include <sstream>


using namespace std;

employe::employe(string & nom, string & prenom, string & email, string & code_postal, vector<int> & colleagues, vector<string> & skills,int & id_enterprise)
    : jobseeker::jobseeker(nom, prenom, email, code_postal, skills)
{
    _colleagues = colleagues;
    _id_etp = id_enterprise;
}  

employe::~employe()
{

}

employe & employe::operator=(const employe &emp)
{
    _id = emp._id;
    _nom = emp._nom;
    _prenom = emp._prenom;
    _email = emp._code_postal;
    _code_postal = emp._code_postal;
    _skills = emp._skills;
    _colleagues = emp._colleagues;
    _id_etp = emp._id_etp;
    
    return *this;
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

int employe::updateEntreprise(int id_entreprise)
{
    int code;

    code = emp_update_enterprise(_id,id_entreprise);
    if(code == SUCCESS) _id_etp = id_entreprise;

    return code;
}

void employe::getEmployeByEmail(string & email, string & mdp)
{
    vector<string> data = login_byEmail(email,TAG_EMPLOYE);
    
    if(data.size() >= 1)
    {
        _id = stoi(data[0]);

        if(password_existAndOk(_id,mdp,TAG_EMPLOYE) == true)
        {
            _nom = data[1];
            _prenom = data[2];
            _email = data[3];
            _code_postal = data[4];

            string word;
            stringstream s(data[5]);

            while (getline(s, word, ';')) { 
                _skills.push_back(word); 
            }

            if(data[6] != "")
            {
                stringstream ss(data[6]);

                while (getline(ss, word, ';')) { 
                    _colleagues.push_back(stoi(word)); 
                }
            }
            _id_etp = stoi(data[7]);
        }else{
            _id = -1;
        }
    }
}

int employe::createEmploye()
{
    int code;
    code = emp_create_profile(_nom,_prenom,_email,_code_postal,_skills,_colleagues,_id_etp);
    
    if(code == SUCCESS)
    {   
        int id_given = get_lastID(tableEmployes);
        code = create_password(id_given,_mdp,TAG_EMPLOYE);
        
        if(code == SUCCESS)
            _id = id_given;
    }
    return code;
}

int employe::deleteEmploye()
{
    int code;
    code = emp_delete_profile(_id);

    if(code == SUCCESS)
        code = delete_password(_id,TAG_EMPLOYE);
    
    return code;
}

vector<vector<string>> employe::searchJob(vector<string> & list_competence,string & code_postal)
{
    return jsk_searchJob(list_competence,code_postal);
}

vector<vector <string>> employe::find_former_colleagues_by_enterprise(int & enterprise)
{
    return jsk_find_former_colleagues_by_enterprise(enterprise);
}

vector<string> employe::getEntrepriseById(const int & id)
{
    return get_EntrepriseByID(id);
}

int employe::employeToJobseeker()
{
    return emp_profile_transition_to_jobseeker(_id,_id_etp);
}

int employe::updatemdp(string & n_mdp, string o_mdp)
{
    int code = update_password(_id,n_mdp,o_mdp,TAG_EMPLOYE);
    if(code == SUCCESS) _mdp = n_mdp;

    return code;
}