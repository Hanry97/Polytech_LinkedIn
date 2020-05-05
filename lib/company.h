#ifndef _COMPANY_
#define _COMPANY_

#include "Position.h"

class company
{
    private:
        int _id;
        std::string _nom;
        std::string _code_postal;
        std::string _email;
        
    public:
        company();
        company(std::string nom, std::string code_postal, std::string email) : _nom(nom), _code_postal(code_postal), _email(email) {};
        ~company();

        int getId() const;
        std::string getNom() const;
        std::string getCodePostal() const;
        std::string getEmail() const;

        void setNom(std::string & nom) { _nom = nom;};
        void setCodePostal(std::string & code_postal) { _code_postal = code_postal;};
        void setEmail(std::string & email) { _email = email;};

        void getCompanyByEmail(std::string & email) const;
        int createCompany();
        int deleteCompany();

        int createPosition(Position & poste);
        int deletePosition(Position & poste);

        std::vector<std::vector<std::string>> searchToHire(std::vector<std::string> & list_competence,std::string & code_postal);
};

company::company()
{
}

company::~company()
{
}


#endif
