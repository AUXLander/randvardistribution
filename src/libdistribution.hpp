#pragma once

#include <ctime>
#include <random>
#include <cstdint>
#include <stdio.h>

class DistributionBase
{
	int64_t m_min;
	int64_t m_max;

	int64_t m_length;

protected:
	std::mt19937* generator;

	void setMinMax(int64_t minval, int64_t maxval)
	{
		m_min = 0;
		m_max = 0;

		if (minval < maxval)
		{
			m_min = minval;
			m_max = maxval;
		}
		else
		{
			m_min = maxval;
			m_max = minval;
		}

		m_length = m_max - m_min;
	}

public:
	typedef std::exponential_distribution<int64_t> Exponential;
	typedef std::uniform_int_distribution<int64_t> Uniform;
	typedef std::normal_distribution<double>        Normal;

	const int64_t& min = m_min;
	const int64_t& max	= m_max;
	const int64_t& length = m_length;

	DistributionBase(std::mt19937* const gen) : generator(gen), m_min(0), m_max(0), m_length(0) { }

	virtual void	init(int64_t minval, int64_t maxval) = 0;
	virtual int64_t next() = 0;
};

template<class T> class Distribution : public DistributionBase
{
	T* distribution{ nullptr };

	T* distribution_init()
	{
		return nullptr;
	}

public:
	Distribution(std::mt19937* const gen) : DistributionBase(gen) { }
	Distribution(std::mt19937* const gen, int64_t minval, int64_t maxval) : DistributionBase(gen) 
	{
		init(minval, maxval);
	}

	void init(int64_t minval, int64_t maxval) final
	{
		if (distribution != nullptr)
		{
			delete distribution;
		}

		setMinMax(minval, maxval);

		distribution = distribution_init();
	}

	int64_t inline next() final
	{
		return distribution ? static_cast<int64_t>(distribution->operator()(*generator)) : 0LL;
	}

	~Distribution()
	{
		if (distribution != nullptr)
		{
			delete distribution;
		}
	}
};

template<> DistributionBase::Uniform* Distribution<DistributionBase::Uniform>::distribution_init()
{
	return new DistributionBase::Uniform(min, max);
}

template<> DistributionBase::Exponential* Distribution<DistributionBase::Exponential>::distribution_init()
{
	return new DistributionBase::Exponential(10.0);
}

template<> DistributionBase::Normal* Distribution<DistributionBase::Normal>::distribution_init()
{
	// https://baguzin.ru/wp/ravnomernoe-i-eksponentsialnoe-rasp/

	const double radius = static_cast<double>(length / 2.0);
	const double disp_3 = (radius * radius)  / 4.0;
	const double disp   = disp_3 / 3.0;
	const double sigma  = sqrt(disp);
	const double mean   = static_cast<double>(min + max) / 2;

	return new DistributionBase::Normal(mean, sigma);
}