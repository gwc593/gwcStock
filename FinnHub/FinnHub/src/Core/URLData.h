#pragma once
#include<curl/curl.h>

struct MemoryStruct
{
	char* memory;
	size_t size;

	MemoryStruct()
	{
		memory = nullptr;
		size = 0;
	}

	void Clear()
	{
		if (memory != nullptr) {
			free(memory);
			memory = nullptr;
		}
		size = 0;
	}
};

namespace gwcStock
{
	class URLData
	{
	public:

		static URLData* GetInstance();
		static size_t WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp);

		std::string CurlURL(const std::string& url);

		~URLData() = default;

	private:
		URLData();
		static URLData* s_instance;
		CURL* m_curl;

		std::string m_Buffer;
		CURLcode m_res;
		MemoryStruct chunk;
	};
}