#include <vector>
#include "Company.h"

using namespace std ;


Company::Company() {}   //contructeur par défaut 

Company::Company(int id,string const& Name, string const& PostalCode, string const& Email )  //Contructeur paramétré
{
	etpId=id;
	name=Name;
	postalCode=PostalCode;
	email=Email;
}



void Company::create_company()                        //Ajouter un profil entreprise
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
	code=etp_create_profile(name,postalCode,email);

	if(code==0)cout << "++++++++++SUCCESFUL!++++++++++++"<< endl;
	else cout <<"-------------FAILURE! ERROR NUMBER : "<<code<<"------------"<< endl;

                            
}



void Company::delete_company()
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

void Company::create_profile_jobVacancy() 
{
	int code,i;
	int entreprise_id;
	vector<string> skills;           //Tableau de compétences
	string skill,titre;    

	cout<< "*************Add an offer for a vacancy position***********"<< endl<< endl;
	cout<<"Please,Enter the name of the position :";
	cin>>titre;

	cout<<"Please, List the skills required for this position"<< endl;
	cout<<"Enter 'q' to quit skill's list"<< endl;  

	i=0;
	do{                                         //Boucle pour permettre la saisie de plusieur competence
		i++;								    //L utilisateur saisi q pour quitter la boucle
		cout<<"Skill N "<<i<<" :"<< endl;
		cin>>skill;
		if(skill!="q") skills.push_back(skill);   //Pour ne pas enregistrer la lettre q
		
	}while(skill!="q");

	entreprise_id=Company::get_etpId();
    code= etp_create_profileOfPosition(titre,skills,entreprise_id);

	if(code==0)cout << "++++++++++SUCCESFUL!++++++++++++"<< endl;
	else cout <<"-------------FAILURE! ERROR NUMBER : "<<code<<"------------"<< endl;
	
}




void Company::delete_profile_jobVacancy()
{
	int id_etp, id_poste,code;

	/*cout<<"Please,Enter the company's ID";
	cin>>id_etp;*/
	id_etp=Company::get_etpId();     //JE NE SUIS PAS SURE

	cout<<"Please,Enter the position ID"<< endl;
	cin>>id_poste;
	//penser a creer une fonction qui retourn l id d un poste a partie du titre

	code=etp_delete_profileOfPosition(id_etp,id_poste);

	if(code==0)cout << "++++++++++SUCCESFUL!++++++++++++"<< endl;
	else cout <<"-------------FAILURE! ERROR NUMBER : "<<code<<"------------"<< endl;
}


/*void Company::search_by_skill() 
{
 
	int i;
	//int id_entreprise
	vector<string> list_competence,result_size;           //Tableau de compétences
	string skill,code_postal; 
	code_postal="#";  //Pour rechercher que par competence   

	cout<<"Please,Enter  List of competence "<< endl;
	cout<<"Enter 'q' to quit skill's list"<< endl;  

	i=0;
	do{                                         //Boucle pour permettre la saisie de plusieur competence
		i++;								    //L utilisateur saisi q pour quitter la boucle
		cout<<"Skill N "<<i<<" :"<< endl;
		cin>>skill;
		if(skill!="q")list_competence.push_back(skill);   //Pour ne pas enregistrer la lettre q
		
	}while(skill!="q");

	vector <vector <string> > result;
	result= etp_searchToHire(list_competence,code_postal);

	result_size=result.size();                         //Pour recup la taille du tableau
	for( i=0;i<result_size;i++){
		cout <<i+1<<"- ";
		for(int j=0;j<4;j++){
			cout<<result[i][j];
		}
		cout <<endl;
	}

	
}


void Company::search_by_skill_postalCode() 
{

	int code,i,j,result_size;
	//int id_entreprise
	vector<string> list_competence;           //Tableau de compétences
	string skill,code_postal; 

	cout<<"Please,	Enter the zip code "<< endl;
	cin>>code_postal;
	cout<<"Please, List required skills "<< endl;
	cout<<"Enter 'q' to quit skill's list"<< endl;  

	i=0;
	do{                                         //Boucle pour permettre la saisie de plusieur competence
		i++;								    //L utilisateur saisi q pour quitter la boucle
		cout<<"Skill N "<<i<<" :"<< endl;
		cin>>skill;
		if(skill!="q") list_competence.push_back(skill);   //Pour ne pas enregistrer la lettre q
		
	}while(skill!="q");

	vector <vector <string> > result;
	result= etp_searchToHire(list_competence,code_postal);

	result_size=result.size();                         //Pour recup la taille du tableau
	for( i=0;i<result_size;i++){
		cout <<i+1<<"- ";
		for( j=0;j<4;j++){
			cout<<result[i][j];
		}
		cout <<endl;
	}

	if(code==0)cout << "++++++++++SUCCESFUL!++++++++++++"<< endl;
	else cout <<"-------------FAILURE! ERROR NUMBER : "<<code<<"------------"<< endl;
}


void Company::print_listJobsVacancy() const 
{
	int code;
	
	//A COMPLETER   //A COMPLETER   //A COMPLETER

	if(code==0)cout << "++++++++++SUCCESFUL!++++++++++++"<< endl;
	else cout <<"-------------FAILURE! ERROR NUMBER : "<<code<<"------------"<< endl;

}
*/


// Accessors

// Name
string Company::get_name() const 
{
	return name;
}		
void Company::set_name(string const& name1 ) 
{
	name=name1;
}

// Postal code
string Company::get_postalCode() const 
{
	return postalCode;
}
void Company::set_postalCode( int const& PostalCode ) 
{
	postalCode=PostalCode;
}


// Email
string Company::get_mail() const 
{
	return email;
}

void Company::set_mail(string const& Email ) 
{
	email=Email;
}


//ID
int Company::get_etpId() const
{
	return etpId;
}
void Company::set_etpId( int const& ID )
{
	etpId=ID;
}
	