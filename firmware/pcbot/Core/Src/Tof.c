#include "Tof.h"
#include "main.h"
#include "VL53L0X.h"


void Tof_Init_All() {
    // 1. Tout éteindre
    HAL_GPIO_WritePin(GPIOA, XSHUT_G_Pin|XSHUT_C_Pin|XSHUT_D_Pin, GPIO_PIN_RESET);
    HAL_Delay(10);

    // 2. Initialiser le Gauche
    HAL_GPIO_WritePin(GPIOA, XSHUT_G_Pin, GPIO_PIN_SET);
    HAL_Delay(5);
    g_i2cAddr = 0x52; // Adresse pour lui parler au début
    setAddress_VL53L0X(0x54); // On lui donne sa nouvelle adresse
    initVL53L0X(true, &hi2c1);

    // 3. Initialiser le Centre
    HAL_GPIO_WritePin(GPIOA, XSHUT_C_Pin, GPIO_PIN_SET);
    HAL_Delay(5);
    g_i2cAddr = 0x52;
    setAddress_VL53L0X(0x56);
    initVL53L0X(true, &hi2c1);

    // 4. Initialiser le Droit
    HAL_GPIO_WritePin(GPIOA, XSHUT_D_Pin, GPIO_PIN_SET);
    HAL_Delay(5);
    g_i2cAddr = 0x52;
    setAddress_VL53L0X(0x58);
    initVL53L0X(true, &hi2c1);
    
    // Démarrer la mesure continue sur les trois
    g_i2cAddr = 0x54; startContinuous(50);
    g_i2cAddr = 0x56; startContinuous(50);
    g_i2cAddr = 0x58; startContinuous(50);
}




void Tof_Distance() {
    //Acquisition de la mesure ToF
    uint16_t distance_mesuree = readRangeContinuousMillimeters(0);
    
    if (timeoutOccurred()) {
        // Sécurité : stop robot si le capteur ne répond plus
        set_motors(0, 0);
        return;
    }
    return distance_mesuree
}


