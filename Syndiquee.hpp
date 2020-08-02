#ifndef SYNDIQUEE_HPP
#define SYNDIQUEE_HPP
#include "Employee.hpp"
#include "ImpotsTaxes.hpp"
class Syndiquee : public Employee,public ImpotsTaxes
{
public:
     Syndiquee();
     Syndiquee(std::string nom,int matricule,double salaire,double heures);
    ~Syndiquee();
    double getSalaire() const;
    double getHeures() const;
    double calculPaieBrute();
    void afficherEtatPaie();
private:
  double salaire;
  double heures;
};

#endif // SYNDIQUEE_HPP
