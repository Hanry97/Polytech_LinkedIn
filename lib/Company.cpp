/*==============================
                              ||
LAST MODIFICATION:


//***************            ||
	DATE: 03/04/2020         ||
	AUTHOR: Mihary R.        ||
                              ||
==============================*/

#include <vector>
#include "Company.h"
using namespace std ;


Company::Company() {}   //contructeur



void create_company()                        //Ajouter un profil entreprise
{
	int code;                               //code contient le code erreur
	cout<< "************Create your company Account ***********"<< endl<< endl;
	cout << "\n Name: " ;
	cin >> name ;
	cout << "\n Postal Code: " ;
	cin >> postalCode ;
	cout << "\n email: " ;
	cin >> email ;

	                                       //Insertion dans le fichier
	code=etp_create_profile(name,PostalCode,email);

	if(code==0)cout << "++++++++++SUCCESFUL!++++++++++++"<< endl;
	else cout <<"-------------FAILURE! ERROR NUMBER : "<<code<<"------------"<< endl;

                            
}



void delete_company()
{
	int id_entreprise,code;
	cout<< "************Delete Your Company Account***********"<< endl<< endl;
	cout<<"Please,enter your Company's ID";
	cin >> id_entreprise;
	
	                                 //Insertion dans le fichier
	code=etp_delete_profile(id_entreprise);

	if(code==0)cout << "++++++++++SUCCESFUL!++++++++++++"<< endl;
	else cout <<"-------------FAILURE! ERROR NUMBER : "<<code<<"------------"<< endl;
}



//////////////////////////////JOB VACANCY/////////////////////////////////

void create_profile_jobVacancy() 
{
	int id_entreprise,code,i;
	std::vector<std::string> skills;           //Tableau de compétences
	std::string skill,titre;    

	cout<< "*************Add an offer for a vacancy position***********"<< endl<< endl;
	cout<<"Please,Enter the name of the position :";
	cin>>titre;

	cout<<"Please, List the skills required for this position"<< endl;
	cout<<"Enter "q" to quit skill's list"<< endl;  

	i=0;
	do{                                         //Boucle pour permettre la saisie de plusieur competence
		i++;								    //L utilisateur saisi q pour quitter la boucle
		cout<<"Skill N "<<i<<" :"<< endl;
		cin>>skill;
		if(skill!="q") skills.push_back(skill);   //Pour ne pas enregistrer la lettre q
		
	}while skill!="q";


	//A COMPLETER   //A COMPLETER   //A COMPLETER

	if(code==0)cout << "++++++++++SUCCESFUL!++++++++++++"<< endl;
	else cout <<"-------------FAILURE! ERROR NUMBER : "<<code<<"------------"<< endl;
	
}




void delete_profile_jobVacancy()
{
	int id_etp, id_poste,code;

	cout<<"Please,Enter the company's ID";
	cin>>id_etp;

	cout<<"Please,Enter the position ID"<< endl;
	cin>>id_poste;
	//penser a creer une fonction qui retourn l id d un poste a partie du titre

	code=etp_delete_profileOfPosition(id_etp,id_poste);

	if(code==0)cout << "++++++++++SUCCESFUL!++++++++++++"<< endl;
	else cout <<"-------------FAILURE! ERROR NUMBER : "<<code<<"------------"<< endl;
}


void search_by_skill(vector<string> const& skills ) const
{
 
	int id_entreprise,code,i;
	vector<string> skills;           //Tableau de compétences
	string skill;    

	cout<<"Please, List your skills "<< endl;
	cout<<"Enter "q" to quit skill's list"<< endl;  

	i=0;
	do{                                         //Boucle pour permettre la saisie de plusieur competence
		i++;								    //L utilisateur saisi q pour quitter la boucle
		cout<<"Skill N "<<i<<" :"<< endl;
		cin>>skill;
		if(skill!="q") skills.push_back(skill);   //Pour ne pas enregistrer la lettre q
		
	}while skill!="q";


	//A COMPLETER   //A COMPLETER   //A COMPLETER

	if(code==0)cout << "++++++++++SUCCESFUL!++++++++++++"<< endl;
	else cout <<"-------------FAILURE! ERROR NUMBER : "<<code<<"------------"<< endl;
}


void search_by_skill_postalCode(vector<string> const& skills, int const& postalCode ) const 
{

	int id_entreprise,code,i;
	vector<string> skills;           //Tableau de compétences
	string skill;    

	cout<<"Please, List your skills "<< endl;
	cout<<"Enter "q" to quit skill's list"<< endl;  

	i=0;
	do{                                         //Boucle pour permettre la saisie de plusieur competence
		i++;								    //L utilisateur saisi q pour quitter la boucle
		cout<<"Skill N "<<i<<" :"<< endl;
		cin>>skill;
		if(skill!="q") skills.push_back(skill);   //Pour ne pas enregistrer la lettre q
		
	}while skill!="q";


	//A COMPLETER   //A COMPLETER   //A COMPLETER

	if(code==0)cout << "++++++++++SUCCESFUL!++++++++++++"<< endl;
	else cout <<"-------------FAILURE! ERROR NUMBER : "<<code<<"------------"<< endl;
}


void print_listJobsVacancy() const 
{
	int code;
	
	//A COMPLETER   //A COMPLETER   //A COMPLETER

	if(code==0)cout << "++++++++++SUCCESFUL!++++++++++++"<< endl;
	else cout <<"-------------FAILURE! ERROR NUMBER : "<<code<<"------------"<< endl;

}



// Accessors

// Name
string get_name() const 
{
	return company.name;
}		
void set_name(string const& name1 ) 
{
	company.name=name1;
}

// Postal code
int get_postalCode() const 
{
	return company.postalCode;
}
void set_postalCode( int const& postalCode ) 
{
	company.postalCode=postalCode;
}


// Email
string get_mail() const 
{
	return company.email;
}

void set_mail( std::string const& email ) 
{
	company.email=email;
}
	