#include"gepch.h"
#include"CandleArray.h"

namespace FinnHub 
{

	void CandleArray::Deserialise(const std::string& historicData)
	{
		std::string closeRaw;
		std::string openRaw;
		std::string highRaw;
		std::string lowRaw;
		std::string timeRaw;

		JSON::DeserialiseMemberArr(historicData, "c", closeRaw);
		JSON::DeserialiseMemberArr(historicData, "o", openRaw);
		JSON::DeserialiseMemberArr(historicData, "h", highRaw);
		JSON::DeserialiseMemberArr(historicData, "l", lowRaw);
		JSON::DeserialiseMemberArr(historicData, "t", timeRaw);
	}


}