#include <iostream>
#include <string>
using namespace std;



#ifndef __OBTENUS__
#define __OBTENUS__
    class Etudiant;
    class Diplome;
    class Obtenus{
        private:
        int dateObtention;
        string lieuObtention;
        Etudiant *etudiant;
        Diplome *diplome;    

        public:
        Obtenus(int d , string l , Diplome *dip , Etudiant *etu);

        int getDateObtention()const{ return dateObtention;}
        string getLieuObtention()const{return lieuObtention;}
        Etudiant *getEtudiant(){return etudiant;}
        Diplome *getDiplome(){return diplome;}

        void setDateObtention(int d){  dateObtention = d;}
        void setLieuObtention(string l){ lieuObtention = l;}



        void afficherObtentionDetaille()const{
            cout << "Date Obtention : " << dateObtention << ", Lieu Obtention : " << lieuObtention << " : ";
        }  


    };


#endif