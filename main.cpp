#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class obslugaPliku{
	public:
		obslugaPliku();
		~obslugaPliku();
		ifstream wejscie;
		ofstream wyjscie;
	bool sprawdzPlik();
};
class obslugaCiagu:public obslugaPliku{
	public:
		vector <int> ciag;
		int dlugosc=0;
		int r;
	void wczytajCiag();
	void znajdzRoznice();
	void znajdzBlad();
	void zapisz(int liczba);
};
obslugaPliku::obslugaPliku(){
	wejscie.open("bledne.txt");
	wyjscie.open("wynik3.txt");
}
obslugaPliku::~obslugaPliku(){
	wejscie.close();
	wyjscie.close();
}
bool obslugaPliku::sprawdzPlik(){
	if(wejscie.good()&&wyjscie.good()) return true;
	else return false;
}
void obslugaCiagu::wczytajCiag(){
	obslugaPliku p1;
	int liczba;
	while(!p1.wejscie.eof()){
		p1.wejscie>>dlugosc;
		for(int i=0;i<=dlugosc-1;i++){
			p1.wejscie>>liczba;
			ciag.push_back(liczba);
		}
		znajdzRoznice();
		znajdzBlad();
		dlugosc=0;
		liczba=0;
		
		ciag.clear();
	}	
}
void obslugaCiagu::znajdzRoznice(){
	int r1,r2,r3;
	int rozmiar = dlugosc-1;
	r1 = ciag[1] - ciag[0];
	r2 = ciag[2] - ciag[1];
	if(r1 == r2) r = r1;
	else{
		r3 = ciag[rozmiar] - ciag[rozmiar - 1];
		if(r1 == r3) r = r1;
		else r = r3;
	}
	
}
void obslugaCiagu::znajdzBlad(){
	for(int i=0;i<=dlugosc-1;i++){
		
		if(ciag[i]+r != ciag[i+1]){
			if(i+1 >= dlugosc) break;
			else zapisz(i+1);
		}
		
	}
}
void obslugaCiagu::zapisz(int liczba){
	
	wyjscie<<"Blad: "<<ciag[liczba]<<endl;
}
int main() {
	obslugaPliku p1;
	obslugaCiagu c1;
	p1.sprawdzPlik();
	if(p1.sprawdzPlik() == false) exit(0); 
	else c1.wczytajCiag();
	return 0;
}
