#include <stdio.h>
#include <wiringPi.h>

#include <mcp3422.h>

#define VR 403

int main()
{
	wiringPiSetup();
	mcp3422Setup(400, 0x6a, 0, 0);

	while (1) {
		int value = analogRead(VR);
		printf("value: %d\n", value);
		//double volt = value / 1000.;
		//printf("volt: %.2lf\n", volt);

		delay(500);
	}

}
