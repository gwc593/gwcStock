#include<FinnHub.h>
#include"WatchList/WatchList.h"
#include"StockTicker/StockTicker.h"
#include<iostream>

const std::string GuyAPIKey = "bse5d8frh5rea8raakb0";
const std::string SimonAPIKey = "";

int main()
{
	//////////////////////////////
	//		Initialisation		//
	//////////////////////////////

	//init FinnhubAPI key
	FinnHubAPI::Init(GuyAPIKey);

	//initialises watchlist
	WatchList watchList("WatchList.txt");

	//Thread exiting states
	bool work = true;
	char intrp = ' ';

	//iitialise ticker
	auto tickerObj = StockTicker::Get(watchList);
	tickerObj->SetPollRate(5);


	//////////////////////////////////
	//		Runtime Execution		//
	//////////////////////////////////

	//start thread to gather data
	std::thread tickerWorker(&StockTicker::GenerateData, tickerObj, std::ref(work));

	//cathch user exit
	std::cout << "type ! to end execution" << std::endl;
	while (intrp != '!') {
		intrp = std::getchar();
	}


	//////////////////////////////////////
	//		Terminate Application		//
	//////////////////////////////////////

	//exit threads upon user request
	work = false;
	tickerWorker.join();
}