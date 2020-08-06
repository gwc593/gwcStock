#pragma once
#include "gepch.h"
#include"Core/JSON.h"

namespace FinnHub
{
	class CandleArray;

	class Candle
	{
		friend class CandleArray;
	public:
		Candle();
		~Candle() = default;

		void Deserialise(const std::string& candleData);

		inline float GetOpenPrice() const { return m_OpenPrice; }
		inline float GetCurrentPrice() const { return m_ClosePrice; }
		inline float GetHigh() const { return m_High; }
		inline float GetLowconst() const { return m_Low; }
		inline float GetPreviousOpenPrice() const { return m_PreviousClose; }
		inline std::time_t GetTimeStamp() const { return m_time; }

	protected:
		void SetOpenPrice(float price) { m_OpenPrice = price; }
		void SetClosePrice(float price) { m_ClosePrice = price; }
		void SetHighPrice(float price) { m_High = price; }
		void SetLowPrice(float price) { m_Low = price; }
		void SetPreviousClose(float price) { m_PreviousClose = price; }
		void SetTimeStamp(std::time_t date) { m_time = date; }

	private:
		float m_OpenPrice;
		float m_ClosePrice;
		float m_High;
		float m_Low;
		float m_PreviousClose;
		std::time_t m_time;
	};
}