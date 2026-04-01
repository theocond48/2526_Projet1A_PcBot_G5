/*
 * robot.h
 *
 *  Created on: Mar 26, 2026
 *      Author: ZafkieL
 */

#ifndef INC_ROBOT_H_
#define INC_ROBOT_H_


typedef enum {
    MODE_NAVIGATION,  // Le robot bouge
    MODE_EVITEMENT,   // Un obstacle est détecté, on change de trajectoire
    MODE_STOP         // Stop d'urgence
} RobotMode_t;

extern float pos_x, pos_y;
extern float vit_x, vit_y;
extern float offset_x, offset_y;
extern float dt;

#endif /* INC_ROBOT_H_ */
