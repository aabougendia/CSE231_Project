#include "esp32-hal-gpio.h"
#include "CommBus_ESP32.h"


void CommBus_Init() {
    pinMode(COMM_AUTOMAN_STATE_PIN, OUTPUT);
    pinMode(COMM_AUTO0_PIN, INPUT);
    pinMode(COMM_AUTO1_PIN, INPUT);
    pinMode(COMM_HUM_FLAG_PIN, OUTPUT);

    pinMode(COMM_MAN0_AUTO_ACK_PIN, OUTPUT);
    pinMode(COMM_MAN1_PIN, OUTPUT);
    pinMode(COMM_MAN2_PIN, OUTPUT);


    digitalWrite(COMM_AUTOMAN_STATE_PIN, HIGH);
    digitalWrite(COMM_MAN0_AUTO_ACK_PIN, LOW);
    digitalWrite(COMM_MAN1_PIN, LOW);
    digitalWrite(COMM_MAN2_PIN, LOW);

    digitalWrite(COMM_HUM_FLAG_PIN, LOW);
    
}

void Set_Man_Stat(ManualState state) {
    switch (state) {
        case DRV_STOP:
            digitalWrite(COMM_MAN0_AUTO_ACK_PIN, LOW);
            digitalWrite(COMM_MAN1_PIN, LOW);
            digitalWrite(COMM_MAN2_PIN, LOW);
            break;
        case DRV_FWD:
            digitalWrite(COMM_MAN0_AUTO_ACK_PIN, HIGH);
            digitalWrite(COMM_MAN1_PIN, LOW);
            digitalWrite(COMM_MAN2_PIN, LOW);
            break;
        case DRV_BWD:
            digitalWrite(COMM_MAN0_AUTO_ACK_PIN, LOW);
            digitalWrite(COMM_MAN1_PIN, HIGH);
            digitalWrite(COMM_MAN2_PIN, LOW);
            break;
        case DRV_RIGHT:
            digitalWrite(COMM_MAN0_AUTO_ACK_PIN, HIGH);
            digitalWrite(COMM_MAN1_PIN, HIGH);
            digitalWrite(COMM_MAN2_PIN, LOW);
            break;
        case DRV_LEFT:
            digitalWrite(COMM_MAN0_AUTO_ACK_PIN, LOW);
            digitalWrite(COMM_MAN1_PIN, LOW);
            digitalWrite(COMM_MAN2_PIN, HIGH);
            break;
        default:
            digitalWrite(COMM_MAN0_AUTO_ACK_PIN, LOW);
            digitalWrite(COMM_MAN1_PIN, LOW);
            digitalWrite(COMM_MAN2_PIN, LOW);
            break;
    }
}

void Set_THM_HUM(THM_State state) {
    digitalWrite(COMM_HUM_FLAG_PIN, state == THM_HUM_DETECTED ? HIGH : LOW);
}

void Set_Ctrl_State(ControlState state) {
    digitalWrite(COMM_AUTOMAN_STATE_PIN, state == STATE_MANUAL ? HIGH : LOW);
}

AutoState Get_Auto_State() {
    int auto0 = digitalRead(COMM_AUTO0_PIN);
    int auto1 = digitalRead(COMM_AUTO1_PIN);
    
    // Combine the two bits to form the state
    int state_value = (auto1 << 1) | auto0;
    
    // Cast to AutoState enum
    return (AutoState)state_value;
}
void Set_Manual_State(ManualState state){
    uint8_t b0 = state & (1 << 0);
    uint8_t b1 = state & (1 << 1);
    uint8_t b2 = state & (1 << 2);

    digitalWrite(COMM_MAN0_AUTO_ACK_PIN, b0);
    digitalWrite(COMM_MAN1_PIN, b1);
    digitalWrite(COMM_MAN2_PIN, b2);

}

void Set_ESP_ACK(){
    digitalWrite(COMM_MAN0_AUTO_ACK_PIN, HIGH);
}
void Clear_ESP_ACK(){
    digitalWrite(COMM_MAN0_AUTO_ACK_PIN, LOW);
}
uint8_t Get_STM_ACK(){
    return digitalRead(COMM_AUTO1_PIN);
}
String Get_GPSLink(){
    String link = "";
    while (Serial2.available()) {
        char c = Serial2.read();
        if (c == '\n') break;
        link += c;
    }
    return link;
}