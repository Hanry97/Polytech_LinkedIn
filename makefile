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

build/libfichier.a: build/fichier.o | build
	ar crs build/libfichier.a build/fichier.o

#Class
#Company
build/Company.o: lib/Company.cpp | build
	$(cc) -Wall -pedantic -Werror -g -c lib/Company.cpp -I ./lib -o build/Company.o

build/libCompany.a: build/Company.o | build
	ar crs build/libCompany.a build/Company.o

#display
build/display.o: lib/display.cpp | build
	$(cc) -Wall -pedantic -Werror -g -c lib/display.cpp -I ./lib -o build/display.o

build/libdisplay.a: build/display.o | build
	ar crs build/libdisplay.a build/display.o

#Person
build/Person.o: lib/Person.cpp | build
	$(cc) -Wall -pedantic -Werror -g -c lib/Person.cpp -I ./lib -o build/Person.o

build/libPerson.a: build/Person.o | build
	ar crs build/libPerson.a build/Person.o

#Position
build/Position.o: lib/Position.cpp | build
	$(cc) -Wall -pedantic -Werror -g -c lib/Position.cpp -I ./lib -o build/Position.o

build/libPosition.a: build/Position.o | build
	ar crs build/libPosition.a build/Position.o

#Test
build/test.o: test/test.cpp | build
	$(cc) -Wall -pedantic -Werror -g -c test/test.cpp -I ./lib -o build/test.o

#build/test: build/test.o build/libfichier.a build/libPosition.a build/libPerson.a build/libdisplay.a build/libCompany.a | build
#	$(cc) build/test.o -Lbuild -lfichier -lPosition -lPerson -ldisplay -lCompany -o build/test

build/test: build/test.o build/libfichier.a | build
	$(cc) build/test.o -Lbuild -lfichier -o build/test

build/appli.o: main.cpp | build
	$(cc) -Wall -pedantic -Werror -g -c main.cpp -I ./lib -o build/appli.o

build/appli: build/appli.o build/libfichier.a build/libPosition.a build/libPerson.a build/libdisplay.a build/libCompany.a | build
	$(cc) build/appli.o -Lbuild -lfichier -lPosition -lPerson -ldisplay -lCompany -o build/appli

# S'assure de l'existence tout les programmes finaux (application, test, etc.)
# Par exemple : all: build/test build/appli

all: build/test #build/appli

# Lance le programme de test.
check: all
	./build/test

# Lance le programme principale
execute_app : all
	./build/appli
