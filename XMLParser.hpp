#include "pugixml.cpp"
#include "Country.hpp"

class XMLParser
{
private:
    pugi::xml_document doc;
    pugi::xml_parse_result result;
    pugi::xml_node countries;

public:
    XMLParser()
    {
        result = doc.load_file("svg//world.svg");
        countries = doc.child("svg");
    }
    vector<Country> parseToCountries()
    {
        vector<Country> countryList;
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

            vector<vector<pair<double, double>>> coordinates = parseCoords(borderCoords);
            Country curCountry = Country(id, countryName, countryCode, coordinates, color, styleRule);
            countryList.push_back(curCountry);
        }

        return countryList;
    }
    vector<vector<pair<double, double>>> parseCoords(string borderCoords)
    {
        vector<vector<pair<double, double>>> paths;
        string coord = "";
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
        return paths;
    }
};