#ifndef BTN_H
#define BTN_H

#include <Arduino.h>

#define NA 0
#define NF 1

class Btn {
private:
    int pino;
    int tipo;
    int estadoAnterior;
    int estadoEstavel;
    unsigned long tempoPressionado;
    unsigned long tempoDebounce;
    unsigned long tempoLimiteTemporizado;
    unsigned long ultimoTempoDebounce;
    bool pressionado;
    bool disparouTemporizado;
    bool acabouDeLiberar;
    bool acabouDeClicar; // Nova flag para o pulso de clique
    void atualizar();

public:
    Btn(int _pino, int _tipo = NA, unsigned long _tempoMs = 3000);
    bool Clicado();
    bool Segurado();
    bool Liberado();
    bool Temporizado();
};

#endif
