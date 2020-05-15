#include "compression.h"
using namespace std ;




/*===============================
                               ||
	FONCTIONS PRINCIPALES     ||
                               ||
===============================*/

void compress_csv_files()
{
	vector<string> csvFiles = { "Entreprise.csv", "Employes.csv", "Jobseeker.csv", "Poste.csv", "Password.csv" } ;
	string csvFile ;
	unsigned int i ;

	for( i=0 ; i<csvFiles.size() ; i++ ) 
	{
		csvFile = "database/" + csvFiles[i] ;
		compress( csvFile ) ;
		remove( csvFile.c_str() ) ;
	}
}



void compress( string const& notCompressed )
{
	ofstream fluxSortant( notCompressed.substr( 0, notCompressed.size()-4 ) ) ;	// le nom du fichier compressé sera le nom du fichier original auquel on enlève son extension
	vector<pair<char,int>> char_et_occu ;
	Tree tree ;

	char_et_occu = list_of_char_and_occu( notCompressed ) ;					// Deterrmination de la frequence de chaque caractère du fichier
	tree = create_Huffman_tree( char_et_occu ) ;								// Creation de l'arbre de Huffman
	code_tree( tree, fluxSortant ) ;										// Ecriture de l'arbre sur le fichier compressé
	code_text( tree, fluxSortant, notCompressed ) ;							// Ecriture du texte sur le fichier compréssé

	fluxSortant.close() ;
	tree.detruire_tree() ;
}





/*=================
                 ||
	ÉTAPE 1     ||
                 ||
=================*/

vector<pair<char,int>> list_of_char_and_occu( string const& notCompressed )
{
	map<char,int> map0 ;
	char c ;

	ifstream fluxEntrant( notCompressed ) ;
	if( !fluxEntrant ) { cout << "\n Erreur ouverture " << notCompressed << endl ; }
	while( fluxEntrant.get(c) ) map0[c]++ ;
	fluxEntrant.close() ;
	
	return list_occurence( map0 ) ;
}



vector<pair<char,int>> list_occurence( map<char,int>& map0 )
{
	map<char,int>::iterator it ;
	vector<pair<char,int>> char_et_occu ;
	pair<char,int> pair0 ;
	unsigned int i ;

	for( it=map0.begin() ; it!=map0.end() ; it++ )
	{	
		pair0.first = it->first ;
		pair0.second = it->second ;

		i = 0 ;
		while(  (i < char_et_occu.size())  &&  (pair0.second < char_et_occu[i].second)  ) i++ ;
		
		char_et_occu.insert( i+char_et_occu.begin(), pair0 ) ;	
	}

	return char_et_occu ;
}





/*=================
                 ||
	ÉTAPE 2     ||
                 ||
=================*/

Tree create_Huffman_tree( vector<pair<char,int>> const& char_et_occu )
{
	map<char,int> list ;
	vector<Tree> listTree ;	// Pile de priorite
	Tree tree1, tree2 ;
	unsigned int i, occu ;
	char c ;

	for( i=0 ; i<char_et_occu.size() ; i++ )
	{
		c = char_et_occu[i].first ;
		occu = char_et_occu[i].second ;
		listTree.push_back( Tree(c,occu) ) ;
	}

	while( listTree.size() > 1 )
	{	
		tree1 = listTree.back() ;
		listTree.pop_back() ;
		tree2 = listTree.back() ;
		listTree.pop_back() ;
		occu = tree1.get_occu() + tree2.get_occu() ;
		add_in_order( Tree('-',occu,tree1,tree2), listTree ) ;
	}
	
	return listTree[0] ;
}



void add_in_order( Tree const& tree, vector<Tree>& listTree )
{
	unsigned int i = 0 ;
	while( (i<listTree.size())  &&  (tree.get_occu()<listTree[i].get_occu()) ) i++ ;
	listTree.insert( i+listTree.begin(), tree ) ;
}





/*=================
                 ||
	ÉTAPE 3     ||
                 ||
=================*/

void code_tree( Tree const& tree, ofstream& fluxSortant )
{
	char c ;
	if( tree.est_feuille() ) 
	{
		c = tree.get_val() ;
		fluxSortant << c ;
	} 
	else
	{
		fluxSortant << '|' ;
		code_tree( tree.fg(), fluxSortant ) ;
		code_tree( tree.fd(), fluxSortant ) ;
	}
}





/*=================
                 ||
	ÉTAPE 4     ||
                 ||
=================*/

void code_text( Tree const& tree, ofstream& fluxSortant, string const& notCompressed )
{
	map<char,string> coding ;
	queue<char> file ;

	coding_characters( tree, coding, "" ) ; 		// on détermine le code de chaque caractère
	file = text_to_file( coding, notCompressed ) ;	// pour chaque caractère rencontrés ds le fichiers, on enfile son code
	write_coded_text( file, fluxSortant ) ;			// à l'aide de la file, on ecrit le texte fichier compressé
}



void coding_characters( Tree tree, map<char,string> &coding, string code )
{
	if( tree.est_feuille() ) coding[ tree.get_val() ] = code ;
	else
	{
		coding_characters( tree.fg(), coding, code+"0" ) ;
		coding_characters( tree.fd(), coding, code+"1" ) ;
	}
}



queue<char> text_to_file( map<char,string>& coding, string const& notCompressed )
{
	queue<char> file ;
	ifstream fluxEntrant( notCompressed ) ;
	string code ;
	unsigned int i ;
	char c ;	
	if( !fluxEntrant ) cout << "\n Erreur ouverture " << notCompressed << endl ;	
	
	while( fluxEntrant.get(c) )
	{
		code = coding[c] ;
		for( i=0 ; i<code.size() ; i++ ) file.push( code[i] ) ;
	}
	code = coding[c] ;
	for( i=0 ; i<code.size() ; i++ ) file.push( code[i] ) ;
	
	fluxEntrant.close() ;
	return file ;
}



void write_coded_text( queue<char>& file, ofstream& fluxSortant )
{
	string s ;
	int i, j ;
	
	i = 0 ;
	while( ! file.empty() )
	{
		s[i] = file.front() ;
		i++ ;
		if( i==8 ) 
		{
			fluxSortant << binaryCode_to_char(s) ;
			i = 0 ;
		}
		file.pop() ;
	}
	
	fluxSortant << "sepa" ;							// On met un séparateur ( "sepa" )
	for( j=0 ; j<i ; j++ ) fluxSortant << s[j] ;			// Et on écris les codes restants ( le dernier groupe n'a possiblement pas pu être complété en un groupe de 8 caractères )
}



unsigned char binaryCode_to_char( string const& s )
{
	int j, res_int=0, puiss2=1 ;

	for( j=7 ; j>=0 ; j-- )
	{
		if( s[j] == '1' ) res_int += puiss2 ;
		puiss2 *= 2 ;
	}

	return (unsigned char)res_int ;
}