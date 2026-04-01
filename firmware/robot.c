/*
 * robot.c
 *
 *  Created on: Mar 26, 2026
 *      Author: ZafkieL
 */

#include "robot.h"

#include "main.h"

float pos_x = 0, pos_y = 0;
float vit_x = 0, vit_y = 0;
float offset_x = 0, offset_y = 0;
float dt = 0.02;

uint16_t dist_front, dist_left, dist_right;
void Robot_logic(RobotMode_t *currentMode) {
    // 1. Lecture de la distance (ToF sur I2C2)
    //read_all_tofs(&dist_front, &dist_left, &dist_right);

    // Gestion des états
    switch(*currentMode) {


        case MODE_NAVIGATION:
        	if (dist_front < 150 && dist_front > 0) {
        		*currentMode = MODE_EVITEMENT;
        	}
       // Si un mur s'approche trop par la gauche, on s'écarte à droite sans s'arrêter
        	else if (dist_left < 80) {
      // moteurs_legere_correction_droite();
        		}
        	else if (dist_right < 80) {
      // moteurs_legere_correction_gauche();
				}
        	break;


        case MODE_EVITEMENT:
        	// Si on est bloqué devant, on regarde quel côté est le plus libre
        	if (dist_left > dist_right) {
        		// moteurs_pivoter_gauche();
        		printf("Dodge -> Gauche \r\n");
        	}
        	else {
        	     // moteurs_pivoter_droite();
        		printf("Dodge -> Droite \r\n");
        	}

        // On sort de l'évitement quand le champ devant est libre
        	if (dist_front > 300 || dist_front == 0) {
        		*currentMode = MODE_NAVIGATION;
        	}
        	break;

        case MODE_STOP:
            // moteurs_stop();
            break;
    }
}

void Robot_Position() {
	uint32_t tickstart = HAL_GetTick();
	int16_t brut_x, brut_y;
	//read_accelero(&brut_x, &brut_y);
	//read_tof();

	//Calcul physique (Conversion en m/s^2)
	float ax = ((float)brut_x - offset_x) * 0.00061f;
	float ay = ((float)brut_y - offset_y) * 0.00061f;

	//Seuil anti-bruit
	if(ax < 0.05 && ax > -0.05) ax = 0;
	if(ay < 0.05 && ay > -0.05) ay = 0;

	//Intégration
	vit_x += ax * dt;
	vit_y += ay * dt;
	pos_x += vit_x * dt;
	pos_y += vit_y * dt;

	while ((HAL_GetTick() - tickstart) < 20)
	{
	}
}
