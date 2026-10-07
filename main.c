// phillip nguyen
// cop 3502c
// tanvir ahmed

#include <stdio.h>
#include <math.h>

// modified to sort arrays of doubles

void insertionSort(double * arr, int len) {

	for (int i = 1; i < len; i++) {

		int index = i;

		while ( index > 0 && arr[index] < arr[index - 1] ) {

			double tmp = arr[index];

			arr[index] = arr[index-1];

			arr[index-1] = tmp;

			index--;

		}

	}

}

// modified to print double values

void printArray(double *arr, int len) {
    
	for ( int i = 0; i < len; i++ ) {
	    
		printf("%lf ", arr[i]);
		
	}
	
	printf("\n");
	
}

int main()

{
    
    // get the number of magical motes and devices

	int magical_motes = 0;

	int magical_devices = 0;
	
	scanf("%d %d", &magical_motes, &magical_devices);

	// get and store the radius of x amount of magical motes, calculate the volume for each mote

	double mote_array[magical_motes];

	for ( int i = 0; i < magical_motes; i = i + 1 ) {

		double radius = 0;

		scanf("%lf", &radius);
		
		    // quick note, using 3.141592 (pi to 6 digits after the decimal will give a different/wrong result than using M_PI from the math library)
		    // might want to specify this in the assignment manifest

		mote_array[i] = ( (4.0 / 3.0) * M_PI * (radius * radius * radius) );

	}

	// get and store the volume of the magical containment devices

	double device_array[magical_devices];

	for ( int i = 0; i < magical_devices; i++ ) {

		double width = 0;

		double height = 0;

		double length = 0;

		scanf("%lf %lf %lf", &width, &height, &length);

		device_array[i] = (double)(width * height * length);

	}

	// sort both arrays from smallest to largest

	    // gonna use insertion sort because i'm assuming the arrays are gonna be pretty small

	insertionSort(mote_array, magical_motes);

	insertionSort(device_array, magical_devices);
	
	// track the status of if a mote has an existing box that will fit or not
	    // 1 = fit, 0 = does not fit
	    // sum up all motes with a fitting status of 0
	
    int fitting_status[magical_motes];
    
    for ( int i = 0; i < magical_motes; i = i + 1 ) {
        
        fitting_status[i] = 0;
        
    }
    
    // find which motes fit in which box and remove devices that have been used
    
    for ( int i = magical_motes - 1; i >= 0; i = i - 1 ) {
        
        for ( int j = magical_devices - 1; j >= 0; j = j - 1 ) {
            
            // a device was found for a mote, subtract 1 from available magic devices (effectively removing that device from the search pool)
            // move to the next mote
            
            if ( device_array[j] - mote_array[i] > 0 ) {
                
                fitting_status[i] = 1;
                
                magical_devices = magical_devices - 1;
                
                break;
                
            }
            
            // a device was not found, move onto the next device
            
            else {
                
                fitting_status[i] = 0;
                
            }
            
        }
        
    }
    
    double unfitted_volume = 0;
    
    for ( int i = 0; i < magical_motes; i = i + 1 ) {
        
        if ( fitting_status[i] == 0 ) {
            
            unfitted_volume = unfitted_volume + mote_array[i];
            
        }
        
    }
    
    printf("%lf", unfitted_volume);

	return 0;
	
}