#include <iostream>
#include <string>
#include <utility>
#include <vector>
class Country
{
private:
    std::string id;
    std::string countryName;
    std::string countryCode;
    std::vector<std::vector<std::pair<double, double>>> countryBorder;
    std::string color;
    std::string styleRule;

public:
    Country(std::string pId, std::string pCountryName, std::string pCountryCode, std::vector<std::vector<std::pair<double, double>>> pCountryBorder, std::string pColor, std::string pStyleRule)
    {
        id = pId;
        countryName = pCountryName;
        countryCode = pCountryCode;
        countryBorder = pCountryBorder;
        color = pColor;
        styleRule = pStyleRule;
    }
    std::string getId()
    {
        return id;
    }
    std::string getCountryName()
    {
        return countryName;
    }
    std::string getCountryCode()
    {
        return countryCode;
    }
    std::vector<std::vector<std::pair<double, double>>> getCountryBorder()
    {
        return countryBorder;
    }
    std::string getColor()
    {
        return color;
    }
    std::string getStyleRule()
    {
        return styleRule;
    }
    void print()
    {
        std::cout << "Id: " << id << std::endl;
        std::cout << "Country Name: " << countryName << std::endl;
        std::cout << "Country Code: " << countryCode << std::endl;
        std::cout << "Border: " << std::endl;
        for (int i = 0; i < countryBorder.size(); i++)
        {
            std::cout << "[";
            for (int j = 0; j < countryBorder.at(i).size(); j++)
            {
                std::cout << "(" << countryBorder.at(i).at(j).first << "," << countryBorder.at(i).at(j).second << ")";
            }
            std::cout << "]" << std::endl;
        }
        std::cout << "Style (color): " << color << std::endl;
        std::cout << "Style (frule): " << styleRule << std::endl;
    }
};