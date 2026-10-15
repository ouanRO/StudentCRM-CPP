#include <iostream>
#include <string>
using namespace std;
#include <vector> 



#ifndef __ENTREPRISE__
#define __ENTREPRISE__
    class RDV;
    class Entreprise{
        private:
        string nomEntreprise;
        string adresseEntreprise;
        string nomContact;
        string telContact;
        vector <RDV*> listeRdvEntreprise;


        public:
        Entreprise(string ne , string ad , string nc , string tc){
            nomEntreprise = ne;
            adresseEntreprise = ad;
            nomContact = nc;
            telContact = tc;
        }
        string getNomEntreprise()const{ return nomEntreprise;}
        string getAdresseEntreprise()const{return adresseEntreprise;}
        string getNomContact()const{return nomContact;}
        string getTelContact()const{return telContact;}

        void setNomEntreprise(string ne){  nomEntreprise = ne;}
        void setAdresseEntreprise(string ad){ adresseEntreprise = ad;}
        void setNomContact(string nc){ nomContact = nc;}
        void setTelContact(string tc){  telContact = tc;}



        void afficherEntreprise()const{
            cout << "Nom Entreprise : " << nomEntreprise << ", Adresse Entreprise : " << adresseEntreprise << ", Nom Contact : " << nomContact << ", Tel Contact" << telContact << endl;
        }


        void ajouterRdv(RDV *rdv);
        void afficherListeRdvEntreprise();


    };


#endif