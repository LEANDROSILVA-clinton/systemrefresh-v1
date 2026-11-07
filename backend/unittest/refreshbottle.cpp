// teste para ativar o jato de resfriamento caso passe de 35°
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ControladorTemperatura.h"



//criação do MOCK para interface do Iresfriador

class MockRefresh : public IResfriador {
    public:
    MOCK_METHOD(void, ativarjato,(), (override));
    MOCK_METHOD(void , desativarjato, (), (override));
};


// teste 1 , abaixo do limite.

TEST(ControladorTemperatura__Test, tempabaixodolimite) {
    MockRefresh mockresfriar;
    ControladorTemperatura controlador (mockresfriar);

    // é esperado que desativarjato seja chamado ao inves de ativarjato.

    EXPECT_CALL(mockresfriar , ativarjato()).Times(0);
    EXPECT_CALL(mockresfriar, desativarjato()).Times(1);

    controlador.processarTemperatura(34.9);

}

// teste 2, no limite 
TEST(ControladorTemperatura__Test_templimite_Test) {
    MockRefresh mockresfriar;
    ControladorTemperatura controlador (mockresfriar);

    // experado que mesmo que chegue no limite de 34° o jato não seja ativado
    EXPECT_CALL(mockresfriar, ativarjato()).Times(0);
    EXPECT_CALL(mockresfriar, desativarjato()).Times(1);
    controlador.processarTemepratura(35.9);
}


// test 3, ativar o jato ,acima de 35°
TEST (ControladorTemperatura__Test_tempacimalimite_Test) {
    MockRefresh mockresfriar;
    ControladorTemperatura controlador (mockresfriar);

    // esperado que passou do limite de 35° é ativado automaticamente o jato.
    EXPECT_CALL(mockresfriar, ativarjato()).Times(1);
    EXPECT_CALL(mockresfriar, desativarjato()). Times(0);
    controlador.processarTemperatura(35.1);
}

int main (int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}