#include <string>

#include "Category.h"
#include "AbsProduct.h"

int Category::m_indent = 0;

Category::Category(std::string name)
	: AbsCatalogComponent(name)
{
}

Category::Category(const Category & mdd)
	: AbsCatalogComponent(mdd.m_name)
{
	// � compl�ter pour copier tous les �l�ments du catalogue contenus dans la cat�gorie
	for (auto product = mdd.cbegin(); product != mdd.cend(); ++product)
	{
		addCatalogComponent(*product);
	}
}

Category * Category::clone(void) const
{
	// � compl�ter pour construire un nouvel objet Category en appelant le constructeur de copie

	Category aCategory = Category(m_name);

	return new Category(aCategory); // � remplacer
}

AbsCatalogComponent& Category::addCatalogComponent(const AbsCatalogComponent & member)
{
	// � compl�ter pour construire par clonage une copie de l'objet re�u en param�tre
	// et l'ins�rer dans le conteneur de produits. On retourne une r�f�rence � l'objet
	// qui vient d'�tre ins�r� dans le conteneur.
	auto CopyCategory = member.clone();
	m_products.push_back(std::unique_ptr<AbsCatalogComponent>(CopyCategory));
	return *CopyCategory; // � remplacer 
}

CatalogComponentIterator Category::begin()
{
	return m_products.begin();
}

CatalogComponentIterator_const Category::cbegin() const
{
	return m_products.cbegin();
}

CatalogComponentIterator_const Category::cend() const
{
	return m_products.cend();
}

CatalogComponentIterator Category::end()
{
	return m_products.end();
}

void Category::deleteCatalogComponent(CatalogComponentIterator_const child)
{
	// � compl�ter pour �liminer de la cat�gorie l'�l�ment auquel r�f�re l'it�rateur
	//std::unique_ptr<AbsCatalogComponent> compotoRemove = std::make_unique<AbsCatalogComponent>(*child);
	//m_products.remove(compotoRemove);
	//m_products.erase(std::remove_if(m_products.begin(), m_products.end(), [&](auto const& element) { return element->getName() == child->getName(); }), m_products.end());
}

void Category::deleteAllComponents(void)
{
	// � compl�ter pour �liminer tous les �l�ments de la cat�gorie
	//for (CatalogComponentIterator itrCompo = begin(); itrCompo != end(); itrCompo++)
	//{
		//m_products.pop_back();
	//}
	//m_products.clear();
}

const AbsProduct* Category::findProduct(std::string productName) const
{
	// � compl�ter pour it�rer sur les �l�ments contenus dans la cat�gorie � la recherche d'un produit
	// portant le nom re�u en argument. Si aucun produit n'est trouv� on retourne nullptr
	const AbsProduct* foundProduct = nullptr;

	// � compl�ter
	for (auto itrCompo = m_products.cbegin(); itrCompo != m_products.cend(); itrCompo++)
	{

		//if (itrCompo->getName() == productName)
		//{
			//foundProduct = dynamic_cast<const AbsProduct*>(&(*itrCompo));
			//break;
		//}
		if ((*itrCompo)->findProduct(productName))
		{
			foundProduct = (*itrCompo)->findProduct(productName);
			break;
		}
	}

	return foundProduct;
}

std::ostream & Category::printToStream(std::ostream & o) const
{
	// � compl�ter pour imprimer sur un stream une cat�gorie et ses produits
	o << "Category:" << m_name;

	for (auto itrCompo = cbegin(); itrCompo != cend(); itrCompo++)
	{
		this->indent(o);
		o << *itrCompo << std::endl;
	}
	return o;
}

std::ostream & Category::indent(std::ostream & o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}
