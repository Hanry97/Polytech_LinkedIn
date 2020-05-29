#include "journal.h"
#include <iostream>
#include <fstream>
#include "constante.h"
#include <sstream>



using namespace std;
//======================JOURNAL============================//

void intialise_date_journal(time_t a)
{
    char* dt = ctime(&a);       // convertir en forme de chaîne

    ofstream flux(tableJournal, ios::app);

        flux<<endl<<"================================================================="<<endl;
        flux<<" Session du : " << dt<<" ";
        flux.close();
}


void intialise_user_journal(string user)
{
  ofstream flux(tableJournal, ios::app);
  flux<<endl<<" User :"<<user<<endl<<"++++++++++++++"<<endl;
  flux.close();
}




void memorise(string a)
{
    time_t actuel = time(0);
    tm *ltm = localtime(&actuel);

     ofstream flux(tableJournal, ios::app);
     flux<<ltm->tm_hour<<":"<< ltm->tm_min<<":"<< ltm->tm_sec;
     flux<<"--> "<<a<<" ; ";
    flux.close();
}


void memorise_avec_code(string a,int code)
{
    time_t actuel = time(0);
    tm *ltm = localtime(&actuel);

    ofstream flux(tableJournal, ios::app);
    flux<<ltm->tm_hour<<":"<< ltm->tm_min<<":"<< ltm->tm_sec;
    flux<<" <--"<<"("<<a<<", "<<code<< " )"<<" ; ";

    flux.close();
}

void fin_de_session(time_t debut)
{
    time_t tmm = time(0);
    char* dt = ctime(&tmm);
    ofstream flux(tableJournal, ios::app);
    flux<<endl<<"+++++++++++"<<endl<<"Fin de session:" <<dt<<"Duree d'execution="<<difftime (tmm,debut)<<" s"<<endl;
    flux<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    flux.close();
}


void intialise_etp_journal(string a,string postalcode)
{
    time_t actuel = time(0);
    tm *ltm = localtime(&actuel);

    ofstream flux(tableJournal, ios::app);
    flux<<endl<<"++++++++++++++"<<endl<<"Statut: Connecte"<<" a "<<ltm->tm_hour<<":"<< ltm->tm_min<<":"<< ltm->tm_sec;
    flux<<endl<<"Type: Entreprise "<<endl<<"Nom :"<<a<<endl<<"Code Postal :"<<postalcode;
    flux<<endl<<"================================================================="<<endl;
    flux.close();
}

void intialise_jsk_journal(string a,string postalcode)
{
    time_t actuel = time(0);
    tm *ltm = localtime(&actuel);

    ofstream flux(tableJournal, ios::app);
    flux<<endl<<"++++++++++++++"<<endl<<"Statut: Connecte"<<" a "<<ltm->tm_hour<<":"<< ltm->tm_min<<":"<< ltm->tm_sec;
    flux<<endl<<"Type: Chercheur d'emploi "<<endl<<"Nom :"<<a<<endl<<"Code Postal :"<<postalcode;
    flux<<endl<<"================================================================="<<endl;
    flux.close();
}

void intialise_emp_journal(string a,string postalcode)
{
    time_t actuel = time(0);
    tm *ltm = localtime(&actuel);
 
    ofstream flux(tableJournal, ios::app);
    flux<<endl<<"++++++++++++++"<<endl<<"Statut: Connecte"<<" a "<<ltm->tm_hour<<":"<< ltm->tm_min<<":"<< ltm->tm_sec;
    flux<<endl<<"Type: Employer "<<endl<<"Nom :"<<a<<endl<<"Code Postal :"<<postalcode;
    flux<<endl<<"================================================================="<<endl;
    flux.close();
}

void login_fail_journal()
{
    time_t actuel = time(0);
    tm *ltm = localtime(&actuel);

    ofstream flux(tableJournal, ios::app);
    flux<<endl<<"++++++++++++++"<<endl<<"Statut: acces refuse" <<"  ("<<ltm->tm_hour<<":"<< ltm->tm_min<<":"<< ltm->tm_sec<<")";
    flux<<endl<<"================================================================="<<endl;
    flux.close();
}

void initialise_new_etp(company etp)
{
    time_t actuel = time(0);
    tm *ltm = localtime(&actuel);

   ofstream flux(tableJournal, ios::app);
   flux<<endl<<"--------------------------------"<<endl;
   flux<<"New company added("<<etp.getNom()<<", "<<etp.getEmail()<<", "<<etp.getCodePostal()<<")"<<" at "<<ltm->tm_hour<<":"<< ltm->tm_min<<":"<< ltm->tm_sec<<endl;
   flux<<"--------------------------------"<<endl;
  flux.close();
}

void initialise_new_jsk(jobseeker jsk)
{
    time_t actuel = time(0);
    tm *ltm = localtime(&actuel);

   ofstream flux(tableJournal, ios::app);
   flux<<endl<<"--------------------------------"<<endl;
   flux<<"New jobseeker added("<<jsk.getNom()<<", "<<jsk.getEmail()<<", "<<jsk.getCodePostal()<<")"<<" at "<<ltm->tm_hour<<":"<< ltm->tm_min<<":"<< ltm->tm_sec<<endl;
   flux<<"--------------------------------"<<endl;
  flux.close();  
}
void initialise_new_emp(employe emp)
{
    time_t actuel = time(0);
    tm *ltm = localtime(&actuel);

   ofstream flux(tableJournal, ios::app);
   flux<<endl<<"--------------------------------"<<endl;
   flux<<"New employe added("<<emp.getNom()<<", "<<emp.getEmail()<<", "<<emp.getCodePostal()<<")"<<" at "<<ltm->tm_hour<<":"<< ltm->tm_min<<":"<< ltm->tm_sec<<endl;
   flux<<"--------------------------------"<<endl;
  flux.close();  
}