#pragma once
#include "FinnHub.h"

class MACD {
public:
	/// <summary>
	/// MACD Constructor
	/// </summary>
	/// <returns></returns>
	MACD(std::vector<FinnHub::Candle> m_data);

/// <summary>
/// MACD Deconstructor
/// </summary>
	~MACD() = default;

	/// <summary>
	/// MACD Update
	/// </summary>
	//Update();

	/// <summary>
	/// Output MACD Histogram
	/// </summary>
	/// <returns></returns>
	const std::vector<double> MACDHist() { return m_MACDHist; }

	/// <summary>
	/// Output MACD Histogram Gradient
	/// </summary>
	/// <returns></returns>
	const std::vector<double> MACDdHist() { return m_MACDdHist; }

	/// <summary>
	/// Output MACD Histogram Gradient
	/// </summary>
	/// <returns></returns>
	const std::vector<double> MACDd3Hist() { return m_MACDd3Hist; }

private:

	void CalcHist(std::vector<FinnHub::Candle> m_data);
	std::vector<double> m_MACDHist;
	std::vector<double> m_MACDdHist;
	std::vector<double> m_MACDd3Hist;

};
