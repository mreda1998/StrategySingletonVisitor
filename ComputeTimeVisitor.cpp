///////////////////////////////////////////////////////////
//  ComputeTimeVisitor.cpp
//  Implementation of the Class ComputeTimeVisitor
//  Created on:      02-avr.-2022 14:16:25
//  Original author: francois
///////////////////////////////////////////////////////////

#include "ComputeTimeVisitor.h"
#include "CompositeStep.h"
#include "Ingredient.h"
#include "Recipe.h"
#include "SingleStep.h"

ComputeTimeVisitor::ComputeTimeVisitor()
	: m_preparationTime(0), m_realizationTime(0)
{
}

void ComputeTimeVisitor::processCompositeStep(CompositeStep& composite)
{
	// À compléter: itérer sur les enfants du composite et appliquer le visiteur à chaque enfant
	for (auto compo = composite.begin(); compo != composite.end(); compo++)
	{
		(*compo).accept(*this);
	}
}

void ComputeTimeVisitor::processIngredient(Ingredient& ingredient)
{
	// À compléter: ajouter la durée de préparation de l'ingrédient au temps total de préparation
	m_preparationTime += ingredient.getDuration();
}

void ComputeTimeVisitor::processRecipe(Recipe& recipe)
{
	// À compléter: itérer sur les ingrédients et appliquer le visiteur à chaque enfant
	//              itérer sur chaque étape et appliquer le visiteur à chaque étape
	for (auto ingred = recipe.begin(); ingred != recipe.end(); ingred++)
	{
		ingred->accept(*this);
	}
	for (auto steps = recipe.begin_step(); steps != recipe.end_step(); steps++)
	{
		steps->accept(*this);
	}
}

void ComputeTimeVisitor::processSingleStep(SingleStep& step)
{
	// À compléter: ajouter la durée de réalisation de l'étape au temps total de réalisation
	m_realizationTime += step.getDuration();
}
