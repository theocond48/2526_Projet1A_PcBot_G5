#include "IMU.h"
#include "main.h"

int IMU_getacceleration(int16_t *ax, int16_t *ay) {
	uint8_t data[4];
	HAL_StatusTypeDef ret = HAL_I2C_Mem_Read(&hi2c1, ADRESSE_IMU, REG_OUT_X_L_A, 1, data, 4, 100);
	if (ret == HAL_OK)
	{
		*ax = (int16_t)((data[1] << 8) | data[0]);
		*ay = (int16_t)((data[3] << 8) | data[2]);
		return 0;
	}
	else
	{
		return -1;
	}
}

// - Calibration au démarrage -
void IMU_calibration() {
	int16_t bx, by;
	float sx = 0, sy = 0;
	printf("Calibrage\r\n");
	for(int i=0; i<100; i++) {
		read_accelero(&bx, &by);
		sx += bx; sy += by;
		HAL_Delay(10);
	}
	offset_x = sx / 100.0f;
	offset_y = sy / 100.0f;
}
