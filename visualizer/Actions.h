#pragma once
#include "../src/distribution.hpp"
#include <map>


void Init(System::Windows::Forms::ComboBox^ select);

void LoadData(System::Windows::Forms::ComboBox^ select, System::Windows::Forms::DataVisualization::Charting::Chart^ chart);
void LoadChart(System::Windows::Forms::DataVisualization::Charting::Chart^ chart, std::map<uint64_t, uint64_t>& histogramm);

void makeHistogramm(DistributionBase* distribution, std::map<uint64_t, uint64_t>& histogramm, const unsigned int N = 10000);