///////////////////////////////////////////////////////////
//  CompositeStep.cpp
//  Implementation of the Class CompositeStep
//  Created on:      19-mars-2022 11:23:22
//  Original author: François
///////////////////////////////////////////////////////////

#include "CompositeStep.h"
#include "AbsRecipeVisitor.h"

CompositeStep::CompositeStep(std::string title)
	: AbsStep(title, 0)
{
}

CompositeStep::CompositeStep(const CompositeStep& mdd)
	: AbsStep(mdd)
{
	// À compléter pour copier toutes les sous-étapes contenues dans l'étape
	for (auto step = mdd.cbegin(); step != mdd.cend(); step++)
	{
		addRecipeComponent(*step);
	}
}

CompositeStep* CompositeStep::clone() const
{
	// À compléter pour construire un nouvel objet CompositeStep en appelant le constructeur de copie
	CompositeStep aCompositeStep = CompositeStep(m_description);
	return new CompositeStep(aCompositeStep); // À remplacer
}

RecipeComponentIterator CompositeStep::begin() {

	return m_stepsContainer.begin();
}


RecipeComponentIterator_const CompositeStep::cbegin() const {

	return m_stepsContainer.cbegin();
}


RecipeComponentIterator_const CompositeStep::cend() const 
{
	return m_stepsContainer.cend();
}

RecipeComponentIterator CompositeStep::end() 
{
	return  m_stepsContainer.end();
}

AbsRecipeComponent& CompositeStep::addRecipeComponent(const AbsRecipeComponent& member)
{
	const AbsStep& step = dynamic_cast<const AbsStep&>(member);
	return addRecipeComponent(step);
}

AbsRecipeComponent& CompositeStep::addRecipeComponent(const AbsStep& member)
{
	// À compléter pour construire par clonage une copie de l'objet reçu en paramètre
	// et l'insérer dans le conteneur des étapes. On retourne une référence à l'objet
	// qui vient d'être inséré dans le conteneur.
	auto CopyCompositeStep = member.clone();
	m_stepsContainer.push_back(std::make_unique<CompositeStep>(CopyCompositeStep->getDescription()));
	return *CopyCompositeStep; // À remplacer 

}

void CompositeStep::deleteRecipeComponent(RecipeComponentIterator_const child)
{
	// À compléter pour éliminer des étapes l'élément auquel réfère l'itérateur
	//m_stepsContainer.erase(std::remove_if(m_stepsContainer.begin(), m_stepsContainer.end(), [&](auto const& element) { return *element == *child; }), m_stepsContainer.end());
	m_stepsContainer.erase(child);
}

void CompositeStep::deleteAllComponents(void)
{
	// À compléter pour éliminer tous les éléments de l'étape
	m_stepsContainer.clear();
}

int CompositeStep::getDuration() const
{
	// À compléter pour calculer le temps total en sommant la durée de toutes les sous-étapes
	int duration = 0;
	for (auto itrStep = cbegin(); itrStep != cend(); itrStep++)
	{
		duration += itrStep->getDuration();
	}
	return duration; // À remplacer
}

std::ostream& CompositeStep::printToStream(std::ostream& o) const 
{
	// À compléter pour imprimer sur un stream une étape et ses sous-étapes

	o << m_description;
	int counter = 1;
	for (auto&& itrStep : m_stepsContainer)
	{
		o << "\t \t" << counter << " " << (*itrStep).getDescription() << "\n";
		counter++;
	}
	
	return o;
}

void CompositeStep::accept(class AbsRecipeVisitor& visitor) {
	visitor.processCompositeStep(*this);
	
}