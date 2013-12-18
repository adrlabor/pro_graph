PREFIX=../..

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
OBJS= Graph.o Random_graph.o Glouton.o TwoAppr_neighbourhood.o main.o

#les dependances 
all: $(OUTFILE)

main: $(OBJS) main.o

#$(OUTFILE): $(OBJS) 
        # regle implicite utilisee par make pour l'edition de liens
        # $(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

#les dependances des fichiers objets
Glouton.o: source/Glouton.cpp 
		gcc -o Glouton.o -c source/Glouton.cpp  -W -Wall -ansi -pedantic

TwoAppr_neighbourhood.o: source/Glouton.cpp source/TwoAppr_neighbourhood.cpp
		gcc -o TwoAppr_neighbourhood.o -c  source/TwoAppr_neighbourhood.cpp -W -Wall -ansi -pedantic



Random_graph.o: source/Random_graph.cpp
		gcc -o Random_graph.o -c source/Random_graph.cpp -W -Wall -ansi -pedantic
Graph.o: source/Graph.cpp 
		gcc -o Graph.o -c source/Graph.cpp -W -Wall -ansi -pedantic
main.o: main.cpp

.o: .cpp .h
        # regle implicite utilisee par make pour la compilation 
        # $(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

clean :
	rm -f  $(OUTFILE) $(OBJS)

mrproper: clean
	rm -f *~
