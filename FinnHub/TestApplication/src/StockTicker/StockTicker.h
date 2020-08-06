#pragma once
#include "WatchList/WatchList.h"
#include"FinnHub.h"
class StockTicker
{
public:

	void GenerateData(bool& work);

	void SetPollRate(const std::time_t period) { m_PollPeriod = period; }

	std::vector<FinnHub::Candle> GetData(const std::string& symbol) { std::lock_guard<std::mutex> lock(m_DBLock); return m_StockData[symbol]; }


	static StockTicker* Get(WatchList& watchlist);
	static StockTicker* Get();
private:

	static StockTicker* s_Instance;

	std::time_t m_PollPeriod;
	WatchList& m_watchList;

	StockTicker(WatchList& watchlist);
	std::unordered_map<std::string, std::vector<FinnHub::Candle>> m_StockData;

	std::mutex m_DBLock;

	std::time_t m_StartTime;
};