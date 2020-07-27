#include "gepch.h"
#include "URLData.h"

namespace gwcStock
{

	 URLData* URLData::GetInstance()
	{
		if (URLData::s_instance == nullptr)
			URLData::s_instance = new URLData;

		return URLData::s_instance;
	}



	 
	 size_t URLData::WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp)
	 {
		 size_t realsize = size * nmemb;
		 MemoryStruct* mem = (MemoryStruct*)userp;

		 char* ptr = (char*)realloc(mem->memory, mem->size + realsize + 1);

		 if (ptr == NULL) {
			 //out of memory! 
			 printf("not enough memory (realloc returned NULL)\n");
			 return 0;
		 }

		 mem->memory = ptr;
		 memcpy(&(mem->memory[mem->size]), contents, realsize);
		 mem->size += realsize;
		 mem->memory[mem->size] = 0;

		 return realsize;
	 }

	 std::string URLData::CurlURL(const std::string& url)
	 {
		 chunk.Clear();
		 curl_easy_setopt(m_curl, CURLOPT_URL, url.c_str());

		 curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, &URLData::WriteMemoryCallback);

		 curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, (void*)&chunk);
		 curl_easy_setopt(m_curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
		 m_res = curl_easy_perform(m_curl);

		 m_Buffer = chunk.memory;
		 return m_Buffer;
	 }

	 URLData::URLData()
	 {
		 curl_global_init(CURL_GLOBAL_ALL);
		 m_curl = curl_easy_init();
	 }

	 URLData* URLData::s_instance = nullptr;
}


