#include <Btn.h>

// Botão configurado como NF no pino 3 com 3 segundos de tempo limite
Btn botao(3, NF, 3000);

void setup() {
    Serial.begin(9600);
}

void loop() {
    // 1. Clicado: Só aparece UMA vez quando você aperta (mesmo se continuar segurando)
    if (botao.Clicado()) {
        Serial.println("-> Evento: Botao foi CLICADO! (Pulso unico)");
    }

    // 2. Segurado: Aparece continuamente enquanto o botão estiver afundado
    if (botao.Segurado()) {
        // Descomente a linha abaixo se quiser ver o fluxo contínuo no Monitor Serial
        // Serial.println("Botao esta sendo SEGURADO...");
    }

    // 3. Temporizado: Aciona após 3 segundos e fica ativo até soltar
    if (botao.Temporizado()) {
        Serial.println("-> Estado: TEMPORIZADO ATIVO (Segurando a mais de 3s)");
    }

    // 4. Liberado: Só aparece UMA vez quando você solta o botão
    if (botao.Liberado()) {
        Serial.println("-> Evento: Botao foi LIBERADO! (Pulso unico)");
        Serial.println("---------------------------------------------");
    }

    delay(10);
}
