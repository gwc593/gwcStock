#pragma once
#include "Core/JSON.h"
namespace FinnHub
{
	class Buzz
	{
	public:
		Buzz():m_ArtitclesThisWeek(0),m_Buzz(0.0f),m_WeeklyAverage(0.0f){}

		const int GetNArticlesThisWeek() const { return m_ArtitclesThisWeek; }
		const float GetBuzz() const { return m_Buzz; }

		void Deserialise(const std::string& JSONData)
		{
			JSON::DeserialiseMember(JSONData, "articlesInLastWeek", m_ArtitclesThisWeek);
			JSON::DeserialiseMember(JSONData, "buzz", m_Buzz);
			JSON::DeserialiseMember(JSONData, "weeklyAverage", m_WeeklyAverage);
		}

	private:
		int m_ArtitclesThisWeek;
		float m_Buzz;
		float m_WeeklyAverage;
	};

	class Sentiment
	{
	public:
		Sentiment() :m_BullishPercentage(0.0f), m_BearishPercentage(0.0f) {}

		void Deserialise(const std::string& JSONData)
		{
			JSON::DeserialiseMember(JSONData, "bullishPercent", m_BullishPercentage);
			JSON::DeserialiseMember(JSONData, "bearishPercent", m_BearishPercentage);
		}

		const float GetBullishPercent()const { return m_BullishPercentage; }
		const float GetBearishPercent()const { return m_BearishPercentage; }
	private:
		float m_BullishPercentage;
		float m_BearishPercentage;
	};


	class NewsSentiment
	{
	public:
		NewsSentiment() = default;
		~NewsSentiment() = default;

		const Buzz& GetBuzz() const { return m_Buzz; }
		const float GetCompanyScore() const { return m_CompanyScore; }
		const float GetSectorAverageBullishPercent() const { return m_SectorAverageBullishPercent; }
		const float GetSectorAverageNewsScore() const { return m_SectorAverageNewsScore; }
		const Sentiment& GetSentiment()const { return m_Sentiment; }
		const std::string GetSymbol()const { return m_Symbol; }

		void Deserialise(const std::string& JSONdata)
		{
			JSON::DeserialiseMember(JSONdata, "companyNewsScore", m_CompanyScore);
			JSON::DeserialiseMember(JSONdata, "sectorAverageBullishPercent", m_SectorAverageBullishPercent);
			JSON::DeserialiseMember(JSONdata, "sectorAverageNewsScore", m_SectorAverageNewsScore);
			JSON::DeserialiseMember(JSONdata, "symbol", m_Symbol);

			m_Buzz.Deserialise(JSON::GetSubObjectData(JSONdata, "buzz"));
			m_Sentiment.Deserialise(JSON::GetSubObjectData(JSONdata, "sentiment"));
		}

	private:
		Buzz m_Buzz;
		float m_CompanyScore;
		float m_SectorAverageBullishPercent;
		float m_SectorAverageNewsScore;
		Sentiment m_Sentiment;
		std::string m_Symbol;

	};
}