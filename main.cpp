#include <iostream>
#include "lib/view.h"
#include "lib/extra3/compression.h"
#include "lib/extra3/decompression.h"
#include "fichier.h"

using namespace std;

//last modif: GNANKENE Cheick   06/04/2020
//=========================================

//Le main pour sera introduit les fonction que vous allez implementer

//Pour les test je propose de le mettre en commentaire en de faire un autre main pour les test




int main()
{
   intialise_date_journal(t_debut);
   decompress_csv_files() ;
   home_screen() ;
   compress_csv_files() ;
   fin_de_session(t_debut);
   
	return 0 ;
}






/*===========================
                           ||
    MAIN DE Sheq le Vrai   ||
                           ||
===========================*/

// int main()
// {
//     //<<end
//     cout<<endl<<endl;
//     cout<<"*********************************************************************************"<<endl;
//     cout<<"*******************************MINI_LINKEDIN*************************************"<<endl;
//     cout<<"*********************************************************************************"<<endl<<endl;
//     int choix;
//     do
//     {
//         system("clear");
//         display_general_menu();  // Affiche le menu général
//         cin>>choix;
//         switch (choix)
//         {
//             int choix_1;
//             int choix_2;
//             case 1:            //GNANDE PARTIE ENTREPRISE
//                 do{
//                     system("clear");
//                     menu_entreprise();  //Dialogue pour du menue entreprise
//                     cin>>choix_1;
//                     switch(choix_1){
//                         case 1:      //Créer un profil entreprise
//                         break;

//                         case 2:      //Supprimer un profil entreprise
//                         break;

//                         case 3:      //Créer le profil d'un poste à pourvoir   
//                         break;

//                         case 4:      // Supprimer le profil d'un poste pourvu
//                         break;

//                         case 5:       //Rechercher parmi les chercheurs d'emploi 
                            
//                             do{
//                                 system("clear");
//                                 rechercher_profil_v_entreprise();
//                                 cin>>choix_2;
//                                 switch(choix_2){
//                                     case 1:      //Rechercher par competence

//                                     break;

//                                     case 2:      //Rechercher par competences et par code postal

//                                     break;

//                                     case 7:   //revenir au menu précédent
    
//                                     break;
 
//                                     case 8:    //Revenir au menu general
//                                     choix_2=7;
//                                     choix_1=8;
//                                     break;

//                                     case 9:    //Quitter le programme
//                                     choix_2=7;
//                                     choix_1=8;
//                                     choix=9;
//                                     break;
//                                 }
//                             }while(choix_2!=7);
                            
//                         break;


//                         case 8:    //Ne fait rien retourne au menu precedent
//                         break;

//                         case 9:     //Quitte le programmme en invalidant les conditions do while
//                             choix_1=8;
//                             choix=9;
//                         break;
//                     }  

//                 }while(choix_1!=8);
//             break;

//             case 2:            //GRANDE PARTIE EMPLOYER
//                     do{
//                     system("clear");
//                     menu_employe(); 
//                     cin>>choix_1;
//                     switch(choix_1){
//                         case 1:               //Creer le profil employer
//                         break;

//                         case 2:               //Modifier le profil employer
                             
//                             do{
//                                 system("clear");
//                                 modifier_profil_employe(); //Dialogue pour savoir ce qu'il faut modifier
//                                 cin>>choix_2;
//                                 switch(choix_2){
//                                     case 1:     //Ajouter des compétences

//                                     break;

//                                     case 2:     //Ajouter un(e) ancien(ne) collègue de travail

//                                     break;

//                                     case 3:   //Modifier le code postal

//                                     break;

//                                     case 4:   // Modifier l'entreprise
                                    
//                                     break;

//                                     case 7:   //revenir au menu précédent
    
//                                     break;
 
//                                     case 8:    //Revenir au menu general
//                                     choix_2=7;
//                                     choix_1=8;
//                                     break;

//                                     case 9:    //Quitter le programme
//                                     choix_2=7;
//                                     choix_1=8;
//                                     choix=9;
//                                     break;
//                                 }
//                             }while(choix_2!=7);
//                         break;

//                         case 3:      //Transitionner le profil de «chercheur d'emploi» à un profil «employé»
//                         break;

//                         case 4:      //Supprimer un profil employer
//                         break;

//                         case 5:    //Rechercher parmi les les postes à pourvoir qui correspondent à son profil
                            
//                             do{
//                                 system("clear");
//                                 rechercher_entreprise(); //Dialoqgue pour savoir comment rechercher l'entreprise
//                                 cin>>choix_2;
//                                 switch(choix_2){
//                                     case 1:     //Rechercher par compétence

//                                     break;

//                                     case 2:     //Rechercher par code postal

//                                     break;

//                                     case 7:   //revenir au menu précédent
    
//                                     break;
 
//                                     case 8:    //Revenir au menu general
//                                     choix_2=7;
//                                     choix_1=8;
//                                     break;

//                                     case 9:    //Quitter le programme
//                                     choix_2=7;
//                                     choix_1=8;
//                                     choix=9;
//                                     break;
//                                 }
//                             }while(choix_2!=7);

//                         break;

//                         case 6:     // Rechercher parmi les anciens collègues
                            
//                             do{
//                                 system("clear");
//                                 recherche_ancien_col(); //Dialogue pour savoir comment rechercher les collegues
//                                 cin>>choix_2;
//                                 switch(choix_2){
//                                     case 1:     //Rechercher par entreprise

//                                     break;

//                                     case 2:     //Rechercher par competence

//                                     break;

//                                     case 7:   //revenir au menu précédent
    
//                                     break;
 
//                                     case 8:    //Revenir au menu general
//                                     choix_2=7;
//                                     choix_1=8;
//                                     break;

//                                     case 9:    //Quitter le programme
//                                     choix_2=7;
//                                     choix_1=8;
//                                     choix=9;
//                                     break;
//                                 }
//                             }while(choix_2!=7);
//                         break;

//                         case 9:
//                             choix_1=8;
//                             choix=9;
//                         break;
//                     }  

//                 }while(choix_1!=8);    
//             break;

//             case 3:             //GRANDE PARTIE CHERCHEUR D'EMPLOI
//                 do{
//                     system("clear");
//                     menu_chercheur_emploi(); 
//                     cin>>choix_1;
//                     switch(choix_1){

//                         case 1:    // Créer un profil 
//                         break;

//                         case 2:    //Modifier un profil 
                             
//                             do{
//                                 system("clear");
//                                 modifier_profil_chercheur(); //Dialogue pour savoir ce qu'il faut modifier
//                                 cin>>choix_2;
//                                 switch(choix_2){
//                                     case 1:     //Ajouter des compétences

//                                     break;

//                                     case 2:     //Ajouter un(e) ancien(ne) collègue de travail

//                                     break;

//                                     case 3:   //Modifier le code postal

//                                     break;

//                                     case 7:   //revenir au menu précédent
    
//                                     break;
 
//                                     case 8:    //Revenir au menu general
//                                     choix_2=7;
//                                     choix_1=8;
//                                     break;

//                                     case 9:    //Quitter le programme
//                                     choix_2=7;
//                                     choix_1=8;
//                                     choix=9;
//                                     break;
//                                 }
//                             }while(choix_2!=7);
//                         break;

//                         case 3:    //Transitionner le profil de «chercheur d'emploi» à un profil «employé»
//                         break;

//                         case 4:    //Supprimer un profil
//                         break;

//                         case 5:    //Rechercher parmi les les postes à pourvoir qui correspondent à son profil 
                            
//                             do{
//                                 system("clear");
//                                 rechercher_entreprise(); //Dialogue pour savoir comment rechercher l'entreprise
//                                 cin>>choix_2;
//                                 switch(choix_2){
//                                     case 1:     //Rechercher par compétence

//                                     break;

//                                     case 2:     //Rechercher par code postal

//                                     break;

//                                     case 7:   //revenir au menu précédent
    
//                                     break;
 
//                                     case 8:    //Revenir au menu general
//                                     choix_2=7;
//                                     choix_1=8;
//                                     break;

//                                     case 9:    //Quitter le programme
//                                     choix_2=7;
//                                     choix_1=8;
//                                     choix=9;
//                                     break;
//                                 }
//                             }while(choix_2!=7);

//                         break;

//                         case 6:    //Rechercher parmi les anciens collègues
                            
//                             do{
//                                 system("clear");
//                                 rechercher_entreprise(); //Dialogue pour savoir comment rechercher l'entreprise
//                                 cin>>choix_2;
//                                 switch(choix_2){
//                                     case 1:     //Rechercher par compétence

//                                     break;

//                                     case 2:     //Rechercher par entreprise

//                                     break;

//                                     case 7:   //revenir au menu précédent
    
//                                     break;
 
//                                     case 8:    //Revenir au menu general
//                                     choix_2=7;
//                                     choix_1=8;
//                                     break;

//                                     case 9:    //Quitter le programme
//                                     choix_2=7;
//                                     choix_1=8;
//                                     choix=9;
//                                     break;
//                                 }
//                             }while(choix_2!=7);
//                         break;

//                         case 9:     //ferme le programme
//                             choix_1=8;
//                             choix=9;
//                         break;
//                     }  

//                 }while(choix_1!=8);
//             break;
//         }
//     }while(choix!=9);
    
//     return 0;
// }