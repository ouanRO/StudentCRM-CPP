#include "RDV.hpp"
#include "Entreprise.hpp"
#include "Etudiant.hpp"
#include "Experience.hpp"
#include <vector>
#include "Diplome.hpp"
#include "Obtenus.hpp"
#include "EstInscrit.hpp"

using namespace std;
vector<RDV*> RDV::listeRdv;

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
Etudiant::Etudiant(string nu , string no , string p , string a , string t ){
            numeroEtudiant = nu;
            nomEtudiant = no;
            prenomEtudiant = p;
            adresseEtudiant = a;
            telEtudiant = t;
        }

void Etudiant::ajouterRdvEtudiant(RDV *rdv) {
    // Vérification de duplication
    for (RDV* r : listeRdvEtudiant) {
        if (r->getDateRDV() == rdv->getDateRDV() &&
            r->getHeureDebut() == rdv->getHeureDebut() &&
            r->getHeureFin() == rdv->getHeureFin()) {
            cout << "Erreur : Ce rendez-vous existe déjà pour cet étudiant." << endl;
            return;
        }
    }

    // Vérification des conflits horaires
    for (RDV* r : listeRdvEtudiant) {
        if (r->getDateRDV() == rdv->getDateRDV() &&
            !(rdv->getHeureFin() <= r->getHeureDebut() || rdv->getHeureDebut() >= r->getHeureFin())) {
            cout << "Erreur : Conflit horaire détecté avec un autre rendez-vous." << endl;
            return;
        }
    }

    // Ajout si aucune erreur n'est détectée
    listeRdvEtudiant.push_back(rdv);
    
}

void Etudiant::afficherListeRdvEtudiant(){
    sort(listeRdvEtudiant.begin(), listeRdvEtudiant.end(), RDV::comparerParDateHeure);
    vector<RDV*>::iterator it;
    it = listeRdvEtudiant.begin();
    while (it != listeRdvEtudiant.end())
    {
        (*it)->afficherRDV();
        it++;
    }
    
}


void Etudiant::ajouterExperienceEtudiant(Experience *ex){
    listeExperienceUnEtudiant.push_back(ex);

}
void Etudiant::afficherListeExperienceEtudiant(){
    vector<Experience*>::iterator it;
    it = listeExperienceUnEtudiant.begin();
    while (it != listeExperienceUnEtudiant.end())
    {
        (*it)->afficherExperience();
        it++;
    }
}


void Etudiant::ajouterDiplomeAUnEtudiant(Obtenus *obt){
    listeDiplomeObtenusParEtudiant.push_back(obt);
}
void Etudiant::afficherListeDiplomeObtenusParEtudiant(){
    vector<Obtenus*>::iterator it;
    it = listeDiplomeObtenusParEtudiant.begin();
    while (it != listeDiplomeObtenusParEtudiant.end())
    {
        (*it)->afficherObtentionDetaille();(*it)->getDiplome()->afficherDiplome();
        it++;
    }
}

void Etudiant::ajouterInscriptionEtudiant(EstInscrit *inscritption){
    listeDiplomeInscritParEtudiant.push_back(inscritption);
}



void Etudiant::afficherListeDiplomeInscritParEtudiant(){
    vector<EstInscrit*>::iterator it;
    it = listeDiplomeInscritParEtudiant.begin();
    while (it != listeDiplomeInscritParEtudiant.end())
    {
        (*it)->afficherInscriptionDetaille(); (*it)->getDiplome()->afficherDiplome();
        it++;
    }
}




 void Etudiant::CV(){
    cout << "Informations administratives : " << endl;
    afficherEtudiant();

    cout << "Diplômes obtenus : " << endl;
    afficherListeDiplomeObtenusParEtudiant();

    cout << "Expériences professionnelles : " << endl;
    afficherListeExperienceEtudiant();
 }

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void RDV::afficherListeRdvEtudiant(Etudiant *etu){
    int verifie = 0;
    vector<RDV*>::iterator it;
    it = listeRdv.begin();
    while (it != listeRdv.end())
    {   
        if((*it)->etudiant->getNomEtudiant() == etu->getNomEtudiant() && (*it)->etudiant->getPrenomEtudiant() == etu->getPrenomEtudiant()){
            (*it)->etudiant->afficherListeRdvEtudiant();
            verifie = 1;
            break;
        }else if(etu->getNomEtudiant() == "-" && etu->getPrenomEtudiant() == "-" && etu->getNumeroEtudiant() == (*it)->etudiant->getNumeroEtudiant()){
            (*it)->etudiant->afficherListeRdvEtudiant();
            verifie = 1;
            break;
        }
        
        it++;
    }

    if(verifie == 0){
        cout << etu->getNomEtudiant() << " " << etu->getPrenomEtudiant() << " n'a pas des RDV ... " << endl;
    }
    
}

void RDV::afficherListeRdvEntreprise(){
    sort(RDV::listeRdv.begin(), RDV::listeRdv.end(), RDV::comparerParNomDateHeure);
    vector<RDV*>::iterator it;
    it = listeRdv.begin();

    while(it != listeRdv.end()){
        (*it)->afficherRDV();


        it++;
    }

}

RDV::RDV(string d , int hd , int hf , Etudiant *etu , Entreprise *entrep ){
            dateRDV = d;
            heureDebut = hd;
            heureFin = hf;
            etudiant = etu;
            entreprise = entrep;
            entreprise->ajouterRdv(this);
            etudiant->ajouterRdvEtudiant(this);
            listeRdv.push_back(this);
            

        }


void RDV::afficherRDV() const {
    
            cout << "Date RDV : " << dateRDV
                << ", Heure Debut : " << heureDebut
                << ", Heure Fin : " << heureFin;

            if (etudiant != nullptr) {
                cout << ", Étudiant : " << etudiant->getNomEtudiant();
            }
            if (entreprise != nullptr) {
                cout << ", Entreprise : " << entreprise->getNomEntreprise();
            }
            cout << endl;
        }



///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////




void Entreprise::afficherListeRdvEntreprise(){
    vector<RDV*>::iterator it;
    it = listeRdvEntreprise.begin();
    while (it != listeRdvEntreprise.end())
    {
        (*it)->afficherRDV();
        it++;
    }
    
}

void Entreprise::ajouterRdv(RDV *rdv) {
    // Vérification de duplication
    for (RDV* r : listeRdvEntreprise) {
        if (r->getDateRDV() == rdv->getDateRDV() &&
            r->getHeureDebut() == rdv->getHeureDebut() &&
            r->getHeureFin() == rdv->getHeureFin()) {
            cout << "Erreur : Ce rendez-vous existe déjà pour cette entreprise." << endl;
            return;
        }
    }

    // Vérification des conflits horaires
    for (RDV* r : listeRdvEntreprise) {
        if (r->getDateRDV() == rdv->getDateRDV() &&
            !(rdv->getHeureFin() <= r->getHeureDebut() || rdv->getHeureDebut() >= r->getHeureFin())) {
            cout << "Erreur : Conflit horaire détecté avec un autre rendez-vous." << endl;
            return;
        }
    }

    // Ajout si aucune erreur n'est détectée
    listeRdvEntreprise.push_back(rdv);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


void Experience::ajouterEtudiantEnExperience(Etudiant *etu) {
    // Vérification si l'étudiant est déjà associé à cette expérience
    for (Etudiant* e : listeEtudiantOntExperience) {
        if (e == etu) {
            cout << "Erreur : Cet étudiant est déjà associé à cette expérience." << endl;
            return;
        }
    }

    // Ajout de l'étudiant si aucune duplication n'est détectée
    listeEtudiantOntExperience.push_back(etu);
}

void Experience::afficherEtudiantEnExperience(){
    vector<Etudiant*>::iterator it;
    it = listeEtudiantOntExperience.begin();
    while (it != listeEtudiantOntExperience.end())
    {
        (*it)->afficherEtudiant();
        it++;
    }
}











///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
//Comperateur pour les liste demandées
bool RDV::comparerParDateHeure(const RDV* rdv1, const RDV* rdv2) {
    if (rdv1->getDateRDV() == rdv2->getDateRDV()) {
        return rdv1->getHeureDebut() < rdv2->getHeureDebut();
    }
    return rdv1->getDateRDV() < rdv2->getDateRDV();
}

bool RDV::comparerParNomDateHeure(const RDV* rdv1, const RDV* rdv2) {
    // Comparaison par le nom de l'entreprise
    if (rdv1->entreprise->getNomEntreprise() != rdv2->entreprise->getNomEntreprise()) {
        return rdv1->entreprise->getNomEntreprise() < rdv2->entreprise->getNomEntreprise();
    }

    // Comparaison par la date si les entreprises sont les mêmes
    if (rdv1->getDateRDV() != rdv2->getDateRDV()) {
        return rdv1->getDateRDV() < rdv2->getDateRDV();
    }

    // Comparaison par heure de début si les dates sont les mêmes
    return rdv1->getHeureDebut() < rdv2->getHeureDebut();
}


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


Obtenus::Obtenus(int d , string l , Diplome *dip , Etudiant *etu){
            dateObtention = d;
            lieuObtention = l;
            etudiant = etu;
            diplome = dip;
            etudiant->ajouterDiplomeAUnEtudiant(this);
            diplome->ajouterEtudiantObtientUnDiplome(this);

        }


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////



void Diplome::ajouterEtudiantObtientUnDiplome(Obtenus *obt){
    listeEtudiantsOntObtenusDiplome.push_back(obt);
}

void Diplome::afficherListeEtudiantsOntObtenusDiplome(){
    vector<Obtenus*>::iterator it;
    it = listeEtudiantsOntObtenusDiplome.begin();
    while (it != listeEtudiantsOntObtenusDiplome.end())
    {
        (*it)->afficherObtentionDetaille();(*it)->getEtudiant()->afficherEtudiant();
        it++;
    }
}

void Diplome::ajouterEtudiantInscitDansUnDiplome(EstInscrit *inscrit){
    listeEtudiantsInscritsDansUnDiplome.push_back(inscrit);
}
void Diplome::afficherListeEtudiantsInscritsDansUnDiplome(){
    vector<EstInscrit*>::iterator it;
    it = listeEtudiantsInscritsDansUnDiplome.begin();
    while (it != listeEtudiantsInscritsDansUnDiplome.end())
    {
        (*it)->afficherInscriptionDetaille() ; (*it)->getEtudiant()->afficherEtudiant();
        it++;
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////




EstInscrit::EstInscrit(int d , int n , Diplome *dip , Etudiant *etu){
    datePremiereInsription = d;
    numeroAnnee = n;
    diplome = dip;
    etudiant = etu;
    diplome->ajouterEtudiantInscitDansUnDiplome(this);
    etudiant->ajouterInscriptionEtudiant(this);
}