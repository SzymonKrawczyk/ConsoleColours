//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                      Klasa ccolor (plik .h)                                          //
//                                                                                      //
//  Klasa ma za zadanie przechowywac kolory konsoli oraz nadawac je konsoli             //
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
//     ccolor.getColor();            // Zwraca kolor obiektu                            //
//     ccolor.getTextColor();        // Zwraca kolor tekstu obiektu                     //
//     ccolor.getBackgroundColor();  // Zwraca kolor tla tekstu obiektu                 //
//     ccolor.getHandle();           // Zwraca uchwyt obiektu                           //
//                                                                                      //
//      (WORD to tak naprawde unsigned short)                                           //
//      (Ustawianie koloru sprawdza poprawnosc wprowadzonej wartosci)                   //
//     ccolor.setColor(WORD);           // Ustawia i zwraca kolor obiektu               //
//     ccolor.setTextColor(WORD);       // Ustawia i zwraca kolor tekstu obiektu        //
//     ccolor.setBackgroundColor(WORD); // Ustawia i zwraca kolor tla tekstu obiektu    //
//     ccolor.setHandle(HANDLE);        // Ustawia i zwraca uchwyt obiektu              //
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
//    ccolor = WORD;        // Ustawienie pol koloru na wartosc WORD                    //
//    ccolor1 + ccolor2     // Laczenie kolorow (tak naprawde operacja lub na bitach)   //
//    cout << ccolor        // Ustawienie koloru konsoli na wartosc pola _color         //
//    WORD = ccolor         // Konwersja ccolor na WORD (zwrocenie pola _color)         //
//                                                                                      //
//  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
//                                                                                      //
//      Funkcje uzywane z ostream                                                       //
//    SetColor(WORD)            // Zwraca obiekt utworzony na podstawie WORD            //
//    SetColor(const ccolor&)   // Zwraca kopie parametru                               //
//                                                                                      //
//     np.: cout << SetColor(ccolor::Red)                                               //
//          // Ustawia kolor tekstu konsoli na czerwony                                 //
//          //  poniewaz zwraca obiekt ccolor ktory wplywa na konsole                   //
//                                                                                      //
//  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
//                                                                                      //
//    Dolaczony jest rowniez zestaw stalych obiektow z kolorami                         //
//     (szczegoly implementacji w dalszej czesci pliku)                                 //
//                                                                                      //
//      defcolor,                                                                       //
//                                                                                      //
//      white, black,                                                                   //
//      red,   green,   blue,                                                           //
//      cyan,  magenta, yellow,                                                         //
//                                                                                      //
//      intenseWhite, intenseBlack,                                                     //
//      intenseRed,   intenseGreen,   intenseBlue,                                      //
//      intenseCyan,  intenseMagenta, intenseYellow,                                    //
//                                                                                      //
//      backgroundWhite, backgroundBlack,                                               //
//      backgroundRed,   backgroundGreen,   backgroundBlue,                             //
//      backgroundCyan,  backgroundMagenta, backgroundYellow,                           //
//                                                                                      //
//      backgroundIntenseWhite, backgroundIntenseBlack,                                 //
//      backgroundIntenseRed,   backgroundIntenseGreen,   backgroundIntenseBlue,        //
//      backgroundIntenseCyan,  backgroundIntenseMagenta, backgroundIntenseYellow       //
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
//              | Dodanie operatora konwersji na WORD               |                   //
//              |                                                   |                   //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef CCOLORS_H
#define CCOLORS_H

#include "baseColor.h"
#include <iostream>

namespace KrawczykS {

    class ccolor : public baseColor {

    private:
        // nic nowego
    public:

        ccolor(WORD = getDefaultConsoleColor(), HANDLE = getDefaultHandle());
        ccolor(const ccolor&);
        virtual ~ccolor();          // Destruktor wirtualny zapewnia wywolanie destruktorow klas pochodnych
                                    //  dzieki temu zapobieagmy mozliwym bledom, 
                                    //  poniewaz niewywolanie destruktora klasy pochodnej moze prowadzic do np.: wyciekow pamieci

        ccolor& operator= (const ccolor&);
        ccolor& operator= (WORD);

        friend ccolor operator+ (const ccolor&, const ccolor&);             // Laczenie kolorow

        friend std::ostream& operator << (std::ostream&, const ccolor&);    // Obsluga napotkanych obiektow ccolor przez ostream

        operator WORD() const;      // Konwersja ccolor na WORD
        
    };


    ccolor SetColor(WORD);
    ccolor SetColor(const ccolor&);


    // Stale obiekty kolorow (manipulatory, chociaz nie funkcje)

        const ccolor defcolor;                  // Konstruktor bezparametrowy (_color ustawione na _defaultColor) 

        const ccolor white                      (ccolor::White);
        const ccolor intenseWhite               (ccolor::IntenseWhite);
        const ccolor backgroundWhite            (ccolor::BackgroundWhite);
        const ccolor backgroundIntenseWhite     (ccolor::BackgroundIntenseWhite);

        const ccolor black                      (ccolor::Black);
        const ccolor intenseBlack               (ccolor::IntenseBlack);
        const ccolor backgroundBlack            (ccolor::BackgroundBlack);
        const ccolor backgroundIntenseBlack     (ccolor::BackgroundIntenseBlack);

        const ccolor red                        (ccolor::Red);
        const ccolor intenseRed                 (ccolor::IntenseRed);
        const ccolor backgroundRed              (ccolor::BackgroundRed);
        const ccolor backgroundIntenseRed       (ccolor::BackgroundIntenseRed);

        const ccolor green                      (ccolor::Green);
        const ccolor intenseGreen               (ccolor::IntenseGreen);
        const ccolor backgroundGreen            (ccolor::BackgroundGreen);
        const ccolor backgroundIntenseGreen     (ccolor::BackgroundIntenseGreen);

        const ccolor blue                       (ccolor::Blue);
        const ccolor intenseBlue                (ccolor::IntenseBlue);
        const ccolor backgroundBlue             (ccolor::BackgroundBlue);
        const ccolor backgroundIntenseBlue      (ccolor::BackgroundIntenseBlue);

        const ccolor cyan                       (ccolor::Cyan);
        const ccolor intenseCyan                (ccolor::IntenseCyan);
        const ccolor backgroundCyan             (ccolor::BackgroundCyan);
        const ccolor backgroundIntenseCyan      (ccolor::BackgroundIntenseCyan);

        const ccolor magenta                    (ccolor::Magenta);
        const ccolor intenseMagenta             (ccolor::IntenseMagenta);
        const ccolor backgroundMagenta          (ccolor::BackgroundMagenta);
        const ccolor backgroundIntenseMagenta   (ccolor::BackgroundIntenseMagenta);

        const ccolor yellow                     (ccolor::Yellow);
        const ccolor intenseYellow              (ccolor::IntenseYellow);
        const ccolor backgroundYellow           (ccolor::BackgroundYellow);
        const ccolor backgroundIntenseYellow    (ccolor::BackgroundIntenseYellow);

        /*
            //
            // Manipulatory mozna rowniez utworzyc poprzez funkcje, np.:
            //
            //      std::ostream& red(std::ostream& O_) {
            //          SetConsoleTextAttribute(ccolor::getDefaultHandle(), ccolor::Red);
            //          return O_;
            //      }
            //  Jednak dzieki przeciazeniu operatora << tak, by ostream po napotkaniu obiektu ccolor
            //  zmienial kolor konsoli na wartosc pola _color obiektu, zyskujemy bardziej czytelny kod.
            //   Jednoczesnie nie ma przeszkod, by tworzyc wlasne manipulatory poprzez funkcje 
            //   (lub poprzez obiekty ccolor!)
            //
            //
            //  Dzieki przeciazeniu << na dzialania zmiany koloru na kolor zawarty w obiekcie ccolor
            //  mozna manipulatory-funkcje tworzyc rowniez w taki sposob:
            //
            //      std::ostream& myRed(std::ostream& O_) {
            //          O_ << red;  // wykorzystujemy operator << 
            //                      // z obiektem const ccolor red(ccolor::Red);
            //          return O_;
            //      }
            //  
            //  
        */
    //

}

#endif