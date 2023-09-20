#ifndef __CARTAS_HPP__
#define __CARTAS_HPP__

enum TipoCartas
{
    TIPOCARTA_BLUEDONKEY, //0
    TIPOCARTA_MADELEINE, // 1
    TIPOCARTA_ESPARROU, //2
    TIPOCARTA_KANEDA, //3
};

struct Carta
{
    TipoCartas tipo;
    int puntosVida;
};


void IniciarCartas();

Carta CreaCarta(TipoCartas tipo);

int EstaVivaCarta(Carta carta);

Carta AnyadeVidaCarta(Carta carta, int puntos);

Carta QuitaVidaCarta(Carta carta, int puntos);

void DibujaCarta(int posX, int posY, Carta carta);

void FinalizaCartas();
#endif