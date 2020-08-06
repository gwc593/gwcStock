#include "FinnHub.h"
#include "gepch.h"
#include "MACD.h"

MACD::MACD(std::vector<FinnHub::Candle> data){
	MACD::CalcHist(data);
}

void MACD::CalcHist(std::vector<FinnHub::Candle> data) {
	int k = 0;
	int m_length = data.size();
	int l26 = 26;
	int l12 = 12;
	int l9 = 9;
	int lema26 = l26 + 1;
	int lema12 = l12 + 1;
	int lema9 = l9 + 1;
	int m_l26 = m_length - l26;
	int m_l12 = m_length - l12;
	int m_emal26 = m_l26 - 1;
	int m_emal12 = m_l12 - 1;
	int m_l9 = m_emal26 - l9;
	int m_emal9 = m_l9 - 1;
	double m_sum;
	double m_26pEMAmult;
	double m_12pEMAmult;
	double m_9pEMAmult;
	std::vector<double> m_datavec(m_length);
	std::vector<double> m_26pMA(m_l26);
	std::vector<double> m_12pMA(m_l12);
	std::vector<double> m_26pEMA(m_emal26);
	std::vector<double> m_12pEMA(m_emal12);
	std::vector<double> m_MACD(m_emal26);
	std::vector<double> m_MACDMA(m_l9);
	std::vector<double> m_Signal(m_emal9);

	m_26pEMAmult = 2 / (l26 + 1.0);
	m_12pEMAmult = 2 / (l12 + 1.0);
	m_9pEMAmult = 2 / (l9 + 1.0);

	for (auto element : data) {
		m_datavec[k] = (double)element.GetCurrentPrice();
		k++;
	}

	if (m_length < lema26) {; }

	for (int j = 0; j < m_l26; j++) {
		m_sum = 0.0;
		for (int i = j; i < j + l26; i++) {
			m_sum += m_datavec[i];
		}
		m_26pMA[j] = m_sum / (double)l26;


		m_sum = 0.0;
		for (int j = 0; j < m_l12; j++) {
			m_sum = 0.0;
			for (int i = j; i < j + l12; i++) {
				m_sum += m_datavec[i];
			}
			m_12pMA[j] = m_sum / (double)l12;
		}

		
	}

	for (int j = 0; j < m_emal26; j++) {
		m_26pEMA[j] = (m_datavec[j + (uint16_t)1] * m_26pEMAmult) + (m_26pMA[j] * (1 - m_26pEMAmult));
		}

	for (int j = 0; j < m_emal12; j++) {
		m_12pEMA[j] = (m_datavec[j + (uint16_t)1] * m_12pEMAmult) + (m_12pMA[j] * (1 - m_12pEMAmult));
	}

	for (int j = 0; j < m_emal26; j++) {
		m_MACD[j] = m_12pEMA[j + (uint16_t)(m_emal12 - m_emal26)] - m_26pEMA[j];
	}

	for (int j = 0; j < m_l9; j++) {
		m_sum = 0.0;
		for (int i = j; i < j + l9; i++) {
			m_sum += m_MACD[i];
		}
		m_MACDMA[j] = m_sum / (double)l9;
	}

	for (int j = 0; j < m_emal9; j++) {
		m_Signal[j] = (m_MACD[j + (uint16_t)1] * m_9pEMAmult) + (m_MACDMA[j] * (1 - m_9pEMAmult));
	}

	for (int j = 0; j < m_emal9; j++) {
		m_MACDHist.push_back(m_MACD[j+ (uint16_t)1] - m_Signal[j]);
	}

	for (int j = 1; j < m_emal9; j++) {
		m_MACDdHist.push_back(m_MACDHist[j] - m_MACDHist[j- (uint16_t)1]);
	}

	for (int j = 3; j < m_emal9; j++) {
		m_MACDd3Hist.push_back((m_MACDHist[j] - m_MACDHist[j - (uint16_t)3])/3);
	}
}