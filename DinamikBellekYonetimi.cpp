// Yaðýzcem CENGÝZ
// 170757058
// Bilgisayar Mühendisliði
// Nesneye Yönelik Programlama BIM - 104
// II. Dönem (2. yarýyýl)
// Proje4
// Dr. Öðr. Üyesi Gülþah TÜMÜKLÜ ÖZYER

#include "DinamikBellekYonetimi.h"
#include <iostream>
#include <cmath>
using namespace std;


bool DinamikBellekYonetimi::EssizEleman(int **matris, int satirSayisi, int sutunSayisi, int elemanSayisi)
{
	int k = 0; 
	for (int i = 0; i < satirSayisi; i++) // Eleman sayisini , dizinin içine girip aratýyoruz.
	{
		for (int j = 0; j < sutunSayisi; j++)
		{
			if (elemanSayisi == matris[i][j])
				k++;
		}
	}

	
	if (k > 1) // Eðer eleman sayisi , 1 den fazlaysa false döndürüyoruz.
		return false;
		
	return true;
}

bool DinamikBellekYonetimi::SatirToplam(int **matris, int boyut, int toplam)
{
	int t = 0; // toplamý 0'a eþitliyoruz.
	for (int i = 0; i < boyut; i++)
	{
		t = 0;
		for (int j = 0; j < boyut; j++)  // Matris içindeki satýrlarýn toplamý , t'ye eþit mi diye bakýyoruz.
		{
			t = t + matris[i][j];
		}

		if (toplam != t) // Satýr toplamýmýz , t ye eþit deðilse false döndürüyoruz.
			return false;
	}
	return true; // Eðer eþitse true döndürüyoruz.
}

bool DinamikBellekYonetimi::SutunToplam( int **matris,  int boyut,  int toplam)
{
	int t = 0; // toplamý 0'a eþitliyoruz.
	for (int i = 0; i < boyut; i++)
	{
		t = 0;
		for (int j = 0; j < boyut; j++)  // burada da , üstte yazdýðýmýz fonksiyon gibi yapýyoruz. Tek farký , bu sefer satýr deðil de sütunlarýn toplamýna bakacaðýz.
		{
			t = t + matris[j][i];
		}

		if (toplam != t) // Sütunlarýn toplamý , t ye eþit deðilse false döndürüyoruz.
			return false;
	}
	return true; // Eðer eþitse true döndürüyoruz.
}


bool DinamikBellekYonetimi::GizemliMatrisMi(int** matris, int satirSayisi, int sutunSayisi)
{
	if (satirSayisi == sutunSayisi)
	{
		int boyut = satirSayisi, min = 1, max = pow(boyut,2);

		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)  // Formülde verildiði gibi , 1 ile n^2 arasýndaki tam sayýlarý kontrol ediyoruz.
			{
				if (matris[i][j] < min || matris[i][j] > max) // Eðer sayý 1 den küçük veya n^2'den büyük olduðu durumda false döndürüyoruz ve Otomatik olarak matrisimizin , Gizemli matris olmadýðýný söyleyebiliyoruz.
					return false;
			}
		}

		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)
			{
				
				if (!EssizEleman(matris, boyut, boyut, matris[i][j])) // EssizEleman fonksiyonumuzu burada çaðýrýyoruz. Eðer EssizEleman fonksiyonunun içindeki þeyleri karþýlamýyorsa , false döndürüyoruz. 
					return false;
			}
		}



		int t = 0;  // Toplamý 0'a eþitledik.
		int t2 = (boyut * (pow(boyut, 2) + 1)) / 2; // Toplam 2 yani M sabitinin formulünü yazýyoruz.

		for (int i = 0; i < boyut; i++)  // Matristeki çapraz elemanlarýn toplamýný buluyoruz.
			t = t + matris[i][i];

		if (t != t2)  // Toplam , Toplam 2'ye yani çapraz toplamýna eþit deðilse false döndürüyoruz.
			return false;

		int j = 0;
		t = 0;


		for (int i = satirSayisi-1; i >= 0; i--)  // Çapraz elemanlarýn toplamýný bulmaya devam ediyoruz.
		{
			t = t + matris[j][i];
			j++;
		}

		if (t != t2)  //Toplam , Toplam 2'ye yani çapraz toplamýna eþit deðilse false döndürüyoruz.
			return false;

		if (!SutunToplam(matris, boyut, t2) || !SatirToplam(matris, boyut, t2))
			return false;
		
		
		return true;
	}
	else
	{
		return false;  // Gizemli Matris deðilse false döndürüyoruz.
	}
}








bool DinamikBellekYonetimi::SatirdakiMinEleman(int **matris, int i, int satirSayisi, int elemanSayisi)
{
	
	for (int j = 0; j < satirSayisi; j++)
	{
		if (elemanSayisi > matris[i][j])  // Satýrdaki minimum eleman olup olmadýðýný kontrol ediyoruz.
			return false;
	}
	return true;
}


bool DinamikBellekYonetimi::SutundekiMaksEleman(int **matris, int j, int sutunSayisi, int elemanSayisi)
{
	
	for (int i = 0; i < sutunSayisi; i++)
	{
		if (elemanSayisi < matris[i][j]) //Sutundaki maksimum eleman olup olmadýðýný kontrol ediyoruz.
			return false;
	}
	return true;
}


int DinamikBellekYonetimi::SansliMatrisElemanlarininSayisi(int **matris, int satirSayisi, int sutunSayisi)
{
	int elemanSayisi = 0;
	
	for (int i = 0; i < satirSayisi; i++)
	{
		for (int j = 0; j < sutunSayisi; j++)
		{
			
			if (!EssizEleman(matris, satirSayisi, sutunSayisi, matris[i][j])) // Matrisin içindeki elemanlarýn Eþsiz olup olmadýðýný göstermek amacýyla EssizEleman fonskiyonumuzu çaðýrýyoruz.
				return elemanSayisi;
		}
	}

	int eleman;
	for (int i = 0; i < satirSayisi; i++)
	{
		for (int j = 0; j < sutunSayisi; j++)
		{
			eleman = matris[i][j];
			if (SatirdakiMinEleman(matris, i, satirSayisi, eleman) && SutundekiMaksEleman(matris, j, sutunSayisi, eleman))
				elemanSayisi++;
		}
	}

	return elemanSayisi;
}
