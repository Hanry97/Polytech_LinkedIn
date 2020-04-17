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
	int code;
	cout<< "************Ajouter un profil pour votre entreprise***********"<< endl<< endl;
	cout << "\n Name: " ;
	cin >> name ;
	cout << "\n Postal Code: " ;
	cin >> postalCode ;
	cout << "\n email: " ;
	cin >> email ;

	                                       //Insertion dans le fichier
	code=etp_create_profile(name,PostalCode,email);

	return code;                            //code contient le code erreur
}



int delete_company()
{
	int id_entreprise,code;
	cout<< "************Supprimer le  profil de votre entreprise***********"<< endl<< endl;
	cout<<"Veuillez entre l'ID de votre entreprise";
	cin >> id_entreprise;
	
	                                 //Insertion dans le fichier
	code=etp_delete_profile(id_entreprise);
	
	return code;                      //le code erreur
}



//////////////////////////////JOB VACANCY/////////////////////////////////

int create_profile_jobVacancy() 
{
	int id_entreprise,code,i;
	std::vector<std::string> skills;           //Tableau de compétences
	std::string skill,titre;    

	cout<< "*************Publier une offre pour un Poste Vacant***********"<< endl<< endl;
	cout<<"Saisir l'intitulé du Poste :";
	cin>>titre;

	cout<<"Lister les compétences requises pour ce poste"<< endl;
	cout<<"Saisir q pour quitter"<< endl;  

	i=0;
	do{                                         //Boucle pour permettre la saisie de plusieur competence
		i++;								    //L utilisateur saisi q pour quitter la boucle
		cout<<"Competence N "<<i<<" :"<< endl;
		cin>>skill;
		if(skill!="q") skills.push_back(skill);   //Pour ne pas enregistrer la lettre q
		
	}while skill!="q";


	//A COMPLETER   //A COMPLETER   //A COMPLETER
	
}


etp_delete_profileOfPosition(int id_etp,int id_poste)

int delete_profile_jobVacancy()
{
	int id_etp, id_poste,code;

	cout<<"Saisir l'ID de l'entreprise";
	cin>>id_etp;

	cout<<"Saisir l'ID du poste a supprimer";
	cin>>id_poste;
	//penser a creer une fonction qui retourn l id d un poste a partie du titre

	code=etp_delete_profileOfPosition(id_etp,id_poste);
}


int search_by_skill(vector<string> const& skills ) const
{

}






string Company::get_name() const
{
	return _name ;
}

int get_postalCode() const 
{
	return _postalCode;
}

	