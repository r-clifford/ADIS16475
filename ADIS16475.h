/*
 * @file imu.h
 * @brief Interface for ADIS16475 IMU
 * @date 2023-11-18
 * @author rvcliffo@ncsu.edu
 * @copyright 2023
 * @details
*/
#include <stdint.h>
namespace ADIS16475 {

/**
 * @brief Device register addresses
 * @addtogroup Registers
 *  @{
 */
#define DIAG_STAT 0x02 /** 16b read, sys error flags */

#define X_GYRO_LOW 0x04 /** x axis gyro, low word */
#define X_GYRO_OUT 0x06 /**x axis gyro, high word */

#define Y_GYRO_LOW 0x08 /** y axis gyro, low */
#define Y_GYRO_OUT 0x0A /** y axis gyro, high*/

#define Z_GYRO_LOW 0x0C /** z axis gyro, low word */
#define Z_GYRO_OUT 0x0E /** z axis gyro, high word */


#define X_ACCL_LOW 0x10 /** x axis accelerometer, low word */
#define X_ACCL_OUT 0x12 /** x axis accelerometer, high word */

#define Y_ACCL_LOW 0x14 /** y axis accelerometer, low word */
#define Y_ACCL_OUT 0x16 /** y axis accelerometer, high word */

#define Z_ACCL_LOW 0x18 /** z axis accelerometer, low word */
#define Z_ACCL_OUT 0x1A /** z axis accelerometer, high word */

#define TEMP_OUT_L 0x1C /** temperature sensor, low word */

#define TIME_STAMP 0x1E /** time stamp register */

#define DATA_CNTR 0x22 /** data counter register */

#define X_DELTANG_LOW 0x24 /** x delta angle register, low word */
#define X_DELTANG_OUT 0x26 /** x delta angle register, high word */

#define Y_DELTANG_LOW 0x28 /** y delta angle register, low word */
#define Y_DELTANG_OUT 0x2A /** y delta angle register, high word */

#define Z_DELTANG_LOW 0x2C /** z delta angle register, low word */
#define Z_DELTANG_OUT 0x2E /** z delta angle register, high word */

#define X_DELTVEL_LOW 0x30 /** x delta velocity register, low word */
#define X_DELTVEL_OUT 0x32 /** x delta velocity register, high word */

#define Y_DELTVEL_LOW 0x34 /** y delta velocity register, low word */
#define Y_DELTVEL_OUT 0x36 /** y delta velocity register, high word */

#define Z_DELTVEL_LOW 0x38 /** z delta velocity register, low word */
#define Z_DELTVEL_OUT 0x3A /** z delta velocity register, high word */

#define XG_BIAS_LOW 0x40 /** x gyro calibration low word */
#define XG_BIAS_HIGH 0x42 /** x gyro calibration high word */

#define YG_BIAS_LOW 0x44 /** y gyro calibration low word */
#define YG_BIAS_HIGH 0x46 /** y gyro calibration high word */

#define ZG_BIAS_LOW 0x48 /** z gyro calibration low word */
#define ZG_BIAS_HIGH 0x4A /** z gyro calibration high word */

#define XA_BIAS_LOW 0x4C /** x accelerometer calibration low word */
#define XA_BIAS_HIGH 0x4E /** x accelerometer calibration high word */

#define YA_BIAS_LOW 0x50 /** y accelerometer calibration low word */
#define YA_BIAS_HIGH 0x52 /** y accelerometer calibration high word */

#define ZA_BIAS_LOW 0x54 /** z accelerometer calibration low word */
#define ZA_BIAS_HIGH 0x56 /** z accelerometer calibration high word */

#define FILT_CTRL 0x5C /** filter control register */
#define RANG_MDL 0x5E /** measurement range register */

#define MSC_CTRL 0x60 /** misc control register */
#define UP_SCALE 0x62 /** scale factor for input clk register */

#define DEC_RATE 0x64 /** decimation rate register, output data rate */
/** @}
*/

enum CLOCK_FREQ { F_1M };
enum IMU_DATA_TYPE {
  ACCELEROMETER,
  GYROSCOPE,
  TEMPERATURE,
  D_ANGLE,
  D_VELOCITY,
};
class IMU {
 public:
  IMU(uint8_t cs, uint8_t dr, uint8_t rst, uint8_t mosi, uint8_t miso,
      CLOCK_FREQ clk);

  void CS_enable();

  void CS_disable();

  int16_t readRegister(uint8_t addr);

  void writeRegister(uint8_t addr);

  double scale(int16_t data, IMU_DATA_TYPE);

 private:
  int CS;
  int DR;
  int rst;
  int mosi;
  int miso;
  int clk;
};
}  // namespace ADIS16475