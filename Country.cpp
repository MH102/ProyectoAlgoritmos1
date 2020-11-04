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
    Country()
    {
    }
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
    std::vector<std::pair<double, double>> sumarVectores(std::vector<std::vector<std::pair<double, double>>> vec1)
    {
        std::vector<std::pair<double, double>> res;
        for (std::vector<std::pair<double, double>> v : vec1)
        {
            for (std::pair<double, double> p : v)
                res.push_back(p);
        }
        return res;
    }
    bool seIntersecan(Country pais)
    {
        for (std::pair<double, double> p1 : sumarVectores(countryBorder))
        {
            for (std::pair<double, double> p2 : sumarVectores(pais.getCountryBorder()))
            {
                if (p1.first - p2.first < 1 && p1.first - p2.first > -1)
                {
                    if (p1.second - p2.second < 1 && p1.second - p2.second > -1)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
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