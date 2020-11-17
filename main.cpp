#include "XML/XMLParser.hpp"
#include "Comparator/ComparatorDinamico.hpp"
#include "Comparator/ComparatorDivide.hpp"
#include "Comparator/ComparatorBacktracking.hpp"
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

    parser.cambiarColorPais("United States", "#FF0000");
    parser.escribirASVG("svg//test.svg");
    // ! Prueba comparador colores
    ComparatorBacktracking comparator;
    comparator.insertarColor("Rojo");
    comparator.insertarColor("Verde");
    comparator.insertarColor("Azul");
    comparator.comparar(countryList);
    comparator.imprimir();
    return 0;
}
