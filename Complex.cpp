#include "Complex.h"
#include <iostream>
using namespace std;

// Constructeur sans param�tres
Complex::Complex()
{
    this->Re = 3;  // Partie r�elle initialis�e � 3
    this->Img = 4; // Partie imaginaire initialis�e � 4
}

// Constructeur avec param�tres
Complex::Complex(double re, double img) : Re(re), Img(img) // Initializer list
{}

// M�thode pour afficher le nombre complexe
void Complex::afficher() const
{
    cout << this->Re << "+ i" << this->Img << endl; // Affiche le format "a + ib"
}

// Surcharge de l'op�rateur + pour additionner deux nombres complexes
Complex* Complex::operator+(const Complex& z)
{
    Complex* Z = new Complex();
    Z->Re = this->Re + z.Re;  // Addition des parties r�elles
    Z->Img = this->Img + z.Img; // Addition des parties imaginaires
    return Z; // Retourne un nouveau nombre complexe
}

// Surcharge de l'op�rateur + pour additionner un nombre complexe et un double
Complex* Complex::operator+(double r)
{
    Complex* Z = new Complex();
    Z->Re = this->Re + r;  // Addition de la partie r�elle
    Z->Img = this->Img;    // La partie imaginaire reste la m�me
    return Z; // Retourne un nouveau nombre complexe
}

// Surcharge de l'op�rateur * pour multiplier deux nombres complexes
Complex* Complex::operator*(const Complex& u)
{
    Complex* Z = new Complex();
    Z->Re = (this->Re * u.Re) - (this->Img * u.Img); // Multiplication des parties r�elles et imaginaires
    Z->Img = (this->Re * u.Img) + (this->Img * u.Re); // Formule de multiplication des complexes
    return Z; // Retourne un nouveau nombre complexe
}

// Surcharge de l'op�rateur / pour diviser deux nombres complexes
Complex* Complex::operator/(const Complex& u)
{
    Complex* Z = new Complex();
    double denominateur = (u.Re * u.Re) + (u.Img * u.Img); // Calcul du d�nominateur

    Z->Re = ((this->Re * u.Re) + (this->Img * u.Img)) / denominateur; // Partie r�elle
    Z->Img = ((this->Img * u.Re) - (this->Re * u.Img)) / denominateur; // Partie imaginaire

    return Z; // Retourne un nouveau nombre complexe
}

// Surcharge de l'op�rateur - pour soustraire deux nombres complexes
Complex* Complex::operator-(const Complex& z) const
{
    Complex* result = new Complex();
    result->Re = this->Re - z.Re;  // Soustraction des parties r�elles  
    result->Img = this->Img - z.Img; // Soustraction des parties imaginaires  
    return result; // Retourne un nouveau nombre complexe
}

// M�thode pour calculer le module d'un nombre complexe
double Complex::module() const
{
    return sqrt(Re * Re + Img * Img); // |z| = sqrt(a^2 + b^2)
}

// M�thode pour obtenir le conjugu� d'un nombre complexe
Complex* Complex::conjugue() const
{
    Complex* result = new Complex();
    result->Re = this->Re;     // Partie r�elle reste la m�me
    result->Img = -(this->Img); // Partie imaginaire invers�e
    return result; // Retourne le conjugu�
}



// Surcharge de l'op�rateur = pour l'affectation
Complex& Complex::operator=(const Complex& c)
{
    // �viter l'auto-affectation (affecter l'objet � lui-m�me)
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

// Surcharge de l'op�rateur == pour comparer deux nombres complexes
bool Complex::operator==(const Complex& z) const
{
    return (this->Re == z.Re) && (this->Img == z.Img); // Retourne true ou false
}
