#pragma once
#include "gepch.h"
#include"Core/JSON.h"

namespace FinnHub
{
	class PriceTarget
	{
	public:
		PriceTarget() = default;
		~PriceTarget() = default;


		void Deserialise(const std::string& JSONdata)
		{
			JSON::DeserialiseMember(JSONdata, "symbol", m_Symbol);
			JSON::DeserialiseMember(JSONdata, "lastUpdated", m_UpdateDate);
			JSON::DeserialiseMember(JSONdata, "targetHigh", m_TargetHigh);
			JSON::DeserialiseMember(JSONdata, "targetLow", m_TargetLow);
			JSON::DeserialiseMember(JSONdata, "targetMean", m_TargetMean);
			JSON::DeserialiseMember(JSONdata, "targetMedian", m_TargetMedian);
		}

		const std::string GetSymbol() const { return m_Symbol; }
		const std::string GetDateStamp() const { return m_UpdateDate; }

		const float GetTargetHigh() const { return m_TargetHigh; }
		const float GetTargetLow() const { return m_TargetLow; }
		const float GetTargetMean() const { return m_TargetMean; }
		const float GetTargetMedian() const { return m_TargetMedian; }
	private:
		std::string m_UpdateDate;
		std::string m_Symbol;
		float m_TargetHigh;
		float m_TargetLow;
		float m_TargetMean;
		float m_TargetMedian;
	};
}