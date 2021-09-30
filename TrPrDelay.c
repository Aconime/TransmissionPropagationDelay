#include <stdio.h>
#include <math.h>

int main() {
	float pSpeed = 2.8 * pow(10, 8);
	
	int routersCount;
	int i; // Loop integer.
	
	float length;
	float rate;
	
	float pSize;
	
	float trDelay;
	float prDelay;
	
	float totalDelay;
	
	// Label - etiketa
	mainMenu:
	
	printf("Enter number of routers (Min 0, Max 3): ");
	scanf("%d", &routersCount);
	
	if (routersCount >= 0 && routersCount <= 3) {
		printf("Enter package size (in Bytes): ");
		scanf("%f", &pSize);
		
		if (routersCount == 0) {
			printf("Enter length from sender to receiver (in KM): ");
			scanf("%f", &length);
			
			printf("Enter rate from sender to receiver (in Mbps): ");
			scanf("%f", &rate);
		} else {
			printf("Enter length from sender to router 1 (in KM): ");
			scanf("%f", &length);
			
			printf("Enter rate from sender to router 1 (in Mbps): ");
			scanf("%f", &rate);
		}
		
		trDelay = (pSize * 8) / (rate * pow(10, 6));
		prDelay = (length * pow(10, 3)) / pSpeed;
		
		totalDelay = trDelay + prDelay;
		
		for (i = 1; i <= routersCount; i++) {
			if (i == routersCount) {
				printf("Enter length from router %d to receiver (in KM): ", i);
				scanf("%f", &length);
			
				printf("Enter rate from router %d to receiver (in Mbps): ", i);
				scanf("%f", &rate);
			} else {
				printf("Enter length from router %d to router %d (in KM): ", i, i+1);
				scanf("%f", &length);
			
				printf("Enter rate from router %d to router %d (in Mbps): ", i, i+1);
				scanf("%f", &rate);
			}
			
			trDelay = (pSize * 8) / (rate * pow(10, 6));
			prDelay = (length * pow(10, 3)) / pSpeed;
			
			totalDelay = totalDelay + (trDelay + prDelay);
		}
		
		printf("The total delay is %fms", totalDelay * 1000);
	} else {
		goto mainMenu;
	}
	
	return 0;
}
