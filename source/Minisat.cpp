#include "../include/Minisat.h"
#include "../include/Graph.h"


Minisat::Minisat() {
}

Minisat::~Minisat() {
}

void Minisat::VertexCoverToSat(Graph *g) {
        int numberVertex = g->getNbVertex();
        //Construction du vecteur avec toutes les arrêtes
        vector<int> neighboursOfVertex;
        vector<pair<int,int> > listVertice =  vector<pair<int,int> > ();
        for(int i=0;i<numberVertex;i++){
          neighboursOfVertex =  g->getNeighbours(i);
          for (int j=0;j<(signed)neighboursOfVertex.size();j++){
            int numVertex = neighboursOfVertex[j];
            listVertice.push_back(pair<int,int>(i+1,numVertex+1));

          }
          //Création du fichier de sortie
          computeFile(numberVertex,listVertice);
          startMinisat();
        }
}

void Minisat::computeFile(int numberVertex, vector<pair<int,int> > listVertice ){
    ofstream out ("fileVCtoSAT", ios_base::out | ios_base::trunc);


          out << "p cnf " << numberVertex;
          out << " " ;
          out << listVertice.size() << endl;

          for (int i=0; i<(signed)listVertice.size(); i++) {
                  out << listVertice[i].first;
                  out << " ";
                  out << listVertice[i].second;
                  out << " 0\n";
          }

          out.close();

}

void Minisat::startMinisat(){
    system("minisat/core/minisat fileVCtoSAT minisat-result" );
}
