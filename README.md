![](https://github.com/Hanry97/DevCommeLesPros-2020-Projet/workflows/Test%20master/badge.svg)

# POLYTECH LINKEDIN C++

Inspiré de LinkedIn, POLYTECH LINKEDIN C++ est un programme écrit en C++ permettant de mettre en relation des entreprises,
des employés et des chercheurs d'emploi.

# Table des matières

- [Généralités](#G%C3%A9n%C3%A9ralit%C3%A9)
- [Fonctionnalités]#Fonctionnalit%C3%A9s)
    - [Fonctionalités pour une entreprise](#fonctionalit%C3%A9s-pour-une-entreprise)
    - [Fonctionalités pour un chercheur d'emploi](#fonctionalit%C3%A9s-pour-un-chercheur-demploi)
    - [Fonctionalité pour un employé](#fonctionalit%C3%A9-pour-un-employ%C3%A9)
- [Bugs](#Bugs)
    
# Généralités

Le site [LinkedIn](https://linkedin.com) est un réseau social servant de rapprochement et de moyen de contact entre des entreprises, des demandeurs d'emploi et d'anciens collègues travail.
Vous avez à créer un programme qui simule cette plateforme.

Cette application n'est pas un site web.
C'est un programme lancé à l'invite de commandes qui utilisent des fichers locaux comme base de données.

# Fonctionnalités

Sur cette platforme, on distingue trois profils d'utilisateur avec des besoins propres.
Les entreprises, les chercheurs d'emploi et les employés.

## Fonctionalités pour une entreprise

Une entreprise annonce des postes à pourvoir, spécifiant les compétences requises.
Elle peut aussi rechercher parmi les chercheurs d'emploi ceux qui correspondent à ses besoins.

- [ ] Créer un profil
    - [ ] Nom
    - [ ] Code postal
    - [ ] Adresse mail
- [ ] Supprimer un profil
    - [ ] Supprime automatiquement les postes à pourvoir existant
- [ ] Créer le profil d'un poste à pourvoir
    - [ ] Titre
    - [ ] Compétences requises
- [ ] Supprimer le profil d'un poste pourvu
- [ ] Rechercher parmi les chercheurs d'emploi pour des profils qui correspondent à un poste à pourvoir
    - [ ] Recherche par compétences
    - [ ] Recherche par compétences et code postal
    - [ ] Résultats
        - [ ] Nom
        - [ ] Prénom
        - [ ] Adresse mail

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
