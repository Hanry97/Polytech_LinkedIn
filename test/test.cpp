/*
 ===============================================
||  Ré-édition ::             Hanry Nzale      ||
 ===============================================
|| Dernière modification ::   28/04/2020       ||
 ===============================================
*/

#include <iostream>
#include <signal.h>
#include <stddef.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include "../lib/constante.h"
#include "../lib/fichier.h"
#include "../lib/extra3/compression.h"
#include "../lib/extra3/decompression.h"

using namespace std;

// Nombre total de tests exécutés. 
int tests_executes = 0;
// Pour chaque test qui réussi, cette variable sera incrémentée de 1.
// Le but est de la garder égale à test_executes.
int tests_reussis = 0;

#define STRINGIZE_(x) #x
#define STRINGIZE(x) STRINGIZE_(x)

// Incrémente le nombre de test exécutés de 1.
// Si le test réussi, incrémente le nombre de tests réussis de 1.
#define TEST(x) tests_executes += 1;    \
                if(x)                   \
                {                       \
                    tests_reussis += 1; \
                    cout << "[SUCCES] ";\
                }                       \
                else                    \
                {                       \
                    cout << "[ECHEC ] ";\
                }                       \
                cout << STRINGIZE(__FILE__) << ", " << STRINGIZE(__LINE__) << ": " << STRINGIZE(x) << endl;

// Fonction à executer lors d'une segmentation fault.
// On imprime les résultats obtenus jusqu'à lors et on arrête immédiatement le programme.
void segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
    cout << "[SEGFAULT]" << endl;
    cout << tests_reussis << " / " << tests_executes << endl;
    exit(tests_reussis - tests_executes);
}

int main()
{
    decompress_csv_files() ;
    
    // Mise en place de la fonction à exécuter lors d'une segmentation fault.
    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = segfault_sigaction;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &sa, NULL);

    //Test entreprise
    {
        string nom, code_postal,email;
        string pathEnterpriseTable = tableEntreprise;
        nom = "Polytech Nice";
        code_postal = "13509";
        email = "polytech@uni-nice.fr";

        TEST(etp_create_profile(nom,code_postal,email) == SUCCESS);
    }
    //Test poste
    {
        string pathPosteTable = tablePoste;
        string titre = "concepteur logiciel";
        vector<string> competences;
        int id_entreprise = get_lastID(tableEntreprise);

        competences.push_back("C");
        competences.push_back("C++");
        competences.push_back("Python");

        TEST(etp_create_profileOfPosition(titre,competences,id_entreprise) == SUCCESS);

        titre = "Admin systeme";
        competences.clear();
        competences.push_back("Linux");
        competences.push_back("Windows");

        TEST(etp_create_profileOfPosition(titre,competences,id_entreprise) == SUCCESS);

    }

    {
        //Suppresion du dernier poste publié par la dernière entreprise créée
        int id_etp = get_lastID(tableEntreprise);
        int id_poste = get_lastID(tablePoste);
        TEST(etp_delete_profileOfPosition(id_etp,id_poste) == SUCCESS);
    }

    {
        //Suppresion du profil de la dernière entreprise créée
        int id_etp2 = get_lastID(tableEntreprise);
        TEST(etp_delete_profile(id_etp2) == SUCCESS);
    }

    
    {
        string nom = "Didier";
        string prenom = "Franck";
        string email = "Franck@gmail.com";
        string code_postal = "13009";
        vector<string> competences;

        competences.push_back("Ruby");
        competences.push_back("C++");
        competences.push_back("React");
        competences.push_back("MySpecialSkill");

        TEST(jsk_create_profile(nom,prenom, email, code_postal, competences) == SUCCESS);   //L'un va transiter vers employé
        TEST(jsk_create_profile(nom,prenom, email, code_postal, competences) == SUCCESS);   //L'autre sera supprimé

        competences.clear();
        competences.push_back("Agile");
        competences.push_back("Java EE");
        competences.push_back("API rest");

        int id = get_lastID(tableJobseeker);

        TEST(jsk_add_skills(id,competences) == SUCCESS);

        vector<int> collegue;
        collegue.push_back(4);
        collegue.push_back(5);
        collegue.push_back(6);

        TEST(jsk_add_colleague(id,collegue) == SUCCESS);

        code_postal = "13005";

        TEST(jsk_update_code_postal(id,code_postal) == SUCCESS);

        int id_enterprise = get_lastID(tableEntreprise);

        TEST(jsk_profile_transition_to_employe(id,id_enterprise) == SUCCESS);

        

    }

    {
        vector<string> list_skill;
        vector <vector <string> > employes;
        vector <vector <string> > results;
        vector <string> employe;
        string code_postal = "#";

        int id = get_lastID(tableJobseeker);

        list_skill.push_back("MySpecialSkill");

        employe.push_back(to_string(id));
        employe.push_back("Didier");
        employe.push_back("Franck");
        employe.push_back("Franck@gmail.com");

        employes.push_back(employe);

        results = etp_searchToHire(list_skill,code_postal);
        TEST( results == employes);

        TEST(jsk_delete_profile(id) == SUCCESS);
    }

    {
        int id = get_lastID(tableEmployes);
        TEST(emp_delete_profile(id) == SUCCESS);
    }
    
    {
        string mdp = "DevCommeLesPros";
        string new_mdp = "HanryJp";

        TEST(create_password(1997,mdp,TAG_EMPLOYE) == SUCCESS);
        TEST(update_password(1997,new_mdp,mdp,TAG_EMPLOYE) == SUCCESS);
        TEST(password_existAndOk(1997,new_mdp,TAG_EMPLOYE) == true);
        TEST(delete_password(1997,TAG_EMPLOYE) == SUCCESS);

    }

    cout << tests_reussis << " / " << tests_executes << endl;
    compress_csv_files() ;
    return tests_reussis - tests_executes;
}
