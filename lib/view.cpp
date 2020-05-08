#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <sstream>

#include "view.h"
using namespace std;


//Page d'acceuil
int home_screen()
{
    int choice ;
    int code = EXIT_WITH_ERROR;

    while(choice != 9)
    {
        system( "clear" ) ;
        cout<<"================================================================================="<<endl;
        cout<<"||                        POLYTECH LINKEDIN C++                                ||"<<endl;
        cout<<"================================================================================="<<endl;
        cout<<"|                                                                               |"<<endl;
        cout<<"|                             1-INSCRIPTION                                     |"<<endl;
        cout<<"|                             2-CONNEXION                                       |"<<endl;
        cout<<"|                                                                               |"<<endl;
        cout<<"|                             9-QUITTER                                         |"<<endl;
        cout<<"================================================================================="<<endl;
        cout<<"\n Veuillez entrer le numero de votre choix: " ;
        cin >> choice ;
    
	    code = navigation_general_menu( choice ) ;
    }
    return code;
}

int navigation_general_menu( int const& choice )
{
	switch( choice )
	{
		case 1:
			return creation_screen();
		case 2:
			return login_screen();
		case 9:
			return quit() ;
		default:
			cout << "\n Ce numero n'existe pas " << endl ;
			return home_screen() ;
	}
}

int quit()
{
    return EXIT_PROGRAM;
}

//vérifi que l'email contient le symbole @
bool isValidEmail(std::string email)
{
    size_t found = email.find("@");

    if(found != string::npos) return true;
        else return false;
}

//Page de connexion
int login_screen()
{
    int code = 0;
    string email;

    cout << "\n\n Email :  "; cin >> email;

    if(isValidEmail(email))
    {
        company etp;
        etp.getCompanyByEmail(email);
        
        if(etp.getId() != -1)
        {
            code = etp_home(etp);
        }
        else
        {
            jobseeker jsk;
            jsk.getJobseekerByEmail(email);
            
            if(jsk.getId() != -1)
            {
                code = jsk_home(jsk);
            }
            else
            {
                employe emp;
                emp.getEmployeByEmail(email);

                if(emp.getId() != -1)
                {
                    code = emp_home(emp);
                }    
                else 
                {
                    code = EXIT_WITH_ERROR;
                }
            } 
        }
         
    }
    return code;
}

//page de création 
int creation_screen()
{
    int choice = -1; 
    int code = SUCCESS;

    system( "clear" ) ;
    cout<<"========================================================================================"<<endl;
    cout<<"||                              CREATION DE COMPTE                                    ||"<<endl;
    cout<<"========================================================================================"<<endl;
    cout<<"|                                                                                      |"<<endl;
    cout<<"|                         TYPE DE COMPTE :                                             |"<<endl;
    cout<<"|                                                                                      |"<<endl;
    cout<<"|                         1-ENTREPRISE                                                 |"<<endl;
    cout<<"|                         2-CHERCHEUR D'EMPLOI                                         |"<<endl;
    cout<<"|                         3-EMPLOYÉ                                                    |"<<endl;
    cout<<"|                                                                                      |"<<endl;
    cout<<"|                         4-RETOURNER AU MENU                                          |"<<endl;
    cout<<"|                                                                                      |"<<endl; 
    cout<<"======================================================================================="<<endl;
    cout<<"\n Veuillez entrer le numero de votre choix: ";
    cin >> choice ;
    
    switch (choice)
    {
        case 1:
            return etp_create_profil();
            break;
        case 2:
            return 1;
            break;
        case 3:
            return 1;
            break;
        case 4:
            return code;
            break;
        default:
            return code;
            break;
    }
    
}

//Menu entreprise
//=========================================================================================
int etp_home(company & etp)
{
    int choice = -1;
    int code_option;

    while(code_option != EXIT_PROGRAM && code_option != DECONNEXION){

        while(choice < 1 or choice >6){
            system( "clear" ) ;
            cout<<"Connecté en tant que " << etp.getNom() << ", " << etp.getEmail() << ", CP " << etp.getCodePostal() << endl;
            cout<< "\n" << endl;
            cout<<"===================================================================================="<<endl;
            cout<<"||                                MENU ENTREPRISE                                 ||"<<endl;
            cout<<"===================================================================================="<<endl;
            cout<<"|                                                                                  |"<<endl;
            cout<<"|                         Que souhaitez vous faire:                                |"<<endl;
            cout<<"|                                                                                  |"<<endl;
            cout<<"|                             1-FAIRE UNE OFFRE D'EMPLOI                           |"<<endl;
            cout<<"|                             2-RETIRER UNE OFFRE D'EMPLOI                         |"<<endl;
            cout<<"|                             3-RECHERCHER DES JOBSEEKERS                          |"<<endl;
            cout<<"|                             4-DECONNEXION                                        |"<<endl;
            cout<<"|                                                                                  |"<<endl;
            cout<<"|                             5-SUPPRIMER LE COMPTE                                |"<<endl;
            cout<<"|                             6-Quitter le programme                               |"<<endl;
            cout<<"|                                                                                  |"<<endl;
            cout<<"===================================================================================="<<endl;
            
            cout<<"\n\n Veuillez entrer le numero de l'action : " ;
            cin >> choice ;
        }

        code_option = navigation_company( choice, etp ) ;
        choice = -1;
    }
    return code_option;
}

int navigation_company( const int & choice, company & etp )
{
    switch( choice )
	{
        case 1:
			return etp_create_poste(etp);
		case 2:
			return etp_delete_poste(etp);
		case 3:
			return etp_search(etp) ;
		case 4:
			return etp_logout(etp);
		case 5:
			return etp_deleteProfil(etp);
		case 6:
			exit(0) ;
		default:
			return choice ;
	}
}

int etp_create_poste(company & etp)
{
    int code = EXIT_WITH_ERROR;
    int i;
	int entreprise_id;
	vector<string> skills;           //Tableau de compétences
	string skill,titre;
    char exit_char;    

    system( "clear" ) ;
    cout<<"Connecté en tant que " << etp.getNom() << ", " << etp.getEmail() << ", CP " << etp.getCodePostal() << endl;
    cout<<"\n"<<endl;

	cout<< "*************CREATION DE L'OFFRE D'EMPLOI***********"<< endl<< endl;
	cout<<"NOM DU POSTE : "; cin.ignore(); getline(cin,titre);
    cout<<endl;

	cout<<"ENTREZ LES COMPETENCES REQUISES (UNE A UNE)"<< endl;
	cout<<"ENTREZ 'q' POUR TERMINER LA SAISIE"<< endl;  

	i=0;
	do{                                         //Boucle pour permettre la saisie de plusieur competence
		i++;								    //L utilisateur saisi q pour quitter la boucle
		cout<<"\nCOMPETENCE N° "<<i<<" : "; getline(cin,skill);
		
		if(skill!="q") skills.push_back(skill);   //Pour ne pas enregistrer la lettre q
		
	}while(skill!="q");

	entreprise_id = etp.getId();
    
    Position poste;
    poste.setTitre(titre);
    poste.setSkills(skills);
    poste.setEntrepriseId(entreprise_id);

    code = etp.createPosition(poste);
    
    if(code == SUCCESS)
        cout<< "\n\nFELICITAIONS, L'OFFRE A ETE PUBLIEE ! ENTREZ 'q' POUR CONTINUER" << endl;
    else 
        cout<< "\n\nUNE ERREUR S'EST PRODUITE, ENTREZ 'q' POUR CONTINUER" << endl;
        
    cin>> exit_char;

	return code;
}

int etp_delete_poste(company & etp)
{
    int code = EXIT_WITH_ERROR;
    int id_poste;
    char confirmation, exit_char;
    vector<string> list_postes;

    list_postes = etp.getAllPosition();
    system( "clear" ) ;

    cout<<"************LISTE DES OFFRES EN COURS************" << endl;
    cout<<endl;

    for (size_t i = 0; i < list_postes.size(); i++)
        cout<< list_postes[i] << endl;
    
    cout<<endl;

    cout << "ENTREZ L'ID DU POSTE A RETIRER : " ; cin >>id_poste;

    cout << "\n\n CONFIRMEZ-VOUS LA SUPPRESSION DE L'OFFRE N° " << id_poste << " ? (y/n) : "; cin>> confirmation;

    if(confirmation == 'y')
    {
        code = etp.deletePosition(id_poste);
        if(code == SUCCESS) cout<<"\n\nL'OFFRE A ETE RETIREE, ENTREZ 'q' POUR CONTINUER."<<endl;
        else cout << "\n\nUNE ERREUR S'EST PRODUITE, ENTREZ 'q' POUR CONTINUER" << endl;
    }else{
        cout << "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    }

    cin>> exit_char;
    
    return code;
}

int etp_search(company & etp) 
{
    int choice = -1; 
    int code = SUCCESS;
    char exit_char;

    while(choice != 3){

        system( "clear" ) ;
        cout<<"========================================================================================"<<endl;
        cout<<"||                 RECHERCHER PARMIS LES DEMANDEURS D'EMPLOI                           ||"<<endl;
        cout<<"========================================================================================"<<endl;
        cout<<"|                                                                                      |"<<endl;
        cout<<"|                         CRITERES :                                                   |"<<endl;
        cout<<"|                                                                                      |"<<endl;
        cout<<"|                         1-COMPETENCES                                                |"<<endl;
        cout<<"|                         2-COMPETENCES & CODE POSTAL                                  |"<<endl;
        cout<<"|                                                                                      |"<<endl;
        cout<<"|                         3-RETOURNER AU MENU                                          |"<<endl;
        cout<<"|                                                                                      |"<<endl; 
        cout<<"======================================================================================="<<endl;
        cout<<"\n Veuillez entrer le numero de votre choix: ";
        cin >> choice ;
        
        if(choice == 1 or choice == 2)
        {
            vector<vector<string>> resultat;
            vector<string> skills;
            string code_postal, skill;
            size_t founded = 0;
            
            system( "clear" ) ;
            cout<< "******************RECHERCHER PARMIS LES DEMANDEURS D'EMPLOI***************" <<endl;

            if(choice == 2) {
                cout << "\nENTREZ LE CODE POSTAL : " ; cin>> code_postal;
            }
            else code_postal = "#";

            cout<<"\nENTREZ LES COMPETENCES (UNE A UNE)"<< endl;
            cout<<"ENTREZ 'q' POUR TERMINER LA SAISIE"<< endl;  

            int i=0;
            cin.ignore();
            do{                                         
                i++;								    
                cout<<"\nCOMPETENCE N° "<<i<<" : "; getline(cin,skill);
                
                if(skill!="q") skills.push_back(skill);   
                
            }while(skill!="q");
            cout<<endl;

            resultat = etp.searchToHire(skills,code_postal);
            founded = resultat.size();

            if(founded < 1) cout << "AUCUN RESULTAT " << endl;
            else
            {
                cout << founded << " PERSONNE(S) TROUVEE(S) " << endl;
                cout << "=================================" << endl;

                for (size_t i = 0; i < founded; i++)
                {
                    cout << i + "  " + resultat[i][1] + " " + resultat[i][2] + "   " + resultat[i][3] << endl;
                }
                cout << endl;
                
            }
        }
        cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
        cin>> exit_char;
    }

    return code;
}

int etp_logout(company & etp)
{
    return DECONNEXION;
}

int etp_deleteProfil(company & etp)
{
    int code = EXIT_WITH_ERROR;
    char confirmation, exit_char;
    
    system( "clear" ) ;

    cout<<"************SUPPRESSION DE COMPTE************" << endl;
    cout<<endl;
    cout << "\n\n CONFIRMEZ-VOUS LA SUPPRESSION DE VOTRE COMPTE ? (y/n) : "; cin>> confirmation;

    if(confirmation == 'y')
    {
        code = etp.deleteCompany();

        if(code == SUCCESS) {
            cout<<"\n\nSUPPRESSION TERMINEE, ENTREZ 'q' POUR CONTINUER."<<endl;
            code = EXIT_PROGRAM;
        }
        else cout << "\n\nUNE ERREUR S'EST PRODUITE, ENTREZ 'q' POUR CONTINUER" << endl;
    }else{
        cout << "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    }

    cin>> exit_char;

    return code;
}

int etp_create_profil()
{
    int code;
    string nom,email,code_postal;
    char exit_char;

    system( "clear" ) ;
    cout<< "*************CREATION D'UN COMPTE ENTREPRISE'***********"<< endl<< endl;
	cout<<"NOM DE L'ENTREPRISE : "; cin.ignore(); getline(cin,nom);
    cout<<"\nCODE POSTAL         : "; getline(cin,code_postal);
    cout<<"\nEMAIL               : "; getline(cin,email);
    cout<<endl;

    company etp;
    etp.setNom(nom);
    etp.setCodePostal(code_postal);
    etp.setEmail(email);

    code = etp.createCompany();
    
    if(code == SUCCESS)
        cout<< "\n\nFELICITAIONS, VOTRE COMPTE A ETE CREE VOUS POUVEZ DESORMAIS VOUS CONNECTER! ENTREZ 'q' POUR CONTINUER" << endl;
    else 
        cout<< "\n\nUNE ERREUR S'EST PRODUITE, ENTREZ 'q' POUR CONTINUER" << endl;
        
    cin>> exit_char;

    return code;
}

//=========================================================================================

//Menu jobseeker
int jsk_home(jobseeker & jsk)
{
    int choice = -1;
    int code_option;

    while(code_option != EXIT_PROGRAM && code_option != DECONNEXION){

        while(choice < 1 or choice >7)
        {

            system( "clear" ) ;
            cout<<"Connecté en tant que " << jsk.getNom() << " " << jsk.getPrenom() << ", " << jsk.getEmail() << endl;
            cout<< "\n" << endl;
            cout<<"========================================================================================"<<endl;
            cout<<"||                         MENU CHERCHEUR D'EMPLOI                                    ||"<<endl;
            cout<<"========================================================================================"<<endl;
            cout<<"|                                                                                      |"<<endl;
            cout<<"|                         Que souhaitez vous faire:                                    |"<<endl;
            cout<<"|                                                                                      |"<<endl;
            cout<<"|                         1-METTRE À JOUR LE PROFIL                                    |"<<endl;
            cout<<"|                         2-DEVENIR EMPLOYE                                            |"<<endl;
            cout<<"|                         3-SUPPRIMER LE PROFIL                                        |"<<endl; 
            cout<<"|                         4-RECHERCHER DES POSTES                                      |"<<endl;
            cout<<"|                         5-RECHERCHER PARMIS LES ANCIENS COLLEGUES                    |"<<endl;
            cout<<"|                                                                                      |"<<endl;
            cout<<"|                         6-DECONNEXION                                                |"<<endl;
            cout<<"|                         7-Quitter le programme                                       |"<<endl;
            cout<<"|                                                                                      |"<<endl;
            cout<<"======================================================================================="<<endl;
            cout<<"\n Veuillez entrer le numero de votre choix  : ";
            cin >> choice ;

        }

        code_option = navigation_jobSeeker( choice, jsk ) ;
        choice = -1;
    }
    return code_option;
}

int navigation_jobSeeker( int const& choice, jobseeker & jsk )
{
	switch( choice )
	{
		case 1: 
			return display_modify_profil_jobSeeker( jsk ) ;		
		case 2:
			return jobseeker_to_employe(jsk); 	
		case 3:
            return jsk_deleteProfile(jsk);
		case 4: 
			return jsk_search_poste(jsk);
		case 5:
			//return display_search_oldColleagues( person ) ;
            return 1;
		case 6:
			return DECONNEXION;
        case 7:
            exit(0);
		default:
			return SUCCESS;
	}
}

int display_modify_profil_jobSeeker( jobseeker & jsk )
{
    int choice = -1;
    int code_option;

    while(code_option != EXIT_PROGRAM && code_option != DECONNEXION && code_option != BACK_PREV_MENU){

        while(choice < 1 or choice >6)
        {

            system( "clear" ) ;
            cout<<"Connecté en tant que " << jsk.getNom() << " " << jsk.getPrenom() << ", " << jsk.getEmail() << endl;
            cout<< "\n" << endl;
            cout<<"===================================================================================="<<endl;
            cout<<"||                     MODIFIER MON PROFIL CHERCHEUR D'EMPLOI                     ||"<<endl;
            cout<<"===================================================================================="<<endl;
            cout<<"|                                                                                  |"<<endl;
            cout<<"|                             Que souhaitez vous faire ?:                          |"<<endl;
            cout<<"|                                                                                  |"<<endl;
            cout<<"|                             1-VOIR MON PROFIL                                    |"<<endl;
            cout<<"|                             2-AJOUTER DES COMPETENCES                            |"<<endl;
            cout<<"|                             3-AJOUTER UN(E) ANCIEN(NE) COLLEGUE                  |"<<endl;
            cout<<"|                             4-CHANGER LE CODE POSTAL                             |"<<endl;
            cout<<"|                                                                                  |"<<endl;
            cout<<"|                             5-RETOURNER AU LE MENU                               |"<<endl;
            cout<<"|                             6-Quitter le Programme                               |"<<endl;
            cout<<"|                                                                                  |"<<endl;
            cout<<"===================================================================================="<<endl;
            cout<<"\n Veuillez entrer le numero de votre choix  : ";
            cin >> choice ;
        }

	    code_option = navigation_modify_profil_jobSeeker( choice, jsk ) ;
        choice = -1;
    }
    return code_option;
}

int navigation_modify_profil_jobSeeker( int const& choice, jobseeker & jsk )
{
    int code = EXIT_WITH_ERROR;

	switch( choice )
	{
		case 1:
			code = jsk_afficher(jsk);
            break;	
		case 2: 
			code = jsk_add_skills(jsk); 
            break ;
		case 3: 
			//jsk.add_oldColleague() ; 
            break ;
		case 4: 
			code = jsk_update_codePostal(jsk); 
            break ;
		case 5: 
			code = BACK_PREV_MENU;
            break;
		case 6: 
			exit(0);	
		default: 
            code = SUCCESS;
            break;
	}
    return code;
}

int jsk_afficher(jobseeker & jsk)
{
    char exit_char;
    vector<string> skills;
    size_t nbr_skills;

    skills = jsk.getSkills();
    nbr_skills = skills.size();

    system( "clear" ) ;
	cout << "\n\n" << endl ;
	cout << "  ========================================== " << endl ;
	cout << " |                                          | " << endl ;
	cout << " |                MON PROFIL                | " << endl ;
	cout << " |                                          | " << endl ;
	cout << "  ========================================== " << endl << endl ;

	cout << "   Nom         : " << jsk.getNom() << endl ;
	cout << "   Prénom      : " << jsk.getPrenom() << endl ;
	cout << "   Code Postal : " << jsk.getCodePostal() << endl ;
	cout << "   Email       : " << jsk.getEmail() << endl ;
    cout << "   Compétences : "; for(size_t i=0; i<nbr_skills;i++ ) cout << skills[i] << " ";

    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;
    
    return SUCCESS;
}

int jsk_add_skills(jobseeker & jsk)
{
    int code = EXIT_WITH_ERROR;
    char exit_char;
    vector<string> skills;
    string skill;

    system( "clear" ) ;
	cout<<"Connecté en tant que " << jsk.getNom() << " " << jsk.getPrenom() << ", " << jsk.getEmail() << endl;
    cout<< "\n" << endl;
	cout << "  ========================================== " << endl ;
	cout << " |                                          | " << endl ;
	cout << " |         AJOUTER DES COMPETENCES          | " << endl ;
	cout << " |                                          | " << endl ;
	cout << "  ========================================== " << endl << endl ;

    cout<<"ENTREZ LES COMPETENCES A AJOUTER (UNE A UNE)"<< endl;
	cout<<"ENTREZ 'q' POUR TERMINER LA SAISIE"<< endl;  

	int i=0;
    cin.ignore();
	do{                                         //Boucle pour permettre la saisie de plusieur competence
		i++;								    //L utilisateur saisi q pour quitter la boucle
		cout<<"\nCOMPETENCE N° "<<i<<" : "; getline(cin,skill);
		
		if(skill!="q") skills.push_back(skill);   //Pour ne pas enregistrer la lettre q
		
	}while(skill!="q");

    if(skills.size() > 0)
    {
        code = jsk.addSkill(skills);
        if(code == SUCCESS) cout << "\nLES COMPETENCES ONT BIEN ETE AJOUTEES" << endl;
            else cout << "\nUNE ERREUR S'EST PRODUITE" << endl;
    }

    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;

    return code;
}

int jsk_update_codePostal(jobseeker & jsk)
{
    int code = EXIT_WITH_ERROR;
    char exit_char;
    string code_postal;

    system( "clear" ) ;
	cout<<"Connecté en tant que " << jsk.getNom() << " " << jsk.getPrenom() << ", " << jsk.getEmail() << endl;
    cout<< "\n" << endl;
	cout << "  ========================================== " << endl ;
	cout << " |                                          | " << endl ;
	cout << " |          CHANGER LE CODE POSTAL          | " << endl ;
	cout << " |                                          | " << endl ;
	cout << "  ========================================== " << endl << endl ;

    cout<< jsk.getCodePostal() << " est votre code postal actuel." << endl;
	cout<<"\nNouveau code postal : " ; cin>> code_postal;  

    code = jsk.updateCodePostal(code_postal);
    if(code == SUCCESS) cout << "\nLE CODE POSTAL A BIEN ETE MIS A JOUR" << endl;
        else cout << "\nUNE ERREUR S'EST PRODUITE" << endl;


    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;

    return code;
}

int jobseeker_to_employe(jobseeker & jsk)
{
    int code = EXIT_WITH_ERROR;
    char exit_char;
    string code_postal;
    string nom_entreprise;
    int id_entreprise;
    vector<string> list_etp;
    char restart = 'n', confirm;

    do
    {
        system( "clear" ) ;
        cout<<"Connecté en tant que " << jsk.getNom() << " " << jsk.getPrenom() << ", " << jsk.getEmail() << endl;
        cout<< "\n" << endl;
        cout << "  =============================================== " << endl ;
        cout << " |                                               | " << endl ;
        cout << " |     PASSER DE CHERCHEUR D'EMPLOI A EMPLOYE    | " << endl ;
        cout << " |                                               | " << endl ;
        cout << "  =============================================== " << endl << endl ;

        cout << "*saisir le caractère '#' pour ignorer un champ\n\n" << endl;

        cin.ignore();
        cout<< "ENTREPRISE D'ACCEUIL : " ; getline(cin,nom_entreprise);
        cout<<"\nCODE POSTAL          : " ; getline(cin,code_postal);  
        cout<<"\n"<<endl;

        list_etp.clear();
        list_etp = jsk.searchEntreprise(nom_entreprise, code_postal);
        
        if(list_etp.size() > 0)
        {
            cout << "ENTREPRISE(S) TROUVE(ES)\n" << endl;
            for(size_t i=0; i<list_etp.size(); i++) cout << list_etp[i] << endl;

            cout << "\n\nN° DE L'ENTREPRISE QUI VOUS EMBAUCHE : "; cin>> id_entreprise; cout<<endl;
            cout << "CONFIRMER LE CHANGEMENT DE STATUT (y) OU ANNULER (n) ? (y/n) : "; cin>>confirm; cout<<endl;
            
            if(confirm == 'y')
            {
                code = jsk.jobseekerToEmploye(id_entreprise);
                
                if(code == SUCCESS)
                {
                    cout<< "\n\nVOTRE STATUT A BIEN ETE MIS A JOUR, VOUS ALLEZ ETRE DECONNECTER"<<endl;
                    code = DECONNEXION;
                }
                else cout<< "\n\nUNE ERREUR S'EST PRODUITE"<<endl;
            }
            else code = SUCCESS;

        }else
        {
            cout<< "AUCUNE ENTREPRISE TROUVE\n"<<endl;
            cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
        }

    }while(restart == 'y');

    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;

    return code;
}

int jsk_deleteProfile(jobseeker & jsk)
{
    int code = EXIT_WITH_ERROR;
    char confirmation, exit_char;
    
    system( "clear" ) ;

    cout<<"************SUPPRESSION DE COMPTE************" << endl;
    cout<<endl;
    cout << "\n\n CONFIRMEZ-VOUS LA SUPPRESSION DE VOTRE COMPTE ? (y/n) : "; cin>> confirmation;

    if(confirmation == 'y')
    {
        code = jsk.deleteJobseeker();

        if(code == SUCCESS) {
            cout<<"\n\nSUPPRESSION TERMINEE, ENTREZ 'q' POUR CONTINUER."<<endl;
            code = EXIT_PROGRAM;
        }
        else cout << "\n\nUNE ERREUR S'EST PRODUITE, ENTREZ 'q' POUR CONTINUER" << endl;
    }else{
        cout << "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    }

    cin>> exit_char;

    return code;

}

int jsk_search_poste(jobseeker & jsk)
{
    int code = SUCCESS;
    char exit_char;
    string code_postal, skill;
    vector<string> skills;

    vector<vector<string>> list_etp;
    char restart = 'n';

    do
    {
        system( "clear" ) ;
        cout<<"Connecté en tant que " << jsk.getNom() << " " << jsk.getPrenom() << ", " << jsk.getEmail() << endl;
        cout<< "\n" << endl;
        cout << "  =============================================== " << endl ;
        cout << " |                                               | " << endl ;
        cout << " |       RECHERCHER DES POSTES A POURVOIR        | " << endl ;
        cout << " |                                               | " << endl ;
        cout << "  =============================================== " << endl << endl ;

        cout << "*saisir le caractère '#' pour une recherche sans code postal\n\n" << endl;

        cin.ignore();
        cout<<"\nCODE POSTAL   : " ; getline(cin,code_postal);  
        cout<<"\n"<<endl;

        cout<<"ENTREZ LES COMPETENCES REQUISES (UNE A UNE)"<< endl;
        cout<<"ENTREZ 'q' POUR TERMINER LA SAISIE"<< endl;  

        int i=1, nbr_skills = 0;
        do{                                         //Boucle pour permettre la saisie de plusieur competence
                								    //L utilisateur saisi q pour quitter la boucle
            cout<<"\nCOMPETENCE N° "<<i<<" : "; getline(cin,skill);
            
            if(skill!="q"){
                skills.push_back(skill);  
                nbr_skills = nbr_skills + 1; 
                i++;
            }
            
        }while(skill!="q" || nbr_skills==0);

        list_etp.clear();
        list_etp = jsk.searchJob(skills,code_postal);
        
        if(list_etp.size() > 0)
        {
            cout << "\nENTREPRISE(S) TROUVE(ES)\n" << endl;
            for(size_t i=0; i<list_etp.size(); i++) cout << i+1 << " ( POSTE ) : " << list_etp[i][0] 
                                                         << " ( ENTRPRISE ) : " << list_etp[i][1] 
                                                         << " ( EMAIL ) : " << list_etp[i][2] 
                                                         << " ( CODE POSTAL ) : " << list_etp[i][3] 
                                                         << "  " << endl;

        }else
        {
            cout<< "AUCUNE ENTREPRISE TROUVE\n"<<endl;
            cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
        }

    }while(restart == 'y');

    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;

    return code;
}
//=========================================================================================
//Menu employé
int emp_home(employe & emp)
{
    return 1;
}
