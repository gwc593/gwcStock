#pragma once

class WatchList
{
public:
	WatchList(const std::string& fp);
	~WatchList();

	void AddSymbol(const std::string& symbol);

	std::vector<std::string> GetSymbols(){ return m_WatchSymbols; }

private:
	void ParseFile(const std::string& fp);
	std::vector<std::string> m_WatchSymbols;
};