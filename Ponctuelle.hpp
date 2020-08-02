#ifndef PONCTUELLE_HPP
#define PONCTUELLE_HPP
#include "Employee.hpp"
#include "ImpotsTaxes.hpp"

class Ponctuelle : public Employee,public ImpotsTaxes
{
public:
    Ponctuelle();
    Ponctuelle(std::string nom,int matricule,int montant);
    ~Ponctuelle();
    int getMontant() const;
    double calculPaieBrute();
    void afficherEtatPaie();
private :
  int montant;
};

#endif // PONCTUELLE_HPP
