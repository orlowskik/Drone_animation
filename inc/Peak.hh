#pragma once

#include "Cuboid.hh"
#include <fstream>

/*!
 * \file
 * \brief Klasa opisujaca Gore z ostrym szczytem
 *
 * Klasa opisujaca gore z ostrym szczytem
 */


/*!
 * \brief Klasa opisujaca gore z ostrym szczytem
 *
 *  Klasa opisuje pojecie gory z ostrym sczytem w przestrzeni.
 *  Jest to klasa dziedziczaca po klasie Cuboid w trybie 
 *  publicznym. Tworzy figure na bazie deformacji prostopadloscianu.
 */
class Peak: public Cuboid{
    private:

    public:
        /*!
        *   \brief Konstruktor bezparametryczny
        */
        Peak();
        /*!
        *   \brief Destruktor
        */
        ~Peak();
        /*!
        *   \brief Konstruktor parametryczny
        */
        Peak(std::string File1, std::string File2, const Vector3D &V_scale, const Vector3D &V, double angle);
        /*!
        *   \brief Metoda wirtualna odpowiadajaca za zwracanie typu klasy
        */
        virtual const std::string ObjectType() const override {return "Gora z ostrym szczytem";};
        /*!
        *   \brief Metoda znieksztalcajaca prostopadloscian i zapisujaca dane do pliku
        */
        bool Count_Save_GlobalCoor();
};
