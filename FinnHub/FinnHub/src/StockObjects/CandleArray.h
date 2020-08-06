#pragma once
#include "gepch.h"
#include"Core/JSON.h"
#include "Candle.h"
namespace FinnHub
{

	class CandleArray
	{
	public:
		CandleArray() = default;
		~CandleArray() = default;

		void Deserialise(const std::string& historicData);

		const std::vector<Candle> GetData() const{ return m_Data; }

	private:
		std::vector<Candle> m_Data;
	};
}
