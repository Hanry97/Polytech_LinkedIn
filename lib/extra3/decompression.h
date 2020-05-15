#ifndef __DECOMPRESSION__
#define __DECOMPRESSION__

#include "Tree.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <deque>
#include <string>



/*-------------------------------------------------------------------------------------------------
                                                                                                  |
ÉTAPES:                                                                                           |
                                                                                                  |
	1. On décode l'arbre 'tree' se trouvant au début du fichier compressé                        |
                                                                                                  |
	2. Pour chaque caractère c se trouvant dans le fichier compressé,                            |
        on enfile dans 'file', l'ecriture binaire (sur 8 bits) du code ascii numerique de c       |
                                                                                                  |
	3. A l'aide de 'tree' et de 'file', on recrée le fichier original                            |
                                                                                                  |
-------------------------------------------------------------------------------------------------*/



/*=======================
	MAIN FONCTION     ||
=======================*/

// Decompresse tous les fichiers csv compressés
void decompress_csv_files() ;

// Decompresse un fichier
void decompress( std::string const& compressed ) ;


/*=================
	ÉTAPE 1     ||
=================*/

// Decode l'arbre inscrit au début du fichier compressé
Tree decode_tree( std::ifstream& fluxEntrant ) ;


/*=================
	ÉTAPE 2     ||
=================*/

// Renvoie une file contenant char_to_binaryCode(c), pour chaque caractère c se tranvant dans le fichier compressé
// ( la file contient donc des 0 et des 1 qui correspondent aux codages Huffman des caractères du fichiers de départs )
std::queue<char> codedText_to_file( std::ifstream& fluxEntrant ) ;

// Soit n le code ascii numerique de c
// Renvoie l'ecriture binaire (sur 8 bits) de n 
std::string char_to_binaryCode( unsigned char const& c ) ;


/*=================
	ÉTAPE 3     ||
=================*/

// Ecris le texte sur le futur fichier non compressé
void write_text( std::queue<char>& file, Tree const& tree, std::string const& compressed ) ;

// Ecris un caractère sur le futur fichier non compressé
void write_a_character( std::queue<char>& file, Tree const& tree, std::ofstream& fluxSortant ) ;


#endif