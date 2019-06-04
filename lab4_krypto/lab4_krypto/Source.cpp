#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;



void dec_to_bin(unsigned long long int liczba,unsigned long long int tab[31])
{
	long long int i = 0;

	while (liczba) 
	{
		tab[i++] = liczba % 2;
		liczba /= 2;
	}
}
unsigned long long int ASPM(unsigned long long int a, unsigned long  long int b, unsigned long long int c) {
	unsigned long long int sum = 1;
	unsigned long long int TAB[31];
	unsigned long long int tab[31];
	for (int i = 0; i < 31; i++) tab[i] = 3;
	dec_to_bin(b, tab);
	TAB[0] = a%c;
	if (tab[0] == 1) sum *= TAB[0];
	for (int i = 1; tab[i] <2; i++) {
		TAB[i] = pow(TAB[i-1], 2);
	    TAB[i]%=c;
		if (tab[i] == 1) sum *= (TAB[i]);
		sum %= c;
	}
	return sum;

}
void a_rozklad(int a, int &k, int &d) {
	d = a;
	k = 0;
	while (d % 2 == 0) {
		d /= 2;
		k++;
	}

}
/*int ile(int rozmiar, int *tabl, int szuk)
{
	int x, wynik = 0;
	for (x = 0; x <= rozmiar - 1; x++)
		if (tabl[x] == szuk)
			wynik++;
	return wynik;
}*/
void Fermat(int a,vector <int> &TAB) {
	double y;
	bool find = false;
	int k, d;
	a_rozklad(a, k, d);
	for (int i = 0; i < k; i++) TAB.push_back(2);
	int x;
	x =floor(sqrt(d));
	if (x != sqrt(d))
	{
		x = x + 1;
		while (x < ((d + 1) / 2)) {
			y = (x*x) - d;
			if ((y > 0) and (floor(sqrt(y)) == sqrt(y))) break;
			x = x + 1;

		}



		int d1 = x + sqrt(y), d2 = x - sqrt(y);
		x = floor(sqrt(d1));
		if (x != sqrt(d1)) {
			x = x + 1;

		while (x < ((d1 + 1) / 2)) {

			y = (x*x) - d1;
			if ((y > 0) and (floor(sqrt(y)) == sqrt(y))) { find = true; break; }

			x = x + 1;

		}
		

		if (find) {
			TAB.push_back(x + (int)sqrt(y));
			TAB.push_back(x - (int)sqrt(y));
		}
		else TAB.push_back(d1);
		}
		else {
			TAB.push_back(sqrt(d1));
			TAB.push_back(sqrt(d1));
		}
		
		
		find = false;
		x = floor(sqrt(d2));
		if (x != sqrt(d2)) {
			x = x + 1;

			while (x < ((d2 + 1) / 2)) {
				y = (x*x) - d2;
				if ((y > 0) and (floor(sqrt(y)) == sqrt(y))) { find = true; break; }
				x = x + 1;

			}
			if (find) {
				TAB.push_back(x + (int)sqrt(y));
				TAB.push_back(x - (int)sqrt(y));
			}
			else TAB.push_back(d2);
		}
		else {
			TAB.push_back(sqrt(d2));
			TAB.push_back(sqrt(d2));
		}
	}
	else {
		TAB.push_back(sqrt(d));
		TAB.push_back(sqrt(d));
	}
	sort(TAB.begin(),TAB.end());

}
void LUCAS(int p, int q) {
	vector <int> TAB;
	bool pierwsza = false;
	Fermat(p - 1, TAB);
	if (ASPM(q, p - 1, p) == 1) {
		cout << endl<<q << "^("<<p - 1 << ") ="<< ASPM(q, p - 1, p)<<" (mod "<<p<<")"<<endl;
		pierwsza = true;
		for (int i = 0; i < TAB.size(); i++) {
			
			if (ASPM(q, (p - 1) / TAB[i], p) == 1) { pierwsza = false; 
			if (i == 0) cout << q << "^(" << p - 1 << "/" << TAB[i] << ") =/=" << ASPM(q, (p - 1) / TAB[i], p) << " (mod " << p << ")" << endl;
			else if(i!=0 and TAB[i]!=TAB[i-1])
				cout << q << "^(" << p - 1 << "/" << TAB[i] << ") ==" << ASPM(q, (p - 1) / TAB[i], p) << " (mod " << p << ")" << endl;
			}
			
			else {
				if(i==0) cout << q << "^(" << p - 1 << "/" << TAB[i] << ") =/=" << ASPM(q, (p - 1) / TAB[i], p) << " (mod " << p << ")" << endl;
				else if (i != 0 and TAB[i] != TAB[i - 1]) cout << q << "^(" << p - 1 << "/" << TAB[i] << ") =/=" << ASPM(q, (p - 1) / TAB[i], p) << " (mod " << p << ")" << endl;
			}
		}
	}
	if(pierwsza==true) cout << endl << p << " jest pierwsza" << endl;
	else cout << endl << "nie rozstrzyga czy " <<p<<" jest pierwsza" << endl;


}
int main()
{
	unsigned long long int a , b, c ;
	cout << "Szybkie potegowanie modulo: " << endl<<"Podaj a: ";
	cin >> a;
	cout << "Podaj b: ";
	cin >> b;
	cout << "Podaj c: ";
	cin >> c;
	cout<<"Wynik: "<<ASPM(a, b, c)<<endl;
	
	int a2;
	vector <int> TAB;
	
	cout << endl << "FERMAT" << endl<<"Podaj liczbe: ";
	cin >> a2;
	Fermat(a2, TAB);
	int t = 1;
	for (int i = 0; i < TAB.size(); i++) {
		for (int j = i; j < TAB.size(); j++) {
			if (i != j and TAB[i] == TAB[j]) t++;
		}
		if (i>0 && TAB[i] != TAB[i - 1])
			cout << "dzielnik: " << TAB[i] << " krotnosc: " << t << endl;
		else if (i == 0) cout << "dzielnik: " << TAB[i] << " krotnosc: " << t << endl;
		t = 1;
	}
	int n,q;
	cout << endl << "Test Lucasa" << endl << "Podaj n: ";
	cin >> n;
	cout << "Podaj q: ";
	cin >> q;
	LUCAS(n, q);

	system("pause");
	return 0;
}