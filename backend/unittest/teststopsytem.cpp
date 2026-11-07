// teste para verificar o  interrompimento do jato de resfriamento caso a tampa seja aberta

#include <gtest/gtest.h>
#include "SistemaResfriamento.h"
#include <gmock/gmock.h>

class MockSensorHardware : public ISensorHardware {
    public:
    MOCK_METHOD(bool, isTampaRetirada, (), (override));
    MOCK_METHOD(void, interromperJatoResfriamento, (), (override));

};
// teste1 ,tampa retirada ,parar sistema de jato
TEST(SistemaResfriamento__Test, Pararjatoimediatamente) {

    //arrange
    MockSensorHardware mockhardware;
    Sistemaresfriamento sistema(mockhardware);

    // configuração do mock: pergunta simples se a tampa foi retirada ou não

    EXPECT_CALL(mockhardware, isTampaRetirada())
    .WillOnce(testing::Return(true));

    EXPECT_CALL(mockhardware, Pararjatoimediatamente())
    .Times(1);

    sistema.verificarEstado();

    // explicação simples, a verificação é feita pelo proprio GoogleMOCK no final do escopo do teste




}






int main (int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}