///////////////////////////////////////////////////////////
//  LitteralFormatStrategy.cpp
//  Implementation of the Class LitteralFormatStrategy
//  Created on:      02-avr.-2022 14:16:27
//  Original author: francois
///////////////////////////////////////////////////////////

#include "LitteralFormatStrategy.h"
#include "TimeFormater.h"

LitteralFormatStrategy LitteralFormatStrategy::instance;


LitteralFormatStrategy::LitteralFormatStrategy()
	: FormatStrategy(LitteralFormat)
{
}

std::string LitteralFormatStrategy::format(int time) const 
{
	// À compléter: décomposer la durée et construire une chaine avec en format litéral
	time_decomposition newTime = decomposeTime(time);
	return(std::to_string(newTime.days) + std::string(" jours ") + std::to_string(newTime.hours) + std::string(" heures ") + std::to_string(newTime.minutes) + std::string(" minutes ") + std::to_string(newTime.seconds) + std::string(" seconds "));

}