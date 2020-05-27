#ifndef _COMPANY_
#define _COMPANY_

#include "Position.h"

//Classe Company, décrit l'objet Company qui
//repésente une entreprise

class company
{
    private:
        int _id;
        std::string _nom;
        std::string _code_postal;
        std::string _email;
        std::string _mdp;
        
    public:
        company(): _id(-1) {};
        company(std::string nom, std::string code_postal, std::string email) : _nom(nom), _code_postal(code_postal), _email(email) {};
        ~company();
        company & operator=(const company & etp);

        int getId() const { return _id; };
        std::string getNom() const { return _nom; };
        std::string getCodePostal() const { return _code_postal;};
        std::string getEmail() const { return _email;};
        std::string getMdp() const { return _mdp;};

        void setNom(std::string & nom) { _nom = nom;};
        void setCodePostal(std::string & code_postal) { _code_postal = code_postal;};
        void setEmail(std::string & email) { _email = email;};
        void setMdp(std::string & mdp) { _mdp = mdp;};

        void getCompanyByEmail(std::string & email, std::string mdp);
        int createCompany();
        int deleteCompany();
        int updatemdp(std::string & n_mdp, std::string o_mdp);

        int createPosition(Position & poste);
        int deletePosition(int id_poste);
        std::vector<std::string> getAllPosition();

        std::vector<std::vector<std::string>> searchToHire(std::vector<std::string> & list_competence,std::string & code_postal);
};



#endif
