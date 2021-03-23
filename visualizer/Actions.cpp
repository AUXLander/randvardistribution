#include "pch.h"
#include "Actions.h"

using namespace System::Collections::Generic;


std::map<std::string, DistributionBase*> list;

std::mt19937* generator;
std::random_device device;
std::map<uint64_t, uint64_t> histogramm;

void Init(System::Windows::Forms::ComboBox^ select)
{
	generator = new std::mt19937(device());

	list["Равномерное распределение"]	= new Distribution<DistributionBase::Uniform>(generator, 0, 100);
	list["Пуассоновское распределение"] = new Distribution<DistributionBase::Poisson>(generator, 0, 100);
	list["Нормальное распределение"]	= new Distribution<DistributionBase::Normal> (generator, 0, 100);

	select->Items->Clear();

	for (const auto item : list)
	{
		select->Items->Add(gcnew System::String(item.first.c_str()));
	}
}

void LoadChart(System::Windows::Forms::DataVisualization::Charting::Chart^ chart, std::map<uint64_t, uint64_t>& histogramm)
{
	chart->ChartAreas->Clear();
	auto chartArea = chart->ChartAreas->Add("HistogrammChartArea");

	chart->Series->Clear();
	auto chartSeria = chart->Series->Add("HistogrammSeries");

	std::pair<uint64_t,uint64_t> min = *(histogramm.cbegin());
	std::pair<uint64_t,uint64_t> max = *(histogramm.cbegin());

	for (const auto point : histogramm)
	{
		if (point.second > max.second)
		{
			max = point;
		}
		else if (point.second < min.second)
		{
			min = point;
		}

		const double x = static_cast<double>(point.first);
		const double y = static_cast<double>(point.second);

		chartSeria->Points->AddXY(x,y);
	}
}

void LoadData(System::Windows::Forms::ComboBox^ select, System::Windows::Forms::DataVisualization::Charting::Chart^ chart)
{
	System::String^ clrStr = (System::String^)select->SelectedItem;

	if (clrStr != nullptr)
	{
		char cStr[50] = { 0 };
		if (clrStr->Length < sizeof(cStr))
		{
			sprintf(cStr, "%s", clrStr);
		}

		makeHistogramm(list[std::string(cStr)], histogramm);

		LoadChart(chart, histogramm);
	}
}

void makeHistogramm(DistributionBase* distribution, std::map<uint64_t, uint64_t>& histogramm, const unsigned int N)
{
	histogramm.clear();

	for (size_t n = 0; n < N; ++n)
	{
		++histogramm[distribution->next()];
	}
}