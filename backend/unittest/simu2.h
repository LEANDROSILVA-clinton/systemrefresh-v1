// simulação voltado ao jato e sua ativação.
#pragma once

class Iresfriador {
    public:
    virtual ~Iresfriador() = default;
    virtual void ativarjato() = 0;
    virtual void desativarjato() = 0;

};

class ControladorTemperatura {
    private:
    Iresfriador& resfriador;


    public:
    ControladorTemperatura(Iresfriador& refResfriador) : resfriador(refResfriador) {}

    void processarTemperatura(double temperatura) {
        if(temperatura > 35.0) {
            resfriador.ativarjato();
        } else {
            resfriador.desativarjato();
        }
    }
};