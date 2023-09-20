#ifndef __MANOS_HPP__
#define __MANOS_HPP__

#include "Cartas.hpp"

const int NUM_CARTAS_MANO = 4; //o tmb lo podriamos hacer: #define NUM_CARTAS_MANO 4;

void IniciarManos();

void IniciaMano(int jugador);

int EstaVivaMano(int jugador);

Carta ObtenCartaMano(int jugador, int indice);

void PonCartaMano(int jugador, int indice, Carta carta);

void DibujaMano(int posX, int posY, int jugador);

void FinalizaManos();

#endif