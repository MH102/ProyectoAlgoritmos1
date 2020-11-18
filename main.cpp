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
    parser->escribirASVG("svg//test.svg");

    // ! Prueba comparador colores
    ComparatorBacktracking comparator(parser);
    comparator.insertarColor("#f6ce00");
    comparator.insertarColor("#cc0000");
    comparator.insertarColor("#003399");
    comparator.insertarColor("#96a65d");
    comparator.comparar(countryList);
    comparator.imprimir();
    return 0;
}
