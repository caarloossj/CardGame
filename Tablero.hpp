#ifndef _TABLERO_HPP_
#define _TABLERO_HPP_

enum Color
{
    COLOR_ROJO,
    COLOR_AZUL,
    COLOR_VERDE,
    COLOR_AMARILLO,
    COLOR_FUCSIA,
    COLOR_NEGRO,
    COLOR_BLANCO
    
};

struct Celda
{
    Color colorFondo;
    Color colorFrente;
    char caracter;
};

void IniciaTablero(int ancho, int alto);
void LimpiaTablero();
void RellenaTablero(int posX, int posY, int ancho, int alto, Celda celda);
void PonCeldaTablero(int posX, int posY, Celda celda);
void PonCeldaBordeTablero(Celda celda);
void DibujaTablero();
void FinalizaTablero();

#endif

