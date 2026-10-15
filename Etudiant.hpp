#include <iostream>
#include <string>
using namespace std;



#ifndef __ETUDIANT__
#define __ETUDIANT__
    class RDV;
    class Experience;
    class Obtenus;
    class EstInscrit;
    class Etudiant{
        protected:
        string numeroEtudiant;
        string nomEtudiant;
        string prenomEtudiant;
        string adresseEtudiant;
        string telEtudiant;
        vector<RDV*> listeRdvEtudiant;
        vector <Experience*> listeExperienceUnEtudiant;
        vector<Obtenus*> listeDiplomeObtenusParEtudiant;
        vector<EstInscrit*> listeDiplomeInscritParEtudiant;


        public:
        
        Etudiant(string nu , string no , string p , string a , string t);
        string getNumeroEtudiant() const{return numeroEtudiant;}
        string getNomEtudiant()const{return nomEtudiant;}
        string getPrenomEtudiant()const{return prenomEtudiant;}
        string getAdresseEtudiant()const{return adresseEtudiant;}
        string getTelEtudiant()const{return telEtudiant;}

        void setNumeroEtudiant(string nu){ numeroEtudiant = nu;}
        void setNomEtudiant(string no){ nomEtudiant = no;}
        void setPrenomEtudiant(string p ){ prenomEtudiant = p;}
        void setAdresseEtudiant(string a){ adresseEtudiant = a;}
        void setTelEtudiant(string t){ telEtudiant = t;}



        virtual void afficherEtudiant()const{
            cout << "N° : " << numeroEtudiant << ", nom : " << nomEtudiant << ", prenom : " << prenomEtudiant << ", adresse : " << adresseEtudiant << ", tel : " << telEtudiant <<", ";
        }

        void ajouterRdvEtudiant(RDV *rdv);
        void afficherListeRdvEtudiant();

        void ajouterExperienceEtudiant(Experience *ex);
        void afficherListeExperienceEtudiant();

        void ajouterDiplomeAUnEtudiant(Obtenus *obt);
        void afficherListeDiplomeObtenusParEtudiant();

        void ajouterInscriptionEtudiant(EstInscrit *inscritption);
        void afficherListeDiplomeInscritParEtudiant();

        void CV();
        

    };



    class EtudiantPremierCycle : public Etudiant{
        private:
        string serieBac;
        int anneeBac;
        string lieuBac;


        public:
        EtudiantPremierCycle(string nu , string no , string p , string a , string t , string s , int an , string l  ): Etudiant(nu,no,p,a,t){
            serieBac = s;
            anneeBac = an;
            lieuBac = l;
        }

        string getSerieBacEtudiant()const{return serieBac;}
        int getAnneeBacEtudiant()const{return anneeBac;}
        string getLieuBacEtudiant()const{return lieuBac;}

        void setSerieBacEtudiant(string s){ serieBac = s;}
        void setAnneeBacEtudiant(int an){ anneeBac = an;}
        void setLieuBacEtudiant(string l ){ lieuBac = l;}

        void afficherEtudiant()const{
            Etudiant::afficherEtudiant();
            cout << "serie bac : " << serieBac << ", annee bac : " << anneeBac << ", lieu d'obtention : " << lieuBac << endl;
        }



    };

    class EtudiantdeuxiemeCycle : public Etudiant{
        private:
        string nomDispline;
    


        public:
        EtudiantdeuxiemeCycle(string nu , string no , string p , string a , string t ,  string nd): Etudiant(nu,no,p,a,t){
            nomDispline = nd;
           
        }

        string getNomDisplineEtudiant()const{return nomDispline;}
        
        void setNomDisplineEtudiant(string nd ){ nomDispline = nd;}

        void afficherEtudiant()const{
            Etudiant::afficherEtudiant();
            cout << "nom Displine : " << nomDispline << endl;}



    };


#endif