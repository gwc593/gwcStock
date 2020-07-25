#include<FinnHub/FinnHub.h>

#include<iostream>
int main()
{
	FinnHub* dataExchange = FinnHub::Get();

	std::cout << "AAPL: " << dataExchange->GetQuote("AAPL") << std::endl;
}