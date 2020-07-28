#pragma once
#include "gepch.h"
#include"Core/JSON.h"

namespace FinnHub
{
	class Recommendations
	{
	public:
		Recommendations() = default;
		~Recommendations() = default;


		void Deserialise(const std::string& JSONdata)
		{
			JSON::DeserialiseMember(JSONdata, "buy", m_Buy);
			JSON::DeserialiseMember(JSONdata, "hold", m_Hold);
			JSON::DeserialiseMember(JSONdata, "sell", m_Sell);
			JSON::DeserialiseMember(JSONdata, "strongBuy", m_StrongBuy);
			JSON::DeserialiseMember(JSONdata, "strongSell", m_StrongSell);
			JSON::DeserialiseMember(JSONdata, "period", m_Date);
			JSON::DeserialiseMember(JSONdata, "symbol", m_Symbol);
		}

		const int GetBuy() const { return m_Buy; }
		const int GetHold() const { return m_Hold; }
		const int GetSell() const { return m_Sell; }
		const int GetStrongSell() const { return m_StrongSell; }
		const int GetStrongBuy() const { return m_StrongBuy; }
		const std::string GetSymbol() const { return m_Symbol; }
		const std::string GetDate() const { return m_Date; }


	private:
		int m_Buy;
		int m_Hold;
		int m_Sell;
		int m_StrongSell;
		int m_StrongBuy;
		std::string m_Symbol;
		std::string m_Date;
	};
}