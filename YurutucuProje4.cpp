// Ya��zcem CENG�Z
// 170757058
// Bilgisayar M�hendisli�i
// Nesneye Y�nelik Programlama BIM - 104
// II. D�nem (2. yar�y�l)
// Proje4
// Dr. ��r. �yesi G�l�ah T�M�KL� �ZYER

#include "DinamikBellekYonetimi.h"
#include <iostream>
using namespace std;

int main()
{
	
	DinamikBellekYonetimi* d = new DinamikBellekYonetimi; // Nesnemizi olu�turuyoruz.

	int **gizemliMatris, gizemliSatir, gizemliSutun, **sansliMatris, sansliSatir, sansliSutun;

	cout << "Gizemli matrisin satir sayisini giriniz : "; // Kullanicidan , gizemli matrisimiz i�in sat�r ve s�tun say�s�n� al�yoruz.
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
		for (int j = 0; j < gizemliSutun; j++) // Kullanicidan , gizemli matrisimizin sat�r ve s�tunlar�n elemanlar�n� al�yoruz.
		{
			cout << "Gizemli matrisin " << i + 1 << ".Satir " << j + 1 << ".Sutun" <<" elemanini giriniz: ";
			cin >> gizemliMatris[i][j];
		}
	}



	cout << "Sansli matrisin satir sayisini giriniz: "; //Kullanicidan , Sansli matrisimiz i�in sat�r ve s�tun say�s�n� al�yoruz.
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
		for (int j = 0; j < sansliSutun; j++) //Kullanicidan , gizemli matrisimizin sat�r ve s�tunlar�n elemanlar�n� al�yoruz.
		{
			cout << "Sansli matrisin " << i + 1 << ".Satir " << j + 1 << ".Sutun" <<" elemanini giriniz: ";
			cin >> sansliMatris[i][j];
		}
	}


	if (d -> GizemliMatrisMi(gizemliMatris, gizemliSatir, gizemliSutun)) // Olu�an matrisimizin gizemli olup olmad���n� kontrol ettiriyoruz.
	{
		cout << "\nOlusan matris bir GIZEMLI MATRIS !\n";
	}
	else
	{
		cout << "\nOlusan matris , Gizemli matris DEGIL !\n";
	}
	
	int toplamSansli = d -> SansliMatrisElemanlarininSayisi(sansliMatris, sansliSatir, sansliSutun); // Olu�an matrisimizin �ansl� matris olup olmad���n� kontrol ettiriyoruz.
	cout << "Toplam sansli matris eleman/elemanlarinin sayisi : " << toplamSansli << endl;



	for (int i = 0; i < gizemliSatir; i++)  // Delete fonksiyonu ile olu�turdu�umun matrisin �nce elemanlar�n� , sonra matrisin kendisini yok ediyoruz.
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
