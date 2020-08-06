#pragma once
#include "gepch.h"

#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) {return this->fn(std::forward<decltype(args)>(args)...);}
#define BIND_EVENT_FNO(fn,O)[this](auto&&... args) -> decltype(auto) {return O->fn(std::forward<decltype(args)>(args)...);}

class IEventCallback
{
public:
	static uint32_t GetNextID() { return s_NextID++; }
	virtual ~IEventCallback() = default;
private:
	IEventCallback() = default;
	static uint32_t s_NextID;

};


template<typename ...T>
class EventCallback
{
public:
	EventCallback()
	{
		m_ID = IEventCallback::GetNextID();
	}

	void SetCallback(std::function<bool(T...)> callbackFunction)
	{
		m_Callback = callbackFunction;
	}

	EventCallback(std::function<bool(T...)> callbackFunction)
	{
		m_ID = IEventCallback::GetNextID();
		m_Callback = callbackFunction;
	}

	virtual ~EventCallback() = default;

	uint32_t GetID() { return m_ID; }
	std::function<bool(T...)>& GetFunction() { return m_Callback; }

private:

	uint32_t m_ID;
	std::function<bool(T...)> m_Callback;
};
