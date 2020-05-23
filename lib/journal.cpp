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

        flux<<endl<<"=============================================="<<endl;
        flux<<" Session of : " << dt<<" ";
        flux.close();
}


void intialise_user_journal(string user,string email)
{
  ofstream flux(tableJournal, ios::app);
  flux<<endl<<" User :"<<user<<endl;
  flux<<"=============================================="<<endl;
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
