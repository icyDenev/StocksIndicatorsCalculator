#include "IndicatorCalculator.h"

using namespace std;

int main()
{
	vector<Quote> quotes;
	Indicators indicators;

	IndicatorCalculator::CalculateTDA(quotes, indicators, "AAPL");

	return 0;
}