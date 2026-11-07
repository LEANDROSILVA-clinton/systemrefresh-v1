//simulação para a tampa e interromper o seu jato
#pragma once

//isolamento o hardware por uma interface

class ISensorHardware {
    public:
    virtual ~ISensorHardware() = default;
    virtual bool isTamparetirada() = 0;
    virtual void interromperJatoResfriamento() = 0;
};

// principal class
class Refreshsystem {
    private:
    ISensorHardware&hardware;

    public:
    Refreshsystem(ISensorHardware& hw) : hardware(hw) {}

    // função abaixo para verificar de forma periodica o sistema
    void verificarEstado() {
        if(hardware.isTamparetirada()) {
            hardware.interromperJatoResfriamento();
        }
    }

};