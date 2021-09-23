//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                      Klasa Edit (plik .h)                                            //
//                                                                                      //
//  Klasa ma za zadanie zarzadzac polem do wprowadzania tekstu                          //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//    Dostepna funkcjonalnosc (z klasy bazowej):                                        //
//                                                                                      //
//     getCurrentConsoleColor();    // Zwracanie aktualnego koloru konsoli              //
//                                                                                      //
//     getDefaultConsoleColor();    // Zwracanie pierwotnego koloru konsoli             //
//                                                                                      //
//     getDefaultHandle();          // Zwracanie standardowego uchwytu                  //
//                                                                                      //
//      //      //      //      //      //      //      //      //      //      //      //
//                                                                                      //
//     Edit.getColor();            // Zwraca kolor obiektu                              //
//     Edit.getTextColor();        // Zwraca kolor tekstu obiektu                       //
//     Edit.getBackgroundColor();  // Zwraca kolor tla tekstu obiektu                   //
//     Edit.getHandle();           // Zwraca uchwyt obiektu                             //
//                                                                                      //
//      (WORD to tak naprawde unsigned short)                                           //
//      (Ustawianie koloru sprawdza poprawnosc wprowadzonej wartosci)                   //
//     Edit.setColor(WORD);           // Ustawia i zwraca kolor obiektu                 //
//     Edit.setTextColor(WORD);       // Ustawia i zwraca kolor tekstu obiektu          //
//     Edit.setBackgroundColor(WORD); // Ustawia i zwraca kolor tla tekstu obiektu      //
//     Edit.setHandle(HANDLE);        // Ustawia i zwraca uchwyt obiektu                //
//                                                                                      //
//  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
//                                                                                      //
//     Enumerator colorList:                                                            //
//                                                                                      //
//      White, Black,                                                                   //
//      Red,   Green,   Blue,                                                           //
//      Cyan,  Magenta, Yellow,                                                         //
//                                                                                      //
//      IntenseWhite, IntenseBlack,                                                     //
//      IntenseRed,   IntenseGreen,   IntenseBlue,                                      //
//      IntenseCyan,  IntenseMagenta, IntenseYellow,                                    //
//                                                                                      //
//      BackgroundWhite, BackgroundBlack,                                               //
//      BackgroundRed,   BackgroundGreen,   BackgroundBlue,                             //
//      BackgroundCyan,  BackgroundMagenta, BackgroundYellow,                           //
//                                                                                      //
//      BackgroundIntenseWhite, BackgroundIntenseBlack,                                 //
//      BackgroundIntenseRed,   BackgroundIntenseGreen,   BackgroundIntenseBlue,        //
//      BackgroundIntenseCyan,  BackgroundIntenseMagenta, BackgroundIntenseYellow       //
//                                                                                      //
//      (szczegoly implementacji dostepne w pliku [ baseColor.h ])                      //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//    Dostepna funkcjonalnosc (z tej klasy):                                            //
//                                                                                      //
//     Edit.display();          // Pokazuje pole edycji w konsoli,                      //
//                              //  wypisuje aktualna zawartosc pola _text              //
//                                                                                      //
//     Edit.userText();         // Dodaje znaki do pola _text, po kazdym znaku          //
//                              //  wypisuje aktualna zawartosc pola _text              //
//                              //  (az do <enter> lub przejscia na poczatek linii)     //
//                                                                                      //
//  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
//                                                                                      //
//     Edit.getPositionX();     // Zwraca pozycje X pola _position                      //
//     Edit.getPositionY();     // Zwraca pozycje Y pola _position                      //
//     Edit.getLength();        // Zwraca szerokosc pola do wpisywania                  //
//     Edit.getText();          // Zwraca pole _text                                    //
//                                                                                      //
//     Edit.setPosition(short, short); // Ustawia pozycje X i Y oraz zwraca pozycje X   //
//     Edit.setLength(int);            // Ustawia i zwraca szerokosc pola do wpisywania //
//     Edit.setText(std::string);      // Ustawia i zwraca pole _text                   //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////
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
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef EDIT_H
#define EDIT_H

#include "baseColor.h"
#include <string>

namespace KrawczykS {

    class Edit : public baseColor {

    private:

        COORD       _position;
        int         _length;
        std::string _text;

        void showCurrentString() const;   // Metoda pomocnicza wykorzystywana przez inne metody

    public:

        Edit();
        Edit(short, short, int, std::string = "");
        Edit(const Edit&);
        virtual ~Edit();            // Destruktor wirtualny zapewnia wywolanie destruktorow klas pochodnych
                                    //  dzieki temu zapobieagmy mozliwym bledom, 
                                    //  poniewaz niewywolanie destruktora klasy pochodnej moze prowadzic do np.: wyciekow pamieci

        Edit& operator= (const Edit&);

        short       getPositionX() const;
        short       getPositionY() const;
        int         getLength   () const;
        std::string getText     () const;

        short       setPosition (short = 0, short = 0);
        int         setLength   (int   = 6);
        std::string setText     (std::string = "");

        void display() const;
        void userText();
    };
}


#endif