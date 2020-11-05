#include "Country.hpp"
#include "pugixml.cpp"
using namespace std;

vector<Country> countryList;

int main()
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("svg//world.svg");
    pugi::xml_node countries = doc.child("svg");

    // Parsear de XML
    for (pugi::xml_node country = countries.child("path"); country; country = country.next_sibling("path"))
    {
        string style = country.attribute("style").as_string();
        string borderCoords = country.attribute("d").as_string();
        borderCoords = borderCoords.substr(0, borderCoords.length() - 1);
        string id = country.attribute("id").as_string();
        string countryCode = country.attribute("data-id").as_string();
        string countryName = country.attribute("data-name").as_string();
        string color = style.substr(0, style.find(';'));
        string styleRule = style.substr(style.find(';') + 1, -1);

        string coord = "";
        vector<vector<pair<double, double>>> paths;
        vector<pair<double, double>> coords;
        pair<double, double> mainPair(-1, -1);
        bool inPath = false;
        for (int i = 0; i < borderCoords.length(); i++)
        {
            if (inPath)
            {
                if (borderCoords.at(i) == 'z')
                {
                    inPath = false;
                    paths.push_back(coords);
                    coords.clear();
                }
                else
                {
                    if (borderCoords.at(i) == ' ')
                    {
                        double coord1 = stod(coord.substr(0, coord.find(',')));
                        double coord2 = stod(coord.substr(coord.find(',') + 1, -1));
                        if (mainPair.first == -1)
                        {
                            mainPair = make_pair(coord1, coord2);
                            coords.push_back(mainPair);
                        }
                        else
                        {
                            mainPair = make_pair((mainPair.first + coord1), (mainPair.second + coord2));
                            coords.push_back(mainPair);
                        }

                        coord = "";
                    }
                    else
                    {
                        coord += borderCoords.at(i);
                    }
                }
            }
            else
            {
                if (borderCoords.at(i) == 'm')
                {
                    inPath = true;
                    i++;
                }
            }
        }
        paths.push_back(coords);
        Country curCountry = Country(id, countryName, countryCode, paths, color, styleRule);
        countryList.push_back(curCountry);
    }
    // cout << countryList.size() << endl;
    Country pais1;
    Country pais2;
    for (Country countryIndex : countryList)
    {
        if (countryIndex.getCountryName() == "Costa Rica")
        {
            // countryIndex.print();
            pais1 = countryIndex;
        }
        if (countryIndex.getCountryName() == "Panama")
        {
            // countryIndex.print();
            pais2 = countryIndex;
        }
    }
    cout << ((pais1.seIntersecan(pais2)) ? "Se intersecan" : "No se intersecan") << endl;
    return 0;
}
