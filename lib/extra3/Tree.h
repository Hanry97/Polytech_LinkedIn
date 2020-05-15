#ifndef __TREE__
#define __TREE__

#include <iostream>
#include <queue>



/*==================
                  ||
	NODE         ||
	             ||
==================*/

class Node
{
	friend class Tree ;
	
	public:
		inline Node() ;
		inline Node( char const& val, int const& occu, Node* const& fg=nullptr, Node* const& fd=nullptr ) ;		
		// inline ~Node() ;																			// Choix: Ne rien faire
		inline void detruire_node() ;																	// Choix: Detruit TOUS les noeuds fils ( utile pour ~Tree )
		inline bool est_feuille() const ;


	private:
		char _val ;
		int _occu ;
		Node* _fg ;
		Node* _fd ;
		inline void parcours_prof() const ;
		inline void parcours_larg() const ;
		inline void parcours_prof_feuille() const ;
		inline void parcours_larg_feuille() const ;
} ;




/*==================
                  ||
	TREE         ||
	             ||
==================*/

class Tree
{
	public:
		inline Tree() ;
		inline Tree( Node* racine ) ;
		inline Tree( char const& val, int const& occu ) ;
		inline Tree( char const& val, int const& occu, Tree const& fg, Tree const& fd ) ;
		inline ~Tree() ;
		
		inline bool est_vide() const ;
		inline bool est_feuille() const ;
		inline int get_occu() const ;
		inline char get_val() const ;
		inline Tree fg() const ;
		inline Tree fd() const ;
		inline void detruire_tree() ;
		

		inline void parcours_prof() const ;
		inline void parcours_larg() const ;
		inline void parcours_prof_feuille() const ;
		inline void parcours_larg_feuille() const ;		

	private:
		Node* _racine ;
} ;






/*============================
	                       ||
	IMPLEMENTATION NODE    ||
	                       ||
============================*/

/*==========================================
	NODE: CONSTRUCTEURS + DESTRUCTEUR    ||
==========================================*/

inline Node::Node() : _fg(nullptr), _fd(nullptr) {}


inline Node::Node( char const& val, int const& occu, Node* const& fg, Node* const& fd ) : _val(val), _occu(occu), _fg(fg), _fd(fd) {}


/*=====================
	NODE: AUTRES    ||
=====================*/

inline void Node::detruire_node()
{
	if( _fg != nullptr )  {
		_fg->detruire_node() ;
		delete _fg ;
	}
	if( _fd != nullptr ) {
		_fd->detruire_node() ;
		delete _fd ;
	} 
}


inline bool Node::est_feuille() const
{
	return( _fg==nullptr && _fd==nullptr ) ;
}


inline void Node::parcours_prof() const
{
	char c = _val ;
	if( c == ' ' ) c = '_' ;
	if( c == '\n' ) c = '-' ;	
	
	std::cout << c << " " ;	
	if( _fg != nullptr ) _fg->parcours_prof() ;
	if( _fd != nullptr ) _fd->parcours_prof() ;
}


inline void Node::parcours_larg() const
{
	std::queue<Node> file ;
	Node courant ;
	char c ;

	std::cout << "larg ---> " ;

	file.push(*this) ;	
	while( !file.empty() )
	{
		courant = file.front() ;
		
		c = courant._val ;
		if( c == ' ' ) c = '_' ;
		if( c == '\n' ) c = '-' ;
		std::cout << c << " " ;
		
		if( courant._fg != nullptr ) file.push( *(courant._fg) ) ;
		if( courant._fd != nullptr ) file.push( *(courant._fd) ) ;
		file.pop() ;
	}
}


inline void Node::parcours_prof_feuille() const
{
	if( est_feuille() ) std::cout << " ( " << _val << " , " << _occu << " ) " ;
	if( _fg != nullptr ) _fg->parcours_prof_feuille() ;
	if( _fd != nullptr ) _fd->parcours_prof_feuille() ;
}


inline void Node::parcours_larg_feuille() const
{
	std::queue<Node> file ;
	Node courant ;

	file.push(*this) ;	
	while( !file.empty() )
	{
		courant = file.front() ;
		if( courant.est_feuille() ) std::cout << " ( " << courant._val << " , " << courant._occu << " ) " ;	
		if( courant._fg != nullptr ) file.push( *(courant._fg) ) ;
		if( courant._fd != nullptr ) file.push( *(courant._fd) ) ;
		file.pop() ;
	}
}


/*=========================================
	TREE: CONSTRUCTEURS + DESTRUCTEUR   ||
=========================================*/

inline Tree::Tree() : _racine(nullptr) {}

inline Tree::Tree( Node* racine ) : _racine(racine) {}

inline Tree::Tree( char const& val, int const& occu )
{
	_racine = new Node( val, occu ) ;
}


inline Tree::Tree( char const& val, int const& occu, Tree const& fg, Tree const& fd )
{
	_racine = new Node( val, occu, fg._racine, fd._racine ) ;
}


inline Tree::~Tree()
{
	// if( _racine != nullptr ) _racine->detruire_node() ;
}


/*====================
	TREE: AUTRES   ||
====================*/

inline bool Tree::est_vide() const
{
	return( _racine==nullptr ) ;
}


inline bool Tree::est_feuille() const
{
	return( _racine->est_feuille() ) ;
}


inline int Tree::get_occu() const
{
	return _racine->_occu ;
}


inline char Tree::get_val() const
{
	return _racine->_val ;
}


inline Tree Tree::fg() const
{
	return Tree( _racine->_fg ) ;
}


inline Tree Tree::fd() const
{
	return Tree( _racine->_fd ) ;
}


inline void Tree::detruire_tree()
{
	_racine->detruire_node() ;
}


inline void Tree::parcours_prof() const
{
	std::cout << "\n\n" ;
	_racine->parcours_prof() ;
	std::cout << "\n\n" ;
}


inline void Tree::parcours_larg() const
{
	std::cout << "\n\n" ;
	_racine->parcours_larg() ;
	std::cout << "\n\n" ;
}


inline void Tree::parcours_prof_feuille() const
{
	std::cout << "\n\n" ;
	_racine->parcours_prof_feuille() ;
	std::cout << "\n\n" ;
}


inline void Tree::parcours_larg_feuille() const
{
	std::cout << "\n\n" ;
	_racine->parcours_larg_feuille() ;
	std::cout << "\n\n" ;
}



#endif