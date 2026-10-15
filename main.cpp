#include "Etudiant.cpp"


int main(){
   
    EtudiantPremierCycle mohamed("2019321" , "alfares" , "mohamed" , "Camille guerin" , "0753172820" , "S" , 2018 , "Syrie");
    EtudiantPremierCycle racha("20221232" , "ouannenas" , "racha" , "Laborie" , "078378220" , "S" , 2021 , "Algerie");
    EtudiantPremierCycle amira("2019321" , "ibersiene" , "amira" , "Laborie" , "075982820" , "S" , 2021 , "Algerie");
    EtudiantPremierCycle katy("2019321" , "belhasan" , "katy" , "Laborie" , "0753702820" , "S" , 2020 , "Algerie");


    EtudiantdeuxiemeCycle ahmed("20195487" , "alfares" , "ahmed" , "Camille guerin" , "0756771477" , "Informatique");
    EtudiantdeuxiemeCycle eya("20195487" , "fennishe" , "eya" , "poitier" , "0756732477" , "Genie biologie");




    Experience kfc("10/10/2022" , "-" , "KFC CENTRE" , "Equiper polyvalent");
    Experience accueil("06/06/2023" , "-" , "cité universitaire camille guerin" , "agent de reception");
    Experience carrefour("01/02/2022" , "-" , "Carrefour" , "Equiper polyvalent");
    Experience tuteur("01/09/2024" , "31/12/2024" , "Maison de langue" , "tuteur");
    Experience macdo("19/05/2022" , "01/06/2024" , "Macdo saint junien" , "Equiper polyvalent");
    Experience dominos("19/05/2024" , "-" , "dominos pizza" , "Equiper polyvalent");

    Entreprise limogesTec("Limoges technoligie" , "Centre ville" , "Albert thomas" , "055553426");
    Entreprise dgfp("Direction general de finance publique" , "ruue de la république" , "dupon olivier" , "055980426");
    Entreprise infoTec("Informatique techno" , "saint junien" , "nicolas martin" , "0598053426");


    RDV rdv1("06/01/2024" , 17 , 18 , &mohamed  , &limogesTec);
    RDV rdv2("05/01/2024" , 10 , 11 , &racha  , &limogesTec);
    RDV rdv3("05/01/2024" ,11 , 12 , &amira  , &limogesTec);
    RDV rdv4("05/01/2024" , 14 , 15 , &katy  , &limogesTec);

    RDV rdv5("06/01/2024" , 9 , 10 , &mohamed  , &dgfp);
    RDV rdv6("07/01/2024" , 16 , 17 , &eya  , &dgfp);
    RDV rdv7("08/01/2024" ,8 , 9 , &amira  , &infoTec);
    RDV rdv8("09/01/2024" , 14 , 15 , &katy  , &infoTec);

    RDV rdv0("06/01/2024" , 17 , 18 , &mohamed  , &limogesTec);

    mohamed.afficherListeRdvEtudiant();

   
    mohamed.ajouterExperienceEtudiant(&tuteur);
    mohamed.ajouterExperienceEtudiant(&accueil);
    amira.ajouterExperienceEtudiant(&kfc);
    katy.ajouterExperienceEtudiant(&carrefour);
    ahmed.ajouterExperienceEtudiant(&macdo);
    racha.ajouterExperienceEtudiant(&tuteur);
    racha.ajouterExperienceEtudiant(&dominos);


    //mohamed.afficherListeRdvEtudiant();
    //RDV::afficherListeRdvEtudiant(&mohamed); // pour afficher les RDV d'un etudiant passer en parametre
    //RDV::afficherListeRdvEntreprise(); //pour afficher tous les RDV des entreprises 
    //mohamed.afficherListeExperienceEtudiant();

    Diplome info("QSDFG" , "INFORMATIQUE");
    Diplome physique("AZERT" , "PHYSIQUE");

    //info.afficherDiplome();

    Obtenus obt(2025 , "Limoges" , &info , &mohamed);
    Obtenus obt1(2025 , "Limoges" , &info , &katy);
    Obtenus obt2(2025 , "Limoges" , &info , &racha);
    Obtenus obt3(2025 , "Limoges" , &info , &amira);
    Obtenus obt4(2024 , "Limoges" , &info , &ahmed);

    //info.afficherListeEtudiantsOntObtenusDiplome();



    EstInscrit i1(2021 , 1 , &info , &mohamed);
    EstInscrit i2(2021 , 1 , &physique , &mohamed);
    EstInscrit i3(2021 , 1 , &info , &racha);

    //mohamed.CV();





    



}


