//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                      Klasa abstrakcyjna baseColor (plik .cpp)                        //
//                                                                                      //
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
//              |                                                   |                   //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

#include "baseColor.h"
#include <iostream> // Informacje z kontroli bledow

namespace KrawczykS {

    //  Elementy statyczne
    //
    //      Pola statyczne, poniewaz maja byc wspolne dla wszystkich obiektow
    //
    //      Metody statyczne, poniewaz:
    //       ) sa wykorzystywane przez zmienne statyczne (przed istnieniem jakichkolwiek obiektow)
    //       ) nie potrzebuja this, 
    //       ) nie moga byc zaprzyjaznione poniewaz chce zaby byly dziedziczone
    //

        HANDLE baseColor::_defHc = GetStdHandle(STD_OUTPUT_HANDLE);
        const WORD baseColor::_defaultColor = getCurrentConsoleColor();

        WORD baseColor::getCurrentConsoleColor() {

            CONSOLE_SCREEN_BUFFER_INFO temp;                        // [ https://docs.microsoft.com/en-us/windows/console/console-screen-buffer-info-str ]
            GetConsoleScreenBufferInfo(getDefaultHandle(), &temp);  // [ https://docs.microsoft.com/en-us/windows/console/getconsolescreenbufferinfo ]

            return temp.wAttributes;                                // pole struktury CONSOLE_SCREEN_BUFFER_INFO zawierajacego atrybuty konsoli
        }

        WORD baseColor::getDefaultConsoleColor() {

            return _defaultColor;
        }

        HANDLE baseColor::getDefaultHandle() {

            return _defHc;
        }


        // Funkcja pomocnicza do sprawdzenia poprawnosci wprowadzanego koloru

            WORD baseColor::checkIfGoodColour(WORD input_) {

                try {

                    if (0x00 <= input_ && input_ <= 0xFF) {     // Poniewaz kolor rozpisany jest na 8 bitach, 
                                                                // maksymalna wartosc to 255, a minimalna 0
                        return input_;
                    }
                    else {

                        throw "Niepoprawna wartosc koloru";
                    }

                }
                catch (const char* str) {

                    std::cout << "\n" << str << "\nUstawienie koloru na domyslny\n";
                    return _defaultColor;
                }

            }
        //
    //


    // Konstruktory i destruktor, operator=

        baseColor::baseColor(WORD color_, HANDLE handle_) 
            :
                _color          (checkIfGoodColour(color_))
            ,   _textColor      (_color & 0x0F) // _color jest juz utworzone oraz poprawne, wiec mozna wykorzystac do nadania wartosci kolejnych pol
            ,   _textBackground (_color & 0xF0) // operacja AND pobiera tylko ta czesc koloru, ktora jest potrzebna
            ,   _hc             (handle_)
        {}


        baseColor::baseColor(const baseColor& input_)
            :
                _color          (checkIfGoodColour(input_._color))
            ,   _textColor      (_color & 0x0F)
            ,   _textBackground (_color & 0xF0)
            ,   _hc             (input_._hc)
        {}

        baseColor::~baseColor() {}

        baseColor& baseColor::operator=(const baseColor& input_) {

            if (this != &input_) {

                _color          = checkIfGoodColour(input_._color);
                _textColor      = _color & 0x0F;
                _textBackground = _color & 0xF0;
                _hc             = input_._hc;
            }
            return *this;
        }
    //

    
    // Gettery i Settery

        WORD baseColor::getColor() const {

            return _color;
        }

        WORD baseColor::getTextColor() const {

            return _textColor;
        }
        
        WORD baseColor::getBackgroundColor() const {

            return _textBackground;
        }

        HANDLE baseColor::getHandle() const {

            return _hc;
        }


        WORD baseColor::setColor(WORD input_) {

            _color          = checkIfGoodColour(input_);
            _textColor      = _color & 0x0F;                // Aktualizacja pozostalych pol na podstawie zmiany jednego
            _textBackground = _color & 0xF0;
            return _color;
        }

        WORD baseColor::setTextColor(WORD input_) {

            _textColor = checkIfGoodColour(input_) & 0x0F;
            _color     = _textColor | _textBackground;      // Aktualizacja _color po zmianie _textColor
                                                            //  (_textBackground bez zmian)
            return _textColor;
        }

        WORD baseColor::setBackgroundColor(WORD input_) {

            if (input_ & 0x0F) {        // Jezeli podany kolor jest kolorem tekstu, zostanie
                                        //  przesuniety bitowo i bedzie odpowiadal za tlo
                                        //  Pozwala to na np. setTextBackground(ccolor::Red) oraz setTextBackground(ccolor::BackgroundRed)
                                        //   (Obie wersje dzialaja tak samo)
                input_ = input_ << 4;
            }
            _textBackground = checkIfGoodColour(input_) & 0xF0;
            _color = _textColor | _textBackground;
            return _textBackground;
        }

        HANDLE baseColor::setHandle(HANDLE input_) {

            _hc = input_;
            return _hc;
        }

    //




}