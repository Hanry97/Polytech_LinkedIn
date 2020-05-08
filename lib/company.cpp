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
void company::getCompanyByEmail(string & email)
{
    vector<string> data = login_byEmail(email,TAG_ENTREPRISE);
    
    if(data.size() >= 1)
    {
        _id = stoi(data[0]);
        _nom = data[1];
        _code_postal = data[2];
        _email = data[3];
    }
}

int company::createCompany()
{
    return etp_create_profile(_nom,_code_postal,_email);
}
int company::deleteCompany()
{
    return etp_delete_profile(_id);
}

int company::createPosition(Position & poste)
{
    return etp_create_profileOfPosition(poste.getTitre(),poste.getSkills(),poste.getEntrepriseId());
}

int company::deletePosition(int id_poste)
{
    return etp_delete_profileOfPosition(_id, id_poste);
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