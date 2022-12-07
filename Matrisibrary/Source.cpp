#include <iostream>
#include "Multiply.h"
#include "Sum.h"
using namespace std;

int main()
{
	int islem;
	cout << "~ Matris Sistemi ~" << endl;
	cout << "#1 Matris Toplama\n"
			"#2 Matris Carpma" << endl;
	cout << "Yapmak istediginiz islemi seciniz: ";
	cin >> islem;

	switch(islem)
	{
	case 1:
		Sum sum = Sum();
		sum.toplam();
		break;
	case 2:
		Multiply m = Multiply();
		m.islem();
		break;
	default:
		cout << "Hatali Tuslama";
	}
	
	return 0;
}