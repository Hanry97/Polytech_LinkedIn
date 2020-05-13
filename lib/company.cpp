#include <iostream>
#include "company.h"
#include "fichier.h"
#include "constante.h"
#include <vector>
#include <string>
#include <sstream>


using namespace std;

company::~company()
{

}
void company::getCompanyByEmail(string & email,string mdp)
{
    vector<string> data = login_byEmail(email,TAG_ENTREPRISE);
    
    if(data.size() >= 1)
    {
        _id = stoi(data[0]);

        if(password_existAndOk(_id,mdp,TAG_ENTREPRISE) == true)
        {
            _nom = data[1];
            _code_postal = data[2];
            _email = data[3];
        }else{
            _id = -1;
        }
    }
}

int company::createCompany()
{
    int code;
    code = etp_create_profile(_nom,_code_postal,_email);

    if(code == SUCCESS)
    {
        int id_given = get_lastID(tableEntreprise);
        code = create_password(id_given,_mdp,TAG_ENTREPRISE);
            
            if(code == SUCCESS)
                _id = id_given;
    }
    return code;
}

int company::deleteCompany()
{
    int code;
    code = etp_delete_profile(_id);
    if(code == SUCCESS)
        code = delete_password(_id,TAG_ENTREPRISE);
        
    return code;
}

int company::createPosition(Position & poste)
{
    return etp_create_profileOfPosition(poste.getTitre(),poste.getSkills(),poste.getEntrepriseId());
}

int company::deletePosition(int id_poste)
{
    int code;
    code = etp_delete_profileOfPosition(_id, id_poste);
    if(code == SUCCESS)
        code = delete_password(_id,TAG_ENTREPRISE);

    return code;
}

vector<vector<string>> company::searchToHire(vector<string> & list_competence,string & code_postal)
{
    return etp_searchToHire(list_competence,code_postal);
}

vector<string> company::getAllPosition()
{
    return get_AllPoste_fromEnterprise(_id);
}

company & company::operator=(const company &etp)
{
    _id = etp._id;
    _nom = etp._nom;
    _code_postal = etp._code_postal;
    _email = etp._email;

    return *this;
}

int company::updatemdp(string & n_mdp, string o_mdp)
{
    int code = update_password(_id,n_mdp,o_mdp,TAG_ENTREPRISE);
    if(code == SUCCESS) _mdp = n_mdp;

    return code;
}