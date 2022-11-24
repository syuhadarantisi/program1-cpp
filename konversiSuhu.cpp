#include <iostream>

using namespace std;

const int CELCIUS = 1, KELVIN = 2, REAMUR = 3, FAHRENHEIT = 4;

/* === Konversi Suhu dari Celcius ===  */
float konverCelRea (float Cel){
    float Rea = (float)4/5 * Cel;
    return Rea;
}

float konverCelFah (float Cel){
    float Fah = (float)9/5 * Cel + 32;
    return Fah;
}

float konverCelKel (float Cel){
    float Kel = Cel + 273;
    return Kel;
}

/* === Konversi Suhu dari Kelvin ===  */
float konverKelCel (float Kel){
    float Cel = Kel - 273;
    return Cel;
}

float konverKelRea (float Kel){
    float Rea = (Kel - 273) * 4/5;
    return Rea;
}

float konverKelFah (float Kel){
    float Fah = (float)9/5 * (Kel - 273) + 32;
    return Fah;
}

/* === Konversi Suhu dari Reamur ===  */
float konverReaCel(float rea)
{
    float cel = rea / 0.8;
    return cel;
}

float konverReaFar(float rea)
{
    float far = rea * 2.25 + 32;
    return far;
}

float konverReaKel(float rea)
{
    float kel = rea / 0.8 + 273.15;
    return kel;
}



/* === Konversi Suhu dari Farenheit ===  */
float konverFarCel(float far){
	float celcius = (far - 32) * 5/9; 
	return celcius;
}

float konverFarRea(float far){
	float reamur = konverFarCel(far) * 4/5; 
	return reamur;
}

float konverFarKel(float far){
	float kelvin = konverFarCel(far) + 273.15; 
	return kelvin;
}


float prosesKonversi(int suhuAwal, int suhuAkhir, float derajatAwal){
	float hasil;
	switch(suhuAwal){
		case CELCIUS:
			switch(suhuAkhir){
				case CELCIUS: hasil = derajatAwal; break; 
				case KELVIN: hasil = konverCelKel(derajatAwal); break;
				case REAMUR: hasil = konverCelRea(derajatAwal); break;
				case FAHRENHEIT: hasil = konverCelFah(derajatAwal); break;
			}
			break;
		case KELVIN:
			switch(suhuAkhir){
				case CELCIUS: hasil = konverKelCel(derajatAwal); break;
				case KELVIN: hasil = derajatAwal; break;
				case REAMUR: hasil = konverKelRea(derajatAwal); break;
				case FAHRENHEIT: hasil = konverKelFah(derajatAwal); break;
			}
			break;
		case REAMUR:
			switch(suhuAkhir){
				case CELCIUS: hasil = konverReaCel(derajatAwal); break;
				case KELVIN: hasil = konverReaKel(derajatAwal); break;
				case REAMUR: hasil = derajatAwal; break;
				case FAHRENHEIT: hasil = konverReaFar(derajatAwal); break;
			}
			break;
		case FAHRENHEIT:
			switch(suhuAkhir){
				case CELCIUS: hasil = konverFarCel(derajatAwal); break; 
				case KELVIN: hasil = konverFarKel(derajatAwal); break;
				case REAMUR: hasil = konverFarRea(derajatAwal); break;
				case FAHRENHEIT: hasil = derajatAwal; break;
			}
			break;
	}
	return hasil;
}

int main(){
	int suhuAwal, suhuAkhir;
	float derajatAwal, derajatAkhir; 
	char lagi;


	do {
		cout << " Pilih Suhu yang ingin dikonversi : \n\n";
		cout << " 1. Celcius\n";
		cout << " 2. Kelvin\n";
		cout << " 3. Reamur\n";
		cout << " 4. Farenheit\n\n";
		cout << " Pilih suhu : ";cin >> suhuAwal;
		cout << " Masukkan suhu : "; cin >> derajatAwal;

		cout << "\n =========================================== \n" << endl;

		cout << " Pilih Suhu Akhir : \n";
		cout << " 1. Celcius\n";
		cout << " 2. Kelvin\n";
		cout << " 3. Reamur\n";
		cout << " 4. Farenheit\n\n";
		cout << " Pilih suhu : ";cin >> suhuAkhir;

		cout << "\n =========================================== \n" << endl;

		derajatAkhir = prosesKonversi(suhuAwal, suhuAkhir, derajatAwal);
		cout << "HASIL KONVERSI : " << derajatAkhir << endl;

		cout << "\nApakah anda ingin mengulang program ? (y/n) : "; cin >> lagi;
	} while(lagi != 'n' && lagi != 'N');

	return 0;
}





