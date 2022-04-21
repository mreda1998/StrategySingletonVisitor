///////////////////////////////////////////////////////////
//  NumericFormatStrategy.cpp
//  Implementation of the Class NumericFormatStrategy
//  Created on:      02-avr.-2022 14:16:27
//  Original author: francois
///////////////////////////////////////////////////////////

#include "NumericFormatStrategy.h"

NumericFormatStrategy NumericFormatStrategy::instance;

NumericFormatStrategy::NumericFormatStrategy()
	: FormatStrategy(NumericFormat)
{
}

std::string NumericFormatStrategy::format(int time) const 
{
	// À compléter: décomposer la durée et construire une chaine avec en format numérique
	time_decomposition newTime = decomposeTime(time);
	return(std::to_string(newTime.days) + std::string(":") + std::to_string(newTime.hours) + std::string(":") + std::to_string(newTime.minutes) + std::string(":") + std::to_string(newTime.seconds) );
}