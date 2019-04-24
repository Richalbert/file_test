#include <fstream>
#include <string>
#include <iostream>
using namespace std;

// ouvrir le fichier puis le convertir en bool... comprenez-
// vous le rôle de la double négation logique ici?
bool fichier_existe(const string &nom) {
   return !!(ifstream{ nom });
}
int main() {
   const string FICHIER_TEST = "test.dat";
   cout << "Le fichier " << FICHIER_TEST;
   if (fichier_existe(FICHIER_TEST))
      cout << " existe." << endl;
   else
      cout << " n'existe pas." << endl;
}
