#pragma once
#include "WatchList/WatchList.h"
#include"FinnHub.h"
#include"Events/Event.h"
class StockTicker
{
public:

	void GenerateData(bool& work);

	void SetPollRate(const FinnHubAPI::Period& period = FinnHubAPI::Period::min30) { 

		switch (period) {
		case FinnHubAPI::Period::min1:	m_PollPeriod = 60;	break;
		case FinnHubAPI::Period::min5:	m_PollPeriod = 5*60;	break;
		case FinnHubAPI::Period::min15: m_PollPeriod = 15*60; break;
		case FinnHubAPI::Period::min30: m_PollPeriod = 30*60; break;
		case FinnHubAPI::Period::min60: m_PollPeriod = 60*60; break;
		case FinnHubAPI::Period::day:	m_PollPeriod = 86400;	break;
		case FinnHubAPI::Period::week:	m_PollPeriod = 86400*5;	break;
		case FinnHubAPI::Period::month: m_PollPeriod = 86400*5*4;	break;
		}
	}

	void SetPollRate(const std::time_t& period = 5)
	{
		m_PollPeriod = period;
	}

	std::vector<FinnHub::Candle> GetData(const std::string& symbol) { std::lock_guard<std::mutex> lock(m_DBLock); return m_StockData[symbol]; }

	Event<>& GetOnUpdateEvent() { return m_PricesUpdated; }

	static void Init(WatchList& watchlist, const FinnHubAPI::Period& period = FinnHubAPI::Period::min30);
	static StockTicker* Get();
private:

	static StockTicker* s_Instance;

	std::time_t m_PollPeriod;
	WatchList& m_watchList;

	StockTicker(WatchList& watchlist);
	std::unordered_map<std::string, std::vector<FinnHub::Candle>> m_StockData;

	std::mutex m_DBLock;

	std::time_t m_StartTime;

private:
	Event<> m_PricesUpdated;
	
};