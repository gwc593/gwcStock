#include"gepch.h"
#include"WatchList.h"

WatchList::WatchList(const std::string& fp)
{
	ParseFile(fp);
}

WatchList::~WatchList()
{

}

void WatchList::AddSymbol(const std::string& symbol)
{
	m_WatchSymbols.push_back(symbol);
}

void WatchList::ParseFile(const std::string& fp)
{
	std::string Line;
	std::ifstream watchDefFile;
	
	m_WatchSymbols.clear();
	
	watchDefFile.open(fp);

	while (std::getline(watchDefFile, Line)) {
		m_WatchSymbols.push_back(Line);
	}

	watchDefFile.close();
}