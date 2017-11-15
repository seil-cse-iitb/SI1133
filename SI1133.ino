#include "SI1133.h"

long int largeIR = 0;
long int largeWhite = 0;
long int uv = 0;
long int uvDeep = 0;

uint8_t msbIR = 0;
uint8_t csbIR = 0;
uint8_t lsbIR = 0;
uint8_t msbWHITE = 0;
uint8_t csbWHITE = 0;
uint8_t lsbWHITE = 0;
uint8_t msbUV = 0;
uint8_t csbUV = 0;
uint8_t lsbUV = 0;
uint8_t msbUVDEEP = 0;
uint8_t csbUVDEEP = 0;
uint8_t lsbUVDEEP = 0;

void resolution_24bit()
{
  // Storing result for for Medium IR
  msbIR = read8(REG_HOSTOUT_0);
  delay(10);
  csbIR = read8(REG_HOSTOUT_1);
  delay(10);
  lsbIR = read8(REG_HOSTOUT_2);
  delay(10);

  // Storing results for Large IR
  msbWHITE = read8(REG_HOSTOUT_3);
  delay(10);
  csbWHITE = read8(REG_HOSTOUT_4);
  delay(10);
  lsbWHITE = read8(REG_HOSTOUT_5);
  delay(10);

  // Storing results for the White Light
  msbUV = read8(REG_HOSTOUT_6);
  delay(10);
  csbUV = read8(REG_HOSTOUT_7);
  delay(10);
  lsbUV = read8(REG_HOSTOUT_8);
  delay(10);

  // Storing results for the Large White Light
  msbUVDEEP = read8(REG_HOSTOUT_9);
  delay(10);
  csbUVDEEP = read8(REG_HOSTOUT_10);
  delay(10);
  lsbUVDEEP = read8(REG_HOSTOUT_11);

  largeIR = ((msbIR << 16) | (csbIR << 8) | lsbIR);
  largeWhite = ((msbWHITE << 16) | (csbWHITE << 8) | lsbWHITE);
  uv = ((msbUV << 16) | (csbUV << 8) | lsbUV);
  uvDeep = ((msbUVDEEP << 16) | (csbUVDEEP << 8) | lsbUVDEEP);

}

void resolution_16bit()
{
  msbIR = read8(REG_HOSTOUT_0);
  delay(10);
  lsbIR = read8(REG_HOSTOUT_1);

  msbWHITE = read8(REG_HOSTOUT_2);
  delay(10);
  lsbWHITE = read8(REG_HOSTOUT_3);

  msbUV = read8(REG_HOSTOUT_4);
  delay(10);
  lsbUV = read8(REG_HOSTOUT_5);


  largeIR = (msbIR << 8) | lsbIR;
  largeWhite = (msbWHITE << 8) | lsbWHITE;
  uv = (msbUV << 8) | lsbUV;
}

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

  resolution_16bit();
  delay(10);

  Serial.print("Large IR is ");
  Serial.println(largeIR);
  Serial.print("Large White Light is ");
  Serial.println(largeWhite);
  Serial.print("UV is ");
  Serial.println(uv);
  Serial.print("Deep UV is ");
  Serial.println(uvDeep);
  Serial.println("==============");
  delay(2000);
}
