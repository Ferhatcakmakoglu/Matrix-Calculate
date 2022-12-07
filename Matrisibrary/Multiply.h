#include <iostream>

using namespace std;

class Multiply
{
public: 
	inline int islem();
	inline int matrisKontrol(int,int);
	inline int digerMatrisKontrol(int,int,int, int);
};

inline int Multiply::islem()
{
	int satir;
	int sutun;
	string isim;
	cout << "Matrisinizi tek harfle isimlendiriniz: ";
	cin >> isim;
	cout << "Lutfen matris satir satirini giriniz: ";
	cin >> satir;
	cout << "Lutfen matris sutun satirini giriniz: ";
	cin >> sutun;

	// Matris sartlari kontrol
	if(matrisKontrol(satir,sutun) == 0)
	{
		return 0;
	}
	
	//matris olusturma 
	int** matris;
	matris = new int* [satir]; // -> satirlar olusturuluyor

	for (int i = 0; i < satir; i++) { //-> sutunlar olusturuluyor
		matris[i] = new int[sutun];
	}

	cout << "Lutfen Matrisinizi olusturunuz" << endl;
	int deger;
	for (int x = 0; x < satir; x++)
	{
		for (int y = 0; y < sutun; y++)
		{
			cout << isim << (x + 1) << (y + 1) << " Degeri: ";
			cin >> deger;
			matris[x][y] = deger;
		}
	}

	int ikinciSatir, ikinciSutun;
	string ikinciIsım;
	cout << "Lutfen carpmak istediginiz matrisi olusturunuz" << endl;
	cout << "Matrise isim veriniz: ";
	cin >> ikinciIsım;
	cout << "Matris satir sayisini giriniz: ";
	cin >> ikinciSatir;
	cout << "Matris sutun sayisini giriniz: ";
	cin >> ikinciSutun;

	
	//Matris kontrol
	if(digerMatrisKontrol(satir, sutun, ikinciSatir, ikinciSutun) == 0)
	{
		return 0;
	}

	int** digerMatris;
	digerMatris = new int* [ikinciSatir];
	int ikinciDeger;
	for(int z=0;z<ikinciSatir;z++)
	{
		digerMatris[z] = new int[ikinciSutun];
	}

	for(int v=0;v<ikinciSatir;v++)
	{
		for(int r=0;r<ikinciSutun;r++)
		{
			cout << ikinciIsım << (v + 1) << (r + 1) << " Degeri: ";
			cin >> ikinciDeger;
			digerMatris[v][r] = ikinciDeger;
		}
	}


	//Sonuc matrisi olusturma
	int** sonucMatrisi;
	sonucMatrisi = new int* [satir];

	for(int j=0;j<satir;j++)
	{
		sonucMatrisi[j] = new int[ikinciSutun];
	}

	int sonuc = 0;
	int u = 0;
	for(int j=0;j<satir;j++)
	{
		for (int o = 0; o < ikinciSutun; o++)
		{
			for(int k=0;k<ikinciSatir;k++)
			{
				sonuc += (matris[j][k] * digerMatris[u++][o]);
			}
			sonucMatrisi[j][o] = sonuc;
			u = 0;
			sonuc = 0;
		}
	}

	cout << "\n" << isim << " x " << ikinciIsım << " Matris Carpimi:" << endl;
	for (int t = 0; t < satir; t++)
	{
		for (int r = 0; r < ikinciSutun; r++)
		{
			cout << sonucMatrisi[t][r] << " ";
		}
		cout << "\n";
	}
	
}
inline int Multiply::matrisKontrol(int satir, int sutun)
{
	// 0xn veya nx0 kontrolu
	if (satir == 0 || sutun == 0)
	{
		cout << "Matrisler 0xn veya nx0 olamaz!";
		return 0;
	}

	// 0 < satir,sutun < 3 sarti saglanmasi
	if (!(1 <= satir && satir <= 3) || !(1 <= sutun && sutun <= 3))
	{
		cout << "Sistemimiz max 3x3 luk matris ile islem yapabilmektedir!" << endl;
		return 0;
	}
	return 1;
}

inline int Multiply::digerMatrisKontrol(int ilkSatir, int ilkSutun, int digerSatir, int digerSutun)
{
	// 0 < satir,sutun < 3 sarti saglanmasi VE 0xn veya nx0 kontrolu 
	if(matrisKontrol(digerSatir,digerSutun) == 0)
	{
		return 0;
	}

	if(ilkSutun != digerSatir)
	{
		cout << "Matrisiniz mxn * n*z formatınde degil!";
		return 0;
	}
	return 1;
}
