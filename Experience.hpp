#include <iostream>
#include <string>
using namespace std;



#ifndef __EXPERIENCE__
#define __EXPERIENCE__
    class Etudiant;
    class Experience{
        private:
        string dateDebut;
        string dateFin;
        string nomEntreprise;
        string fonctionOccupee;
        vector<Etudiant*> listeEtudiantOntExperience;


        public:
        Experience(string dd , string df , string ne , string fo){
            dateDebut = dd;
            dateFin = df;
            nomEntreprise = ne;
            fonctionOccupee = fo;
        }

        string getDateDebut()const{ return dateDebut;}
        string getDateFin()const{return dateFin;}
        string getDomEntreprise()const{return nomEntreprise;}
        string getDonctionOccupee()const{return fonctionOccupee;}

        void setDateDebut(string dd){  dateDebut = dd;}
        void setDateFin(string df){ dateFin = df;}
        void setDomEntreprise(string ne){ nomEntreprise = ne;}
        void setDonctionOccupee(string fo){  fonctionOccupee = fo;}



        void afficherExperience()const{
            cout << "Date Debut : " << dateDebut << ", Date Fin : " << (dateFin == "-" ? "Present" :dateFin ) << ", Nom Entreprise : " << nomEntreprise << ", Fonction Occupee : " << fonctionOccupee << endl;
        }
        void ajouterEtudiantEnExperience(Etudiant *etu);
        void afficherEtudiantEnExperience();


    };


#endif