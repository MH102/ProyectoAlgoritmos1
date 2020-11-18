#include "XML/XMLParser.hpp"
#include "Comparator/ComparatorDinamico.hpp"
#include "Comparator/ComparatorDivide.hpp"
#include "Comparator/ComparatorBacktracking.hpp"
using namespace std;

int main()
{
    vector<Country> countryList;

    // Parsear de XML
    XMLParser *parser = new XMLParser();
    countryList = parser->parseToCountries();
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

    // parser.cambiarCantidadPaisesPintados(100);
    // parser.cambiarCantidadPaisesEnBlanco(111);
    parser->escribirASVG("svg//test.svg");

    // ! Prueba comparador colores
    ComparatorDivide comparator(parser);
    comparator.insertarColor("#f6ce00");
    comparator.insertarColor("#cc0000");
    comparator.insertarColor("#003399");
    comparator.comparar(countryList, 0, 0);
    comparator.imprimir();
    return 0;
}
