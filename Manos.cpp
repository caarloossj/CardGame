#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Manos.hpp"

Carta manoJugador1[NUM_CARTAS_MANO]; //NUM_CARTAS_MANO = 4;
Carta manoJugador2[NUM_CARTAS_MANO];



void IniciarManos()
{
    IniciaMano(1);
    IniciaMano(2);
}

void IniciaMano(int jugador)
{
    srand (time(NULL));

    int secreto1;
    int secreto2;
    int secreto3;

    int secreto4;
    int secreto5;
    int secreto6;

    int indice;
    indice = 0;

    while(indice < 8)
    {
        secreto1 = rand() % 3 + 1;
        secreto2 = rand() % 3 + 1;
        secreto3 = rand() % 3 + 1;
        secreto4 = rand() % 3 + 1;
        secreto5 = rand() % 3 + 1;
        secreto6 = rand() % 3 + 1;

        if(jugador == 1)
        {
            manoJugador1[0] = CreaCarta((TipoCartas)(0));
            manoJugador1[1] = CreaCarta((TipoCartas)(secreto1));
            manoJugador1[2] = CreaCarta((TipoCartas)(secreto2));
            manoJugador1[3] = CreaCarta((TipoCartas)(secreto3));
        }
        else if(jugador == 2)
        {
            manoJugador2[0] = CreaCarta((TipoCartas)(0));
            manoJugador2[1] = CreaCarta((TipoCartas)(secreto4));
            manoJugador2[2] = CreaCarta((TipoCartas)(secreto5));
            manoJugador2[3] = CreaCarta((TipoCartas)(secreto6));
        }
        indice = indice + 1;
    }
}

int EstaVivaMano(int jugador)
{
    int indiceVidaCarta;
    indiceVidaCarta = 0;

    if(jugador == 1)
    {
        for(int i = 0; i < 4; i++)
        {
            indiceVidaCarta = indiceVidaCarta + manoJugador1[i].puntosVida;
            printf("Carta jugador 1: %d, ", manoJugador1[i].puntosVida);
        }
    }
    else if(jugador == 2)
    {
        for(int i = 0; i < 4; i++)
        {
            indiceVidaCarta = indiceVidaCarta + manoJugador2[i].puntosVida;
            printf("Carta jugador 2: %d, ", manoJugador2[i].puntosVida);
        }
    }

    printf("Vida total de la mano: %d. \n", indiceVidaCarta);
    printf("---------------------------------------\n");

    if(indiceVidaCarta > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Carta ObtenCartaMano(int jugador, int indice)
{
    if(jugador == 1 && indice == 0)
    {
        return manoJugador1[0];
    }
    else if(jugador == 1 && indice == 1)
    {
        return manoJugador1[1];
    }
    else if(jugador == 1 && indice == 2)
    {
        return manoJugador1[2];
    }
    else if(jugador == 1 && indice == 3)
    {
        return manoJugador1[3];
    }
    else if(jugador == 2 && indice == 0)
    {
        return manoJugador2[0];
    }
    else if(jugador == 2 && indice == 1)
    {
        return manoJugador2[1];
    }
    else if(jugador == 2 && indice == 2)
    {
        return manoJugador2[2];
    }
    else //(jugador == 2 && indice == 3)
    {
        return manoJugador2[3];
    }
}

void PonCartaMano(int jugador, int indice, Carta carta)
{
    if(jugador == 1)
    {
        manoJugador1[indice] = carta;
    }
    else
    {
        manoJugador2[indice] = carta;
    }
}

void DibujaMano(int posX, int posY, int jugador)
{
    int indice;
    indice = 0;

    posX = 20;
    posY = 1;

    Carta cartaJ1;
    Carta cartaJ2;

    while(indice < 4)
    {
        if(jugador == 1)
        {
            cartaJ1 = manoJugador1[indice];
            DibujaCarta(posX, posY, cartaJ1);                    
        }
        else if(jugador == 2)
        {
            posY = 11;
            cartaJ2 = manoJugador2[indice];
            DibujaCarta(posX, posY, cartaJ2);  
        }

        indice = indice + 1;
        posX = posX + 9;
    }
}

void FinalizaManos()
{

}