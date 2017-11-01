#include <Wire.h>

// I2C Address
#define SI1133_ADDR 0x55

// Channel Selections List
#define CHAN_1 0x01
#define CHAN_2 0x03
#define CHAN_3 0x07
#define CHAN_4 0x0F
#define CHAN_5 0x1F
#define CHAN_6 0x3F

// Photodiodes (ADCCONFIGx Reg)
#define SMALL_IR 0x00
#define MEDIUM_IR 0x01
#define LARGE_IR 0x02
#define WHITE 0x0B
#define LARGE_WHITE 0x0D
#define UV 0x18
#define UV_DEEP 0x19

// Software and Hardware Gain (ADCSENSx)
#define HSIG 0x00
#define SW_GAIN 0x00
#define HW_GAIN 0x00

// Sensor Output Resolution (ADCPOSTx Reg)
#define BITS_16 0x00
#define BITS_24	0x40

// Sensor Threshold (ADCPOSTx Reg)
#define THRESH_1 0x00	// No Threshold
#define THRESH_2 0x01	// Generates an Interrupt when measurement is greater than THRESHOLD0 register
#define THRESH_3 0x02	// Generates an Interrupt when measurement is greater than THRESHOLD1 register
#define THRESH_4 0x03	// Generates an Interrupt when measurement is greater than THRESHOLD2 register

// Counter Selection (MEASCONFIGx Reg)
#define COUNTER_INDEX_0 0x00	// No Counter(Hence no measurements in Autonomous mode)
#define COUNTER_INDEX_1 0x40 	// Selects MEASCOUNT 1
#define COUNTER_INDEX_2 0x80 	// Selects MEASCOUNT 2
#define COUNTER_INDEX_3 0x10 	// Selects MEASCOUNT 3

// Commands
#define CMD_RESET_CMD_CTR 0x00
#define CMD_RESET_SW 0x01
#define CMD_FORCE_MEASUREMENT 0x11
#define CMD_PAUSE_MEASUREMENT 0x12
#define CMD_START_MEASUREMENT 0x13	// Starts an autonomous measurement
#define CMD_PARAM_QUERY 0x40	// Reads parameters and stores results in RESPONSE1
#define CMD_PARAM_SET 0x80	// Writes INPUT0 to the parameter x

// Registers
#define REG_PART_ID 0x00
#define REG_HW_ID 0x01
#define REG_REV_ID 0x02
#define REG_HOSTIN_3 0x07
#define REG_HOSTIN_2 0x08
#define REG_HOSTIN_1 0x09
#define REG_HOSTIN_0 0x0A
#define REG_COMMAND 0x0B
#define REG_RESET 0x0f
#define REG_RESPONSE_1 0x10
#define REG_RESPONSE_0 0x11
#define REG_IRQ_STATUS 0x12
#define REG_HOSTOUT_0 0x13
#define REG_HOSTOUT_1 0x14
#define REG_HOSTOUT_2 0x15
#define REG_HOSTOUT_3 0x16
#define REG_HOSTOUT_4 0x17
#define REG_HOSTOUT_5 0x18
#define REG_HOSTOUT_6 0x19
#define REG_HOSTOUT_7 0x1A
#define REG_HOSTOUT_8 0x1B
#define REG_HOSTOUT_9 0x1C
#define REG_HOSTOUT_10 0x1D
#define REG_HOSTOUT_11 0x1E
#define REG_HOSTOUT_12 0x1F
#define REG_HOSTOUT_13 0x20
#define REG_HOSTOUT_14 0x21
#define REG_HOSTOUT_15 0x22
#define REG_HOSTOUT_16 0x23
#define REG_HOSTOUT_17 0x24
#define REG_HOSTOUT_18 0x25
#define REG_HOSTOUT_19 0x26
#define REG_HOSTOUT_20 0x27
#define REG_HOSTOUT_21 0x28
#define REG_HOSTOUT_22 0x29
#define REG_HOSTOUT_23 0x2A
#define REG_HOSTOUT_24 0x2B
#define REG_HOSTOUT_25 0x2C

// Parameter Table
#define PARAM_I2CADDR 0x00
#define PARAM_CHAN_LIST 0x01
#define PARAM_ADCCONFIG0 0x02
#define PARAM_ADCSENS0 0x03
#define PARAM_ADCPOST0 0x04
#define PARAM_MEASCONFIG0 0x05
#define PARAM_ADCCONFIG1 0x06
#define PARAM_ADCSENS1 0x07
#define PARAM_ADCP0ST1 0x08
#define PARAM_MEASCONFIG1 0x09
#define PARAM_ADCCONFIG2 0x0A
#define PARAM_ADCSENS2 0x0B
#define PARAM_ADCPOST2 0x0C
#define PARAM_MEASCONFIG2 0x0D
#define PARAM_ADCCONFIG3 0x0E
#define PARAM_ADCSENS3 0x0F
#define PARAM_ADCPOST3 0x10
#define PARAM_MEASCONFIG3 0x11
#define PARAM_ADCCONFIG4 0x12
#define PARAM_ADCSENS4 0x13
#define PARAM_ADCPOST4 0x14
#define PARAM_MEASCONFIG4 0x15
#define PARAM_ADCCONFIG5 0x16
#define PARAM_ADCSENS5 0x17
#define PARAM_ADCPOST5 0x18
#define PARAM_MEASCONFIG5 0x19
#define PARAM_MEASRATE_H 0x1A
#define PARAM_MEASRATE_L 0x1B
#define PARAM_MEASCOUNT0 0x1C
#define PARAM_MEASCOUNT1 0x1D
#define PARAM_MEASCOUNT2 0x1E
#define PARAM_THRESHOLD0_H 0x25
#define PARAM_THRESHOLD0_L 0x26
#define PARAM_THRESHOLD1_H 0x27
#define PARAM_THRESHOLD1_L 0x28
#define PARAM_THRESHOLD2_H 0x29
#define PARAM_THRESHOLD2_L 0x2A
#define PARAM_BURST 0x2B
