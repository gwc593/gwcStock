#include<FinnHub.h>
#include"WatchList/WatchList.h"
#include"StockTicker/StockTicker.h"
#include<iostream>



int main()
{
	//Thread exiting states
	bool work = true;
	char intrp = ' ';

	//initialises watchlist
	WatchList watchList("WatchList.txt");

	//iitialise ticker
	auto tickerObj = StockTicker::Get(watchList);
	tickerObj->SetPollRate(5);

	//start thread to gather data
	std::thread tickerWorker(&StockTicker::GenerateData, tickerObj, std::ref(work));

	//cathch user exit
	std::cout << "type ! to end execution" << std::endl;
	while (intrp != '!') {
		intrp = std::getchar();
	}

	//exit threads upon user request
	work = false;
	tickerWorker.join();
	
}