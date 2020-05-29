#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <sstream>

#include "view.h"

#include "extra3/compression.h"
#include "extra3/decompression.h"
using namespace std;


//Page d'acceuil
int home_screen()
{
    int choice ;
    int code = EXIT_WITH_ERROR;

    //On décompresse la base de données
    decompress_csv_files() ;

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

    //On compresse la base de données avant de quitter
    compress_csv_files() ;

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
    string email,mdp;

    cout << "\n\n Email    :  "; cin >> email;
    cout << "\nPassword :  "; cin >> mdp;

    if(isValidEmail(email))
    {
        company etp;
        etp.getCompanyByEmail(email,mdp);
        
        if(etp.getId() != -1)
        {
            code = etp_home(etp);
        }
        else
        {
            jobseeker jsk;
            jsk.getJobseekerByEmail(email,mdp);
            
            if(jsk.getId() != -1)
            {
                code = jsk_home(jsk);
            }
            else
            {
                employe emp;
                emp.getEmployeByEmail(email,mdp);

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
            return jsk_create_profil();
            break;
        case 3:
            return emp_create_profil();
            break;
        case 4:
            return code;
            break;
        default:
            return code;
            break;
    }
    
}

//Vérifie l'exitence d'un entier dans un tableau
bool existOnVector(const vector<int> & tab, const int & val)
{
    bool exist = false;
    int tab_size = tab.size();
    int i = 0;
 
    while (i < tab_size && exist == false)
    {
        if(tab[i] == val) exist = true;
        ++i;
    }
    
    return exist;
}

//Menu entreprise
//=========================================================================================
int etp_home(company & etp)
{
    int choice = -1;
    int code_option;

    while(code_option != EXIT_PROGRAM && code_option != DECONNEXION){

        while(choice < 1 or choice >7){
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
            cout<<"|                             4-MODIFIER LE MOT DE PASSE                           |"<<endl;
            cout<<"|                             5-DECONNEXION                                        |"<<endl;
            cout<<"|                                                                                  |"<<endl;
            cout<<"|                             6-SUPPRIMER LE COMPTE                                |"<<endl;
            cout<<"|                             7-Quitter le programme                               |"<<endl;
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
			return etp_update_password(etp);
		case 5:
			return etp_logout(etp);
		case 6:
			return etp_deleteProfil(etp);
		case 7:
            compress_csv_files() ;
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
    string nom,email,code_postal,mdp;
    char exit_char;

    system( "clear" ) ;
    cout<< "*************CREATION D'UN COMPTE ENTREPRISE'***********"<< endl<< endl;
	cout<<"NOM DE L'ENTREPRISE : "; cin.ignore(); getline(cin,nom);
    cout<<"CODE POSTAL         : "; getline(cin,code_postal);
    cout<<"EMAIL               : "; getline(cin,email);
    cout<<"PASSWORD            : "; getline(cin,mdp);
    cout<<endl;

    company etp;
    etp.setNom(nom);
    etp.setCodePostal(code_postal);
    etp.setEmail(email);
    etp.setMdp(mdp);

    code = etp.createCompany();
    
    if(code == SUCCESS)
        cout<< "\n\nFELICITAIONS, VOTRE COMPTE A ETE CREE VOUS POUVEZ DESORMAIS VOUS CONNECTER! ENTREZ 'q' POUR CONTINUER" << endl;
    else 
        cout<< "\n\nUNE ERREUR S'EST PRODUITE, ENTREZ 'q' POUR CONTINUER" << endl;
        
    cin>> exit_char;

    return code;
}

int etp_update_password(company & etp)
{
    int code = EXIT_WITH_ERROR;
    char exit_char;
    string old_mdp, new_mdp;

    system( "clear" ) ;
	cout<<"Connecté en tant que " << etp.getNom() << " " << etp.getEmail() << " (" << etp.getCodePostal() << ")" << endl;
    cout<< "\n" << endl;
	cout << "  ========================================== " << endl ;
	cout << " |                                          | " << endl ;
	cout << " |         CHANGER LE MOT DE PASSE          | " << endl ;
	cout << " |                                          | " << endl ;
	cout << "  ========================================== " << endl << endl ;

    cin.ignore();
    cout << "ENTREZ VOTRE MOT DE PASSE ACTUEL : " ; getline(cin,old_mdp);
	cout << "\nENTREZ LE NOUVEAU MOT DE PASSE   : " ; getline(cin,new_mdp);  

    code = etp.updatemdp(new_mdp,old_mdp);

    if(code == SUCCESS) cout << "\nLE MOT DE PASSE A BIEN ETE MIS A JOUR" << endl;
        else cout << "\nUNE ERREUR S'EST PRODUITE" << endl;


    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
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
			return jsk_search_oldColleagues( jsk ) ;
		case 6:
			return DECONNEXION;
        case 7:
            compress_csv_files() ;
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

        while(choice < 1 or choice >7)
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
            cout<<"|                             5-CHANGER LE MOT DE PASSE                            |"<<endl;
            cout<<"|                                                                                  |"<<endl;
            cout<<"|                             6-RETOURNER AU MENU                                  |"<<endl;
            cout<<"|                             7-Quitter le Programme                               |"<<endl;
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
			code = jsk_add_oldColleague(jsk); 
            break ;
        case 4: 
			code = jsk_update_codePostal(jsk); 
            break ;
		case 5: 
			code = jsk_update_password(jsk); 
            break ;
		case 6: 
			code = BACK_PREV_MENU;
            break;
		case 7: 
            compress_csv_files() ;
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
    vector<string> oldColleagues;
    size_t nbr_oldColleagues;
    vector<int> list_id;

    list_id = jsk.getColleagues();
    oldColleagues = jsk.getOldColleaguesById(list_id);
    nbr_oldColleagues = oldColleagues.size();
    
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
    cout << "   Compétences : "; for(size_t i=0; i<nbr_skills;i++ ) cout << skills[i] << " "; cout<<endl;
    cout << endl;
    cout << "   Anciens collègues :" << endl << endl;

    if(nbr_oldColleagues < 1) cout<< "     VOUS N'AVEZ PAS D'ANCIENS COLLEGUES.";
    else for(size_t i=0; i<nbr_oldColleagues;i++ ) cout<< "    "<< i+1 << " - " << oldColleagues[i] <<endl;

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
        restart = 'n';
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
        restart = 'n';
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
            cout << "\nPOSTE(S) TROUVE(S)\n" << endl;
            for(size_t i=0; i<list_etp.size(); i++) cout << "N° " << i+1 
                                                         << "\nPOSTE       : " << list_etp[i][0] 
                                                         << "\nENTRPRISE   : " << list_etp[i][1] 
                                                         << "\nEMAIL       : " << list_etp[i][2] 
                                                         << "\nCODE POSTAL : " << list_etp[i][3] 
                                                         << "\n" << endl;

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

int jsk_create_profil()
{
    int code;
    string nom, prenom, email,code_postal, skill, mdp;
    vector<string> skills;
    char exit_char;

    system( "clear" ) ;
    cout<< "*************CREATION D'UN COMPTE CHERCHEUR D'EMPLOI'***********"<< endl<< endl;
    cin.ignore();

	cout<<"NOM         : "; getline(cin,nom);
    cout<<"PRENOM      : "; getline(cin,prenom);
    cout<<"EMAIL       : "; getline(cin,email);
    cout<<"CODE POSTAL : "; getline(cin,code_postal);
    cout<<"PASSWORD    : "; getline(cin,mdp);
    cout<<endl;

    cout<<"ENTREZ VOS COMPETENCES (UNE A UNE)"<< endl;
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

    jobseeker jsk;
    jsk.setNom(nom);
    jsk.setPrenom(prenom);
    jsk.setEmail(email);
    jsk.setCodePostal(code_postal);
    jsk.setSkills(skills);
    jsk.setMdp(mdp);

    code = jsk.createJobseeker();
    
    if(code == SUCCESS)
        cout<< "\n\nFELICITAIONS, VOTRE COMPTE A ETE CREE VOUS POUVEZ DESORMAIS VOUS CONNECTER! ENTREZ 'q' POUR CONTINUER" << endl;
    else 
        cout<< "\n\nUNE ERREUR S'EST PRODUITE, ENTREZ 'q' POUR CONTINUER" << endl;
        
    cin>> exit_char;

    return code;
}

int jsk_search_oldColleagues(jobseeker & jsk )
{
    int code = SUCCESS;
    char exit_char;
    string code_postal = "#";
    string nom_entreprise, skill;
    vector<string> skills;
    int id_entreprise;
    vector<string> list_etp;
    char restart = 'n', type_search = 'x';
    

    do
    {
        restart = 'n';
        while(type_search != 'e' && type_search != 'c')
        {

            system( "clear" ) ;
            cout<<"Connecté en tant que " << jsk.getNom() << " " << jsk.getPrenom() << ", " << jsk.getEmail() << endl;
            cout<< "\n" << endl;
            cout << "  =============================================== " << endl ;
            cout << " |                                               | " << endl ;
            cout << " |      RECHERCHER D'ANCIEN(NE)S COLLEGUES       | " << endl ;
            cout << " |                                               | " << endl ;
            cout << "  =============================================== " << endl << endl ;

            cout << "\n-> RECHERCHE PAR ENTREPRISE (e) OU PAR COMPETENCES (c)  (e/c)? : "; cin>>type_search;
        }
        
        if(type_search == 'e')
        {
            cin.ignore();
            cout<<"\n\nENTREPRISE  : " ; getline(cin,nom_entreprise);
            cout<<"\n"<<endl;

            list_etp.clear();
            list_etp = jsk.searchEntreprise(nom_entreprise, code_postal);

            if(list_etp.size() > 0)
            {
                cout << "ENTREPRISE(S) TROUVE(ES)\n" << endl;
                for(size_t i=0; i<list_etp.size(); i++) cout << list_etp[i] << endl;

                cout << "\n\nN° DE L'ENTREPRISE DANS LAQUELLE VOUS RECHERCHEZ D'ANCIEN(NE)S COLLEGUES : "; cin>> id_entreprise; cout<<endl;
                vector<vector<string>> colleagues;
                colleagues = jsk.find_former_colleagues_by_enterprise(id_entreprise);

                if(colleagues.size() > 0)
                {
                    cout<< colleagues.size() << " ANCIEN(NE)(S) COLLEGUE(S) TROUVE(ES)(S)\n" << endl;
                    for(size_t i=0; i<colleagues.size(); i++) 
                    {
                        cout<< "\nNOM    : " << colleagues[i][0] << endl;
                        cout<< "PRENOM : " << colleagues[i][1] << endl;
                        cout<< "EMAIL  : " << colleagues[i][2] << endl;
                    }
                }
                else
                {
                    cout<< "AUCUN(E) COLLEGUE TROUVE(E)\n"<<endl;
                    cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
                    if(restart == 'y') type_search = 'x';
                } 
            }
            else
            {
                cout<< "AUCUNE ENTREPRISE TROUVE\n"<<endl;
                cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
                if(restart == 'y') type_search = 'x';
            }
        }
        else if(type_search == 'c')
        {
            vector<vector<string>> colleagues;
            colleagues = jsk.find_former_colleagues_by_skills();

            if(colleagues.size() > 0)
            {
                cout<<endl;
                cout<< colleagues.size() << " ANCIEN(NE)(S) COLLEGUE(S) TROUVE(ES)(S)\n" << endl;
                for(size_t i=0; i<colleagues.size(); i++) 
                {
                    cout<< "\nNOM    : " << colleagues[i][0] << endl;
                    cout<< "PRENOM : " << colleagues[i][1] << endl;
                    cout<< "EMAIL  : " << colleagues[i][2] << endl;
                }
            }
            else
            {
                cout<< "\nAUCUN(E) COLLEGUE TROUVE(E)\n"<<endl;
                cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
                if(restart == 'y') type_search = 'x';
            } 
        }


    }while(restart == 'y');

    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;

    return code;
}

int jsk_add_oldColleague(jobseeker & jsk)
{
    int code = SUCCESS;
    char exit_char;
    string code_postal = "#";
    string nom_entreprise;
    int id_entreprise;
    vector<string> list_etp;
    char restart = 'n';
    

    do
    {
        restart = 'n';
  
        system( "clear" ) ;
        cout<<"Connecté en tant que " << jsk.getNom() << " " << jsk.getPrenom() << ", " << jsk.getEmail() << endl;
        cout<< "\n" << endl;
        cout << "  =============================================== " << endl ;
        cout << " |                                               | " << endl ;
        cout << " |        AJOUTER D'ANCIEN(NE)S COLLEGUES        | " << endl ;
        cout << " |                                               | " << endl ;
        cout << "  =============================================== " << endl << endl ;

        cout << "\n-> AJOUT PAR ENTREPRISE ";

        cin.ignore();
        cout<<"\n\nENTREPRISE  : " ; getline(cin,nom_entreprise);
        cout<<"\n"<<endl;

        list_etp.clear();
        list_etp = jsk.searchEntreprise(nom_entreprise, code_postal);

        if(list_etp.size() > 0)
        {
            cout << "ENTREPRISE(S) TROUVE(ES)\n" << endl;
            for(size_t i=0; i<list_etp.size(); i++) cout << list_etp[i] << endl;

            cout << "\n\nN° DE L'ENTREPRISE DANS LAQUELLE VOUS RECHERCHEZ D'ANCIEN(NE)S COLLEGUES : "; cin>> id_entreprise; cout<<endl;
            vector<vector<string>> colleagues;
            colleagues = jsk.find_former_colleagues_by_enterprise(id_entreprise);

            if(colleagues.size() > 0)
            {
                cout<< colleagues.size() << " ANCIEN(NE)(S) COLLEGUE(S) TROUVE(ES)(S)\n" << endl;
                for(size_t i=0; i<colleagues.size(); i++) 
                {
                    cout<< "\nID     : " << colleagues[i][3] << endl; 
                    cout<< "NOM    : " << colleagues[i][0] << endl;
                    cout<< "PRENOM : " << colleagues[i][1] << endl;
                    cout<< "EMAIL  : " << colleagues[i][2] << endl;
                }

                cout<<"\nENTREZ LES ID DES PERSONNES A AJOUTER A VOTRE LISTE D'ANCIEN(NE)(S) COLLEGUE (UN A UN)"<< endl;
                cout<<"ENTREZ '0' POUR TERMINER LA SAISIE"<< endl;  

                int i=0;
                int id;
                vector<int> list_id;
                do{                                         //Boucle pour permettre la saisie de plusieur competence
                    i++;								    //L utilisateur saisi q pour quitter la boucle
                    cout<<"\nID N° "<<i<<" : "; cin>>id;
                    
                    if(id!=0) list_id.push_back(id);   //Pour ne pas enregistrer la lettre q
                    
                }while(id!=0);

                
                if(list_id.size() > 0)
                {
                    bool exist = false;
                    vector<int> old_c = jsk.getColleagues();

                    for(size_t i=0; i<list_id.size(); i++)
                    {
                        for (size_t j = 0; j < old_c.size(); j++)
                        {
                            if(list_id[i] == old_c[j]) exist = true;
                        }
                        
                    }

                    if(exist == false)
                    {
                        code = jsk.addColleague(list_id);
                        if(code == SUCCESS) cout << "\nVOTRE LISTE D'ANCIENS COLLEGUES A BIEN ETE MISE A JOUR." << endl;
                            else cout << "\nUNE ERREUR S'EST PRODUITE" << endl;
                    }
                    else{
                        cout<< "CERTAINES DE CES PERSONNES SONT DEJA DANS VOTRE LISTE D'ANCIENS COLLEGUES\n"<<endl;
                        cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
                    }
                }
                

            }
            else
            {
                cout<< "AUCUN(E) COLLEGUE TROUVE(E)\n"<<endl;
                cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
                
            } 
        }
        else
        {
            cout<< "AUCUNE ENTREPRISE TROUVE\n"<<endl;
            cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
            
        }

    }while(restart == 'y');

    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;

    return code;
}

int jsk_update_password(jobseeker & jsk)
{
    int code = EXIT_WITH_ERROR;
    char exit_char;
    string old_mdp, new_mdp;

    system( "clear" ) ;
    cout<<"Connecté en tant que " << jsk.getNom() << " " << jsk.getPrenom() << ", " << jsk.getEmail() << endl;
    cout<< "\n" << endl;
	cout << "  ========================================== " << endl ;
	cout << " |                                          | " << endl ;
	cout << " |         CHANGER LE MOT DE PASSE          | " << endl ;
	cout << " |                                          | " << endl ;
	cout << "  ========================================== " << endl << endl ;

    cin.ignore();
    cout << "ENTREZ VOTRE MOT DE PASSE ACTUEL : " ; getline(cin,old_mdp);
	cout << "\nENTREZ LE NOUVEAU MOT DE PASSE   : " ; getline(cin,new_mdp);  

    code = jsk.updatemdp(new_mdp,old_mdp);

    if(code == SUCCESS) cout << "\nLE MOT DE PASSE A BIEN ETE MIS A JOUR" << endl;
        else cout << "\nUNE ERREUR S'EST PRODUITE" << endl;


    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;

    return code;
}

//=========================================================================================
//Menu employé
int emp_home(employe & emp)
{
    int choice = -1;
    int code_option;

    while(code_option != EXIT_PROGRAM && code_option != DECONNEXION){

        while(choice < 1 or choice >7)
        {

            system( "clear" ) ;
            cout<<"Connecté en tant que " << emp.getNom() << " " << emp.getPrenom() << ", " << emp.getEmail() << endl;
            cout<< "\n" << endl;
            cout<<"========================================================================================"<<endl;
            cout<<"||                                MENU EMPLOYE                                        ||"<<endl;
            cout<<"========================================================================================"<<endl;
            cout<<"|                                                                                      |"<<endl;
            cout<<"|                         Que souhaitez vous faire:                                    |"<<endl;
            cout<<"|                                                                                      |"<<endl;
            cout<<"|                         1-METTRE À JOUR LE PROFIL                                    |"<<endl;
            cout<<"|                         2-DEVENIR CHERCHEUR D'EMPLOI                                 |"<<endl;
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

        code_option = navigation_employe( choice, emp ) ;
        choice = -1;
    }
    return code_option;
}

int navigation_employe( int const & choice, employe & emp )
{
    switch( choice )
	{
		case 1: 
			return display_modify_profil_employe( emp ) ;		
		case 2:
			return employe_to_jobseeker(emp); 	
		case 3:
            return emp_deleteProfile(emp);
		case 4: 
			return emp_search_poste(emp);
		case 5:
			return emp_search_oldColleagues( emp ) ;
		case 6:
			return DECONNEXION;
        case 7:
            compress_csv_files() ;
            exit(0);
		default:
			return SUCCESS;
	}
}

int display_modify_profil_employe(employe & emp )
{
    int choice = -1;
    int code_option;

    while(code_option != EXIT_PROGRAM && code_option != DECONNEXION && code_option != BACK_PREV_MENU){

        while(choice < 1 or choice >8)
        {

            system( "clear" ) ;
            cout<<"Connecté en tant que " << emp.getNom() << " " << emp.getPrenom() << ", " << emp.getEmail() << endl;
            cout<< "\n" << endl;
            cout<<"===================================================================================="<<endl;
            cout<<"||                            MODIFIER MON PROFIL EMPLOYE                         ||"<<endl;
            cout<<"===================================================================================="<<endl;
            cout<<"|                                                                                  |"<<endl;
            cout<<"|                             Que souhaitez vous faire ?:                          |"<<endl;
            cout<<"|                                                                                  |"<<endl;
            cout<<"|                             1-VOIR MON PROFIL                                    |"<<endl;
            cout<<"|                             2-AJOUTER DES COMPETENCES                            |"<<endl;
            cout<<"|                             3-AJOUTER UN(E) ANCIEN(NE) COLLEGUE                  |"<<endl;
            cout<<"|                             4-CHANGER LE CODE POSTAL                             |"<<endl;
            cout<<"|                             5-CHANGER D'ENTREPRISE                               |"<<endl;
            cout<<"|                             6-CHANGER DE MOT DE PASSE                            |"<<endl;
            cout<<"|                                                                                  |"<<endl;
            cout<<"|                             7-RETOURNER AU MENU                                  |"<<endl;
            cout<<"|                             8-Quitter le Programme                               |"<<endl;
            cout<<"|                                                                                  |"<<endl;
            cout<<"===================================================================================="<<endl;
            cout<<"\n Veuillez entrer le numero de votre choix  : ";
            cin >> choice ;
        }

	    code_option = navigation_modify_profil_employe( choice, emp ) ;
        choice = -1;
    }
    return code_option;
}

int navigation_modify_profil_employe ( const int & choice, employe & emp)
{
    int code = EXIT_WITH_ERROR;

	switch( choice )
	{
		case 1:
			code = emp_afficher(emp);
            break;	
		case 2: 
			code = emp_add_skills(emp); 
            break ;
		case 3: 
			code = emp_add_oldColleague(emp); 
            break ;
		case 4: 
			code = emp_update_codePostal(emp); 
            break ;
        case 5:
            code = emp_update_entreprise(emp);
            break;
        case 6:
            code = emp_update_password(emp);
            break;
		case 7: 
			code = BACK_PREV_MENU;
            break;
		case 8: 
            compress_csv_files() ;
			exit(0);	
		default: 
            code = SUCCESS;
            break;
	}
    return code;
}

int emp_afficher(employe & emp)
{
    char exit_char;
    vector<string> skills;
    size_t nbr_skills;
    vector<string> oldColleagues;
    size_t nbr_oldColleagues;
    vector<int> list_id;
    vector<string> etp;
    int id_etp;

    list_id = emp.getColleagues();
    oldColleagues = emp.getOldColleaguesById(list_id);
    nbr_oldColleagues = oldColleagues.size();
    
    skills = emp.getSkills();
    nbr_skills = skills.size();

    id_etp = emp.getEnterpriseId();
    etp = emp.getEntrepriseById(id_etp);

    system( "clear" ) ;
	cout << "\n\n" << endl ;
	cout << "  ========================================== " << endl ;
	cout << " |                                          | " << endl ;
	cout << " |                MON PROFIL                | " << endl ;
	cout << " |                                          | " << endl ;
	cout << "  ========================================== " << endl << endl ;

	cout << "   Nom         : " << emp.getNom() << endl ;
	cout << "   Prénom      : " << emp.getPrenom() << endl ;
	cout << "   Code Postal : " << emp.getCodePostal() << endl ;
	cout << "   Email       : " << emp.getEmail() << endl ;
    cout << "   Compétences : "; for(size_t i=0; i<nbr_skills;i++ ) cout << skills[i] << " "; cout<<endl;
    cout << endl;
    cout << "   Entreprise actuelle : "; if(etp.size() > 0) cout<< etp[1] << " (" << etp[2] << ")" << endl << endl;
                                            else cout << "Votre entreprise n'est plus dans notre liste d'entreprises" << endl << endl;

    cout << "   Anciens collègues :" << endl << endl;

    if(nbr_oldColleagues < 1) cout<< "     VOUS N'AVEZ PAS D'ANCIENS COLLEGUES.";
    else for(size_t i=0; i<nbr_oldColleagues;i++ ) cout<< "    "<< i+1 << " - " << oldColleagues[i] <<endl;

    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;
    
    return SUCCESS;
}

int emp_create_profil()
{
    int code = EXIT_WITH_ERROR;
    char exit_char;
    string nom,prenom,email,code_postal,mdp;
    string nom_entreprise, skill;
    int id_entreprise;
    vector<string> list_etp;
    vector<string> skills;
    char restart = 'n';

    do
    {
        restart = 'n';
        system( "clear" ) ;
        cout<< "*************CREATION D'UN COMPTE EMPLOYE***********"<< endl<< endl;
        
        cout << "*saisir le caractère '#' pour ignorer un champ\n\n" << endl;

        cin.ignore();
        cout<< "NOM DE L'ENTREPRISE         : " ; getline(cin,nom_entreprise);
        cout<< "\nCODE POSTAL DE L'ENTREPRISE : " ; getline(cin,code_postal);  
        cout<<"\n"<<endl;

        employe emp;
        list_etp.clear();
        list_etp = emp.searchEntreprise(nom_entreprise,code_postal);
        
        if(list_etp.size() > 0)
        {
            cout << "ENTREPRISE(S) TROUVE(ES)\n" << endl;
            for(size_t i=0; i<list_etp.size(); i++) cout << list_etp[i] << endl;

            cout << "\n\nN° DE L'ENTREPRISE DANS LAQUELLE VOUS ETES EMPLOYE : "; cin>> id_entreprise; cout<<endl;
            cin.ignore();

            cout<<"NOM         : "; getline(cin,nom);
            cout<<"PRENOM      : "; getline(cin,prenom);
            cout<<"EMAIL       : "; getline(cin,email);
            cout<<"CODE POSTAL : "; getline(cin,code_postal);
            cout<<"PASSWORD    : "; getline(cin,mdp);
            cout<<endl;

            cout<<"ENTREZ VOS COMPETENCES (UNE A UNE)"<< endl;
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

            emp.setNom(nom);
            emp.setPrenom(prenom);
            emp.setEmail(email);
            emp.setCodePostal(code_postal);
            emp.setSkills(skills);
            emp.setEnterpriseId(id_entreprise);
            emp.setMdp(mdp);

            code = emp.createEmploye();
            
            if(code == SUCCESS)
                cout<< "\n\nFELICITAIONS, VOTRE COMPTE A ETE CREE VOUS POUVEZ DESORMAIS VOUS CONNECTER!" << endl;
            else 
                cout<< "\n\nUNE ERREUR S'EST PRODUITE, ENTREZ 'q' POUR CONTINUER" << endl;

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

int emp_add_skills(employe & emp)
{
    int code = EXIT_WITH_ERROR;
    char exit_char;
    vector<string> skills;
    string skill;

    system( "clear" ) ;
	cout<<"Connecté en tant que " << emp.getNom() << " " << emp.getPrenom() << ", " << emp.getEmail() << endl;
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
        code = emp.addSkill(skills);
        if(code == SUCCESS) cout << "\nLES COMPETENCES ONT BIEN ETE AJOUTEES" << endl;
            else cout << "\nUNE ERREUR S'EST PRODUITE" << endl;
    }

    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;

    return code;
}

int emp_add_oldColleague(employe & emp)
{
    int code = SUCCESS;
    char exit_char;
    string code_postal = "#";
    string nom_entreprise;
    int id_entreprise;
    vector<string> list_etp;
    char restart = 'n';
    

    do
    {
        restart = 'n';
  
        system( "clear" ) ;
        cout<<"Connecté en tant que " << emp.getNom() << " " << emp.getPrenom() << ", " << emp.getEmail() << endl;
        cout<< "\n" << endl;
        cout << "  =============================================== " << endl ;
        cout << " |                                               | " << endl ;
        cout << " |        AJOUTER D'ANCIEN(NE)S COLLEGUES        | " << endl ;
        cout << " |                                               | " << endl ;
        cout << "  =============================================== " << endl << endl ;

        cout << "\n-> AJOUT PAR ENTREPRISE ";

        cin.ignore();
        cout<<"\n\nENTREPRISE  : " ; getline(cin,nom_entreprise);
        cout<<"\n"<<endl;

        list_etp.clear();
        list_etp = emp.searchEntreprise(nom_entreprise, code_postal);

        if(list_etp.size() > 0)
        {
            cout << "ENTREPRISE(S) TROUVE(ES)\n" << endl;
            for(size_t i=0; i<list_etp.size(); i++) cout << list_etp[i] << endl;

            cout << "\n\nN° DE L'ENTREPRISE DANS LAQUELLE VOUS RECHERCHEZ D'ANCIEN(NE)S COLLEGUES : "; cin>> id_entreprise; cout<<endl;
            
            vector<vector<string>> colleagues;
            colleagues = emp.find_former_colleagues_by_enterprise(id_entreprise);

            if(colleagues.size() > 0)
            {
                int my_id = emp.getId();
                size_t nbr_results = colleagues.size();
                vector<int> list_idOfresults;
                for (size_t i = 0; i < nbr_results; i++)
                    list_idOfresults.push_back(stoi(colleagues[i][3]));
                
                if(existOnVector(list_idOfresults, my_id)) nbr_results -= 1;

                cout<< nbr_results << " ANCIEN(NE)(S) COLLEGUE(S) TROUVE(ES)(S)\n" << endl;

                if(nbr_results > 0){
                
                    for(size_t i=0; i<colleagues.size(); i++) 
                    {
                        //On exclut l'utilisateur courant de la liste de résultats
                        if(my_id != stoi(colleagues[i][3]))
                        {
                            cout<< "\nID     : " << colleagues[i][3] << endl; 
                            cout<< "NOM    : " << colleagues[i][0] << endl;
                            cout<< "PRENOM : " << colleagues[i][1] << endl;
                            cout<< "EMAIL  : " << colleagues[i][2] << endl;
                        }
                    }

                    cout<<"\nENTREZ LES ID DES PERSONNES A AJOUTER A VOTRE LISTE D'ANCIEN(NE)(S) COLLEGUE (UN A UN)"<< endl;
                    cout<<"ENTREZ '0' POUR TERMINER Lcolleagues.size()A SAISIE"<< endl;  

                    int i=0;
                    int id;
                    vector<int> list_id;
                    do{                                         //Boucle pour permettre la saisie de plusieur competence
                        i++;								    //L utilisateur saisi q pour quitter la boucle
                        cout<<"\nID N° "<<i<<" : "; cin>>id;
                        
                        if(id!=0) list_id.push_back(id);   //Pour ne pas enregistrer la lettre q
                        
                    }while(id!=0);

                    
                    if(list_id.size() > 0)
                    {
                        bool exist = false;
                        vector<int> old_c = emp.getColleagues();

                        for(size_t i=0; i<list_id.size(); i++)
                        {
                            for (size_t j = 0; j < old_c.size(); j++)
                            {
                                if(list_id[i] == old_c[j]) exist = true;
                            }
                            
                        }

                        if(exist == false)
                        {
                            code = emp.addColleague(list_id);
                            if(code == SUCCESS) cout << "\nVOTRE LISTE D'ANCIENS COLLEGUES A BIEN ETE MISE A JOUR." << endl;
                                else cout << "\nUNE ERREUR S'EST PRODUITE" << endl;
                        }
                        else{
                            cout<< "CERTAINES DE CES PERSONNES SONT DEJA DANS VOTRE LISTE D'ANCIENS COLLEGUES\n"<<endl;
                            cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
                        }
                    }
                    
                }else{
                    cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
                }
            }
            else
            {
                cout<< "AUCUN(E) COLLEGUE TROUVE(E)\n"<<endl;
                cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
                
            } 
        }
        else
        {
            cout<< "AUCUNE ENTREPRISE TROUVE\n"<<endl;
            cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
            
        }

    }while(restart == 'y');

    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;

    return code;
}

int emp_update_codePostal(employe & emp)
{
    int code = EXIT_WITH_ERROR;
    char exit_char;
    string code_postal;

    system( "clear" ) ;
	cout<<"Connecté en tant que " << emp.getNom() << " " << emp.getPrenom() << ", " << emp.getEmail() << endl;
    cout<< "\n" << endl;
	cout << "  ========================================== " << endl ;
	cout << " |                                          | " << endl ;
	cout << " |          CHANGER LE CODE POSTAL          | " << endl ;
	cout << " |                                          | " << endl ;
	cout << "  ========================================== " << endl << endl ;

    cout<< emp.getCodePostal() << " est votre code postal actuel." << endl;
	cout<<"\nNouveau code postal : " ; cin>> code_postal;  

    code = emp.updateCodePostal(code_postal);
    if(code == SUCCESS) cout << "\nLE CODE POSTAL A BIEN ETE MIS A JOUR" << endl;
        else cout << "\nUNE ERREUR S'EST PRODUITE" << endl;


    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;

    return code;
}

int emp_update_entreprise(employe & emp)
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
        restart = 'n';
        system( "clear" ) ;
        cout<<"Connecté en tant que " << emp.getNom() << " " << emp.getPrenom() << ", " << emp.getEmail() << endl;
        cout<< "\n" << endl;
        cout << "  =============================================== " << endl ;
        cout << " |                                               | " << endl ;
        cout << " |              CHANGER D'ENTREPRISE             | " << endl ;
        cout << " |                                               | " << endl ;
        cout << "  =============================================== " << endl << endl ;

        cout << "*saisir le caractère '#' pour ignorer le champ code postal\n\n" << endl;

        cin.ignore();
        cout<< "ENTREPRISE D'ACCEUIL : " ; getline(cin,nom_entreprise);
        cout<<"\nCODE POSTAL          : " ; getline(cin,code_postal);  
        cout<<"\n"<<endl;

        list_etp.clear();
        list_etp = emp.searchEntreprise(nom_entreprise, code_postal);
        
        if(list_etp.size() > 0)
        {
            cout << "ENTREPRISE(S) TROUVE(ES)\n" << endl;
            for(size_t i=0; i<list_etp.size(); i++) cout << list_etp[i] << endl;

            cout << "\n\nN° DE L'ENTREPRISE QUI VOUS EMBAUCHE : "; cin>> id_entreprise; cout<<endl;
            
            int current_etp_id = emp.getEnterpriseId();
            
            if(current_etp_id != id_entreprise)
            {
                cout << "CONFIRMER LE CHANGEMENT D'ENTREPRISE (y) OU ANNULER (n) ? (y/n) : "; cin>>confirm; cout<<endl;
                
                if(confirm == 'y')
                {
                    code = emp.updateEntreprise(id_entreprise);
                    
                    if(code == SUCCESS)
                    {
                        //On met à jour les information chargées dans l'objet (en session)
                        string email = emp.getEmail();
                        string mdp = emp.getMdp();
                        emp.getEmployeByEmail(email,mdp);

                        cout<< "\n\nVOS INFORMATIONS ONT BIEN ETE MIS A JOUR"<<endl;
                    }
                    else cout<< "\n\nUNE ERREUR S'EST PRODUITE"<<endl;
                }
                else code = SUCCESS;
            }
            else{
                cout<< "\nVOUS FAITE DEJA PARTIE DE CETTE ENTREPRISE\n"<<endl;
                cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
            }

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

int employe_to_jobseeker(employe & emp)
{
    int code = EXIT_WITH_ERROR;
    char exit_char;
    char confirm;

    system( "clear" ) ;
    cout<<"Connecté en tant que " << emp.getNom() << " " << emp.getPrenom() << ", " << emp.getEmail() << endl;
    cout<< "\n" << endl;
    cout << "  =============================================== " << endl ;
    cout << " |                                               | " << endl ;
    cout << " |     PASSER D'EMPLOYE A CHERCHEUR D'EMPLOI     | " << endl ;
    cout << " |                                               | " << endl ;
    cout << "  =============================================== " << endl << endl ;

    
    cout << "CONFIRMER LE CHANGEMENT DE STATUT (y) OU ANNULER (n) ? (y/n) : "; cin>>confirm; cout<<endl;
    
    if(confirm == 'y')
    {
        code = emp.employeToJobseeker();
        
        if(code == SUCCESS)
        {
            cout<< "\n\nVOTRE STATUT A BIEN ETE MIS A JOUR, VOUS ALLEZ ETRE DECONNECTER"<<endl;
            code = DECONNEXION;
        }
        else cout<< "\n\nUNE ERREUR S'EST PRODUITE"<<endl;
    }
    else code = SUCCESS;

    

    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;

    return code;
}

int emp_deleteProfile(employe & emp)
{
    int code = EXIT_WITH_ERROR;
    char confirmation, exit_char;
    
    system( "clear" ) ;

    cout<<"************SUPPRESSION DE COMPTE************" << endl;
    cout<<endl;
    cout << "\n\n CONFIRMEZ-VOUS LA SUPPRESSION DE VOTRE COMPTE ? (y/n) : "; cin>> confirmation;

    if(confirmation == 'y')
    {
        code = emp.deleteEmploye();
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

int emp_search_poste(employe & emp)
{
    int code = SUCCESS;
    char exit_char;
    string code_postal, skill;
    vector<string> skills;

    vector<vector<string>> list_etp;
    char restart = 'n';

    do
    {
        restart = 'n';
        system( "clear" ) ;
        cout<<"Connecté en tant que " << emp.getNom() << " " << emp.getPrenom() << ", " << emp.getEmail() << endl;
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
        list_etp = emp.searchJob(skills,code_postal);
        
        if(list_etp.size() > 0)
        {
            cout << "\nPOSTE(S) TROUVE(S)\n" << endl;
            for(size_t i=0; i<list_etp.size(); i++) cout << "N° " << i+1 
                                                         << "\nPOSTE       : " << list_etp[i][0] 
                                                         << "\nENTRPRISE   : " << list_etp[i][1] 
                                                         << "\nEMAIL       : " << list_etp[i][2] 
                                                         << "\nCODE POSTAL : " << list_etp[i][3] 
                                                         << "\n" << endl;

        }else
        {
            cout<< "\nAUCUNE ENTREPRISE TROUVE\n"<<endl;
            cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
        }

    }while(restart == 'y');

    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;

    return code;
}

int emp_search_oldColleagues( employe & emp )
{
    int code = SUCCESS;
    char exit_char;
    string code_postal = "#";
    string nom_entreprise, skill;
    vector<string> skills;
    int id_entreprise;
    vector<string> list_etp;
    char restart = 'n', type_search = 'x';
    

    do
    {
        restart = 'n';
        while(type_search != 'e' && type_search != 'c')
        {

            system( "clear" ) ;
            cout<<"Connecté en tant que " << emp.getNom() << " " << emp.getPrenom() << ", " << emp.getEmail() << endl;
            cout<< "\n" << endl;
            cout << "  =============================================== " << endl ;
            cout << " |                                               | " << endl ;
            cout << " |      RECHERCHER D'ANCIEN(NE)S COLLEGUES       | " << endl ;
            cout << " |                                               | " << endl ;
            cout << "  =============================================== " << endl << endl ;

            cout << "\n-> RECHERCHE PAR ENTREPRISE (e) OU PAR COMPETENCES (c)  (e/c)? : "; cin>>type_search;
        }
        
        if(type_search == 'e')
        {
            cin.ignore();
            cout<<"\n\nENTREPRISE  : " ; getline(cin,nom_entreprise);
            cout<<"\n"<<endl;

            list_etp.clear();
            list_etp = emp.searchEntreprise(nom_entreprise, code_postal);

            if(list_etp.size() > 0)
            {
                cout << "ENTREPRISE(S) TROUVE(ES)\n" << endl;
                for(size_t i=0; i<list_etp.size(); i++) cout << list_etp[i] << endl;

                cout << "\n\nN° DE L'ENTREPRISE DANS LAQUELLE VOUS RECHERCHEZ D'ANCIEN(NE)S COLLEGUES : "; cin>> id_entreprise; cout<<endl;
                vector<vector<string>> colleagues;
                colleagues = emp.find_former_colleagues_by_enterprise(id_entreprise);

                if(colleagues.size() > 0)
                {
                    cout<< colleagues.size() << " ANCIEN(NE)(S) COLLEGUE(S) TROUVE(ES)(S)\n" << endl;
                    for(size_t i=0; i<colleagues.size(); i++) 
                    {
                        cout<< "\nNOM    : " << colleagues[i][0] << endl;
                        cout<< "PRENOM : " << colleagues[i][1] << endl;
                        cout<< "EMAIL  : " << colleagues[i][2] << endl;
                    }
                }
                else
                {
                    cout<< "AUCUN(E) COLLEGUE TROUVE(E)\n"<<endl;
                    cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
                    if(restart == 'y') type_search = 'x';
                } 
            }
            else
            {
                cout<< "AUCUNE ENTREPRISE TROUVE\n"<<endl;
                cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
                if(restart == 'y') type_search = 'x';
            }
        }
        else if(type_search == 'c')
        {
            vector<vector<string>> colleagues;
            colleagues = emp.find_former_colleagues_by_skills();

            if(colleagues.size() > 0)
            {
                cout<<endl;
                cout<< colleagues.size() << " ANCIEN(NE)(S) COLLEGUE(S) TROUVE(ES)(S)\n" << endl;
                for(size_t i=0; i<colleagues.size(); i++) 
                {
                    cout<< "\nNOM    : " << colleagues[i][0] << endl;
                    cout<< "PRENOM : " << colleagues[i][1] << endl;
                    cout<< "EMAIL  : " << colleagues[i][2] << endl;
                }
            }
            else
            {
                cout<< "\nAUCUN(E) COLLEGUE TROUVE(E)\n"<<endl;
                cout<< "RECOMMENCER (y/n) ? : "; cin >>restart; cout<<endl;
                if(restart == 'y') type_search = 'x';
            } 
        }


    }while(restart == 'y');

    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;

    return code;
}

int emp_update_password(employe & emp)
{
    int code = EXIT_WITH_ERROR;
    char exit_char;
    string old_mdp, new_mdp;

    system( "clear" ) ;
    cout<<"Connecté en tant que " << emp.getNom() << " " << emp.getPrenom() << ", " << emp.getEmail() << endl;
    cout<< "\n" << endl;
	cout << "  ========================================== " << endl ;
	cout << " |                                          | " << endl ;
	cout << " |         CHANGER LE MOT DE PASSE          | " << endl ;
	cout << " |                                          | " << endl ;
	cout << "  ========================================== " << endl << endl ;

    cin.ignore();
    cout << "ENTREZ VOTRE MOT DE PASSE ACTUEL : " ; getline(cin,old_mdp);
	cout << "\nENTREZ LE NOUVEAU MOT DE PASSE   : " ; getline(cin,new_mdp);  

    code = emp.updatemdp(new_mdp,old_mdp);

    if(code == SUCCESS) cout << "\nLE MOT DE PASSE A BIEN ETE MIS A JOUR" << endl;
        else cout << "\nUNE ERREUR S'EST PRODUITE" << endl;


    cout<< "\n\nENTREZ 'q' POUR CONTINUER" << endl;
    cin>> exit_char;

    return code;
}

