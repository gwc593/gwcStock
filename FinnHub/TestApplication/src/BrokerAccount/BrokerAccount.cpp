#include"gepch.h"
#include "BrokerAccount.h"

uint32_t BrokerAccount::s_NumAccounts = 0;

BrokerAccount::BrokerAccount()
{
	m_AvailableBalance = 0;
	m_Alias = "un-named:" + std::to_string(s_NumAccounts++);
	c_OnBuyRecommended.SetCallback(BIND_EVENT_FN(BrokerAccount::OnBuyReccomend));
	c_OnSellRecommended.SetCallback(BIND_EVENT_FN(BrokerAccount::OnSellReccomend));
	m_CommisionCost = 0.0f;

	//Todo - subscribe callbacks
	//GetOnBuyReccomendEvent.subscribe(c_OnBuyRecommended);
	//GetOnSellReccomendEvent.subscribe(c_OnSellRecommended);
}

BrokerAccount::~BrokerAccount()
{
	//Todo - unsubscribe callbacks
	//GetOnBuyReccomendEvent.unsubscribe(c_OnBuyRecommended);
	//GetOnSellReccomendEvent.unsubscribe(c_OnSellRecommended);
}

void BrokerAccount::PrintStatement()
{
	CalculateAccountValue();

	std::cout << "########################################" << std::endl;
	std::cout << "# Account Name: " << m_Alias << std::endl;
	std::cout << "# Account Value: $" << m_AccountValue << std::endl;
	std::cout << "# Available Balance: $" << m_AvailableBalance << std::endl;
	std::cout << "# Owned Shares: " << std::endl;

	for (auto asset : m_OwnedShares) {
		if(asset.second >0)
			std::cout << "#     " << asset.first << ": " << std::to_string(asset.second) << " @ $" << m_priceData[asset.first].GetCurrentPrice() <<" = $" << m_priceData[asset.first].GetCurrentPrice()*(float)asset.second <<  std::endl;
	}

	std::cout << "########################################" << std::endl;
}

bool BrokerAccount::DepositFunds(const float& amount)
{
	if (amount < 0.0f)
		return false;

	m_AvailableBalance += amount;
	m_AccountValue += amount;

	return true;
}

bool BrokerAccount::Buy(const std::string& symbol, uint32_t amount)
{
	FinnHub::Candle priceData;
	priceData.Deserialise(FinnHubAPI::Get()->GetQuote(symbol.c_str()));
	float price = priceData.GetCurrentPrice();
	m_priceData[symbol] = priceData;

	float cost = ((float)amount * price) + m_CommisionCost;

	if (cost <= m_AvailableBalance) {
		m_AvailableBalance -= cost;
		m_OwnedShares[symbol] += amount;
		return true;
	} 

	return false;
}


bool BrokerAccount::Sell(const std::string& symbol, uint32_t amount)
{
	FinnHub::Candle priceData;
	priceData.Deserialise(FinnHubAPI::Get()->GetQuote(symbol.c_str()));

	float price = priceData.GetCurrentPrice();
	m_priceData[symbol] = priceData;

	float cost = ((float)amount * price) - m_CommisionCost;

	if (amount <= m_OwnedShares[symbol]) {
		m_AvailableBalance += cost;
		m_OwnedShares[symbol] -= amount;
		return true;
	}
	else {
		cost = (float)m_OwnedShares[symbol] * price;
		m_AvailableBalance += cost;
		m_OwnedShares[symbol] = 0;
		return true;
	}

	return false;
}

bool BrokerAccount::OnBuyReccomend(const std::string& symbol, const FinnHub::Candle& price)
{

	return PROPAGATE_EVENT;
}


bool BrokerAccount::OnSellReccomend(const std::string& symbol, const FinnHub::Candle& price)
{

	return PROPAGATE_EVENT;
}

void BrokerAccount::CalculateAccountValue()
{
	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	FinnHub::Candle tmpCandle;

	for (auto candle : m_priceData) {
		if (now - candle.second.GetTimeStamp() >= 60) {
			tmpCandle.Deserialise(FinnHubAPI::Get()->GetQuote(candle.first.c_str()));
			candle.second = tmpCandle;
		}
	}

	m_AccountValue = m_AvailableBalance;
	for (auto element : m_OwnedShares) {
		m_AccountValue += m_priceData[element.first].GetCurrentPrice() * (float)element.second;
	}

}

