#pragma once
#include"Events/Event.h"
#include"FinnHub.h"

class BrokerAccount
{
public:
	BrokerAccount();
	~BrokerAccount();

	bool DepositFunds(const float& amount);

	void SetAlias(const std::string& alias) { m_Alias = alias; }

	void PrintStatement();

	bool Buy(const std::string& symbol, uint32_t amount);
	bool Sell(const std::string& symbol, uint32_t amount);

	void SetComission(const float& price){m_CommisionCost = price;}

public://callbacks
	EventCallback<const std::string&, const FinnHub::Candle&> c_OnBuyRecommended;
	EventCallback<const std::string&, const FinnHub::Candle&> c_OnSellRecommended;

private://data
	float m_AvailableBalance = 0;
	float m_AccountValue = 0;
	std::unordered_map<std::string, uint32_t> m_OwnedShares;
	std::unordered_map<std::string, FinnHub::Candle> m_priceData;
	std::string m_Alias;
	static uint32_t s_NumAccounts;
	float m_CommisionCost;

private://methods
	bool OnBuyReccomend(const std::string& symbol, const FinnHub::Candle& price);
	bool OnSellReccomend(const std::string& symbol, const FinnHub::Candle& price);
	void CalculateAccountValue();



};