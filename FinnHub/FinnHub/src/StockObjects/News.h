#pragma once
#include "gepch.h"
#include "Core/JSON.h"
namespace FinnHub {

	class News
	{
	public:
		News() = default;
		~News() = default;

		void Deserialise(const std::string& companyProfileData)
		{
			JSON::DeserialiseMember(companyProfileData, "category", m_Category);
			JSON::DeserialiseMember(companyProfileData, "datetime", m_DateTime);
			JSON::DeserialiseMember(companyProfileData, "headline", m_Headline);
			JSON::DeserialiseMember(companyProfileData, "id", m_ID);
			JSON::DeserialiseMember(companyProfileData, "image", m_Image);
			JSON::DeserialiseMember(companyProfileData, "related", m_Related);
			JSON::DeserialiseMember(companyProfileData, "source", m_Source);
			JSON::DeserialiseMember(companyProfileData, "summary", m_Summary);
			JSON::DeserialiseMember(companyProfileData, "url", m_URL);

		}

		const std::string GetCategory() const { return m_Category; }
		const std::time_t GetDateTime() const { return m_DateTime; }
		const std::string GetHeadline() const { return m_Headline; }
		const int GetID() const { return m_ID; }
		const std::string GetImageURL() const { return m_Image; }
		const std::string GetSymbol() const { return m_Related; }
		const std::string GetSource() const { return m_Source; }
		const std::string GetSummary() const { return m_Summary; }
		const std::string GetURL() const { return m_URL; }



	private:
		std::string m_Category;
		std::time_t m_DateTime;
		std::string m_Headline;
	    int m_ID;
		std::string m_Image;
		std::string m_Related;
		std::string m_Source;
		std::string m_Summary;
		std::string m_URL;

	};
}