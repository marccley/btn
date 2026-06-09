# Biblioteca Btn para Arduino

Biblioteca para gerenciamento de botões com tratamento de ruído mecânico (Debounce), suporte a lógica Invertida (NF) e mapeamento completo de eventos físicos.

## Métodos Disponíveis
- `Clicado()`: Retorna `true` como um **pulso único** no exato instante em que o botão é pressionado.
- `Segurado()`: Retorna `true` de forma **contínua** enquanto o botão permanecer pressionado.
- `Liberado()`: Retorna `true` como um **pulso único** no exato instante em que o botão é solto.
- `Temporizado()`: Torna-se `true` após o tempo limite configurado e **permanece ativo** até o botão ser solto.

## Inicialização
```cpp
Btn botao(pino, tipo, tempo_ms);
// Exemplo padrão (NA, 3000ms): Btn botao(2);
```
