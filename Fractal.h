#ifndef EX2_FRACTAL_H
#define EX2_FRACTAL_H
#include <array>

/**
 *Abstract class
 */
class Fractal
{

public:
    /**
     *Virtual method - responsible for drawing the fractal
     */
    virtual void drawFractal() = 0;
    /**
     * Destructor - default
     */
    virtual ~Fractal() = default;
    /**
     *Factory method - responsible for creating fractals
     * @param type
     * @param depth
     * @return
     */
    static Fractal* factory(int& type, int& depth);
    /**
     * Operator Overloading  - default
     * @param other
     * @return
     */
    Fractal& operator=(const Fractal& other) = default;
    /**
     * Copy Constructor - default
     * @param other
     */
    Fractal(const Fractal &other) = default;
    /**
     * Move Constructor - default
     * @param other
     */
    Fractal(Fractal && other) = default;


protected:
    int _depth;
    /**
     * Constructor
     * @param depth - depth of the recursion
     */
    explicit Fractal(int &depth):_depth(depth){}

};
//***************************************SierpinskiCarpet*******************************************
/**
 * class SierpinskiCarpet
 */
class SierpinskiCarpet:public Fractal
{
public:
    /**
     *Constructor
     * @param depth
     */
     explicit SierpinskiCarpet(int &depth);

    /**
     *Destructor
     */
     ~SierpinskiCarpet() override;
     /**
      * Copy Constructor
      * @param other
      * @return
      */
     SierpinskiCarpet& operator=(const SierpinskiCarpet& other) = default;

    /**
     * Copy Constructor
     * @param other
     */
     SierpinskiCarpet(const SierpinskiCarpet &other) = default;
     /**
      * Move Constructor
      * @param other
      */
     SierpinskiCarpet(SierpinskiCarpet && other) = default;
    /**
    *Responsible for drawing the fractal
    */
     void drawFractal() override;

private:
    /**
     *Helper method for printing the relevant fractal
     * @param xCor
     * @param yCor
     * @return
     */
    bool _carpetHelper(int xCor, int yCor);
};
//**************************************SierpinskiSieve********************************************
/**
 * class SierpinskiSieve
 */
class SierpinskiSieve:public Fractal
{
public:
    /**
     *Constructor
     * @param depth
     */
    explicit SierpinskiSieve(int& depth);
    /**
     *Destructor
     */
    ~SierpinskiSieve() override;
    /**
     *Copy Constructor
     */
     SierpinskiSieve(SierpinskiSieve& other) = default;
     /**
      * Move Constructor
      * @param other
      */
     SierpinskiSieve(SierpinskiSieve && other) = default;
    /**
    *Responsible for drawing the fractal
    */
    void drawFractal() override;

private:
    /**
     *Helper method for printing the relevant fractal
     * @param xCor
     * @param yCor
     * @return
     */
    bool _sieveHelper(int xCor, int yCor);
};
//**************************************CantorDust************************************************
/**
 *class CantorDust
 */
class CantorDust:public Fractal
{
public:
    /**
     *Constructor
     * @param depth
     */
    explicit CantorDust(int& depth);
//    CantorDust(CantorDust& other);
    /**
     *Destructor
     */
    ~CantorDust() override;
    /**
     * Copy Constructor
     * @param other
     */
    CantorDust(CantorDust& other) = default;
    /**
     * Move Constructor
     * @param other
     */
    CantorDust(CantorDust && other) = default;
    /**
     *Responsible for drawing the fractal
     */
    void drawFractal() override;

private:
    /**
     *Helper method for printing the relevant fractal
     * @param xCor
     * @param yCor
     * @return
     */
    bool _dustHelper(int xCor, int yCor);
};

#endif //EX2_FRACTAL_H
