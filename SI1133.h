#include "SI1133_REG.h"

uint8_t write8(uint8_t reg, uint8_t val)
{
  Wire.beginTransmission(SI1133_ADDR);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}

void reset()
{
  write8(REG_COMMAND, CMD_RESET_SW);
  delay(10);
}

uint8_t read8(uint8_t reg)
{
  Wire.beginTransmission(SI1133_ADDR);
  Wire.write((uint8_t)reg);
  Wire.endTransmission();
  Wire.requestFrom((uint8_t)SI1133_ADDR, (uint8_t)1);
  uint8_t returnVal = Wire.read();
  //Serial.println(returnVal);
  return returnVal;
}

uint8_t writeParameter(uint8_t parameterSet, uint8_t val)
{
  write8(REG_HOSTIN_0, val);
  write8(REG_COMMAND, parameterSet | CMD_PARAM_SET);
  return read8(REG_RESPONSE_1);
}

void init_SI1133()
{
  writeParameter(PARAM_CHAN_LIST, CHAN_6);

  writeParameter(PARAM_ADCCONFIG0, MEDIUM_IR);
  writeParameter(PARAM_ADCSENS0, 0x09);   // Measure after every 12.2 msec
  writeParameter(PARAM_ADCPOST0, 0x00);   // 16 bit resolution and no threshold
  writeParameter(PARAM_MEASRATE_L, 0x01); // Measure rate cannot be zero hence some random number
  writeParameter(PARAM_MEASRATE_H, 0x01);
  writeParameter(PARAM_MEASCONFIG0, COUNTER_INDEX_1);  // Selected MEASCOUNT

  writeParameter(PARAM_ADCCONFIG1, LARGE_IR);
  writeParameter(PARAM_ADCSENS1, 0x09);   // Measure after every 12.2 msec
  writeParameter(PARAM_ADCP0ST1, 0x00);   // 16 bit resolution and no threshold
  writeParameter(PARAM_MEASRATE_L, 0x01); // Measure rate cannot be zero hence some random number
  writeParameter(PARAM_MEASRATE_H, 0x01);
  writeParameter(PARAM_MEASCONFIG1, COUNTER_INDEX_1);  // Selected MEASCOUNT

  writeParameter(PARAM_ADCCONFIG2, WHITE);
  writeParameter(PARAM_ADCSENS2, 0x09);   // Measure after every 12.2 msec
  writeParameter(PARAM_ADCPOST2, 0x00);   // 16 bit resolution and no threshold
  writeParameter(PARAM_MEASRATE_L, 0x01); // Measure rate cannot be zero hence some random number
  writeParameter(PARAM_MEASRATE_H, 0x01);
  writeParameter(PARAM_MEASCONFIG2, COUNTER_INDEX_1);  // Selected MEASCOUNT

  writeParameter(PARAM_ADCCONFIG3, LARGE_WHITE);
  writeParameter(PARAM_ADCSENS3, 0x09);   // Measure after every 12.2 msec
  writeParameter(PARAM_ADCPOST3, 0x00);   // 16 bit resolution and no threshold
  writeParameter(PARAM_MEASRATE_L, 0x01); // Measure rate cannot be zero hence some random number
  writeParameter(PARAM_MEASRATE_H, 0x01);
  writeParameter(PARAM_MEASCONFIG3, COUNTER_INDEX_1);  // Selected MEASCOUNT

  writeParameter(PARAM_ADCCONFIG4, UV);
  writeParameter(PARAM_ADCSENS4, 0x09);   // Measure after every 12.2 msec
  writeParameter(PARAM_ADCPOST4, 0x00);   // 16 bit resolution and no threshold
  writeParameter(PARAM_MEASRATE_L, 0x01); // Measure rate cannot be zero hence some random number
  writeParameter(PARAM_MEASRATE_H, 0x01);
  writeParameter(PARAM_MEASCONFIG4, COUNTER_INDEX_1);  // Selected MEASCOUNT

  writeParameter(PARAM_ADCCONFIG5, UV_DEEP);
  writeParameter(PARAM_ADCSENS5, 0x09);   // Measure after every 12.2 msec
  writeParameter(PARAM_ADCPOST5, 0x00);   // 16 bit resolution and no threshold
  writeParameter(PARAM_MEASRATE_L, 0x01); // Measure rate cannot be zero hence some random number
  writeParameter(PARAM_MEASRATE_H, 0x01);
  writeParameter(PARAM_MEASCONFIG5, COUNTER_INDEX_1);  // Selected MEASCOUNT
}
