#include<iostream>
using namespace std;
#include"Complex.h"




int main()
{

	Complex* C1=new Complex();
	Complex* C2=new Complex();


   Complex* C=new Complex() ;
	C = *C1 + *C2; //*:d�r�f�rencer un pointeur afin d'acc�der � l'objet auquel il pointe

	//*(*C1).operator+(*C2);   /// C2 objet en parametre 
  
    C->afficher();
	C1->afficher();
	C2->afficher();

    //C1 = (*C1).operator+(4);
	C1 = *C1 + 4;
	delete C;
	delete C1;
	delete C2;


}