#include "SI1133.h"

long mediumIR = 0;
long largeIR = 0;
int white = 0;
int largeWhite = 0;
int uv = 0;
int uvDeep = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println("____SI1133_TESTING____");
  Serial.println();

  Wire.begin();

  uint8_t id = read8(REG_PART_ID);
  Serial.print("ID is 0x");
  Serial.println(id, HEX);

  reset();

  //initChannel_1();
  //delay(50);
  //initChannel_2();
  //initChannel_3();

  init_SI1133();

  write8(REG_COMMAND, CMD_START_MEASUREMENT);
  delay(100);
}

void loop()
{

  Serial.println("==============");
  uint8_t msbMIR = read8(REG_HOSTOUT_0);
  delay(10);
  uint8_t lsbMIR = read8(REG_HOSTOUT_1);
  delay(10);
  uint8_t msbIR = read8(REG_HOSTOUT_2);
  delay(10);
  uint8_t lsbIR = read8(REG_HOSTOUT_3);
  delay(10);
  uint8_t msbWHITE = read8(REG_HOSTOUT_4);
  delay(10);
  uint8_t lsbWHITE = read8(REG_HOSTOUT_5);
  delay(10);
  uint8_t msbLWHITE = read8(REG_HOSTOUT_6);
  delay(10);
  uint8_t lsbLWHITE = read8(REG_HOSTOUT_7);
  delay(10);
  uint8_t msbUV = read8(REG_HOSTOUT_8);
  delay(10);
  uint8_t lsbUV = read8(REG_HOSTOUT_9);
  delay(10);
  uint8_t msbUVDEEP = read8(REG_HOSTOUT_10);
  delay(10);
  uint8_t lsbUVDEEP = read8(REG_HOSTOUT_11);

  mediumIR = ((msbMIR << 8) | lsbMIR);
  largeIR = ((msbIR << 8) | lsbIR);
  white = ((msbWHITE << 8) | lsbWHITE);
  largeWhite = ((msbLWHITE << 8) | lsbLWHITE);
  uv = ((msbUV << 8) | lsbUV);
  uvDeep = ((msbUVDEEP << 8) | lsbUVDEEP);
  
  Serial.print("Medium IR is ");
  Serial.println(mediumIR);
  Serial.print("Large IR is ");
  Serial.println(largeIR);
  Serial.print("White Light is ");
  Serial.println(white);
  Serial.print("Large White Light is ");
  Serial.println(largeWhite);
  Serial.print("UV is ");
  Serial.println(uv);
  Serial.print("Deep UV is ");
  Serial.println(uvDeep);
  Serial.println("==============");
  delay(2000);
}

