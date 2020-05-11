#ifndef _EMPLOYE_
#define _EMPLOYE_

#include "jobseeker.h"

class employe : public jobseeker
{
    private:
        int _id_etp;

    public:
        employe() : jobseeker::jobseeker() {};
        employe(std::string & nom, std::string & prenom, std::string & email, std::string & code_postal, std::vector<int> & colleagues,std::vector<std::string> & skills, int & id_enterprise);
        ~employe();
        employe & operator=(const employe & emp);

        int getEnterpriseId() const { return _id_etp;};
        void setEnterpriseId(const int & id) { _id_etp = id;};

        int addSkill(std::vector<std::string> & skills);
        int addColleague(std::vector<int> & colleagues);
        int updateCodePostal(std::string & code_postal);
        int updateEntreprise(int id_entreprise);

        void getEmployeByEmail(std::string & email);
        int createEmploye();
        int deleteEmploye();
        std::vector<std::vector<std::string>> searchJob(std::vector<std::string> & list_competence,std::string & code_postal);
        std::vector<std::vector <std::string>> find_former_colleagues_by_enterprise(int & enterprise);

        std::vector<std::string> getEntrepriseById(const int & id);

        int employeToJobseeker();


};



#endif
