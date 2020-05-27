#include <iostream>
#include "jobseeker.h"
#include "fichier.h"
#include "constante.h"
#include <vector>
#include <string>
#include <sstream>


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
}

jobseeker & jobseeker::operator=(const jobseeker &jsk)
{
    _id = jsk._id;
    _nom = jsk._nom;
    _prenom = jsk._prenom;
    _email = jsk._code_postal;
    _code_postal = jsk._code_postal;
    _skills = jsk._skills;
    _colleagues = jsk._colleagues;

    return *this;
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

void jobseeker::getJobseekerByEmail(string & email, string & mdp)
{
    
    vector<string> data = login_byEmail(email,TAG_JOBSEEKER);
    
    if(data.size() >= 1)
    {
        _id = stoi(data[0]);

         if(password_existAndOk(_id,mdp,TAG_JOBSEEKER) == true)
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

            if(data.size() == 7)
            {
                stringstream ss(data[6]);

                while (getline(ss, word, ';')) { 
                    _colleagues.push_back(stoi(word)); 
                }
            }
        }else{
            _id = -1;
        }
    }
}

int jobseeker::createJobseeker()
{
    int code;
    code = jsk_create_profile(_nom,_prenom,_email,_code_postal,_skills);
    
    if(code == SUCCESS)
    {   
        int id_given = get_lastID(tableJobseeker);
        code = create_password(id_given,_mdp,TAG_JOBSEEKER);
        
        if(code == SUCCESS)
            _id = id_given;
    }

    return code;
}

int jobseeker::deleteJobseeker()
{
    int code;
    code = jsk_delete_profile(_id);
    
    if(code == SUCCESS)
        code = delete_password(_id,TAG_JOBSEEKER);
        
    return code;
}

vector<string> jobseeker::searchEntreprise(string & nom, string code_postal)
{
    return jsk_search_entreprise(nom, code_postal);
}

vector<vector<string>> jobseeker::searchJob(vector<string> & list_competence,string & code_postal)
{
    return jsk_searchJob(list_competence,code_postal);
}

vector<vector <string>> jobseeker::find_former_colleagues_by_enterprise(int & enterprise)
{
    return jsk_find_former_colleagues_by_enterprise(enterprise);
}

vector<vector <string>> jobseeker::find_former_colleagues_by_skills()
{
    return jsk_find_former_colleagues_by_skills(_colleagues,_skills);
}

int jobseeker::jobseekerToEmploye(int id_etp)
{
    return jsk_profile_transition_to_employe(_id, id_etp);
}

vector<string> jobseeker::getOldColleaguesById(vector<int> & list_id)
{
    return jsk_get_old_colleagues_by_id(list_id);
}

int jobseeker::updatemdp(string & n_mdp, string o_mdp)
{
    int code = update_password(_id,n_mdp,o_mdp,TAG_JOBSEEKER);
    if(code == SUCCESS) _mdp = n_mdp;

    return code;
}