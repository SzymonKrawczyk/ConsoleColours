//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//              Klasy ccolor i edit (plik pokazujacy mozliwosci klas)                   //
//                                                                                      //
//                                                                                      //
//                                                                                      //
//  Autor: Szymon Krawczyk                                                              //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
// Changelog:                                                                           //
//  Data        |  Zmiany                                           | Przez kogo        //
// -------------|-------------------------------------------------- |------------------ //
//  26/11/2019  | Utworzenie programu                               | Szymon Krawczyk   //
//              |                                                   |                   //
//  30/11/2019  | Dodanie komentarzy                                | Szymon Krawczyk   //
//              | Rozbudowa programu                                |                   //
//              |                                                   |                   //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "ccolor.h"
#include "edit.h"


using std::cout;
using std::cin;
using KrawczykS::ccolor;
using KrawczykS::Edit;


// Kolory

    using KrawczykS::white;
    using KrawczykS::intenseWhite;
    using KrawczykS::backgroundWhite;
    using KrawczykS::backgroundIntenseWhite;

    using KrawczykS::black;
    using KrawczykS::intenseBlack;
    using KrawczykS::backgroundBlack;
    using KrawczykS::backgroundIntenseBlack;

    using KrawczykS::red;
    using KrawczykS::intenseRed;
    using KrawczykS::backgroundRed;
    using KrawczykS::backgroundIntenseRed;

    using KrawczykS::green;
    using KrawczykS::intenseGreen;
    using KrawczykS::backgroundGreen;
    using KrawczykS::backgroundIntenseGreen;

    using KrawczykS::blue;
    using KrawczykS::intenseBlue;
    using KrawczykS::backgroundBlue;
    using KrawczykS::backgroundIntenseBlue;

    using KrawczykS::cyan;
    using KrawczykS::intenseCyan;
    using KrawczykS::backgroundCyan;
    using KrawczykS::backgroundIntenseCyan;

    using KrawczykS::magenta;
    using KrawczykS::intenseMagenta;
    using KrawczykS::backgroundMagenta;
    using KrawczykS::backgroundIntenseMagenta;

    using KrawczykS::yellow;
    using KrawczykS::intenseYellow;
    using KrawczykS::backgroundYellow;
    using KrawczykS::backgroundIntenseYellow;

    using KrawczykS::defcolor;
//


// Przyklady manipulatorow

    std::ostream& MyRed(std::ostream& O_) {
        O_ << red;
        return O_;
    }

    std::ostream& MyGreen(std::ostream& O_) {
        SetConsoleTextAttribute(ccolor::getDefaultHandle(), ccolor::Green);
        return O_;
    }

    std::ostream& MyRed2(std::ostream& O_) {
        O_ << red+backgroundWhite;
        return O_;
    }
//

int main() {

    cout << "Oto wszystkie kolory: \n" <<

        white << "0" <<
        intenseWhite << "0" <<
        backgroundWhite << "0" <<
        backgroundIntenseWhite << "0" <<

        black << "1" <<
        intenseBlack << "1" <<
        backgroundBlack << "1" <<
        backgroundIntenseBlack << "1" <<

        red << "2" <<
        intenseRed << "2" <<
        backgroundRed << "2" <<
        backgroundIntenseRed << "2" <<

        green << "3" <<
        intenseGreen << "3" <<
        backgroundGreen << "3" <<
        backgroundIntenseGreen << "3" <<

        blue << "4" <<
        intenseBlue << "4" <<
        backgroundBlue << "4" <<
        backgroundIntenseBlue << "4" <<

        cyan << "5" <<
        intenseCyan << "5" <<
        backgroundCyan << "5" <<
        backgroundIntenseCyan << "5" <<

        magenta << "6" <<
        intenseMagenta << "6" <<
        backgroundMagenta << "6" <<
        backgroundIntenseMagenta << "6" <<

        yellow << "7" <<
        intenseYellow << "7" <<
        backgroundYellow << "7" <<
        backgroundIntenseYellow << "7" <<

        defcolor;

    cout << "\n(Ich nazwy dostepne sa w dokumentacji)\n\n";
    cout << "Mozemy uzywac je naprzemiennie oraz je laczyc (np tlo oraz kolor tekstu):\n\n";

    cout << MyRed << " Hello " << MyGreen << " World!\n" 
         << "   (nowy kolor obowiazuje do jego zmiany, aby przywrocic pierwotny nalezy uzyc defcolor)\n\n" << defcolor;
    cout << "Laczenie kolorow odbywa sie poprzez znak +, np.: red+backgroundWhite\n";
    cout << "  " << MyRed2 << ">Hello user!\n" << SetColor(defcolor) << "\n";   // Dodatkowo korzystamy z wlasnych manipulatorow

    cout << "(Oczywiscie mozna tworzyc oraz korzystac z wlasnych manipulatorow, \nchociaz jezeli chcemy tylko zmienic kolory, poslugiwanie sie zestawem dostarczonych obiektow kolorow jest prostsze)\n\n";

    cout << "Dodatkowo mozna definiowac wlasne kolory a potem ich uzywac: \n";
    ccolor MyMix = green + backgroundIntenseWhite;
    cout << MyMix << "ccolor MyMix = green + backgroundIntenseWhite;" << ccolor(ccolor::getDefaultConsoleColor());  // Inny sposob na defcolor (bardziej nieczytelny)

    cout << "\nZmieniajac np kolor tla, kolor tekstu pozostanie bez zmian: \n";
    MyMix.setBackgroundColor(blue);
    cout << MyMix << "MyMix.setBackgroundColor(blue);" << defcolor;

    /* - - - - -*/
    cout << "\n\n<Enter aby kontynuowac>";
    cin.get();
    /* - - - - -*/

    cout << "\n Pole edit sluzace do wpisywania ciagu znakow \n(chociaz widac tylko pewna ilosc ostatnio wproadzonych znakow, caly ciag jest zapisywany)\n";
    std::string s;
    Edit e;
    e.setPosition(8, 25);
    e.setLength(10);
    e.setText("Awesome colors");
    e.setTextColor(Edit::White);        // enumerator
    e.setBackgroundColor(Edit::Blue);   // enumerator
    e.display();
    e.userText();
    s = e.getText();

    cout << s << defcolor << "\n";

    Edit e2;
    e2.setPosition(10, 28);
    e2.setLength(15);
    e2.setText("Thank you");
    e2.setTextColor(black);                 // obiekt ccolor konwertowany na WORD
    e2.setBackgroundColor(backgroundWhite); // obiekt ccolor konwertowany na WORD
    e2.display();
    e2.userText();
    s = e2.getText();
    cout << s << defcolor << "\n";

    /* - - - - -*/
    cout << "\n<Koniec>";
    cin.get();
    /* - - - - -*/

    return 0;
}