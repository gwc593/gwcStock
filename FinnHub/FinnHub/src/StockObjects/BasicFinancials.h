#pragma once
#include "gepch.h"
#include"Core/JSON.h"

namespace FinnHub 
{
	class Metric
	{
	public:
		Metric() = default;
		~Metric() = default;

		void Deserialise(const std::string& JSONdata)
		{
			JSON::DeserialiseMember(JSONdata,"52WeekHighDate", m_52WeekHighDate);
			JSON::DeserialiseMember(JSONdata,"52WeekLowDate", m_52WeekLowDate);
			JSON::DeserialiseMember(JSONdata,"10DayAverageTradingVolume", m_10DayAverageTradingVolume);
			JSON::DeserialiseMember(JSONdata,"13WeekPriceReturnDaily", m_13WeekPriceReturnDaily);
			JSON::DeserialiseMember(JSONdata,"26WeekPriceReturnDaily", m_26WeekPriceReturnDaily);
			JSON::DeserialiseMember(JSONdata,"3MonthAverageTradingVolume", m_3MonthAverageTradingVolume);
			JSON::DeserialiseMember(JSONdata,"52WeekHigh", m_52WeekHigh);
			JSON::DeserialiseMember(JSONdata,"52WeekLow", m_52WeekLow);
			JSON::DeserialiseMember(JSONdata,"52WeekPriceReturnDaily", m_52WeekPriceReturnDaily);
			JSON::DeserialiseMember(JSONdata,"5DayPriceReturnDaily", m_5DayPriceReturnDaily);
			JSON::DeserialiseMember(JSONdata,"assetTurnoverAnnual", m_assetTurnoverAnnual);
			JSON::DeserialiseMember(JSONdata,"assetTurnoverTTM", m_assetTurnoverTTM);
			JSON::DeserialiseMember(JSONdata,"beta", m_beta);
			JSON::DeserialiseMember(JSONdata,"bookValuePerShareAnnual", m_bookValuePerShareAnnual);
			JSON::DeserialiseMember(JSONdata,"bookValuePerShareQuarterly", m_bookValuePerShareQuarterly);
			JSON::DeserialiseMember(JSONdata,"bookValueShareGrowth5Y", m_bookValueShareGrowth5Y);
			JSON::DeserialiseMember(JSONdata,"capitalSpendingGrowth5Y", m_capitalSpendingGrowth5Y);
			JSON::DeserialiseMember(JSONdata,"cashFlowPerShareAnnual", m_cashFlowPerShareAnnual);
			JSON::DeserialiseMember(JSONdata,"cashFlowPerShareTTM", m_cashFlowPerShareTTM);
			JSON::DeserialiseMember(JSONdata,"cashPerSharePerShareAnnual", m_cashPerSharePerShareAnnual);
			JSON::DeserialiseMember(JSONdata,"cashPerSharePerShareQuarterly", m_cashPerSharePerShareQuarterly);
			JSON::DeserialiseMember(JSONdata,"currentDividendYieldTTM", m_currentDividendYieldTTM);
			JSON::DeserialiseMember(JSONdata,"currentEv/freeCashFlowAnnual", m_currentEv_freeCashFlowAnnual);
			JSON::DeserialiseMember(JSONdata,"currentEv/freeCashFlowTTM", m_currentEv_freeCashFlowTTM);
			JSON::DeserialiseMember(JSONdata,"currentRatioAnnual", m_currentRatioAnnual);
			JSON::DeserialiseMember(JSONdata,"currentRatioQuarterly", m_currentRatioQuarterly);
			JSON::DeserialiseMember(JSONdata,"dilutedEpsExclExtraTTM", m_dilutedEpsExclExtraTTM);
			JSON::DeserialiseMember(JSONdata,"dividendGrowthRate5Y", m_dividendGrowthRate5Y);
			JSON::DeserialiseMember(JSONdata,"dividendPerShare5Y", m_dividendPerShare5Y);
			JSON::DeserialiseMember(JSONdata,"dividendPerShareAnnual", m_dividendPerShareAnnual);
			JSON::DeserialiseMember(JSONdata,"dividendYield5Y", m_dividendYield5Y);
			JSON::DeserialiseMember(JSONdata,"dividendYieldIndicatedAnnual", m_dividendYieldIndicatedAnnual);
			JSON::DeserialiseMember(JSONdata,"dividendsPerShareTTM", m_dividendsPerShareTTM);
			JSON::DeserialiseMember(JSONdata,"ebitdAnnual", m_ebitdAnnual);
			JSON::DeserialiseMember(JSONdata,"ebitdPerShareTTM", m_ebitdPerShareTTM);
			JSON::DeserialiseMember(JSONdata,"ebitdTTM", m_ebitdTTM);
			JSON::DeserialiseMember(JSONdata,"ebitdaCagr5Y", m_ebitdaCagr5Y);
			JSON::DeserialiseMember(JSONdata,"ebitdaInterimCagr5Y", m_ebitdaInterimCagr5Y);
			JSON::DeserialiseMember(JSONdata,"ebtAnnual", m_ebtAnnual);
			JSON::DeserialiseMember(JSONdata,"ebtNormalizedAnnual", m_ebtNormalizedAnnual);
			JSON::DeserialiseMember(JSONdata,"ebtTTM", m_ebtTTM);
			JSON::DeserialiseMember(JSONdata,"epsBasicExclExtraItemsAnnual", m_epsBasicExclExtraItemsAnnual);
			JSON::DeserialiseMember(JSONdata,"epsBasicExclExtraItemsTTM", m_epsBasicExclExtraItemsTTM);
			JSON::DeserialiseMember(JSONdata,"epsExclExtraItemsAnnual", m_epsExclExtraItemsAnnual);
			JSON::DeserialiseMember(JSONdata,"epsExclExtraItemsTTM", m_epsExclExtraItemsTTM);
			JSON::DeserialiseMember(JSONdata,"epsGrowth3Y", m_epsGrowth3Y);
			JSON::DeserialiseMember(JSONdata,"epsGrowth5Y", m_epsGrowth5Y);
			JSON::DeserialiseMember(JSONdata,"epsGrowthQuarterlyYoy", m_epsGrowthQuarterlyYoy);
			JSON::DeserialiseMember(JSONdata,"epsGrowthTTMYoy", m_epsGrowthTTMYoy);
			JSON::DeserialiseMember(JSONdata,"epsInclExtraItemsAnnual", m_epsInclExtraItemsAnnual);
			JSON::DeserialiseMember(JSONdata,"epsInclExtraItemsTTM", m_epsInclExtraItemsTTM);
			JSON::DeserialiseMember(JSONdata,"epsNormalizedAnnual", m_epsNormalizedAnnual);
			JSON::DeserialiseMember(JSONdata,"focfCagr5Y", m_focfCagr5Y);
			JSON::DeserialiseMember(JSONdata,"freeCashFlowAnnual", m_freeCashFlowAnnual);
			JSON::DeserialiseMember(JSONdata,"freeCashFlowPerShareTTM", m_freeCashFlowPerShareTTM);
			JSON::DeserialiseMember(JSONdata,"freeCashFlowTTM", m_freeCashFlowTTM);
			JSON::DeserialiseMember(JSONdata,"freeOperatingCashFlow/revenue5Y", m_freeOperatingCashFlow_revenue5Y);
			JSON::DeserialiseMember(JSONdata,"freeOperatingCashFlow/revenueTTM", m_freeOperatingCashFlow_revenueTTM);
			JSON::DeserialiseMember(JSONdata,"grossMargin5Y", m_grossMargin5Y);
			JSON::DeserialiseMember(JSONdata,"grossMarginAnnual", m_grossMarginAnnual);
			JSON::DeserialiseMember(JSONdata,"grossMarginTTM", m_grossMarginTTM);
			JSON::DeserialiseMember(JSONdata,"inventoryTurnoverAnnual", m_inventoryTurnoverAnnual);
			JSON::DeserialiseMember(JSONdata,"inventoryTurnoverTTM", m_inventoryTurnoverTTM);
			JSON::DeserialiseMember(JSONdata,"longTermDebt/equityAnnual", m_longTermDebt_equityAnnual);
			JSON::DeserialiseMember(JSONdata,"longTermDebt/equityQuarterly", m_longTermDebt_equityQuarterly);
			JSON::DeserialiseMember(JSONdata,"marketCapitalization", m_marketCapitalization);
			JSON::DeserialiseMember(JSONdata,"monthToDatePriceReturnDaily", m_monthToDatePriceReturnDaily);
			JSON::DeserialiseMember(JSONdata,"netDebtAnnual", m_netDebtAnnual);
			JSON::DeserialiseMember(JSONdata,"netDebtInterim", m_netDebtInterim);
			JSON::DeserialiseMember(JSONdata,"netIncomeCommonAnnual", m_netIncomeCommonAnnual);
			JSON::DeserialiseMember(JSONdata,"netIncomeCommonNormalizedAnnual", m_netIncomeCommonNormalizedAnnual);
			JSON::DeserialiseMember(JSONdata,"netIncomeCommonTTM", m_netIncomeCommonTTM);
			JSON::DeserialiseMember(JSONdata,"netIncomeEmployeeAnnual", m_netIncomeEmployeeAnnual);
			JSON::DeserialiseMember(JSONdata,"netIncomeEmployeeTTM", m_netIncomeEmployeeTTM);
			JSON::DeserialiseMember(JSONdata,"netInterestCoverageAnnual", m_netInterestCoverageAnnual);
			JSON::DeserialiseMember(JSONdata,"netInterestCoverageTTM", m_netInterestCoverageTTM);
			JSON::DeserialiseMember(JSONdata,"netMarginGrowth5Y", m_netMarginGrowth5Y);
			JSON::DeserialiseMember(JSONdata,"netProfitMargin5Y", m_netProfitMargin5Y);
			JSON::DeserialiseMember(JSONdata,"netProfitMarginAnnual", m_netProfitMarginAnnual);
			JSON::DeserialiseMember(JSONdata,"netProfitMarginTTM", m_netProfitMarginTTM);
			JSON::DeserialiseMember(JSONdata,"operatingMargin5Y", m_operatingMargin5Y);
			JSON::DeserialiseMember(JSONdata,"operatingMarginAnnual", m_operatingMarginAnnual);
			JSON::DeserialiseMember(JSONdata,"operatingMarginTTM", m_operatingMarginTTM);
			JSON::DeserialiseMember(JSONdata,"payoutRatioAnnual", m_payoutRatioAnnual);
			JSON::DeserialiseMember(JSONdata,"payoutRatioTTM", m_payoutRatioTTM);
			JSON::DeserialiseMember(JSONdata,"pbAnnual", m_pbAnnual);
			JSON::DeserialiseMember(JSONdata,"pbQuarterly", m_pbQuarterly);
			JSON::DeserialiseMember(JSONdata,"pcfShareTTM", m_pcfShareTTM);
			JSON::DeserialiseMember(JSONdata,"peBasicExclExtraTTM", m_peBasicExclExtraTTM);
			JSON::DeserialiseMember(JSONdata,"peExclExtraAnnual", m_peExclExtraAnnual);
			JSON::DeserialiseMember(JSONdata,"peExclExtraHighTTM", m_peExclExtraHighTTM);
			JSON::DeserialiseMember(JSONdata,"peExclExtraTTM", m_peExclExtraTTM);
			JSON::DeserialiseMember(JSONdata,"peExclLowTTM", m_peExclLowTTM);
			JSON::DeserialiseMember(JSONdata,"peInclExtraTTM", m_peInclExtraTTM);
			JSON::DeserialiseMember(JSONdata,"peNormalizedAnnual", m_peNormalizedAnnual);
			JSON::DeserialiseMember(JSONdata,"pfcfShareAnnual", m_pfcfShareAnnual);
			JSON::DeserialiseMember(JSONdata,"pfcfShareTTM", m_pfcfShareTTM);
			JSON::DeserialiseMember(JSONdata,"pretaxMargin5Y", m_pretaxMargin5Y);
			JSON::DeserialiseMember(JSONdata,"pretaxMarginAnnual", m_pretaxMarginAnnual);
			JSON::DeserialiseMember(JSONdata,"pretaxMarginTTM", m_pretaxMarginTTM);
			JSON::DeserialiseMember(JSONdata,"priceRelativeToS_u0026P50013Week", m_priceRelativeToS_u0026P50013Week);
			JSON::DeserialiseMember(JSONdata,"priceRelativeToS_u0026P50026Week", m_priceRelativeToS_u0026P50026Week);
			JSON::DeserialiseMember(JSONdata,"priceRelativeToS_u0026P5004Week", m_priceRelativeToS_u0026P5004Week);
			JSON::DeserialiseMember(JSONdata,"priceRelativeToS_u0026P50052Week", m_priceRelativeToS_u0026P50052Week);
			JSON::DeserialiseMember(JSONdata,"priceRelativeToS_u0026P500Ytd", m_priceRelativeToS_u0026P500Ytd);
			JSON::DeserialiseMember(JSONdata,"psAnnual", m_psAnnual);
			JSON::DeserialiseMember(JSONdata,"psTTM", m_psTTM);
			JSON::DeserialiseMember(JSONdata,"ptbvAnnual", m_ptbvAnnual);
			JSON::DeserialiseMember(JSONdata,"ptbvQuarterly", m_ptbvQuarterly);
			JSON::DeserialiseMember(JSONdata,"quickRatioAnnual", m_quickRatioAnnual);
			JSON::DeserialiseMember(JSONdata,"quickRatioQuarterly", m_quickRatioQuarterly);
			JSON::DeserialiseMember(JSONdata,"receivablesTurnoverAnnual", m_receivablesTurnoverAnnual);
			JSON::DeserialiseMember(JSONdata,"receivablesTurnoverTTM", m_receivablesTurnoverTTM);
			JSON::DeserialiseMember(JSONdata,"revenueAnnual", m_revenueAnnual);
			JSON::DeserialiseMember(JSONdata,"revenueEmployeeAnnual", m_revenueEmployeeAnnual);
			JSON::DeserialiseMember(JSONdata,"revenueEmployeeTTM", m_revenueEmployeeTTM);
			JSON::DeserialiseMember(JSONdata,"revenueGrowth3Y", m_revenueGrowth3Y);
			JSON::DeserialiseMember(JSONdata,"revenueGrowth5Y", m_revenueGrowth5Y);
			JSON::DeserialiseMember(JSONdata,"revenueGrowthQuarterlyYoy", m_revenueGrowthQuarterlyYoy);
			JSON::DeserialiseMember(JSONdata,"revenueGrowthTTMYoy", m_revenueGrowthTTMYoy);
			JSON::DeserialiseMember(JSONdata,"revenuePerShareAnnual", m_revenuePerShareAnnual);
			JSON::DeserialiseMember(JSONdata,"revenuePerShareTTM", m_revenuePerShareTTM);
			JSON::DeserialiseMember(JSONdata,"revenueShareGrowth5Y", m_revenueShareGrowth5Y);
			JSON::DeserialiseMember(JSONdata,"revenueTTM", m_revenueTTM);
			JSON::DeserialiseMember(JSONdata,"roaRfy", m_roaRfy);
			JSON::DeserialiseMember(JSONdata,"roaa5Y", m_roaa5Y);
			JSON::DeserialiseMember(JSONdata,"roae5Y", m_roae5Y);
			JSON::DeserialiseMember(JSONdata,"roaeTTM", m_roaeTTM);
			JSON::DeserialiseMember(JSONdata,"roeRfy", m_roeRfy);
			JSON::DeserialiseMember(JSONdata,"roeTTM", m_roeTTM);
			JSON::DeserialiseMember(JSONdata,"roi5Y", m_roi5Y);
			JSON::DeserialiseMember(JSONdata,"roiAnnual", m_roiAnnual);
			JSON::DeserialiseMember(JSONdata,"roiTTM", m_roiTTM);
			JSON::DeserialiseMember(JSONdata,"tangibleBookValuePerShareAnnual", m_tangibleBookValuePerShareAnnual);
			JSON::DeserialiseMember(JSONdata,"tangibleBookValuePerShareQuarterly", m_tangibleBookValuePerShareQuarterly);
			JSON::DeserialiseMember(JSONdata,"tbvCagr5Y", m_tbvCagr5Y);
			JSON::DeserialiseMember(JSONdata,"totalDebt/totalEquityAnnual", m_totalDebt_totalEquityAnnual);
			JSON::DeserialiseMember(JSONdata,"totalDebt/totalEquityQuarterly", m_totalDebt_totalEquityQuarterly);
			JSON::DeserialiseMember(JSONdata,"totalDebtCagr5Y", m_totalDebtCagr5Y);
			JSON::DeserialiseMember(JSONdata,"yearToDatePriceReturnDaily", m_yearToDatePriceReturnDaily);
		}
		
#pragma region Getters
		const std::string Get52WeekHighDate() const { return m_52WeekHighDate; }
		const std::string Get52WeekLowDate() const { return m_52WeekLowDate; }
		const float Get10DayAverageTradingVolume() const { return					m_10DayAverageTradingVolume; }
		const float Get13WeekPriceReturnDaily() const { return						m_13WeekPriceReturnDaily; }
		const float Get26WeekPriceReturnDaily() const { return						m_26WeekPriceReturnDaily; }
		const float Get3MonthAverageTradingVolume() const { return					m_3MonthAverageTradingVolume; }
		const float Get52WeekHigh() const { return									m_52WeekHigh; }
		const float Get52WeekLow() const { return									m_52WeekLow; }
		const float Get52WeekPriceReturnDaily() const { return						m_52WeekPriceReturnDaily; }
		const float Get5DayPriceReturnDaily() const { return						m_5DayPriceReturnDaily; }
		const float GetAssetTurnoverAnnual() const { return							m_assetTurnoverAnnual; }
		const float GetAssetTurnoverTTM() const { return							m_assetTurnoverTTM; }
		const float GetBeta() const { return										m_beta; }
		const float GetBookValuePerShareAnnual() const { return						m_bookValuePerShareAnnual; }
		const float GetBookValuePerShareQuarterly() const { return					m_bookValuePerShareQuarterly; }
		const float GetBookValueShareGrowth5Y() const { return						m_bookValueShareGrowth5Y; }
		const float GetCapitalSpendingGrowth5Y() const { return						m_capitalSpendingGrowth5Y; }
		const float GetCashFlowPerShareAnnual() const { return						m_cashFlowPerShareAnnual; }
		const float GetCashFlowPerShareTTM() const { return							m_cashFlowPerShareTTM; }
		const float GetCashPerSharePerShareAnnual() const { return					m_cashPerSharePerShareAnnual; }
		const float GetCashPerSharePerShareQuarterly() const { return				m_cashPerSharePerShareQuarterly; }
		const float GetCurrentDividendYieldTTM() const { return						m_currentDividendYieldTTM; }
		const float GetCurrentEv_freeCashFlowAnnual() const { return				m_currentEv_freeCashFlowAnnual; }
		const float GetCurrentEv_freeCashFlowTTM() const { return					m_currentEv_freeCashFlowTTM; }
		const float GetCurrentRatioAnnual() const { return							m_currentRatioAnnual; }
		const float GetCurrentRatioQuarterly() const { return						m_currentRatioQuarterly; }
		const float GetDilutedEpsExclExtraTTM() const { return						m_dilutedEpsExclExtraTTM; }
		const float GetDividendGrowthRate5Y() const { return						m_dividendGrowthRate5Y; }
		const float GetDividendPerShare5Y() const { return							m_dividendPerShare5Y; }
		const float GetDividendPerShareAnnual() const { return						m_dividendPerShareAnnual; }
		const float GetDividendYield5Y() const { return								m_dividendYield5Y; }
		const float GetDividendYieldIndicatedAnnual() const { return				m_dividendYieldIndicatedAnnual; }
		const float GetDividendsPerShareTTM() const { return						m_dividendsPerShareTTM; }
		const float GetEbitdAnnual() const { return									m_ebitdAnnual; }
		const float GetEbitdPerShareTTM() const { return							m_ebitdPerShareTTM; }
		const float GetEbitdTTM() const { return									m_ebitdTTM; }
		const float GetEbitdaCagr5Y() const { return								m_ebitdaCagr5Y; }
		const float GetEbitdaInterimCagr5Y() const { return							m_ebitdaInterimCagr5Y; }
		const float GetEbtAnnual() const { return									m_ebtAnnual; }
		const float GetEbtNormalizedAnnual() const { return							m_ebtNormalizedAnnual; }
		const float GetEbtTTM() const { return										m_ebtTTM; }
		const float GetEpsBasicExclExtraItemsAnnual() const { return				m_epsBasicExclExtraItemsAnnual; }
		const float GetEpsBasicExclExtraItemsTTM() const { return					m_epsBasicExclExtraItemsTTM; }
		const float GetEpsExclExtraItemsAnnual() const { return						m_epsExclExtraItemsAnnual; }
		const float GetEpsExclExtraItemsTTM() const { return						m_epsExclExtraItemsTTM; }
		const float GetEpsGrowth3Y() const { return									m_epsGrowth3Y; }
		const float GetEpsGrowth5Y() const { return									m_epsGrowth5Y; }
		const float GetEpsGrowthQuarterlyYoy() const { return						m_epsGrowthQuarterlyYoy; }
		const float GetEpsGrowthTTMYoy() const { return								m_epsGrowthTTMYoy; }
		const float GetEpsInclExtraItemsAnnual() const { return						m_epsInclExtraItemsAnnual; }
		const float GetEpsInclExtraItemsTTM() const { return						m_epsInclExtraItemsTTM; }
		const float GetEpsNormalizedAnnual() const { return							m_epsNormalizedAnnual; }
		const float GetFocfCagr5Y() const { return									m_focfCagr5Y; }
		const float GetFreeCashFlowAnnual() const { return							m_freeCashFlowAnnual; }
		const float GetFreeCashFlowPerShareTTM() const { return						m_freeCashFlowPerShareTTM; }
		const float GetFreeCashFlowTTM() const { return								m_freeCashFlowTTM; }
		const float GetFreeOperatingCashFlow_revenue5Y() const { return				m_freeOperatingCashFlow_revenue5Y; }
		const float GetFreeOperatingCashFlow_revenueTTM() const { return			m_freeOperatingCashFlow_revenueTTM; }
		const float GetGrossMargin5Y() const { return								m_grossMargin5Y; }
		const float GetGrossMarginAnnual() const { return							m_grossMarginAnnual; }
		const float GetGrossMarginTTM() const { return								m_grossMarginTTM; }
		const float GetInventoryTurnoverAnnual() const { return						m_inventoryTurnoverAnnual; }
		const float GetInventoryTurnoverTTM() const { return						m_inventoryTurnoverTTM; }
		const float GetLongTermDebt_equityAnnual() const { return					m_longTermDebt_equityAnnual; }
		const float GetLongTermDebt_equityQuarterly() const { return				m_longTermDebt_equityQuarterly; }
		const float GetMarketCapitalization() const { return						m_marketCapitalization; }
		const float GetMonthToDatePriceReturnDaily() const { return					m_monthToDatePriceReturnDaily; }
		const float GetMetDebtAnnual() const { return								m_netDebtAnnual; }
		const float GetNetDebtInterim() const { return								m_netDebtInterim; }
		const float GetNetIncomeCommonAnnual() const { return						m_netIncomeCommonAnnual; }
		const float GetNetIncomeCommonNormalizedAnnual() const { return				m_netIncomeCommonNormalizedAnnual; }
		const float GetNetIncomeCommonTTM() const { return							m_netIncomeCommonTTM; }
		const float GetNetIncomeEmployeeAnnual() const { return						m_netIncomeEmployeeAnnual; }
		const float GetNetIncomeEmployeeTTM() const { return						m_netIncomeEmployeeTTM; }
		const float GetNetInterestCoverageAnnual() const { return					m_netInterestCoverageAnnual; }
		const float GetNetInterestCoverageTTM() const { return						m_netInterestCoverageTTM; }
		const float GetNetMarginGrowth5Y() const { return							m_netMarginGrowth5Y; }
		const float GetNetProfitMargin5Y() const { return							m_netProfitMargin5Y; }
		const float GetNetProfitMarginAnnual() const { return						m_netProfitMarginAnnual; }
		const float GetNetProfitMarginTTM() const { return							m_netProfitMarginTTM; }
		const float GetOperatingMargin5Y() const { return							m_operatingMargin5Y; }
		const float GetOperatingMarginAnnual() const { return						m_operatingMarginAnnual; }
		const float GetOperatingMarginTTM() const { return							m_operatingMarginTTM; }
		const float GetPayoutRatioAnnual() const { return							m_payoutRatioAnnual; }
		const float GetPayoutRatioTTM() const { return								m_payoutRatioTTM; }
		const float GetPbAnnual() const { return									m_pbAnnual; }
		const float GetPbQuarterly() const { return									m_pbQuarterly; }
		const float GetPcfShareTTM() const { return									m_pcfShareTTM; }
		const float GetPeBasicExclExtraTTM() const { return							m_peBasicExclExtraTTM; }
		const float GetPeExclExtraAnnual() const { return							m_peExclExtraAnnual; }
		const float GetPeExclExtraHighTTM() const { return							m_peExclExtraHighTTM; }
		const float GetPeExclExtraTTM() const { return								m_peExclExtraTTM; }
		const float GetPeExclLowTTM() const { return								m_peExclLowTTM; }
		const float GetPeInclExtraTTM() const { return								m_peInclExtraTTM; }
		const float GetPeNormalizedAnnual() const { return							m_peNormalizedAnnual; }
		const float GetPfcfShareAnnual() const { return								m_pfcfShareAnnual; }
		const float GetPfcfShareTTM() const { return								m_pfcfShareTTM; }
		const float GetPretaxMargin5Y() const { return								m_pretaxMargin5Y; }
		const float GetPretaxMarginAnnual() const { return							m_pretaxMarginAnnual; }
		const float GetPretaxMarginTTM() const { return								m_pretaxMarginTTM; }
		const float GetPriceRelativeToS_u0026P50013Week() const { return			m_priceRelativeToS_u0026P50013Week; }
		const float GetPriceRelativeToS_u0026P50026Week() const { return			m_priceRelativeToS_u0026P50026Week; }
		const float GetPriceRelativeToS_u0026P5004Week() const { return				m_priceRelativeToS_u0026P5004Week; }
		const float GetPriceRelativeToS_u0026P50052Week() const { return			m_priceRelativeToS_u0026P50052Week; }
		const float GetPriceRelativeToS_u0026P500Ytd() const { return				m_priceRelativeToS_u0026P500Ytd; }
		const float GetPsAnnual() const { return									m_psAnnual; }
		const float GetPsTTM() const { return										m_psTTM; }
		const float GetPtbvAnnual() const { return									m_ptbvAnnual; }
		const float GetPtbvQuarterly() const { return								m_ptbvQuarterly; }
		const float GetQuickRatioAnnual() const { return							m_quickRatioAnnual; }
		const float GetQuickRatioQuarterly() const { return							m_quickRatioQuarterly; }
		const float GetReceivablesTurnoverAnnual() const { return					m_receivablesTurnoverAnnual; }
		const float GetReceivablesTurnoverTTM() const { return						m_receivablesTurnoverTTM; }
		const float GetRevenueAnnual() const { return								m_revenueAnnual; }
		const float GetRevenueEmployeeAnnual() const { return						m_revenueEmployeeAnnual; }
		const float GetRevenueEmployeeTTM() const { return							m_revenueEmployeeTTM; }
		const float GetRevenueGrowth3Y() const { return								m_revenueGrowth3Y; }
		const float GetRevenueGrowth5Y() const { return								m_revenueGrowth5Y; }
		const float GetRevenueGrowthQuarterlyYoy() const { return					m_revenueGrowthQuarterlyYoy; }
		const float GetRevenueGrowthTTMYoy() const { return							m_revenueGrowthTTMYoy; }
		const float GetRevenuePerShareAnnual() const { return						m_revenuePerShareAnnual; }
		const float GetRevenuePerShareTTM() const { return							m_revenuePerShareTTM; }
		const float GetRevenueShareGrowth5Y() const { return						m_revenueShareGrowth5Y; }
		const float GetRevenueTTM() const { return									m_revenueTTM; }
		const float GetRoaRfy() const { return										m_roaRfy; }
		const float GetRoaa5Y() const { return										m_roaa5Y; }
		const float GetRoae5Y() const { return										m_roae5Y; }
		const float GetRoaeTTM() const { return										m_roaeTTM; }
		const float GetRoeRfy() const { return										m_roeRfy; }
		const float GetRoeTTM() const { return										m_roeTTM; }
		const float GetRoi5Y() const { return										m_roi5Y; }
		const float GetRoiAnnual() const { return									m_roiAnnual; }
		const float GetRoiTTM() const { return										m_roiTTM; }
		const float GetTangibleBookValuePerShareAnnual() const { return				m_tangibleBookValuePerShareAnnual; }
		const float GetTangibleBookValuePerShareQuarterly() const { return			m_tangibleBookValuePerShareQuarterly; }
		const float GetTbvCagr5Y() const { return									m_tbvCagr5Y; }
		const float GetTotalDebt_totalEquityAnnual() const { return					m_totalDebt_totalEquityAnnual; }
		const float GetTotalDebt_totalEquityQuarterly() const { return				m_totalDebt_totalEquityQuarterly; }
		const float GetTotalDebtCagr5Y() const { return								m_totalDebtCagr5Y; }
		const float GetYearToDatePriceReturnDaily() const { return		            m_yearToDatePriceReturnDaily; }
#pragma endregion


		
		
	private:
		std::string m_52WeekHighDate; 
		std::string m_52WeekLowDate; 
		float m_10DayAverageTradingVolume;
		float m_13WeekPriceReturnDaily; 
		float m_26WeekPriceReturnDaily; 
		float m_3MonthAverageTradingVolume; 
		float m_52WeekHigh; 
		float m_52WeekLow;
		float m_52WeekPriceReturnDaily; 
		float m_5DayPriceReturnDaily; 
		float m_assetTurnoverAnnual; 
		float m_assetTurnoverTTM; 
		float m_beta; 
		float m_bookValuePerShareAnnual; 
		float m_bookValuePerShareQuarterly; 
		float m_bookValueShareGrowth5Y; 
		float m_capitalSpendingGrowth5Y; 
		float m_cashFlowPerShareAnnual; 
		float m_cashFlowPerShareTTM; 
		float m_cashPerSharePerShareAnnual;
		float m_cashPerSharePerShareQuarterly; 
		float m_currentDividendYieldTTM; 
		float m_currentEv_freeCashFlowAnnual; 
		float m_currentEv_freeCashFlowTTM; 
		float m_currentRatioAnnual; 
		float m_currentRatioQuarterly; 
		float m_dilutedEpsExclExtraTTM; 
		float m_dividendGrowthRate5Y; 
		float m_dividendPerShare5Y; 
		float m_dividendPerShareAnnual; 
		float m_dividendYield5Y; 
		float m_dividendYieldIndicatedAnnual;
		float m_dividendsPerShareTTM;
		float m_ebitdAnnual; 
		float m_ebitdPerShareTTM; 
		float m_ebitdTTM; 
		float m_ebitdaCagr5Y; 
		float m_ebitdaInterimCagr5Y; 
		float m_ebtAnnual; 
		float m_ebtNormalizedAnnual; 
		float m_ebtTTM;
		float m_epsBasicExclExtraItemsAnnual;
		float m_epsBasicExclExtraItemsTTM; 
		float m_epsExclExtraItemsAnnual; 
		float m_epsExclExtraItemsTTM; 
		float m_epsGrowth3Y; 
		float m_epsGrowth5Y; 
		float m_epsGrowthQuarterlyYoy; 
		float m_epsGrowthTTMYoy; 
		float m_epsInclExtraItemsAnnual; 
		float m_epsInclExtraItemsTTM; 
		float m_epsNormalizedAnnual; 
		float m_focfCagr5Y;
		float m_freeCashFlowAnnual;
		float m_freeCashFlowPerShareTTM; 
		float m_freeCashFlowTTM;
		float m_freeOperatingCashFlow_revenue5Y; 
		float m_freeOperatingCashFlow_revenueTTM; 
		float m_grossMargin5Y; 
		float m_grossMarginAnnual; 
		float m_grossMarginTTM; 
		float m_inventoryTurnoverAnnual; 
		float m_inventoryTurnoverTTM; 
		float m_longTermDebt_equityAnnual; 
		float m_longTermDebt_equityQuarterly; 
		float m_marketCapitalization; 
		float m_monthToDatePriceReturnDaily; 
		float m_netDebtAnnual; 
		float m_netDebtInterim; 
		float m_netIncomeCommonAnnual; 
		float m_netIncomeCommonNormalizedAnnual; 
		float m_netIncomeCommonTTM; 
		float m_netIncomeEmployeeAnnual; 
		float m_netIncomeEmployeeTTM; 
		float m_netInterestCoverageAnnual; 
		float m_netInterestCoverageTTM; 
		float m_netMarginGrowth5Y; 
		float m_netProfitMargin5Y; 
		float m_netProfitMarginAnnual; 
		float m_netProfitMarginTTM; 
		float m_operatingMargin5Y; 
		float m_operatingMarginAnnual; 
		float m_operatingMarginTTM; 
		float m_payoutRatioAnnual; 
		float m_payoutRatioTTM; 
		float m_pbAnnual; 
		float m_pbQuarterly; 
		float m_pcfShareTTM; 
		float m_peBasicExclExtraTTM; 
		float m_peExclExtraAnnual;
		float m_peExclExtraHighTTM; 
		float m_peExclExtraTTM; 
		float m_peExclLowTTM; 
		float m_peInclExtraTTM; 
		float m_peNormalizedAnnual; 
		float m_pfcfShareAnnual; 
		float m_pfcfShareTTM; 
		float m_pretaxMargin5Y; 
		float m_pretaxMarginAnnual; 
		float m_pretaxMarginTTM; 
		float m_priceRelativeToS_u0026P50013Week; 
		float m_priceRelativeToS_u0026P50026Week; 
		float m_priceRelativeToS_u0026P5004Week;
		float m_priceRelativeToS_u0026P50052Week; 
		float m_priceRelativeToS_u0026P500Ytd;
		float m_psAnnual; 
		float m_psTTM; 
		float m_ptbvAnnual; 
		float m_ptbvQuarterly; 
		float m_quickRatioAnnual; 
		float m_quickRatioQuarterly; 
		float m_receivablesTurnoverAnnual; 
		float m_receivablesTurnoverTTM; 
		float m_revenueAnnual; 
		float m_revenueEmployeeAnnual; 
		float m_revenueEmployeeTTM;
		float m_revenueGrowth3Y; 
		float m_revenueGrowth5Y;
		float m_revenueGrowthQuarterlyYoy; 
		float m_revenueGrowthTTMYoy; 
		float m_revenuePerShareAnnual; 
		float m_revenuePerShareTTM; 
		float m_revenueShareGrowth5Y; 
		float m_revenueTTM; 
		float m_roaRfy; 
		float m_roaa5Y; 
		float m_roae5Y; 
		float m_roaeTTM; 
		float m_roeRfy; 
		float m_roeTTM;
		float m_roi5Y; 
		float m_roiAnnual; 
		float m_roiTTM;
		float m_tangibleBookValuePerShareAnnual; 
		float m_tangibleBookValuePerShareQuarterly;
		float m_tbvCagr5Y;
		float m_totalDebt_totalEquityAnnual; 
		float m_totalDebt_totalEquityQuarterly; 
		float m_totalDebtCagr5Y; 
		float m_yearToDatePriceReturnDaily; 
	};

	class BasicFinancials
	{
	public:
		BasicFinancials() = default;
		~BasicFinancials() = default;

		void Deserialise(const std::string& JSONdata)
		{
			m_Metric.Deserialise(JSON::GetSubObjectData(JSONdata, "metric"));
			JSON::DeserialiseMember(JSONdata, "metricType", m_MetricType);
			JSON::DeserialiseMember(JSONdata, "symbol", m_Symbol);
		}

		const Metric GetMetric()const { return m_Metric; }
		const std::string GetMetricType()const { return m_MetricType; }
		const std::string GetSymbol ()const { return m_Symbol; }
	private:
		Metric m_Metric;
		std::string m_MetricType;
		std::string m_Symbol;
	};
}