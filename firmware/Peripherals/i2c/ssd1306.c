#include "SSD1306_H"
#include <string.h>
HAL_StatusTypeDef SSD1306_Init(I2C_HandleTypeDef *hi2c){
if(SSD1306_SendCommand(hi2c,SSD1306_SET_MUX_RATIO)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,0x3F)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,SSD1306_SET_DISP_OFFSET)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,0x00)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,SSD1306_SET_DISP_START)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,SSD1306_SEG_REMAP_NORMAL)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,SSD1306_COM_SCAN_NORMAL)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,SSD1306_SET_COM_PINS)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,0x02)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,SSD1306_SET_CONTRAST)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,0x7F)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,SSD1306_DISPLAY_RAM)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,SSD1306_NORMAL_DISPLAY)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,SSD1306_SET_CLK_DIV)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,0x80)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,SSD1306_SET_CHARGE_PUMP)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,SSD1306_CHARGE_PUMP_ON)!=HAL_OK) return HAL_ERROR;
if(SSD1306_SendCommand(hi2c,SSD1306_DISP_ON)!=HAL_OK) return HAL_ERROR;
return HAL_OK;
}

HAL_StatusTypeDef SSD1306_SendCommand(I2C_HandleTypeDef *hi2c,uint8_t cmd){
      uint8_t data[2]={SSD1306_CMD, cmd};

    return HAL_I2C_Master_Transmit(hi2c, SSD1306_ADDR <<1,data,2,500);
}

HAL_StatusTypeDef SSD1306_SendData(I2C_HandleTypeDef *hi2c,uint8_t *data,uint16_t size){
    uint8_t buff[129];
    buff[0]=SSD1306_DATA;
    memcpy(&buff[1],data,size);
    return HAL_I2C_Master_Transmit(hi2c, SSD1306_ADDR <<1,buff,size+1,500);
}

HAL_StatusTypeDef SSD1306_Clear(I2C_HandleTypeDef *hi2c){
    uint8_t zeros[1024];
    if(SSD1306_SendCommand(hi2c, SSD1306_COL_ADDR)!= HAL_OK) return HAL_ERROR;
    if(SSD1306_SendCommand(hi2c, 0)!= HAL_OK) return HAL_ERROR;
    if(SSD1306_SendCommand(hi2c, 127)!= HAL_OK) return HAL_ERROR;
    if( SSD1306_SendCommand(hi2c, SSD1306_PAGE_ADDR)!= HAL_OK) return HAL_ERROR;
    if(SSD1306_SendCommand(hi2c, 0)!= HAL_OK) return HAL_ERROR;
    if(SSD1306_SendCommand(hi2c, 7) != HAL_OK) return HAL_ERROR;  
    memset(zeros, 0, sizeof(zeros));
    return SSD1306_SendData(hi2c,zeros,1024);
}

HAL_StatusTypeDef SSD1306_WriteString(I2C_HandleTypeDef *hi2c,char *string){


}