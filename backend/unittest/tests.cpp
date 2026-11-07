#include <gtest/gtest.h>

bool hotambient (double temp) {
    return temp > 35.0;
}
TEST (refresh, test) {

    EXPECT_TRUE (hotambient(36.0));
    EXPECT_TRUE (hotambient(40.0));
    EXPECT_FALSE (hotambient(30.0));
    EXPECT_FALSE (hotambient(20.0));

}


int main (int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}