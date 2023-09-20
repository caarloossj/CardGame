#include "Manos.hpp"
//No importa que incluyamos Cartas.hpp despues
// de Manos.hpp
#include "Cartas.hpp"
#include "Tablero.hpp"

#include <stdio.h>
#include <time.h>
#include <Windows.h>

int jugadorJuega;
int indiceCarta;
int jugadorOponente;
int tiempoEspera;

void ImprimeCarta(Carta c)
{
    printf("Le quedan %d puntos de vida.\n", c.puntosVida);
    printf("Introduce 9 para continuar\n");
}

void UsarCarta(int jugador, Carta carta)
{
    if(carta.tipo == TIPOCARTA_BLUEDONKEY)
    {
        printf("Has usado el BlueDonkey!\n");
        printf("------------------------\n");
        if(EstaVivaCarta(ObtenCartaMano(jugadorJuega, 1)))
        {
            PonCartaMano(jugador, 1, AnyadeVidaCarta(ObtenCartaMano(jugadorJuega, 1), 3));

            ImprimeCarta(ObtenCartaMano(jugador, 1));
        }
        if(EstaVivaCarta(ObtenCartaMano(jugadorJuega, 2)))
        {
            PonCartaMano(jugador, 2, AnyadeVidaCarta(ObtenCartaMano(jugadorJuega, 2), 3));

            ImprimeCarta(ObtenCartaMano(jugador, 2));
        }
        if(EstaVivaCarta(ObtenCartaMano(jugadorJuega, 3)))
        {
            PonCartaMano(jugador, 3, AnyadeVidaCarta(ObtenCartaMano(jugadorJuega, 3), 3));

            ImprimeCarta(ObtenCartaMano(jugador, 3));
        }
    }
    else if(carta.tipo == TIPOCARTA_MADELEINE)
    {
        int quitaVidaMadeleine; 
        
        quitaVidaMadeleine = rand() % 3 + 2;

        do
        {
            printf("A que carta rival quieres atacar\n");
            scanf("%d", &indiceCarta);
        }while(EstaVivaCarta(ObtenCartaMano(jugadorOponente, indiceCarta)) == 0);

        printf("Has usado a Madeleine!\n");
        printf("------------------------\n");

        PonCartaMano(jugadorOponente, indiceCarta, QuitaVidaCarta(ObtenCartaMano(jugadorOponente, indiceCarta), quitaVidaMadeleine));
    
        printf("Has atacado a su carta %d y les has quitado %d puntos de vida\n", indiceCarta, quitaVidaMadeleine);
        printf("------------------------\n");

        ImprimeCarta(ObtenCartaMano(jugadorOponente, indiceCarta));
    }
    else if(carta.tipo == TIPOCARTA_ESPARROU)
    {
        int quitaVidaEsparrou;
        quitaVidaEsparrou = rand() % 6 + 1;
        Carta Esp;
        int randomNumEsp; 
        do
        {
            randomNumEsp = rand() % 4;
        }while(EstaVivaCarta(ObtenCartaMano(jugadorOponente, randomNumEsp)) == 0);

        printf("Has usado a Esparrou!\n");
        printf("------------------------\n");

        Esp = QuitaVidaCarta(ObtenCartaMano(jugadorOponente, randomNumEsp), quitaVidaEsparrou);
        
        PonCartaMano(jugadorOponente, randomNumEsp, Esp);

        printf("Has atacado a su carta %d y les has quitado %d puntos de vida\n", randomNumEsp, quitaVidaEsparrou);
        printf("------------------------\n");

        ImprimeCarta(ObtenCartaMano(jugadorOponente, randomNumEsp));
    }
    else if(carta.tipo == TIPOCARTA_KANEDA)
    {
        printf("Has usado a Kaneda!\n");
        printf("------------------------\n");
        int cambioBando;
        Carta Kan;

        int cartaRandom;
        cartaRandom = rand() % 4;
        int vidaQuitadaKaneda;
        vidaQuitadaKaneda = rand() % 4 + 7;
        int numeroRandom;
        numeroRandom = rand() % 100;

        if(numeroRandom <= 33.3)
        {
            cambioBando = jugadorJuega;
        }
        else
        {
            cambioBando = jugadorOponente;
        }

        int randomNumKan; 
        do
        {
            randomNumKan = rand() % 4;
        }while(EstaVivaCarta(ObtenCartaMano(jugadorOponente, randomNumKan)) == 0);

        Kan = QuitaVidaCarta(ObtenCartaMano(cambioBando, randomNumKan), vidaQuitadaKaneda);

        PonCartaMano(cambioBando, randomNumKan, Kan);

        printf("Has atacado a su carta %d y les has quitado %d puntos de vida\n", randomNumKan, vidaQuitadaKaneda);
        printf("------------------------\n");

        ImprimeCarta(ObtenCartaMano(cambioBando, randomNumKan));


    }
}

void main()
{    

    jugadorJuega = 1;
    jugadorOponente = 2;
    tiempoEspera = 0;

   srand (time(NULL));
 
    IniciarManos();
        
    IniciaTablero(80, 20);

    LimpiaTablero();        
    
    DibujaMano(0, 1, 1);
    DibujaMano(0, 1, 2);

    DibujaTablero();

    printf("Turno jugador 1\n");
    printf("------------------\n");

    while(EstaVivaMano(1) && EstaVivaMano(2))
    {

        do
        {
            printf("Que carta quieres usar?\n");
            scanf("%d", &indiceCarta);

        }while(EstaVivaCarta(ObtenCartaMano(jugadorJuega, indiceCarta)) == 0);

        UsarCarta(jugadorJuega, ObtenCartaMano(jugadorJuega, indiceCarta));

        scanf("%d", &tiempoEspera);

        DibujaMano(0, 1, 1);
        DibujaMano(0, 1, 2);

        DibujaTablero();

        if(jugadorJuega == 1)
        {
            jugadorJuega = 2;
            jugadorOponente = 1;
            printf("Turno jugador 2\n");
            printf("------------------\n");
        }
        else
        {
            jugadorJuega = 1;
            jugadorOponente = 2;
            printf("Turno jugador 1\n");
            printf("------------------\n");
        }
    }

    if(EstaVivaMano(1))
    {
        printf("--------- EL JUGADOR 1 HA GANADO LA PARTIDA!!! ---------\n");
    }

    if(EstaVivaMano(2))
    {
        printf("--------- EL JUGADOR 2 HA GANADO LA PARTIDA!!! ---------\n");
    }

    FinalizaTablero();    
    FinalizaManos();
    FinalizaCartas();
}

