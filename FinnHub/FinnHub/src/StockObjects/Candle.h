#pragma once
#include "gepch.h"
namespace FinnHub
{
	class Candle
	{
	public:
		Candle();
		~Candle() = default;

		void Deserialise(const std::string& candleData);

		inline float GetOpenPrice() const { return m_OpenPrice; }
		inline float GetClosePrice() const { return m_ClosePrice; }
		inline float GetHigh() const { return m_High; }
		inline float GetLowconst() const { return m_Low; }
		inline float GetPreviousOpenPrice() const { return m_PreviousClose; }
		inline std::time_t GetTimeStamp() const { return m_time; }

	private:
		float m_OpenPrice;
		float m_ClosePrice;
		float m_High;
		float m_Low;
		float m_PreviousClose;
		std::time_t m_time;
	};
}