#ifndef CONTRACTUELLE_HPP
#define CONTRACTUELLE_HPP
#include "Employee.hpp"
#include "ImpotsTaxes.hpp"
class Contractuelle : public Employee,public ImpotsTaxes
{
public:
    Contractuelle();
    Contractuelle(std::string nom,int matricule,int montant,int semaines);
    ~Contractuelle();
    int getMontant() const;
    int getSemaines() const;
    double calculPaieBrute();
    void afficherEtatPaie();
private :
  int montant;
  int semaines;
};

#endif // CONTRACTUELLE_HPP
