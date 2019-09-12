#include "Fractal.h"
#include <iostream>
#include <math.h>
//**************************************Factral********************************************
/**
 * Factory method - responsible for creating fractals objects
 * @param type
 * @param depth
 * @return
 */
Fractal* Fractal::factory(int& type, int& depth)
{
    switch (type)
    {
        case(1):
            return new SierpinskiCarpet(depth);
        case(2):
            return new SierpinskiSieve(depth);
        case(3):
            return new CantorDust(depth);
        default:
            return nullptr;
    }
}
//**********************************SierpinskiCarpet***************************************
/**
 * Constructor
 * @param depth
 */
SierpinskiCarpet::SierpinskiCarpet(int& depth):Fractal(depth)
{
}

/**
 *Destructor
 */
SierpinskiCarpet::~SierpinskiCarpet() = default;

/**
 * Helper method for printing the relevant fractal
 * @param xCor
 * @param yCor
 * @return
 */
bool SierpinskiCarpet::_carpetHelper(int xCor, int yCor)
{
    while(true)
    {
        if(xCor == 0 || yCor == 0)
        {
            return true;
        }
        else
        {
            if (xCor % 3 == 1 && yCor % 3 == 1)
            {
                return false;
            }
        }

        xCor /= 3;
        yCor /= 3;

        _carpetHelper(xCor, yCor);
    }
}
/**
 * Responsible for drawing the fractal
 */
void SierpinskiCarpet::drawFractal()
{
    for(int i = 0; i < (pow(3, this->_depth)); i++)
    {
        for(int j = 0; j < (pow(3, this->_depth)); j++)
        {
            if(this->_carpetHelper(i, j))
            {
                std::cout << '#';
            }
            else
            {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}
//***************************************CantorDust*****************************************
/**
 * Constructor
 * @param depth
 */
CantorDust::CantorDust(int& depth):Fractal(depth)
{
}

/**
 * Destructor
 */
CantorDust::~CantorDust() = default;
/**
 * Helper method for printing the relevant fractal
 * @param xCor
 * @param yCor
 * @return
 */
bool CantorDust::_dustHelper(int xCor, int yCor)
{
    while(true)
    {
        if((xCor == 0 && yCor != 1) && yCor == 0)
        {
            return true;
        }
        else
        {
            if (xCor % 3 == 1 || yCor % 3 == 1)
            {
                return false;
            }
        }

        xCor /= 3;
        yCor /= 3;

        _dustHelper(xCor, yCor);
    }
}
/**
 *Responsible for drawing the fractal
 */
void CantorDust::drawFractal()
{
    for(int i = 0; i < (pow(3, this->_depth)); i++)
    {
        for(int j = 0; j < (pow(3, this->_depth)); j++)
        {
            if(this->_dustHelper(i, j))
            {
                std::cout << '#';
            }
            else
            {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}
//**************************************SierpinskiSieve***************************************
/**
 *Constructor
 * @param depth
 */
SierpinskiSieve::SierpinskiSieve(int &depth):Fractal(depth)
{
}

/**
 *Destructor
 */
SierpinskiSieve::~SierpinskiSieve() = default;
/**
 * Helper method for printing the relevant fractal
 * @param xCor
 * @param yCor
 * @return
 */
bool SierpinskiSieve::_sieveHelper(int xCor, int yCor)
{
    while(true)
    {
        if(xCor == 0 || yCor == 0)
        {
            return true;
        }
        else
        {
            if (xCor % 2 == 1 && yCor % 2 == 1)
            {
                return false;
            }
        }
        xCor /= 2;
        yCor /= 2;

        _sieveHelper(xCor, yCor);
    }
}

/**
 * Responsible for drawing the fractal
 */
void SierpinskiSieve::drawFractal()
{
    for(int i = 0; i < (pow(2, this->_depth)); i++)
    {
        for(int j = 0; j < (pow(2, this->_depth)); j++)
        {
            if(this->_sieveHelper(i, j))
            {
                std::cout << '#';
            }
            else
            {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}