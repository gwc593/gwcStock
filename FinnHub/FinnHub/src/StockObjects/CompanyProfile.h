#pragma once
#include "gepch.h"
#include "Core/JSON.h"
namespace FinnHub {

	class CompanyProfile
	{
	public:
		CompanyProfile() = default;
		~CompanyProfile() = default;

		void Deserialise(const std::string& companyProfileData)
		{
			JSON::DeserialiseMember(companyProfileData, "country", m_Country);
			JSON::DeserialiseMember(companyProfileData, "currency", m_Currency);
			JSON::DeserialiseMember(companyProfileData, "exchange", m_Exchange);
			JSON::DeserialiseMember(companyProfileData, "ipo", m_Ipo);
			JSON::DeserialiseMember(companyProfileData, "marketCapitalization", m_MarketCapitalization);
			JSON::DeserialiseMember(companyProfileData, "name", m_Name);
			JSON::DeserialiseMember(companyProfileData, "phone", m_Phone);
			JSON::DeserialiseMember(companyProfileData, "shareOutstanding", m_ShareOutstanding);
			JSON::DeserialiseMember(companyProfileData, "ticker", m_Ticker);
			JSON::DeserialiseMember(companyProfileData, "weburl", m_WebURL);
			JSON::DeserialiseMember(companyProfileData, "logo", m_LogoURL);
			JSON::DeserialiseMember(companyProfileData, "finnhubIndustry", m_FinnHubIndustry);
		}

		const std::string GetCountry() const { return m_Country; }
		const std::string GetCurrency() const { return m_Currency; }
		const std::string GetExchange() const { return m_Exchange; }
		const std::string GetIpo() const { return m_Ipo; }
		const float GetMarketCapitalization() const { return m_MarketCapitalization; }
		const std::string GetName() const { return m_Name; }
		const std::string GetPhone() const { return m_Phone; }
		const float GetShareOutstanding() const { return m_ShareOutstanding; }
		const std::string GetTicker() const { return m_Ticker; }
		const std::string GetWebURL() const { return m_WebURL; }
		const std::string GetLogoURL() const { return m_LogoURL; }
		const std::string GetFinnHubIndustry() const { return m_FinnHubIndustry; }


	private:
		std::string m_Country;
		std::string m_Currency;
		std::string m_Exchange;
		std::string m_Ipo;
		float m_MarketCapitalization;
		std::string m_Name;
		std::string m_Phone;
		float m_ShareOutstanding;
		std::string m_Ticker;
		std::string m_WebURL;
		std::string m_LogoURL;
		std::string m_FinnHubIndustry;
	};
}