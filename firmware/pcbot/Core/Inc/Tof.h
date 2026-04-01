#ifndef INC_TOF_H_
#define INC_TOF_H_



#define SET_POINT 80
#define ROBOT_SPEED 

void Tof_Init_All();


extern float Kp;
extern float erreur_precedente, integrale;
extern float setPoint; 
extern float vRobot ; 
extern float erreur ;

extern float derivee;
extern float vAngulaire; 
extern float vL;
extern float vR;

#endif /* INC_TOF_H_ */