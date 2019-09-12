#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include "Fractal.h"

/**
 * Responsible for printing the fractals
 * @param factoryFractal
 */
void printVector(std::vector<Fractal *> &factoryFractal);
/**
 * Responsible for free memory in case of exit
 * @param factoryFractal
 */
void freeVector(std::vector<Fractal *> &factoryFractal);
/**
 * Checks if the input correct, calls to free memory if not
 * @param factoryFractal
 * @param myfile
 * @return
 */
int checkInput(std::vector<Fractal *> &factoryFractal, std::fstream &myfile);

/**
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[])
{
    if(argc !=2)
    {
        std::cerr << "Usage: FractalDrawer <file path>" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::vector<Fractal*> factoryFractal;
    std::string line;
    std::fstream myfile;
    myfile.open(argv[1]);
    if(!myfile.is_open())
    {
        std::cerr << "Invalid input" << std::endl;
        exit(EXIT_FAILURE);
    }
    if(myfile.peek() == std::ifstream::traits_type::eof())
    {
        return 0;
    }
    while(!myfile.eof())
    {
        int type;
        char op = ',';
        int depth;

        std::getline(myfile, line);
        if(line.length() != 3)
        {
            return checkInput(factoryFractal, myfile);
        }
        type = line[0] - '0';
        depth = line[2] - '0';
        if (op != line[1] || type < 1 || type > 3 || depth < 1 || depth > 6)
        {
            return checkInput(factoryFractal, myfile);
        }
        //todo - if return default, return 1 and free memory
        Fractal* fractal = Fractal::factory(type, depth);
        if(fractal == nullptr)
        {
            return checkInput(factoryFractal, myfile);
        }
        factoryFractal.push_back(fractal);

    }
    printVector(factoryFractal);
    myfile.close();
    return 0;
}

int checkInput(std::vector<Fractal *> &factoryFractal, std::fstream &myfile)
{
    myfile.close();
    std::cerr << "Invalid input" << std::endl;
    freeVector(factoryFractal);
    return EXIT_FAILURE;
}

void printVector(std::vector<Fractal *> &factoryFractal)
{
    while(!factoryFractal.empty())
    {
        Fractal* fractal = factoryFractal.back();
        fractal->drawFractal();
        std::cout << "\n";
        factoryFractal.pop_back();
        delete fractal;
    }
}

void freeVector(std::vector<Fractal *> &factoryFractal)
{
    while(!factoryFractal.empty())
    {
        Fractal* fractal = factoryFractal.back();
        factoryFractal.pop_back();
        delete fractal;
    }
}