//Mario Han 
#include <stdio.h>

#include "driver/i2c.h"
#include "esp_console.h"
#include "esp_log.h"

// Master I2C
#define I2C_EXAMPLE_MASTER_SCL_IO 22        // gpio number for i2c clk
#define I2C_EXAMPLE_MASTER_SDA_IO 23        // gpio number for i2c data
#define I2C_EXAMPLE_MASTER_NUM I2C_NUM_0    // i2c port
#define I2C_EXAMPLE_MASTER_TX_BUF_DISABLE 0 // i2c master no buffer needed
#define I2C_EXAMPLE_MASTER_RX_BUF_DISABLE 0 // i2c master no buffer needed
#define I2C_EXAMPLE_MASTER_FREQ_HZ 400000   // i2c master clock freq 400kHz
#define WRITE_BIT I2C_MASTER_WRITE          // i2c master write
#define READ_BIT I2C_MASTER_READ            // i2c master read
#define ACK_CHECK_EN true                   // i2c master will check ack
#define ACK_CHECK_DIS false                 // i2c master will not check ack
#define ACK_VAL 0x00                        // i2c ack value
#define NACK_VAL 0xFF                       // i2c nack value

// LIDAR
#define SLAVE_ADDR (0x62) // 0x53
// #define RegisterMeasure (0x00) // Register to write to initiate ranging.
// #define MeasureValue (0x04)    // Value to initiate ranging.
// #define RegisterHighLowB 0x8f  // Register to get both High and Low bytes in 1 call.

//0xC4 write, 0xC5 read

static const char *TAG = "cmd_i2ctools";

// Function to initiate i2c -- note the MSB declaration!
static void i2c_master_init()
{
  // Debug
  printf("\n>> i2c Config\n");
  int err;

  // Port configuration
  int i2c_master_port = I2C_EXAMPLE_MASTER_NUM;

  /// Define I2C configurations
  i2c_config_t conf;
  conf.mode = I2C_MODE_MASTER;                        // Master mode
  conf.sda_io_num = I2C_EXAMPLE_MASTER_SDA_IO;        // Default SDA pin
  conf.sda_pullup_en = GPIO_PULLUP_ENABLE;            // Internal pullup
  conf.scl_io_num = I2C_EXAMPLE_MASTER_SCL_IO;        // Default SCL pin
  conf.scl_pullup_en = GPIO_PULLUP_ENABLE;            // Internal pullup
  conf.master.clk_speed = I2C_EXAMPLE_MASTER_FREQ_HZ; // CLK frequency
  err = i2c_param_config(i2c_master_port, &conf);     // Configure
  if (err == ESP_OK)
  {
    printf("- parameters: ok\n");
  }

  // Install I2C driver
  err = i2c_driver_install(i2c_master_port, conf.mode,
                           I2C_EXAMPLE_MASTER_RX_BUF_DISABLE,
                           I2C_EXAMPLE_MASTER_TX_BUF_DISABLE, 0);
  if (err == ESP_OK)
  {
    printf("- initialized: yes\n");
  }

  // Data in MSB mode
  i2c_set_data_mode(i2c_master_port, I2C_DATA_MODE_MSB_FIRST, I2C_DATA_MODE_MSB_FIRST);
}

// Utility  Functions //////////////////////////////////////////////////////////

// Utility function to test for I2C device address -- not used in deploy
int testConnection(uint8_t devAddr, int32_t timeout)
{
  i2c_cmd_handle_t cmd = i2c_cmd_link_create();
  i2c_master_start(cmd);
  i2c_master_write_byte(cmd, (devAddr << 1) | I2C_MASTER_WRITE, ACK_CHECK_EN);
  i2c_master_stop(cmd);
  int err = i2c_master_cmd_begin(I2C_EXAMPLE_MASTER_NUM, cmd, 1000 / portTICK_RATE_MS);
  i2c_cmd_link_delete(cmd);
  return err;
}

// Utility function to scan for i2c device
static void i2c_scanner()
{
  int32_t scanTimeout = 1000;
  printf("\n>> I2C scanning ..."
         "\n");
  uint8_t count = 0;
  for (uint8_t i = 1; i < 127; i++)
  {
    // printf("0x%X%s",i,"\n");
    if (testConnection(i, scanTimeout) == ESP_OK)
    {
      printf("- Device found at address: 0x%X%s", i, "\n");
      count++;
    }
  }
  if (count == 0)
  {
    printf("- No I2C devices found!"
           "\n");
  }
}

////////////////////////////////////////////////////////////////////////////////
uint16_t get_Distance()
{
  uint8_t val1;
  uint8_t val2;

  i2c_cmd_handle_t cmd = i2c_cmd_link_create();
  i2c_master_start(cmd);                                                   //start
  i2c_master_write_byte(cmd, (SLAVE_ADDR << 1) | WRITE_BIT, ACK_CHECK_EN); //slave address + write
  i2c_master_write_byte(cmd, 0x00, ACK_CHECK_EN);                          // register address
  i2c_master_write_byte(cmd, 0x04, ACK_CHECK_EN);                          // data
  i2c_master_stop(cmd);                                                    // stop
  esp_err_t ret = i2c_master_cmd_begin(I2C_EXAMPLE_MASTER_NUM, cmd, 1000 / portTICK_RATE_MS);
  if (ret == ESP_OK)
  {
    ESP_LOGI(TAG, "Write OK");
  }
  else if (ret == ESP_ERR_TIMEOUT)
  {
    ESP_LOGW(TAG, "Bus is busy");
  }
  else
  {
    ESP_LOGW(TAG, "Write Failed");
  }
  printf("Wrote 0 to 4 \n");
  vTaskDelay(20 / portTICK_RATE_MS);

  i2c_cmd_handle_t cmd1 = i2c_cmd_link_create();
  i2c_master_start(cmd1);
  i2c_master_write_byte(cmd1, (SLAVE_ADDR << 1) | WRITE_BIT, ACK_CHECK_EN);
  i2c_master_write_byte(cmd1, 0x8F, ACK_CHECK_EN);
  i2c_master_stop(cmd1);
  i2c_master_cmd_begin(I2C_EXAMPLE_MASTER_NUM, cmd1, 1000 / portTICK_RATE_MS);

  i2c_cmd_handle_t cmd2 = i2c_cmd_link_create();
  i2c_master_start(cmd2);
  i2c_master_write_byte(cmd2, (SLAVE_ADDR << 1) | READ_BIT, ACK_CHECK_EN);
  i2c_master_read_byte(cmd2, &val1, ACK_VAL);
  i2c_master_read_byte(cmd2, &val2, ACK_VAL);
  i2c_master_stop(cmd2);
  i2c_master_cmd_begin(I2C_EXAMPLE_MASTER_NUM, cmd2, 1000 / portTICK_RATE_MS);

  i2c_cmd_link_delete(cmd);
  i2c_cmd_link_delete(cmd1);
  i2c_cmd_link_delete(cmd2);
  printf("%d, %d\n", val1, val2);

  uint16_t output = (uint16_t)((val1 << 8) | val2);
  return output;
}

int checkBit()
{
  while (1)
  {
    uint8_t val1;

    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (SLAVE_ADDR << 1) | WRITE_BIT, ACK_CHECK_EN);
    i2c_master_write_byte(cmd, (0x01), ACK_CHECK_EN);
    i2c_master_stop(cmd);

    i2c_cmd_handle_t cmd2 = i2c_cmd_link_create();
    i2c_master_start(cmd2);
    i2c_master_write_byte(cmd2, (SLAVE_ADDR << 1) | READ_BIT, ACK_CHECK_EN);
    i2c_master_read_byte(cmd2, &val1, ACK_CHECK_DIS);
    i2c_master_stop(cmd2);

    i2c_master_cmd_begin(I2C_EXAMPLE_MASTER_NUM, cmd, 1000 / portTICK_RATE_MS);
    esp_err_t ret = i2c_master_cmd_begin(I2C_EXAMPLE_MASTER_NUM, cmd2, 1000 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);
    i2c_cmd_link_delete(cmd2);

    if ((val1 & 1) == 0)
    {
      return 1;
    }
  }
}

void LIDAR_task()
{
  while (1)
  {
    if (checkBit())
    {
      printf("Distance: %d\n", get_Distance());
    }
    vTaskDelay(1000 / portTICK_RATE_MS);
  }
}

void app_main()
{

  // Routine
  i2c_master_init();
  i2c_scanner();

  xTaskCreate(LIDAR_task, "LIDAR_task", 4096, NULL, 5, NULL);
}
