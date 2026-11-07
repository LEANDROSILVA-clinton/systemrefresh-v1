#include <iostream>
#include <functional>
#include "httpapi.h"
#include "ControladorTemperatura.h"
#include "SistemaResfriamento.h"

using namespace std;

struct TemperatureMonitor {
    static constexpr double threshold = 35.0;
    static constexpr double hysteresis = 2.0;
    bool alertActive = false;

    void update(double temperature) {
        cout << "Temperatura atual: " << temperature << " °C\n";

        if (!alertActive && temperature >= threshold) {
            alertActive = true;
            cout << "Alerta: temperatura alta!\n";
        } else if (alertActive && temperature <= threshold - hysteresis) {
            alertActive = false;
            cout << "Temperatura normalizada.\n";
        }
    }
};

// Passe uma função que consulte a API de httpapi.h, grave a temperatura em
// 'temperature' e retorne true se a consulta tiver sucesso.
void monitorTemperature(const function<bool(double&)>& fetchTemperature) {
    double temperature = 0.0;
    if (!fetchTemperature(temperature)) {
        cerr << "Falha ao obter a temperatura pela API.\n";
        return;
    }

    static TemperatureMonitor monitor;
    monitor.update(temperature);
}
  
int main() {
   
   ControladorTemperatura::ControladorTemperatura(IRefresh& resfriador_param) : resfriador(resfriador_param) {}

   void ControladorTemperatura::processarTemperatura(double temperatura) {
        if (temperatura > 35.0) {
            resfriador.ativarjato();
        } else {
            resfriador.desativarjato();
        }
    }

    void SistemaResfriamento::verificarEstado() {
        if (hardware.isTampaRetirada()) {
            hardware.interromperJatoResfriamento();
        }
    }
  
    return 0;
}