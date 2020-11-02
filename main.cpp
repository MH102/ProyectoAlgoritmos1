#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "pugixml.cpp"

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
        std::string countryCode = country.attribute("data-name").as_string();
        std::string countryName = country.attribute("data-id").as_string();
        std::string color = style.substr(0, style.find(';'));
        std::string styleRule = style.substr(style.find(';') + 1, -1);

        std::string coord = "";
        std::vector<std::vector<std::pair<double, double>>> paths;
        std::vector<std::pair<double, double>> coords;
        std::pair<double, double> mainPair(-1, -1);
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
                            coords.push_back(std::make_pair(mainPair.first + coord1, mainPair.second + coord2));
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
        std::cout << "Id: " << id << std::endl;
        std::cout << "Country Code: " << countryCode << std::endl;
        std::cout << "Country Name: " << countryName << std::endl;
        std::cout << "Border: " << std::endl;
        for (int i = 0; i < paths.size(); i++)
        {
            std::cout << "[";
            for (int j = 0; j < paths.at(i).size(); j++)
            {
                std::cout << "(" << paths.at(i).at(j).first << "," << paths.at(i).at(j).second << ")";
            }
            std::cout << "]" << std::endl;
        }
        std::cout << "Style (color): " << color << std::endl;
        std::cout << "Style (frule): " << styleRule << std::endl;
    }
    return 0;
}