#pragma once

namespace gwcStock
{
	class Symbol
	{
	public:

		Symbol(const std::string& desc, const std::string& dSym, const std::string& sym)
			:m_Description(desc), m_DisplaySymbol(dSym), m_Symbol(sym){	}

		~Symbol() = default;

		const std::string& GetDesctription() const { return m_Description; }
		const std::string& GetDisplaySymbol() const  { return m_DisplaySymbol; }
		const std::string& GetSymbol() const { return m_Symbol; }

		void SetDescription(const std::string& desc) { m_Description = desc; }
		void SetDisplaySymbol(const std::string& dSym) { m_DisplaySymbol = dSym; }
		void SetSymbol(const std::string& sym) { m_Symbol = sym; }

	private:
		std::string m_Description;
		std::string m_DisplaySymbol;
		std::string m_Symbol;
	};
}
