
#include <iostream>
#include "User.h"
#include "Heap.h"
#include "Magazin.h"
using namespace std;

template<typename T>
struct Array {
    int resultSize;
    T* resultData;

    Array(int resultSize, T* resultData) :
        resultSize(resultSize), resultData(resultData) {}
};

class Service {

private:
	int idUserMostInv;

public:
	

    void createUser(int id, double homeX, double homeY);

    void createStore(int id, double storeX, double storeY);

    // discount = -1 daca userul nu a cumparat nimic si, astfel nu s-a acordat discount
    void visit(int timestamp, int clientId, int storeId, int discount);
    
    void invite (int userWhichInvites, int invitedUser);

    // numar de vizite in intervalul (startTime, endTime)
    int visitsInTimeframe(int startTime, int endTime);

    // discount total in intervalul (startTime, endTime)
    int totalDiscountInTimeframe(int startTime, int endTime);

    // Returneaza un Array de k elemente cu id-urile user-ilor
    Array<int> usersWithBestBuyToDiscountRate(int K);

    // numar de vizite in intervalul (startTime, endTime) pentru magazinul storeId
    int visitsInTimeframeOfStore(int startTime, int endTime, int storeId);

    // cele mai mari discount-uri acordate in magazinul storeId
    Array<int> biggestKDiscounts(int K, int storeId);

    // cele mai mari distante de la care vin clientii la magazinul storeId
    Array<double> biggestKClientDistances(int K, int storeId);

    // Returneaza un array cu index-ul zilelor cele mai aglomerate
    Array<int> mostCrowdedKDays(int K, int storeId);

    // Returneaza un array cu dimensiunile grupurilor de utilizatori
    Array<int> distinctGroupsOfUsers();

    // Id-ul userului care a invitat cei mai multi utilizatori
    // Daca sunt doi cu aceeasi valoare, se va intoarce id-ul minim
    int userWithMostInvites();

    // Lungimea celui mai lung lant de invitatii
    int longestInvitesChainSize();

    // Id-urile grupurilor cu cele mai multe invitatii overall
    // Id-ul unui grup se considera minimul id-urilor utilizatorilor din acel grup
    Array<int> topKGroupsWithMostVisitsOverall(int K);

    // O lista de perechi de forma (idGrup, numarMediuDeVizite)
    // Id-ul unui grup se considera minimul id-urilor utilizatorilor din acel grup
    Array<pair<int, double>> averageVisitsPerUser();

    // Returneaza latitudine si longitudine pentru locatia recomandata pentru un nou magazin
    pair<double, double> newStoreCoordinates();
};
	void Service::createUser(int id, double homeX, double homeY){
		//TODO
	}

	void Service::createStore(int id, double storeX, double storeY){
		//TODO
	}


	void Service::invite (int userWhichInvites, int invitedUser) {

		directedClientsGraph[userWhichInvites].push_back(invitedUser);
		undirectedClientsGraph[userWhichInvites].push_back(invitedUser);
		undirectedClientsGraph[invitedUser].push_back(userWhichInvites);

		if ( directedClientsGraph[userWhichInvites].size() > directedClientsGraph[mostInv].size() ){
			idUserMostInv = userWhichInvites;
		}
		else if ( directedClientsGraph[userWhichInvites].size() == directedClientsGraph[mostInv].size() 
				  && userWhichInvites < idUserMostInv){
			idUserMostInv = userWhichInvites;
			}	
	}

	Array<int> Service::usersWithBestBuyToDiscountRate(int K){
 	
 		Array<int>* array = new Array<int>(K);
 		Heap<User> auxHeap = ratioHeap;

 		for ( i = 0; i < K && auxHeap.size() > 0; i++){
 			 User top = auxHeap.extract();
 			 array[i].push_back() = top.getId();
 		}
 		delete[] array;
	 }

	 int userWithMostInvites(){
		return idUserMostInv;
	}