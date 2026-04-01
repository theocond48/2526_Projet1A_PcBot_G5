#include "Tof.h"
#include "main.h"
#include "VL53L0X.h"

// Constantes du PID (à tuner)
float Kp = 1.5;
float erreur_precedente = 0, integrale = 0;
float setPoint = SET_POINT; // Consigne

// Paramètres du robot
float vRobot = ROBOT_SPEED; // Vitesse










void Tof_Distance() {
    // 1. Acquisition de la mesure ToF
    uint16_t distance_mesuree = readRangeContinuousMillimeters(0);
    
    if (timeoutOccurred()) {
        // Sécurité : stop robot si le capteur ne répond plus
        set_motors(0, 0);
        return;
    }

    // 2. Calcul du PID (Commande Angulaire)
    float erreur = (float)setPoint - distance_mesuree;
    integrale += erreur;
    float derivee = erreur - erreur_precedente;
    
    // Résultat du bloc PID du schéma
    float vAngulaire = (Kp * erreur) + (Ki * integrale) + (Kd * derivee);
    erreur_precedente = erreur;

    // 3. Modèle Cinématique (Calcul des vitesses moteurs)
    // Formules du tableau :
    // vL = vRobot + vAngulaire
    // vR = vRobot - vAngulaire
    float vL = vRobot + vAngulaire;
    float vR = vRobot - vAngulaire;

    // 4. Envoi aux moteurs (PWM)
    apply_motor_speeds(vL, vR);
    
    HAL_Delay(20); // Fréquence d'échantillonnage (ex: 50Hz)
}