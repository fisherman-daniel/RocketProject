#ifndef __PINS_H__
#define __PINS_H__

//motor encoder pins
#define M1_ENCA_Pin GPIO_PIN_1
#define M1_ENCA_GPIO_Port GPIOC
#define M2_ENCA_Pin
#define M2_ENCA_GPIO_Port
#define M3_ENCA_Pin
#define M3_ENCA_GPIO_Port
#define M4_ENCA_Pin
#define M4_ENCA_GPIO_Port

#define M1_ENCB_Pin GPIO_PIN_5
#define M1_ENCB_GPIO_Port GPIOC
#define M2_ENCB_Pin
#define M2_ENCB_GPIO_Port
#define M3_ENCB_Pin
#define M3_ENCB_GPIO_Port
#define M4_ENCB_Pin
#define M4_ENCB_GPIO_Port

//motor limit switch pins
#define M1_SW_Pin GPIO_PIN_5
#define M1_SW_GPIO_Port GPIOB
#define M2_SW_Pin
#define M2_SW_GPIO_Port
#define M3_SW_Pin
#define M3_SW_GPIO_Port
#define M4_SW_Pin
#define M4_SW_GPIO_Port

//motor control pins
#define M1_DIR_Pin GPIO_PIN_5
#define M1_DIR_GPIO_Port GPIOC
#define M2_DIR_Pin
#define M2_DIR_GPIO_Port
#define M3_DIR_Pin
#define M3_DIR_GPIO_Port
#define M4_DIR_Pin
#define M4_DIR_GPIO_Port

#define M1_PWM_Pin GPIO_PIN_5
#define M1_PWM_GPIO_Port GPIOC
#define M2_PWM_Pin
#define M2_PWM_GPIO_Port
#define M3_PWM_Pin
#define M3_PWM_GPIO_Port
#define M4_PWM_Pin
#define M4_PWM_GPIO_Port

//pressure sensor pins
#define P1_Pin GPIO_PIN_0
#define P1_GPIO_Port GPIOA
#define P2_Pin GPIO_PIN_1
#define P2_GPIO_Port GPIOA
#define P3_Pin GPIO_PIN_2
#define P3_GPIO_Port GPIOA
#define P4_Pin GPIO_PIN_3
#define P4_GPIO_Port GPIOA

//power control pins
#define V_SNS_Pin GPIO_PIN_4
#define V_SNS_GPIO_Port GPIOA
#define POWER_Pin GPIO_PIN_6
#define POWER_GPIO_Port GPIOC

//ignitor pins
#define IGN_SNS_Pin GPIO_PIN_5
#define IGN_SNS_GPIO_Port GPIOA
#define IGN_Pin GPIO_PIN_15
#define IGN_GPIO_Port GPIOB

//fill line switch pins
#define FL_SW_Pin GPIO_PIN_9
#define FL_SW_GPIO_Port GPIOB
#define OX_SW_Pin GPIO_PIN_12
#define OX_SW_GPIO_Port GPIOB

//serial port pins
#define TELEM_TX_Pin GPIO_PIN_9
#define TELEM_TX_GPIO_Port GPIOA
#define TELEM_RX_Pin GPIO_PIN_10
#define TELEM_RX_GPIO_Port GPIOA

//debugger/programmer pins (leave unused)
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA

//arm switch, lights, and buzzer
#define RED_Pin GPIO_PIN_8
#define RED_GPIO_Port GPIOC
#define GREEN_Pin GPIO_PIN_9
#define GREEN_GPIO_Port GPIOC
#define BUZZ_Pin
#define BUZZ_GPIO_Port
#define ABORT_SW_Pin
#define ABORT_SW_GPIO_Port

#endif // __PINS_H__