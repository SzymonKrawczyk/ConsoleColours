//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                      Klasa Edit (plik .cpp)                                          //
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
//              | Wiele mniejszych usprawnien                       |                   //
//              |                                                   |                   //
//  01/12/2019  | Usuniecie zaleznosci od innej klasy               | Szymon Krawczyk   //
//              |                                                   |                   //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

#include "Edit.h"
#include <iostream> // Kontrola bledow
#include <conio.h>  // _getch()

namespace KrawczykS {

    // Funkcja pomocnicza

        namespace {

            int checkIfPositive(int input_) {

                try {

                    if (input_ < 0) {
                        throw "Zla wartosc! (ujemna)";
                    }
                }
                catch (const char* str_) {
                    std::cout << "\n" << str_ << "\n"
                              << "Zmiana wartosci na wartosc dodatnia\n";
                    return -input_;
                }
                return input_;
            }
        }
    //

    // Konstruktory, destruktor, operator=

        Edit::Edit()
            :
                baseColor ()
            ,   _position ({})
            ,   _length   (0)
            ,   _text     ("")
        {}


        Edit::Edit(short x_, short y_, int length_, std::string input_)
            :
                baseColor ()
            ,   _position ({})
            ,   _length   (checkIfPositive(length_))
            ,   _text     (input_)
        {
            _position.X = checkIfPositive(x_);
            _position.Y = checkIfPositive(y_);
        }


        Edit::Edit(const Edit& input_)
            :
                baseColor (input_)
            ,   _position ({})
            ,   _length   (input_._length)
            ,   _text     (input_._text)
        {
            _position.X = input_._position.X;
            _position.Y = input_._position.Y;
        }


        Edit::~Edit() {}


        Edit & Edit::operator=(const Edit& input_) {

            if (this != &input_) {

                baseColor::operator=(input_);
                _position.X = input_._position.X;
                _position.Y = input_._position.Y;
                _length     = input_._length;
                _text       = input_._text;
            }
            return *this;
        }

    //


    // Gettery i Settery

        short Edit::getPositionX() const {

            return _position.X;
        }


        short Edit::getPositionY() const {

            return _position.Y;
        }


        int Edit::getLength() const {

            return _length;
        }


        std::string Edit::getText() const {

            return _text;
        }



        short Edit::setPosition(short x_, short y_) {

            _position.X = checkIfPositive(x_);
            _position.Y = checkIfPositive(y_);
            return _position.X;
        }


        int Edit::setLength(int length_) {

            _length = checkIfPositive(length_);
            return _length;
        }


        std::string Edit::setText(std::string input_) {

            _text = input_;
            return _text;
        }
    //


    // Funkcje do oblugi edycji

        void Edit::showCurrentString() const {      // Pokazywanie odpowiedniej ilosci ostatnich znakow pola _text

            SetConsoleCursorPosition(getHandle(), _position);               // Przesun kursor na poczatek pola edycji

            for (int i = 0; (i < _length-1) && (_text.size() - i); i++) {   // Wypisuj znaki az sie nie skonczy pole edycji lub _text

                if (_text.size() >= _length) {      // Jesli _text nie zmiesci sie w polu edycji,
                                                    //  wypisz ostatnie znaki tak, aby sie zmiescily

                    std::cout << _text[_text.size()-_length + i+1];
                }
                else {                              // Jesli _text zmiesci sie w polu edycji, po prostu wypisz

                    std::cout << _text[i];
                }
            }

        }

        void Edit::display() const {

            SetConsoleCursorPosition(getHandle(), _position);

            SetConsoleTextAttribute(getHandle(), getColor());

            for (int i = 0; i < _length; i++) {     // Tworzenie tla pod pisanie

                std::cout << ' ';
            }

            showCurrentString();        // Wyswietlenie tekstu juz zawartego
        }


        void Edit::userText() {

            char tempch;
            while ((tempch = _getch()) != '\r' && tempch != '\n') {   // Wczytuje znaki do wcisniecia klawisza <Enter>
                                                                      //  lub przejscia na poczatek linii

                _text += tempch;                    // Dodaje kolejny znak do _text
                showCurrentString();                // Pokazuje odpowiednio zawartosc _text w polu edycji
            }
            std::cout << '\n';                      // Przejdz do nowej linii po zakonczeniu wpisywania
        }
    //
}
