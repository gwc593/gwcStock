#include"gepch.h"
#include"Candle.h"
namespace FinnHub {

	Candle::Candle()
	{
		m_ClosePrice = -1.0f;
		m_OpenPrice = -1.0f;
		m_High = -1.0f;
		m_Low = -1.0f;
		m_PreviousClose = -1.0f;
		m_time = 0;
	}

	void Candle::Deserialise(const std::string& candleData)
	{

		auto test = JSON::NumObjects(candleData);
		JSON::DeserialiseMember(candleData, "c", m_ClosePrice);
		JSON::DeserialiseMember(candleData, "o", m_OpenPrice);
		JSON::DeserialiseMember(candleData, "h", m_High);
		JSON::DeserialiseMember(candleData, "l", m_Low);
		JSON::DeserialiseMember(candleData, "pc", m_PreviousClose);
		JSON::DeserialiseMember(candleData, "t", m_time);
	}

}