#include <iostream>

using namespace std;
class Sum
{
	int ilkSatir, ilkSutun, ikinciSatir, ikinciSutun;
public:
	inline int toplam();
	inline int matrisKontrol(int, int);
	inline int digerMatrisKontrol(int, int,int,int);
	inline void degerAtama(int**,int,int,string);
};

inline int Sum::toplam()
{
	int** ilkmatris;
	int** ikinciMatris;
	int** sonucMatris;

	string isim;
	cout << "Ilk Matrisinizi tek harfle isimlendiriniz: ";
	cin >> isim;
	cout << "Lutfen " << isim <<" matrisinin satir sayisini giriniz: ";
	cin >> Sum::ilkSatir;
	cout << "Lutfen "<< isim <<" matrisinin sutun sayisini giriniz: ";
	cin >> Sum::ilkSutun;

	if (!matrisKontrol(ilkSatir, ilkSutun))
	{
		return 0;
	}

	//ilk matris olusturma
	ilkmatris = new int* [ilkSatir];
	for (int i = 0; i < ilkSatir; i++)
	{
		ilkmatris[i] = new int[ilkSutun];
	}

	string ikinciIsım;
	cout << "Ikinci matrisi olusturunuz!" << endl;
	cout << "Matrise isim veriniz: ";
	cin >> ikinciIsım;
	cout << "Lutfen " << ikinciIsım << " matrisinin satir sayisini giriniz: ";
	cin >> Sum::ikinciSatir;
	cout << "Lutfen " << ikinciIsım << " matrisinin sutun sayisini giriniz: ";
	cin >> Sum::ikinciSutun;

	if (digerMatrisKontrol(ilkSatir, ilkSutun, ikinciSatir, ikinciSutun) == 0)
	{
		cout << "Hata!" << endl;
		return 0;
	}
	
	//ikinci matris olusturma
	ikinciMatris = new int*[ikinciSatir];
	for(int i=0;i<ikinciSatir;i++)
	{
		ikinciMatris[i] = new int[ikinciSutun];
	}

	//matrislere deger atama bolumu
	degerAtama(ilkmatris, ilkSatir, ilkSutun, isim);
	degerAtama(ikinciMatris, ikinciSatir, ikinciSutun, ikinciIsım);
	
	
	//Sonuc matrisi olusturma
	sonucMatris = new int* [ilkSatir];
	for(int i=0;i<ilkSatir;i++)
	{
		sonucMatris[i] = new int[ilkSutun];
	}


	//toplama islemi yapma
	for(int i=0;i<ilkSatir;i++)
	{
		for(int j=0;j<ilkSutun;j++)
		{
			sonucMatris[i][j] = ilkmatris[i][j] + ikinciMatris[i][j];
		}
	}

	//sonuc yazdırma
	cout << isim << " + " << ikinciIsım << " Sonucu" << endl;
	for(int i=0;i<ilkSatir;i++)
	{
		for(int j=0;j<ilkSutun;j++)
		{
			cout << sonucMatris[i][j] << " ";
		}
		cout << "\n";
	}
	
}

inline void Sum::degerAtama(int** arr,int satir,int sutun,string name)
{
	int deger;
	cout << name << " Matrisi degerlerini giriniz!" << endl;
	for(int i=0;i<satir;i++)
	{
		for(int j=0;j<sutun;j++)
		{
			cout << name << "[" << (i + 1) << "][" << (j + 1) << "] = ";
			cin >> deger;
			arr[i][j] = deger;
		}
	}
}
inline int Sum::matrisKontrol(int satir, int sutun)
{
	// 0xn veya nx0 kontrolu
	if (satir == 0 || sutun == 0)
	{
		cout << "Matrisler 0xn veya nx0 olamaz!" << endl;
		return 0;
	}
	return 1;
}

inline int Sum::digerMatrisKontrol(int ilkSatir, int ilkSutun, int ikinciSatir, int ikinciSutun)
{
	if (ikinciSatir == 0 || ikinciSutun == 0)
	{
		cout << "Matrisler 0xn veya nx0 olamaz!" << endl;
		return 0;
	}

	//iki matrisin nxn ve nxn tip kontrolu
	if((ilkSatir != ikinciSatir) || (ilkSutun != ikinciSutun))
	{
		cout << "Verilen matrislerin satir ve sutunlari esit degil!" << endl;
		return 0;
	}
	return 1;

}