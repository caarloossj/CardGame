#include "Cartas.hpp"
#include "Tablero.hpp"

void IniciarCartas()
{

}

Carta CreaCarta(TipoCartas tipo)
{
    if(tipo == TIPOCARTA_BLUEDONKEY)
    {
        Carta BlueDonkey;
        BlueDonkey.tipo = (TipoCartas)0;
        BlueDonkey.puntosVida = 15;
        return BlueDonkey;
    }
    else if(tipo == TIPOCARTA_MADELEINE)
    {
        Carta Madeleine;
        Madeleine.tipo = (TipoCartas)1;
        Madeleine.puntosVida = 8;
        return Madeleine;
    }
    else if(tipo == TIPOCARTA_ESPARROU)
    {
        Carta Esparrou;
        Esparrou.tipo = (TipoCartas)2;
        Esparrou.puntosVida = 10;
        return Esparrou;
    }
    else //(tipo == TIPOCARTA_KANEDA)
    {
        Carta Kaneda;
        Kaneda.tipo = (TipoCartas)3;
        Kaneda.puntosVida = 6;
        return Kaneda;
    }
}

int EstaVivaCarta(Carta carta)
{
    if(carta.puntosVida > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Carta AnyadeVidaCarta(Carta carta, int puntos)
{
    carta.puntosVida = carta.puntosVida + puntos;
    return carta;
}

Carta QuitaVidaCarta(Carta carta, int puntos)
{
    carta.puntosVida = carta.puntosVida - puntos;
    if(carta.puntosVida < 0)
    {
        carta.puntosVida = 0;
    }
    return carta;
}

void DibujaCarta(int posX, int posY, Carta carta)
{
    Celda celda1;

    if(carta.tipo == 0)
    {
        celda1.colorFondo = COLOR_AZUL;
        celda1.colorFrente = COLOR_NEGRO;
        celda1.caracter = 'BD';

        RellenaTablero(posX, posY, 7, 7, celda1);
    }
    if(carta.tipo == 1)
    {
        celda1.colorFondo = COLOR_AMARILLO;
        celda1.colorFrente = COLOR_NEGRO;
        celda1.caracter = 'M';

        RellenaTablero(posX, posY, 7, 7, celda1);
    }
    if(carta.tipo == 2)
    {
        celda1.colorFondo = COLOR_ROJO;
        celda1.colorFrente = COLOR_NEGRO;
        celda1.caracter = 'E';

        RellenaTablero(posX, posY, 7, 7, celda1);
    }
    if(carta.tipo == 3)
    {
        celda1.colorFondo = COLOR_VERDE;
        celda1.colorFrente = COLOR_NEGRO;
        celda1.caracter = 'K';

        RellenaTablero(posX, posY , 7, 7, celda1);
    }

    if(carta.tipo == 0 && carta.puntosVida <= 0)
    {
        celda1.colorFondo = COLOR_BLANCO;
        celda1.colorFrente = COLOR_BLANCO;
        celda1.caracter = 'K';

        RellenaTablero(posX, posY , 7, 7, celda1);
    }
    if(carta.tipo == 1 && carta.puntosVida <= 0)
    {
        celda1.colorFondo = COLOR_BLANCO;
        celda1.colorFrente = COLOR_BLANCO;
        celda1.caracter = 'K';

        RellenaTablero(posX, posY , 7, 7, celda1);
    }
    if(carta.tipo == 2 && carta.puntosVida <= 0)
    {
        celda1.colorFondo = COLOR_BLANCO;
        celda1.colorFrente = COLOR_BLANCO;
        celda1.caracter = 'K';

        RellenaTablero(posX, posY , 7, 7, celda1);
    }
    if(carta.tipo == 3 && carta.puntosVida <= 0)
    {
        celda1.colorFondo = COLOR_BLANCO;
        celda1.colorFrente = COLOR_BLANCO;
        celda1.caracter = 'K';

        RellenaTablero(posX, posY , 7, 7, celda1);
    }
}

void FinalizaCartas()
{

}
