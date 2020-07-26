#pragma once
#include "gepch.h"
#include "Core/JSON.h"
namespace FinnHub {

	class Symbol
	{
	public:
		Symbol() = default;
		~Symbol() = default;

		void Deserialise(const std::string& symbolData)
		{
			JSON::DeserialiseMember(symbolData, "description", m_Description);
			JSON::DeserialiseMember(symbolData, "displaySymbol", m_DisplaySymbol);
			JSON::DeserialiseMember(symbolData, "symbol", m_Symbol);
			JSON::DeserialiseMember(symbolData, "type", m_Type);
			JSON::DeserialiseMember(symbolData, "currency", m_Currency);
		}

		const std::string GetDescription()const { return m_Description; }
		const std::string GetDisplaySymbol()const { return m_DisplaySymbol; }
		const std::string GetSymbol()const { return m_Symbol; }
		const std::string GetType()const { return m_Type; }
		const std::string GetCurrency()const { return m_Currency; }
	private:
		std::string m_Description;
		std::string m_DisplaySymbol;
		std::string m_Symbol;
		std::string m_Type;
		std::string m_Currency;
	};
}