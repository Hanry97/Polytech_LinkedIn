#include <iostream>
#include "company.h"
#include "fichier.h"

using namespace std;

void company::getCompanyByEmail(std::string & email) const
{
    
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

int company::deletePosition(Position & poste)
{
    return etp_delete_profileOfPosition(_id,poste.getId());
}

vector<vector<string>> company::searchToHire(vector<string> & list_competence,string & code_postal)
{
    return etp_searchToHire(list_competence,code_postal);
}