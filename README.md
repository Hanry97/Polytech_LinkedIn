![](https://github.com/Hanry97/DevCommeLesPros-2020-Projet/workflows/Test%20master/badge.svg)

# POLYTECH LINKEDIN C++

Inspiré de LinkedIn, POLYTECH LINKEDIN C++ est un programme écrit en C++ permettant de mettre en relation des entreprises,
des employés et des chercheurs d'emploi.

# Table des matières

- [Généralités](#G%C3%A9n%C3%A9ralit%C3%A9)
- [Fonctionnalités](#Fonctionnalit%C3%A9s)
    - [Fonctionalités pour une entreprise](#fonctionalit%C3%A9s-pour-une-entreprise)
    - [Fonctionalités pour un chercheur d'emploi](#fonctionalit%C3%A9s-pour-un-chercheur-demploi)
    - [Fonctionalité pour un employé](#fonctionalit%C3%A9-pour-un-employ%C3%A9)
- [Bugs](#Bugs)
    
# Généralités

Le programme s'execute en console en executant la commande 'make execute_app' depuis la racine du projet.
L'utilisateur est appellé à saisir des numéros correspondants à des options. Au lancement, deux choix sont proposés : 
Inscription et Connexion.

   - Connexion : l'utilisateur saisie sont adresse email et son mot de passe. Notons que la casse est prise en compte (les 
     majuscules et les miniuscules sont différenciées) et le mot de passe est saisis en clair.

   - Inscription : l'utilisateur choisit le type de profil et saisit les informations demandées. Une fois l'inscription         
     terminée, il est redirigé vers la page deconnexion.

Après chaque opération, l'utilisateur est généralement invité à saisir le caractère 'q' pour revenir au menu. De plus, depuis 
chaque menu, il a la possibilité de quitter 'proprement' le programme grace à l'option 'quitter'.


# Fonctionnalités

On distingue trois profils d'utilisateur du programme et chacun avec des besoins propres.
Les entreprises, les chercheurs d'emploi et les employés.

## Fonctionalités pour une entreprise

Une entreprise annonce des postes à pourvoir en spécifiant les compétences requises.
Elle peut aussi rechercher parmi les chercheurs d'emploi ceux qui correspondent à ses besoins.
Une entreprise:
- Crée un profil en saisissant : Nom,Code postal et Adresse mail. 
- Supprime son profil.
- Publie une offre d'emploi en précisant Titre et Compétences requises.
- Retire une ou plusieurs offres d'emploi (la liste des offres est au préalabe affichée).
- Rechercher parmi les chercheurs d'emploi pour des profils qui correspondent à un poste à pourvoir:
    - Par compétences (l'utilisateur saisit succéssivement des compétences et saisit 'q' pour terminer)
    - Par compétences et code postal.
  Pour ignorer le critère code postal, il suffit de saisir '#' lorsque le code postal est demandé.  
    
## Fonctionalités pour un chercheur d'emploi

Pour un chercheur d'emploi, un bon moyen d'entrer en contact avec une entreprise qui nous intéresse est grâce à une personne que l'on connaît déjà (un(e) ancien(ne) collègue de travail) qui travaille présentement pour cette entreprise.

Lorsqu'un checheur d'emploi est embauché, son profil transitionne vers «employé».

- [ ] Créer un profil
    - [ ] Nom
    - [ ] Prénom
    - [ ] Adresse mail
    - [ ] Code postal
    - [ ] Compétences
    - [ ] Ancien(ne)s collègues de travail parmi les personne employés
- [ ] Modifier un profil
    - [ ] Ajouter des compétences
    - [ ] Ajouter un(e) ancien(ne) collègue de travail
    - [ ] Modifier le code postal
- [ ] Transitionner le profil de «chercheur d'emploi» à un profil «employé»
- [ ] Supprimer un profil
- [ ] Rechercher parmi les les postes à pourvoir qui correspondent à son profil
    - [ ] Recherche par compétences
    - [ ] Recherche par compétences et code postal
    - [ ] Résultats
        - [ ] Titre du poste
        - [ ] Nom de l'entreprise
        - [ ] Adresse mail de l'entreprise
        - [ ] Code postal de l'entreprise
- [ ] Rechercher parmi les anciens collègues
    - [ ] Recherche par entreprise (retoune les ancien(ne)s collègues employés à l'entreprise)
    - [ ] Recherche par compétences (pour les compétences du chercheur d'emploi, retourne les ancien(ne)s collègues employés aux entreprises qui recherchent ces compétences)
    - [ ] Résultats
        - [ ] Nom du (de la) collègue
        - [ ] Prénom du (de la) collègue
        - [ ] Adresse mail du (de la) collègue

## Fonctionalités pour un employé

C'est bien d'être à l'emploi mais pour diverses raisons il peut arriver qu'on veuille quand même s'informer sur les postes à pourvoir pour trouver un travail plus rémunérateur, plus près de chez soi, etc.

Lorsqu'un un employé quitte ou perd son emploi et est en recherche d'emploi, son profil transitionne vers «checheur d'emploi».

- [ ] Créer un profil
    - [ ] Nom
    - [ ] Prénom
    - [ ] Adresse mail
    - [ ] Code postal
    - [ ] Compétences
    - [ ] Ancien(ne)s collègues de travail parmi les personne employés
    - [ ] Entreprise
- [ ] Modifier un profil
    - [ ] Ajouter des compétences
    - [ ] Ajouter un(e) ancien(ne) collègue de travail
    - [ ] Modifier le code postal
    - [ ] Modifier l'entreprise
- [ ] Transitionner le profil «employé» vers «chercheur d'emploi»
    - [ ] Les employé(e)s de l'entreprise quittée s'ajoutent automatiquement à liste des ancien(ne)s collègues de travail
- [ ] Supprimer le profil
- [ ] Rechercher parmi les les postes à pourvoir qui correspondent au profil de l'employé
    - [ ] Recherche par compétences
    - [ ] Recherche par compétences et code postal
    - [ ] Résultats
        - [ ] Titre du poste
        - [ ] Nom de l'entreprise
        - [ ] Adresse mail de l'entreprise
        - [ ] Code postal de l'entreprise
- [ ] Rechercher parmi les anciens collègues
    - [ ] Recherche par entreprise (retoune les ancien(ne)s collègues employés à l'entreprise)
    - [ ] Recherche par compétences (pour les compétences du chercheur d'emploi, retourne les ancien(ne)s collègues employés aux entreprises qui recherchent ces compétences)
    - [ ] Résultats
        - [ ] Nom du (de la) collègue
        - [ ] Prénom du (de la) collègue
        - [ ] Adresse mail du (de la) collègue

# Bugs
