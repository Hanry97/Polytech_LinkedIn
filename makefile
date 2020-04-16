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
build/fichier.o: lib/fichier.cpp | build
	$(cc) -Wall -pedantic -Werror -g -c lib/fichier.cpp -I ./lib -o build/fichier.o

build/libfichier.a: build/fichier.o | build
	ar crs build/libfichier.a build/fichier.o

#Test
build/test.o: test/test.cpp | build
	$(cc) -Wall -pedantic -g -c test/test.cpp -I ./lib -o build/test.o

build/test: build/test.o build/libfichier.a | build
	$(cc) build/test.o -Lbuild -lfichier -o build/test

# S'assure de l'existence tout les programmes finaux (application, test, etc.)
# Par exemple : all: build/test build/appli

all: build/test 

# Lance le programme de test.
check: all
	./build/test
