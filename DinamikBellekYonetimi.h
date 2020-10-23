// Ya��zcem CENG�Z
// 170757058
// Bilgisayar M�hendisli�i
// Nesneye Y�nelik Programlama BIM - 104
// II. D�nem (2. yar�y�l)
// Proje4
// Dr. ��r. �yesi G�l�ah T�M�KL� �ZYER

#include <iostream>
using namespace std;

class DinamikBellekYonetimi
{
	public:						
		bool GizemliMatrisMi(int** matris, int satirSayisi, int sutunSayisi);		// istenilen gibi fonksiyonlar�m�z� yaz�yoruz...
		int SansliMatrisElemanlarininSayisi(int **matris,  int satirSayisi,  int sutunSayisi);

	private: 
		bool SatirdakiMinEleman(int **matris, int i, int satirSayisi, int elemanSayisi); // GizemliMatris ve SanliMatrisElemanlarininSayisini kontrol ettirecek bool fonksiyonlar�m�z� private olarak ekliyoruz , parametrelerini istenilen gibi giriyoruz...
		bool SutundekiMaksEleman(int **matris, int j, int sutunSayisi, int elemanSayisi);
		bool EssizEleman(int **matris,  int satirSayisi, int sutunSayisi,  int elemanSayisi);
		bool SatirToplam(int **matris,  int boyut,  int toplam);
		bool SutunToplam(int **matris,  int boyut,  int toplam);
};

