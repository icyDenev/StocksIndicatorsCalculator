#pragma once
#include <vector>
#include <string>

/// @brief Indicators of a stock
struct Indicators
{
	std::string symbol;
	std::vector<long double> tda; // 10-day average
};

/// @brief Quote of a stock
struct Quote
{
	long double open;
	long double high;
	long double low;
	long double close;
	long double volume;
};

/// @brief Indicator calculator
class IndicatorCalculator
{
	private:
		static bool isDouble(const std::string& s);
	public:
		static void CalculateTDA(std::vector<Quote>& quotes, Indicators& indicators, const std::string stockSymbol);
};