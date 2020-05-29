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
- [Bugs et manipulations](#Bugs-et-manipulations)
    
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

Un chercheur d'emploi entre en contact avec une entreprise est grâce à une personne qu'il connaît déjà (un(e) ancien(ne) collègue de travail) qui travaille présentement pour cette entreprise.

Lorsqu'un checheur d'emploi est embauché, son profil passe de demandeur d'emploi vers «employé».
Le chercheur d'emploi :
- Crée un profil en saisissant : Nom, Prénom, Adresse mail, Code postal, Compétences.
- Modifie son profil :
    - Ajoute des compétences.
    - Ajoute un(e) ancien(ne) collègue de travail
    - Modifie son code postal.
- Met à jour son statut («chercheur d'emploi» vers «employé»).
- Supprime son profil.
- Recherche parmi les postes à pourvoir qui correspondent à son profil :
    - Par compétences (il saisit succéssivement des compétences et saisit 'q' pour terminer)
    - Par compétences et code postal.
  Pour ignorer le critère code postal, il suffit de saisir '#' lorsque le code postal est demandé.  

- Recherche parmi les anciens collègues :
    - Par entreprise (retoune les ancien(ne)s collègues employés à l'entreprise)
    - Par compétences (pour les compétences du chercheur d'emploi, retourne les ancien(ne)s collègues employés aux entreprises qui recherchent ces compétences)
    
    
## Fonctionalités pour un employé

Bien qu'étant dans une entreprise, il peut arriver qu'un employé veuille quand même s'informer sur les postes à pourvoir au 
sein d'autre entreprises.
De plus, lorsqu'un un employé quitte ou perd son emploi et est en recherche d'emploi, son profil transitionne vers «checheur 
d'emploi».
L'employé :
- Crée un profil en saisissant : Nom, Prénom, Adresse mail, Code postal, Compétences, Entreprise (la liste des entreprises est au préalable affichée).
- Modifie son profil :
    - Ajoute des compétences.
    - Ajoute un(e) ancien(ne) collègue de travail.
    - Modifie son code postal.
- Met à jour son statut («employé» vers «chercheur d'emploi»)
    - De plus, les employé(e)s de l'entreprise quittée s'ajoutent automatiquement à liste des ancien(ne)s collègues de travail.
- Supprime son profil.
- Recherche parmi les postes à pourvoir ceux qui correspondent à son profil :
    - Par compétences.
    - Par compétences et code postal
      Pour ignorer le critère code postal, il suffit de saisir '#' lorsque le code postal est demandé.  

- Recherche parmi les anciens collègues :
    - Par entreprise (retoune les ancien(ne)s collègues employés à l'entreprise)
    - Par compétences (pour les compétences du chercheur d'emploi, retourne les ancien(ne)s collègues employés aux entreprises qui recherchent ces compétences).


# Bugs et manipulations

- Mauvaise saisie : saisir autre chose que des chiffres dans les options des menus génère un dysfonctionnement du programme (manipulation à éviter).
- Il n'y a pas de message d'erreur lorsque l'email et le mot de passe sont incorrectes.
- On ne peut pas abandonner la saisie d'un formulaire sans l'avoir terminer et valider.
-La base de données est décompressée au lancement du programme et compressée lorsque l'utilisateur quitte 'proprement' le programme.
 Aussi, la base de données n'est pas compressée si le programme n'est pas quitté depuis le menu principale.
 - Il n'y a pas de vérification d'unicité du mot de passe ou de l'adresse email.
 - Pour éviter les problèmes de compression de la fichiers de données il est recommander de quitter le programme en utilisant l'option 'Quitter' proposée dans les différents menus.
