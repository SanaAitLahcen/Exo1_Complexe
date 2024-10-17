#pragma once
using namespace std;

class Complex
{
private:
	double Re;//attribut d'instance
	double Img;

public:
	Complex();
	Complex(double, double);
	Complex(const Complex&);
	void afficher() const;
	Complex* operator+(const Complex& z);//ona donné juste un seul param car on a a l'intérieur de la classe l'autre objet est de la classe
	Complex* operator+(double r);
	Complex* operator*(const Complex& u);
	Complex* operator/(const Complex& c);
	Complex* operator-(const Complex& z) const;
	double module() const;                // Retourne le module du nombre complexe
	Complex* conjugue() const;            // Retourne le conjugué du nombre complexe
	Complex& operator=(const Complex&);
	bool operator==(const Complex& z) const;
};

