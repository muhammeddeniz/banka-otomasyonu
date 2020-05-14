#include <iostream> 
using namespace std; 

int hesapNoSayaci = 0;
void yeniHesapAcildi(){
	hesapNoSayaci++;
}

class Hesap{
	
	
	public:
		bool hesapAcildiMi = false;
		int bakiye;
		int hesapNo;
		string hesapTuru;


	void ParaYatir(int tutar){
		bakiye+= tutar;
	};
	
	bool ParaCek(int tutar){
		if(tutar<bakiye){
			bakiye-=tutar;
			return true;
		}else{
			cout << "Yetersiz Bakiye";
			return false;
		}
	};
	
	void faizHesapla(string hesapturu){
		if(hesapturu == "bireysel" ){
			bakiye*=110/100;
		}else{
			bakiye*=115/100;
		}
	}
};
 
class Musteri  {
	public:
		Hesap hesap[10];
		string isim; 
		int bakiye;	
		string sifre;
};	

 
void hesaplarimiGetir(Musteri m){
	for(int i=0; i<10; i++){
		
		if(m.hesap[i].hesapAcildiMi != false){
			cout << i << ". hesabin Numarasi : ";
			cout << m.hesap[i].hesapNo;
			cout << '\n';
		};
	};
 
};


void hesapIslemleri(Musteri m){
		int secim = 0;
		int tutar = 0;

		cout <<  "1- Para cekme\n";
		cout <<  "2- Para Yatirma\n";
		cout <<  "3- Yeni Hesap Acma\n";
		bool sonuc;

		cin >> secim;		

		switch(secim){
			case 1: 
				cout << "Tutar� Giriniz: ";
				cin >> tutar;
				sonuc = m.hesap[1].ParaCek(tutar);

				if(sonuc){
					cout << "Islem basarili";
				}else{
					cout << "Yetersiz Bakiye";
				}
				break;
			
			case 2:
				cout << "Tutar� Giriniz: ";
				cin >> tutar;

				m.hesap[1].ParaYatir(tutar);
				break;

			case 3:
				cout << "Yeni Hesap A�ma ��lemleri S�r�yor. . .";
		}
}


void butunHesaplariGetir(Musteri m){
	for(int j=0; j<10; j++){
		if(m.hesap[j].hesapAcildiMi == true){
			cout << "hesap no: ";
			cout << m.hesap[j].hesapNo;
			cout << "\n";	
		}
	}
}

Hesap hesapGetir(Musteri m, int hNo){
	for(int j=0; j<10; j++){
		if(m.hesap[j].hesapNo == hNo){
			return m.hesap[j]; 
		}
	} 
}
 
/*__________________________________________________________________________*/
string musteriGirisTuru = ""; 
int maxMusteri = 2000;
int birinciSecim = 0;
string loginIsim= "";
string loginSifre = ""; 
bool giris = false;

Musteri currentMusteri ;

int main(int argc, char** argv) {
	
	 Musteri musteriler[maxMusteri];
	

	/*
	 Denemek icin bir m�steri olusturduk.
	*/
	musteriler[0].isim = "a"; 
	musteriler[0].bakiye = 1000; 
	musteriler[0].sifre = "123";
	musteriler[0].hesap[0].hesapAcildiMi = true;
	musteriler[0].hesap[0].hesapNo = 0;
	musteriler[0].hesap[0].bakiye = 990;
	
	musteriler[0].hesap[1].hesapAcildiMi = true;
	musteriler[0].hesap[1].hesapNo = 1;

	/*
	 hesap no yu kontrol edebilmek icin her acilan hesap sonrasi yeniHesapAcildi() fonksiyonu 
	 hesap noyu arttiriyor
	*/
	yeniHesapAcildi();
	yeniHesapAcildi();

	cout << "***************************************\n";
	cout << "*           Undefined BANK            *\n";
	cout << "***************************************\n\n\n";
	 
 

	cout << "Giris Yapmak icin 1'e basiniz!\n";
  	cout << "Yeni kayit Acmak icin 2'ye basiniz!\n";
  	cin >> birinciSecim;

	switch(birinciSecim){
		case 1: 
			/*
	 			Kayitli bir  kisi ise bu secim ile giris yapacaktir
			*/
			while(!giris){
				cout << "Adinizi Giriniz: ";
				cin >> loginIsim;
				cout << "Sifre: ";
				cin >> loginSifre;

				for(int i=0; i<maxMusteri; i++ ){
					if(musteriler[i].isim == loginIsim &&  musteriler[i].sifre == loginSifre){
						giris = true;
						currentMusteri = musteriler[i];
						cout << "Basarili Giris.\n";
					}else if(i == maxMusteri-1 && giris != true){
						cout << "Hatali Giris.\n";
					}					
				}	
			}
			break;
		
		case 2: 
			/*
	 			Kayit olma islemleri 
			*/
			int temp = 0;
			cout << "�lk Hesap Turunu Seciniz\n";
			cout << "1- Ticari Musteri\n";
			cout << "2- Bireysel Musteri\n";
			cin >> temp;
			if(temp == 1){
				musteriGirisTuru = "Ticari Musteri";
			}else{
				musteriGirisTuru = "Bireysel Musteri";
			}
		
			cout << "Isminizi giriniz: ";
			cin >> musteriler[hesapNoSayaci].isim;
			
			cout << "Sifrenizi giriniz: ";
			cin >> musteriler[hesapNoSayaci].sifre;
			
			musteriler[hesapNoSayaci].hesap[0].hesapTuru = musteriGirisTuru; 
			musteriler[hesapNoSayaci].hesap[0].hesapNo = hesapNoSayaci;
			
			
			cout << "Kayit Basarili\n";
			cout << "Hesap Turunuz: "<<musteriler[hesapNoSayaci].hesap[0].hesapTuru;
			cout << "\nHesap Adiniz: "<<musteriler[hesapNoSayaci].isim;
			cout << "\nHesap Sifresi: "<<musteriler[hesapNoSayaci].sifre;
			
			yeniHesapAcildi();

		
			cout << '\n' << "Devam etmek icin bir tusa basiniz...";
			cin.ignore();
			cin.get();
			system("cls");
			
				/*
	 				Yeni hesap acildiktan sonra giris yapilmasi istenmektedir
				*/
			while(!giris){
				std::cout << "Kayitiniz Tamamlandi simdi Giris Yapabilirsiniz\n";
				std::cout << "Hesap �smi: ";
				std::cin >> loginIsim;
				std::cout << "Sifre: ";
				std::cin >> loginSifre;
					
				for(int i=0; i<maxMusteri; i++ ){
					if(musteriler[i].isim == loginIsim &&  musteriler[i].sifre == loginSifre){
						giris = true;
						currentMusteri = musteriler[i];
						cout << "Basarili Giris.\n";
					}else if(i == maxMusteri-1 && giris != true){
						cout << "Hatali Giris.\n";
					}					
				}	
			}
	  	break;
	}
	
	/*
	LOGIN SONRASI MUSTERI ISLEMLERI
	*/
	cout << '\n' << "Bankamiza Hos Geldiniz\n";
	cout << '\n' << "Devam Etmek icin bir tusa basiniz. . .";

	cin.ignore();
	cin.get();
	system("cls");
	Hesap h ;
	bool logout = false;
	
	
	
	//////// M�sterinin Yeniden islem yapabilmesi icin islemleri While icinde
	while(!logout){
 
		int secimHesapNo;
		std::cout << "**************************************************************\n";
		
		std::cout << "islem yapmak istediginiz hesabi seciniz\n\n";
		
		/*
			Kullaniciya ait butun hesaplar getirildi
		*/
		butunHesaplariGetir(currentMusteri);
		cin >> secimHesapNo;
		
			/*
	 			kullanicinin islem yapmak istedigi hesap getiriliyor
			*/
		h = hesapGetir(currentMusteri, secimHesapNo);
		cout <<"Hesap no : "<< h.hesapNo << "\n";
		cout << "Bakiye: "<< h.bakiye << "\n"; 

		int hesapIslemSecimi = 0;
		cout<< "Hesap ile yapmak istediginiz islemi seciniz. \n";
		cout << "1- Para Yatir\n";
		cout << "2- Para Cek\n";
		cout << "3- Yeni Hesap Ac\n";
		cin >> hesapIslemSecimi;

		int yatirilacakTutar = 0;
		int cekilecekTutar = 0;
		
			/*
	 			Kullanicinin hesap ile yapmak istedigi islem secme kismi
			*/
		switch(hesapIslemSecimi){
			case 1:
				cout << "Yatirilacak tutari Giriniz: ";
				cin >> yatirilacakTutar;
				
				h.ParaYatir(yatirilacakTutar);
				cout << "\nBakiye = "<< h.bakiye;
				cout << "\nIsleminiz tamamlandi Bankamiz iyi gunler diler";
				break;
			
			case 2:
				cout << "Cekilecek tutari Giriniz: ";
				cin >> cekilecekTutar;
				
				h.ParaCek(cekilecekTutar);
				cout << "\nBakiye = "<< h.bakiye;
				cout << "\nIsleminiz tamamlandi Bankamiz iyi gunler diler";
				break;
			
			case 3: 
				// YENI HESAP ACMA ISLEMLERI
			break;
		}

		string cikisSecimi = "";
		cout<< "\nCikis Yapmak �stiyor musunuz? (e & evet  /  h & hayir)";
		cin >> cikisSecimi;

		if(cikisSecimi == "e" || cikisSecimi == "evet" ){
			logout = true;
		}else{
			logout = false;
		}
	}

	return 0;
}
