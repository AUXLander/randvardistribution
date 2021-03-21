#pragma once

#include <ctime>
#include <random>
#include <cstdint>

class Distribution
{
protected:
	std::mt19937* generator;

public:
	Distribution(std::mt19937* const gen) : generator(gen) { }

	virtual void	 init(uint64_t min, uint64_t max) = 0;
	virtual uint64_t next(uint64_t min, uint64_t max) = 0;
};

class UniformDistribution : public Distribution
{
	std::uniform_int_distribution<uint64_t>* distribution{nullptr};

public:
	UniformDistribution(std::mt19937* const gen) : Distribution(gen) { }

	void init(uint64_t min, uint64_t max)
	{
		distribution = new std::uniform_int_distribution<uint64_t>(min, max);
	}

	uint64_t next(uint64_t min, uint64_t max)
	{
		if (distribution == nullptr)
		{
			init(min, max);
		}

		return distribution->operator()(*generator);
	}

	~UniformDistribution()
	{
		delete distribution;
	}
};

class PoissonDistribution : public Distribution
{
	std::poisson_distribution<uint64_t>* distribution{ nullptr };

public:
	PoissonDistribution(std::mt19937* const gen) : Distribution(gen) { }

	void init(uint64_t min, uint64_t max) final
	{
		distribution = new std::poisson_distribution<uint64_t>(static_cast<double>(max - min));
	}

	uint64_t inline next(uint64_t min, uint64_t max) final
	{
		if (distribution == nullptr)
		{
			init(min, max);
		}

		return distribution->operator()(*generator);
	}

	~PoissonDistribution()
	{
		delete distribution;
	}
};

class NormalDistribution : public Distribution
{
	std::normal_distribution<double>* distribution{ nullptr };

public:
	NormalDistribution(std::mt19937* const gen) : Distribution(gen) { }

	void init(uint64_t min, uint64_t max) final
	{
		// TO DO
		//distribution = new std::normal_distribution<uint64_t>();
	}

	uint64_t inline next(uint64_t min, uint64_t max) final
	{
		if (distribution == nullptr)
		{
			init(min, max);
		}

		//TO DO convert double -> uint64_t

		return distribution->operator()(*generator);
	}

	~NormalDistribution()
	{
		delete distribution;
	}
};