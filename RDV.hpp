#include <iostream>
#include <string>
using namespace std;



#ifndef __RDV__
#define __RDV__
    class Entreprise;
    class Etudiant;
    class RDV{
        private:
        string dateRDV;
        int heureDebut;
        int heureFin;
        Etudiant *etudiant;
        Entreprise *entreprise;

        public:
        static vector<RDV*> listeRdv;
        RDV(string d , int hd , int hf , Etudiant *etu , Entreprise *entrep );
        string getDateRDV()const{ return dateRDV;}
        int getHeureDebut()const{return heureDebut;}
        int getHeureFin()const{return heureFin;}

        void setDateRDV(string d){  dateRDV = d;}
        void setHeureDebut(int hd){ heureDebut = hd;}
        void setHeureFin(int hf){ heureFin = hf;}
        
        void afficherRDV() const;
        static bool comparerParDateHeure(const RDV* rdv1, const RDV* rdv2);
        static bool comparerParNomDateHeure(const RDV* rdv1, const RDV* rdv2);
        static void afficherListeRdvEtudiant(Etudiant *etu);
        static void afficherListeRdvEntreprise();

    };


#endif