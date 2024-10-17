#include "Complex.h"
#include <iostream>
using namespace std;

// Constructeur sans paramètres
Complex::Complex()
{
    this->Re = 3;  // Partie réelle initialisée à 3
    this->Img = 4; // Partie imaginaire initialisée à 4
}

// Constructeur avec paramètres
Complex::Complex(double re, double img) : Re(re), Img(img) // Initializer list
{}

// Méthode pour afficher le nombre complexe
void Complex::afficher() const
{
    cout << this->Re << "+ i" << this->Img << endl; // Affiche le format "a + ib"
}

// Surcharge de l'opérateur + pour additionner deux nombres complexes
Complex* Complex::operator+(const Complex& z)
{
    Complex* Z = new Complex();
    Z->Re = this->Re + z.Re;  // Addition des parties réelles
    Z->Img = this->Img + z.Img; // Addition des parties imaginaires
    return Z; // Retourne un nouveau nombre complexe
}

// Surcharge de l'opérateur + pour additionner un nombre complexe et un double
Complex* Complex::operator+(double r)
{
    Complex* Z = new Complex();
    Z->Re = this->Re + r;  // Addition de la partie réelle
    Z->Img = this->Img;    // La partie imaginaire reste la même
    return Z; // Retourne un nouveau nombre complexe
}

// Surcharge de l'opérateur * pour multiplier deux nombres complexes
Complex* Complex::operator*(const Complex& u)
{
    Complex* Z = new Complex();
    Z->Re = (this->Re * u.Re) - (this->Img * u.Img); // Multiplication des parties réelles et imaginaires
    Z->Img = (this->Re * u.Img) + (this->Img * u.Re); // Formule de multiplication des complexes
    return Z; // Retourne un nouveau nombre complexe
}

// Surcharge de l'opérateur / pour diviser deux nombres complexes
Complex* Complex::operator/(const Complex& u)
{
    Complex* Z = new Complex();
    double denominateur = (u.Re * u.Re) + (u.Img * u.Img); // Calcul du dénominateur

    Z->Re = ((this->Re * u.Re) + (this->Img * u.Img)) / denominateur; // Partie réelle
    Z->Img = ((this->Img * u.Re) - (this->Re * u.Img)) / denominateur; // Partie imaginaire

    return Z; // Retourne un nouveau nombre complexe
}

// Surcharge de l'opérateur - pour soustraire deux nombres complexes
Complex* Complex::operator-(const Complex& z) const
{
    Complex* result = new Complex();
    result->Re = this->Re - z.Re;  // Soustraction des parties réelles  
    result->Img = this->Img - z.Img; // Soustraction des parties imaginaires  
    return result; // Retourne un nouveau nombre complexe
}

// Méthode pour calculer le module d'un nombre complexe
double Complex::module() const
{
    return sqrt(Re * Re + Img * Img); // |z| = sqrt(a^2 + b^2)
}

// Méthode pour obtenir le conjugué d'un nombre complexe
Complex* Complex::conjugue() const
{
    Complex* result = new Complex();
    result->Re = this->Re;     // Partie réelle reste la même
    result->Img = -(this->Img); // Partie imaginaire inversée
    return result; // Retourne le conjugué
}



// Surcharge de l'opérateur = pour l'affectation
Complex& Complex::operator=(const Complex& c)
{
    // Éviter l'auto-affectation (affecter l'objet à lui-même)
    if (this == &c)
    {
        return *this; // Retourne l'objet courant
    }

    // Copie des attributs
    this->Re = c.Re;
    this->Img = c.Img;

    // Retourne l'objet courant
    return *this;
}

// Surcharge de l'opérateur == pour comparer deux nombres complexes
bool Complex::operator==(const Complex& z) const
{
    return (this->Re == z.Re) && (this->Img == z.Img); // Retourne true ou false
}
