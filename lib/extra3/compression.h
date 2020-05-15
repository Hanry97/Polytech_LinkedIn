#ifndef __COMPRESSION__
#define __COMPRESSION__

#include "Tree.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <deque>
#include <string>



/*----------------------------------------------------------------------
                                                                       |
ÉTAPES:                                                                |
                                                                       |
	1. On détermine la fréquence de chaque caractère du fichier         |
                                                                       |
	2. On crée l'arbre de Huffman                                       |
                                                                       |
	3. On écris l'arbre au début du futur fichier compréssé             |
                                                                       |
	4. On écris le texte à la suite                                     |
                                                                       |
----------------------------------------------------------------------*/



/*============================
	FONCTION PRINCIPALE    ||
============================*/

// Compresse tous les fichiers csv
void compress_csv_files() ;

// Compresse un fichier
void compress( std::string const& notCompressed ) ;


/*===============
	ÉTAPE 1   ||
===============*/

// Renvoie la liste des caracères présent dans le fichier 'notCompressed'
// La liste renvoyée est triée par ordre croissant de fréquence
std::vector< std::pair<char,int> > list_of_char_and_occu( std::string const& notCompressed ) ;

// map0 a pour clé des caractères et pour valeurs leur nombre d'occurence
// Renvoie la liste des caractères triès par ordre decroissant d'occurence
std::vector< std::pair<char,int> > list_occurence( std::map<char,int>& map0 ) ;


/*===============
	ÉTAPE 2   ||
===============*/

// 'char_et_occu' contient tous les caractères et leur fréquence
// Renvoie l'arbre de Huffman
Tree create_Huffman_tree( std::vector<std::pair<char,int>> const& char_et_occu ) ;

// Ajoute 'tree' dans 'listTree' de manière à ce que 'listTree' reste triè par ordre decroissant d'occurence
void add_in_order( Tree const& tree, std::vector<Tree>& listTree ) ;


/*===============
	ÉTAPE 3   ||
===============*/

// Ecris l'arbre d'Huffman sur le fichier compressé
void code_tree( Tree const& tree, std::ofstream& fluxSortant ) ;


/*===============
	ÉTAPE 4   ||
===============*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------
1. On determine le code de Huffman de chaque caractère                                                                                                   |
2. Pour chaque caractère rencontrée dans le fichier, on enfile son code de Huffman dans 'file' ( la file est donc une succession de 0 et de 1 )          |
3. - Dans la 'file', on prend les caractères 8 par 8                                                                                                     |
   - Ces groupes de 8 peuvent être associés à un nombre binaires de 0 à 255                                                                              |
   - Par consequent, ces groupes de 8 peuvent être associés à un caractère                                                                               |
   - C'est ce caractère qu'on écrit dans le fichier compressé                                                                                            |
   - ( A la fin de la file, il peut rester un groupe incomplet ( ie un groupe qui n'a pas pu se completer avec 8 caractères ) )                          |
   - ( On met donc ce groupe restant directement dans le fichier )                                                                                       |
--------------------------------------------------------------------------------------------------------------------------------------------------------*/

// Ecris le texte sur le fichier compressé
void code_text( Tree const& tree, std::ofstream& fluxSortant, std::string const& notCompressed ) ;

// Etape 4.1
// Remplis 'codage' de manière à ce que pour tout caractère c, codage[c] = code_Huffman(c)
void coding_characters( Tree tree, std::map<char,std::string> &codage, std::string code ) ;

// Etape 4.2
// Renvoie une file constitué du code de chaque caractère rencontrés dans le fichier
std::queue<char> text_to_file( std::map<char,std::string>& coding, std::string const& notCompressed ) ;

// Etape 4.3
// Ecris le texte sur le fichier compressé
void write_coded_text( std::queue<char>& file, std::ofstream& fluxSortant ) ;

// s représente un nombre binaire sur 8 bits qu'on note n
// Renvoie le caractère ascii représenté par n
unsigned char binaryCode_to_char( std::string const& s ) ;



#endif