//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//                      Klasa abstrakcyjna baseColor (plik .h)                          //
//                                                                                      //
//  Klasa ma za zadanie stanowic klase bazowa dla klas wykorzystujacych kolory          //
//   oraz HANDLE                                                                        //
//  (Klasa abstrakcyjna, wiec nie mozna tworzyc jej obiektow)                           //
//                                                                                      //
//  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
//                                                                                      //
//    Dostepna funkcjonalnosc:                                                          //
//                                                                                      //
//     getCurrentConsoleColor();    // Zwracanie aktualnego koloru konsoli              //
//                                                                                      //
//     getDefaultConsoleColor();    // Zwracanie pierwotnego koloru konsoli             //
//                                                                                      //
//     getDefaultHandle();          // Zwracanie standardowego uchwytu                  //
//                                                                                      //
//      //      //      //      //      //      //      //      //      //      //      //
//                                                                                      //
//     baseColor.getColor();            // Zwraca kolor obiektu                         //
//     baseColor.getTextColor();        // Zwraca kolor tekstu obiektu                  //
//     baseColor.getBackgroundColor();  // Zwraca kolor tla tekstu obiektu              //
//     baseColor.getHandle();           // Zwraca uchwyt obiektu                        //
//                                                                                      //
//      (WORD to tak naprawde unsigned short)                                           //
//      (Ustawianie koloru sprawdza poprawnosc wprowadzonej wartosci)                   //
//     baseColor.setColor(WORD);           // Ustawia i zwraca kolor obiektu            //
//     baseColor.setTextColor(WORD);       // Ustawia i zwraca kolor tekstu obiektu     //
//     baseColor.setBackgroundColor(WORD); // Ustawia i zwraca kolor tla tekstu obiektu //
//     baseColor.setHandle(HANDLE);        // Ustawia i zwraca uchwyt obiektu           //
//                                                                                      //
//  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
//                                                                                      //
//     Enumerator colorList, ktory bedzie widoczny w klasach pochodnych:                //
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
//      (szczegoly implementacji dostepne w dalszej czesci pliku)                       //
//                                                                                      //
//  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  //
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

#ifndef BASECOLOR_H
#define BASECOLOR_H

#include <Windows.h>

namespace KrawczykS {

    class baseColor {
    private:

        WORD   _color;
        WORD   _textColor;
        WORD   _textBackground;
        HANDLE _hc;

        static       HANDLE _defHc;             // Jeden uchwyt domyslny dla wszystkich obiektow
        static const WORD   _defaultColor;      // Kolor poczatkowy konsoli

    protected:

        static WORD   checkIfGoodColour(WORD);  // Funkcja pomocnicza sprawdzajaca poprawnosc wprowadzanego koloru

    public:

        static WORD   getCurrentConsoleColor(); // Zwracanie aktualnego koloru
        static WORD   getDefaultConsoleColor(); // Zwracanie poczatkowego koloru
        static HANDLE getDefaultHandle();       // Zwracanie standardowego uchwytu


        baseColor(WORD = _defaultColor, HANDLE = _defHc);
        baseColor(const baseColor&);
        virtual ~baseColor() = 0;               // Destruktor wirtualny zapewnia wywolanie destruktorow klas pochodnych
                                                //  dzieki temu zapobieagmy mozliwym bledom, 
                                                //  poniewaz niewywolanie destruktora klasy pochodnej moze prowadzic do np.: wyciekow pamieci
                                                // 
                                                // W pelni wirtualny (poprzez = 0) destruktor sprawia, ze klasa staje sie klasa abstrakcyjna
                                                //  przez co nie mozna tworzyc obiektow jej typu
                                                //  (jest przeznaczona do bycia klasa bazowa)

        baseColor& operator=(const baseColor&);


        WORD   getColor          () const;
        WORD   getTextColor      () const;
        WORD   getBackgroundColor() const;
        HANDLE getHandle         () const;

        WORD   setColor          (WORD);
        WORD   setTextColor      (WORD);
        WORD   setBackgroundColor(WORD);
        HANDLE setHandle         (HANDLE);




        enum colorList {    // Ten enumerator bedzie widoczny w klasach pochodnych

            White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
            Black = FOREGROUND_RED & FOREGROUND_GREEN & FOREGROUND_BLUE,

            Red   = FOREGROUND_RED,
            Green = FOREGROUND_GREEN,
            Blue  = FOREGROUND_BLUE,

            Cyan    = FOREGROUND_GREEN | FOREGROUND_BLUE,
            Magenta = FOREGROUND_RED   | FOREGROUND_BLUE,
            Yellow  = FOREGROUND_RED   | FOREGROUND_GREEN,


            IntenseWhite = (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE) | FOREGROUND_INTENSITY,
            IntenseBlack = (FOREGROUND_RED & FOREGROUND_GREEN & FOREGROUND_BLUE) | FOREGROUND_INTENSITY,

            IntenseRed   = FOREGROUND_RED   | FOREGROUND_INTENSITY,
            IntenseGreen = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
            IntenseBlue  = FOREGROUND_BLUE  | FOREGROUND_INTENSITY,

            IntenseCyan    = FOREGROUND_GREEN | FOREGROUND_BLUE  | FOREGROUND_INTENSITY,
            IntenseMagenta = FOREGROUND_RED   | FOREGROUND_BLUE  | FOREGROUND_INTENSITY,
            IntenseYellow  = FOREGROUND_RED   | FOREGROUND_GREEN | FOREGROUND_INTENSITY,



            BackgroundWhite = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
            BackgroundBlack = BACKGROUND_RED & BACKGROUND_GREEN & BACKGROUND_BLUE,

            BackgroundRed   = BACKGROUND_RED,
            BackgroundGreen = BACKGROUND_GREEN,
            BackgroundBlue  = BACKGROUND_BLUE,

            BackgroundCyan    = BACKGROUND_GREEN | BACKGROUND_BLUE,
            BackgroundMagenta = BACKGROUND_RED   | BACKGROUND_BLUE,
            BackgroundYellow  = BACKGROUND_RED   | BACKGROUND_GREEN,


            BackgroundIntenseWhite = (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE) | BACKGROUND_INTENSITY,
            BackgroundIntenseBlack = (BACKGROUND_RED & BACKGROUND_GREEN & BACKGROUND_BLUE) | BACKGROUND_INTENSITY,

            BackgroundIntenseRed   = BACKGROUND_RED   | BACKGROUND_INTENSITY,
            BackgroundIntenseGreen = BACKGROUND_GREEN | BACKGROUND_INTENSITY,
            BackgroundIntenseBlue  = BACKGROUND_BLUE  | BACKGROUND_INTENSITY,

            BackgroundIntenseCyan    = BACKGROUND_GREEN | BACKGROUND_BLUE  | BACKGROUND_INTENSITY,
            BackgroundIntenseMagenta = BACKGROUND_RED   | BACKGROUND_BLUE  | BACKGROUND_INTENSITY,
            BackgroundIntenseYellow  = BACKGROUND_RED   | BACKGROUND_GREEN | BACKGROUND_INTENSITY,
        };

    };
}

#endif