///////////////////////////////////////////////////////////
//  FindIngredientVisitor.cpp
//  Implementation of the Class FindIngredientVisitor
//  Created on:      02-avr.-2022 14:16:25
//  Original author: francois
///////////////////////////////////////////////////////////

#include "FindIngredientVisitor.h"
#include "Ingredient.h"
#include "Recipe.h"
#include "CompositeStep.h"
#include "SingleStep.h"

FindIngredientVisitor::FindIngredientVisitor(const char* ingredientName)
	: m_searchedName(ingredientName), m_currentIterator(nullptr)
{
}

void FindIngredientVisitor::processCompositeStep(CompositeStep& composite)
{
	// RIEN � FAIRE POUR LES �TAPES COMPOSITES
}

void FindIngredientVisitor::processIngredient(Ingredient& ingredient)
{
	// � compl�ter: v�rifier si le nom du produit utilis� comme ingr�dient correspond au nom cherch�
	//              si oui, ajouter l'it�rateur sur cet ingr�dient dans la liste des ingr�dients trouv�s
	if (m_searchedName == ingredient.getProduct().getName())
	{
		m_ingredientsFound.push_back(*m_currentIterator);
	}
}

void FindIngredientVisitor::processRecipe(Recipe& recipe)
{
	// � compl�ter: it�rer sur tous les ingr�dients de la recette
	//                   - conserver un pointeur sur l'it�rateur de l'ingr�dient
	//                   - appliquer le visiteur sur l'ingr�dient
	for (auto ingredient = recipe.begin(); ingredient != recipe.end(); ++ingredient)
	{
		m_currentIterator = &ingredient;
		ingredient->accept(*this);
		
	}
}

void FindIngredientVisitor::processSingleStep(SingleStep& step)
{
	// RIEN � FAIRE POUR UNE �TAPE SIMPLE
}

FoundIngredientIterator FindIngredientVisitor::begin()
{
	return m_ingredientsFound.begin();
}

FoundIngredientIterator_const FindIngredientVisitor::cbegin() const
{
	return m_ingredientsFound.begin();
}

FoundIngredientIterator_const FindIngredientVisitor::cend() const
{
	return m_ingredientsFound.cend();
}

FoundIngredientIterator FindIngredientVisitor::end()
{
	return m_ingredientsFound.end();
}

void FindIngredientVisitor::reset()
{ 
	m_ingredientsFound.clear(); 
}

