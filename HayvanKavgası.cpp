#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class kullanici {
    private:
        string isim = " ";
        int skor = 0;

    public:
        kullanici(string isim, int skor) {
            this->isim = isim;
            this->skor = skor;
        }

        string getIsim() {
            return isim;
        }
        int getSkor() {
            return skor;
        }
};

class hayvan {
protected:

    //----- Yemekler -----
    int kucuk_yemek = 1;
    int orta_yemek = 1;
    int buyuk_yemek = 0;
    //--------------------

    string turu = "hayvan";
    int can = 100;
    int hasar = 10;
    int kritik_hasar = 13;
    int sans = 25;

    //Seviye
    int tecrube_ozu = 0;
    int tecrube = 0;
    int seviye = 1;
    int hedef_tecrube = 100;

public:
    virtual ~hayvan() {}
    virtual void sescikar() {
        cout << "Ses cikarildi" << endl;
    }

    void canGoster() {
        cout << "Anlik can: " << can << endl;
    }
    int getCan() {
        return can;
    }
    int getSans() {
        return sans;
    }
    int getHasar() {
        return hasar;
    }
    int getKritikHasar() {
        return kritik_hasar;
    }
    int canDegistir(int miktar) {
        if (can <= miktar) {
            can = 0;
            return can;
        }
        else {
            return can -= miktar;
        }
    }

    string getTur() {
        return turu;
    }

    void bilgileriGoster() {
        cout << "--- Hayvan Bilgileri ---" << endl;
        cout << "Hayvanin Turu: " << turu << endl;
        cout << "Saglik: " << can << endl;
        cout << "Hasar: " << hasar << endl;
        cout << "Kritik hasar: " << kritik_hasar << endl;
        cout << "Kritik sans: %" << sans << endl;
    }

    //Yemek Fonksiyonları
    int getKucukYemek() {
        return kucuk_yemek;
    }
    int getOrtaYemek() {
        return orta_yemek;
    }
    int getBuyukYemek() {
        return buyuk_yemek;
    }

    void YemekYe(int yemek_tipi) {

        int max_can = 0;

        if (getTur() == "Kopek") max_can = 125;
        else if (getTur() == "Kedi") max_can = 100;
        else if (getTur() == "Aslan") max_can = 150;

        if (yemek_tipi == 1 /*Kucuk yemek */ && kucuk_yemek > 0) {
            can += 15;
            kucuk_yemek--;
            cout << "Kucuk yemek yendi: can + 15" << endl;
        }
        else if (yemek_tipi == 2 /*Orta yemek*/ && orta_yemek > 0) {
            can += 30;
            orta_yemek--;
            cout << "Orta yemek yendi: can + 30" << endl;
        }
        else if (yemek_tipi == 3 /*Buyuk yemek*/ && buyuk_yemek > 0) {
            can += 45;
            buyuk_yemek--;
            cout << "Buyuk yemek yendi: can + 45" << endl;
        }
        else {
            cout << "Bu yemekten elinde yok" << endl;
        }

        if (can > max_can) can = max_can;
    }

    void yemekAl(int yemekTipi) {
        if (yemekTipi == 1) {
            kucuk_yemek++;
            cout << "Kucuk yemek dustu" << endl;
        }
        else if (yemekTipi == 2) {
            orta_yemek++;
            cout << "Orta yemek dustu" << endl;
        }
        else if (yemekTipi == 3) {
            buyuk_yemek++;
            cout << "Buyuk yemek dustu" << endl;
        }


    }

    void yemekGoster() {
        cout << "------- Yemek Menu -------" << endl;
        cout << "Hayvanin cani: " << getCan() << endl;
        cout << "1.Kucuk yemek miktari: " << kucuk_yemek << endl;
        cout << "2.Orta yemek miktari: " << orta_yemek << endl;
        cout << "3.Buyuk yemek miktari: " << buyuk_yemek << endl;
    }


    //Seviye fonsiyonları
    int getSeviye() {
        return seviye;
    }
    int getTecrube() {
        return tecrube;
    }
    int getHedefTecrube() {
        return hedef_tecrube;
    }
    int getTecrubeOzu() {
        return tecrube_ozu;
    }
    
    void tecrubAl(int tecrubeMiktari) {
        tecrube += tecrubeMiktari;
        
        if (tecrube >= hedef_tecrube) {
            seviye++;
            tecrube = 0;
            cout << "Seviye Atlandı" << endl;
            hasar += 5;
            kritik_hasar += 5;
        }
    }

};

class kopek : public hayvan {
    private:

    public:
        kopek() {
            tecrube_ozu = 30;
            turu = "Kopek";
            can = 125;
            hasar = 13;
            kritik_hasar = 20;
            sans = 15;
        }
        void sescikar() override {
            cout << "Hav havv..." << endl;
        }
};

class kedi : public hayvan {
    private:


    public:
        kedi() {
            tecrube_ozu = 25;
            turu = "Kedi";
            can = 100;
            hasar = 10;
            kritik_hasar = 15;
            sans = 20;
        }
        void sescikar() override {
            cout << "Miyav..." << endl;
        }
};

class aslan : public hayvan {
    private:


    public:
        aslan() {
            tecrube_ozu = 30;
            turu = "Aslan";
            can = 150;
            hasar = 17;
            kritik_hasar = 25;
            sans = 10;
        }
        void sescikar() override {
            cout << "Roaar..." << endl;
        }
};

int aksiyon(hayvan* benimHayvanim);
int kacis(hayvan* benimHayvanim, hayvan* dusmanHayvan);
int saldir(hayvan* benimHayvanim, hayvan* dusmanHayvan);
int savasMenu(hayvan* benimiHayvanim, hayvan* dusmanHayvan);
void yemekMenu(hayvan* benimHayvanim);
void skoruKaydet(string isim, int skor);
void dataKaydet(string isim, int skor);
void dataCek();
hayvan* dusmanSecim();
hayvan* menu(string* isim);
hayvan* hayvanSecim();


int main()
{
    string isim = "";
    int skor = 0;
    int ne_oldu = -1;//1: geçti , 2.öldü
    
    srand((unsigned int)time(0));
    
    dataCek();
    hayvan* benimHayvanim = menu(&isim);
    hayvan* dusmanHayvan = nullptr;

    
    do {

        int donus = aksiyon(benimHayvanim);

        if (donus == -1) {

            dusmanHayvan = dusmanSecim();
            ne_oldu = savasMenu(benimHayvanim, dusmanHayvan);

            if (ne_oldu == 1) {
                system("cls");

                cout << "--- Savas Sonucu ---" << endl;
                if ((rand() % 100) < 60) {
                    benimHayvanim->yemekAl((rand() % 3) + 1);
                }

                cout << "Tecrube alindi: +" << dusmanHayvan->getTecrubeOzu() << endl;
                benimHayvanim->tecrubAl(dusmanHayvan->getTecrubeOzu());

                if (dusmanHayvan->getTur() == "Kedi") skor += 10;
                else if (dusmanHayvan->getTur() == "Kopek") skor += 15;
            }
            delete dusmanHayvan;
            dusmanHayvan = nullptr;
        }
        else if (donus == 0) {
            skoruKaydet(isim, skor);
            dataKaydet(isim, skor);
            break;
        }

        if (ne_oldu == 2) {
            int secim;

            cout << "Skorunuz: " << skor << endl;

            cout << "\n1.Tekrar Dene" << endl;
            cout << "Cikmak icin baska tusa basin..." << endl;
            cout << "Seciminiz: ";
            cin >> secim;
            cin.ignore();

            if (secim == 1) {
                skoruKaydet(isim, skor);
                dataKaydet(isim, skor);
                delete benimHayvanim; 
                skor = 0;
                isim = "";
                benimHayvanim = menu(&isim);
                ne_oldu = -1;
            }
            else {
                dataKaydet(isim, skor);
                skoruKaydet(isim, skor);
                break;
            }

        }
    } while (ne_oldu != 2);

    system("pause");
    return 0;
}
void skoruKaydet(string isim, int skor) {

    ofstream log("Kayitlar\\log.txt", ios::app);

    if (log.is_open()) {
        log << "İsim: " << isim << ", Skor: " << skor << endl;
        log << " " << endl;;
        log.close();
        cout << "-->Dosya Kaydedildi" << endl;
    }
    else {
        cout << "Dosya Acilamadi" << endl;
    }

}

void dataKaydet(string isim, int skor) {
    fstream data("Kayitlar\\data.txt", ios::app);

    if (data.is_open()) {
        data << isim << "," << skor << endl;
        data.close();
    }
    else {
        cout << "Data Dosyasi Acilamadi" << endl;
    }

}

void dataCek() {
    ifstream dosyaoku("Kayitlar\\data.txt");
    string isim = "";
    string skorString = "";
    vector<kullanici> skorlar;

    if (dosyaoku.is_open()) {
        
        
        while (getline(dosyaoku, isim, ',')) {
           
            if (getline(dosyaoku, skorString)) {
                if (!skorString.empty()) {
                    skorlar.push_back(kullanici(isim, stoi(skorString)));
                }
            }
        }
        dosyaoku.close();
        cout << "\n--- LIDERLIK TABLOSU ---" << endl;

        int sayac = 0;
        int max;

        for (int i = 0; i < skorlar.size() && i < 10; i++) {

            for (int j = 0; j < skorlar.size() - 1; j++) {

                if (skorlar[j].getSkor() < skorlar[j + 1].getSkor()) {
                    kullanici gecici = skorlar[j];
                    skorlar[j] = skorlar[j + 1];
                    skorlar[j + 1] = gecici;
                }

            }

        }

        for (int i = 0; i < skorlar.size() && i < 10; i++) {
            cout << i + 1 << "." << skorlar[i].getIsim() << ": " << skorlar[i].getSkor() << endl;
        }


        cout << "-----------------------" << endl;
        system("pause"); 
    }
    else {
        cout << "Dosya Okunamadi!" << endl;
    }
}

hayvan* menu(string* isim) {

    int secim = 0;

    do {
        cout << "Kullanici adi giriniz: ";
        getline(cin, *isim);

        system("cls");
        cout << "\n------- MENU ------" << endl;
        cout << "1.Basla\n0.Cikis" << endl;
        cout << "Secimin: ";

        cin >> secim;
        cout << "-------------------" << endl;

        if (secim != 1 && secim != 0) {
            cout << "Gecersiz secim!!" << endl;
        }
    } while (secim != 0 && secim != 1);
    system("cls");

    switch (secim) {
    case 0:
        return nullptr;
        break;
    case 1:
        return hayvanSecim();
    default:
        return nullptr;

    }

}

hayvan* hayvanSecim() {
    int i = 0;
    int secim = 0;
    hayvan* yeniHayvan = nullptr;
    do {
        cout << "\n---- Hayvanlar ----" << endl;
        cout << "1.Kedi\n2.Kopek\n3.Aslan\n" << endl;
        cout << "Seciminiz: ";
        cin >> secim;


        switch (secim) {
        case 1:
            yeniHayvan = new kedi();
            break;
        case 2:
            yeniHayvan = new kopek();
            break;
        case 3:
            yeniHayvan = new aslan();
            break;
        default:
            system("cls");
            cout << "Gecersiz hayvan" << endl;
            continue;
            break;
        }

        i++;
        system("cls");

    } while (yeniHayvan == nullptr);

    return yeniHayvan;

}

int aksiyon(hayvan* benimHayvanim) {

    if (benimHayvanim == nullptr) return 0;

    int secim = -1;
    do {
        cout << "Seviyen: " << benimHayvanim->getSeviye() << "   Tecruben: " << benimHayvanim->getTecrube() << endl;
        cout << "\n--- Aksiyonlar -----" << endl;
        cout << "1.Ses cikar" << endl;
        cout << "2.Hayvan Bilgileri" << endl;
        cout << "3.Yemek Ye" << endl;
        cout << "4.Hayvan Degistir" << endl;
        cout << "5.Savasa Gec" << endl;
        cout << "0.Cikis" << endl;
        cout << "Secimin: ";
        cin >> secim;

        system("cls");

        switch (secim) {
        case 1:
            benimHayvanim->sescikar();
            break;

        case 2:
            benimHayvanim->bilgileriGoster();
            system("pause");
            system("cls");
            break;
        case 3:
            yemekMenu(benimHayvanim);
            break;
        case 4:
            delete benimHayvanim;
            benimHayvanim = hayvanSecim();
            break;
        case 5:
            return -1;
            break;
        case 0:
            return 0;
            break;

        default:

            cout << "Hatali secim" << endl;
            continue;
            break;
        }

    } while (secim != 0);

    return 0;
}

hayvan* dusmanSecim() {
    int secim = -1;
    hayvan* dusmanHayvan = nullptr;
    system("cls");

    int rastgele = 1 + (rand() % 2);

    if (rastgele == 1) {
        dusmanHayvan = new kedi();
    }
    else {
        dusmanHayvan = new kopek();
    }

    return dusmanHayvan;
}

int savasMenu(hayvan* benimHayvanim, hayvan* dusmanHayvan) {

    int secim = -1;
    int ne_oldu = 0;//1: kacti , 2: öldü

    system("cls");

    cout << "Karsina cikti: " << dusmanHayvan->getTur() << " (Can: " << dusmanHayvan->getCan() << ")" << endl;

    do {
        cout << "Senin Canin: " << benimHayvanim->getCan() << "    Dusmanin Cani: " << dusmanHayvan->getCan() << endl;

        cout << "\n---- Savas Menusu ----" << endl;
        cout << "1.Saldir (Sans -> Kritik Hasar)" << endl;
        cout << "2.Kac (Kacma Sansi = Sans)" << endl;
        cout << "3.Yemek Ye" << endl;
        cout << "Secimin: ";
        cin >> secim;

        switch (secim) {
        case 1: {
            ne_oldu = saldir(benimHayvanim, dusmanHayvan);
            if (ne_oldu == 2) return 2;
            else if (ne_oldu == 1) return 1;
            break;
        }
        case 2: {
            ne_oldu = kacis(benimHayvanim, dusmanHayvan);
            if (ne_oldu == 2) return 2;
            else if (ne_oldu == 1) return 1;
            break;
        }
        case 3:
            yemekMenu(benimHayvanim);
            break;
        default:
            system("cls");
            cout << "Gecersiz Secim" << endl;
            continue;
            break;
        }
        system("cls");
    } while (ne_oldu != 1 && benimHayvanim->getCan() != 0 && dusmanHayvan->getCan() != 0);
    return 0;
}

int saldir(hayvan* benimHayvanim, hayvan* dusmanHayvan) {

    int benim_oran = benimHayvanim->getSans();
    int dusman_oran = dusmanHayvan->getSans();

    int benim_hasar = benimHayvanim->getHasar();
    int dusman_hasar = dusmanHayvan->getHasar();

    int benim_kritik_hasar = benimHayvanim->getKritikHasar();
    int dusman_kritik_hasar = dusmanHayvan->getKritikHasar();

    if (((rand() % 100) + 1) <= benim_oran) {
        dusmanHayvan->canDegistir(benim_kritik_hasar);
        cout << "\nKritik vurdun: -" << benim_kritik_hasar << endl;
    }
    else {
        dusmanHayvan->canDegistir(benim_hasar);
        cout << "\nKritik vuramadin: -" << benim_hasar << endl;
    }

    cout << "Dusman cani: " << dusmanHayvan->getCan() << endl;
    if (dusmanHayvan->getCan() == 0) {
        cout << "Dusmani Yendin" << endl;

        //Random yemek düşme ( %60 ihtimalle )
        
        system("pause");
        return 1;
    }

    system("pause");

    if (((rand() % 100) + 1) <= dusman_oran) {
        benimHayvanim->canDegistir(dusman_kritik_hasar);
        cout << "\nDusman Kritik vurdu: -" << dusman_kritik_hasar << endl;
    }
    else {
        benimHayvanim->canDegistir(dusman_hasar);
        cout << "\nDusman Kritik vuramadi: -" << dusman_hasar << endl;
    }

    cout << "Kalan canin: " << benimHayvanim->getCan() << endl;


    if (benimHayvanim->getCan() == 0) {
        cout << "Hayvanin Oldu KAYBETTIN" << endl;
        return 2;
    }

    system("pause");
    return 0;
}

int kacis(hayvan* benimHayvanim, hayvan* dusmanHayvan) {
    int benim_kacis_oran = benimHayvanim->getSans();

    if ((rand() % 100) + 1 <= benim_kacis_oran) {
        cout << "\nKacma eylemi basarili..." << endl;
        system("pause");
        return 1;
    }
    else {
        cout << "\nKacma eylemi basarisiz..." << endl;
        cout << "Dusman arkandan saldiriyor" << endl;

        int dusman_oran = dusmanHayvan->getSans();
        int dusman_hasar = dusmanHayvan->getHasar();
        int dusman_kritik_hasar = dusmanHayvan->getKritikHasar();

        if (((rand() % 100) + 1) <= dusman_oran) {
            benimHayvanim->canDegistir(dusman_kritik_hasar);
            cout << "\nDusman arkandan Kritik vurdu: -" << dusman_kritik_hasar << endl;
        }
        else {
            benimHayvanim->canDegistir(dusman_hasar);
            cout << "\nDusman arkandan vurdu: -" << dusman_hasar << endl;
        }

        cout << "Kalan canin: " << benimHayvanim->getCan() << endl;


        if (benimHayvanim->getCan() == 0) {
            cout << "Hayvanin Oldu KAYBETTIN" << endl;
            return 2;
        }
        system("pause");
        return 0;
    }

}

void yemekMenu(hayvan* benimHayvanim) {
    int secim = -1;

    system("cls");

    do {

        benimHayvanim->yemekGoster();
        cout << "0.Vazgec" << endl;
        cout << "Seciminiz: ";
        cin >> secim;

        if (secim == 0) {
            break;
        }
        else if (secim < 1 || secim > 3) {
            cout << "Gecersiz Secim..." << endl;
            continue;
        }
        benimHayvanim->YemekYe(secim);

        break;
    } while (secim >= 1 && secim <= 3);
    system("cls");
}
