#include "XML/XMLParser.hpp"
#include "Comparator/ComparatorDinamico.hpp"
#include "Comparator/ComparatorDivide.hpp"
using namespace std;

int main()
{
    vector<Country> countryList;

    // Parsear de XML
    XMLParser parser;
    countryList = parser.parseToCountries();
    // ! Prueba de intersec
    Country pais1;
    Country pais2;
    // for (Country c : countryList)
    // {
    //     if (c.getCountryName() == "Portugal")
    //         pais1 = c;
    //     if (c.getCountryName() == "Spain")
    //         pais2 = c;
    // }
    // pais1.print();
    // pais2.print();
    // cout << ((pais1.seIntersecan(pais2)) ? "Son vecinos" : "NO son vecinos") << endl;

    // ! Prueba comparador colores
    ComparatorDivide comparator;
    comparator.insertarColor("Rojo");
    comparator.insertarColor("Verde");
    comparator.insertarColor("Azul");
    comparator.comparar(countryList, 0, 0);
    comparator.imprimir();
    return 0;
}
