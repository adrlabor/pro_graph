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
OUTFILE= test

#les fichiers objets a generer 
#OBJS= $(LIBOBJS) 
OBJS= Graph.o Random_graph.o Algorithmes.o test.o

#les dependances 
all: $(OUTFILE)

test: $(OBJS) test.o

#$(OUTFILE): $(OBJS) 
        # regle implicite utilisee par make pour l'edition de liens
        # $(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

#les dependances des fichiers objets

test.o: test.cpp

.o: .cpp .h
        # regle implicite utilisee par make pour la compilation 
        # $(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

clean :
	rm -f  $(OUTFILE) $(OBJS)

mrproper: clean
	rm -f *~