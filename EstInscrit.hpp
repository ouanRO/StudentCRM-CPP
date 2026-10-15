#include <iostream>
#include <string>
using namespace std;



#ifndef __ESTINSCRIT__
#define __ESTINSCRIT__
    class Etudiant;
    class Diplome;
    class EstInscrit{
        private:
        int datePremiereInsription;
        int numeroAnnee;
        Etudiant *etudiant;
        Diplome *diplome;    

        public:
        EstInscrit(int d , int n , Diplome *dip , Etudiant *etu);

        int getDatePremiereInsription()const{ return datePremiereInsription;}
        int getNumeroAnnee()const{return numeroAnnee;}
        Etudiant *getEtudiant(){return etudiant;}
        Diplome *getDiplome(){return diplome;}

        void setDatePremiereInsription(int d){  datePremiereInsription = d;}
        void setNumeroAnnee(int n){ numeroAnnee = n;}



        void afficherInscriptionDetaille()const{
            cout << "Date Premiere Insription : " << datePremiereInsription << ", Numero Annee : " << numeroAnnee << " : ";
        }  


    };


#endif