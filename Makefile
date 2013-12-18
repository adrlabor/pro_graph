PREFIX=
DIRINCLUDE = $(PREFIX)include/
DIRSOURCE = $(PREFIX)source/

#le compilateur
CC= g++

#les flags de compilation
CFLAGS= -g -Wall -Werror

#les flags du preprocesseur 
CPPFLAGS=

#les flags de l'editeur de liens 
LDFLAGS= 

#les librairies utilisees 
LDLIBS= -lm

#Les fichiers d'entete de la librairie a creer
INSTHEADERS= .h

#Les fichiers objets Ãƒ  inserer das la bibliotheque
LIBOBJS= .o

#Le nom du fichier executable servant a valider le module
OUTFILE= main

#les fichiers objets a generer 
#OBJS= $(LIBOBJS) 
OBJS= Graph.o Random_graph.o Glouton.o TwoAppr_neighbourhood.o TwoAppr_depthSearch.o Random_bipartis.o main.o

#les dependances 
all: $(OUTFILE)

main: $(OBJS) main.o

#$(OUTFILE): $(OBJS) 
        # regle implicite utilisee par make pour l'edition de liens
        # $(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

#les dependances des fichiers objets
Glouton.o: source/Glouton.cpp 
		gcc -o Glouton.o -c $(DIRSOURCE)Glouton.cpp  -W -Wall -ansi -pedantic

TwoAppr_neighbourhood.o: $(DIRSOURCE)TwoAppr_neighbourhood.cpp
		gcc -o TwoAppr_neighbourhood.o -c  $(DIRSOURCE)TwoAppr_neighbourhood.cpp -W -Wall -ansi -pedantic

TwoAppr_depthSearch.o: $(DIRSOURCE)TwoAppr_depthSearch.cpp
		gcc -o TwoAppr_depthSearch.o -c  $(DIRSOURCE)TwoAppr_depthSearch.cpp -W -Wall -ansi -pedantic

Random_bipartis.o: $(DIRSOURCE)Random_bipartis.cpp
		gcc -o Random_bipartis.o -c  $(DIRSOURCE)Random_bipartis.cpp -W -Wall -ansi -pedantic



Random_graph.o: source/Random_graph.cpp
		gcc -o Random_graph.o -c $(DIRSOURCE)Random_graph.cpp -W -Wall -ansi -pedantic
Graph.o: source/Graph.cpp 
		gcc -o Graph.o -c $(DIRSOURCE)Graph.cpp -W -Wall -ansi -pedantic
main.o: main.cpp

.o: .cpp .h
        # regle implicite utilisee par make pour la compilation 
        # $(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

clean :
	rm -f  $(OUTFILE) $(OBJS)

mrproper: clean
	rm -f *~
