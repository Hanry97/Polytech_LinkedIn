#include <iostream>
#include <signal.h>
#include <stddef.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include "../lib/constante.h"
#include "../lib/fichier.h"

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
    // Mise en place de la fonction à exécuter lors d'une segmentation fault.
    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = segfault_sigaction;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &sa, NULL);

    {
        string nom, code_postal,email;
        string pathEnterpriseTable = tableEntreprise;
        nom = "Polytech Nice";
        code_postal = "13509";
        email = "polytech@uni-nice.fr";

        TEST(etp_create_profile(nom,code_postal,email) == SUCCESS);
    }

    {
        string pathPosteTable = tablePoste;
        string titre = "concepteur logiciel";
        string competences = "C;C++;Python";
        int id_entreprise = get_lastID(tableEntreprise);

        TEST(etp_create_profileOfPosition(titre,competences,id_entreprise) == SUCCESS);

        titre = "Admin systeme";
        competences = "Linux;Windows";

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
        vector<string> list_skill;
        vector <vector <string> > employes;
        vector <vector <string> > results;
        vector <string> employe;
        string code_postal = "#";

        list_skill.push_back("Ruby");
        list_skill.push_back("Python");
        list_skill.push_back("C");

        employe.push_back("1");
        employe.push_back("nzale");
        employe.push_back("hanry");
        employe.push_back("hanry@gmail.com");

        employes.push_back(employe);

        results = etp_searchToHire(list_skill,code_postal);
        TEST( results == employes);
    }

    cout << tests_reussis << " / " << tests_executes << endl;
    return tests_reussis - tests_executes;
}
