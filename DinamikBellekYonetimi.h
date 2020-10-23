// Yaðýzcem CENGÝZ
// 170757058
// Bilgisayar Mühendisliði
// Nesneye Yönelik Programlama BIM - 104
// II. Dönem (2. yarýyýl)
// Proje4
// Dr. Öðr. Üyesi Gülþah TÜMÜKLÜ ÖZYER

#include <iostream>
using namespace std;

class DinamikBellekYonetimi
{
	public:						
		bool GizemliMatrisMi(int** matris, int satirSayisi, int sutunSayisi);		// istenilen gibi fonksiyonlarýmýzý yazýyoruz...
		int SansliMatrisElemanlarininSayisi(int **matris,  int satirSayisi,  int sutunSayisi);

	private: 
		bool SatirdakiMinEleman(int **matris, int i, int satirSayisi, int elemanSayisi); // GizemliMatris ve SanliMatrisElemanlarininSayisini kontrol ettirecek bool fonksiyonlarýmýzý private olarak ekliyoruz , parametrelerini istenilen gibi giriyoruz...
		bool SutundekiMaksEleman(int **matris, int j, int sutunSayisi, int elemanSayisi);
		bool EssizEleman(int **matris,  int satirSayisi, int sutunSayisi,  int elemanSayisi);
		bool SatirToplam(int **matris,  int boyut,  int toplam);
		bool SutunToplam(int **matris,  int boyut,  int toplam);
};

