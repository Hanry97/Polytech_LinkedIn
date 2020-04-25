#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fichier.h"
#include "constante.h"
#include <sstream>

using namespace std;

//GENERICS FUNCTIONS

bool existOnVector(vector<int> tab, int val)
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


int get_lastID(string const path)
{
    int id = 0;
    
    ifstream table_file(path.c_str());

    if(table_file){
        
        string ligne, word, last_ligne;
        int c = 0;
        vector<string> row; 
        
        while(getline(table_file, ligne)) {
            last_ligne = ligne;
            c++;
        }                   //Tant qu'on n'est pas à la fin, on lit. A la fin ligne contient la dernière ligne
        
        if(c>1){
            // utilisé pour casser des mots 
            stringstream s(last_ligne); 
            // On lit chaque colone de la ligne 
            // On stock dans word 
            while (getline(s, word, ',')) { 
                // On ajoute chaque colonne 
                // de word au tableau 
                // la colonne id est en row[0]
                row.push_back(word); 
            } 

            id = stoi(row[0]);  
        }                
    
    }else{

        cout << "ERREUR: Impossible d'ouvrir le fichier " << path << endl; //à écrire dans le journal
        id = -1;
    }

    table_file.close();

    return id;
}




vector <int> get_List_Of_idPost_Of_Enterprise(int id_enterprise)
{

    vector <int> tab_of_post_id;
    ifstream tablePoste_file(tablePoste.c_str());

    if(tablePoste_file){
         
        vector<string> row; 
        string line, word, temp;
        int enterprise_id;
        int poste_id;

        getline(tablePoste_file, line); // La ligne contenant l'entete 
        while (getline(tablePoste_file, line)) { 
  
            row.clear(); 
    
            // On lit une ligne entière 
            // On la stock dans la variable 'line' 
             
    
            // utilisé pour casser des mots 
            stringstream s(line); 
    
            // On lit chaque colone de la ligne 
            // On stock dans word 
            while (getline(s, word, ',')) { 
    
                // On ajoute chaque colonne 
                // de word au tableau 
                row.push_back(word); 
            } 
    
            // On convertit la 3e colonne (id_entreprise) en int
            // Pour pouvoir effectuer la comparaison 
            enterprise_id = stoi(row[3]); 
    
            // Si l'id de l'entreprise correspond, on ajoute au tableau l'id du poste
            if (enterprise_id == id_enterprise){

                poste_id = stoi(row[0]); 
                tab_of_post_id.push_back(poste_id);
            } 
        } 

    }else{

        cout << "ERREUR: Impossible d'ouvrir le fichier " << tablePoste << endl; //à écrire dans le journal
    }

    return tab_of_post_id;
}



int delete_list_of_row_from_table(vector<int> listOfRowsID, string const path_table)
{
    int code = SUCCESS;
    string row_old_table;
    const char * path = path_table.c_str();
    vector<string> row; 
    string word;

    ifstream table_file(path);

    if(table_file){
        
        ofstream newTable_file("database/new_tmp.csv", ios::app);

        if(newTable_file){
             int id_on_line;
             
             if (path_table == tableEntreprise) newTable_file << header_tableEntreprise << endl;
             else if (path_table == tablePoste) newTable_file << header_tablePoste << endl;

             getline(table_file, row_old_table);
             while(getline(table_file, row_old_table)){

                 row.clear();
                // utilisé pour casser des mots 
                stringstream s(row_old_table); 
                // On lit chaque colone de la ligne 
                // On stock dans word 
                while (getline(s, word, ',')) { 
                    // On ajoute chaque colonne 
                    // de word au tableau 
                    // la colonne id est en row[0]
                    row.push_back(word); 
                } 
                id_on_line = stoi(row[0]);
                 
                if(existOnVector(listOfRowsID,id_on_line) == false){            
                    newTable_file << row_old_table << endl;
                }
             }
             if( remove(path) != 0 ) code = ERROR_REMOVE_FILE;
             if( rename("database/new_tmp.csv", path) != 0 ) code = ERROR_RENAME_FILE;

        }else{
            cout << "ERREUR: Impossible de creer le fichier new_tmp.csv" << endl;
            code = OPEN_FILE_ERROR;
        }
        newTable_file.close();

    }else{

        cout << "ERREUR: Impossible d'ouvrir le fichier " << path << endl; //à écrire dans le journal
        code = OPEN_FILE_ERROR;
    }

    table_file.close();
    

    return code;
}

bool skillFounded(std::vector<std::string> tab, std::string val)
{
    bool exist = false;
    int sizeOfList = tab.size();
    int c = 0;

    while (c<sizeOfList && exist == false)
    {
        if(tab[c] == val) exist = true;
        c++;
    }
    

    return exist;
}

//FUNCTIONS OF THE ENTERPRISE

int etp_create_profile(string nom, string code_postal, string email) 
{ 
    int id;
    int code;

    int lastID = get_lastID(tableEntreprise);

    if(lastID != -1){
        
        id = lastID + 1;

        ofstream flux(tableEntreprise.c_str(), ios::app);

        if(flux)    
        {
            flux << id << "," << nom << "," << code_postal << "," << email << endl;
            code = SUCCESS;
        }else{
            cout << "ERREUR: Impossible d'ouvrir le fichier " << tableEntreprise << endl;
            code = OPEN_FILE_ERROR;
        }

        flux.close();
    
    }else{
        code = SUB_FUNCTION_ERROR;
    }

    return code;
	
} 

int etp_create_profileOfPosition(string titre, string skills, int entreprise_id){

    int code = EXIT_WITH_ERROR;
    int id,lastID;

    lastID = get_lastID(tablePoste);

    if(lastID != -1){

        id = lastID +1;
        ofstream flux(tablePoste.c_str(), ios::app);
        
        if(flux)    
        {
            flux << id << "," << titre << "," << skills << "," << entreprise_id << endl;
            code = SUCCESS;
        }else{
            cout << "ERREUR: Impossible d'ouvrir le fichier " << tableEntreprise << endl;
            code = OPEN_FILE_ERROR;
        }

        flux.close();

    }else{
        code = SUB_FUNCTION_ERROR;
    }

    return code;
}

int etp_delete_profileOfPosition(int id_etp,int id_poste)
{
    
    int code = EXIT_WITH_ERROR;
    
    vector<int> tab_OnePost;
    vector<int> tab_List_Post_of_entreprise;

    tab_List_Post_of_entreprise = get_List_Of_idPost_Of_Enterprise(id_etp);

    if(existOnVector(tab_List_Post_of_entreprise,id_poste) == true){

        tab_OnePost.push_back(id_poste);
        code = delete_list_of_row_from_table(tab_OnePost,tablePoste);

    }
    
    return code;
}

int etp_delete_profile(int id_entreprise)
{
    int code_op1 = EXIT_WITH_ERROR;
    int code_op2 = EXIT_WITH_ERROR;
    int code = EXIT_WITH_ERROR;
    vector<int> list_of_id;

    list_of_id = get_List_Of_idPost_Of_Enterprise(id_entreprise);

    if(list_of_id.size() > 0){
        
        code_op1 = delete_list_of_row_from_table(list_of_id,tablePoste);
        if(code_op1 == SUCCESS){
            
            vector<int> tab_OneID;
            tab_OneID.push_back(id_entreprise);
            
            code_op2 = delete_list_of_row_from_table(tab_OneID,tableEntreprise);
            if (code_op2 == SUCCESS)
            {
                code = SUCCESS;
            }else{
                code = code_op2;
            }
            
        }else{
            code = code_op1;
        }
    }
    

    return code;    
}

vector <vector <string> > etp_searchToHire(vector<string> list_competence,string code_postal)
{
    vector <vector <string> > list_of_result;

    ifstream table_file(tableJobseeker.c_str());

    if(table_file){

        string ligne, word, sub_word, skill, last_ligne;
        int x = 0;
        bool match = false;
        vector<string> row; 
        vector<string> employe;
        
        getline(table_file, ligne);        //Ligne de l'entete
        while(getline(table_file, ligne)) {

            employe.clear();
            stringstream s(ligne); 

            while (getline(s, word, ',')) { 
                row.push_back(word); 
            }
            sub_word = row[5];

            stringstream ss(sub_word);
            while (getline(ss, skill, ';') && match == false) { 
                match = skillFounded(list_competence,skill); 
            } 

            if(match == true){
                if((code_postal != "#" && row[4] == code_postal) || (code_postal == "#")){
                    for(int i=0;i<4;i++) employe.push_back(row[i]);
                    list_of_result.push_back(employe);
                    ++x;
                }
                
            }  
        } 

    }else{
        cout << "ERREUR: Impossible d'ouvrir le fichier " << tableJobseeker << endl; //à écrire dans le journal
    }
    table_file.close();

    return list_of_result;
}

