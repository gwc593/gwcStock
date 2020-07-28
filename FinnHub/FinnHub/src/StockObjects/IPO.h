#pragma once
#include "gepch.h"
#include "Core/JSON.h"
namespace FinnHub
{
	class IPO
	{
	public:
		IPO() = default;
		~IPO() = default;

		void Deserialise(const std::string& JSONdata)
		{
			JSON::DeserialiseMember(JSONdata, "symbol", m_Symbol);
			JSON::DeserialiseMember(JSONdata, "date", m_Date);
			JSON::DeserialiseMember(JSONdata, "payDate", m_PayDate);
			JSON::DeserialiseMember(JSONdata, "recordDate", m_RecordDate);
			JSON::DeserialiseMember(JSONdata, "declarationDate", m_DeclarationDate);
			JSON::DeserialiseMember(JSONdata, "currency", m_Currency);
			JSON::DeserialiseMember(JSONdata, "amount", m_Amount);
			JSON::DeserialiseMember(JSONdata, "adjustedAmount", m_AdjustedAmount);
		}

		const std::string GetSymbol() const { return m_Symbol; }
		const std::string GetDate() const { return m_Date; }
		const std::string GetPayDate() const { return m_PayDate; }
		const std::string GetRecordDate() const { return m_RecordDate; }
		const std::string GetDeclarationDate()const { return m_DeclarationDate; }
		const std::string GetCurrency() const { return m_Currency; }
		const float GetAmount() const { return m_Amount; }
		const float GetAdjustedAmount() const { return m_AdjustedAmount; }

	private:
		std::string m_Symbol;
		std::string m_Date;
		std::string m_PayDate;
		std::string m_RecordDate;
		std::string m_DeclarationDate;
		std::string m_Currency;
		float m_Amount;
		float m_AdjustedAmount;
	};
}