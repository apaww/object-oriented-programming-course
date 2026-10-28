#include <gtest/gtest.h>
#include <utility>
#include "TemperatureSensor.hpp"

class TemperatureSensorTest : public testing::Test {
protected:
    double history_double[3] = {6.7, 4.2, 2.1};
    int history_int[2] = {3, -10};

    TemperatureSensor<double> sensor_double{"6", "7", 67., history_double, 3, 3};
    TemperatureSensor<int> sensor_int{"7", "6", 12, history_int, 2, 2};
    TemperatureSensor<double> sensor_default;
};

TEST_F(TemperatureSensorTest, Default) {
    EXPECT_EQ(sensor_default.getCurrentTemperature(), 0.);
    EXPECT_EQ(sensor_default.getSize(), 10);
    EXPECT_EQ(sensor_default.getCapacity(), 10);
    EXPECT_FALSE(sensor_default.getItemId().empty());
    EXPECT_FALSE(sensor_default.getInBatchId().empty());
}

TEST_F(TemperatureSensorTest, Init) {
    EXPECT_EQ(sensor_double.getItemId(), "6");
    EXPECT_EQ(sensor_double.getInBatchId(), "7");
    EXPECT_EQ(sensor_double.getCurrentTemperature(), 67.);
    EXPECT_EQ(sensor_double.getSize(), 3);
    EXPECT_EQ(sensor_double.getCapacity(), 3);

    EXPECT_EQ(sensor_int.getItemId(), "7");
    EXPECT_EQ(sensor_int.getInBatchId(), "6");
    EXPECT_EQ(sensor_int.getCurrentTemperature(), 12);
    EXPECT_EQ(sensor_int.getSize(), 2);
    EXPECT_EQ(sensor_int.getCapacity(), 2);
}

TEST_F(TemperatureSensorTest, Normalize) {
    double history[2] = {-670., 4200.};
    TemperatureSensor<double> s("67", "21", 6700., history, 2, 2);
    EXPECT_EQ(s.getCurrentTemperature(), 1000.);
    EXPECT_EQ(s.getLastTemperatures()[0], -273.);
    EXPECT_EQ(s.getLastTemperatures()[1], 1000.);
}

TEST_F(TemperatureSensorTest, EmptyId) {
    double history[1] = {6.7};
    TemperatureSensor<double> s("", "42", 0., history, 1, 1);
    EXPECT_FALSE(s.getItemId().empty());
}

TEST_F(TemperatureSensorTest, Copy) {
    TemperatureSensor<double> b = sensor_double;
    EXPECT_EQ(b.getItemId(), "6");
    EXPECT_EQ(b.getCurrentTemperature(), 67.);
    EXPECT_NE(sensor_double.getLastTemperatures(), b.getLastTemperatures());
    EXPECT_EQ(b.getLastTemperatures()[0], 6.7);
}

TEST_F(TemperatureSensorTest, Assign) {
    TemperatureSensor<double> b;
    b = sensor_double;
    EXPECT_EQ(b.getInBatchId(), "7");
    EXPECT_EQ(b.getCurrentTemperature(), 67.);
    EXPECT_NE(sensor_double.getLastTemperatures(), b.getLastTemperatures());
    EXPECT_EQ(b.getLastTemperatures()[1], 4.2);
}

TEST_F(TemperatureSensorTest, Add) {
    sensor_default.addLastTemperature(2.1);
    EXPECT_EQ(sensor_default.getLastTemperatures()[0], 0.);
    EXPECT_EQ(sensor_default.getLastTemperatures()[9], 2.1);
}

TEST_F(TemperatureSensorTest, Average) {
    EXPECT_DOUBLE_EQ(sensor_double.calcAverageLastTemperature(), 4.3333333333333333);
}

TEST_F(TemperatureSensorTest, AverageEmpty) {
    TemperatureSensor<double> moved = std::move(sensor_double);
    EXPECT_DOUBLE_EQ(sensor_double.calcAverageLastTemperature(), 0.);
}

TEST_F(TemperatureSensorTest, SetTemperature) {
    sensor_default.setCurrentTemperature(6700.);
    EXPECT_EQ(sensor_default.getCurrentTemperature(), 1000.);
    sensor_default.setCurrentTemperature(-670.);
    EXPECT_EQ(sensor_default.getCurrentTemperature(), -273.);
}
