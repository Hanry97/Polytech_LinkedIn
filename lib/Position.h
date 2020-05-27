/*==============================
                              ||
	LAST MODIFICATION:        ||
	DATE: 03/04/2020          ||
	AUTHOR: Mihary R.         ||
                              ||
==============================*/

//Classe Position, décrit l'objet Position qui
//repésente un poste mis à disposition par une entreprise

#ifndef __POSITION__
#define __POSITION__
#include <vector>
#include <string>

class Position
{
	public:
		
		Position() ;		
		Position(const std::string & title, const std::vector<std::string> & skills, const int id_entreprise);
		~Position();

		int getId() const { return _id; };
		std::string getTitre() const { return _titre;};
		std::vector<std::string> getSkills() const { return _skills;};
		int getEntrepriseId() const { return _id_entreprise;};

		void setId(int & id) { _id = id;};
		void setTitre(std::string & titre) { _titre = titre;};
		void setEntrepriseId(int & id) { _id_entreprise = id;};
		void setSkills(std::vector<std::string> & skills);

	private:

		int _id;
		std::string _titre ;
		std::vector<std::string> _skills;
		int _id_entreprise;		
} ;


#endif
