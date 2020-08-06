#include<FinnHub.h>
#include"WatchList/WatchList.h"
#include"StockTicker/StockTicker.h"
#include<iostream>

const std::string GuyAPIKey = "bse5d8frh5rea8raakb0";
const std::string SimonAPIKey = "";


bool onPricesChanged()
{
	std::cout << "updating stock prices!!!!!!!!!!" << std::endl;
	return false;
}

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
	StockTicker::Init(watchList,FinnHubAPI::Period::min30);
	auto tickerObj = StockTicker::Get();

	tickerObj->SetPollRate(5);
	auto& eventThing = tickerObj->GetOnUpdateEvent();
	eventThing.subscribe(onPricesChanged);


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