#include "IMU.h"
#include "main.h"
#include "Tof.h"
#include "robot.h"



// Constantes du PD (à tuner)
float Kp = 1.5;
float erreur_precedente = 0;
float setPoint = SET_POINT; // Consigne

// Paramètres du robot
float vRobot = ROBOT_SPEED; // Vitesse



void Compute_asserv(uint16_t distance_mesuree, float *vL_out, float *vR_out){
    //Calcul du PD (Commande Angulaire)
    erreur = (float)setPoint - (float)distance_mesuree;
    derivee = erreur - erreur_precedente;
    
    // Résultat du bloc PD du schéma
    vAngulaire = Kp * erreur +Kd * derivee;
    erreur_precedente = erreur;

    // Modèle Cinématique (Calcul des vitesses moteurs)
    // Formules du tableau :
    // vL = vRobot + vAngulaire
    // vR = vRobot - vAngulaire
    *vL_out = vRobot + vAngulaire;
    *vR_out = vRobot - vAngulaire;
}

