///////////////////////////////////////////////////////////
//  Ingredient.cpp
//  Implementation of the Class Ingredient
//  Created on:      19-mars-2022 11:23:22
//  Original author: Fran�ois
///////////////////////////////////////////////////////////

#include "Ingredient.h"
#include "AbsRecipeVisitor.h"




Ingredient::Ingredient(std::string name, int duration, const AbsProduct& product)
	: AbsIngredient(name, duration), m_product(product)
{
}

Ingredient* Ingredient::clone() const
{
	// � compl�ter pour construire un nouvel objet Ingredient en appelant le constructeur de copie

	return new Ingredient(*this); // � remplacer
}

const AbsProduct& Ingredient::getProduct() const
{
	return m_product;
}

std::ostream& Ingredient::printToStream(std::ostream& o) const 
{
	// � compl�ter pour imprimer sur un stream une cat�gorie et ses produits
	o << "\t" << "\t" << m_product.getName() << " " << m_description;
	return o;
}

void Ingredient::accept(class AbsRecipeVisitor& visitor) {
	visitor.processIngredient(*this);

}