#pragma once

#include <memory>
#include "Vector3D.hh"

/*!
 * \file
 * \brief Klasa abstrakcyjna opisujaca obiekty sceny
 *
 * Klasa abstrakcyjna opisujaca obiekty sceny
 */


/*!
 * \brief Klasa abstrakcyjna opisujaca obiekty sceny
 *
 *  Klasa abstrakcyjna opisujaca obiekty sceny. Jest klasa
 *  bazowa dla klas Drone oraz Solid. Opisuje wszystkie bryly,
 *  ktore moga byc umieszczane na Scenie. Traktuje kazdy obiekt
 *  w taki sam sposob. Nie posiada wlasnych pol z wartosciami.
 *  Podstawa jej istnienia sa metody wirtualne, ktore udostepnia
 *  klasom dziedziczacym.
 */
class SceneObject{

    public :
        /*!
        *   \brief Metoda wirtualna zwracajaca typ klasy
        */
        virtual const std::string ObjectType() const {return "SceneObject";};
        /*!
        *   \brief Metoda wirtualna zwracajaca sciezke do pliku z docelowa bryla
        */
        virtual const std::string& TakeFilename_FinalSolid() const = 0;
        /*!
        *   \brief Metoda wirtualna zwracajaca wektor polozenia
        */
        virtual const Vector3D& Take() const = 0;
        /*!
        *   \brief Metoda wirtualna badania kolizyjnosci
        */
        virtual double  Check_Collision(std::shared_ptr<SceneObject>&Obstacle) const = 0;

};
