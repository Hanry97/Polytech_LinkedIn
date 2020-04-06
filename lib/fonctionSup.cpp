#include <iostream>
using namespace std;

//last modif: GNANKENE Cheick   06/04/2020
//=========================================

void rechercher_entreprise()
{
    cout<<"===================================================================================="<<endl;
    cout<<"||                          RECHERCHER UNE ENTREPRISE                             ||"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                         Comment souhaitez vous rechercher :                      |"<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                             1-Par Competence                                     |"<<endl;
    cout<<"|                             2-Par Competence et par Code Postal                  |"<<endl;
    cout<<"|                             7-Retourner au Menu precedent                        |"<<endl;
    cout<<"|                             8-Retourner au MENU GENERAL                          |"<<endl;
    cout<<"|                             9-Quitter le Programme                               |"<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<" Veuillez entrer le numero de votre choix  : ";
}

void recherche_ancien_col()
{
    cout<<"===================================================================================="<<endl;
    cout<<"||                   AFFICHER MES ANCIEN COLLEGUES DE TRAVAIL                     ||"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                   Comment souhaitez lister vos ancien collegues :                |"<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                             1-Lister par entreprise                              |"<<endl;
    cout<<"|                             2-Lister par Competence                              |"<<endl;
    cout<<"|                             7-Retourner au Menu precedent                        |"<<endl;
    cout<<"|                             8-Retourner au MENU GENERAL                          |"<<endl;
    cout<<"|                             9-Quitter le Programme                               |"<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<" Veuillez entrer le numero de votre choix  : ";
}

void modifier_profil_employe()
{
    cout<<"===================================================================================="<<endl;
    cout<<"||                            MODIFIER MON PROFIL EMPLOYER                        ||"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                             Que souhaitez vous faire ?:                          |"<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                             1-Ajouter une compétence                             |"<<endl;
    cout<<"|                             2-Ajouter un(e) ancien(ne) collègue de travail       |"<<endl;
    cout<<"|                             3-Modifier mon code postal                           |"<<endl;
    cout<<"|                             4-Modifier mon entreprise                            |"<<endl;
    cout<<"|                             7-Retourner au Menu precedent                        |"<<endl;
    cout<<"|                             8-Retourner au MENU GENERAL                          |"<<endl;
    cout<<"|                             9-Quitter le Programme                               |"<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<" Veuillez entrer le numero de votre choix  : ";
}

void modifier_profil_chercheur()
{
    cout<<"===================================================================================="<<endl;
    cout<<"||                     MODIFIER MON PROFIL CHERCHEUR D'EMPLOI                     ||"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                             Que souhaitez vous faire ?:                          |"<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                             1-Ajouter une compétence                             |"<<endl;
    cout<<"|                             2-Ajouter un(e) ancien(ne) collègue de travail       |"<<endl;
    cout<<"|                             3-Modifier mon code postal                           |"<<endl;
    cout<<"|                             7-Retourner au Menu precedent                        |"<<endl;
    cout<<"|                             8-Retourner au MENU GENERAL                          |"<<endl;
    cout<<"|                             9-Quitter le Programme                               |"<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<" Veuillez entrer le numero de votre choix  : ";
}

void rechercher_profil_v_entreprise()
{
    cout<<"===================================================================================="<<endl;
    cout<<"||                   RECHERCHER UN CHERCHEUR D'EMPLOI                             ||"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                         Comment souhaitez vous rechercher :                      |"<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                             1-Par Competence                                     |"<<endl;
    cout<<"|                             2-Par Competence et par Code Postal                  |"<<endl;
    cout<<"|                             7-Retourner au Menu precedent                        |"<<endl;
    cout<<"|                             8-Retourner au MENU GENERAL                          |"<<endl;
    cout<<"|                             9-Quitter le Programme                               |"<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<" Veuillez entrer le numero de votre choix  : ";
}

void menu_entreprise()
{           
    
    cout<<"===================================================================================="<<endl;
    cout<<"||                                MENU ENTREPRISE                                 ||"<<endl;
    cout<<"===================================================================================="<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                         Que souhaitez vous faire:                                |"<<endl;
    cout<<"|                                                                                  |"<<endl;
    cout<<"|                             1-Créer un profil                                    |"<<endl;
    cout<<"|                             2-Supprimer un profil                                |"<<endl;
    cout<<"|                             3-Créer le profil d'un poste à pourvoir              |"<<endl;
    cout<<"|                             4-Supprimer le profil d'un poste pourvu              |"<<endl;
    cout<<"|                             5- Rechercher parmi les chercheurs d'emploi pour     |"<<endl;
    cout<<"|                              des profils qui correspondent à un poste à pourvoir |"<<endl;                                 
    cout<<"|                             8-Retourner au menu précédent                        |"<<endl;
    cout<<"|                             9-Quitter le programme                               |"<<endl;
    cout<<"|                                                                                  |"<<endl; 
    cout<<"===================================================================================="<<endl;
    cout<<" Veuillez entrer le numero de votre choix  : ";
}

void menu_employe()
{
    
    cout<<"========================================================================================"<<endl;
    cout<<"||                                MENU EMPLOYER                                       ||"<<endl;
    cout<<"========================================================================================"<<endl;
    cout<<"|                                                                                      |"<<endl;
    cout<<"|                         Que souhaitez vous faire:                                    |"<<endl;
    cout<<"|                                                                                      |"<<endl;
    cout<<"|                         1-Créer votre profil                                         |"<<endl;
    cout<<"|                         2-Modifier votre profil                                      |"<<endl;
    cout<<"|                         3-Devenir un chercheur d'emploi                              |"<<endl;
    cout<<"|                         4-Supprimer le profil                                        |"<<endl; 
    cout<<"|                         5-Rechercher les postes me correspondant                     |"<<endl;
    cout<<"|                         6-Recherche parmi les anciens collègues                      |"<<endl;
    cout<<"|                         8-Retourner au menu précédent                                |"<<endl;
    cout<<"|                         9-Quitter le programme                                       |"<<endl;
    cout<<"|                                                                                      |"<<endl; 
    cout<<"======================================================================================="<<endl;
    cout<<" Veuiillez entrer le numero de votre choix  : "; 
}
void menu_chercheur_emploi()
{
    
    cout<<"========================================================================================"<<endl;
    cout<<"||                                MENU CHERCHEUR D'EMPLOI                             ||"<<endl;
    cout<<"========================================================================================"<<endl;
    cout<<"|                                                                                      |"<<endl;
    cout<<"|                         Que souhaitez vous faire:                                    |"<<endl;
    cout<<"|                                                                                      |"<<endl;
    cout<<"|                         1-Créer votre profil                                         |"<<endl;
    cout<<"|                         2-Modifier votre profil                                      |"<<endl;
    cout<<"|                         3-Devenir employé                                            |"<<endl;
    cout<<"|                         4-Supprimer le profil                                        |"<<endl; 
    cout<<"|                         5-Rechercher les postes me correspondant                     |"<<endl;
    cout<<"|                         6-Recherche parmi les anciens collègues                      |"<<endl;
    cout<<"|                         8-Retourner au menu précédent                                |"<<endl;
    cout<<"|                         9-Quitter le programme                                       |"<<endl; 
    cout<<"======================================================================================="<<endl;
    cout<<" Veuillez entrer le numero de votre choix  : ";
}

void menu_gen()
{
    cout<<"================================================================================="<<endl;
    cout<<"||                                MENU GENERAL                                 ||"<<endl;
    cout<<"================================================================================="<<endl;
    cout<<"|                                                                               |"<<endl;
    cout<<"|           Vous souhaitez utilisez l'applications en tant que:                 |"<<endl;
    cout<<"|                                                                               |"<<endl;
    cout<<"|                             1-Entreprise                                      |"<<endl;
    cout<<"|                             2-Employé                                         |"<<endl;
    cout<<"|                             3-Chercheur d'emploie                             |"<<endl;
    cout<<"|                             9-Quitter le programme                            |"<<endl;
    cout<<"================================================================================="<<endl;
    cout<<" Veuiillez entrer le numero de votre choix  : ";
}