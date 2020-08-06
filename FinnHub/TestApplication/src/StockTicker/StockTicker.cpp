#include"gepch.h"
#include"StockTicker.h"

StockTicker* StockTicker::s_Instance = nullptr;

void  StockTicker::Init(WatchList& watchlist, const FinnHubAPI::Period& period)
{
	if (s_Instance == nullptr)
		s_Instance = new StockTicker(watchlist);


	FinnHubAPI* dataExchange = FinnHubAPI::Get();
	s_Instance->SetPollRate(period);

	for (auto symbol : watchlist.GetSymbols()) {
		FinnHub::CandleArray tmpArr;
		std::string Json = dataExchange->GetHistoricCandles(symbol.c_str(), period, std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) - (14 * 86400), std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));

		tmpArr.Deserialise(Json);

		s_Instance->m_StockData[symbol] = tmpArr.GetData();
	}
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
			for (auto symbol : m_watchList.GetSymbols()) {
				tmpCandle.Deserialise(dataExchange->GetQuote(symbol.c_str()));
				m_StockData[symbol].push_back(tmpCandle);

			}

			m_PricesUpdated.raiseEvent();
		}
	}
}