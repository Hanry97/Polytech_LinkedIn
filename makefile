
# ===============================================
#||  Auteur ::                 Hanry Nzale      ||
# ===============================================
#|| Dernière modification ::   28/04/2020       ||
# ===============================================

cc := g++

.DEFAULT_GOAL := check

.PHONY: clean

# Efface tout les fichiers temporaires et les produits finaux.
clean:
	rm -rf build

# Crée le répertoire qui acceuille les fichiers temporaires et les produits finaux.
build:
	mkdir -p build

#Librairies
#Fichiers
build/fichier.o: lib/fichier.cpp | build
	$(cc) -Wall -pedantic -Werror -g -c lib/fichier.cpp -I ./lib -o build/fichier.o

#Class
#Company
build/company.o: lib/company.cpp | build
	$(cc) -Wall -pedantic -Werror -g -c lib/company.cpp -I ./lib -o build/company.o

#display
build/display.o: lib/display.cpp | build
	$(cc) -Wall -pedantic -Werror -g -c lib/display.cpp -I ./lib -o build/display.o

#jobseeker
build/jobseeker.o: lib/jobseeker.cpp | build
	$(cc) -Wall -pedantic -Werror -g -c lib/jobseeker.cpp -I ./lib -o build/jobseeker.o

#employe
build/employe.o: lib/employe.cpp | build
	$(cc) -Wall -pedantic -Werror -g -c lib/employe.cpp -I ./lib -o build/employe.o

#Position
build/Position.o: lib/Position.cpp | build
	$(cc) -Wall -pedantic -Werror -g -c lib/Position.cpp -I ./lib -o build/Position.o

#Librairie statique globale
build/libglobal.a: build/fichier.o build/Position.o build/Person.o build/display.o build/Company.o
	ar crs build/libglobal.a build/fichier.o build/Position.o build/Person.o build/display.o build/Company.o

#Test
build/test.o: test/test.cpp | build
	$(cc) -Wall -pedantic -Werror -g -c test/test.cpp -I ./lib -o build/test.o

build/test: build/test.o build/libglobal.a | build
	$(cc) build/test.o -Lbuild -lglobal -o build/test

build/appli.o: main.cpp | build
	$(cc) -Wall -pedantic -Werror -g -c main.cpp -I ./lib -o build/appli.o

#build/appli: build/appli.o build/libglobal.a | build
#	$(cc) build/appli.o -Lbuild -lglobal -o build/appli

build/appli: build/appli.o build/fichier.o build/company.o build/display.o build/employe.o build/jobseeker.o build/Position.o
	$(cc) build/appli.o -o build/appli build/fichier.o build/company.o build/display.o build/employe.o build/jobseeker.o build/Position.o
# S'assure de l'existence de tous les programmes finaux (application, test, etc.)
# Par exemple : all: build/test build/appli

all: build/test build/appli

# Lance le programme de test.
check: all
	./build/test

# Lance le programme principale
execute_app : all
	./build/appli
