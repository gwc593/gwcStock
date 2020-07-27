#pragma once
#include "gepch.h"
#include "Core/JSON.h"
namespace FinnHub
{
	class Peers
	{
	public:
		Peers() = default;
		~Peers() = default;

		const std::vector<std::string> GetPeers()const { return m_Peers; }
	
		void Deserialise(const std::string& JSONdata)
		{
			std::string cpy = JSONdata;

			//remove square brackets / array markers
			cpy.erase(0, 1);
			cpy.erase(cpy.size() - 1);

			std::stringstream ss(cpy);

			while (ss.good()) {
				std::string substr;
				getline(ss, substr, ',');
				substr.erase(0, 1);
				substr.erase(substr.size() - 1);
				m_Peers.push_back(substr);
			}
		}

	private:
		std::vector<std::string> m_Peers;
	};
}