
#include <cstdlib> 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int sadrzi(int pobjede[], int kvadrat) {
    for (int i = 0; i < 9; i++) {
        if (pobjede[i] == kvadrat) {
            return 1;
        }
    }
    return 0;
}

int getKoordinateX(int kvadrat) {
    if (kvadrat <= 3) {
        return 0;
    }
    else if (kvadrat <= 6) {
        return 3;
    }
    else if (kvadrat <= 9) {
        return 6;
    }
}

int getKoordinateY(int kvadrat) {
    if (kvadrat == 1 || kvadrat == 4 || kvadrat == 7) {
        return 0;
    }
    else if (kvadrat == 2 || kvadrat == 5 || kvadrat == 8) {
        return 3;
    }
    else if (kvadrat == 3 || kvadrat == 6 || kvadrat == 9) {
        return 6;
    }
}

void ispisiMatricu(char glavnoPolje[][9]) {

    int brojac = 0, brojac1 = 0;
    cout << endl;
    for (int i = 0; i < 9; i++) {

        brojac1 = 0;
        for (int j = 0; j < 9; j++) {
            if (glavnoPolje[i][j] == 'a') {
                cout << " " << i << "," << j << " ";
            }
            else {
                cout << " " << glavnoPolje[i][j] << "   ";
            }
            brojac1++;
            if (brojac1 % 3 == 0) {
                cout << "|";
            }
        }
        brojac++;
        if (brojac % 3 == 0) {
            cout << "\n-----------------------------------------------\n";
        }
        cout << endl;
    }
    cout << endl;
}

void popuniMatricu(char glavnoPolje[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            glavnoPolje[i][j] = 'a';
        }
    }
}

void odigrajKoordinate(char glavnoPolje[][9], int igrac, int x, int y) {
    if (igrac == 1) {
        glavnoPolje[x][y] = 'X';
    }
    else {
        glavnoPolje[x][y] = 'O';
    }
}

int odrediSljedeciKvadrat(int kvadrat, int x, int y) {
    int xx = getKoordinateX(kvadrat);
    int yy = getKoordinateY(kvadrat);

    if (x == xx && y == yy) {
        return 1;
    }
    else if (x == xx && y == yy + 1) {
        return 2;
    }
    else if (x == xx && y == yy + 2) {
        return 3;
    }
    else if (x == xx + 1 && y == yy) {
        return 4;
    }
    else if (x == xx + 1 && y == yy + 1) {
        return 5;
    }
    else if (x == xx + 1 && y == yy + 2) {
        return 6;
    }
    else if (x == xx + 2 && y == yy) {
        return 7;
    }
    else if (x == xx + 2 && y == yy + 1) {
        return 8;
    }
    else if (x == xx + 2 && y == yy + 2) {
        return 9;
    }
}

int provjeriOdigraniKvadrat(int kvadrat, int odigraniKvadrati[]) {
    for (int i = 0; i < 9; i++) {
        if (odigraniKvadrati[i] == kvadrat) {
            return 1;
        }
    }
    return 0;
}

int provjeriGlavnuPobjedu(int pobjede[]) {
    //vodorabno
    if (sadrzi(pobjede, 1) == 1 && sadrzi(pobjede, 2) == 1 && sadrzi(pobjede, 3) == 1) {
        return 1;
    }
    else if (sadrzi(pobjede, 4) == 1 && sadrzi(pobjede, 5) == 1 && sadrzi(pobjede, 6) == 1) {
        return 1;
    }
    else if (sadrzi(pobjede, 7) == 1 && sadrzi(pobjede, 8) == 1 && sadrzi(pobjede, 9) == 1) {
        return 1;
    }

    //okomito
    if (sadrzi(pobjede, 1) == 1 && sadrzi(pobjede, 4) == 1 && sadrzi(pobjede, 7) == 1) {
        return 1;
    }
    else if (sadrzi(pobjede, 2) == 1 && sadrzi(pobjede, 5) == 1 && sadrzi(pobjede, 8) == 1) {
        return 1;
    }
    else if (sadrzi(pobjede, 3) == 1 && sadrzi(pobjede, 6) == 1 && sadrzi(pobjede, 9) == 1) {
        return 1;
    }

    //dijagonalno
    if (sadrzi(pobjede, 1) == 1 && sadrzi(pobjede, 5) == 1 && sadrzi(pobjede, 9) == 1) {
        return 1;
    }
    else if (sadrzi(pobjede, 7) == 1 && sadrzi(pobjede, 5) == 1 && sadrzi(pobjede, 3) == 1) {
        return 1;
    }

    return 0;
}

int provjeriPobjeduUKvadratu(int kvadrat, char glavnoPolje[][9], int igrac) {
    int x = getKoordinateX(kvadrat);
    int y = getKoordinateY(kvadrat);
    char c = 'X';
    if (igrac == 2) {
        c = 'O';
    }

    //vodoravno
    if (glavnoPolje[x][y] == c && glavnoPolje[x][y + 1] == c && glavnoPolje[x][y + 2] == c) {
        return 1;
    }
    else if (glavnoPolje[x + 1][y] == c && glavnoPolje[x + 1][y + 1] == c && glavnoPolje[x + 1][y + 2] == c) {
        return 1;
    }
    else if (glavnoPolje[x + 2][y] == c && glavnoPolje[x + 2][y + 1] == c && glavnoPolje[x + 2][y + 2] == c) {
        return 1;
    }

    //okomito
    if (glavnoPolje[x][y] == c && glavnoPolje[x + 1][y] == c && glavnoPolje[x + 2][y] == c) {
        return 1;
    }
    else if (glavnoPolje[x][y + 1] == c && glavnoPolje[x + 1][y + 1] == c && glavnoPolje[x + 2][y + 1] == c) {
        return 1;
    }
    else if (glavnoPolje[x][y + 2] == c && glavnoPolje[x + 1][y + 2] == c && glavnoPolje[x + 2][y + 2] == c) {
        return 1;
    }

    //dijagonalno
    if (glavnoPolje[x][y] == c && glavnoPolje[x + 1][y + 1] == c && glavnoPolje[x + 2][y + 2] == c) {
        return 1;
    }
    else if (glavnoPolje[x + 2][y] == c && glavnoPolje[x + 1][y + 1] == c && glavnoPolje[x][y + 2] == c) {
        return 1;
    }

    return 0;
}


int validirajKoordinate(int x, int y) {
    int moguciKvadrati[3];

    if (x <= 2) {
        moguciKvadrati[0] = 1; moguciKvadrati[1] = 2; moguciKvadrati[2] = 3;
    }
    else if (x <= 5) {
        moguciKvadrati[0] = 4; moguciKvadrati[1] = 5; moguciKvadrati[2] = 6;
    }
    else if (x <= 8) {
        moguciKvadrati[0] = 7; moguciKvadrati[1] = 8; moguciKvadrati[2] = 9;
    }

    if (y <= 2) {
        return moguciKvadrati[0];
    }
    else if (y <= 5) {
        return moguciKvadrati[1];
    }
    else if (y <= 8) {
        return moguciKvadrati[2];
    }
}

int main()
{
    char glavnoPolje[9][9];
    popuniMatricu(glavnoPolje);
    fstream file;
    cout << "Ocete li ucitati prijasnju igru? (d/n) ";
    string choice;
    getline(cin, choice);
    string fileName;

    if (choice == "D" || choice == "d") //ucitavanje
    {
        system("cls");
        std::cout << "Ime spremljene datoteke: ";
        std::cin >> fileName;
        file.open(fileName, std::ios::binary | std::ios::in);
        if (file.fail())
        {
            std::cout << "Greska pri otvaranju " << fileName;
            return 0;
        }
        file.read((char*)&glavnoPolje, sizeof(glavnoPolje));
        file.close();
        std::cin.ignore();
    }
    else {
        system("cls");
    }



    int gameOver = 0;
    int igrac = 1;
    int kvadrat, x, y;
    int sljedeciKvadrat = 0;
    int pobjedeniKvadratiIgrac1[9];
    int pobjedeniKvadratiIgrac2[9];
    int odigraniKvadrati[9];
    int odigraniCnt = 0, pobjedeni1Cnt = 0, pobjedeni2Cnt = 0;
    while (gameOver < 1) {

        //ispisi igru
        ispisiMatricu(glavnoPolje);

        //unos igraca
        if (sljedeciKvadrat == 0) {
            cout << "Igrac " << igrac << " unesi kordinate X,Y (ili \"6 9\" da save-as igru): ";
        }
        else {
            cout << "Igrac " << igrac << " unesi koordinate X,Y kvadrata broj: " << sljedeciKvadrat << "(ili \"6 9\" da save-as igru): ";
        }
        cin >> x;
        cin >> y;

        if (x == 6 && y == 9) //save-anje igre
        {
            std::cout << "Upisi ime za spremanje datoteke: ";
            std::cin >> fileName;
            file.open(fileName, std::ios::binary | std::ios::out);
            file.write((char*)&glavnoPolje, sizeof(glavnoPolje));
            file.close();
            std::cout << "Igra spremljena!";
            return 0;
        }

        cout << "\n\n";

        //provjeri jesu li ispravne koordinate
        int kvadrat = validirajKoordinate(x, y);
        if (sljedeciKvadrat != 0 && kvadrat != sljedeciKvadrat) {
            cout << "\nOdabrane krive koordinate, sljedeci potez mora biti u " << sljedeciKvadrat << " kvadratu.\n";

            continue;
        }

        //TODO ODREDI SLJEDECI KVADRAT
        sljedeciKvadrat = odrediSljedeciKvadrat(kvadrat, x, y);
        if (sadrzi(odigraniKvadrati, sljedeciKvadrat) == 1) {
            sljedeciKvadrat = 0;
        }

        //odigraj
        odigrajKoordinate(glavnoPolje, igrac, x, y);

        //provjeri pobjedu u kvadratu
        if (provjeriPobjeduUKvadratu(kvadrat, glavnoPolje, igrac) == 1) {
            odigraniKvadrati[odigraniCnt] = kvadrat;
            if (igrac == 1) {
                pobjedeniKvadratiIgrac1[pobjedeni1Cnt] = kvadrat;
            }
            else {
                pobjedeniKvadratiIgrac2[pobjedeni2Cnt] = kvadrat;
            }
        }
        system("cls");
        //provjeri pobjedu u glavnom polju
        if (igrac == 1) {
            gameOver = provjeriGlavnuPobjedu(pobjedeniKvadratiIgrac1);
        }
        else {
            gameOver = provjeriGlavnuPobjedu(pobjedeniKvadratiIgrac2);
        }

        if (igrac == 1) {
            igrac = 2;
        }
        else {
            igrac = 1;
        }
    }
    if (igrac == 1) {
        igrac = 2;
    }
    else {
        igrac = 1;
    }
    cout << "\nGotovo! Pobjednik je: Igrac " << igrac;

}