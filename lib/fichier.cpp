/*
 ===============================================
||  Auteur ::                 Hanry Nzale      ||
 ===============================================
|| Dernière modification ::   28/04/2020       ||
 ===============================================
*/

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

             newTable_file << get_tableHeader(path_table) << endl;

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

int update_row(int id_row, string new_row, string const path_table)
{
    int code  = SUCCESS;
    string row_old_table;
    const char * path = path_table.c_str();
    vector<string> row; 
    string word;

    ifstream table_file(path);

    if(table_file){
        
        ofstream newTable_file("database/new_tmp.csv", ios::app);

        if(newTable_file){
             int id_on_line;

             newTable_file << get_tableHeader(path_table) << endl;

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
                 
                if(id_on_line == id_row){            
                    newTable_file << new_row << endl;
                }else{
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

string get_tableHeader(std::string const path_table)
{
    string table_header = "";

    if (path_table == tableEntreprise) table_header = header_tableEntreprise;
    else if (path_table == tablePoste) table_header = header_tablePoste;
    else if (path_table == tableJobseeker) table_header = header_tableJobseeker;

    return table_header;
}

string get_tableRow(int id, string const path)
{
    string table_row = "";
    
    ifstream table_file(path.c_str());

    if(table_file){
        
        string ligne, word;
        int id_row = -1;
        vector<string> row; 
        
        getline(table_file, ligne);
        while(getline(table_file, ligne) && id_row == -1) {
            row.clear();
            // utilisé pour casser des mots 
            stringstream s(ligne); 
            // On lit chaque colone de la ligne 
            // On stock dans word 
            while (getline(s, word, ',')) { 
                // On ajoute chaque colonne 
                // de word au tableau 
                // la colonne id est en row[0]
                row.push_back(word); 
            } 

            id_row = stoi(row[0]);
            if(id_row==id) table_row = ligne;
        }                   
    
    }else{

        cout << "ERREUR: Impossible d'ouvrir le fichier " << path << endl; //à écrire dans le journal
        id = -1;
    }

    table_file.close();

    return table_row;
}

vector<string> get_Allemploye_fromEnterprise(int id_entreprise)
{
    vector<string> list_result;
    
    ifstream table_file(tableEntreprise.c_str());

    if(table_file){
        
        string ligne, word;
        int id_etp = -1;
        vector<string> row; 
        
        getline(table_file, ligne);
        while(getline(table_file, ligne)) {
            row.clear();
            // utilisé pour casser des mots 
            stringstream s(ligne); 
            // On lit chaque colone de la ligne 
            // On stock dans word 
            while (getline(s, word, ',')) { 
                // On ajoute chaque colonne 
                // de word au tableau 
                // la colonne id est en row[0]
                row.push_back(word); 
            } 

            id_etp = stoi(row[7]);
            if(id_etp==id_entreprise) list_result.push_back(ligne);
        }                   
    
    }else{

        cout << "ERREUR: Impossible d'ouvrir le fichier " << tableEntreprise << endl; //à écrire dans le journal
    }

    table_file.close();

    return list_result;
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

int etp_create_profileOfPosition(string titre, vector<string> skills, int entreprise_id){

    int code = EXIT_WITH_ERROR;
    int id,lastID;

    lastID = get_lastID(tablePoste);

    if(lastID != -1){

        id = lastID +1;
        string string_skills = "";
        int i;
        int nb_skills = skills.size();

        if(nb_skills > 1){
            for(i=0; i<nb_skills - 1; i++) string_skills = string_skills + skills[i] + ";";
            string_skills = string_skills + skills[i];                                      //On ajoute la dernière de la liste;  
        }else{
            string_skills = string_skills + skills[0];
        }
        ofstream flux(tablePoste.c_str(), ios::app);
        
        if(flux)    
        {
            flux << id << "," << titre << "," << string_skills << "," << entreprise_id << endl;
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

vector<vector<string>> etp_searchToHire(vector<string> list_competence,string code_postal)
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
            row.clear();
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

//FUNCTIONS OF THE JOBSEEKER

int jsk_create_profile(string nom, string prenom, string email, string code_postal, vector<string> skills)
{
    int id;
    int code;

    int lastID = get_lastID(tableJobseeker);

    if(lastID != -1){
        
        id = lastID + 1;
        string string_skills = "";
        int i;
        int nb_skills = skills.size();

        if(nb_skills > 1){
            for(i=0; i<nb_skills - 1; i++) string_skills = string_skills + skills[i] + ";";
            string_skills = string_skills + skills[i];                                      //On ajoute la dernière de la liste;  
        }else{
            string_skills = string_skills + skills[0];
        }

        ofstream flux(tableJobseeker.c_str(), ios::app);

        if(flux)    
        {
            flux << id << "," << nom << "," << prenom << "," << email << "," << code_postal << "," << string_skills << endl;
            code = SUCCESS;
        }else{
            cout << "ERREUR: Impossible d'ouvrir le fichier " << tableJobseeker << endl;
            code = OPEN_FILE_ERROR;
        }

        flux.close();
    
    }else{
        code = SUB_FUNCTION_ERROR;
    }

    return code;
}

int jsk_add_skills(int id_jsk,vector<string> skills)
{
    int code = EXIT_WITH_ERROR;
    string string_skills = "";
    string oldrow;
    string skill;
    int i;
    int nb_skills = skills.size();

    

    oldrow = get_tableRow(id_jsk,tableJobseeker);

    if(oldrow != ""){
        vector<string> row;
        string ligne,word;

        stringstream s(oldrow); 
        while (getline(s, word, ',')) {
            row.push_back(word);            //On récupère les colonnes
        } 
        stringstream ss(row[5]);
        while (getline(ss, skill, ';')) {
            string_skills = string_skills + skill + ";";            //On récupère les compétences
        }

        if(nb_skills > 1){
            for(i=0; i<nb_skills - 1; i++) string_skills = string_skills + skills[i] + ";";
            string_skills = string_skills + skills[i];                                       
        }else{
            string_skills = string_skills + skills[0];
        }
        
        ligne = ligne + row[0];
        for(size_t i=1; i<row.size(); i++){
            if(i != 5) ligne = ligne + "," + row[i];
            else ligne = ligne + "," + string_skills;
        }

        code = update_row(id_jsk,ligne,tableJobseeker);


    }

    return code;
}

int jsk_add_colleague(int id_jsk, vector<int> colleague)
{
    int code = EXIT_WITH_ERROR;
    string string_colleague = "";
    string oldrow;
    string collegue;
    int i;
    int nb_colleague = colleague.size();

    

    oldrow = get_tableRow(id_jsk,tableJobseeker);

    if(oldrow != ""){
        vector<string> row;
        string ligne,word;

        stringstream s(oldrow); 
        while (getline(s, word, ',')) {
            row.push_back(word);            //On récupère les colonnes
        } 
        if(row.size() == 7){
            stringstream ss(row[6]);
            while (getline(ss, collegue, ';')) {
                string_colleague = string_colleague + collegue + ";";            //On récupère les compétences
            }
        }

        if(nb_colleague > 1){
            for(i=0; i<nb_colleague - 1; i++) string_colleague = string_colleague + to_string(colleague[i]) + ";";
            string_colleague = string_colleague + to_string(colleague[i]);                                       
        }else{
            string_colleague = string_colleague + to_string(colleague[0]);
        }
        
        ligne = ligne + row[0];
        for(size_t i=1; i<7; i++){
            if(i != 6) ligne = ligne + "," + row[i];
            else ligne = ligne + "," + string_colleague;
        }

        code = update_row(id_jsk,ligne,tableJobseeker);


    }

    return code;
}

int jsk_update_code_postal(int id_jsk, std::string new_code_postale)
{
    int code = EXIT_WITH_ERROR;
    string new_row = "";
    string oldrow;

    oldrow = get_tableRow(id_jsk,tableJobseeker);

    if(oldrow != ""){
        vector<string> row;
        string ligne,word;

        stringstream s(oldrow); 
        while (getline(s, word, ',')) {
            row.push_back(word);            //On récupère les colonnes
        } 
        
        ligne = ligne + row[0];
        for(size_t i=1; i<row.size(); i++){
            if(i != 4) ligne = ligne + "," + row[i];
            else ligne = ligne + "," + new_code_postale;
        }

        code = update_row(id_jsk,ligne,tableJobseeker);


    }

    return code;
}

int jsk_profile_transition_to_employe(int id_jsk, int id_enterprise)
{
    int code = EXIT_WITH_ERROR;
    string new_row = "";
    string oldrow;

    oldrow = get_tableRow(id_jsk,tableJobseeker);

    if(oldrow != ""){
        vector<string> row;
        vector<string> skills;
        vector<int> colleagues;
        string ligne,word;

        stringstream s(oldrow); 
        while (getline(s, word, ',')) {
            row.push_back(word);            //On récupère les colonnes
        } 
        
        string nom =  row[1];
        string prenom = row[2];
        string email = row[3];
        string code_postal = row[4];

        string skill;
        stringstream ss(row[5]);
        while (getline(ss, skill, ';')) {
            skills.push_back(skill);            //On récupère les compétences
        }

        if(row.size() == 7){
            string colleague;
            stringstream sc(row[6]);

            while (getline(sc, colleague, ';')) {
                colleagues.push_back(stoi(colleague));            //On récupère les compétences
            }
        }

        code = emp_create_profile(nom, prenom, email, code_postal, skills, colleagues, id_enterprise);

        if(code == SUCCESS)
        {
            vector<int> listRow;

            listRow.push_back(id_jsk);

            code = delete_list_of_row_from_table(listRow,tableJobseeker);
        }


    }

    return code;
}

int jsk_delete_profile(int id)
{
    int code = EXIT_WITH_ERROR;

    vector<int> tab_OneID;
    tab_OneID.push_back(id);
    
    code = delete_list_of_row_from_table(tab_OneID,tableJobseeker);
    
    return code;
}

vector<vector<string>> jsk_searchJob(vector<string> list_competence,string code_postal)
{
    vector <vector <string> > list_of_result;

    ifstream table_file(tablePoste.c_str());

    if(table_file){

        string ligne, word, sub_word, skill, last_ligne;
        bool match = false;
        vector<string> row; 
        vector<string> poste;
        
        getline(table_file, ligne);        //Ligne de l'entete
        while(getline(table_file, ligne)) {

            poste.clear();
            row.clear();
            stringstream s(ligne); 

            while (getline(s, word, ',')) {     //On met chaque champ dans le tableau row
                row.push_back(word); 
            }
            sub_word = row[2];                  //row[2] contient les compétences

            stringstream ss(sub_word);
            while (getline(ss, skill, ';') && match == false) { 
                match = skillFounded(list_competence,skill);        //Si une compétence correspond on valide
            } 

            if(match == true)                           //Si au moins une compétence correspond
            {                                           //On recherche l'entreprise correspondant au poste
                string data_enterprise;                 //L'id de l'entreprise est dans row[3]
                string enterprise = "";
                vector<string> data; 

                enterprise = get_tableRow(stoi(row[3]), tableEntreprise);
                if(enterprise != "")
                {
                    
                    stringstream sx(enterprise);
                    data.clear();

                    while(getline(sx, data_enterprise, ','))
                    {
                        data.push_back(data_enterprise);
                    }

                    if((code_postal != "#" && data[3] == code_postal) || (code_postal == "#"))
                    {
                        poste.push_back(row[1]);        //On met dans poste[0] le titre du poste
                        poste.push_back(data[1]);       //On met dans poste[1] le nom
                        poste.push_back(data[3]);       //On met dans poste[2] l'adresse mail
                        poste.push_back(data[2]);       //On met dans poste[3] le code postal
                    }
                }
                list_of_result.push_back(poste);
            }
  
        } 

    }else{
        cout << "ERREUR: Impossible d'ouvrir le fichier " << tablePoste << endl; //à écrire dans le journal
    }
    table_file.close();

    return list_of_result;
}

std::vector<std::vector <std::string>> jsk_find_former_colleagues_by_enterprise(int enterprise)
{
    vector <vector <string> > list_of_result;

    ifstream table_file(tableEmployes.c_str());

    if(table_file)
    {
        string ligne, word;
        vector<string> row; 
        vector<string> collegue;
        
        getline(table_file, ligne);        //Ligne de l'entete
        while(getline(table_file, ligne)) 
        {
            stringstream s(ligne); 
            row.clear();

            while (getline(s, word, ',')) { 
                row.push_back(word); 
            }

            if(stoi(row[7]) == enterprise)
            {
                collegue.clear();
                collegue.push_back(row[1]);
                collegue.push_back(row[2]);
                collegue.push_back(row[3]);

                list_of_result.push_back(collegue);
            }

            row.clear();
        }
    }else{
        cout << "ERREUR: Impossible d'ouvrir le fichier " << tableEmployes << endl; //à écrire dans le journal
    }
    table_file.close();

    return list_of_result;
}

//FUNCTIONS OF THE EMPLOYE

int emp_create_profile(string nom, string prenom, string email, string code_postal, vector<string> skills, vector<int> colleagues, int id_enterprise)
{
    int id;
    int code;

    int lastID = get_lastID(tableEmployes);

    if(lastID != -1){
        
        id = lastID + 1;
        string string_skills = "";
        int i;
        int nb_skills = skills.size();

        if(nb_skills > 1){
            for(i=0; i<nb_skills - 1; i++) string_skills = string_skills + skills[i] + ";";
            string_skills = string_skills + skills[i];                                      //On ajoute la dernière de la liste;  
        }else{
            string_skills = string_skills + skills[0];
        }

        int nb_colleagues = colleagues.size();
        string string_colleagues = "";

        if(nb_colleagues > 1){
            for(i=0; i<nb_colleagues - 1; i++) string_colleagues = string_colleagues + to_string(colleagues[i]) + ";";
            string_colleagues = string_colleagues + to_string(colleagues[i]);                                      //On ajoute la dernière de la liste;  
        }else{
            string_colleagues = string_colleagues + to_string(colleagues[0]);
        }

        ofstream flux(tableEmployes.c_str(), ios::app);

        if(flux)    
        {
            flux << id << "," << nom << "," << prenom << "," << email << "," << code_postal << "," << string_skills << "," << string_colleagues << "," << to_string(id_enterprise) << endl;
            code = SUCCESS;
        }else{
            cout << "ERREUR: Impossible d'ouvrir le fichier " << tableEmployes << endl;
            code = OPEN_FILE_ERROR;
        }

        flux.close();
    
    }else{
        code = SUB_FUNCTION_ERROR;
    }

    return code;
}

int emp_add_skills(int id_emp, vector<string> skills)
{
    int code = EXIT_WITH_ERROR;
    string string_skills = "";
    string oldrow;
    string skill;
    int i;
    int nb_skills = skills.size();

    

    oldrow = get_tableRow(id_emp,tableEmployes);

    if(oldrow != ""){
        vector<string> row;
        string ligne,word;

        stringstream s(oldrow); 
        while (getline(s, word, ',')) {
            row.push_back(word);            //On récupère les colonnes
        } 
        stringstream ss(row[5]);
        while (getline(ss, skill, ';')) {
            string_skills = string_skills + skill + ";";            //On récupère les compétences
        }

        if(nb_skills > 1){
            for(i=0; i<nb_skills - 1; i++) string_skills = string_skills + skills[i] + ";";
            string_skills = string_skills + skills[i];                                       
        }else{
            string_skills = string_skills + skills[0];
        }
        
        ligne = ligne + row[0];
        for(size_t i=1; i<row.size(); i++){
            if(i != 5) ligne = ligne + "," + row[i];
            else ligne = ligne + "," + string_skills;
        }

        code = update_row(id_emp,ligne,tableEmployes);


    }

    return code;
}

int emp_add_colleague(int id_emp, std::vector<int> colleague)
{
    int code = EXIT_WITH_ERROR;
    string string_colleague = "";
    string oldrow;
    string collegue;
    int i;
    int nb_colleague = colleague.size();

    

    oldrow = get_tableRow(id_emp,tableEmployes);

    if(oldrow != ""){
        vector<string> row;
        string ligne,word;

        stringstream s(oldrow); 
        while (getline(s, word, ',')) {
            row.push_back(word);            //On récupère les colonnes
        } 
        if(row[6] != ""){
            stringstream ss(row[6]);
            while (getline(ss, collegue, ';')) {
                string_colleague = string_colleague + collegue + ";";            //On récupère les compétences
            }
        }

        if(nb_colleague > 1){
            for(i=0; i<nb_colleague - 1; i++) string_colleague = string_colleague + to_string(colleague[i]) + ";";
            string_colleague = string_colleague + to_string(colleague[i]);                                       
        }else{
            string_colleague = string_colleague + to_string(colleague[0]);
        }
        
        ligne = ligne + row[0];
        for(size_t i=1; i<row.size(); i++){
            if(i != 6) ligne = ligne + "," + row[i];
            else ligne = ligne + "," + string_colleague;
        }

        code = update_row(id_emp,ligne,tableEmployes);

    }

    return code;
}

int emp_update_code_postal(int id_emp, std::string new_code_postale)
{
    int code = EXIT_WITH_ERROR;
    string new_row = "";
    string oldrow;

    oldrow = get_tableRow(id_emp,tableEmployes);

    if(oldrow != ""){
        vector<string> row;
        string ligne,word;

        stringstream s(oldrow); 
        while (getline(s, word, ',')) {
            row.push_back(word);            //On récupère les colonnes
        } 
        
        ligne = ligne + row[0];
        for(size_t i=1; i<row.size(); i++){
            if(i != 4) ligne = ligne + "," + row[i];
            else ligne = ligne + "," + new_code_postale;
        }

        code = update_row(id_emp,ligne,tableEmployes);


    }

    return code;
}

int emp_update_enterprise(int id_emp, int new_id_enterprise)
{
    int code = EXIT_WITH_ERROR;
    string new_row = "";
    string oldrow;

    oldrow = get_tableRow(id_emp,tableEmployes);

    if(oldrow != ""){
        vector<string> row;
        string ligne,word;

        stringstream s(oldrow); 
        while (getline(s, word, ',')) {
            row.push_back(word);            //On récupère les colonnes
        } 
        
        ligne = ligne + row[0];
        for(size_t i=1; i<row.size(); i++){
            if(i != 7) ligne = ligne + "," + row[i];
            else ligne = ligne + "," + to_string(new_id_enterprise);
        }

        code = update_row(id_emp,ligne,tableEmployes);


    }

    return code;
}

int emp_profile_transition_to_jobseeker(int id_emp, int id_etp)
{
    int code = EXIT_WITH_ERROR, code1 = EXIT_WITH_ERROR, code2 = EXIT_WITH_ERROR, code3 = EXIT_WITH_ERROR;
    string new_row = "";
    string oldrow;
    int id_created = -1;

    oldrow = get_tableRow(id_emp,tableEmployes);

    if(oldrow != ""){
        vector<string> row;
        vector<string> skills;
        vector<int> colleagues;
        string ligne,word;

        stringstream s(oldrow); 
        while (getline(s, word, ',')) {
            row.push_back(word);            //On récupère les colonnes
        } 
        
        string nom =  row[1];
        string prenom = row[2];
        string email = row[3];
        string code_postal = row[4];

        string skill;
        stringstream ss(row[5]);
        while (getline(ss, skill, ';')) {
            skills.push_back(skill);            //On récupère les compétences
        }

        code1 = jsk_create_profile(nom, prenom, email, code_postal, skills);
        
        if(code1 == SUCCESS)
        {
            id_created = get_lastID(tableJobseeker);

            if(row[6] != ""){
                string colleague;
                stringstream sc(row[6]);

                while (getline(sc, colleague, ';')) {
                    colleagues.push_back(stoi(colleague));            //On récupère les compétences
                }
                code2 = jsk_add_colleague(id_created, colleagues);
            }else{
                code2 = NOTHING_TO_DO;
            }

            vector<string> colleagueOnEnterprise = get_Allemploye_fromEnterprise(id_etp);
            if(colleagueOnEnterprise.size() > 0)
            {
                colleagues.clear();
                for(size_t k=0; k<colleagueOnEnterprise.size(); k++)
                {
                    row.clear();
                    stringstream sd(colleagueOnEnterprise[k]); 
                    while (getline(sd, word, ',')) {
                        row.push_back(word);            
                    }

                    colleagues.push_back(stoi(row[0]));        
                    
                }

                code3 = jsk_add_colleague(id_created, colleagues);

            }else{
                code3 =NOTHING_TO_DO;
            }

        }
        if(code1 == SUCCESS && (code2 == SUCCESS || code2 == NOTHING_TO_DO) && (code3 = SUCCESS || code3 == NOTHING_TO_DO)) code = SUCCESS;

        if(code == SUCCESS)
        {
            vector<int> listRow;

            listRow.push_back(id_emp);

            code = delete_list_of_row_from_table(listRow,tableEmployes);
        }


    }

    return code;
}

int emp_delete_profile(int id)
{
    int code = EXIT_WITH_ERROR;

    vector<int> tab_OneID;
    tab_OneID.push_back(id);
    
    code = delete_list_of_row_from_table(tab_OneID,tableEmployes);
    
    return code;
}
