#include "Ponctuelle.hpp"
#include <iostream>

Ponctuelle::Ponctuelle()
{
}

Ponctuelle::Ponctuelle(std::string nom,int matricule,int montant)
  :Employee(nom,matricule)
{
    this->montant=montant;
}

Ponctuelle::~Ponctuelle()
{
}

int Ponctuelle::getMontant() const
{
    return montant;
}

double Ponctuelle::calculPaieBrute()
{
    return this->montant;
}

void Ponctuelle::afficherEtatPaie()
{
   double impotsCA=this->calculPaieBrute()*this->getImpotsCA();
   double impotsQC=this->calculPaieBrute()*this->getImpotsQC();
   double paieNette=calculPaieBrute()-impotsCA-impotsQC;
   std::cout<<this->getNom()<<" "<<this->getMatricule()<<std::endl;
   std::cout<<"  Paie brute de "<<this->calculPaieBrute()<<" $"<<std::endl; 
   std::cout<<"  Impots CA de " <<impotsCA<<" $"<<std::endl;
   std::cout<<"  Impots QC de " <<impotsQC<<" $"<<std::endl;
   std::cout<<"  Paie nette de "<<paieNette<<" $"<<std::endl;     
}

