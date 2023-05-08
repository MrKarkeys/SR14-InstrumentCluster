#ifndef LCD_H_
#define LCD_H_

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include "config.h"

// Display Screen Status
// 0 for Driver
// 1 for Menu
// 2 for Individual Menu Screens
// 3 for Settings




// Fonts and other Setup
void lcd__init(U8G2_ST7565_NHD_C12864_F_4W_SW_SPI *lcd_ptr); // changed from SW -> HW
void lcd__print8(uint8_t x, uint8_t y, const char *str);                 //Print str with Helvetica Bold Size 10
void lcd__print14(uint8_t x, uint8_t y, const char *str);                 //Print str with Helvetica Bold Size 14
void lcd__print18(uint8_t x, uint8_t y, char *str);                 //Print str with Helvetica Bold Size 18
void lcd__print24(uint8_t x, uint8_t y, char *str);                 //Print str with Helvetica Bold Size 24
void lcd__clear_screen();

void lcd_welcome_screen();
void lcd__print_default_screen_template();
void lcd__clear_section (uint8_t sect);

// C car
//void lcd__print_rpm(uint16_t rpm);
//void lcd__print_gear(uint8_t gear);
//void lcd__print_oilpress(float oilpress); // Oil coolant? pressure // float or uint8
// E car
void lcd__print_hv(float hv, int displayScreen, int prevDisplayScreen); // accumulator voltage
void lcd__print_soc(uint8_t soc); // State of charge 0-100%
void lcd__print_wattemp(uint8_t watertemp); // Water Coolant Temp
// E & C car
void lcd__print_lv(float lv); // low voltage battery soc
void lcd__print_tps0voltage(float tps0);
void lcd__print_hvtemp(float hvtemp); // Accumulator/Engine temperature
void lcd__print_hvlow(float hvlow);
void lcd__print_launch(float launch, int displayScreen);
void lcd__print_drs(float drsMode, int displayScreen);
void lcd__print_rgm(int regenmode, int displayScreen);
void lcd__print_torque(int torque, int displayScreen);
// 
//void lcd_print__tiracctemp(uint8_t tiracctemp); // Tire temperatures multiple variables?

// Menu stuff
void lcd__menu(int rowCount, int prevRowCount);
void lcd__highlight_screen(uint8_t row, const char* screen);
void lcd__print_screen(uint8_t selection, uint8_t row, const char* screen[], int& prevRowCount); // 5 row + Back template
// void lcd__drs_screen(uint8_t drs);

// diagnostics screen
//void lcd__diagnostics(uint8_t cellfault, uint8_t cellwarn, uint8_t bmsstate);
void lcd__debugscreen(int rowCount, int prevRowCount);
void lcd__debugscreen2(int rowCount, int prevRowCount);
void lcd__debugscreen3(int rowCount, int prevRowCount);
void lcd__print_rpm_diag(uint16_t rpm); // rpm diagnostics for ev
void lcd_settings(int rowCount, int prevRowCount);

void lcd__update_screen(uint16_t rpm, uint8_t gear, float lv, float oilpress, uint8_t drs, uint32_t curr_millis_lcd);
void lcd__update_screenE(float hv, float soc, float lv, float hvlow, float hvtemp, float hvcurr, int drsMode, int regenmode, float launchReady, float tps0, int displayScreen, int& rowCount, int& prevDisplayScreen, int& prevRowCount,int torque,int currentStateCLK, int lastStateCLK, int currentStateDT, uint32_t curr_millis_lcd);

#endif /* LCD_H_ */