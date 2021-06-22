#pragma once

#include "Cuboid.hh"
#include <fstream>


/*!
 * \file
 * \brief Klasa opisujaca Gore z grania
 *
 * Klasa opisujaca gore z grania
 */


/*!
 * \brief Klasa opisujaca gore z grania
 *
 *  Klasa opisuje pojecie gory z grania w przestrzeni.
 *  Jest to klasa dziedziczaca po klasie Cuboid w trybie 
 *  publicznym. Tworzy figure na bazie deformacji prostopadloscianu.
 */
class Slope: public Cuboid{


    public:
        /*!
        *   \brief Konstruktor bezparametryczny
        */
        Slope();
        /*!
        *   \brief Destruktor
        */
        ~Slope();
        /*!
        *   \brief Konstruktor parametryczny
        */
        Slope(std::string File1, std::string File2, const Vector3D &V_scale, const Vector3D &V, double angle);
        /*!
        *   \brief Metoda znieksztalcajaca prostopadloscian i zapisujaca dane do pliku
        */
        bool Count_Save_GlobalCoor();
        /*!
        *   \brief Metoda wirtualna zwracajaca typ klasy
        */
        virtual const std::string ObjectType() const override {return "Gora z dluga grania";};
};