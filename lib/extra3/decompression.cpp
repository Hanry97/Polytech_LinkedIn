#include "decompression.h"
using namespace std ;




/*==============================
                              ||
	FONCTIONS PRINCIPALES    ||
                              ||
==============================*/

void decompress_csv_files()
{
	vector<string> compressedFiles = { "Entreprise", "Employes", "Jobseeker", "Poste", "Password" } ;
	string compressedFile ;
	unsigned int i ;

	for( i=0 ; i<compressedFiles.size() ; i++ ) 
	{
		compressedFile = "database/" + compressedFiles[i] ;
		decompress( compressedFile ) ;
		remove( compressedFile.c_str() ) ;
	}
}



void decompress( string const& compressed )
{
	ifstream fluxEntrant( compressed ) ;
	queue<char> file ;
	Tree tree ;
	
	if( ! fluxEntrant ) { cout << "\n Erreur ouverture " << compressed << endl ; return ; }
	tree = decode_tree( fluxEntrant ) ;											// On décode l'arbre 'tree' se trouvant au début du fichier compressé
	file = codedText_to_file( fluxEntrant ) ; 										// Pour chaque caractère c se trouvant dans le fichier compressé, on enfile dans 'file', l'ecriture binaire (sur 8 bits) du code ascii numerique de c 
	write_text( file, tree, compressed ) ;											// A l'aide de 'tree' et de 'file', on recrée le fichier original
	
	fluxEntrant.close() ;
}




/*=================
                 ||
	ÉTAPE 1     ||
                 ||
=================*/

Tree decode_tree( ifstream& fluxEntrant )
{
	char c ;
	fluxEntrant.get(c) ;

	if( c == '|' ) 
	{
		Tree treeg = decode_tree( fluxEntrant ) ;
		Tree treed = decode_tree( fluxEntrant ) ;
		return Tree( '-', 0 , treeg, treed ) ;
	}
	else return Tree( c, 0 ) ;
}




/*=================
                 ||
	ÉTAPE 2     ||
                 ||
=================*/

queue<char> codedText_to_file( ifstream& fluxEntrant )
{
	queue<char> file ;
	string binaryString ;
	char c, tab_char[4] ;
	int i, l ;
	unsigned int j ;
	bool separatorFound = false ;

	while( fluxEntrant.get(tab_char[0]) && (!separatorFound) ) 
	{	
		if( tab_char[0] == 's' )												// ON REGARDE SI CE N'EST PAS LE SYMBOLE DE SEPARATION
		{
			fluxEntrant.get( tab_char[1] ) ;
			if( tab_char[1] == 'e' )
			{
				fluxEntrant.get( tab_char[2] ) ;
				if( tab_char[2] == 'p' )
				{
					fluxEntrant.get( tab_char[3] ) ;
					if( tab_char[3] == 'a' )
					{
						separatorFound = true ;
						l = -1 ;
					}
					else l = 3 ;
				}
				else l = 2 ;
			}
			else l = 1 ;
		}
		else l = 0 ;

		for( i=0 ; i<=l ; i++ )												// SI CE N'EST PAS LE SEPARATEUR, ALORS ON MET LE CODE DES CARACTÈRES TROUVÉS DANS LA FILE
		{
			binaryString = char_to_binaryCode( (unsigned char)tab_char[i] ) ;
			for( j=0 ; j<binaryString.size() ; j++ ) file.push( binaryString[j] ) ;			
		}
	}

	if( separatorFound )													// ON ENFILE LE CODE SE TROUVANT APRÈS LE SÉPARATEUR
	{
		file.push( tab_char[0] ) ;
		while( fluxEntrant.get(c) ) file.push(c) ;
	}

	return file ;
}



string char_to_binaryCode( unsigned char const& c )
{
	int i, n = (int)c ;
	string s = "12345678" ;

	for( i=7 ; i>=0 ; i-- )
	{
		if( n%2 == 0 ) s[i] = '0' ;
		else s[i] = '1' ;
		n /= 2 ;
	}

	return s ;
}




/*=================
                 ||
	ÉTAPE 3     ||
                 ||
=================*/

void write_text( queue<char>& file, Tree const& tree, string const& compressed )
{	
	ofstream fluxSortant( compressed+".csv" ) ;
	while( !file.empty() ) write_a_character( file, tree, fluxSortant ) ;
	fluxSortant.close() ;
}



void write_a_character( queue<char>& file, Tree const& tree, ofstream& fluxSortant )
{
	if( file.empty() ) return ;
	if( tree.est_feuille() ) fluxSortant << tree.get_val() ;
	else
	{
		char c = file.front() ;
		file.pop() ;
		if( c == '0' ) return write_a_character( file, tree.fg(), fluxSortant ) ;
		else return write_a_character( file, tree.fd(), fluxSortant ) ;
	}
}