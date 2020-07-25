#pragma once

class FinnHub
{
public:

	static FinnHub* Get();

	std::string GetQuote(const char* symbol);

private:
	FinnHub();
	static FinnHub* S_Instance;

	const char* m_Key;
	const char* m_Base;
};