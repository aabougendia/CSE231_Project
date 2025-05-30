
#ifndef INC_ALERTS_H_
#define INC_ALERTS_H_


#define LED_ON	GPIO_PIN_SET
#define LED_OFF	GPIO_PIN_RESET

typedef struct {
    uint8_t R_on, G_on, B_on;
    uint32_t on_ms;
    uint32_t off_ms;
    uint8_t buzzer_on;
} AlertPattern;


void LED_vON(GPIO_TypeDef* GPIOx, u16 GPIO_Pin);
void LED_vOFF(GPIO_TypeDef* GPIOx, u16 GPIO_Pin);
void BUZZER_vON();
void BUZZER_vOFF();
void RGB_LED_vON(u8 R_State, u8 G_State, u8 B_State); //common cathode diffused RGB LED
void RGB_LED_vOFF();
void LED_vBlink(GPIO_TypeDef* GPIOx, u16 GPIO_Pin, u32 delay);
void RGB_LED_vBlink(u8 R_State, u8 G_State, u8 B_State, u32 delay);

// Called automatically every 1ms from SysTick
void AlertHandler_SysTickCallback(void);

#endif /* INC_ALERTS_H_ */
