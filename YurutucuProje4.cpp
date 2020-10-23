// Yaðýzcem CENGÝZ
// 170757058
// Bilgisayar Mühendisliði
// Nesneye Yönelik Programlama BIM - 104
// II. Dönem (2. yarýyýl)
// Proje4
// Dr. Öðr. Üyesi Gülþah TÜMÜKLÜ ÖZYER

#include "DinamikBellekYonetimi.h"
#include <iostream>
using namespace std;

int main()
{
	
	DinamikBellekYonetimi* d = new DinamikBellekYonetimi; // Nesnemizi oluþturuyoruz.

	int **gizemliMatris, gizemliSatir, gizemliSutun, **sansliMatris, sansliSatir, sansliSutun;

	cout << "Gizemli matrisin satir sayisini giriniz : "; // Kullanicidan , gizemli matrisimiz için satýr ve sütun sayýsýný alýyoruz.
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
		for (int j = 0; j < gizemliSutun; j++) // Kullanicidan , gizemli matrisimizin satýr ve sütunlarýn elemanlarýný alýyoruz.
		{
			cout << "Gizemli matrisin " << i + 1 << ".Satir " << j + 1 << ".Sutun" <<" elemanini giriniz: ";
			cin >> gizemliMatris[i][j];
		}
	}



	cout << "Sansli matrisin satir sayisini giriniz: "; //Kullanicidan , Sansli matrisimiz için satýr ve sütun sayýsýný alýyoruz.
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
		for (int j = 0; j < sansliSutun; j++) //Kullanicidan , gizemli matrisimizin satýr ve sütunlarýn elemanlarýný alýyoruz.
		{
			cout << "Sansli matrisin " << i + 1 << ".Satir " << j + 1 << ".Sutun" <<" elemanini giriniz: ";
			cin >> sansliMatris[i][j];
		}
	}


	if (d -> GizemliMatrisMi(gizemliMatris, gizemliSatir, gizemliSutun)) // Oluþan matrisimizin gizemli olup olmadýðýný kontrol ettiriyoruz.
	{
		cout << "\nOlusan matris bir GIZEMLI MATRIS !\n";
	}
	else
	{
		cout << "\nOlusan matris , Gizemli matris DEGIL !\n";
	}
	
	int toplamSansli = d -> SansliMatrisElemanlarininSayisi(sansliMatris, sansliSatir, sansliSutun); // Oluþan matrisimizin þanslý matris olup olmadýðýný kontrol ettiriyoruz.
	cout << "Toplam sansli matris eleman/elemanlarinin sayisi : " << toplamSansli << endl;



	for (int i = 0; i < gizemliSatir; i++)  // Delete fonksiyonu ile oluþturduðumun matrisin önce elemanlarýný , sonra matrisin kendisini yok ediyoruz.
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
