#pragma once
#include "gepch.h"


class JSON
{
public:
	~JSON() = default;

	static int32_t NumObjects(const std::string& serialisedObjs)
	{
		uint32_t nOpen = 0;
		uint32_t nClosed = 0;
		for (int i = 0; i < serialisedObjs.size(); i++) {
			if (serialisedObjs.c_str()[i] == '{')
				++nOpen;
			if (serialisedObjs.c_str()[i] == '}')
				++nClosed;
		}

		if (nOpen != nClosed)
			return -1;

		return nOpen;
	}

	static std::string GetObjDataN(const std::string& serialisedObjs, uint32_t n)
	{
		uint32_t nOpen = 0;
		uint32_t pos = 0;

		std::string cpy = serialisedObjs;

		while (nOpen < (n+1) && pos < serialisedObjs.size()) {
			if (serialisedObjs.c_str()[pos++] == '{')
				++nOpen;
		}
		--pos;

		
		cpy.erase(0, pos);
		cpy.erase(cpy.find('}') + 1, cpy.size());
		return cpy;
	}

	static void DeserialiseMember(const std::string& serialisedObj, const std::string& memberToken, float& output)
	{
		std::string data;
		size_t end;

		data = serialisedObj.substr(serialisedObj.find("\"" +memberToken +"\"") + (3+memberToken.size()));

		end = data.find(",");
		if (end == std::string::npos)
			end = data.find("}");

		data.erase(end, data.size() - end);
		try {
		output = std::stof(data);
		}
		catch (...) {
			output = 0.0f;
		}
	}

	static void DeserialiseMember(const std::string& serialisedObj, const std::string& memberToken, double& output)
	{
		std::string data;
		size_t end;

		data = serialisedObj.substr(serialisedObj.find("\"" + memberToken + "\"") + (3 + memberToken.size()));

		end = data.find(",");
		if (end == std::string::npos)
			end = data.find("}");

		data.erase(end, data.size() - end);

		try {
		output = std::stod(data);
		}
		catch (...) {
			output = 0.0;
		}
	}

	static void DeserialiseMember(const std::string& serialisedObj, const std::string& memberToken, std::time_t& output)
	{
		std::string data;
		size_t end;
		
		data = serialisedObj.substr(serialisedObj.find("\"" + memberToken + "\"") + (3 + memberToken.size()));

		end = data.find(",");
		if(end == std::string::npos)
			end = data.find("}");

		data.erase(end, data.size() - end);

		try {
		output = std::atoll(data.c_str());
		}
		catch (...) {
			output = 0;
		}
	}

	static void DeserialiseMember(const std::string& serialisedObj, const std::string& memberToken, int& output)
	{
		std::string data;
		size_t end;

		data = serialisedObj.substr(serialisedObj.find("\"" + memberToken + "\"") + (3 + memberToken.size()));

		end = data.find(",");
		if (end == std::string::npos)
			end = data.find("}");

		data.erase(end, data.size() - end);
		try {
			output = std::atoi(data.c_str());
		}
		catch (...) {
			output = 0;
		}
		
	}

	static void DeserialiseMember(const std::string& serialisedObj, const std::string& memberToken, std::string& output)
	{
		std::string data;
		size_t end;

		data = serialisedObj.substr(serialisedObj.find("\"" + memberToken + "\"") + (3 + memberToken.size()));

		end = data.find(",");
		if (end == std::string::npos)
			end = data.find("}");

		data.erase(end, data.size() - (end));

		data.erase(0, 1);
		data.erase(data.size() - 1);
		
		output = data;
	}

	static std::string GetSubObjectData(const std::string& serialisedObj, const std::string& memberToken)
	{
		std::string data;
		size_t end;

		data = serialisedObj.substr(serialisedObj.find("\"" + memberToken + "\"") + (3 + memberToken.size()));

		end = data.find("}");

		data.erase(end, data.size() - (end+1));

		return data;
	}



private:
	JSON() = default;
};