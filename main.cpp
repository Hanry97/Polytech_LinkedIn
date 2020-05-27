#include <iostream>
#include "lib/view.h"
#include "lib/extra3/compression.h"
#include "lib/extra3/decompression.h"

using namespace std;

//last modif: GNANKENE Cheick   27/05/2020
//=========================================

int main()
{
   //On décompresse la base de données
   decompress_csv_files() ;
   
   //Fonction d'entré du programme
   home_screen() ;

   //On compresse la base de données avant de quitter
   compress_csv_files() ;

	return 0 ;
}
