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
		//TODO GWC - this will not work if object has sub object, need to find where sum of open -close = 0
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

	static void DeserialiseMemberArr(const std::string& serialisedObj, const std::string& memberToken, std::string& output)
	{
		std::string data;
		size_t end;

		data = serialisedObj.substr(serialisedObj.find("\"" + memberToken + "\"") + (3 + memberToken.size()));

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


	static void Print(const std::string& JSONdata)
	{
		uint32_t noOpen =0;
		char c;
		int tabSize = 4;
		for (int i = 0; i < JSONdata.size(); i++) {
			c = JSONdata.c_str()[i];

			switch (c) {
				case '{': 
				{
					std::cout << std::endl;
					printTabs(noOpen, 4);
					std::cout << c << std::endl;
					++noOpen;
					printTabs(noOpen, 4);
					break;
				}
				case '[':
				{
					std::cout << std::endl;
					printTabs(noOpen, 4);
					std::cout << c << std::endl;
					++noOpen;
					printTabs(noOpen, 4);
					break;
				}
				case '}':
				{
					std::cout << std::endl;
					--noOpen;
					printTabs(noOpen, 4);
					std::cout << c;
					if (JSONdata.c_str()[i + 1] == ',') {
						std::cout << "," << std::endl;
						i++;
					}
					std::cout << std::endl;
					printTabs(noOpen, 4);
					break;
				}
				case ']':
				{
					std::cout << std::endl;
					--noOpen;
					printTabs(noOpen, 4);
					std::cout << c;
					if (JSONdata.c_str()[i + 1] == ',') {
						std::cout << "," << std::endl;
						i++;
					}
					std::cout << std::endl;
					printTabs(noOpen, 4);
					break;
				}
				case',':
				{
					std::cout << c << std::endl;
					printTabs(noOpen, 4);
					break;
				}
				default: {
					std::cout << c;
					break;
				}
			}
		}
	}

private:
	JSON() = default;

	static void printTabs(uint32_t n, uint32_t size)
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < size; j++) {
				std::cout << " ";
			}
		}
	}
};