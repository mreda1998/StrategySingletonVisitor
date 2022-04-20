///////////////////////////////////////////////////////////
//  FormatStrategy.cpp
//  Implementation of the Class FormatStrategy
//  Created on:      02-avr.-2022 14:16:26
//  Original author: francois
///////////////////////////////////////////////////////////

#include "FormatStrategy.h"
#include "TimeFormater.h"

FormatStrategy::FormatStrategy(std::string id)
{
	registerFormatStrategy(id, this);
}

FormatStrategy::time_decomposition FormatStrategy::decomposeTime(int time) const
{
	// � compl�ter: d�composer la dur�e en nombre de jours, heures, minutes et secondes
	//              retourner le r�sultat de la d�composition dans un objet time_decomposition
	int decompTime = time;
	int day = decompTime / (24 * 3600);

	decompTime = decompTime % (24 * 3600);
	int hour = decompTime / 3600;

	decompTime %= 3600;
	int minutes = decompTime / 60;

	int secondes = decompTime % 60;

	return time_decomposition(day,hour,minutes,secondes);
}

void FormatStrategy::registerFormatStrategy(std::string id, const FormatStrategy* strategy)
{
	// � compl�ter: ins�rer la strat�gie dans le registre des strat�gies de la classe TimeFormater

}
