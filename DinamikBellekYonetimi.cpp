// Ya��zcem CENG�Z
// 170757058
// Bilgisayar M�hendisli�i
// Nesneye Y�nelik Programlama BIM - 104
// II. D�nem (2. yar�y�l)
// Proje4
// Dr. ��r. �yesi G�l�ah T�M�KL� �ZYER

#include "DinamikBellekYonetimi.h"
#include <iostream>
#include <cmath>
using namespace std;


bool DinamikBellekYonetimi::EssizEleman(int **matris, int satirSayisi, int sutunSayisi, int elemanSayisi)
{
	int k = 0; 
	for (int i = 0; i < satirSayisi; i++) // Eleman sayisini , dizinin i�ine girip arat�yoruz.
	{
		for (int j = 0; j < sutunSayisi; j++)
		{
			if (elemanSayisi == matris[i][j])
				k++;
		}
	}

	
	if (k > 1) // E�er eleman sayisi , 1 den fazlaysa false d�nd�r�yoruz.
		return false;
		
	return true;
}

bool DinamikBellekYonetimi::SatirToplam(int **matris, int boyut, int toplam)
{
	int t = 0; // toplam� 0'a e�itliyoruz.
	for (int i = 0; i < boyut; i++)
	{
		t = 0;
		for (int j = 0; j < boyut; j++)  // Matris i�indeki sat�rlar�n toplam� , t'ye e�it mi diye bak�yoruz.
		{
			t = t + matris[i][j];
		}

		if (toplam != t) // Sat�r toplam�m�z , t ye e�it de�ilse false d�nd�r�yoruz.
			return false;
	}
	return true; // E�er e�itse true d�nd�r�yoruz.
}

bool DinamikBellekYonetimi::SutunToplam( int **matris,  int boyut,  int toplam)
{
	int t = 0; // toplam� 0'a e�itliyoruz.
	for (int i = 0; i < boyut; i++)
	{
		t = 0;
		for (int j = 0; j < boyut; j++)  // burada da , �stte yazd���m�z fonksiyon gibi yap�yoruz. Tek fark� , bu sefer sat�r de�il de s�tunlar�n toplam�na bakaca��z.
		{
			t = t + matris[j][i];
		}

		if (toplam != t) // S�tunlar�n toplam� , t ye e�it de�ilse false d�nd�r�yoruz.
			return false;
	}
	return true; // E�er e�itse true d�nd�r�yoruz.
}


bool DinamikBellekYonetimi::GizemliMatrisMi(int** matris, int satirSayisi, int sutunSayisi)
{
	if (satirSayisi == sutunSayisi)
	{
		int boyut = satirSayisi, min = 1, max = pow(boyut,2);

		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)  // Form�lde verildi�i gibi , 1 ile n^2 aras�ndaki tam say�lar� kontrol ediyoruz.
			{
				if (matris[i][j] < min || matris[i][j] > max) // E�er say� 1 den k���k veya n^2'den b�y�k oldu�u durumda false d�nd�r�yoruz ve Otomatik olarak matrisimizin , Gizemli matris olmad���n� s�yleyebiliyoruz.
					return false;
			}
		}

		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)
			{
				
				if (!EssizEleman(matris, boyut, boyut, matris[i][j])) // EssizEleman fonksiyonumuzu burada �a��r�yoruz. E�er EssizEleman fonksiyonunun i�indeki �eyleri kar��lam�yorsa , false d�nd�r�yoruz. 
					return false;
			}
		}



		int t = 0;  // Toplam� 0'a e�itledik.
		int t2 = (boyut * (pow(boyut, 2) + 1)) / 2; // Toplam 2 yani M sabitinin formul�n� yaz�yoruz.

		for (int i = 0; i < boyut; i++)  // Matristeki �apraz elemanlar�n toplam�n� buluyoruz.
			t = t + matris[i][i];

		if (t != t2)  // Toplam , Toplam 2'ye yani �apraz toplam�na e�it de�ilse false d�nd�r�yoruz.
			return false;

		int j = 0;
		t = 0;


		for (int i = satirSayisi-1; i >= 0; i--)  // �apraz elemanlar�n toplam�n� bulmaya devam ediyoruz.
		{
			t = t + matris[j][i];
			j++;
		}

		if (t != t2)  //Toplam , Toplam 2'ye yani �apraz toplam�na e�it de�ilse false d�nd�r�yoruz.
			return false;

		if (!SutunToplam(matris, boyut, t2) || !SatirToplam(matris, boyut, t2))
			return false;
		
		
		return true;
	}
	else
	{
		return false;  // Gizemli Matris de�ilse false d�nd�r�yoruz.
	}
}








bool DinamikBellekYonetimi::SatirdakiMinEleman(int **matris, int i, int satirSayisi, int elemanSayisi)
{
	
	for (int j = 0; j < satirSayisi; j++)
	{
		if (elemanSayisi > matris[i][j])  // Sat�rdaki minimum eleman olup olmad���n� kontrol ediyoruz.
			return false;
	}
	return true;
}


bool DinamikBellekYonetimi::SutundekiMaksEleman(int **matris, int j, int sutunSayisi, int elemanSayisi)
{
	
	for (int i = 0; i < sutunSayisi; i++)
	{
		if (elemanSayisi < matris[i][j]) //Sutundaki maksimum eleman olup olmad���n� kontrol ediyoruz.
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
			
			if (!EssizEleman(matris, satirSayisi, sutunSayisi, matris[i][j])) // Matrisin i�indeki elemanlar�n E�siz olup olmad���n� g�stermek amac�yla EssizEleman fonskiyonumuzu �a��r�yoruz.
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
