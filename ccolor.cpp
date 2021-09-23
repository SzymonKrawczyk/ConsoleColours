//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                      Klasa ccolor (plik .cpp)                                        //
//                                                                                      //
//  Autor: Szymon Krawczyk                                                              //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
// Changelog:                                                                           //
//  Data        |  Zmiany                                           | Przez kogo        //
// -------------|-------------------------------------------------- |------------------ //
//  26/11/2019  | Utworzenie klasy                                  | Szymon Krawczyk   //
//              |                                                   |                   //
//  30/11/2019  | Dodanie komentarzy                                | Szymon Krawczyk   //
//              | Dodanie operatora konwersji na WORD               |                   //
//              |                                                   |                   //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

#include "ccolor.h"

namespace KrawczykS {

    // Konstruktowy i destruktor, operatory =

        ccolor::ccolor(WORD input_, HANDLE handle_)
            :
            baseColor(input_, handle_)
        {}

        ccolor::ccolor(const ccolor& input_)
            :
            baseColor(input_)
        {}

        ccolor::~ccolor() {}
       

        ccolor& ccolor::operator=(const ccolor& C_) {

            if (this != &C_) {
                baseColor::operator=(C_);
            }

            return *this;
        }

        ccolor & ccolor::operator=(WORD input_) {

            setColor(checkIfGoodColour(input_));
            return *this;
        }
    //


    // Ustawienie koloru poprzez funkcje

        ccolor SetColor(WORD input_) {

            ccolor temp(input_);
            SetConsoleTextAttribute(temp.getHandle(), temp.getColor()); // Mozemy uzyc tej funkcji takze osobno
            return temp;
        }

        ccolor SetColor(const ccolor& input_) {

            ccolor temp(input_);
            SetConsoleTextAttribute(temp.getHandle(), temp.getColor()); // Mozemy uzyc tej funkcji takze osobno
            return temp;
        }
    //

    
    // Operator+ dla laczenia kolorow (glownie chodzi o kolor tekstu i tla)

        ccolor operator+(const ccolor &C1_, const ccolor &C2_) {

            return ccolor(C1_.getColor() | C2_.getColor());
        }
    //


    // Obsluga napotkanych obiektow przez ostream (ustawienie koloru)

        std::ostream & operator<<(std::ostream& O_, const ccolor& C_) {

            SetConsoleTextAttribute(C_.getHandle(), C_.getColor());
            return O_;
        }
    //

    // Operator konwersji na WORD

        ccolor::operator WORD() const{

            return getColor();
        }
    //

}