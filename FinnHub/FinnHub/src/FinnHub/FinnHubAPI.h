#pragma once
#include<string>
class FinnHubAPI
{
public:

	FinnHubAPI();
	FinnHubAPI(std::string key);
	~FinnHubAPI() = default;

	void SetKey(std::string key);
	void SetBase(std::string base);

	std::string GetQuote(const char* symbol);
private:


	std::string m_Key;
	std::string m_Base;
};