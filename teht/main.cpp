#include <iostream>

class Asunto {
public:
    int asukasMaara = (2);
    int neliot = (100);

    Asunto() {
        std::cout << "asunto luotu" << std::endl;
    }

    void maarita(int asukasMaara, int neliot) {
        std::cout << "Asunto maaritetty asukkaita= " << asukasMaara << " nelioita= " << neliot << std::endl;
    }

    double laskeKulutus(double) {
        double kulutus = asukasMaara * neliot;
        return kulutus;
    }
};

class Katutaso {
private:
    Asunto as1;
    Asunto as2;
public:
    Katutaso() {
        std::cout << "Katutaso luotu" << std::endl;
    }
    void maaritaAsunnot() {
        std::cout << "Maaritetaan 2 kpl katutason asuntoja" << std::endl;
        as1.maarita(2, 100);
        as2.maarita(2, 100);
        std::cout << "Maaritetaan katutason kerrokselta perittyja asuntoja" << std::endl;
    }
    double laskeKulutus(double hinta) {
        double totalKulutus = as1.laskeKulutus(hinta) + as2.laskeKulutus(hinta);
        return totalKulutus;
    }
};

class Kerros {
private:
    Asunto as1;
    Asunto as2;
    Asunto as3;
    Asunto as4;
public:
    Kerros() {
        std::cout << "Kerros luotu" << std::endl;
    }
    void maaritaAsunnot() {
        std::cout << "Maaritetaan 4 kpl kerroksen asuntoja" << std::endl;
        as1.maarita(2, 100);
        as2.maarita(2, 100);
        as3.maarita(2, 100);
        as4.maarita(2, 100);

    }
    double laskeKulutus(double hinta) {
        double totalKulutus = as1.laskeKulutus(hinta) + as2.laskeKulutus(hinta) + as3.laskeKulutus(hinta) + as4.laskeKulutus(hinta);
        return totalKulutus;
    }
};

class Kerrostalo {
private:
    Katutaso eka;
    Kerros toka;
    Kerros Kolmas;
public:
    double laskeKulutus(double hinta) {
        std::cout << "Kerrostalo luotu" << std::endl;
        std::cout << "Maaritellaan koko kerrostalon kaikki asunnot" << std::endl;
        eka.maaritaAsunnot();
        toka.maaritaAsunnot();
        Kolmas.maaritaAsunnot();

        double kerrostaloKulutus = eka.laskeKulutus(hinta) + toka.laskeKulutus(hinta) + Kolmas.laskeKulutus(hinta);
        return kerrostaloKulutus;
    };
};

int main() {
    Kerros kerros;
    Kerrostalo kerrostalo;


    double hinta = 1.0;
    double katutasoKulutus = kerros.laskeKulutus(hinta) / 2;
    double kerrosKulutus = kerros.laskeKulutus(hinta) / 2;
    double kerrostalokulutus = kerrostalo.laskeKulutus(hinta);

    kerros.maaritaAsunnot();

    std::cout << "Kerrostalon kulutus, = " << (katutasoKulutus + kerrosKulutus + kerrostalokulutus) << std::endl;

    return 0;
};

