#include"gepch.h"
#include"CandleArray.h"

namespace FinnHub 
{

	void CandleArray::Deserialise(const std::string& historicData)
	{



		std::vector<float> close;
		std::vector<float> open;
		std::vector<float> high;
		std::vector<float> low;
		std::vector<std::time_t> timeStamp;

		{
		std::string closeRaw;
		JSON::DeserialiseMemberArr(historicData, "c", closeRaw);
			std::stringstream ss(closeRaw);
			while (ss.good()) {
				std::string substr;
				getline(ss, substr, ',');
				close.push_back(std::stof(substr));
			}
		}

		
		{
		std::string openRaw;
		JSON::DeserialiseMemberArr(historicData, "o", openRaw);
			std::stringstream ss(openRaw);
			while (ss.good()) {
				std::string substr;
				getline(ss, substr, ',');
				open.push_back(std::stof(substr));
			}
		}

		{
		std::string highRaw;
		JSON::DeserialiseMemberArr(historicData, "h", highRaw);
			std::stringstream ss(highRaw);
			while (ss.good()) {
				std::string substr;
				getline(ss, substr, ',');
				high.push_back(std::stof(substr));
			}
		}

		{
		std::string lowRaw;
		JSON::DeserialiseMemberArr(historicData, "l", lowRaw);
			std::stringstream ss(lowRaw);
			while (ss.good()) {
				std::string substr;
				getline(ss, substr, ',');
				low.push_back(std::stof(substr));
			}
		}

		{
			std::string timeRaw;
			JSON::DeserialiseMemberArr(historicData, "t", timeRaw);
			std::stringstream ss(timeRaw);
			while (ss.good()) {
				std::string substr;
				getline(ss, substr, ',');
				timeStamp.push_back(std::atoll(substr.c_str()));
			}
		}

		auto size = timeStamp.size();

		for (int i = 0; i < size; i++) {
			Candle tmp;
			tmp.SetClosePrice(close[i]);
			tmp.SetHighPrice(high[i]);
			tmp.SetLowPrice(low[i]);
			tmp.SetOpenPrice(open[i]);
			tmp.SetTimeStamp(timeStamp[i]);
			m_Data.push_back(tmp);
		}
	}


}