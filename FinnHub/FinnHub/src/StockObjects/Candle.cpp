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
		std::string cd = candleData;
		std::string data;

		//TODO: this is not order independant, this should be modified incase of API changes.
		//get close
		data = cd.substr(cd.find("\"c\"")+4);
		data.erase(data.find(","),data.size() - data.find(","));
		m_ClosePrice = std::stof(data);

		//get open
		data = cd.substr(cd.find("\"o\"") + 4);
		data.erase(data.find(","), data.size() - data.find(","));
		m_OpenPrice = std::stof(data);
	
		//get high
		data = cd.substr(cd.find("\"h\"") + 4);
		data.erase(data.find(","), data.size() - data.find(","));
		m_High = std::stof(data);

		//get Low
		data = cd.substr(cd.find("\"l\"") + 4);
		data.erase(data.find(","), data.size() - data.find(","));
		m_Low = std::stof(data);

		//get Previous Close
		data = cd.substr(cd.find("\"pc\"") + 5);
		data.erase(data.find(","), data.size() - data.find(","));
		m_PreviousClose = std::stof(data);

		//get Time Stamp
		data = cd.substr(cd.find("\"t\"") + 4);
		data.erase(data.find("}"), data.size() - data.find("}"));
		m_time = std::atol(data.c_str());
	}

}