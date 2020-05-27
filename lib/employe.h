#ifndef _EMPLOYE_
#define _EMPLOYE_

#include "jobseeker.h"

//Classe Employe, décrit l'objet Employe qui
//repésente un employé.
//Employe est aussi la classe fille de Jobseeker
//de ce fait, hérites des attributs qui sont commumns à 
//un employé et à un jobseeker certaines fonction sont réécrites
//pour adapter l'insertion en base de données.

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
        int updatemdp(std::string & n_mdp, std::string o_mdp);


        void getEmployeByEmail(std::string & email, std::string & mdp);
        int createEmploye();
        int deleteEmploye();
        std::vector<std::vector<std::string>> searchJob(std::vector<std::string> & list_competence,std::string & code_postal);
        std::vector<std::vector <std::string>> find_former_colleagues_by_enterprise(int & enterprise);

        std::vector<std::string> getEntrepriseById(const int & id);

        int employeToJobseeker();


};



#endif
