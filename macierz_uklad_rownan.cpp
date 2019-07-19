#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
    // eliminacji Gaussa lub inna metoda
    // w pierwszej literacji eliminujemy kolumne po lewej stronie
    // w pliku wejściowym - macierz 10x10, w drugim wetor wyrazow wolnych (dane po prawej rownosci), wynik do pliku
    // na  5 - programy - mnozenie macierzry i strassen + uklady rownan 10x10
    // co to jest stopien uwarunkownia macierzy
    // macierz 3x3 eliminacji gaussa - zredukuj do macierzy trojkatnej
double MACIERZ[10][10], WEKTOR [10],X[10], XTEMP[10];
double liczba, zero=1e-10, licznik, mianownik, pomoc, s;
int main()
{
fstream plik;
plik.open( "macierz_uklad_rownan3.txt", ios::in | ios::out ); // otwarcie pliku
if( plik.good() == true )
    {
        cout << "Uzyskano dostep do pliku!" << endl;
        for( int i = 0; i < 3; i++ )
        {
            for(int j=0; j <3; j++)
            {
                plik >> MACIERZ[j][i]; // przepisanie do tablicy
                //plik.flush();
            }
        }
    } else cout << "Dostep do pliku zostal zabroniony!" << endl;
fstream plikW; // oblsuga pliku wektora
plikW.open( "wektor.txt", ios::in | ios::out );
    if( plikW.good() == true )
    {
        cout << "Uzyskano dostep do pliku!" << endl;
        for( int i = 0; i <= 3; i++ )
        {
            plikW >> WEKTOR[i];
            XTEMP[i]=0;
            X[i]=0;
            //plikW.flush();
        }
    } else cout << "Dostep do pliku zostal zabroniony!" << endl;
cout << "Dane wejsciowe" << endl;
for( int i = 0; i <= 3; i++ )
    {
    for(int j=0; j <= 3; j++)
    {
        cout << MACIERZ[j][i] << " ";
        //plik.flush();
    }
    cout << "  "<< WEKTOR[i] << " ";
    cout << endl;
    }
for(int j=0; j<3; j++)
{
    for(int i=1+j; i<4; i++)
    {
        //if (fabs(MACIERZ[i][i] < zero)) {cout << "Dzielenie przez 0";cout << " j - " << j << " i - " << i << endl ;return false;}
        //licznik = MACIERZ[i][j+1];
        //mianownik = MACIERZ[i][j];

        pomoc=MACIERZ[j][i]/MACIERZ[j][j];
        //cout << " i=" << i <<"-> "<< " j=" << j << " MACIERZ[j][i]=" <<MACIERZ[j][i]<< " MACIERZ[i][i]=" <<MACIERZ[i][i]<< " -> " <<" Pomoc -> "<< pomoc  <<endl;
        for( int i = 0; i < 3; i++ )
    { // usunac
    for(int j=0; j < 3; j++)
    {
       // cout << MACIERZ[j][i] << " ";
        plik.flush();
    }
    //cout << "  "<< WEKTOR[i] << " ";
    //cout << endl;
    } // usunac
        for(int k = j; k <3; k++)
        {

           MACIERZ[k][i]=MACIERZ[k][i]-(pomoc*MACIERZ[j][k]);
           if (fabs(MACIERZ[k][i]) < 1e-5)MACIERZ[k][i]=0;
            //MACIERZ[j][k]=MACIERZ[j+1][k]-pomoc;
        }
        WEKTOR[i]=WEKTOR[i]-WEKTOR[j]*pomoc;
    }//cout << "   "<< pomoc;
}
int n;// obliczanie X [i]
for(int m = 3; m >= 0; m--)
  {
    X[m]=WEKTOR[m]/MACIERZ[2][m];
    for(n=2;n>=m+1;n--)
    {
        XTEMP[m]=XTEMP[m]+WEKTOR[n]*MACIERZ[n][m-1];
        cout <<"XTEMP " << m << " " << XTEMP[m] << endl;
    }
    X[m]=X[m]+XTEMP[m];
    cout <<"X " << m << " " << X[m] << endl;
  }

//X[9]=WEKTOR[9]/MACIERZ[9][9];
//X[8]=WEKTOR[8]/MACIERZ[9][8]+X[9]*MACIERZ[8][8];
cout << endl<< "Dane wyjsciowe" << endl;
//cout << pomoc;
for( int i = 0; i < 3; i++ )
    {
    for(int j=0; j < 3; j++)
    {
        cout << MACIERZ[j][i] << " ";
        plik.flush();
    }
    cout << "  "<< WEKTOR[i] << " ";
cout << endl;
    }

for( int i = 0; i < 3; i++ )
    {
    cout << "X" << i << " "<< X[i] << endl;
    }

   // cout << "   "<< MACIERZ[0][0];
return 0;
}
