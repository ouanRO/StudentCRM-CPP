#include <iostream>
#include <string>
using namespace std;



#ifndef __DIPLOME__
#define __DIPLOME__
    class Obtenus;
    class EstInscrit;
    class Diplome{
        private:
        string codeDiplome;
        string nomNational;
        vector<Obtenus*> listeEtudiantsOntObtenusDiplome;
        vector<EstInscrit*> listeEtudiantsInscritsDansUnDiplome;


        public:
        Diplome(string c , string n){
            codeDiplome = c;
            nomNational = n;
        }

        string getCodeDiplome()const{ return codeDiplome;}
        string getNomNational()const{return nomNational;}
 

        void setCodeDiplome(string c){  codeDiplome = c;}
        void setNomNational(string n){ nomNational = n;}

        void ajouterEtudiantObtientUnDiplome(Obtenus *obt);
        void afficherListeEtudiantsOntObtenusDiplome();

        void ajouterEtudiantInscitDansUnDiplome(EstInscrit *inscrit);
        void afficherListeEtudiantsInscritsDansUnDiplome();


        void afficherDiplome()const{
            cout << "Code : " << codeDiplome << ", Nom national : " << nomNational << endl;
        }  


    };


#endif