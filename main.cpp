#include <iostream>
#include "pthread.h"

using namespace std;

/**
* Struct to represent the station
*/
struct station{
    int waiting_passengers;
    pthread_mutex_t load_train;
};

/**
* Initilization of station
*/
void station_init(struct station *station)
{
	station.waiting_passengers = 0;

	if(pthread_mutex_init(&load_train, NULL) != 0 ){
        // Error in inititilization of mutex
        cout << "Caution! Error!" << endl;
        cout << "This station has been Destroyed." << endl;
	}
}

/**
* New train has been arrived to the given station.
* You must fill the train by passengers before leave this method
*/
void station_load_train(struct station *station, int count){
    if( count == 0 || station.waiting_passengers == 0) // No seats available, or no waiting passengers
        return;

    // There are available seats and there are waiting passengers
    do{
        count--;
        station_on_board(station);
    }while( count > 0 && station.waiting_passengers > 0 );

    /*No passengers left or No seats left*/
}

/**
*
*/
void station_wait_for_train(struct station *station){

}

/**
*
*/
void station_on_board(struct station *station){

}

int main(){

    return 0;
}
