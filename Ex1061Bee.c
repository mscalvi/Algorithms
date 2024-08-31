#include <stdio.h>

int main() {

    int DiaI, HoraI, MinI, SegI, DiaF, HoraF, MinF, SegF;
    int DiaT, HoraT, MinT, SegT;
    long int TempoInicial, TempoFinal, DiferencaSegundos;

    scanf("Dia %d %d : %d : %d Dia %d %d : %d : %d", &DiaI, &HoraI, &MinI, &SegI, &DiaF, &HoraF, &MinF, &SegF);

    TempoInicial = DiaI * 86400 + HoraI * 3600 + MinI * 60 + SegI;
    TempoFinal = DiaF * 86400 + HoraF * 3600 + MinF * 60 + SegF;

    DiferencaSegundos = TempoFinal - TempoInicial;
    
    
    DiaT = DiferencaSegundos / 86400;
    HoraT = (DiferencaSegundos % 86400) / 3600;
    MinT = ((DiferencaSegundos % 86400) % 3600) / 60;
    SegT = ((DiferencaSegundos % 86400) % 3600) % 60;

    printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", DiaT, HoraT, MinT, SegT);

    return 0;
}