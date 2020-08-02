#ifndef IMPOTSTAXES_HPP
#define IMPOTSTAXES_HPP

/* Declaration d'une classe impots taxes pour faciliter la gestion
 * la maintenance de notre programme sur le volet impots en cas 
 * il y aura des changements un jours*/
class ImpotsTaxes 
{
public:
     ImpotsTaxes();
    ~ImpotsTaxes();
     double getImpotsCA() const;
     double getImpotsQC() const;      
private :
    double const impotsCA=0.15;
    double const impotsQC=0.15;
};

#endif // IMPOTSTAXES_HPP

