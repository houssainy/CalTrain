#include <iostream>
#include "pthread.h"

using namespace std;
//Houssainy
/**
* Struct to represent the station
*/
struct station{
    int waiting_passengers;
    pthread_mutex_t passenger_lock;
    pthread_mutex_t train_lock;
};

/*Header*/
void station_init(struct station *station);
void station_on_board(struct station *station);
void station_load_train(struct station *station, int count);
void station_wait_for_train(struct station *station);

/**
* Initilization of station.
*/
void station_init(struct station *station)
{
	station->waiting_passengers = 0;

	if(pthread_mutex_init(&station->passenger_lock, NULL) != 0 && pthread_mutex_init(&station->train_lock, NULL) != 0){
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
    if( count == 0 || station->waiting_passengers == 0) // No seats available, or no waiting passengers
        return;

    // There are available seats and there are waiting passengers
    do{
        pthread_mutex_unlock(&(station->train_lock)); // unlock the waiting passenger
        count--;
    }while( count > 0 && station->waiting_passengers > 0 );

    /*No passengers left or No seats left*/
}

/**
*   New passenger has been arrived.
*/
void station_wait_for_train(struct station *station){
    pthread_mutex_lock(&(station->passenger_lock));
    station->waiting_passengers++;
    pthread_mutex_unlock(&(station->passenger_lock));

    pthread_mutex_lock(&(station->train_lock));
    station_on_board(station);
}

/**
*   Release one passenger from the station.
*/
void station_on_board(struct station *station){
    if( station->waiting_passengers <= 0 ) // No waiting passenger
        return;
    pthread_mutex_lock(&(station->passenger_lock));
    station->waiting_passengers--;
    pthread_mutex_unlock(&(station->passenger_lock));
}

int main(){

    return 0;
}
