#include "Btn.h"

Btn::Btn(int _pino, int _tipo, unsigned long _tempoMs) {
    pino = _pino;
    tipo = _tipo;
    tempoLimiteTemporizado = _tempoMs;
    tempoDebounce = 50;
    ultimoTempoDebounce = 0;
    disparouTemporizado = false;
    acabouDeLiberar = false;
    acabouDeClicar = false;

    if (tipo == NF) {
        pinMode(pino, INPUT_PULLUP);
        estadoAnterior = HIGH;
        estadoEstavel = HIGH;
    } else {
        pinMode(pino, INPUT);
        estadoAnterior = LOW;
        estadoEstavel = LOW;
    }

    tempoPressionado = 0;
    pressionado = false;
}

void Btn::atualizar() {
    int leituraAtual = digitalRead(pino);

    if (leituraAtual != estadoAnterior) {
        ultimoTempoDebounce = millis();
    }

    if ((millis() - ultimoTempoDebounce) > tempoDebounce) {
        if (leituraAtual != estadoEstavel) {
            estadoEstavel = leituraAtual;

            bool estaAtivo = (tipo == NF) ? (estadoEstavel == LOW) : (estadoEstavel == HIGH);

            if (estaAtivo) {
                tempoPressionado = millis();
                pressionado = true;
                disparouTemporizado = false;
                acabouDeClicar = true; // Ativa o pulso único de clique
            }
            else {
                if (pressionado) {
                    acabouDeLiberar = true; // Ativa o pulso único de liberação
                }
                pressionado = false;
                disparouTemporizado = false;
            }
        }
    }

    estadoAnterior = leituraAtual;
}

bool Btn::Clicado() {
    atualizar();
    // Retorna true APENAS no instante em que aperta e limpa a flag em seguida
    if (acabouDeClicar) {
        acabouDeClicar = false;
        return true;
    }
    return false;
}

bool Btn::Segurado() {
    atualizar();
    // Retorna true continuamente enquanto o botão estiver ativo
    return (tipo == NF) ? (estadoEstavel == LOW) : (estadoEstavel == HIGH);
}

bool Btn::Liberado() {
    atualizar();
    if (acabouDeLiberar) {
        acabouDeLiberar = false;
        return true;
    }
    return false;
}

bool Btn::Temporizado() {
    atualizar();

    if (pressionado && (millis() - tempoPressionado >= tempoLimiteTemporizado)) {
        disparouTemporizado = true;
    }

    if (disparouTemporizado && pressionado) {
        return true;
    }

    return false;
}
