#include "XMLParser.hpp"
#include "ColorComparator.hpp"
using namespace std;

int main()
{
    vector<Country> countryList;

    // Parsear de XML
    XMLParser parser;
    countryList = parser.parseToCountries();
    //cout << countryList.size() << endl;
    // for (Country c : countryList)
    // {
    //     c.print();
    // }
    ColorComparator comparator;
    comparator.insertarColor("Rojo");
    comparator.insertarColor("Verde");
    comparator.insertarColor("Azul");
    comparator.comparar(countryList);
    comparator.imprimir();

    return 0;
}
