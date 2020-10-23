// Yağızcem CENGİZ

#include "DinamikBellekYonetimi.h"
#include <iostream>
using namespace std;

int main()
{
	
	DinamikBellekYonetimi* d = new DinamikBellekYonetimi; // Nesnemizi oluşturuyoruz.

	int **gizemliMatris, gizemliSatir, gizemliSutun, **sansliMatris, sansliSatir, sansliSutun;

	cout << "Gizemli matrisin satir sayisini giriniz : "; // Kullanicidan , gizemli matrisimiz için satır ve sütun sayısını alıyoruz.
	cin >> gizemliSatir;
	cout << "Gizemli matrisin sutun sayisini giriniz : ";
	cin >> gizemliSutun;

	gizemliMatris = new int* [gizemliSatir];

	for (int i = 0; i < gizemliSatir; i++)
	{
		gizemliMatris[i] = new int[gizemliSutun];
	}

	for (int i = 0; i < gizemliSatir; i++)  
	{
		for (int j = 0; j < gizemliSutun; j++) // Kullanicidan , gizemli matrisimizin satır ve sütunların elemanlarını alıyoruz.
		{
			cout << "Gizemli matrisin " << i + 1 << ".Satir " << j + 1 << ".Sutun" <<" elemanini giriniz: ";
			cin >> gizemliMatris[i][j];
		}
	}



	cout << "Sansli matrisin satir sayisini giriniz: "; //Kullanicidan , Sansli matrisimiz için satır ve sütun sayısını alıyoruz.
	cin >> sansliSatir;
	cout << "Sansli matrisin sutun sayisini giriniz: ";
	cin >> sansliSutun;

	sansliMatris = new int* [sansliSatir];

	for (int i = 0; i < sansliSatir; i++)
	{
		sansliMatris[i] = new int[sansliSutun];
	}


	for (int i = 0; i < sansliSatir; i++)
	{
		for (int j = 0; j < sansliSutun; j++) //Kullanicidan , gizemli matrisimizin satır ve sütunların elemanlarını alıyoruz.
		{
			cout << "Sansli matrisin " << i + 1 << ".Satir " << j + 1 << ".Sutun" <<" elemanini giriniz: ";
			cin >> sansliMatris[i][j];
		}
	}


	if (d -> GizemliMatrisMi(gizemliMatris, gizemliSatir, gizemliSutun)) // Oluşan matrisimizin gizemli olup olmadığını kontrol ettiriyoruz.
	{
		cout << "\nOlusan matris bir GIZEMLI MATRIS !\n";
	}
	else
	{
		cout << "\nOlusan matris , Gizemli matris DEGIL !\n";
	}
	
	int toplamSansli = d -> SansliMatrisElemanlarininSayisi(sansliMatris, sansliSatir, sansliSutun); // Oluşan matrisimizin şanslı matris olup olmadığını kontrol ettiriyoruz.
	cout << "Toplam sansli matris eleman/elemanlarinin sayisi : " << toplamSansli << endl;



	for (int i = 0; i < gizemliSatir; i++)  // Delete fonksiyonu ile oluşturduğumun matrisin önce elemanlarını , sonra matrisin kendisini yok ediyoruz.
	{
		delete gizemliMatris[i];
	}

	delete gizemliMatris;
	
	for (int i = 0; i < sansliSatir; i++)
	{
		delete sansliMatris[i];
	}

	delete sansliMatris;
	
	delete d;
}
