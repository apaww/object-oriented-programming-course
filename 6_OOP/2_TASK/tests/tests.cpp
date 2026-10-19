#include <gtest/gtest.h>
#include "TemperatureSensor.hpp"

TEST(TemperatureSensor, Default) {
    TemperatureSensor s;
    EXPECT_EQ(s.getCurrentTemperature(), 0.);
    EXPECT_EQ(s.getSize(), 10);
    EXPECT_EQ(s.getCapacity(), 10);
    EXPECT_FALSE(s.getItemId().empty());
    EXPECT_FALSE(s.getInBatchId().empty());
}

TEST(TemperatureSensor, Init) {
    double history[3] = {6.7, 4.2, 2.1};
    TemperatureSensor s("21", "42", 67.0, history, 3, 3);
    EXPECT_EQ(s.getItemId(), "21");
    EXPECT_EQ(s.getInBatchId(), "42");
    EXPECT_EQ(s.getCurrentTemperature(), 67.0);
    EXPECT_EQ(s.getSize(), 3);
    EXPECT_EQ(s.getCapacity(), 3);
}

TEST(TemperatureSensor, Normalize) {
    double history[2] = {-670., 4200.};
    TemperatureSensor s("67", "21", 6700., history, 2, 2);
    EXPECT_EQ(s.getCurrentTemperature(), 1000.);
    EXPECT_EQ(s.getLastTemperatures()[0], -273.);
    EXPECT_EQ(s.getLastTemperatures()[1], 1000.);
}

TEST(TemperatureSensor, EmptyId) {
    double history[1] = {6.7};
    TemperatureSensor s("", "42", 0., history, 1, 1);
    EXPECT_FALSE(s.getItemId().empty());
}

TEST(TemperatureSensor, Copy) {
    double history[2] = {6.7, 4.2};
    TemperatureSensor a("21", "42", 67., history, 2, 2);
    TemperatureSensor b = a;
    EXPECT_EQ(b.getItemId(), "21");
    EXPECT_EQ(b.getCurrentTemperature(), 67.);
    EXPECT_NE(a.getLastTemperatures(), b.getLastTemperatures());
    EXPECT_EQ(b.getLastTemperatures()[0], 6.7);
}

TEST(TemperatureSensor, Assign) {
    double history[2] = {6.7, 4.2};
    TemperatureSensor a("21", "42", 67., history, 2, 2);
    TemperatureSensor b;
    b = a;
    EXPECT_EQ(b.getInBatchId(), "42");
    EXPECT_EQ(b.getCurrentTemperature(), 67.);
    EXPECT_NE(a.getLastTemperatures(), b.getLastTemperatures());
    EXPECT_EQ(b.getLastTemperatures()[1], 4.2);
}

TEST(TemperatureSensor, SelfAssign) {
    double history[1] = {6.7};
    TemperatureSensor a("21", "42", 67., history, 1, 1);
    a = a;
    EXPECT_EQ(a.getCurrentTemperature(), 67.);
    EXPECT_EQ(a.getLastTemperatures()[0], 6.7);
}

TEST(TemperatureSensor, Add) {
    double history[2] = {6.7, 4.2};
    TemperatureSensor s("21", "42", 0., history, 2, 2);
    s.addLastTemperature(2.1);
    EXPECT_EQ(s.getLastTemperatures()[0], 4.2);
    EXPECT_EQ(s.getLastTemperatures()[1], 2.1);
}

TEST(TemperatureSensor, Average) {
    double history[3] = {6.7, 4.2, 2.1};
    TemperatureSensor s("21", "42", 0., history, 3, 3);
    EXPECT_DOUBLE_EQ(s.calcAverageLastTemperature(), 4.3333333333333333);
}

TEST(TemperatureSensor, SetTemperature) {
    TemperatureSensor s;
    s.setCurrentTemperature(6700.);
    EXPECT_EQ(s.getCurrentTemperature(), 1000.);
    s.setCurrentTemperature(-670.);
    EXPECT_EQ(s.getCurrentTemperature(), -273.);
}
