#include "IndicatorCalculator.h"
#include <fstream>
#include <iostream>
#include <sstream>

bool IndicatorCalculator::isDouble(const std::string& s) {
	char* end = nullptr;
	double val = strtod(s.c_str(), &end);
	return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}

void IndicatorCalculator::CalculateTDA(std::vector<Quote>& quotes, Indicators& indicators, const std::string stockSymbol) {
	double tda;
	char div = ',';
	Quote quote;
	std::ifstream stockFile("C:\\Users\\icyde\\source\\repos\\CMPS361\\SPXDataFetcher\\SPXDataFetcher\\bin\\Release\\net7.0\\" + stockSymbol + ".csv"), indicatorsFile(stockSymbol + "-indicators.csv");
	
	// Check if the stocks file is open
	if (stockFile.is_open()) {
		// Read the stocks file
		std::string number, line;

		std::getline(stockFile, line);

		// Read the stocks file
		while (std::getline(stockFile, line))
		{
			std::stringstream str(line);

			std::getline(str, number, div);
			std::getline(str, number, div);
			if (isDouble(number)) {
				quote.open = stod(number);
			}
			std::getline(str, number, div);
			if (isDouble(number)) {
				quote.high = stod(number);
			}
			std::getline(str, number, div);
			if (isDouble(number)) {
				quote.low = stod(number);
			}
			std::getline(str, number, div);
			if (isDouble(number)) {
				quote.close = stod(number);
			}
			std::getline(str, number, div);
			if (isDouble(number)) {
				quote.volume = stod(number);
			}

			quotes.push_back(quote);
		}

		stockFile.close();

		// Check if the indicators file exists
		if (!indicatorsFile.is_open()) {
			tda = 0;
			
			for (int i = 0; i < 10; ++i) {
				tda += quotes[i].close / 10;
			}

			indicators.tda.push_back(tda);

			// Calculate the TDA
			for (int i = 10; i < quotes.size(); ++i) {
				tda += quotes[i].close / 10;
				tda -= quotes[i - 10].close / 10;
				indicators.tda.push_back(tda);
			}
		}
		// If the indicators file exists, read the indicators from it
		else {
			while (indicatorsFile.good()) {
				indicatorsFile >> tda;
				// TODO: Add more indicators
				
				indicators.tda.push_back(tda);
			}
		}
	}
	// If the stocks file doesn't exist, print an error message
	else {
		std::cout << "Couldn't open the file" << std::endl;

		return;
	}
}