#ifndef _JOBSEEKER_
#define _JONSEEKER_

#include <vector>

//Classe Jobseeker, décrit l'objet Jobseeker qui
//repésente un demandeur d'emploi.
//Jobseeker est aussi la classe mère d'employé
//de ce fait, certaines de ses fonctions sont virtuelles
//pour ne pas causer de confusion quand elles seront reécrites dans
//employé.

class jobseeker
{
    protected:
        int _id;
        std::string _nom;
        std::string _prenom;
        std::string _email;
        std::string _code_postal;
        std::string _mdp;
        std::vector<std::string> _skills;
        std::vector<int> _colleagues;

    public:
        jobseeker() : _id(-1) {};
        jobseeker(std::string & nom, std::string & prenom, std::string & email, std::string & code_postal, std::vector<std::string> & skills );
        ~jobseeker();
        jobseeker & operator=(const jobseeker & jsk);

        int getId() const {  return _id;};
        std::string getNom() const {  return _nom;};
        std::string getPrenom() const {  return _prenom;};
        std::string getEmail() const {  return _email;};
        std::string getCodePostal() const {  return _code_postal;};
        std::string getMdp() const { return _mdp;};
        std::vector<std::string> getSkills() const {  return _skills;};
        std::vector<int> getColleagues() const {  return _colleagues;};

        void setId(int & id) { _id = id;};
        void setNom(std::string & nom) { _nom = nom;};
        void setPrenom(std::string & prenom) { _prenom = prenom;};
        void setEmail(std::string & email) { _email = email;};
        void setCodePostal(std::string & code_postal) { _code_postal = code_postal;};
        void setMdp(std::string & mdp) { _mdp = mdp;};
        void setSkills(std::vector<std::string> & skills);
        void setColleagues(std::vector<int> & colleagues);

        virtual int addSkill(std::vector<std::string> & skills);
        virtual int addColleague(std::vector<int> & colleagues);
        virtual int updateCodePostal(std::string & code_postal);
        virtual int updatemdp(std::string & n_mdp, std::string o_mdp);


        virtual void getJobseekerByEmail(std::string & email, std::string & mdp);
        virtual int createJobseeker();
        virtual int deleteJobseeker();
        std::vector<std::string> searchEntreprise(std::string & nom, std::string code_postal);
        virtual std::vector<std::vector<std::string>> searchJob(std::vector<std::string> & list_competence,std::string & code_postal);
        virtual std::vector<std::vector <std::string>> find_former_colleagues_by_enterprise(int & enterprise);
        std::vector<std::vector <std::string>> find_former_colleagues_by_skills();

        virtual int jobseekerToEmploye(int id_etp);

        std::vector<std::string> getOldColleaguesById(std::vector<int> & list_id);

};


#endif
