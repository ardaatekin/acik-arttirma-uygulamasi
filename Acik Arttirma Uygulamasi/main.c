#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int teklifveren_no;
    double teklif;
} Teklif;

typedef struct {
    int katilimci_sayisi;
    int teklifveren_sayisi;
    Teklif teklifler[50];
} Artirma;

double odemeyi_hesapla(Artirma a, int kazanan_no) {
	int i;
    double enyuksek_teklif = -1.0;
    double odeme = 0.0;
    for (i = 0; i < a.teklifveren_sayisi; i++) {
        if (i != kazanan_no) {
            odeme += a.teklifler[i].teklif;
        }
        if (a.teklifler[i].teklif > enyuksek_teklif) {
            enyuksek_teklif = a.teklifler[i].teklif;
        }
    }
    return odeme;
}

void acikarttirma(Artirma a) {
	int i;
    int kazanan_no = -1;
    double enyuksek_teklif = -1.0;
    for (i = 0; i < a.teklifveren_sayisi; i++) {
        if (a.teklifler[i].teklif > enyuksek_teklif) {
            enyuksek_teklif = a.teklifler[i].teklif;
            kazanan_no = i;
        }
    }
    double odeme = odemeyi_hesapla(a, kazanan_no);
    printf("Odeme: %.2f\n", odeme);
}

int main() {
    Artirma a;
    a.katilimci_sayisi = 3;
    a.teklifveren_sayisi = 3;

    a.teklifler[0].teklifveren_no = 1;
    a.teklifler[0].teklif = 500.0;

    a.teklifler[1].teklifveren_no = 2;
    a.teklifler[1].teklif = 700.0;

    a.teklifler[2].teklifveren_no = 3;
    a.teklifler[2].teklif = 900.0;

    acikarttirma(a);
    return 0;
}
