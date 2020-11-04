#include "Country.cpp"
#include "pugixml.cpp"
std::vector<Country> countryList;

int main()
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("svg//world.svg");
    pugi::xml_node countries = doc.child("svg");
    for (pugi::xml_node country = countries.child("path"); country; country = country.next_sibling("path"))
    {
        std::string style = country.attribute("style").as_string();
        std::string borderCoords = country.attribute("d").as_string();
        borderCoords = borderCoords.substr(0, borderCoords.length() - 1);
        std::string id = country.attribute("id").as_string();
        std::string countryCode = country.attribute("data-id").as_string();
        std::string countryName = country.attribute("data-name").as_string();
        std::string color = style.substr(0, style.find(';'));
        std::string styleRule = style.substr(style.find(';') + 1, -1);

        std::string coord = "";
        std::vector<std::vector<std::pair<double, double>>> paths;
        std::vector<std::pair<double, double>> coords;
        std::pair<double, double> mainPair(-1, -1);
        bool inPath = false;
        // n
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
                        double coord1 = std::stod(coord.substr(0, coord.find(',')));
                        double coord2 = std::stod(coord.substr(coord.find(',') + 1, -1));
                        //coords.push_back(std::make_pair(coord1, coord2));
                        if (mainPair.first == -1)
                        {
                            mainPair = std::make_pair(coord1, coord2);
                            coords.push_back(mainPair);
                        }
                        else
                        {
                            mainPair = std::make_pair((mainPair.first + coord1), (mainPair.second + coord2));
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
        //curCountry.print();
    }
    std::cout << countryList.size() << std::endl;
    for (Country c : countryList)
    {
        if (c.getId() == "US" || c.getId() == "CA")
        {
            c.print();
        }
    }
    return 0;
}