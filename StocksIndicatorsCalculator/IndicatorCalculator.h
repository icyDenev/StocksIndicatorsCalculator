#pragma once
#include <vector>
#include <string>

struct Indicators
{
	std::string symbol;
	std::vector<long double> tda; // 10-day average
};

struct Quote
{
	long double open;
	long double high;
	long double low;
	long double close;
	long double volume;
};

class IndicatorCalculator
{
	private:
		static bool isDouble(const std::string& s);
	public:
		static void CalculateTDA(std::vector<Quote>& quotes, Indicators& indicators, const std::string stockSymbol);
};