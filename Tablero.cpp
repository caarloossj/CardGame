#include "Tablero.hpp"
#include <windows.h>
#include <stdio.h>

HANDLE  handleConsola;

int anchoTablero;
int altoTablero;

Celda* celdas;
Celda celdaBorde;

WORD _ColorAAtributo(Color color, int esFrente)
{
    if(color == COLOR_NEGRO)
    {
        return 0;  
    }
    else if(color == COLOR_BLANCO)
    {
        return esFrente ? FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED : 
                          BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
    }
    else if(color == COLOR_ROJO)
    {
        return esFrente ? FOREGROUND_RED : 
                          BACKGROUND_RED;
    }
    else if(color == COLOR_VERDE)
    {
        return esFrente ? FOREGROUND_GREEN : 
                          BACKGROUND_GREEN;
    }
    else if(color == COLOR_AZUL)
    {
        return esFrente ? FOREGROUND_BLUE : 
                          BACKGROUND_BLUE;
    }
    else if(color == COLOR_AMARILLO)
    {
        return esFrente ? FOREGROUND_GREEN | FOREGROUND_RED : 
                          BACKGROUND_GREEN | BACKGROUND_RED;
    }
    else if(color == COLOR_FUCSIA)
    {
        return esFrente ? FOREGROUND_BLUE | FOREGROUND_RED : 
                          BACKGROUND_BLUE | BACKGROUND_RED;
    }    
    else // color == COLOR_CYAN
    {
        return esFrente ? FOREGROUND_BLUE | FOREGROUND_GREEN : 
                          BACKGROUND_BLUE | BACKGROUND_GREEN;
    }    
    
}


void _PonAtributos(Color frente, Color fondo)
{
    WORD atributoFrente = _ColorAAtributo(frente, 1);
    WORD atributoFondo = _ColorAAtributo(fondo, 0);
    
    SetConsoleTextAttribute(handleConsola, atributoFrente | atributoFondo);
}

void _LimpiarAtributos()
{
    _PonAtributos(COLOR_BLANCO, COLOR_NEGRO);
}

void _DibujaCelda(Celda c)
{
    _PonAtributos(c.colorFrente, c.colorFondo);
    
    printf("%c", c.caracter);
    
}

void _LimpiaConsola()
{
    COORD origen  = { 0, 0 };
    WORD blanco = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO pantalla;
    DWORD caracteresEscritos;

    GetConsoleScreenBufferInfo(handleConsola, &pantalla);
    FillConsoleOutputCharacterA(handleConsola, ' ', pantalla.dwSize.X * pantalla.dwSize.Y, origen, &caracteresEscritos);
    FillConsoleOutputAttribute(handleConsola, blanco, pantalla.dwSize.X * pantalla.dwSize.Y, origen, &caracteresEscritos);
    SetConsoleCursorPosition(handleConsola, origen);
    
}


void IniciaTablero(int ancho, int alto)
{
    anchoTablero = ancho;
    altoTablero = alto;
    
    celdas = (Celda*)malloc(sizeof(Celda) * ancho * alto);
    
    Celda celda;
    
    celda.colorFondo = COLOR_BLANCO;
    celda.colorFrente = COLOR_NEGRO;
    celda.caracter = ' ';
    
    for(int i = 0; i < anchoTablero * altoTablero; i ++) { celdas[i] = celda; }
    
    handleConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    
    celdaBorde = Celda();
    celdaBorde.colorFondo = COLOR_ROJO;
    celdaBorde.colorFondo = COLOR_FUCSIA;
    celdaBorde.caracter = '#';
    

    
}

void LimpiaTablero()
{
    Celda celda;
    
    celda.colorFondo = COLOR_BLANCO;
    celda.colorFrente = COLOR_NEGRO;
    celda.caracter = ' ';
    
    for(int i = 0; i < anchoTablero * altoTablero; i ++) { celdas[i] = celda; }    
}

void RellenaTablero(int posX, int posY, int ancho, int alto, Celda celda)
{    
    for(int y = posY; y < posY + alto; y ++)
    {
        for(int x = posX; x < posX + ancho; x ++)
        {
            if(x >= 0 && x < anchoTablero && y >= 0 && y < altoTablero)
            {
                celdas[y * anchoTablero + x] = celda;
            }
        }
    }
}

void PonCeldaTablero(int posX, int posY, Celda celda)
{
    if(posX >= 0 && posX < anchoTablero && posY >= 0 && posY < altoTablero)
    {
        celdas[posY * anchoTablero + posX] = celda;
    }    
}

void DibujaTablero()
{
    _LimpiaConsola();
    
    for(int x = 0; x < anchoTablero + 2; x ++)
    {
        _DibujaCelda(celdaBorde);
    }
    
    _LimpiarAtributos();
    printf("\n");

    for(int y = 0; y < altoTablero; y ++)
    {
        _DibujaCelda(celdaBorde);

        for(int x = 0; x < anchoTablero; x ++)
        {
            Celda celda = celdas[y * anchoTablero + x];
            
            _DibujaCelda(celda);
            
        }
        
        _DibujaCelda(celdaBorde);

        _LimpiarAtributos();
        printf("\n");
    }        

    for(int x = 0; x < anchoTablero + 2; x ++)
    {
        _DibujaCelda(celdaBorde);        
    }
    
    _LimpiarAtributos();
    printf("\n");
    
}


void FinalizaTablero()
{
    free(celdas);
}