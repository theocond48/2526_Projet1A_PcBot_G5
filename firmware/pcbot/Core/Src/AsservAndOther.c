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



void Compute_asserv(distance_mesuree);{
    //Calcul du PD (Commande Angulaire)
    float erreur = (float)setPoint - distance_mesuree;
    float derivee = erreur - erreur_precedente;
    
    // Résultat du bloc PD du schéma
    float vAngulaire = (Kp * erreur);
    erreur_precedente = erreur;

    // Modèle Cinématique (Calcul des vitesses moteurs)
    // Formules du tableau :
    // vL = vRobot + vAngulaire
    // vR = vRobot - vAngulaire
    float vL = vRobot + vAngulaire;
    float vR = vRobot - vAngulaire;
}

