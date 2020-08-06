#include"gepch.h"
#include"StockTicker.h"

StockTicker* StockTicker::s_Instance = nullptr;

StockTicker* StockTicker::Get(WatchList& watchlist)
{
	if (s_Instance == nullptr)
		s_Instance = new StockTicker(watchlist);

	return s_Instance;
}

StockTicker* StockTicker::Get()
{
	return s_Instance;
}


StockTicker::StockTicker(WatchList& watchlist) :m_watchList(watchlist)
{
	m_StartTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

std::time_t getNow() { return std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); }

void StockTicker::GenerateData(bool& work)
{
	FinnHub::Candle tmpCandle;
	FinnHubAPI* dataExchange = FinnHubAPI::Get();
	while (work) {
		if ((getNow() - m_StartTime) > m_PollPeriod) {
			std::lock_guard<std::mutex> lock(m_DBLock);
			m_StartTime = getNow();
			std::cout << "updating stock prices" << std::endl;

			for (auto symbol : m_watchList.GetSymbols()) {
				tmpCandle.Deserialise(dataExchange->GetQuote(symbol.c_str()));
				m_StockData[symbol].push_back(tmpCandle);

			}
		}
	}
}